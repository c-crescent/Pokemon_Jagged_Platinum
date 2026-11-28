# Pokémon Jagged Platinum

This is a WIP ROM Hack based on the [Pokémon Platinum Disassembly](https://github.com/pret/pokeplatinum).

## Project Goals

- Ehance the game's experience with a variety of Quality of Life changes, mostly focused on speed during gameplay and reducing grind.
- Modernise the battle systems in certain places to reduce frustration while still keeping the gen 4 feel.
- Make it possible for the player to build a living dex in a single save file. Notably, all Pokémon except Legendary / sub-Legendary / Mythical will be available before the first Elite 4.
- Rebalance the game to highlight gen 4 Pokémon and give underpowered Pokémon more notable niches through availability and / or buffs, ultimately to give players more varied and unique tool set during the adventure.
- Increase the difficulty of the experience to make boss fights genuinely engaging and satisfying through the use of improved trainer AI, teambuilding, and movesets. The game is also built around hardmode (level caps, no items in battle, Set Mode)

## AI Disclaimer

A lot (about 80%) of the code in this project was written by Claude (Anthropic's AI model). All changes are directed, supervised, and tested manually by me.

# Features

## Quality of Life

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
- Rare Candies can now be used in multiples at once (respecting level caps).
- Repels now have a reuse prompt.

## Balance
### Abilities
- Storm Drain and Lightning Rod now make the user immune to Water and Electric respectively, and raises the user's Special Attack by 1 stage when hit, like later gens.
### Mechanics
* Full paralysis chance is now 1 in 8 instead of 1 in 4, and now affects Magic Guard Pokemon
### Moves

- Acid
  - BP: 60(+20)
  - Now a viable mid game move.

- Aqua Tail
  - BP: 100(+10)
  - Now a viable alternative to Waterfall.
    
- Air Slash
  - BP: 80(+5)
  * Now more inline with other mid-late game moves.
 
- Assurance
  - Class: Special
  - Now an early-mid game Special Dark move.

- Avalanche
  * BP: 85(+25)
  * Acc: 90(-10)
  * Priority: 0(+4)
  * Now has a 30% flinch chance and no other special effects.
  * A clone of Icicle Crash since a stronger physical Ice move was needed.
 
- Chatter
  - BP: 200(+140)
  - Chatot-specific buff.

- Crab Hammer
  - BP: 120(+30)
  - Now a viable signature move.
    
- Defog
  - Now also clears hazards from the user's side.
  - Another viable hazard control move.

- Dragon Rush
  - BP: 60(-40)
  - Acc: 100(+25)
  - PP: 25(+15)
  - Eff%: 30(+10)
  - Now an early-mid game physical Dragon equivalent of Bite.

- Earth Power
  - BP: 100(+10)
  - Now special equivalent of Earthquake.
  
- Fire Fang
  - BP: 70(+5)
  - Universal buffs to Fang moves.

- Ice Fang
  - BP: 70(+5)
 
- Knock Off
  - BP: 65(+40)
  - PP: 10(-10)
  - Effect: Now also does 50% more damage when the target has an item.
  - Now is similar to modern Knock Off.

- Leech Life
  - BP: 40(+20)
  - Class: Special
  - Now an early game special Bug move.
    
* Mud Bomb
  * BP: 80(+15)
  * Acc: 95(+10)
  * Now a viable late game move.
    
- Mud-Slap
  - BP: 35(+15)
  - Now a viable early-game move.

- Poison Fang
  - BP: 70(+20)
  - Acc: 95(-5)
  - Eff%: 10(-20)
  - Now similar to elemental Fang moves.
    
- Power Gem
  - BP: 95(+25)
  - Now a standard late game move.

- Psycho Cut
  - BP: 75(+5)
  - Now a standard mid-late game move.

- Rapid Spin
  - BP: 50(+30)
  - Now also raises the user's speed by 1 stage.
  - Better hazard control and viable as a setup move.

- Sludge
  - BP: 90(+25)
  - Now a viable late game move

- Sludge Bomb
  - BP: 120(+30)
  - Acc: 90(-10)
  - PP: 5(-5)
  - Now a viable ultra-tier move.

- Smelling Salt
  - BP: 45(-15)
  - Type: Psychic (was Normal)
  - Now an early game physical Psychic move.

- Smog:
  - BP: 45(+25)
  - Now a viable early game move.

- Spark
  - BP: 55(-10)
  - PP: 25(+5)
  - Nerfed to be distinct from Thunder Fang. Physical Electric types now get Volt Tackle to compensate in late game.

- Thunder Fang
  - BP: 70(+5)
 
- Twineedle
  - BP: 45(+25)
  - Now an actual move worth using.

- Zen Headbutt
  - BP: 100(+20)
  - Now an ultra-tier move.

## Living Dex

- After entering the Hall of Fame, the player can encounter an infinite number of clones of the Pokémon in the lead slot in Sandgem Town Lab.
- All Land / Surfing / Rod encounter slots normalised to scale down linearly to a minimum of 5%.

### Evolutions

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

## Difficulty

- Added a level caps according to various boss battles.
