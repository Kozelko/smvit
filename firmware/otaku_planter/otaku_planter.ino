/**
 * Project: OtakuPlanter (PRJ_004_AnimeSmartPlanter_ST004_ST013)
 * Course:  SMVIT / STHDF 2026 (FIIT STU)
 * Authors: Peter Brandajsky (ST004), Timotej Strecko (ST013)
 *
 * Description:
 *   Interactive anime-themed smart planter firmware for Arduino Nano (ATmega328P).
 *   Uses a Capacitive Soil Moisture Sensor v1.2 (analog pin A0) with a 16-sample
 *   moving average filter and hysteresis thresholds to drive a DFPlayer Mini MP3
 *   module over SoftwareSerial (pins D10, D11) and an indicator LED (pin D6).
 *
 * MicroSD Card Structure (FAT32):
 *   /mp3/0001.mp3 -> Thirsty alert ("Yamete kudasai! Mizu o kudasai!")
 *   /mp3/0002.mp3 -> Watered thank-you ("Arigato!")
 *   /mp3/0003.mp3 -> Boot greeting ("Ohayo!")
 */

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// -------------------- PIN DEFINITIONS --------------------
constexpr uint8_t PIN_MOISTURE_SENSOR = A0;
constexpr uint8_t PIN_DFP_RX          = 10; // Connect to DFPlayer TX
constexpr uint8_t PIN_DFP_TX          = 11; // Connect via 1kOhm resistor to DFPlayer RX
constexpr uint8_t PIN_STATUS_LED      = 6;  // Indicator LED (anime character eyes)

// -------------------- CALIBRATION & HYSTERESIS -----------
// Capacitive sensor v1.2 outputs HIGHER ADC values when DRY, LOWER when WET.
constexpr int ADC_DRY_AIR             = 760; // 0% moisture reference
constexpr int ADC_WET_WATER           = 310; // 100% moisture reference
constexpr int DRY_THRESHOLD           = 620; // Trigger "Thirsty" state when ADC > 620 (~30% moisture)
constexpr int WET_THRESHOLD           = 450; // Trigger "Watered" state when ADC < 450 (~68% moisture)

// -------------------- TIMING & FILTERING -----------------
constexpr uint8_t  FILTER_SAMPLES     = 16;
constexpr uint32_t MEASURE_INTERVAL_MS = 2000UL;       // Sample every 2 seconds
constexpr uint32_t REMINDER_COOLDOWN_MS = 3600000UL;   // Repeat thirsty voice max once per hour (60 min)
constexpr uint8_t  AUDIO_VOLUME       = 22;            // Range: 0..30

// -------------------- TRACK NUMBERS ----------------------
constexpr uint16_t TRACK_THIRSTY      = 1; // /mp3/0001.mp3
constexpr uint16_t TRACK_WATERED      = 2; // /mp3/0002.mp3
constexpr uint16_t TRACK_BOOT         = 3; // /mp3/0003.mp3

// -------------------- FINITE STATE MACHINE ---------------
enum class PlanterState : uint8_t {
  INIT,
  STANDBY,
  MEASURE,
  ALERT_THIRSTY,
  WAIT_WATER,
  WATERED_HAPPY
};

SoftwareSerial dfSerial(PIN_DFP_RX, PIN_DFP_TX);
DFRobotDFPlayerMini dfPlayer;

PlanterState currentState = PlanterState::INIT;
bool dfPlayerReady = false;
int sampleBuffer[FILTER_SAMPLES];
uint8_t sampleIndex = 0;
bool bufferFilled = false;

uint32_t lastMeasureTime = 0;
uint32_t lastAlertTime = 0;
uint32_t ledBlinkTimer = 0;
bool ledState = false;

// Read and smooth capacitive sensor using 16-sample moving average
int readFilteredMoistureADC() {
  int raw = analogRead(PIN_MOISTURE_SENSOR);
  sampleBuffer[sampleIndex] = raw;
  sampleIndex = (sampleIndex + 1) % FILTER_SAMPLES;
  if (sampleIndex == 0) {
    bufferFilled = true;
  }

  uint8_t count = bufferFilled ? FILTER_SAMPLES : sampleIndex;
  long sum = 0;
  for (uint8_t i = 0; i < count; i++) {
    sum += sampleBuffer[i];
  }
  return static_cast<int>(sum / count);
}

