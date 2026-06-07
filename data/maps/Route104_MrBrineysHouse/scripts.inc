Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "SR. ARENQUE: ¡Espera, muchacha!\n"
	.string "¡Espera, PEEKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "¿Mmm? ¡Eres {PLAYER}{KUN}!\n"
	.string "¡Salvaste a mi querida PEEKO!\l"
	.string "¡Te debemos mucho!\p"
	.string "¿Qué dices?\n"
	.string "¿Quieres navegar conmigo?\p"
	.string "Jumjum…\p"
	.string "Tienes una CARTA para PUEBLO AZULIZA\n"
	.string "y un paquete para CIUDAD PORTUAL, ¿no?\p"
	.string "¡Qué vida tan ocupada debes llevar!\p"
	.string "Pero, ciertamente, lo que pides no es\n"
	.string "ningún problema.\p"
	.string "¡Has venido al hombre indicado!\n"
	.string "Zarparemos hacia PUEBLO AZULIZA.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "SR. ARENQUE: ¡A PUEBLO AZULIZA, pues!\p"
	.string "¡Levantar anclas!\n"
	.string "¡PEEKO, zarpamos, mi querida!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "SR. ARENQUE: ¿Ah, sí?\n"
	.string "¿Tus entregas pueden esperar?\p"
	.string "¡Dime cuando quieras zarpar!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "SR. ARENQUE: ¡Ahoy!\n"
	.string "¡Sé exactamente lo que quieres decir!\p"
	.string "Tienes que entregar una CARTA a\n"
	.string "PUEBLO AZULIZA y un paquete a\l"
	.string "CIUDAD PORTUAL.\p"
	.string "Lo que necesitas que haga no es ningún\n"
	.string "problema--¡soy el hombre indicado para\l"
	.string "el trabajo!\p"
	.string "Primero, zarparemos hacia PUEBLO\n"
	.string "AZULIZA.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "SR. ARENQUE: ¡Ahoy!\n"
	.string "¡Sé exactamente lo que quieres decir!\p"
	.string "Tienes que entregar un paquete al\n"
	.string "CAPITÁN BABOR en CIUDAD PORTUAL.\p"
	.string "Lo que necesitas que haga no es ningún\n"
	.string "problema--¡soy el hombre indicado para\l"
	.string "el trabajo!\p"
	.string "Primero, zarparemos hacia PUEBLO\n"
	.string "AZULIZA.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "SR. ARENQUE: ¡Ahoy!\n"
	.string "¡Para ti, zarpo a mar abierto cuando\l"
	.string "quieras!\p"
	.string "Ahora, amigo mío, ¿adónde vamos?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "SR. ARENQUE: ¿Ah, sí?\n"
	.string "Bueno, PEEKO te debe la vida.\p"
	.string "¡Dime cuando quieras zarpar!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: ¡Pii piihyoro!$"

