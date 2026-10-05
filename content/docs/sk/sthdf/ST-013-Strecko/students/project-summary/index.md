---
# 🧩 Versioning – systém dopĺňa automaticky
fm_version: "1.0.1"

# Dátum buildu – generuje skript
fm_build: "2026-10-05T10:01:19.206107+00:00"

# Poznámka k verzii – voliteľné
fm_version_comment: ""


# 🆔 IDENTITY --------------------------------------------------------

# ID generuje CLI / skript

# Unikátne UUID – generuje skript
guid: "271ec01e-f823-4ee9-9c9e-7bf1d4778e74"


# 🧭 CONTEXT ---------------------------------------------------------

# DAO / doména (knife, sdlc, q12, 7ds...) dopĺňa skript
dao: "sthdf"

# Názov zápisu – dopĺňa používateľ
title: "project summary"

# Krátky popis – dopĺňa používateľ (voliteľné)
description: "{{DESCRIPTION}}"


# 👥 AUTHORSHIP ------------------------------------------------------

# Hlavný autor – z globálneho configu
author: "Roman Kazicka"

# Zoznam autorov – generuje skript
authors:
  - "Roman Kazicka"


# 🗂 CLASSIFICATION ---------------------------------------------------

# Nadradená kategória – môže doplniť používateľ
category: ""

# Typ dokumentu (guide, case, tutorial...) – používateľ (voliteľné)
type: ""

# Priorita (low/medium/high) – voliteľné
priority: ""

# Tagy – odporúča sa 2–6 tagov.
# Typy tagov:
#   - rámce: knife, 7ds, sdlc, q12
#   - účel: tutorial, guide, pattern, case-study
#   - téma: git, backup, ai, communication
#   - úroveň: beginner, intermediate, advanced
tags: []


# 🌍 LOCALIZATION -----------------------------------------------------

# Jazyk dokumentu – doplní skript podľa štruktúry
locale: "sk"


# 🕒 LIFECYCLE --------------------------------------------------------

# Dátum vytvorenia – generuje skript
created: "2026-10-05 12:01"

# Dátum poslednej úpravy – dopĺňa človek
modified: "2026-10-05 12:01"

# Stav dokumentu – default "backlog"
status: "backlog"

# Viditeľnosť – default "public"
privacy: "public"


# ⚖ INTELLECTUAL PROPERTY -------------------------------------------

# Držiteľ práv k obsahu – dopĺňa skript
rights_holder_content: "Roman Kazicka"

# Systémový vlastník práv
rights_holder_system: "CAA / KNIFE / LetItGrow"

# Licencia
license: "CC-BY-NC-SA-4.0"

# Disclaimer
disclaimer: "Use at your own risk. Methods provided as-is; participation is voluntary and context-aware."

# Copyright
copyright: "© 2025 Roman Kazicka"


# 🔗 ORIGIN / PROVENANCE ---------------------------------------------

# Repozitár pôvodu
origin_repo: ""

# URL pôvodného repozitára
origin_repo_url: ""

# Commit pôvodu
origin_commit: ""

# Branch pôvodu
origin_branch: ""

# Systém pôvodu (CAA/KNIFE/STHDF…)
origin_system: "CAA"

# Pôvodný autor
origin_author: "Roman Kazicka"

# Importovaný zdroj
origin_imported_from: ""

# Dátum importu
origin_import_date: ""


# 🧱 RESERVED ---------------------------------------------------------

fm_reserved1: ""
fm_reserved2: ""
---

<!-- SDLC_INSTANCE_ID: ST-013-Strecko -->

# 📝 Project Summary — OtakuPlanter (PRJ_004)

## 🔖 Identifikácia
## 1️⃣ Názov projektu
- **Názov projektu:** `PRJ_004_AnimeSmartPlanter_ST004_ST013`
- **Pracovný názov:** *OtakuPlanter: Interaktívny smart kvetináč s anime tematikou a hlasovou odozvou*
- **Stručný popis:** Inteligentný izbový kvetináč v tvare anime postavičky vyrobený pomocou digitálnej fabrikácie (3D tlače), ktorý v reálnom čase monitoruje stav pôdnej vlhkosti. Pri poklese vlahy pod kritickú úroveň mikrokontrolér cez audio modul prehrá varovnú hlášku v japončine (napr. *"Yamete kudasai, napoj ma!"*), čím zábavnou formou predchádza vysychaniu rastliny.

