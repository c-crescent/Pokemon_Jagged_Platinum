#include "macros/scrcmd.inc"
#include "res/text/bank/sandgem_town_counterpart_house_2f.h"


    ScriptEntry SandgemTownCounterpartHouse2F_PC
    ScriptEntry SandgemTownCounterpartHouse2F_TrashCan
    ScriptEntryEnd

SandgemTownCounterpartHouse2F_PC:
    PlaySE SE_CONFIRM_sseq_3
    LockAll
    BufferPlayerName 0
    Message SandgemTownCounterpartHouse2F_Text_PlayerCheckedPCScreen
    WaitButton
    // Reading the PC also gives 999 Rare Candies, if they fit in the Bag.
    SetVar VAR_0x8004, ITEM_RARE_CANDY
    SetVar VAR_0x8005, 999
    GoToIfCannotFitItem VAR_0x8004, VAR_0x8005, VAR_RESULT, SandgemTownCounterpartHouse2F_BagIsFull
    CallCommonScript CommonScript_AddItemQuantity
    CloseMessage
    ReleaseAll
    End

SandgemTownCounterpartHouse2F_BagIsFull:
    CallCommonScript CommonScript_BagIsFull
    CloseMessage
    ReleaseAll
    End

// The trash can gives 999 Master Balls, if they fit in the Bag.
SandgemTownCounterpartHouse2F_TrashCan:
    PlaySE SE_CONFIRM_sseq_3
    LockAll
    SetVar VAR_0x8004, ITEM_MASTER_BALL
    SetVar VAR_0x8005, 999
    GoToIfCannotFitItem VAR_0x8004, VAR_0x8005, VAR_RESULT, SandgemTownCounterpartHouse2F_BagIsFull
    CallCommonScript CommonScript_AddItemQuantity
    CloseMessage
    ReleaseAll
    End

    .balign 4, 0
