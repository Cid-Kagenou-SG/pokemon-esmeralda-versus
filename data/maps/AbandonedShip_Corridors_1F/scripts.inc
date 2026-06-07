AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "¿Qué tiene de gracioso llevar mi flotador\n"
	.string "a bordo del barco?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "¡Vaya, me has aplastado!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "¡No es fácil lanzar POKé BALLS mientras te\n"
	.string "aferras a un flotador!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "¿No es divertido aquí?\n"
	.string "¡Me emociono solo con estar aquí!$"
