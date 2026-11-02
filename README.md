# Anime Planter // Inteligentný kvetináč

> **Projekt:** Inteligentný kvetináč s figúrkou Grimmjowa — BLEACH × Smart Hardware  
> **Predmet:** Systémové myslenie v IT a digitálna fabrikácia (STHDF / SMVIT 2026/2027)  
> **Univerzita:** Fakulta informatiky a informačných technológií, Slovenská technická univerzita v Bratislave (FIIT STU)  
> **Autori:** Bc. Peter Brandajský (`ST004`) & Bc. Timotej Strečko (`ST013`)  
> **Webová prezentácia:** [`index.html`](./index.html) *(interaktívny 3D model, zvukový simulátor a technický rez)*  

---

## 💡 O projekte

**Anime Planter** je inteligentný kvetináč navrhnutý pre sukulenty a izbové rastliny, ktorý spája **3D digitálnu fabrikáciu** a **lokálny vstavaný hardvér**:

- **Fyzický dizajn:** 140 mm vysoká 3D tlačená figúrka Grimmjowa v sediacej póze, ktorej lono slúži ako lôžko pre valcový kvetináč s priemerom **Ø 78 mm**.
- **Autonómna prevádzka:** Zariadenie nepotrebuje žiadnu mobilnú aplikáciu, Wi-Fi ani cloud. Funguje 100% lokálne v izbe okamžite po pripojení 5V napájania.
- **Akustické hlášky:** Modul **DFPlayer Mini** a 0.5W reproduktor v reálnom čase prehrávajú hlasové reakcie postavy. Keď pôda vyschne, figúrka si vypýta vodu (*„Yamete kudasai! Mizu o kudasai!“*). Po zaliatí sa poďakuje (*„Arigatō!“*).
- **Nekorodujúci kapacitný senzor:** Na rozdiel od bežných odporových senzorov, ktoré kvôli elektrolýze do pár týždňov zhrdzavejú, kapacitný senzor v1.2 meria permitivitu pôdy bez priameho kontaktu medi s vodou.
- **Dvojkomorová konštrukcia:** Vrchná vlhká pestovateľská komora (hĺbka 50 mm) je od spodnej suchej komory s elektronikou (výška 30 mm) hermeticky oddelená vodotesnou prepážkou s tesnením.

---

## 📂 Čo sa nachádza v repozitári

| Súbor / Priečinok | Typ | Popis |
|---|---|---|
| [`index.html`](./index.html) | Webový showcase | Kompletná interaktívna prezentácia s Three.js 3D prehliadačom figúrky, interaktívnym zvukovým simulátorom, technickým nákresom a kusovníkom. |
| [`3d_models/`](./3d_models/) | 3D modely (STL / FBX) | Modely pripravené na 3D tlač: `grimmjow_140mm_ready.stl` (spojený meč a záštita pri páse, mierka 140 mm) a pôvodné zdrojové súbory. |
| [`firmware/`](./firmware/) | Arduino C++ | Firmvér `otaku_planter.ino` s 16-násobným kruhovým priemerovaním, hysteréziou pre ochranu pred kmitaním stavov a UART ovládaním audio modulu. |
| [`EA_ST004_AutoLogin.eaps`](./EA_ST004_AutoLogin.eaps) | Enterprise Architect | Konfiguračné pripojenie na centrálny Enterprise Architect model (UML Use Case, Component a State Machine diagramy). |
| [`OtakuPlanter.qea`](./OtakuPlanter.qea) | Enterprise Architect | Lokálny SQLite model systémovej architektúry projektu. |
| [`OtakuPlanter_Pitch_Presentation.pptx`](./OtakuPlanter_Pitch_Presentation.pptx) | Prezentácia | 6-slajdový Pitch Deck projektu (Problém, Riešenie, Hodnota, Hardvér, Tím). |
| [`content/docs/`](./content/docs/) | Dokumentácia STHDF | 7 povinných akademických výstupov predmetu (About Me, KNIFE príspevky, Project Summary, Outcomes, Pitch, Final a Reflexia). |

---

## 👥 Tím a rozdelenie úloh

- **Bc. Peter Brandajský (`ST004`)** — *Firmware, Electronics & Architecture Lead*  
  Návrh elektronického obvodu, zapojenie senzorov a audio dekodéra, C++ firmvér pre Arduino Nano s kruhovým filtrom a hysteréziou, systémové modelovanie v Enterprise Architect (UML/SysML).

- **Bc. Timotej Strečko (`ST013`)** — *3D CAD & Digital Fabrication Lead*  
  Úprava a čistenie 3D modelu figúrky, návrh dvojkomorového tela kvetináča, slicovanie v PrusaSliceri a FDM tlač na 3D tlačiarni (PLA/PETG).

---

## 🛠️ Hardvérová architektúra & Zapojenie pinov

```
+-----------------------------------------------------------+
|               HORNÁ PESTOVATEĽSKÁ KOMORA                  |
|  - Hĺbka: 50 mm, priemer: Ø 78 mm                         |
|  - Kapacitný senzor vlhkosti v1.2 (ponor 45 mm v pôde)    |
+-----------------------------------------------------------+
| ====== VODOTESNÁ PREPÁŽKA (4 perimetre + O-krúžok) ====== |
+-----------------------------------------------------------+
|                 SPODNÁ SUCHÁ KOMORA                       |
|  - Výška: 30 mm                                           |
|  - Arduino Nano (ATmega328P, 5V napájanie)                |
|  - DFPlayer Mini + MicroSD karta s MP3 hláškami           |
|  - 8Ω 0.5W reproduktor so smerovanými zvukovými štrbinami |
|  - Mini nepájivé pole (montáž bez nutnosti leptania DPS)  |
+-----------------------------------------------------------+
```

| Komponent | Pin na komponente | Pin na Arduino Nano | Funkcia |
|---|---|---|---|
| **Kapacitný senzor v1.2** | VCC / GND | `5V` / `GND` | Napájanie senzora |
| | AOUT | `A0` | Analógový vstup vlhkosti (ADC 0–1023) |
| **DFPlayer Mini** | VCC / GND | `5V` / `GND` | Napájanie audio radiča |
| | TX | `D10` | SoftwareSerial RX na Arduine |
| | RX | `D11` | SoftwareSerial TX (cez 1 kΩ ochranný rezistor) |
| | SPK_1 / SPK_2 | Reproduktor | Výstup na 8Ω 0.5W reproduktor |
| **Indikačná LED** | Anóda (+) | `D6` | PWM signál dýchania očí postavičky |

---

## 🛒 Kusovník (BOM) — 16,20 €

Všetky komponenty boli vybrané s ohľadom na okamžitú dostupnosť u slovenského dodávateľa:

1. **Kapacitný senzor vlhkosti pôdy v1.2** — 1,50 €
2. **DFPlayer Mini MP3 prehrávač** — 2,75 €
3. **Arduino Nano klon (Micro USB, ATmega328P)** — 5,45 €
4. **Reproduktor 8Ω 0.5W (Ø 40 mm)** — 0,60 €
5. **Prepojovacie kábliky Dupont (40 ks)** — 2,20 €
6. **Mini nepájivé pole (170 bodov, 45 × 35 mm)** — 0,40 €
7. **Sada metalických rezistorov (30 hodnôt vrátane 1 kΩ a 220 Ω)** — 2,90 €

**Celkový rozpočet hardvéru: 16,20 € s DPH.**