## 2️⃣ Členovia tímu

| ST ID | Meno | Rola v tíme | Kompetencie |
|-------|------|-------------|-------------|
| **ST004** | Bc. Peter Brandajský | Project Lead & Hardware/Firmware | Koordinácia projektu, vývoj firmvéru (Arduino/ESP32), integrácia senzorov a DFPlayer audia, kalibrácia stavového automatu |
| **ST013** | Bc. Timotej Strečko | 3D Designer & Systems Architect | CAD dizajn tela postavičky a kvetináča, riešenie suchej komory pre elektroniku a drenáže, 7Ds systémová dekompozícia |

## 3️⃣ Motivácia tímu
- **Problém:** Izbové rastliny v domácnostiach a na internátoch často hynú kvôli nepravidelnému polievaniu a zabúdaniu. Bežné komerčné smart kvetináče sú buď drahé, sterilné alebo len posielajú notifikácie na mobil, ktoré používateľ ignoruje.
- **Prečo práve tento projekt:** Chceme spojiť digitálnu fabrikáciu s praktickým IoT zariadením a gamifikáciou starostlivosti o rastliny. Postavička získa vlastnú "osobnosť" a prirodzene si hlasom vypýta pozornosť v momente, keď rastlina potrebuje vodu.
- **Osobný zmysel:** Praktické overenie systémového životného cyklu (od výberu súčiastok a 3D modelovania až po finálne oživenie a testovanie funkčného fyzického produktu). Projekt má navyše aj dôležitú osobnú motiváciu – Timotej chce vytvoriť pekný a funkčný interaktívny kvetináč/podstavec inšpirovaný anime/Lookism estetikou, aby potešil svoju priateľku, pričom naplno zužitkuje Petrov hardvérový skill a vlastné DataOps/analytické zázemie.

## 4️⃣ Cieľ a pridaná hodnota projektu
- **Finálny cieľ:** Plne funkčný, estetický a vodotesne oddelený 3D tlačený kvetináč s integrovanou elektronikou, ktorý spoľahlivo meria vlhkosť a akusticky reaguje na zmeny stavu.
- **Kritériá úspechu:**
  1. Presná a stabilná detekcia sucha pomocou kapacitného senzora bez degradácie pôsobením korózie.
  2. Spoľahlivé prehratie správnej zvukovej stopy cez DFPlayer Mini podľa aktuálneho stavu (Sucho $\rightarrow$ Zaliatie).
  3. Mechanická integrita: Žiadny prienik vody ani vlhkosti z drenážnej časti do priestoru s elektronikou.

## 5️⃣ Popis riešenia (Systémová architektúra)
Zariadenie je koncipované ako ucelený kyberneticko-fyzikálny systém pozostávajúci zo 4 subsystémov:
- **Senzorický subsystém:** Kapacitný senzor pôdnej vlhkosti v1.2 (analógové meranie permitivity pôdy, nepodlieha galvanickej korózii ako lacné odporové sondy).
- **Riadiaci subsystém:** Mikrokontrolér (Arduino Nano / ESP32) so stavovým automatom:
  - *Stav 1 (Standby/Sleep):* Pravidelné budenie a nízka spotreba energie.
  - *Stav 2 (Meranie & Vyhodnotenie):* Odčítanie hodnôt s vyhladením šumu a hysteréziou.
  - *Stav 3 (Kritické sucho):* Aktivácia zvukového subsystému a varovnej hlášky.
  - *Stav 4 (Detekcia poliatia):* Úspešná detekcia nárastu vlahy $\rightarrow$ prehratie spokojnej hlášky (*"Arigatō!"*).
