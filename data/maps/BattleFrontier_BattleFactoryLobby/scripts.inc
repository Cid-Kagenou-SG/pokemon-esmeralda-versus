BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "¡Donde se pone a prueba la inteligencia\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Bienvenido/a a la FÁBRICA de BATALLA!\p"
	.string "Soy tu guía para el Torneo de\n"
	.string "Intercambio de Batalla Individual.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "¿Deseas aceptar el desafío de\n"
	.string "Intercambio de Batalla Individual?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "El Torneo de Intercambio de Batalla\n"
	.string "Individual es una competición de\l"
	.string "COMBATE INDIVIDUAL usando solo\l"
	.string "Pokémon de alquiler.\p"
	.string "Primero, se te prestarán tres Pokémon\n"
	.string "específicamente para este evento.\p"
	.string "Usando los Pokémon de alquiler\n"
	.string "proporcionados, debes realizar un\l"
	.string "COMBATE INDIVIDUAL.\p"
	.string "Si ganas, se te permitirá intercambiar\n"
	.string "uno de tus Pokémon de alquiler.\p"
	.string "Repite este ciclo de combate e\n"
	.string "intercambio: si ganas siete veces\l"
	.string "seguidas, ganarás Puntos de Batalla.\p"
	.string "Si quieres interrumpir tu desafío,\n"
	.string "por favor guarda la partida.\p"
	.string "Si no guardas, serás descalificado/a\n"
	.string "de tu desafío.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Esperamos tu próxima visita.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "¿Qué nivel deseas desafiar?\n"
	.string "¿Nivel 50 o Nivel Libre?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Antes de empezar tu desafío, debo\n"
	.string "guardar la partida. ¿Te parece bien?$"

@ Sin usar
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "Bien, guardaré tus Pokémon para que\n"
	.string "estén seguros mientras compites.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Por aquí, por favor.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "¡Gracias por participar!\p"
	.string "Devolveré tus Pokémon a cambio de\n"
	.string "nuestros Pokémon de alquiler.\p"
	.string "También debo guardar los resultados\n"
	.string "del evento. Espera, por favor.$"

@ Sin usar
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Devolveré tus Pokémon a cambio de\n"
	.string "nuestros Pokémon de alquiler.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "¡Enhorabuena! ¡Has ganado siete\n"
	.string "combates de Intercambio de Batalla\l"
	.string "seguidos!$"

@ Sin usar
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "En reconocimiento a tu racha de 7\n"
	.string "victorias, te otorgamos estos Punto(s)\l"
	.string "de Batalla.$"

@ Sin usar
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "¡Oh, oh, oh!\p"
	.string "Tus Puntos de Batalla están al máximo.\p"
	.string "Por favor, vuelve después de usar\n"
	.string "algunos Puntos de Batalla.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "¡Te estábamos esperando!\p"
	.string "Antes de reanudar tu desafío, debo\n"
	.string "guardar la partida.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Siento decirte esto, pero no guardaste\n"
	.string "antes de abandonar la partida la última\l"
	.string "vez.\p"
	.string "Como resultado, has sido descalificado/a\n"
	.string "de tu desafío.$"

@ Sin usar
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Devolveremos tus Pokémon personales.$"

