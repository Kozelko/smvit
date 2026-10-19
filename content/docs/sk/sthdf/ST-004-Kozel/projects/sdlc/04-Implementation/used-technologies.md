---
# 🧩 Versioning – systém dopĺňa automaticky
fm_version: "1.0.1"

# Dátum buildu – generuje skript
fm_build: "2026-10-05T10:01:14.416372+00:00"

# Poznámka k verzii – voliteľné
fm_version_comment: ""


# 🆔 IDENTITY --------------------------------------------------------

# ID generuje CLI / skript

# Unikátne UUID – generuje skript
guid: "f9b8b630-28e8-4265-b08c-c386cc4e826c"


# 🧭 CONTEXT ---------------------------------------------------------

# DAO / doména (knife, sdlc, q12, 7ds...) dopĺňa skript
dao: "sthdf"

# Názov zápisu – dopĺňa používateľ
title: "used technologies"

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

<!-- SDLC_INSTANCE_ID: ST-004-Kozel -->

# 🧰 Used Technologies — OtakuPlanter (PRJ_004)

Prehľad hardvérových, softvérových a fabrikačných technológií zvolených pre projekt **OtakuPlanter** spolu s odôvodnením ich výberu.

---

## 1. Hardvérové komponenty (Electronics & IoT)

| Komponent | Špecifikácia | Dôvod výberu |
|---|---|---|
| **Mikrokontrolér** | **Arduino Nano (ATmega328P)** / **ESP32** | Kompaktné rozmery do podstavca, $5\text{ V}$ logika, nízka cena, okamžitý štart bez operačného systému |
| **Senzor vlhkosti** | **Capacitive Soil Moisture Sensor v1.2** | Kapacitný princíp zabraňuje elektrolytickej korózii sondy a uvoľňovaniu medi do substrátu |
| **Audio modul** | **DFPlayer Mini (YX5200)** | Integrovaný hardvérový MP3/WAV dekodér, slot na MicroSD a $3\text{ W}$ zosilňovač na jedinom čipe |
| **Akustický menič** | **Mini reproduktor $8\,\Omega / 3\text{ W}$ (alebo $4\,\Omega / 3\text{ W}$)** | Dostatočná hlasitosť pre celú miestnosť pri napájaní priamo z DFPlayer Mini bez externého zosilňovača |
| **Pamäťové médium** | **MicroSD karta ($1 - 32\text{ GB}$, FAT32)** | Jednoduchá výmena japonských hlasových stôp v priečinku `/mp3/` bez nutnosti preprogramovať MCU |

---

## 2. Softvér a firmvér

| Technológia | Účel | Dôvod výberu |
|---|---|---|
| **C++ / Arduino Framework** | Riadiaci firmvér (`otaku_planter.ino`) | Priama práca s ADC prevodníkom, nízka latencia, deterministický konečný stavový automat (FSM) |
| **`SoftwareSerial.h`** | Emulácia UART na pinoch `D10` / `D11` | Uvoľňuje hardvérový USB UART (`D0`/`D1`) pre ladenie a kalibráciu cez Serial Monitor |
| **`DFRobotDFPlayerMini.h`** | Ovládanie MP3 modulu cez sériovú linku | Overená knižnica pre spoľahlivé odosielanie rámcov (`0x7E ... 0xEF`) a riadenie hlasitosti |

---

## 3. Digitálna fabrikácia a modelovanie (CAD / CAM)

| Technológia | Účel | Dôvod výberu |
|---|---|---|
| **Autodesk Fusion 360 / Blender** | 3D modelovanie kvetináča a anime postavičky | Kombinácia parametrického CAD modelovania (dvojkomorové telo, závity, úchyty) a organického sculptingu postavičky |
| **PrusaSlicer / Bambu Studio** | Príprava tlačových dát (`.gcode`) | Presné riadenie počtu perimetrov (`4 perimetre`) a švu (`Seam`) pre dosiahnutie vodotesnosti |
| **FDM 3D tlač (PETG / PLA)** | Fyzická výroba kvetináča | **PETG** pre vnútornú vodotesnú nádobu (chemická a hydroizolačná odolnosť), **PLA** pre detailnú anime figúrku |
| **Enterprise Architect (UML/SysML)** | Architektonické modelovanie (`OtakuPlanter.qea`) | Štandardizovaný návrh Use Case, Component, State Machine a Sequence diagramov |

---
**Navigation:** [⬆️ Up](./index.md) · [🏠 Home](../index.md)
