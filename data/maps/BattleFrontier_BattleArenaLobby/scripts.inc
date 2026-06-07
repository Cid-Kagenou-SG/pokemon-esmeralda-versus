BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
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

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "¡Donde se pone a prueba el espíritu\n"
	.string "de combate de los ENTRENADORES!\p"
	.string "¡Te doy la bienvenida a la ARENA de\n"
	.string "BATALLA!\p"
	.string "Soy tu guía para el Torneo KO\n"
	.string "Definitivo!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Ahora, ¿deseas aceptar el desafío\n"
	.string "de la ARENA de BATALLA?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "¡Esperamos tu desafío en otra\n"
	.string "ocasión!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "En la ARENA de BATALLA, realizamos el\n"
	.string "Torneo KO Definitivo.\p"
	.string "Todos los participantes entran con un\n"
	.string "equipo de tres POKéMON.\p"
	.string "Los tres POKéMON deben alinearse en\n"
	.string "el orden en que van a aparecer.\p"
	.string "Durante el combate, los POKéMON\n"
	.string "aparecerán uno a uno en el orden\l"
	.string "predeterminado.\p"
	.string "Una vez que un POKéMON entra en\n"
	.string "combate, debe permanecer fuera hasta\l"
	.string "que el combate se decida.\p"
	.string "Si un combate permanece indeciso en\n"
	.string "tres turnos, pasa a valoración.\p"
	.string "Si deseas interrumpir tu desafío,\n"
	.string "por favor guarda la partida.\p"
	.string "Si no guardas, no podrás continuar\n"
	.string "con tu desafío.\p"
	.string "Si logras el logro de vencer a siete\n"
	.string "ENTRENADORES seguidos, te entregaremos\l"
	.string "Puntos de Batalla.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Antes de llevarte a la ARENA de\n"
	.string "BATALLA, debes guardar. ¿Te parece\l"
	.string "bien?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "La ARENA de BATALLA ofrece dos niveles\n"
	.string "de desafío: Nivel 50 y Nivel Libre.\l"
	.string "¿Cuál eliges?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Muy bien, ahora selecciona tus tres\n"
	.string "POKéMON, por favor.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "¡Mi querido desafiante!\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para entrar.\p"
	.string "Para calificar, debes traer tres\n"
	.string "POKéMON de distintas clases.\p"
	.string "Además, no deben llevar objetos de\n"
	.string "las mismas clases.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Cuando hayas hecho tus preparativos,\n"
	.string "por favor, vuelve.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "¡Mi querido desafiante!\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para entrar.\p"
	.string "Para calificar, debes traer tres\n"
	.string "POKéMON de distintas clases.\p"
	.string "Los tres POKéMON distintos deben ser\n"
	.string "todos de Nivel 50 o inferior.\p"
	.string "Además, no deben llevar objetos de\n"
	.string "las mismas clases.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Cuando hayas hecho tus preparativos,\n"
	.string "por favor, vuelve.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Ahora te acompañaré a la ARENA de\n"
	.string "BATALLA.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "¡Mi querido desafiante!\p"
	.string "No guardaste la partida antes de\n"
	.string "apagar, ¿verdad?\p"
	.string "Es lamentable, pero eso ha resultado\n"
	.string "en tu descalificación de tu desafío.\p"
	.string "Puedes, por supuesto, empezar con un\n"
	.string "desafío nuevo.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "¡Te felicitamos por tu magnífica\n"
	.string "racha de victorias sobre siete\l"
	.string "ENTRENADORES!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Se registrará tu hazaña.\n"
	.string "Espera mientras guardo la partida.$"

@ Sin usar
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "En conmemoración de tu racha de 7\n"
	.string "victorias, te entregamos este premio.$"

@ Sin usar
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

