---
# 🧩 Versioning – systém dopĺňa automaticky
fm_version: "1.0.1"

# Dátum buildu – generuje skript
fm_build: "2026-10-05T10:01:14.410643+00:00"

# Poznámka k verzii – voliteľné
fm_version_comment: ""


# 🆔 IDENTITY --------------------------------------------------------

# ID generuje CLI / skript

# Unikátne UUID – generuje skript
guid: "a6098079-4249-4e9f-bc0a-04f4f658dc86"


# 🧭 CONTEXT ---------------------------------------------------------

# DAO / doména (knife, sdlc, q12, 7ds...) dopĺňa skript
dao: "sthdf"

# Názov zápisu – dopĺňa používateľ
title: "non functional"

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

# 🔧 Non-Functional Requirements (NFR) — OtakuPlanter (PRJ_004)

Nefunkčné požiadavky definujú kvalitatívne, bezpečnostné, prevádzkové a mechanické vlastnosti systému **OtakuPlanter**.

---

## Zoznam nefunkčných požiadaviek

| ID | Kategória | Požiadavka | Metrika / Cieľová hodnota |
|---|---|---|---|
| **NFR-01** | **Odolnosť voči korózii (Longevity)** | Meranie vlhkosti musí prebiehať bez priameho kontaktu nechráneného kovu s vlhkým substrátom | Životnosť senzora v pôde $> 12\text{ mesiacov}$ bez oxidácie (použitie kapacitného senzora v1.2 s lakovaným okrajom) |
| **NFR-02** | **Elektrická bezpečnosť a vodotesnosť** | Suchá komora s MCU a audio modulom musí byť hydroizolačne oddelená od mokrej zóny | 4 perimetre pri 3D tlači z PETG, hrúbka prepážky $\ge 3.2\text{ mm}$, bezpečné napätie $5\text{ V DC}$ |
| **NFR-03** | **Odozva pri poliatí (Latency)** | Okamžitá zvuková reakcia po zaliatí smädnej rastliny | Odozva od poklesu ADC hodnoty pod `WET_THRESHOLD` po začiatok prehrávania audia $\le 2.0\text{ s}$ |
| **NFR-04** | **Stabilita merania (Noise Immunity)** | Odolnosť voči kolísaniu ADC a falošným poplachom na hranici vyschnutia | 16-bodový kĺzavý priemer + pásmo hysterézie šírky min. $150\text{ ADC dielikov}$ |
| **NFR-05** | **Akustická kvalita** | Zrozumiteľný hlasový výstup bez počuteľného bzučania na pozadí | Odstup rušenia zabezpečený $1\text{ k}\Omega$ rezistorom na RX linke a $100\,\mu\text{F}$ kondenzátorom na napájaní; akustická mriežka v 3D modeli |
| **NFR-06** | **Samostatnosť (Zero-Cloud / Privacy)** | Plná funkčnosť offline bez potreby Wi-Fi, cloudového servera alebo smartfónu | $100\,\%$ lokálne spracovanie na mikrokontroléri |
| **NFR-07** | **Udržateľnosť a servisovateľnosť** | Jednoduchý prístup k elektronike a MicroSD karte pri údržbe | Odnímateľné spodné servisné veko na $4\times\text{ M3}$ skrutky; čitateľný a komentovaný Arduino kód |

---
**Navigation:** [⬆️ Up](./index.md) · [🏠 Home](../index.md)
