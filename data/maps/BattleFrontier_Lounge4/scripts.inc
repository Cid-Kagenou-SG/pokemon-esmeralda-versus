BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Me pregunto si hoy emitirán\n"
	.string "entrevistas con entrenadores duros.$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Si abriera un restaurante aquí,\n"
	.string "seguro que ganaría dinero.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Uf…\p"
	.string "Necesito tomar un respiro después de\n"
	.string "unos combates tan intensos…\p"
	.string "Pero incluso ahora, nunca descanso de\n"
	.string "tramar estrategias y combos.$"

