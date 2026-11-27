#ifndef POKEPLATINUM_LEVEL_CAP_H
#define POKEPLATINUM_LEVEL_CAP_H

#include "pokemon.h"
#include "savedata.h"

/**
 * Gets the current level cap from the given save data. Pokemon at or above the
 * cap gain no EXP and cannot use Rare Candies. The cap itself is set up in the
 * configuration table at the top of src/level_cap.c.
 *
 * Returns MAX_POKEMON_LEVEL when the cap is disabled.
 */
u8 LevelCap_Get(SaveData *saveData);

/**
 * LevelCap_Get on the save data that is currently loaded.
 */
u8 LevelCap_GetCurrent(void);

/**
 * Clamps an EXP reward so that the Pokemon does not go past the current level
 * cap. Returns 0 if the Pokemon is already at or above the cap.
 */
u32 LevelCap_ClampExpGain(Pokemon *mon, u32 expGain);

#endif // POKEPLATINUM_LEVEL_CAP_H