@ Sin usar
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "¿Oh?\n"
	.string "Tu MOCHILA parece estar llena.\p"
	.string "Te insto a que hagas espacio y vuelvas\n"
	.string "por tu premio.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "¡Muchas gracias por participar!\p"
	.string "Espera mientras guardo la partida.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "¡Esperamos tu desafío en otra\n"
	.string "ocasión!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Hemos estado esperando tu llegada.\p"
	.string "Antes de llevarte a la ARENA de\n"
	.string "BATALLA, debo guardar la partida.\l"
	.string "Espera, por favor.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "¿Debería grabar tu último combate de\n"
	.string "la ARENA de BATALLA en tu PASE del\l"
	.string "FRENTE de BATALLA?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "Perdí por decisión del ÁRBITRO…\p"
	.string "No creo que fuera buena idea solo usar\n"
	.string "movimientos defensivos y no atacar…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "¡Gané en la valoración!\p"
	.string "¡Aterrizar golpes consistentemente en\n"
	.string "el POKéMON del rival funcionó!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Nuestro combate fue declarado empate.\p"
	.string "Cuando se acabó el tiempo, tanto mi\n"
	.string "POKéMON como el del oponente tenían\l"
	.string "aproximadamente la misma cantidad de\l"
	.string "PS restantes.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "En la ARENA de BATALLA, el orden de\n"
	.string "los POKéMON es totalmente importante.\p"
	.string "Por ejemplo, si tu primer POKéMON tiene\n"
	.string "ciertas desventajas de tipo, intenta\l"
	.string "que tu segundo POKéMON sea uno con\l"
	.string "movimientos que sean supereficaces\l"
	.string "contra el primero.\p"
	.string "Creo que esa será una buena forma de\n"
	.string "hacer un equipo efectivo.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Se muestran las reglas del Torneo KO\n"
	.string "Definitivo.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "¿Qué apartado quieres leer?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "El Torneo KO Definitivo tiene reglas\n"
	.string "especiales, a diferencia de los combates\l"
	.string "estándar.\p"
	.string "Primero, un combate dura solo tres\n"
	.string "turnos.\p"
	.string "Si el resultado no se decide después\n"
	.string "de tres turnos, pasa a valoración.\p"
	.string "El ÁRBITRO elegirá al ganador basándose\n"
	.string "en cómo combatieron los POKéMON.\p"
	.string "Además, un POKéMON no puede ser\n"
	.string "cambiado hasta que se decida el\l"
	.string "resultado de su combate.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "El primer factor de valoración es\n"
	.string "“Mente”. Este factor evalúa qué tan\l"
	.string "agresivos fueron los combatientes.\p"
	.string "La valoración se basa en cuántas veces\n"
	.string "los ENTRENADORES ordenaron el uso de\l"
	.string "movimientos ofensivos.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "El segundo factor de valoración es\n"
	.string "“Habilidad”. Este factor evalúa qué tan\l"
	.string "eficazmente se usaron los movimientos\l"
	.string "POKéMON.\p"
	.string "Si un movimiento funcionó con éxito,\n"
	.string "la valoración de Habilidad sube.\p"
	.string "Si un movimiento falló, la valoración\n"
	.string "de Habilidad baja.\p"
	.string "Si fue un movimiento ofensivo, la\n"
	.string "valoración de Habilidad sube si el\l"
	.string "movimiento fue “supereficaz” y baja si\l"
	.string "fue “poco eficaz”.\p"
	.string "La valoración de Habilidad no subirá\n"
	.string "por movimientos como PROTECCIÓN y\l"
	.string "DETECCIÓN.\p"
	.string "Si el oponente usó PROTECCIÓN o\n"
	.string "DETECCIÓN, y tu POKéMON falló al\l"
	.string "golpear con un movimiento, su\l"
	.string "valoración de Habilidad no bajará.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "El tercer factor de valoración es\n"
	.string "“Cuerpo”. Este factor se basa en cuántos\l"
	.string "PS quedaron al final del combate.\p"
	.string "La valoración tiene en cuenta cuántos\n"
	.string "PS tenía un POKéMON al inicio del\l"
	.string "combate, y cuántos quedaron al final.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "¡Una victoria arrebatada al MAGNATE\n"
	.string "de la ARENA, y una barrida de siete\l"
	.string "ENTRENADORES!\p"
	.string "¡Te felicitamos por tu más espléndido\n"
	.string "desafío!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Mi querido desafiante, en reconocimiento\n"
	.string "a tu espíritu incansable, por favor\l"
	.string "acepta estos Punto(s) de Batalla.$"
