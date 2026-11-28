#include "macros/btlcmd.inc"


_000:
    SetMultiHit 3, SYSCTL_TRIPLE_KICK
    UpdateVar OPCODE_SET, BTLVAR_AFTER_MOVE_MESSAGE_TYPE, AFTER_MOVE_MESSAGE_MULTI_HIT
    GetCurrentMoveData MOVEATTRIBUTE_POWER
    UpdateVarFromVar OPCODE_ADD, BTLVAR_MOVE_POWER, BTLVAR_CALC_TEMP
    CalcCrit 
    CalcDamage 
    End 
