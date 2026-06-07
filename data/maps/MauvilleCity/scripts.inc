MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "TÍO: Supongo que es por los Pokémon\n"
	.string "que este chico tiene tanto brío…\l"
	.string "Pero se ha vuelto un poco demasiado\l"
	.string "enérgico…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "BLASCO: Eh… ¡Tío!\p"
	.string "Quiero desafiar al Líder de este\n"
	.string "gimnasio y ver cuánto he mejorado.\l"
	.string "¿Puedo? ¿Puedo? Porfaaa…$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "TÍO: Espera un poco, Blasco…\p"
	.string "Es cierto que te has vuelto mucho más\n"
	.string "fuerte desde que tienes a tu Pokémon.\p"
	.string "¿Pero no crees que te precipitas un poco\n"
	.string "cuando hablas de desafiar a un Líder\l"
	.string "de Gimnasio?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "BLASCO: No me estoy precipitando…\p"
	.string "¡Si Ralts y yo unimos fuerzas,\n"
	.string "podemos con todo!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "BLASCO: Oh, hola, {PLAYER}.\p"
	.string "¡No te puedes ni imaginar lo que he\n"
	.string "mejorado desde la última vez!\l"
	.string "¡Ralts y yo hemos entrenado muchísimo!\p"
	.string "{PLAYER}, quiero que mi Tío y tú no\n"
	.string "tengáis ninguna duda al respecto.\p"
	.string "{PLAYER}, ¿querrías luchar conmigo?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "BLASCO: Oh, pues si no libramos un\n"
	.string "combate, mi tío no podrá ver lo fuerte\l"
	.string "que me he vuelto…$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "TÍO: {PLAYER}{KUN}, ¿verdad?\p"
	.string "En nombre de Blasco, ¿podría pedirte\n"
	.string "que luches con él solo esta vez?\p"
	.string "No creo que vaya a escuchar razones\n"
	.string "estando como está.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "BLASCO: {PLAYER}, ¡por favor!\n"
	.string "¡Lucha conmigo, por favor!$"

MauvilleCity_Text_WallyHereICome:
	.string "BLASCO: {PLAYER}, gracias.\p"
	.string "Muy bien… ¡Allá vamos!$"

MauvilleCity_Text_WallyDefeat:
	.string "BLASCO: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Pues… Pues… Pues he perdido…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "BLASCO: Tío…\n"
	.string "Me vuelvo a Pueblo Verdegal…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, gracias.\n"
	.string "Es duro ser un Entrenador, ¿no?\p"
	.string "No basta con tener Pokémon y hacerlos\n"
	.string "combatir. Ser Entrenador es más que\l"
	.string "eso…$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "TÍO: Blasco, no debes venirte abajo\n"
	.string "por esto…\p"
	.string "A ver, ¿qué te impide mejorar cada vez\n"
	.string "más?\p"
	.string "Venga, vámonos a casa.\n"
	.string "Todos te están esperando.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "TÍO: {PLAYER}{KUN}, acabo de darme cuenta\n"
	.string "de que tú fuiste quien ayudó a Blasco\l"
	.string "a atrapar su Pokémon.\p"
	.string "¿Por qué no vienes a visitarnos a\n"
	.string "Pueblo Verdegal algún día?\l"
	.string "A Blasco le haría ilusión.$"

MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … ¡Beep!\p"
	.string "BLASCO: Oh, hola, {PLAYER}.\p"
	.string "Solo quería decirte que mi tío me ha\n"
	.string "comprado un PokéNav.\p"
	.string "¡Ahora puedo contactar contigo\n"
	.string "cuando quiera, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … ¡Click!$"