// Convert ADC value into human-readable 0-100% relative soil moisture
int adcToPercentage(int adcValue) {
  long pct = map(adcValue, ADC_DRY_AIR, ADC_WET_WATER, 0, 100);
  return constrain(static_cast<int>(pct), 0, 100);
}

void playVoiceTrack(uint16_t trackNumber) {
  if (dfPlayerReady) {
    dfPlayer.playMp3Folder(trackNumber);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_STATUS_LED, OUTPUT);
  digitalWrite(PIN_STATUS_LED, HIGH);

  // Pre-fill moving average buffer with initial sensor readings
  for (uint8_t i = 0; i < FILTER_SAMPLES; i++) {
    readFilteredMoistureADC();
    delay(10);
  }

  Serial.println(F("=========================================="));
  Serial.println(F(" OtakuPlanter (PRJ_004) Firmware Starting "));
  Serial.println(F("=========================================="));

  dfSerial.begin(9600);
  if (dfPlayer.begin(dfSerial, true, true)) {
    dfPlayerReady = true;
    dfPlayer.volume(AUDIO_VOLUME);
    Serial.println(F("[OK] DFPlayer Mini initialized."));
    playVoiceTrack(TRACK_BOOT);
  } else {
    dfPlayerReady = false;
    Serial.println(F("[WARN] DFPlayer Mini not detected. Running in visual/serial mode."));
  }

  currentState = PlanterState::STANDBY;
  lastMeasureTime = millis();
}

void loop() {
  uint32_t now = millis();

  // Blink LED rapidly when waiting for water, keep steady dim/on in standby
  if (currentState == PlanterState::WAIT_WATER) {
    if (now - ledBlinkTimer >= 350UL) {
      ledBlinkTimer = now;
      ledState = !ledState;
      digitalWrite(PIN_STATUS_LED, ledState ? HIGH : LOW);
    }
  } else {
    analogWrite(PIN_STATUS_LED, 60); // Calm glowing eyes in normal mode
  }

  switch (currentState) {
    case PlanterState::INIT:
      currentState = PlanterState::STANDBY;
      break;

    case PlanterState::STANDBY:
      if (now - lastMeasureTime >= MEASURE_INTERVAL_MS) {
        lastMeasureTime = now;
        currentState = PlanterState::MEASURE;
      }
      break;

    case PlanterState::MEASURE: {
      int adcAvg = readFilteredMoistureADC();
      int moisturePct = adcToPercentage(adcAvg);

      Serial.print(F("[STANDBY] Moisture ADC: "));
      Serial.print(adcAvg);
      Serial.print(F(" ("));
      Serial.print(moisturePct);
      Serial.println(F("%)"));

      if (adcAvg > DRY_THRESHOLD) {
        currentState = PlanterState::ALERT_THIRSTY;
      } else {
        currentState = PlanterState::STANDBY;
      }
      break;
    }

    case PlanterState::ALERT_THIRSTY:
      Serial.println(F("[ALERT] Soil is DRY! Playing Track 0001 (Yamete kudasai!)"));
      playVoiceTrack(TRACK_THIRSTY);
      lastAlertTime = now;
      currentState = PlanterState::WAIT_WATER;
      break;

    case PlanterState::WAIT_WATER:
      if (now - lastMeasureTime >= 1000UL) { // Faster polling (1s) while waiting for watering
        lastMeasureTime = now;
        int adcAvg = readFilteredMoistureADC();
        int moisturePct = adcToPercentage(adcAvg);

        Serial.print(F("[THIRSTY] Waiting for water... ADC: "));
        Serial.print(adcAvg);
        Serial.print(F(" ("));
        Serial.print(moisturePct);
        Serial.println(F("%)"));

        // Hysteresis check: only exit thirsty state when moisture drops below WET_THRESHOLD
        if (adcAvg < WET_THRESHOLD) {
          currentState = PlanterState::WATERED_HAPPY;
        } else if (now - lastAlertTime >= REMINDER_COOLDOWN_MS) {
          Serial.println(F("[REMINDER] Cooldown elapsed, repeating Track 0001."));
          playVoiceTrack(TRACK_THIRSTY);
          lastAlertTime = now;
        }
      }
      break;

    case PlanterState::WATERED_HAPPY:
      Serial.println(F("[HAPPY] Plant watered! Playing Track 0002 (Arigato!)"));
      digitalWrite(PIN_STATUS_LED, HIGH);
      playVoiceTrack(TRACK_WATERED);
      delay(2500);
      currentState = PlanterState::STANDBY;
      break;
  }
}
