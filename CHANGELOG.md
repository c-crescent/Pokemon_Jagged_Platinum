# Changelog

All notable changes to Pokémon Jagged Platinum are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

This project is based on the [pret/pokeplatinum](https://github.com/pret/pokeplatinum)
decompilation (upstream commit `485c400f9`). Only changes made on top of upstream
are listed here.

## [Unreleased]

### Quality of Life

- The game now boots directly past the opening cutscene and the title screen
  ("Press Start"). On boot, the save-integrity check runs and then the main menu
  opens:
  - With no save file, the game goes straight into the new-game intro
    (Professor Rowan).
  - With an existing save file, the Continue / New Game menu is shown.
  - Save-corruption warnings are still displayed as before.
  - The clear-save-data shortcut (hold **B + Up + Select**) now works when held at
  boot, because the title screen that used to read it is no longer shown.
  - Soft reset (**L + R + Start + Select**) follows the same boot path and also
  skips the intro.
- All text now prints 3x faster at every text speed setting (Slow, Mid and Fast), including battle text and while A/B is held to speed text up.
- Saving from the Start menu no longer asks for confirmation. The "saved the game" message no longer waits for the save jingle to finish.
- Writing the save to the cartridge is faster: only the parts of the save that changed since the last save are rewritten, instead of the whole file. 
- Pokémon Center healing is faster and takes the same time regardless of party size.
- HM Moves can be deleted normally.
- TMs are now reuseable.
- Running is now the default once you have the Running Shoes. Hold **B** to walk instead.
- The new-game introduction is much shorter. You can now skip the first battle with the rival.
