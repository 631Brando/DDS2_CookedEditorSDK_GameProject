# DDS2 Modding Guide: Your First Mod

This guide walks through **EXAMPLEMOD_P** (`Content/MODS/EXAMPLEMOD_P/`), a working example mod
that adds one new item — a "Modded Crowbar" — to Drug Dealer Simulator 2. Every piece of the
general modding workflow (mod folder setup, DataTable appending, packaging) is demonstrated in
this one small example. Read this guide alongside the actual assets in the editor.

> **Note:** this guide assumes you're already comfortable with Unreal Engine (Blueprints, the
> Content Browser, basic editor navigation). If you're brand new to UE modding, start with these
> first, then come back:
> - [UE Modding Guide by Dmgvol](https://github.com/Dmgvol/UE_Modding)
> - [RoboCop: Rogue City – Modding Guide](https://www.nexusmods.com/robocoproguecity/mods/3)

## Setup

Full setup instructions are in the [README](../README.md) — do that first. The short version:

1. Install the prerequisites: the **modified UE 5.3.2 ("ModKit") engine**, Visual Studio 2022 with
   the *Game development with C++* workload, and [UE4SS](https://github.com/UE4SS-RE/RE-UE4SS) if
   you're building a logic mod. **Stock Unreal Engine will not work** — the SDK depends on engine
   changes that mount the game's cooked containers and load a premade asset registry. Without them
   your Content Browser comes up empty.
2. Get the SDK and switch it to your engine build: right-click `DrugDealerSimulator2.uproject` →
   **Switch Unreal Engine version** → pick your ModKit build. The checked-in `EngineAssociation` is
   a GUID for someone else's source build and won't match yours.
3. Edit `GameInstallDirectory.txt` in the project root to point at your own game's pak folder
   (the one holding the `.utoc`/`.ucas` files). It ships with the default Steam path.
4. Open `DrugDealerSimulator2.uproject`. If prompted to rebuild project modules, click **Yes**.
   The first open is slow — it's mounting and indexing the whole retail game.
5. In the editor, go to `Content/MODS` — every mod folder lives here, including the
   `EXAMPLEMOD_P` example this guide walks through. You should also see the game's own content
   (`/Game/DataTables`, `/Game/Blueprints`, …). If `Content/MODS` is there but the game's folders
   aren't, step 3 is wrong.

## How DDS2 mods load

Mods run through **UE4SS**. At game start, UE4SS scans loaded mod content for a Blueprint
class named `ModActor` and automatically spawns one instance of it into the world — you never
place it in a level yourself, and you never call it from anywhere. This is why every mod's
folder contains a Blueprint literally named `ModActor`: that exact name is the hook UE4SS looks
for. Whatever logic you want your mod to run on startup goes in that Blueprint's `Event BeginPlay`.

This only applies to **logic mods** — mods that need code to run at game start, like appending
rows to a DataTable (EXAMPLEMOD_P is a logic mod). A pure **content patch** that just overrides
existing assets by path (a replaced texture, mesh, etc., with no runtime behavior) doesn't need
a `ModActor` or UE4SS at all — it's still just a PrimaryAssetLabel'd folder, but nothing spawns.

## Anatomy of EXAMPLEMOD_P

Three assets, three jobs:

| Asset | Purpose |
|---|---|
| `ModActor.uasset` | The entry point UE4SS spawns. Contains the logic that runs your mod. |
| `DataTables/CustomItemDatabase.uasset` | A new DataTable holding just *your* mod's rows. |
| `Label_EXAMPLE.uasset` | A `PrimaryAssetLabel` that tells the cooker to include this folder's content in the packaged mod, even though nothing in the base game references it. |

## Step 1 — Set up your mod folder

Create a new folder under `Content/MODS/`, named after your mod with a `_P` suffix
(e.g. `Content/MODS/YourModName_P/`) — the `_P` matches the pakchunk naming convention your
packaged mod ships as.

## Step 2 — Add a PrimaryAssetLabel

Right-click your mod folder → **Miscellaneous → Data Asset** → pick `PrimaryAssetLabel`. Name it
whatever you like (`Label_EXAMPLE` in this example). Set:

- **Cook Rule** → `Always Cook` — without this, the cooker strips your assets out entirely, since
  nothing in the base game points at them.
- **Label Assets In My Directory** → `true` — auto-includes everything you drop in this folder,
  so you don't have to hand-list every asset.
- **Chunk Id** → a unique number not used by another installed mod, suggested range **1000–9999**
  (this example uses `9999`) — just enter 4 random numbers like `2575`. This is what buckets your
  content into its own pak chunk when the game cooks, and it's what you'll filter by when sorting
  packaged output later (Step 6).

You only need to create this once per mod; you won't touch it again unless you're troubleshooting
packaging.

## Step 3 — Create your ModActor

Right-click your mod folder → **Blueprint Class** → parent it to **Actor** (plain `Actor`, nothing
DDS2-specific needed). Name it exactly `ModActor` — UE4SS finds it by this name. **Do not rename
it** if you're building a logic mod; UE4SS won't find anything else.

In `EventGraph`, off `Event BeginPlay`, the working pattern (exactly what EXAMPLEMOD_P does):

```
Event BeginPlay
  → Do Once                          (guards against BeginPlay firing more than once)
    → Sequence
        Then 0 → Append Data Tables  (the actual work — see Step 5)
                   → To String (Integer) on the return value
                   → Append (+ " DT row(s) appended to target DataTable")
                   → Print to Mod Loader   (surfaces the result in UE4SS's log,
                                             so you can confirm your mod actually ran)
```

`Do Once` isn't optional set-dressing — without it, anything that mutates a shared DataTable in
`BeginPlay` could run twice if the actor is ever respawned, silently duplicating your changes.

`Print to Mod Loader` is a plain custom function (see `ModActor`'s function list) that just
forwards a string — use it liberally while testing so you have log confirmation your mod loaded
and did what you expected, not silence either way.

## Step 4 — Build your custom DataTable

Right-click `DataTables/` inside your mod folder → **Miscellaneous → Data Table** → pick the
**same row struct** the table you're targeting uses. This is a hard requirement, not a
recommendation — `Append Data Tables` merges row-for-row and needs matching layouts.

To find the right struct for a given base-game table: open the base table (e.g.
`/Game/DataTables/Databases/ItemDatabase`) and check its Row Structure — for the item database
that's `ItemData`. EXAMPLEMOD_P's `CustomItemDatabase` uses that same struct.

Add one row per thing you're introducing. Two cases:

- **Adding something new** (what this example does): give the row a `Name` that doesn't exist
  anywhere in the target table — EXAMPLEMOD_P uses `MODEXAMPLE_ITEMID`. Fill in every field the
  struct expects (see the example row for the full `ItemData` field list — display name/
  description via localized text, icon texture, category, weight, value, melee weapon ID, etc.)
- **Overriding something existing**: give the row the *exact same* `Name` as the row you want to
  change in the target table, and set `bOverwriteExisting = true` on the append call (Step 5) so
  your version wins instead of being skipped.

## Step 5 — Call Append Data Tables

Back in `ModActor`'s `EventGraph`, add an **Append Data Tables** node (from
`AppendDatatableHelper`) and set:

- **Target Data Table** → the real base-game table you're extending (`ItemDatabase` in this
  example).
- **Source Data Table** → your own table from Step 4 (`CustomItemDatabase`).
- **Overwrite Existing** → `true` if you want your rows to replace any matching existing row by
  name; `false` to skip rows that would collide.

It returns an `int` — the number of rows actually merged — which is what gets printed to the mod
loader log in the example, so a successful run shows something like `1 DT row(s) appended to
target DataTable`. If you ever see `0`, your row's `Name` matched something unexpected, or the
source table is empty — check there before assuming the merge silently failed elsewhere.

**Reusing this for a second table:** EXAMPLEMOD_P's graph has a second, disconnected
`Append Data Tables` + `Print to Mod Loader` pair sitting off to the side, unwired, with default
values. That's a deliberate copy-paste starting point — duplicate that pair, wire it into your
`Sequence` node as another branch, and point it at a different Target/Source pair if your mod
touches more than one table (a new DataTable per target table you're extending, same pattern
each time).


## Step 6 — Package it

The verified process:

1. **Platforms → Windows → Package Project.**
2. Packaged output lands in `Windows/DrugDealerSimulator2/Content/Paks/`. This packages the
   *whole* project, so you'll see pak/ucas/utoc sets for every chunk, not just yours — **only
   keep the `.pak`, `.ucas`, and `.utoc` files matching your mod's Chunk Id** from Step 2; discard
   the rest.
3. **For logic mods** (anything using `ModActor`): these three files need UE4SS installed to run.
   Place them in `Paks/LogicMods/` inside the game's install, and **rename them to match your mod
   folder's name**, not the chunk number — e.g. `EXAMPLEMOD_P.pak`, `EXAMPLEMOD_P.ucas`,
   `EXAMPLEMOD_P.utoc`.
4. Whichever kind of mod you're shipping, **the mod folder name and the output filenames must all
   end in `_P`** — that suffix is what makes both logic and content patches load correctly.


## Testing in the editor

UE4SS is a runtime injector for the shipped game — **it does not run in PIE**. Nothing spawns your
`ModActor` when you hit Play in the editor, so a logic mod that looks completely silent in PIE may
still be fine in the packaged game.

To exercise the logic before packaging, drag `ModActor` into the level manually (or spawn it) so
`BeginPlay` fires. Just remember that's a test-only placement: the real mod relies on UE4SS
spawning it, and you don't want a stray placed copy in anything you ship.

Keep test-only assets out of your mod folder entirely. Anything inside it gets swept up by the
PrimaryAssetLabel's *Label Assets In My Directory*, so a scratch mesh or a debug widget left in
there ships to everyone who installs your mod. Park that work in a folder outside
`Content/MODS/YourModName_P/`.

## Common mistakes

- **Row struct mismatch** between your custom table and the target table — the append will fail
  or silently do nothing useful. Always match the target's Row Structure exactly.
- **Forgetting `Always Cook`** on the PrimaryAssetLabel — your assets get stripped at cook time
  since nothing else references them, and your mod ships with nothing in it.
- **No `Do Once`** guarding a DataTable-mutating `BeginPlay` — safe in the common case, but don't
  assume `BeginPlay` only ever fires once.
- **Wrong `Name` on a row when trying to override an existing item** — it just becomes a new,
  separate item instead of replacing the one you meant to change. Double-check the exact `Name`
  of the row you're targeting in the base table before setting `bOverwriteExisting`.
- **Shipping the wrong chunk's pak/ucas/utoc, or forgetting to rename them for `LogicMods`** —
  Package Project outputs every chunk in the game, not just yours; grab only the three files
  matching your Chunk Id, and for logic mods rename them to your mod folder's name before placing
  them in `LogicMods`.
- **Folder or output filenames missing the `_P` suffix** — both logic and content patches fail to
  load without it.
