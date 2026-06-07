FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Las personas… Los Pokémon…\p"
	.string "Sus poderes ocultos se despiertan al\n"
	.string "vivir en entornos naturales…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Déjame ver si tu poder oculto se ha\n"
	.string "despertado…\p"
	.string "Sostengo una moneda en mi mano.\p"
	.string "Ahora, dime, ¿la he escondido en la\n"
	.string "mano derecha? ¿O en la izquierda?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "¡Oh! ¡Sí, correcto!\p"
	.string "Intentémoslo otra vez.\p"
	.string "¿En qué mano he escondido la moneda?\n"
	.string "¿La derecha o la izquierda?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "¡Oh! ¡Sí, correcto!\p"
	.string "Intentémoslo otra vez.\p"
	.string "¿En qué mano he escondido la moneda?\n"
	.string "¿La derecha o la izquierda?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "¡Oh! ¡Espléndido!\n"
	.string "¡Tu poder oculto se ha despertado!\p"
	.string "Toma, coge esto y despierta el poder\n"
	.string "oculto de tus Pokémon.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "Poder oculto es un movimiento que cambia\n"
	.string "según el Pokémon.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "No, qué pena.\n"
	.string "Has fallado.$"

