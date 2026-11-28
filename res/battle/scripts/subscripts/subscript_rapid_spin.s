#include "macros/btlcmd.inc"


_000:
    RapidSpin
    // Also raise the user's Speed by 1 stage, handled like Metal Claw's Attack raise.
    UpdateVar OPCODE_SET, BTLVAR_SIDE_EFFECT_PARAM, MOVE_SUBSCRIPT_PTR_SPEED_UP_1_STAGE
    UpdateVarFromVar OPCODE_SET, BTLVAR_SIDE_EFFECT_MON, BTLVAR_ATTACKER
    Call BATTLE_SUBSCRIPT_UPDATE_STAT_STAGE
    End
