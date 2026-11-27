# Changelog

All notable changes to Pokémon Jagged Platinum are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

This project is based on the [pret/pokeplatinum](https://github.com/pret/pokeplatinum)
decompilation (upstream commit `485c400f9`). Only changes made on top of upstream
are listed here.

## [Unreleased]

### Quality of Life

- The game now boots directly past the opening cutscene and the title screen.
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
- The new-game introduction is much shorter. You can now skip the first battle with the rival and decline going to Lake Verity.
- The Pokédex has National Dex features from the start. Postgame content still unlocks when Prof. Oak upgrades your Pokédex.
- The catching tutorial on Route 202 is now optional, and Dawn/Lucas gives you 10 Poké Balls instead of 5.
- Reading the PC in Dawn/Lucas's room in Sandgem Town gives you 999 Rare Candies, and checking the trash can gives you 999 Master Balls.
- Fishing can no longer fail, but can still be cancelled.
- In L=A Button Mode, L turboes A and R turboes B.

### Living Dex Compatability

- After entering the Hall of Fame, the player can encounter an infinite number of clones of the Pokémon in the lead slot in Sandgem Town Lab.
- All Land / Surfing / Rod encounter slots normalised to scale down linearly to a minimum of 5%.

#### Evolutions

Simplified all evolution lines and relaced all trade evolutions.

- Most baby Pokemon (Azurill, Bonsly, Budew, Happiny, Chingling, Cleffa, Igglybuff, Mime Jr., Munchlax, Pichu, Togepi) now evolve at 10.
- Nosepass, Piloswine, Sneasel, Gligar, and Magneton now evolve at 36.
- Tangela and Yanma now evolve at 33.
- Golbat now evolves at 30.
- Aipom now evolves at 28.
- Buneary, Riolu, and Munchlax now evolve at 20.
- Chansey now evolves at 42.
- All trade evolutions with held items (Politoed, Slowking, Steelix, Rhyperior, Kindra, Scizor, Electivire, Magmortar, Porygon 2, Porgyon-Z, Dusknoir, Huntail, Gorebyss) now evolve when leveling up with their specific item held.
- Feebas now evolves at 20.
- Graveler now evolves at 36.
- Lickitung now evolves at 38.
- Machoke now evolves at 40.
- Kadabra now evolves at 42.
- Haunter now evolves at 44.
- Eevee
  - evolves to Leafeon with Leaf Stone
  - evolves to Glaceon if leveled up holding a Never Melt Ice
  - evolves to Umbreon with Dusk Stone
  - evolves to Espeon with Dawn Stone
### Difficulty

- Added a level caps according to various boss battles.
