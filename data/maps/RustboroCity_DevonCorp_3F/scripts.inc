RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Soy el SR. PIEDRA, el PRESIDENTE de\n"
	.string "la CORPORACIÓN DEVON.\p"
	.string "¡Acabo de recibir noticias sobre ti!\p"
	.string "¡Salvaste a nuestro personal no una,\n"
	.string "sino dos veces!\p"
	.string "Tengo un favor que pedirte a una\n"
	.string "persona tan increíble como tú.\p"
	.string "Entiendo que estás entregando un\n"
	.string "paquete a los ASTILLEROS de PORTUAL.\p"
	.string "Bueno, ¿podrías parar en PUEBLO\n"
	.string "AZULIZA de camino?\p"
	.string "Esperaba que entregaras una CARTA\n"
	.string "a MÁXIMO en AZULIZA.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "SR. PIEDRA: Ahora, debes saber que\n"
	.string "soy un gran PRESIDENTE.\p"
	.string "Así que nunca sería tan tacaño como\n"
	.string "para pedirte un favor sin nada a cambio.\p"
	.string "¡Por eso quiero que aceptes esto!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} ha recibido un POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "SR. PIEDRA: Ese dispositivo…\p"
	.string "Es un POKéMON NAVIGATOR, o POKéNAV\n"
	.string "para abreviar.\p"
	.string "Es una herramienta indispensable para\n"
	.string "cualquier ENTRENADOR en una aventura.\p"
	.string "Tiene un mapa de la región de HOENN.\p"
	.string "¡Puedes comprobar fácilmente la\n"
	.string "ubicación de AZULIZA y PORTUAL!\p"
	.string "Por cierto, he oído que unos criminales\n"
	.string "siniestros -MAGMA y AQUA, creo- han\l"
	.string "estado causando problemas por todas\l"
	.string "partes.\p"
	.string "Creo que sería mejor que descansaras\n"
	.string "antes de seguir tu camino.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "SR. PIEDRA: Bueno, entonces,\n"
	.string "{PLAYER}{KUN}, ¡ve con cuidado y precaución!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "SR. PIEDRA: ¡Cuento contigo!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "SR. PIEDRA: ¿Entregaste mi CARTA?\n"
	.string "¡Muchas gracias!\p"
	.string "Esta es mi forma de agradecértelo.\n"
	.string "Debería ayudarte a ti, como ENTRENADOR.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "SR. PIEDRA: Un POKéMON que lleve ese\n"
	.string "REPARTIR EXP. recibirá parte de los\l"
	.string "Puntos de Experiencia del combate.\p"
	.string "Obtendrá Puntos de Experiencia incluso\n"
	.string "si no combatió realmente.\p"
	.string "Diría que REPARTIR EXP. es bastante útil\n"
	.string "para criar POKéMON débiles.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "SR. PIEDRA: Desde mi juventud, me he\n"
	.string "sumergido en el trabajo.\p"
	.string "En consecuencia, no estoy familiarizado\n"
	.string "con las tendencias y esas cosas.\p"
	.string "Pero ¿todos los jóvenes quieren ser\n"
	.string "ENTRENADORES en la LIGA POKéMON?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Esta es la tercera planta de la\n"
	.string "CORPORACIÓN DEVON.\p"
	.string "El DESPACHO DEL PRESIDENTE está en\n"
	.string "esta planta.\p"
	.string "En cualquier caso, no puedo decirte lo\n"
	.string "agradecido que estoy por lo que has\l"
	.string "hecho.\p"
	.string "Um… Por cierto, el paquete que\n"
	.string "recuperaste para nosotros…\p"
	.string "¿Podría pedirte que lo entregaras en los\n"
	.string "ASTILLEROS de PORTUAL?\p"
	.string "Sería terrible si esos ladrones\n"
	.string "intentaran llevárselo otra vez.\p"
	.string "Uh… Jejeje, así que, eh, ¿podría\n"
	.string "contar contigo para eso?\p"
	.string "Oh, eso es cierto.\n"
	.string "¿Podrías esperar aquí un segundo?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Nuestro PRESIDENTE querría hablar\n"
	.string "contigo.\p"
	.string "Por favor, ven conmigo.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Por favor, adelante.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Si visitas los ASTILLEROS de PORTUAL,\n"
	.string "deberías ir a ver al CAPITÁN BABOR.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Los nuevos productos de DEVON, la\n"
	.string "ACOPIO BALL y la TURNO BALL, han tenido\l"
	.string "un éxito enorme entre los ENTRENADORES.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Es una colección de rocas y piedras\n"
	.string "raras reunidas por el PRESIDENTE.$"

