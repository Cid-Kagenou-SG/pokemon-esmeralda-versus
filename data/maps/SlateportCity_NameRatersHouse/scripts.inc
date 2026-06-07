SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "¡Hola, hola! ¡Soy el INSPECTOR DE MOTES!\n"
	.string "¡Soy el adivino de los nombres!\p"
	.string "Me encantaría evaluar el mote de\n"
	.string "tu POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "¿El mote de qué POKéMON debo\n"
	.string "evaluar?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Mmm… ¿{STR_VAR_1}, dices? Ese es un\n"
	.string "nombre bastante bueno que le has puesto.\p"
	.string "¡Pero! ¿Qué me dices si te propongo\n"
	.string "uno ligeramente mejor?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, bien. Entonces, ¿cuál será el\n"
	.string "nuevo mote?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "¡Hecho! ¡A partir de ahora, este POKéMON\n"
	.string "se llamará {STR_VAR_1}!\p"
	.string "¡Es un nombre mejor que el anterior!\n"
	.string "¡Qué suerte tienes!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ya veo.\n"
	.string "Vuelve cuando quieras.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "¡Hecho! ¡A partir de ahora, este POKéMON\n"
	.string "se llamará {STR_VAR_1}!\p"
	.string "No parece diferente del anterior,\n"
	.string "pero, aun así, ¡es enormemente superior!\p"
	.string "¡Qué suerte tienes!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "¡Mmm… {STR_VAR_1}!\p"
	.string "¡Este es un mote magnífico!\n"
	.string "¡Es impecable e irreprochable!\p"
	.string "Harías bien en apreciar a tu\n"
	.string "{STR_VAR_1} ahora y siempre.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Vamos, vamos.\n"
	.string "¡Eso no es más que un HUEVO!$"

