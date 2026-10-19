---
# 🧩 Versioning – systém dopĺňa automaticky
fm_version: "1.0.1"

# Dátum buildu – generuje skript
fm_build: "2026-10-05T10:01:19.140943+00:00"

# Poznámka k verzii – voliteľné
fm_version_comment: ""


# 🆔 IDENTITY --------------------------------------------------------

# ID generuje CLI / skript

# Unikátne UUID – generuje skript
guid: "45598182-a390-4653-b12b-668670981cd0"


# 🧭 CONTEXT ---------------------------------------------------------

# DAO / doména (knife, sdlc, q12, 7ds...) dopĺňa skript
dao: "sthdf"

# Názov zápisu – dopĺňa používateľ
title: "test cases"

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

# ✅ Test Cases — OtakuPlanter (PRJ_004)

Testovacie scenáre overujúce funkčnosť senzoriky, audio subsystému, hysterézie a vodotesnosti 3D tlačeného kvetináča.

---

## Prehľad testovacích scenárov

| ID | Názov testu | Vstup / Kroky | Očakávaný výsledok | Priorita |
|---|---|---|---|---|
| **TC-01** | **Kalibrácia senzora na vzduchu a vo vode** | 1. Ponechať senzor na suchom vzduchu.<br>2. Ponoriť senzor po rysku do pohára s vodou.<br>3. Sledovať výpis v Serial Monitore. | Hodnota na vzduchu $\approx 720 - 800$, vo vode $\approx 280 - 340$. Kĺzavý priemer nekolíše o viac ako $\pm 3$ dieliky. | **High** |
| **TC-02** | **Spustenie alarmu smädu (Dry Trigger)** | 1. Vložiť senzor do suchého substrátu (`ADC > 620`).<br>2. Počkať na vyhodnotenie 16 vzoriek. | Prechod do stavu `ALERT_THIRSTY`, rozsvietenie/blikanie LED na pine `D6` a prehratie stopy `/mp3/0001.mp3` (*"Yamete kudasai!"*). | **High** |
| **TC-03** | **Reakcia na poliatie (Watered Trigger)** | 1. V stave `WAIT_WATER` naliať $100\text{ ml}$ vody ku koreňom.<br>2. Sledovať pokles ADC pod `WET_THRESHOLD` ($< 450$). | Okamžité (do $2\text{ s}$) prehratie stopy `/mp3/0002.mp3` (*"Arigatō!"*), LED prejde do pokojného stavu a stavový automat do `STANDBY`. | **High** |
| **TC-04** | **Overenie hysterézie a Cooldownu** | 1. Udržiavať vlhkosť na hrane prahu (`ADC` medzi $460$ a $610$).<br>2. Sledovať správanie počas 10 minút. | Žiadne falošné prepínanie stavov ani neustále opakovanie zvuku. Pripomienka smädu sa zopakuje až po uplynutí `REMINDER_COOLDOWN`. | **Medium** |
| **TC-05** | **Hydroizolačný test 3D výtlačku** | 1. Do vytlačenej kvetináčovej komory (bez elektroniky) naliať $250\text{ ml}$ zafarbenej vody na 24 hodín.<br>2. Skontrolovať papierovú servítku v suchej komore. | Servítka v elektronickej komore zostáva 100 % suchá; prebytočná voda vyteká výhradne cez drenážny kanálik. | **High** |

---
**Navigation:** [⬆️ Up](./index.md) · [🏠 Home](../index.md)
