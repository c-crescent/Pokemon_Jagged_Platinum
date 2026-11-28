#include "macros/btlcmd.inc"


_000:
    UpdateVar OPCODE_SET, BTLVAR_SIDE_EFFECT_FLAGS_INDIRECT, MOVE_SIDE_EFFECT_ON_HIT|MOVE_SUBSCRIPT_PTR_KNOCK_OFF
    // 50% more power if the target is holding an item.
    CompareMonDataToValue OPCODE_EQU, BTLSCR_DEFENDER, BATTLEMON_HELD_ITEM, ITEM_NONE, _020
    UpdateVar OPCODE_SET, BTLVAR_POWER_MULTI, 15
    GoTo _024

_020:
    UpdateVar OPCODE_SET, BTLVAR_POWER_MULTI, 10

_024:
    CalcCrit
    CalcDamage
    End
