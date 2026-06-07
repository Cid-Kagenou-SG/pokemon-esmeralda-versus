BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Elige a un compañero de entre los\n"
	.string "entrenadores reunidos aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, aún no has elegido\n"
	.string "compañero para tu equipo.\p"
	.string "¿Quieres dejar de buscar y\n"
	.string "volver al mostrador de recepción?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Entonces, elige a un compañero de\n"
	.string "entre los entrenadores reunidos aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Gracias por elegir compañero.\p"
	.string "Ahora te acompañaré a la\n"
	.string "SALA DE MULTI BATALLA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. ¡Puedes llamarme {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Siguiendo el consejo de {STR_VAR_1},\n"
	.string "he traído un {STR_VAR_3} con {STR_VAR_2} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por favor, déjame unirme a tu equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "¡Gracias!\n"
	.string "Voy a registrarme ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Tenía muchas ganas de formar un\n"
	.string "equipo contigo, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. Mi nombre es {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "Recibí el consejo de {STR_VAR_1} y elegí\n"
	.string "un {STR_VAR_3} con {STR_VAR_2} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Por favor, formemos un equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "¡Muchas gracias!\n"
	.string "¡Voy a registrarme enseguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, esperaba poder hacer\n"
	.string "equipo contigo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Eh, me llamo {STR_VAR_3} y soy el\n"
	.string "aprendiz n.º {STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Sob…\p"
	.string "¡Lo siento!\n"
	.string "Estoy tan nervioso que no puedo evitar\l"
	.string "llorar…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} me aconsejó, así que tengo\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Sob…\n"
	.string "¡Por favor, por favor, únete a mí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "¿De verdad? ¿Lo harás?\n"
	.string "¡Genial! ¡Qué pasada! ¡Aaaah!\p"
	.string "Oh… Lo siento…\n"
	.string "Estoy tan contento que no puedo evitar\l"
	.string "llorar…\p"
	.string "Voy a registrarme enseguida.\n"
	.string "¡No te vayas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, p-pero…\n"
	.string "Sob… ¡Buaaaaa!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "¡Hola! ¡Soy {STR_VAR_3}!\n"
	.string "¡Soy el aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} me recomendó este equipo.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¡Qué equipo más chulo, ¿eh?!\p"
	.string "¡Venga!\n"
	.string "¡Formemos un equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "¡Yupi! ¡Genial!\n"
	.string "Vale, voy a registrarme, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Vaya, ¿por qué?\n"
	.string "Quería hacer equipo contigo, {PLAYER}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Soy {STR_VAR_3}, el aprendiz n.º {STR_VAR_2}\n"
	.string "del famoso {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "Pedí consejo a {STR_VAR_3}. Un {STR_VAR_2}\n"
	.string "con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Ese es mi equipo.\p"
	.string "Por favor, ¿quieres unirte a mí\n"
	.string "en un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "¡Gracias!\n"
	.string "¡Voy a registrarme ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, esperaba poder unirme\n"
	.string "a tu equipo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Eh… Estoy muy contento de que te\n"
	.string "tomes la molestia de hablar conmigo.\p"
	.string "Soy {STR_VAR_3}.\n"
	.string "Soy el aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} me dio un consejo.\n"
	.string "Le estoy muy agradecido.\p"
	.string "Tengo un equipo formado por un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Sé que es mucho pedir…\p"
	.string "No creo que quieras, pero ¿podría\n"
	.string "unirme a ti como compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "¿De verdad? ¡No me lo puedo creer!\n"
	.string "¡No me puedo creer que me dejes\l"
	.string "unirme a ti!\l"
	.string "¡N… No te defraudaré!\p"
	.string "Eh… Si de verdad está bien, voy a\n"
	.string "registrarnos ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "No creía ser lo bastante bueno…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "¡Hola! Soy {STR_VAR_3}.\n"
	.string "¡Soy el aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} me dijo que sería bueno\n"
	.string "formar este equipo: un {STR_VAR_2}\l"
	.string "con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "y un {STR_VAR_2} que sabe usar\n"
	.string "{STR_VAR_1}.\p"
	.string "¿A que no está mal?\n"
	.string "¿Quieres que hagamos equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "¡Vale, encantado de unirme a ti!\n"
	.string "¡Espero que no me estropees las\l"
	.string "cosas! Voy a registrarme.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "¿Eh? ¿Por qué me has rechazado?\n"
	.string "¡No tienes ojo para el talento!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Soy {STR_VAR_3} y soy triatleta.\n"
	.string "Estoy ocupado todos los días: corro,\l"
	.string "entreno y hago rap.\p"
	.string "También soy el aprendiz n.º {STR_VAR_2}\n"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Esto es lo que me recomendó {STR_VAR_3}.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Me he esforzado mucho en entrenarlos,\n"
	.string "aunque esté ocupado.\p"
	.string "¡Formemos un equipo y demos lo\n"
	.string "mejor de nosotros!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "¡Gracias, así se habla!\n"
	.string "Espera un momento, voy a registrarme.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "He sacado tiempo de mi apretada\n"
	.string "agenda para venir aquí. ¡Dame una\l"
	.string "oportunidad!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "¡Hola!\n"
	.string "¿Qué tal?\p"
	.string "Soy {STR_VAR_3}, el aprendiz n.º {STR_VAR_2}\n"
	.string "de {STR_VAR_1}. ¡Encantado!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "¡Escucha, escucha! Tienes que oír\n"
	.string "lo que me recomendó {STR_VAR_3}.\l"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¡Por supuesto que los he entrenado\l"
	.string "a la perfección!\p"
	.string "Entonces, ¿quieres hacer equipo?\n"
	.string "¡Seguro que formamos un gran dúo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "¡Yupi, creo que esto va a ser divertido!\n"
	.string "¡Voy a registrarme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, ¡qué malo eres!\n"
	.string "Vengo muy recomendado, ¿sabes?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Permíteme presentarme.\n"
	.string "Soy {STR_VAR_3}.\p"
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "Busqué el sabio consejo de {STR_VAR_3}\n"
	.string "y entrené un equipo formado por\l"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Por favor, acepta formar un equipo\n"
	.string "conmigo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… ¡Estoy encantado!\n"
	.string "¡Prometo dar lo mejor de mí!\p"
	.string "Por supuesto que me registraré.\n"
	.string "¡Espera un momento!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "Esperaba poder unirme a ti,\n"
	.string "{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "¡Eek! ¡Me has hablado!\n"
	.string "¡Estoy… estoy eufórico!\p"
	.string "¡Soy {STR_VAR_3}! ¡Soy el aprendiz\n"
	.string "n.º {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Siguiendo el consejo de {STR_VAR_3},\n"
	.string "entrené un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por favor, ¿puedes concederme mi\n"
	.string "deseo? ¡Quiero ser tu compañero\l"
	.string "de equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "¡Eek! Me… me siento mareado…\n"
	.string "¡Muchísimas gracias!\l"
	.string "¡Voy a registrarnos ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "¡Buaaa! ¿No tienes compasión?\n"
	.string "Pero eso te hace todavía más guay…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "¡Yeehaw! ¡Soy el aprendiz n.º {STR_VAR_2}\n"
	.string "de {STR_VAR_1}!\p"
	.string "¡Me llamo {STR_VAR_3}, hola, hola!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mi mentor {STR_VAR_3} me recomendó\n"
	.string "un {STR_VAR_2} maestro de {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "y un {STR_VAR_2} maestro de {STR_VAR_1}.\p"
	.string "¿A que es bueno?\n"
	.string "Harás equipo conmigo, ¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "¡Vale, excelente!\n"
	.string "¡Voy a registrarme enseguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "¡Gwaaah!\n"
	.string "¡Eres un calculador, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "¡Eh! ¡Hay un gran problema! ¡Hoy es\n"
	.string "el último día de la TORRE BATALLA!\p"
	.string "… … … … … …\n"
	.string "¡Solo bromeaba!\p"
	.string "La gente me llama {STR_VAR_3} y yo\n"
	.string "también. ¡Soy el aprendiz n.º 1.000\l"
	.string "de {STR_VAR_1}! En realidad, soy el\l"
	.string "n.º {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} me dio un consejo.\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¡Tengo diez de cada uno!\l"
	.string "En realidad, solo uno de cada.\p"
	.string "¿Qué me dices?\n"
	.string "¿Quieres probar los combates en\l"
	.string "equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "¡Yupi!\n"
	.string "¡Te daré un Pokémon en agradecimiento!\p"
	.string "¡Solo bromeaba! Pero sí que voy a\n"
	.string "registrarme, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, ¡qué frío! Tendré que destruir\n"
	.string "la TORRE BATALLA por eso.\p"
	.string "¡Claro que no lo haré!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "¡Eh, hola! ¡Soy un tipo enrollado\n"
	.string "y con mucho ritmo!\p"
	.string "¡Soy {STR_VAR_3}, el marinero rapero!\n"
	.string "¡No me confundas con un llorón!\p"
	.string "Soy el aprendiz n.º {STR_VAR_2} de\n"
	.string "{STR_VAR_1}. ¡No me subestimes!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Con el consejo de {STR_VAR_3} me\n"
	.string "he montado un equipo de la hostia:\l"
	.string "un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Nuestro encuentro debemos celebrar,\n"
	.string "¡con una victoria en equipo para\l"
	.string "conmemorar!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "¡Eh, eh, me gusta tu estilo!\n"
	.string "¡Voy a registrarnos con mucho estilo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, eh, {PLAYER}, ¡qué frío eres!\n"
	.string "¡Si me lo permites decir!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "¡Yippee-yahoo!\n"
	.string "¡Oh, no te vayas! ¡Solo me estaba\l"
	.string "divirtiendo!\p"
	.string "¡Hola! ¡Soy {STR_VAR_3}!\n"
	.string "¡Soy el aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} me dijo qué hacer.\n"
	.string "Así que un {STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "esos elegí.\p"
	.string "Entonces, ¿qué me dices?\n"
	.string "¡Venga, anímate!\p"
	.string "¡Por favor, te lo suplico!\n"
	.string "¡Déjame unirme a ti, no me dejes\l"
	.string "triste y azul!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "¡Yeeeah! ¡La suerte está de mi lado!\n"
	.string "¡Esto me pone muy contento!\p"
	.string "Antes de que empecemos a luchar,\n"
	.string "voy a registrarme enseguida.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "¿Me estás rechazando?\n"
	.string "{PLAYER}, me estás poniendo triste.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "¡Cof, cof!\p"
	.string "Oh, perdón, estoy resfriado.\n"
	.string "Mis Pokémon están bien, eso sí.\p"
	.string "Me llamo {STR_VAR_3}, aprendiz n.º {STR_VAR_2}\n"
	.string "de {STR_VAR_1}. ¡Cof, cof!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "Tomé el consejo de {STR_VAR_3} muy\n"
	.string "en serio y monté un equipo con\l"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Los entrené todos los días,\n"
	.string "hiciera viento o lloviera.\p"
	.string "Creo que por eso me he resfriado.\p"
	.string "Eso es lo que hay.\n"
	.string "¿Quieres ser mi compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "¡Gracias, te lo agradezco mucho!\n"
	.string "¡Cof, cof!\l"
	.string "Espera, voy a registrarme.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, ¿no quieres?\n"
	.string "{PLAYER}, creo que formaríamos un\l"
	.string "buen equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, ¡hola!\n"
	.string "Esto me pone nervioso.\p"
	.string "Soy {STR_VAR_3}.\n"
	.string "Soy el aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} dijo que este equipo\n"
	.string "sería bueno: un {STR_VAR_2} con\l"
	.string "{STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Me siento un poco avergonzado,\n"
	.string "pero ¿me dejarás unirme a ti?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, vaya, ¡gracias!\n"
	.string "Me siento un poco tímido, pero\l"
	.string "haré lo mejor que pueda.\p"
	.string "Voy a registrarme.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, por favor, ¡no digas que no!\n"
	.string "Ya me siento lo bastante avergonzado…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Soy {STR_VAR_3}, y eso no es mentira.\n"
	.string "Soy el aprendiz n.º {STR_VAR_2} de\l"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} me recomendó mi equipo.\p"
	.string "Como el consejo sonaba sincero,\n"
	.string "decidí traer conmigo mi {STR_VAR_2}\l"
	.string "con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "mi {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Si es posible, me gustaría que\n"
	.string "aceptaras ser mi compañero de equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "¿De verdad me aceptas?\n"
	.string "Sería terrible que no lo hicieras.\p"
	.string "Pero como has aceptado, todo está bien.\n"
	.string "Voy a registrarnos a los dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "¿Mmm? ¿Por qué rechazas?\n"
	.string "¿Es tu idea de una broma?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Soy {STR_VAR_1}, ¡y soy una\n"
	.string "CHICA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Lo que tengo es un {STR_VAR_2}\n"
	.string "con {STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Eso es lo que llevo conmigo.\p"
	.string "¿Quieres ser mi compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "¡Gracias!\n"
	.string "¡Voy a registrarme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "¿No quieres ser mi compañero?\n"
	.string "¡Te arrepentirás!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "¡Hola!\p"
	.string "¡Soy {STR_VAR_1}, el JOVEN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "¿Quieres saber qué tengo?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Serás mi compañero de equipo,\n"
	.string "¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "¡Yupi!\n"
	.string "Voy a registrarme, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "¡Vaya! Si hicieras equipo con mis\n"
	.string "Pokémon, seríamos imparables.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "¡Yahoo!\n"
	.string "¡Soy {STR_VAR_1}, el MONTAÑERO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "¿Sabes qué llevo conmigo?\n"
	.string "Mi {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "mi {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Suena bien, eh?\n"
	.string "¿Quieres formar un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "¡Yahoo!\n"
	.string "Voy a registrarnos, entonces.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Me habría gustado luchar contigo\n"
	.string "a mi lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "¡Hola!\n"
	.string "¡Soy {STR_VAR_1}, y soy una\n"
	.string "MODELISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "¿Sabes qué he estado criando?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Qué te parece?\n"
	.string "¿Quieres formar un equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "¡Maravilloso!\n"
	.string "¡Voy a registrarme ahora mismo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "¡Qué decepción!\p"
	.string "Juntas, habríamos sido\n"
	.string "las mejores.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "¡Eh!\p"
	.string "¿Sabes quién soy?\n"
	.string "¡Soy {STR_VAR_1}, el PESCADOR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Tengo un equipo formado por un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Entonces, ¿qué me dices?\n"
	.string "¿Lucharás a mi lado?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "¡Bien, bien!\n"
	.string "¡Déjamelo a mí!\p"
	.string "Voy a registrarnos ahora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Habríamos encajado a la perfección…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Encantada de conocerte.\n"
	.string "Soy {STR_VAR_1}, una DAMISELA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Me acompaña un equipo formado por\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Espero cumplir con tus expectativas.\n"
	.string "Me gustaría que fueras mi compañero.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Te lo agradezco sinceramente.\n"
	.string "Me encargaré del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Estoy segura de que te arrepentirás\n"
	.string "de no haberme elegido como compañera.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "¡Soy {STR_VAR_1}, la TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Lo que tengo…\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¡Ese es mi equipo!\p"
	.string "¿Por favor?\n"
	.string "¿Quieres formar un equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "¡Vaya, gracias!\n"
	.string "Voy a registrarme en el mostrador.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Juntas, habríamos sido\n"
	.string "imbatibles con toda seguridad.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "¡Hola!\n"
	.string "¡Soy {STR_VAR_1}, el CAZABICHOS!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "¡Mira lo que tengo!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Entonces, ¡escucha!\n"
	.string "¿Quieres formar un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "¡Entendido!\p"
	.string "Voy a registrarme en el mostrador.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Vaya, mis Pokémon son increíbles.\n"
	.string "Espero que no te arrepientas.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "¡Buenas!\n"
	.string "¡Soy {STR_VAR_1}, el ESCOLAR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Lo que he estado criando son un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "y un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "No está mal, ¿verdad?\n"
	.string "¿Te gustaría formar un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "¡Muchas gracias!\n"
	.string "Me encargaré del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Qué pena…\p"
	.string "Esperaba poder aprender de ti\n"
	.string "como tu compañero…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "¡Eh! ¡Déjame que te diga quién soy!\n"
	.string "¡Soy {STR_VAR_1}, el NIÑO BIEN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "¿Adivina qué tengo?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Estoy dispuesto a ofrecerte la\n"
	.string "oportunidad de estar en mi equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "¡Buena decisión!\p"
	.string "Terminaré con el registro\n"
	.string "en un periquete.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "¿Me rechazas a mí, de entre todos?\n"
	.string "Seguro que te arrepientes.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "¡Hiyah!\n"
	.string "Soy {STR_VAR_1}, el KARATEKA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Como compañeros, tengo un\n"
	.string "{STR_VAR_2} con {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "y un {STR_VAR_2} con\n"
	.string "{STR_VAR_1}.\p"
	.string "¡Por favor, concédeme mi deseo!\n"
	.string "¡Déjame ser tu compañero!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "¡Hiyah!\n"
	.string "¡Voy a registrarme enseguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Ya veo… Espero tener una oportunidad\n"
	.string "la próxima vez que nos veamos…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "¡Hola!\n"
	.string "¡Soy {STR_VAR_1}, la PLAYERA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Te diré lo que tengo.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¿Puedo unirme a tu equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "¡Gracias!\n"
	.string "¡Voy a registrarnos ahora!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Si hubiéramos hecho equipo, habríamos\n"
	.string "sido muy fuertes.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Saludos…\n"
	.string "Soy {STR_VAR_1}, la BRUJITA…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "Llevo conmigo un {STR_VAR_2} con\n"
	.string "{STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_2} con {STR_VAR_1}…\p"
	.string "Te lo ruego…\n"
	.string "Únete a mí en un equipo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Te lo agradezco…\n"
	.string "Voy a registrarnos…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Tenía tantas ganas de unirme a ti…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "¿Qué tal? Soy {STR_VAR_1},\n"
	.string "y soy un CRIAPOKÉMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "¡Estoy criando a un par de buenos!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Qué te parece?\n"
	.string "¿Te apetece formar un equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "¡Muchas gracias!\p"
	.string "Me encargaré del registro,\n"
	.string "así que espera aquí.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "Tenía muchas ganas de ser\n"
	.string "tu compañero…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "¡Buenas!\n"
	.string "¡Soy {STR_VAR_1}, la TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "¿Quieres saber con qué corro?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Y bien?\n"
	.string "¿Quieres estar en mi equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "¡Así se habla!\p"
	.string "Seré rápida y me encargaré del\n"
	.string "registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Contigo, habríamos formado el\n"
	.string "equipo definitivo. Qué pena…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "¡Eh! ¡Me llamo {STR_VAR_1}!\n"
	.string "¡Soy un TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Corro con mi resistente equipo: un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "No está nada mal, ¿eh?\n"
	.string "¡Deberíamos formar un equipo juntos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "¡Vale!\n"
	.string "Voy a registrarme en un santiamén.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Tenía muchas ganas de luchar como\n"
	.string "tu compañero de equipo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "¡Soy {STR_VAR_1}, la LUCHADORA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "He estado endureciendo a un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te gusta esa combinación?\n"
	.string "¿Quieres unirte a mí?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "¡Gracias!\p"
	.string "Me encargaré del registro\n"
	.string "ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Contigo, pensé que podríamos formar\n"
	.string "el equipo definitivo…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "¡Soy {STR_VAR_1}, el TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "He estado corriendo con un {STR_VAR_2}\n"
	.string "que sabe usar {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "y un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Podríamos estar en un equipo.\n"
	.string "¿No sería genial?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "¡Gracias!\p"
	.string "Voy a registrarnos, y eso\n"
	.string "significa ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Vaya, qué pena. Habríamos sido\n"
	.string "el equipo más duro de la zona.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "¿Yo?\n"
	.string "¡Soy {STR_VAR_1}, el PLAYERO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "¿Qué llevo conmigo?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Eh?\n"
	.string "Harás equipo conmigo, ¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "¡Vale!\p"
	.string "¡Voy a registrarme!\n"
	.string "¡Seremos geniales juntos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Mis Pokémon son fuertes de verdad…\n"
	.string "Es una pena que no quieras hacer equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "¡Yay-hey!\n"
	.string "¡Llámame {STR_VAR_1}, el GUITARRISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "¡Mira mi séquito!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Yay-hey! ¡Qué pasada, eh?\n"
	.string "Tendremos que hacer un dúo en equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "¡Yay-hey! ¡Así se habla!\n"
	.string "Voy a registrarme ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "¡Mis Pokémon son la bomba!\n"
	.string "¡Te arrepentirás, te lo digo yo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Encantado de conocerte.\n"
	.string "Soy {STR_VAR_1}, un CABALLERO.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Me acompañan mi fiel {STR_VAR_2}\n"
	.string "con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Puedo pedirte que te unas a mí\n"
	.string "en un acuerdo de equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, te agradezco tu confianza.\n"
	.string "Me encargaré del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Es una lástima…\p"
	.string "Esperaré la próxima\n"
	.string "oportunidad…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hola, soy {STR_VAR_1},\n"
	.string "y soy un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Llevo conmigo ahora un {STR_VAR_2}\n"
	.string "que sabe el movimiento {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te gusta lo que ves?\n"
	.string "¿Por qué no eres mi compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "¡Gracias!\n"
	.string "Me encargaré del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Mis Pokémon son de primera clase…\n"
	.string "Es una pena que no lo aprecies.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "¡Mmm!\n"
	.string "Soy {STR_VAR_1}, ¡y soy un EXPERTO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Los Pokémon que he endurecido son\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Qué me dices?\n"
	.string "¿Quieres formar un equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "¡Mmm!\n"
	.string "¡Nos registraremos enseguida!\l"
	.string "¡Hagamos lo mejor que podamos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Esperaré que tu elección sea\n"
	.string "acertada…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hola, hola.\n"
	.string "Soy {STR_VAR_1}, y soy una EXPERTA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "He entrenado a mis Pokémon a fondo.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Eso es lo que tengo.\p"
	.string "¿No te gustaría formar un equipo\n"
	.string "conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bien, bien.\n"
	.string "Me encargaré del registro enseguida.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Quizá podamos formar un equipo la\n"
	.string "próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "¡Soy {STR_VAR_1}, el DOMADRAGÓN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "El equipo que he estado endureciendo\n"
	.string "es un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Qué te parece?\n"
	.string "¿Quieres ser mi compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "¡Vale, lo daré todo!\n"
	.string "Voy a registrarme ahora, ¿de acuerdo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "No vas a encontrar muchos compañeros\n"
	.string "más duros que yo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "¡Soy {STR_VAR_1}, el ORNITÓLOGO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "¿Qué Pokémon tengo?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿No crees que formaríamos un\n"
	.string "buen equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "¡Genial, gracias!\n"
	.string "Me encargaré del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mis Pokémon y yo somos fuertes.\n"
	.string "Qué decepción.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "¡Soy {STR_VAR_1}, el CHICO NINJA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mi equipo Pokémon está formado por\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¡Formemos un equipo juntos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "¡Yupi!\n"
	.string "¡Déjame que me registre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Te arrepentirás de no tener mis\n"
	.string "fuertes Pokémon de tu lado.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "¡Hola!\n"
	.string "¡Soy {STR_VAR_1}, la DAMA PARASOL!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Me acompañan mi {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "¿No son estupendos?\n"
	.string "¿Te unes a nosotros en un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "¡Muchas gracias!\p"
	.string "Voy a registrarme en el mostrador.\n"
	.string "¡No nos defraudemos el uno al otro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mis Pokémon son tremendamente\n"
	.string "fuertes. Qué decepción…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hola.\n"
	.string "Soy {STR_VAR_1}, y soy un POKéMANIÁTICO.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "He encontrado mis Pokémon, sí.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "Eso es lo que he encontrado.\p"
	.string "¿Te interesaría formar\n"
	.string "un equipo conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "¡Vale!\n"
	.string "¡Entendido!\p"
	.string "¡No tardaré en registrarme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Con los Pokémon que he encontrado,\n"
	.string "no habríamos perdido…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "¡Ahoy, compañero!\n"
	.string "¡Soy {STR_VAR_1}, el MARINERO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "¡Déjame que te enseñe mi orgullo!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Por supuesto que no me vas a rechazar.\n"
	.string "Haremos equipo, ¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "¡No esperaba menos!\n"
	.string "Voy a registrarme ahora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Habríamos arrasado con la\n"
	.string "competición. Qué pena.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hola, soy {STR_VAR_1}.\n"
	.string "Soy un COLECCIONISTA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Las joyas de mi colección son\n"
	.string "mi {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿A que son geniales?\n"
	.string "Deberíamos estar en un equipo juntos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "¡Oh, sí!\p"
	.string "Bueno, no perdamos tiempo.\n"
	.string "Voy a registrarnos a los dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Vaya, eso me molesta.\n"
	.string "No aprecias mis Pokémon.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "¡Hola! Soy {STR_VAR_1}.\n"
	.string "Soy un POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Me acompañan un {STR_VAR_2}\n"
	.string "con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿No crees que formaríamos un equipo\n"
	.string "impresionante?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "¡Eso es genial!\n"
	.string "Me encargaré del registro ahora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La próxima vez, elige mis Pokémon,\n"
	.string "¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Me llamo {STR_VAR_1}.\n"
	.string "¡Soy una POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Déjame que te hable de mi equipo.\n"
	.string "Tengo un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Qué te parece formar un equipo\n"
	.string "con mi pequeña pandilla?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "¡Estaremos en nuestra mejor forma!\n"
	.string "¡Me encargaré del registro rápido!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "Espero que elijas mis Pokémon\n"
	.string "la próxima vez.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Encantada de conocerte. Soy {STR_VAR_1}.\n"
	.string "Me considero una DAMA AROMA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Viajo con un {STR_VAR_2}\n"
	.string "que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1}.\p"
	.string "Espero que sean de tu agrado.\n"
	.string "¿Te importaría ser mi compañero?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Me siento honrada por tu aceptación.\n"
	.string "Me encargaré del registro ahora mismo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Sería maravilloso si pudiéramos formar\n"
	.string "un equipo la próxima vez que nos veamos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "¿Quieres saber quién soy?\n"
	.string "¡Soy {STR_VAR_1}, el RUINAMANÍACO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Los Pokémon que llevo conmigo son\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Intrigante, eh?\n"
	.string "¿Quieres que hagamos equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "¡Esa es una decisión sensata!\n"
	.string "Voy a ocuparme del papeleo del\l"
	.string "registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Mmm…\n"
	.string "Creo que mis Pokémon son fuertes…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "¡Soy {STR_VAR_1}, el ENTRENADOR GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Los Pokémon que tengo ahora son un\n"
	.string "{STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\n"
	.string "¿Guay, eh?\p"
	.string "¿No crees que sería genial si\n"
	.string "formáramos un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "¡Guay!\n"
	.string "Voy a registrarme en un periquete.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Pensaba que formaríamos el\n"
	.string "equipo más genial de todos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "¡Soy {STR_VAR_1}, la ENTRENADORA GUAY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "El equipo que he estado criando tiene\n"
	.string "un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Suena bien?\n"
	.string "¿Quieres que seamos compañeros?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "¡Suena genial!\n"
	.string "Mejor me encargo del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Pensaba que seríamos un equipo\n"
	.string "muy duro…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "¡Heyo!\n"
	.string "¡Soy {STR_VAR_1}, el POKéMANIÁTICO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "¿Qué tiene un tipo como yo?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1},\n"
	.string "¡eso es lo que tengo!\p"
	.string "¡Vamos allá!\n"
	.string "¡Patearemos traseros como equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "¡Buena elección!\n"
	.string "¡Voy a registrarnos a los dos!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Mis Pokémon son brutales.\n"
	.string "No es culpa mía si te arrepientes.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "¡Eh, hola!\n"
	.string "¡Soy {STR_VAR_1}, el FOGONERO!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "¿Sabes qué ha cocinado mi entrenamiento?\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "Bueno, ¿qué me dices?\n"
	.string "¿Quieres formar un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "¡Vale!\n"
	.string "Voy a ocuparme del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Prométeme que harás equipo conmigo\n"
	.string "la próxima vez que nos encontremos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "¡Soy {STR_VAR_1}, el CAMPISTA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "He estado criando un {STR_VAR_2}\n"
	.string "con {STR_VAR_1} y un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Crees que sería divertido hacer equipo?\n"
	.string "¡Apuesto a que sí!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "¡Sí!\n"
	.string "¡Voy a registrarme!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "La próxima vez, ¿vale?\n"
	.string "Quiero estar en tu equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "¡Hola!\n"
	.string "¡Soy {STR_VAR_1}, la DOMADORA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Los Pokémon que he estado llevando\n"
	.string "son un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Te interesa unirte a mí\n"
	.string "en un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "¡Vaya, gracias!\n"
	.string "Voy a registrarme ahora.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Me habría gustado poder unirme\n"
	.string "a ti en otra ocasión.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "¡Soy {STR_VAR_1}, el MÉDIUM!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "El dúo que he criado es un {STR_VAR_2}\n"
	.string "con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿Quieres formar un equipo\n"
	.string "conmigo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "¡Claro que sí!\n"
	.string "¡Yo me encargo del registro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Si nos volvemos a encontrar, me\n"
	.string "gustaría formar equipo contigo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Soy {STR_VAR_1}.\n"
	.string "Soy MÉDIUM.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}--\n"
	.string "son mis discípulos.\p"
	.string "¿No te parece interesante la idea\n"
	.string "de formar un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Gracias.\n"
	.string "Voy a encargarme del registro.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "Espero que haya otra oportunidad\n"
	.string "de forjar una alianza.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "¡Soy {STR_VAR_1}, la ESCOLAR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "y un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} son mi pareja Pokémon.\p"
	.string "¿Puedo ser tu compañera en\n"
	.string "un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "¡Oh, gracias!\n"
	.string "¡Voy a registrarnos enseguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "¿Por favor?\n"
	.string "¿Puedo unirme a ti la próxima vez?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "¡Hola! Me llamo {STR_VAR_1}.\n"
	.string "¡Soy CRIADORA POKéMON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Los Pokémon que he criado son un\n"
	.string "{STR_VAR_2} que usa {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "un {STR_VAR_2} que usa {STR_VAR_1}.\p"
	.string "¿Te parece interesante?\n"
	.string "¿Qué tal si formamos un equipo?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "¡Perfecto!\n"
	.string "¡Yo me encargo del registro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Tienes que formar equipo conmigo\n"
	.string "la próxima vez, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Soy {STR_VAR_1}, y me enorgullezco\n"
	.string "de ser una POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Los adorables Pokémon que he criado\n"
	.string "son un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}.\p"
	.string "¿No son una monada?\n"
	.string "¡Deberíamos hacer un equipo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "¡Gracias, cariño!\n"
	.string "¡Voy a registrarnos enseguida!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Mis adorables Pokémon son los mejores,\n"
	.string "te lo aseguro. ¡Qué fastidio!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hola, soy {STR_VAR_1}, la NADADORA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Un {STR_VAR_2} que usa {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "y un {STR_VAR_2} que usa\n"
	.string "{STR_VAR_1} son los que he entrenado.\p"
	.string "Tú y yo, hagamos un equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "¡Genial!\n"
	.string "Voy a registrarnos a los dos.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Si nos volvemos a encontrar, me debes\n"
	.string "un equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "¿Qué pasa? Soy {STR_VAR_1},\n"
	.string "y soy TRIATLETA.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "Tengo un par de Pokémon decentes.\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "Estaría bien formar un equipo\n"
	.string "juntos, ¿qué dices?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "¡Muy bien!\n"
	.string "Espera mientras me encargo del\l"
	.string "registro, ¿vale?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Espero que me dejes unirme a ti\n"
	.string "la próxima vez, ¿qué te parece?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "¡Soy {STR_VAR_1}, la TRIATLETA!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "otro {STR_VAR_2} que sabe usar\n"
	.string "{STR_VAR_1}. Esa es mi pareja.\p"
	.string "¿Qué te parece?\n"
	.string "Creo que haríamos un buen equipo.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "¡Me gusta esa respuesta!\n"
	.string "¡Voy a encargarme del registro rápido!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Me darás otra oportunidad de formar\n"
	.string "una alianza, ¿verdad?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "¡Hola, hola! Soy {STR_VAR_1},\n"
	.string "¡y soy NADADOR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "¡Mira lo que he estado criando!\n"
	.string "Un {STR_VAR_2} con {STR_VAR_1} y$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "un {STR_VAR_2} con {STR_VAR_1}!\p"
	.string "¿A que mola?\n"
	.string "¡Formar un equipo también molaría!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "¡Muchas gracias!\n"
	.string "¡Voy a encargarme de lo del registro!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Si nos volvemos a encontrar, tienes\n"
	.string "que formar equipo conmigo. ¿Lo harás?$"

