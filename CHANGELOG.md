# Changelog

All notable changes to Pokémon Jagged Platinum are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

This project is based on the [pret/pokeplatinum](https://github.com/pret/pokeplatinum)
decompilation (upstream commit `485c400f9`). Only changes made on top of upstream
are listed here.

## [0.2.0]

### Added

### Updated

- Battle Style Option is now SET by default.
- Button Mode is now L=A by default.
- Text Speed is now Fast by default.
- The game now runs 2x faster. Most delays in battle are now removed.
- Both sides of a battle now appears simultaneously, reducing the delay before the player can take an action.
- Progression HMs no longer require a Pokemon knowing the move, just the respective badge & HM / TM in your bag.

### Removed

## [0.1.0]

### Added

- Added level caps based on various boss battles.
- In L=A Button Mode, L rapidly presses A and R rapidly presses B.
- Rare Candies can now be used in multiples at once (respecting level caps).
- Repels now have a reuse prompt.
- After entering the Hall of Fame, the player can encounter an infinite number of clones of the Pokémon in the lead slot in Sandgem Town Lab.
- The Pokédex has National Dex features from the start. Postgame content still unlocks when Prof. Oak upgrades your Pokédex.

### Updated

- All Land / Surfing / Rod encounter slots are normalised to scale down linearly to a minimum of 5%.
- The game now boots directly past the opening cutscene and the title screen, preserving the clear-save-data and soft-reset shortcuts.
- All text now prints 3x faster at every text speed setting (Slow, Medium, and Fast).
- Saving from the Start menu no longer asks for confirmation. The "saved the game" message no longer waits for the save jingle to finish.
- Writing the save to the cartridge is faster.
- Pokémon Center healing is faster and takes the same time regardless of party size.
- HM moves can be deleted normally.
- TMs are now reusable.
- Running is now the default once you have the Running Shoes. Hold **B** to walk instead.
- The new-game introduction is much shorter. You can now skip the first battle with the rival and decline going to Lake Verity.
- The catching tutorial on Route 202 is now optional, and Dawn/Lucas gives you 10 Poké Balls instead of 5.
- Reading the PC in Dawn/Lucas's room in Sandgem Town gives you 999 Rare Candies, and checking the trash can gives you 999 Master Balls.
- Fishing can no longer fail, but can still be cancelled.
- Simplified all evolution lines and replaced all trade evolutions; see [FEATURES.md](FEATURES.md) for details.