- **Aktuačný & Zvukový subsystém:** MP3 dekodér DFPlayer Mini s microSD kartou (uložené audio hlášky), mini reproduktor (8Ω / 3W) a signalizačná LED dióda (indikácia stavu v očiach postavičky).
- **Konštrukčný subsystém (Digitálna fabrikácia):** 3D tlačené telo (PLA / PETG) navrhnuté v CAD nástroji. Konštrukcia obsahuje vrchnú kvetináčovú nádobu s prepadovým otvorom a spodnú hermeticky izolovanú komoru pre elektroniku a reproduktor.

## 6️⃣ Projektový plán
- **Odhadovaný čas na prácu:** 6–8 hodín týždenne na tím.
- **Predpokladaný stav v čase prezentácie:** Funkčný prototyp (MVP) v 3D tlačenom tele s demonštráciou reakcie na zalievanie.
- **Hlavné míľniky:**
  - [x] **M1 (Týždeň 4):** Project Summary, systémová dekompozícia a špecifikácia kusovníka (BOM).
  - [ ] **M2 (Týždeň 6):** Zostavenie obvodu na breadboarde, kalibrácia senzora vlhkosti a test DFPlayer audia.
  - [ ] **M3 (Týždeň 8):** Dokončenie CAD modelu postavičky a prvá testovacia 3D tlač vo FabLabe.
  - [ ] **M4 (Týždeň 10):** Finálna montáž elektroniky do vytlačeného tela, hydroizolácia a zladenie firmvéru.
  - [ ] **M5 (Týždeň 12):** Verifikácia, finálna 7Ds dokumentácia, video demonštrácia a prezentácia.

### 📅 Míľniky a výstupy
- **Do januára dodáme:**
  - [x] funkčný hardvérový prototyp kvetináča
  - [x] kompletnú 7Ds dokumentáciu v Docusauruse
  - [x] CAD podklady (STL/STEP) a zdrojový kód firmvéru
  - [x] finálnu pitch a záverečnú prezentáciu

## 7️⃣ Zákazník a hodnoty
- **Cieľová skupina:** Študenti, kancelárski pracovníci, fanúšikovia anime kultúry a smart-home technológií.
- **Prínos:** Spoľahlivá záchrana izbových rastlín pred vyschnutím, personalizovaný dizajn pracovného stola a zábavný interaktívny prvok namiesto nudných plastových kvetináčov.

## 8️⃣ Očakávané výstupy
- **Dokumentácia:** Kompletná systémová dokumentácia 7Ds (D1 až D7), schémy zapojenia (Fritzing), návod na replikáciu.
- **Artefakty:** Fyzický 3D prototyp, repozitár so zdrojovým kódom C++ (Arduino), CAD modely pre 3D tlačiareň, demo video.

## 📚 Kontext & Inšpirácie
- Nadväznosť na staršie projekty FabLab / SMVIT: *Plant Monitoring (2020)* a *Sensoric Tortoise (2020)*.
- Metodický rámec 7Ds pre štruktúrovaný návrh riešenia (od požiadaviek po verifikáciu).

## 🧭 Riziká a závislosti
- **Riziko 1 (Vlhkosť a voda):** Nebezpečenstvo zatečenia vody zo substrátu k elektronike.  
  *Mitigácia:* Fyzicky oddelená dvojstenná komora, drenážny kanálik s odtokom mimo PCB, ochranné lakovanie spojov.
- **Riziko 2 (Falošná signalizácia / šum merania):** Kolísanie analógových hodnôt zo senzora.  
  *Mitigácia:* Softvérový plávajúci priemer a hysterézia limitných hodnôt vo firmvéri.

## 9️⃣ Reflexia a ďalšie kroky
- **Čo sa naučíme:** Praktickú integráciu embedded mikrokontrolérov s audio perifériami, konštrukčný návrh pre 3D tlač s ohľadom na montáž a vodeodolnosť, uplatnenie princípov systémového inžinierstva.
- **Možný ďalší rozvoj:** Pridanie Wi-Fi / Bluetooth (ESP32) pre webový dashboard a možnosť nahrávania vlastných hlášok cez webové rozhranie.

---

## Navigácia
- [↩️ Späť](../index.md)
