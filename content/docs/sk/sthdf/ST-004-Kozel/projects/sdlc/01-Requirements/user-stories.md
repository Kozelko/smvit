---
# 🧩 Versioning – systém dopĺňa automaticky
fm_version: "1.0.1"

# Dátum buildu – generuje skript
fm_build: "2026-10-05T10:01:14.411061+00:00"

# Poznámka k verzii – voliteľné
fm_version_comment: ""


# 🆔 IDENTITY --------------------------------------------------------

# ID generuje CLI / skript

# Unikátne UUID – generuje skript
guid: "3e7be7d2-4f6c-4f4f-87e8-806e2050f535"


# 🧭 CONTEXT ---------------------------------------------------------

# DAO / doména (knife, sdlc, q12, 7ds...) dopĺňa skript
dao: "sthdf"

# Názov zápisu – dopĺňa používateľ
title: "user stories"

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

# 🧑‍🤝‍🧑 User Stories — OtakuPlanter (PRJ_004)

Používateľské príbehy definujú funkčné požiadavky na interaktívny kvetináč **OtakuPlanter** z pohľadu koncovej používateľky (priateľky, fanúšičky anime a izbových rastlín) aj z pohľadu tvorcov a údržby zariadenia.

---

## Prehľad používateľských príbehov

| ID | Rola (As a...) | Požiadavka (I want...) | Prínos (So that...) | Priorita |
|---|---|---|---|---|
| **US-01** | Majiteľka rastliny | Aby kvetináč pri vyschnutí substrátu prehral japonskú hlasovú hlášku (*"Yamete kudasai!"*) | Aby som nezabudla rastlinu poliať ani počas náročného týždňa bez nutnosti inštalovať mobilnú aplikáciu | **High (Must)** |
| **US-02** | Majiteľka rastliny | Aby mi kvetináč po naliatí vody okamžite poďakoval (*"Arigatō!"*) | Aby som mala okamžitú pozitívnu emočnú spätnú väzbu a vedela, že vody je už dostatok | **High (Must)** |
| **US-03** | Majiteľka rastliny | Aby kvetináč neopakoval zvukovú výzvu neustále každú sekundu, ani nevyrušoval uprostred noci | Aby zariadenie v izbe nepôsobilo otravne, ale ako príjemný spoločník | **High (Must)** |
| **US-04** | Fanúšička anime | Aby mal kvetináč estetický 3D tlačený dizajn s anime postavičkou a podsvietenými očami (LED) | Aby slúžil ako štýlová dekorácia na pracovnom stole a vizuálne signalizoval smäd aj pri stíšenom zvuku | **Medium (Should)** |
| **US-05** | Používateľka / Tvorca | Aby boli všetky elektronické súčiastky bezpečne oddelené od vody a vlhkej hliny | Aby pri preliatí kvetináča nedošlo ku skratu ani k poškodeniu USB napájania | **High (Must)** |
| **US-06** | Tvorca / Údržbár | Aby som mohol jednoducho vymeniť MP3 súbory na MicroSD karte | Aby bolo možné kedykoľvek zmeniť hlas postavičky alebo pridať nové anime hlášky bez preprogramovania čipu | **Low (Could)** |

---

## Akceptačné kritériá (Acceptance Criteria)

- **AC-01 (Detekcia sucha):** Ak priemerná hodnota z kapacitného senzora (16 vzoriek) prekročí prah `DRY_THRESHOLD` ($> 620$), systém do 5 sekúnd prejde do stavu `ALERT_THIRSTY`, rozsvieti/rozbliká varovnú LED a prehrá zvukovú stopu `0001.mp3`.
- **AC-02 (Detekcia poliatia s hysteréziou):** Ak je systém v stave smädu (`WAIT_WATER`) a hodnota senzora klesne pod `WET_THRESHOLD` ($< 450$), systém do 2 sekúnd prehrá ďakovnú stopu `0002.mp3` a prepne LED do pokojného režimu.
- **AC-03 (Cooldown proti spamu):** Medzi dvoma zvukovými pripomienkami smädu musí uplynúť minimálne nastavený interval (`REMINDER_COOLDOWN`), aby nedochádzalo k neustálemu opakovaniu stopy.
- **AC-04 (Vodotesnosť komôr):** Naliatie $200\text{ ml}$ vody do kvetináčovej komory nesmie spôsobiť prienik ani jednej kvapky do suchej komory s elektronikou.

---
**Navigation:** [⬆️ Up](./index.md) · [🏠 Home](../index.md)
