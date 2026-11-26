# DDS2 Cooked Editor SDK

An Unreal Engine 5.3.2 project for building mods for **Drug Dealer Simulator 2**.

The game ships cooked. Normally that means you cannot open its content in the editor at all —
cooked packages have no editor data, and the Content Browser has nothing to enumerate. This
project is paired with a **modified UE 5.3.2 engine build** that mounts the retail game's IoStore
containers and reads a premade asset registry, so the game's real assets show up in the Content
Browser and your mod can reference them directly.

That pairing is the whole point of this SDK, and it is also its main requirement: **this project
will not work on a stock Unreal Engine install.**

---

## Requirements

| | |
|---|---|
| **Modified UE 5.3.2 ("ModKit") engine** | Source-built. Stock UE 5.3.2 will not work — see below. |
| **Drug Dealer Simulator 2** | Installed. The SDK mounts its paks; it does not contain game content. |
| **Visual Studio 2022** | With the *Game development with C++* workload. |
| **[UE4SS](https://github.com/UE4SS-RE/RE-UE4SS)** | Only needed for *logic* mods (anything using a `ModActor`). |

### Why stock Unreal will not work

Two engine-level changes this project depends on:

- **Premade asset registry in the editor.** The fork sets
  `ASSETREGISTRY_ENABLE_PREMADE_REGISTRY_IN_EDITOR=1` as a global definition and flips the
  editor default to *on* (stock UE requires opting in with `-EnablePremadeAssetRegistry`; the
  fork instead accepts `-DisablePremadeAssetRegistry` to turn it off). This is what makes the
  editor load `AssetRegistry.bin` from the project root and populate the Content Browser with the
  game's cooked assets.
- **Game container mounting.** The fork reads `GameInstallDirectory.txt` from the project root
  and mounts the game's `.utoc`/`.ucas` containers. Loading cooked packages through the IoStore
  path preserves the cooker's export-bundle ordering, which resolves circular package
  dependencies that the loose loader cannot.

On stock UE both are absent: you get an empty Content Browser and unresolvable game assets.

---

## Setup

1. **Build the modified engine** and register it. The `.uproject`'s `EngineAssociation` is a local
   GUID pointing at a source build, so it will not match yours — right-click
   `DrugDealerSimulator2.uproject` → **Switch Unreal Engine version** → pick your ModKit build.
   (Or just clear the `EngineAssociation` value and let the editor prompt you.)

2. **Point the SDK at your game install.** Edit `GameInstallDirectory.txt` in the project root so
   it holds the absolute path to the folder containing the game's `.utoc`/`.ucas` files:

   ```
   C:\Program Files (x86)\Steam\steamapps\common\Drug Dealer Simulator 2\DrugDealerSimulator2\Content\Paks
   ```

   One path per line; the first non-empty line that is not a comment (`#` or `;`) is used. **This
   file ships with the default Steam path and almost certainly needs changing for your machine** —
   if the Content Browser comes up empty, check this first.

3. **Open `DrugDealerSimulator2.uproject`.** Say **Yes** if prompted to rebuild project modules.
   First open is slow — it is mounting and indexing the whole retail game.

4. **Check it worked.** You should see the game's content (`/Game/DataTables`, `/Game/Blueprints`,
   …) in the Content Browser alongside `Content/MODS`. If `Content/MODS` is there but the game's
   folders are not, step 2 is wrong.

5. **Read [`Docs/ModdingGuide.md`](Docs/ModdingGuide.md)** and open `Content/MODS/EXAMPLEMOD_P`
   next to it.

---

## Layout

| Path | What it is |
|---|---|
| `Content/MODS/` | Where every mod lives. Ships with `EXAMPLEMOD_P`, a complete working example. |
| `Source/DrugDealerSimulator2/` | Header/stub mirror of the game's C++ classes (see below). |
| `Plugins/` | Plugins the game's project depends on. |
| `Config/` | Project config, including the chunked-packaging setup mods rely on. |
| `AssetRegistry.bin` | **Do not delete.** The premade registry the editor loads at startup to see cooked game assets. |
| `GameInstallDirectory.txt` | Path to your game's pak folder. Edit this. |
| `Docs/ModdingGuide.md` | Step-by-step walkthrough of building a mod. |

---

## About the C++ in `Source/`

`Source/DrugDealerSimulator2/` mirrors the game's native classes so Blueprints have correctly
reflected types to bind against — matching class names, properties, function signatures, and
`UFUNCTION`/`UPROPERTY` metadata.

**The implementations are not included.** Function bodies are stubs that return defined values
and clear their out-params. The module compiles and links, and that is enough to give Blueprints
a real API surface to work with, but calling into these classes from C++ yields empty or zero
results — the actual behaviour lives in the shipped game binary at runtime.

`InventoryComponent.cpp` documents the scope of the stubs. The SDK also contains original helpers:

- `AppendDatatableHelper::AppendDataTables` — the DataTable merge helper mods use.
- `PlayerCharacterMaster::Tick` — restores basic mouse-look in PIE by polling raw mouse delta off
  the controller, so testing does not depend on the game's Enhanced Input setup being wired up.
- `-DDS2PIEInventoryTransfers` — enables ordinary whole-stack transfers, container stock
  and inventory weight in authoritative standalone PIE.

### Ordinary hideout crafting in PIE

Start an isolated editor session with both `-DDS2PIEInventoryTransfers` and
`-DDS2PIEOrdinaryCraft`. This enables ordinary stock counting and debits, free-slot
and stack-space reads, hideout storage accounting, and the live crafting queue in
authoritative standalone PIE. The station's existing Blueprint checks the output
bin, retries when it is full, and acknowledges each completed lot.

Use a disposable test profile with a known deterministic recipe that produces one
ordinary item type, such as the DIY Table recipe `C-STASH-FOOD`. The native queue
does not accept recipes with substance inputs or outputs, random outputs, waste,
or additional feature and equipment requirements. Scope requests to supported
recipes before the cooked request path debits ingredients. Cancellation, time
catch-up, save/load, multiplayer and Shipping behavior are outside this test path.

---

## Making a mod

The short version, in full detail in [`Docs/ModdingGuide.md`](Docs/ModdingGuide.md):

1. Create `Content/MODS/YourModName_P/` — the `_P` suffix matters.
2. Add a `PrimaryAssetLabel` with **Cook Rule = Always Cook**, **Label Assets In My Directory =
   true**, and a unique **Chunk Id**.
3. For a logic mod, add an Actor Blueprint named exactly `ModActor` — UE4SS finds it by that name
   and spawns it at game start.
4. Package the project, then keep only the `.pak`/`.ucas`/`.utoc` matching your Chunk Id.

`EXAMPLEMOD_P` does all of this to add one item, a Modded Crowbar.

---

## License

MIT — see [`LICENSE`](LICENSE).

This covers the SDK's own code and documentation only. It does **not** cover Drug Dealer
Simulator 2's assets or code, which remain the property of their respective owners. No game
content is redistributed here; you supply that with your own copy of the game. Bundled plugins
under `Plugins/` carry their own licenses.
