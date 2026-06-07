AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Estoy investigando este barco en nombre\n"
	.string "del CAP. STERN.\p"
	.string "También me pidió que encontrara un ESCÁNER,\n"
	.string "pero no he tenido éxito…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "¡Oh! ¡Eso es un ESCÁNER!\p"
	.string "Escucha, ¿podrías llevarle eso\n"
	.string "al CAP. STERN?\p"
	.string "Quiero investigar un poco más\n"
	.string "este barco.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Este barco se llama S.S. CACTUS.\n"
	.string "Parece ser de una época anterior.$"

