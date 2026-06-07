Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, cielo, cielo.\n"
	.string "¿Tus Pokémon no están exhaustos?\p"
	.string "Si quieres, descansa aquí.\n"
	.string "¡Es una idea estupenda! Deberías hacerlo.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Eso es.\n"
	.string "¡Tómate tu tiempo y descansa!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh, cielo, cielo.\n"
	.string "¿Tus Pokémon siguen cansados?\p"
	.string "Deberías descansar otro poco aquí.\n"
	.string "Es una idea estupenda. Deberías hacerlo.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "¿Ah, sí?\n"
	.string "No tienes por qué ser tímido.$"

