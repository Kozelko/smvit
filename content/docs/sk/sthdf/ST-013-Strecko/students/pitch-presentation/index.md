---
# 🧩 Versioning – systém dopĺňa automaticky
fm_version: "1.0.1"

# Dátum buildu – generuje skript
fm_build: "2026-10-05T10:01:19.207066+00:00"

# Poznámka k verzii – voliteľné
fm_version_comment: ""


# 🆔 IDENTITY --------------------------------------------------------

# ID generuje CLI / skript

# Unikátne UUID – generuje skript
guid: "783dead3-19fd-475d-808f-b5340256cdab"


# 🧭 CONTEXT ---------------------------------------------------------

# DAO / doména (knife, sdlc, q12, 7ds...) dopĺňa skript
dao: "sthdf"

# Názov zápisu – dopĺňa používateľ
title: "pitch presentation"

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

# 🎤 Pitch Presentation — OtakuPlanter (PRJ_004)

## 1. Problém
- Izbové rastliny často vysychajú a hynú, pretože študenti a pracujúci ľudia zabúdajú na ich pravidelné polievanie.
- Bežné kvetináče sú statické, pasívne a nudné objekty. Komerčné smart senzory posielajú len notifikácie na mobil, ktoré používateľ rýchlo ignoruje.
- Chýba emocionálne a interaktívne prepojenie s rastlinou v domácom pracovnom priestore.

## 2. Riešenie
- **OtakuPlanter:** Interaktívny 3D tlačený kvetináč v tvare anime postavičky s integrovanou elektronikou.
- **Hlasová spätná väzba:** Keď kapacitný senzor zaznamená sucho, postavička sa hlasovo ozve v japončine (napr. *"Yamete kudasai, napoj ma!"*).
- **Potvrdenie zaliatia:** Po pridaní vody postavička ihneď reaguje spokojnou hláškou (*"Arigatō!"*) a svetelnou indikáciou.
- **Dvojitá komora:** Fyzické a bezpečné oddelenie zeminy s vodou od priestoru pre elektroniku.

## 3. Hodnota
- **Záchrana rastlín:** Zábavná a neprehliadnuteľná prevencia vyschnutia.
- **Gamifikácia & Dizajn:** Originálny dizajnový prvok pre fanúšikov anime, technológií a štýlových doplnkov na pracovný stôl.
- **Bezúdržbovosť elektroniky:** Kapacitné snímanie nepodlieha korózii, nízka spotreba mikrokontroléra.

## 4. Biznis model / Monetizácia (Hypotéza)
- **Open-source + DIY stavebnica:** Voľné STL modely a kód; predaj kompletnej hardvérovej stavebnice (BOM + PCB + senzory).
- **Zberateľské edície:** Rôzne custom 3D modely postavičiek a vymeniteľné zvukové profily (balíčky hlášok na microSD).
- **B2C e-shop predaj:** Hotový plug-and-play zostavený produkt pre fanúšikovskú komunitu.

## 5. Tím
- **Bc. Peter Brandajský (ST004):** Project Lead & Hardware/Firmware Developer (Informačná bezpečnosť, firmware na Arduino/ESP32, kalibrácia senzorov a DFPlayer audia).
- **Bc. Timotej Strečko (ST013):** 3D Designer & Systems Architect (DataOps analytik, 3D CAD modelovanie tela, riešenie drenáže a hydroizolácie, systémová architektúra 7Ds).

## 6. Call to action / Výzva
- **Čo potrebujeme na realizáciu:**
  1. Schválenie konceptu v rámci predmetu STHDF.
  2. Využitie FabLab infraštruktúry (3D tlačiarne, spotreba PLA/PETG filamentu).
  3. Spätná väzba od vyučujúceho k návrhu architektúry a mechanickému oddeleniu elektroniky od vody.

---

## 🛠️ Štruktúra pitchu (3–5 slajdov)
1. **Slajd 1 (Titulka):** `PRJ_004_AnimeSmartPlanter` (OtakuPlanter) — Tím ST004 & ST013.
2. **Slajd 2 (Problém):** Prečo rastliny hynú a prečo bežné kvetináče zlyhávajú.
3. **Slajd 3 (Riešenie & Systém):** Senzor vlhkosti $\rightarrow$ MCU $\rightarrow$ DFPlayer audio hlášky $\rightarrow$ 3D telo.
4. **Slajd 4 (Digitálna fabrikácia):** CAD návrh postavičky s bezpečnou suchou komorou.
5. **Slajd 5 (Plán & Tím):** Rozdelenie úloh a harmonogram do januára.

## ⏱️ Časovanie
- **Prezentácia:** 3–5 minút
- **Q&A:** 2 minúty

---

## Navigácia
- [↩️ Späť](../index.md)
