SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "¿Conoces el POKéMON SEEDOT?\n"
	.string "Casi nunca se ve en ARRECÍPOLIS.\p"
	.string "En fin, me encantan los SEEDOT grandes.\n"
	.string "Cuanto más grandes, mejor.\p"
	.string "Pero mi hermano pequeño dice que\n"
	.string "LOTAD es más grande.\p"
	.string "Eso es una tontería.\n"
	.string "¡SEEDOT tiene que ser más grande que eso!\p"
	.string "¿Eh? ¿Llevas un SEEDOT contigo?\n"
	.string "¡P-p-por favor, enséñamelo!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "¡{STR_VAR_2} centímetros!\n"
	.string "¡Oh, Dios mío, este es grande!\p"
	.string "¡Igual supera al LOTAD grande que\n"
	.string "vio mi hermano pequeño!\p"
	.string "Gracias por enséñarmelo.\n"
	.string "¡Esto es para agradecértelo!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} ha recibido una POCIÓN.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "¿Eh?\n"
	.string "Tu MOCHILA está a rebosar.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "¿{STR_VAR_2} centímetros?\p"
	.string "Mmm… He visto un SEEDOT más grande\n"
	.string "que este.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Oh, esto es algo extraordinario…\n"
	.string "¡Pero no es un SEEDOT!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "¿No tienes un SEEDOT grande?\n"
	.string "Qué pena…\p"
	.string "Si consigues un SEEDOT grande, por\n"
	.string "favor ven a enséñamelo.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "¡El SEEDOT más grande de la historia!\n"
	.string "¡El gigante de {STR_VAR_2} centímetros!\p"
	.string "¡Un SEEDOT más grande que un LOTAD\n"
	.string "como siempre había deseado!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "¿Conoces el POKéMON LOTAD?\n"
	.string "Casi nunca se ve en ARRECÍPOLIS.\p"
	.string "¡Me encantan, y digo encantan, los\n"
	.string "LOTAD grandes!\p"
	.string "Mi hermano mayor dice que SEEDOT es\n"
	.string "más grande.\p"
	.string "¡Pero eso está mal! Todo el mundo sabe\n"
	.string "que LOTAD es mucho más grande.\p"
	.string "¿Eh? ¿Llevas un LOTAD?\n"
	.string "¡P-p-por favor, enséñamelo!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "¡{STR_VAR_2} centímetros!\n"
	.string "¡Vaya, eso es grande!\p"
	.string "Puede que sea incluso más grande que el\n"
	.string "SEEDOT enorme que vio mi hermano mayor.\p"
	.string "¡Gracias por enséñarmelo!\n"
	.string "¡Esto es para agradecértelo!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} ha recibido una POCIÓN.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "¿Eh?\n"
	.string "Tu MOCHILA está a rebosar.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "¿{STR_VAR_2} centímetros?\p"
	.string "Mmm… He visto un LOTAD más grande\n"
	.string "que este.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "¡Vaya, esto es algo!\n"
	.string "¡Pero no es un LOTAD!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "¿No tienes un LOTAD grande?\n"
	.string "Qué decepción…\p"
	.string "Si consigues un LOTAD grande, por\n"
	.string "favor ven a enséñamelo.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "¡El LOTAD más grande de la historia!\n"
	.string "¡El coloso de {STR_VAR_2} centímetros!\p"
	.string "¡Un LOTAD más grande que un SEEDOT\n"
	.string "como siempre había deseado!$"

