SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mi POKéMON tiene una naturaleza ACTIVA.\p"
	.string "Tiene más VELOCIDAD en comparación con\n"
	.string "mis otros POKéMON.\p"
	.string "Quizás su naturaleza tiene algo que ver\n"
	.string "con el aumento de características de los\l"
	.string "POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Eres un ENTRENADOR, ¿verdad?\p"
	.string "Como has venido a CIUDAD PORTUAL,\n"
	.string "seguro que vas a la TIENDA DE BATALLA.$"