MauvilleCity_Text_RegisteredWally:
	.string "Se ha registrado a BLASCO\n"
	.string "en el PokéNav.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "TRETO: Je, je…\n"
	.string "¡He estado viendo ese combate!\p"
	.string "Eres amigo de ese chico Blasco,\n"
	.string "¿verdad?\p"
	.string "Pero no te has guardado nada y le has\n"
	.string "derrotado de forma impresionante.\p"
	.string "¡Sí! ¡Así es como debe ser un combate\n"
	.string "Pokémon de verdad!\p"
	.string "¡Admiro a los Entrenadores así!\p"
	.string "… … … … … …\n"
	.string "¡Te estaré animando!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "ERICO: Oh, {PLAYER}{KUN}.\n"
	.string "¡Parece que tienes mucho brío!\l"
	.string "¡Eso es bueno, ja, ja, ja, ja!\p"
	.string "¡Vale! ¡Lo he decidido!\n"
	.string "¡Necesito un favor, {PLAYER}{KUN}!\p"
	.string "MALVALONA tiene un sector subterráneo\n"
	.string "llamado NUEVA MALVALONA.\p"
	.string "{PLAYER}{KUN}, me gustaría que fueras allí\n"
	.string "y apagaras el GENERADOR.\p"
	.string "El GENERADOR se ha estado comportando\n"
	.string "un poco erráticamente. Se está\l"
	.string "volviendo peligroso.\p"
	.string "Toma, esta es la LLAVE para entrar en\n"
	.string "NUEVA MALVALONA.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "ERICO: No te preocupes.\n"
	.string "No será un desafío para ti.\p"
	.string "La entrada a NUEVA MALVALONA está a\n"
	.string "una corta distancia nadando desde la\l"
	.string "RUTA 110.\p"
	.string "Eso es todo, ¡confío en ti!\n"
	.string "¡Ja, ja, ja, ja!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "ERICO: ¡Ja, ja, ja, ja!\p"
	.string "¡Lo sabía, {PLAYER}{KUN}! ¡Sabía que había\n"
	.string "hecho bien pidiéndotelo!\p"
	.string "Esto es mi agradecimiento: una MT que\n"
	.string "contiene RAYO.\p"
	.string "¡Venga, te la has ganado!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "ERICO: ¡Ja, ja, ja, ja!\p"
	.string "¡Me alegra un montón ver a los jóvenes\n"
	.string "tomar las riendas!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Sabes, es genial tener combates Pokémon\n"
	.string "y todo eso…\p"
	.string "Pero si tu Pokémon se hace daño,\n"
	.string "tienes que curarlo.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Las calles de este pueblo se extienden\n"
	.string "hacia el norte y el sur, y hacia el\l"
	.string "este y el oeste.\p"
	.string "Por eso, pasa toda clase de gente\n"
	.string "por aquí.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "¿Has estado ya en las BICIS de\n"
	.string "RODOLFO?\p"
	.string "RODOLFO, el dueño, es un hombre\n"
	.string "muy generoso.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Incluso si vas en BICI, los Pokémon\n"
	.string "salvajes pueden atacarte.$"

MauvilleCity_Text_CitySign:
	.string "CIUDAD MALVALONA\n"
	.string "“¡La ciudad brillante y radiante de la\l"
	.string "diversión!”$"

MauvilleCity_Text_GymSign:
	.string "GIMNASIO POKéMON de CIUDAD MALVALONA\n"
	.string "LÍDER: ERICO\l"
	.string "“¡El hombre alegre y electrizante!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“¡Monta en grava y sacude tu alma!”\n"
	.string "BICIS de RODOLFO$"

MauvilleCity_Text_GameCornerSign:
	.string "“¡El lugar de juegos para todos!”\n"
	.string "CASINO de MALVALONA$"

MauvilleCity_Text_ExplainTV:
	.string "Hola, ¿ves la tele a menudo?\p"
	.string "Han añadido un montón de programas\n"
	.string "nuevos recientemente.\p"
	.string "La tele es genial. He visto a mis amigos\n"
	.string "en la tele de repente.\p"
	.string "Y, a veces, incluso te ponen en la tele\n"
	.string "sin avisarte.\p"
	.string "Ojalá me pusieran en la tele algún día.\p"
	.string "Por eso creo que deberías mirar la tele\n"
	.string "siempre que puedas.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hola, ¿has estado mirando la tele?$"