@ Sin usar
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrize:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "¡Donde se pone a prueba la inteligencia\n"
	.string "de los ENTRENADORES!\p"
	.string "¡Bienvenido/a a la FÁBRICA de BATALLA!\p"
	.string "Soy tu guía para el Torneo de\n"
	.string "Intercambio de Batalla Doble.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "¿Deseas aceptar el desafío de\n"
	.string "Intercambio de Batalla Doble?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "El Torneo de Intercambio de Batalla\n"
	.string "Doble es una competición de COMBATE\l"
	.string "DOBLE usando solo Pokémon de alquiler.\p"
	.string "Primero, se te prestarán tres Pokémon\n"
	.string "específicamente para este evento.\p"
	.string "Usando los Pokémon de alquiler\n"
	.string "proporcionados, debes realizar un\l"
	.string "COMBATE DOBLE.\p"
	.string "Si ganas, se te permitirá intercambiar\n"
	.string "uno de tus Pokémon de alquiler.\p"
	.string "Repite este ciclo de combate e\n"
	.string "intercambio: si ganas siete veces\l"
	.string "seguidas, ganarás Puntos de Batalla.\p"
	.string "Si quieres interrumpir tu desafío,\n"
	.string "por favor guarda la partida.\p"
	.string "Si no guardas antes de interrumpir,\n"
	.string "serás descalificado/a.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "¡Enhorabuena por derrotar al JEFE de\n"
	.string "FÁBRICA y ganar siete combates seguidos!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "En reconocimiento a tu riqueza de\n"
	.string "conocimiento y aguda inteligencia, te\l"
	.string "otorgamos estos Punto(s) de Batalla.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Déjame intercambiar tus Pokémon por\n"
	.string "nuestros Pokémon de alquiler.\p"
	.string "Necesito guardar los datos del combate,\n"
	.string "así que espera, por favor.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "¿Te gustaría grabar tu último combate\n"
	.string "de la FÁBRICA de BATALLA en tu PASE\l"
	.string "del FRENTE de BATALLA?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "¡Hola!\n"
	.string "¡Tú, allí!\p"
	.string "¿Estás pensando que los eventos aquí\n"
	.string "son fáciles porque no necesitas tener\l"
	.string "un equipo entrenado de Pokémon?\p"
	.string "No estaría tan seguro de ganar\n"
	.string "tan fácilmente.\p"
	.string "Si no tienes un conocimiento exhaustivo\n"
	.string "sobre Pokémon y sus movimientos, será\l"
	.string "difícil seguir ganando.$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "Intercambié por un Pokémon débil…\n"
	.string "Pensé que era un buen tipo para tener…\p"
	.string "Nos hicieron polvo…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Las cosas no me han ido bien en\n"
	.string "absoluto.\p"
	.string "Necesitas comprobar los Pokémon de tu\n"
	.string "rival durante el combate para ver si\l"
	.string "son buenos.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "¿Sabes que el personal aquí te da\n"
	.string "algunas pistas sobre tu próximo\l"
	.string "rival?\p"
	.string "Bueno, soy un hombre hecho y derecho,\n"
	.string "pero tengo problemas para entender\l"
	.string "sus pistas.$"

@ Sin usar
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Es que soy muy duro, pero me aburro\n"
	.string "muy fácilmente, así que solo seguí\l"
	.string "intercambiando y combatiendo una y\l"
	.string "otra vez.\p"
	.string "Así que, de todos modos, cuando seguí\n"
	.string "entrando en eventos de Intercambio de\l"
	.string "Batalla, noté que variaban los Pokémon\l"
	.string "de alquiler.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Se muestran las reglas del Intercambio\n"
	.string "de Batalla.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "¿Qué apartado quieres leer?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "En un evento de Intercambio de Batalla,\n"
	.string "puedes usar solo tres Pokémon.\p"
	.string "Ya sea que estés alquilando o\n"
	.string "intercambiando, tu equipo no puede\l"
	.string "tener dos o más del mismo Pokémon.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Solo puedes intercambiar Pokémon con\n"
	.string "el ENTRENADOR que acabas de derrotar.\p"
	.string "Solo puedes intercambiar por aquellos\n"
	.string "Pokémon usados por el ENTRENADOR\l"
	.string "derrotado.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Después de cada combate que ganes,\n"
	.string "puedes intercambiar por uno de los\l"
	.string "Pokémon de tu oponente derrotado.\p"
	.string "No podrás intercambiar Pokémon con el\n"
	.string "séptimo ENTRENADOR del evento.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Hay dos puntos clave a tener en cuenta\n"
	.string "al intercambiar Pokémon.\p"
	.string "Primero, al intercambiar, no puedes\n"
	.string "comprobar las estadísticas del Pokémon\l"
	.string "que estás a punto de recibir.\p"
	.string "Segundo, los Pokémon de tu equipo están\n"
	.string "alineados en secuencia, dependiendo del\l"
	.string "orden en que los alquilaste.\p"
	.string "Esta secuencia permanece inalterada\n"
	.string "incluso cuando se realizan intercambios.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "En el Nivel Libre, los Pokémon de\n"
	.string "alquiler y los Pokémon de los\l"
	.string "ENTRENADORES rivales son todos de\l"
	.string "Nivel 100.$"
