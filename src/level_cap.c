#include "level_cap.h"

#include <nitro.h>

#include "constants/pokemon.h"
#include "constants/savedata/vars_flags.h"
#include "generated/badges.h"

#include "pokemon.h"
#include "save_player.h"
#include "savedata.h"
#include "trainer_info.h"
#include "vars_flags.h"

// ============================================================================
// Level cap configuration
// ============================================================================
//
// The cap starts at LEVEL_CAP_START. Every rule in sLevelCapRules whose
// requirement is met can raise it to that rule's level. The highest level out
// of all rules that are met wins, so the order of the table does not matter.
//
// Requirement types:
//   LEVEL_CAP_REQ_BADGE        value is a badge ID (BADGE_ID_*), met when the
//                              player owns that badge.
//   LEVEL_CAP_REQ_BADGE_COUNT  value is a number of badges, met when the
//                              player owns at least that many.
//   LEVEL_CAP_REQ_FLAG         value is an event flag (FLAG_*, see
//                              generated/vars_flags.txt), met when it is set.
//
// The default values are the level of the next Gym Leader's / Elite Four
// member's / Champion's strongest Pokemon, in Platinum's gym order. The cap
// never goes down: the highest cap reached is kept in LEVEL_CAP_HIGHEST_VAR.

// Set to FALSE to turn the level cap off completely.
#define LEVEL_CAP_ENABLED TRUE

// Cap before any rule below is met (Roark's strongest Pokemon).
#define LEVEL_CAP_START 14

// The cap is removed once this flag is set. Use 0 to never remove it.
#define LEVEL_CAP_REMOVED_FLAG FLAG_DEFEATED_TRAINER_CHAMPION_CYNTHIA_REMATCH

// The highest cap reached so far is saved in this var, so the cap never goes
// down, even if a flag used by a rule gets cleared again.
#define LEVEL_CAP_HIGHEST_VAR VAR_LEVEL_CAP_HIGHEST

enum LevelCapRequirement {
    LEVEL_CAP_REQ_BADGE = 0,
    LEVEL_CAP_REQ_BADGE_COUNT,
    LEVEL_CAP_REQ_FLAG,
};

typedef struct LevelCapRule {
    u8 requirement;
    u16 value;
    u8 level;
} LevelCapRule;

static const LevelCapRule sLevelCapRules[] = {
    // Gyms
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_COAL, 22 }, // Next: Gardenia
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_FOREST, 26 }, // Next: Fantina
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_RELIC, 32 }, // Next: Maylene
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_COBBLE, 37 }, // Next: Crasher Wake
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_FEN, 41 }, // Next: Byron
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_MINE, 44 }, // Next: Candice
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_ICICLE, 50 }, // Next: Volkner
    { LEVEL_CAP_REQ_BADGE, BADGE_ID_BEACON, 53 }, // Next: Aaron

    // Elite Four, first time. The League scripts set these trainer flags on a
    // win, and they are never cleared.
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_AARON, 55 }, // Next: Bertha
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_BERTHA, 57 }, // Next: Flint
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_FLINT, 59 }, // Next: Lucian
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_LUCIAN, 62 }, // Next: Cynthia

    // Elite Four rematches (after Charon is arrested at Stark Mountain).
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_CHAMPION_CYNTHIA, 69 }, // Next: Aaron (rematch)
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_AARON_REMATCH, 71 }, // Next: Bertha (rematch)
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_BERTHA_REMATCH, 73 }, // Next: Flint (rematch)
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_FLINT_REMATCH, 75 }, // Next: Lucian (rematch)
    { LEVEL_CAP_REQ_FLAG, FLAG_DEFEATED_TRAINER_ELITE_FOUR_LUCIAN_REMATCH, 78 }, // Next: Cynthia (rematch)
};

// ============================================================================

static BOOL LevelCap_IsRuleMet(const LevelCapRule *rule, TrainerInfo *trainerInfo, VarsFlags *varsFlags)
{
    switch (rule->requirement) {
    case LEVEL_CAP_REQ_BADGE:
        return TrainerInfo_HasBadge(trainerInfo, rule->value);
    case LEVEL_CAP_REQ_BADGE_COUNT:
        return TrainerInfo_BadgeCount(trainerInfo) >= rule->value;
    case LEVEL_CAP_REQ_FLAG:
        return VarsFlags_CheckFlag(varsFlags, rule->value);
    }

    return FALSE;
}

u8 LevelCap_Get(SaveData *saveData)
{
    if (LEVEL_CAP_ENABLED == FALSE || saveData == NULL) {
        return MAX_POKEMON_LEVEL;
    }

    TrainerInfo *trainerInfo = SaveData_GetTrainerInfo(saveData);
    VarsFlags *varsFlags = SaveData_GetVarsFlags(saveData);
    u16 *highestCap = VarsFlags_GetVarAddress(varsFlags, LEVEL_CAP_HIGHEST_VAR);
    u8 cap = LEVEL_CAP_START;

    if (LEVEL_CAP_REMOVED_FLAG != 0 && VarsFlags_CheckFlag(varsFlags, LEVEL_CAP_REMOVED_FLAG)) {
        cap = MAX_POKEMON_LEVEL;
    } else {
        for (int i = 0; i < NELEMS(sLevelCapRules); i++) {
            if (sLevelCapRules[i].level > cap && LevelCap_IsRuleMet(&sLevelCapRules[i], trainerInfo, varsFlags)) {
                cap = sLevelCapRules[i].level;
            }
        }
    }

    // Never go below a cap that was already reached.
    if (cap < *highestCap) {
        cap = *highestCap;
    }

    if (cap > MAX_POKEMON_LEVEL) {
        cap = MAX_POKEMON_LEVEL;
    }

    *highestCap = cap;

    return cap;
}

u8 LevelCap_GetCurrent(void)
{
    return LevelCap_Get(SaveData_Ptr());
}

u32 LevelCap_ClampExpGain(Pokemon *mon, u32 expGain)
{
    u8 cap = LevelCap_GetCurrent();

    if (Pokemon_GetValue(mon, MON_DATA_LEVEL, NULL) >= cap) {
        return 0;
    }

    u32 curExp = Pokemon_GetValue(mon, MON_DATA_EXPERIENCE, NULL);
    u32 capExp = Pokemon_GetSpeciesBaseExpAt(Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL), cap);

    if (curExp >= capExp) {
        return 0;
    }

    if (expGain > capExp - curExp) {
        expGain = capExp - curExp;
    }

    return expGain;
}
