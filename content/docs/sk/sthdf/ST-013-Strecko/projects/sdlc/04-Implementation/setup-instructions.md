---
# 🧩 Versioning – systém dopĺňa automaticky
fm_version: "1.0.1"

# Dátum buildu – generuje skript
fm_build: "2026-10-05T10:01:19.149702+00:00"

# Poznámka k verzii – voliteľné
fm_version_comment: ""


# 🆔 IDENTITY --------------------------------------------------------

# ID generuje CLI / skript

# Unikátne UUID – generuje skript
guid: "58866c30-fc3e-4950-98a3-546f42ce3ccf"


# 🧭 CONTEXT ---------------------------------------------------------

# DAO / doména (knife, sdlc, q12, 7ds...) dopĺňa skript
dao: "sthdf"

# Názov zápisu – dopĺňa používateľ
title: "setup instructions"

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

# ⚙️ Setup Instructions — OtakuPlanter (PRJ_004)

Návod na zostavenie hardvéru, prípravu MicroSD karty a nahratie firmvéru do mikrokontroléra.

---

## 1. Príprava MicroSD karty

1. Naformátujte MicroSD kartu (kapacita do $32\text{ GB}$) na súborový systém **FAT32**.
2. V koreňovom adresári karty vytvorte priečinok s názvom `mp3`.
3. Vložte zvukové súbory pomenované štvormiestnym číslom:
   - `/mp3/0001.mp3` — Hláška pri smäde (*"Yamete kudasai! Mizu o kudasai!"*)
   - `/mp3/0002.mp3` — Hláška po poliatí (*"Arigatō!"*)
   - `/mp3/0003.mp3` — Uvítacia zvučka pri zapnutí (*"Ohayō!"*)
4. Zasuňte MicroSD kartu do modulu **DFPlayer Mini**.

---

## 2. Zapojenie obvodu (Wiring)

1. Prepojte **Kapacitný senzor v1.2** s Arduino Nano:
   - `VCC` $\rightarrow$ `5V`, `GND` $\rightarrow$ `GND`, `AOUT` $\rightarrow$ `A0`.
2. Prepojte **DFPlayer Mini** s Arduino Nano:
   - `VCC` $\rightarrow$ `5V` (pridajte paralelne kondenzátor $100\,\mu\text{F}$ medzi `VCC` a `GND`),
   - `GND` $\rightarrow$ `GND`,
   - `RX` (pin 2 na DFPlayeri) $\rightarrow$ cez rezistor $1\text{ k}\Omega$ na pin `D11` Arduina,
   - `TX` (pin 3 na DFPlayeri) $\rightarrow$ pin `D10` Arduina,
   - `SPK_1` a `SPK_2` $\rightarrow$ reproduktor $8\,\Omega / 3\text{ W}$.
3. Prepojte **indikačnú LED** (oči postavičky):
   - Anóda (`+`) cez rezistor $220\,\Omega$ na pin `D6`, katóda (`-`) na `GND`.

---

## 3. Nahratie firmvéru (Arduino IDE)

1. Otvorte súbor `firmware/otaku_planter/otaku_planter.ino` v **Arduino IDE**.
2. V správcovi knižníc (*Library Manager*) nainštalujte knižnicu **`DFRobotDFPlayerMini`** (autor: DFRobot).
3. Zvoľte dosku **Arduino Nano** (*Processor: ATmega328P* alebo *ATmega328P Old Bootloader* pri klonoch CH340).
4. Kliknite na **Upload** a otvorte **Serial Monitor** s rýchlosťou `115200 baud` pre sledovanie nameraných hodnôt a kalibráciu prahov `DRY_THRESHOLD` a `WET_THRESHOLD`.

---
**Navigation:** [⬆️ Up](./index.md) · [🏠 Home](../index.md)
