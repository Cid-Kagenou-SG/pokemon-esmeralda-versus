BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "Donde se pone a prueba el corazón\n"
	.string "de los ENTRENADORES.\p"
	.string "Te doy la bienvenida al PALACIO de\n"
	.string "BATALLA.\p"
	.string "Acepto desafíos para las SALAS de\n"
	.string "COMBATE INDIVIDUAL.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "¿Deseas aceptar el desafío de la\n"
	.string "SALA de COMBATE INDIVIDUAL?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "En el PALACIO de BATALLA hay varias\n"
	.string "SALAS para COMBATES INDIVIDUALES que\l"
	.string "se llaman SALAS de COMBATE INDIVIDUAL.\p"
	.string "Los COMBATES INDIVIDUALES se libran\n"
	.string "de la forma habitual, salvo una regla\l"
	.string "crucial que debe obedecerse.\p"
	.string "Los ENTRENADORES solo pueden cambiar\n"
	.string "sus POKéMON de entrada y salida.\p"
	.string "Los ENTRENADORES no pueden dar órdenes\n"
	.string "a sus POKéMON de ninguna otra forma.\p"
	.string "Los POKéMON deben actuar según su\n"
	.string "naturaleza y combatir por sí mismos.\p"
	.string "Debes confiar en tus POKéMON y\n"
	.string "observarlos.\p"
	.string "Si logras el honor de vencer a siete\n"
	.string "ENTRENADORES seguidos, te entregaremos\l"
	.string "Puntos de Batalla.\p"
	.string "Si quieres interrumpir tu desafío,\n"
	.string "debes guardar la partida.\p"
	.string "Si no guardas antes de interrumpir,\n"
	.string "serás descalificado/a.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "Cuando hayas fortalecido tu corazón\n"
	.string "y el de tus POKéMON, debes volver.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "Hay dos SALAS de COMBATE: Nivel 50\n"
	.string "y Nivel Libre. ¿Cuál eliges para tu\l"
	.string "desafío?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "Suspiro…\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para el desafío.\p"
	.string "Para entrar, debes presentar tres\n"
	.string "POKéMON de distintas clases.\p"
	.string "Todos estos POKéMON deben ser de\n"
	.string "Nivel 50 o inferior.\p"
	.string "Además, no deben llevar objetos de\n"
	.string "las mismas clases.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Vuelve cuando hayas hecho los\n"
	.string "preparativos.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Suspiro…\p"
	.string "No tienes los tres POKéMON necesarios\n"
	.string "para el desafío.\p"
	.string "Para entrar, debes presentar tres\n"
	.string "POKéMON de distintas clases.\p"
	.string "Además, no deben llevar objetos de\n"
	.string "las mismas clases.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Vuelve cuando hayas hecho los\n"
	.string "preparativos.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "Bien. Ahora debes seleccionar tus\n"
	.string "tres POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "Debo guardar antes de llevarte a la\n"
	.string "SALA de COMBATE. ¿Te parece bien?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "Bien.\n"
	.string "Ahora, sígueme.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "Me siento privilegiado/a por haber\n"
	.string "presenciado las proezas de tus POKéMON.\p"
	.string "Se registrarán los resultados.\n"
	.string "Te pido que esperes un momento.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "Para lograr una racha de 7 victorias…\p"
	.string "Los lazos que unen tu corazón con el\n"
	.string "de tus POKéMON parecen firmes y\l"
	.string "verdaderos.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "Se registrará tu hazaña.\n"
	.string "Te pido que esperes un momento.$"

@ Sin usar
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "Por el logro de tu racha de 7 victorias,\n"
	.string "te entregamos Punto(s) de Batalla.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "Parece que no tienes espacio para\n"
	.string "nuestro premio.\p"
	.string "Deberías volver cuando hayas\n"
	.string "organizado tu MOCHILA.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "Te estábamos esperando…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "Debo guardar antes de llevarte a la\n"
	.string "SALA de COMBATE. ¿Te parece bien?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "Suspiro…\p"
	.string "No guardaste antes de terminar tu\n"
	.string "desafío la última vez.\p"
	.string "Como resultado, tu desafío ha sido\n"
	.string "descalificado. Es muy lamentable.$"

@ Sin usar
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "Para un tipo duro como yo, los POKéMON\n"
	.string "duros son los mejores.\p"
	.string "¡El ataque es la mejor defensa!\n"
	.string "¡Un ataque implacable es lo supremo!\p"
	.string "Pero eso no es de lo que quería hablar.\p"
	.string "De vez en cuando pasa por aquí una\n"
	.string "chica realmente mona.\p"
	.string "Dice que puede saber qué piensan\n"
	.string "los POKéMON.\p"
	.string "No sé qué pensar de eso, pero es\n"
	.string "realmente mona.\p"
	.string "¿Eh?\n"
	.string "¿Por qué me miras así?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "Mmm…\p"
	.string "Parece que la naturaleza de los POKéMON\n"
	.string "y los movimientos que han aprendido son\l"
	.string "la clave para combatir aquí.\p"
	.string "Para ser más precisos, se trata de\n"
	.string "cuán bien encajan los movimientos con\l"
	.string "la naturaleza del POKéMON.\p"
	.string "Si tu POKéMON tiene problemas y no\n"
	.string "puede dar lo mejor de sí, quizá debas\l"
	.string "examinar cuán bien encajan sus\l"
	.string "movimientos con su naturaleza.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "Mi POKéMON suele ser muy dócil.\p"
	.string "Pero cuando está en una SALA de\n"
	.string "COMBATE, a veces parece transformarse\l"
	.string "en algo malvado.\p"
	.string "Se vuelve totalmente intimidante.\n"
	.string "Es incluso impactante.$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "Me pregunto qué naturaleza tendría un\n"
	.string "POKéMON que prefiriera debilitar a sus\l"
	.string "oponentes y desgastarlos poco a poco.\p"
	.string "Me sorprendería que fuera una\n"
	.string "naturaleza RELAJADA.\p"
	.string "Pero, nah, eso no puede ser.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "Donde se pone a prueba el corazón\n"
	.string "de los ENTRENADORES.\p"
	.string "Te doy la bienvenida al PALACIO de\n"
	.string "BATALLA.\p"
	.string "Acepto desafíos para las SALAS de\n"
	.string "COMBATE DOBLE.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "¿Deseas aceptar el desafío de la\n"
	.string "SALA de COMBATE DOBLE?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "En el PALACIO de BATALLA hay varias\n"
	.string "SALAS para COMBATES DOBLES que se\l"
	.string "llaman SALAS de COMBATE DOBLE.\p"
	.string "Los COMBATES DOBLES se libran de la\n"
	.string "forma habitual, salvo una regla\l"
	.string "crucial que debe obedecerse.\p"
	.string "Los ENTRENADORES solo pueden cambiar\n"
	.string "sus POKéMON de entrada y salida.\p"
	.string "Los ENTRENADORES no pueden dar órdenes\n"
	.string "a sus POKéMON de ninguna otra forma.\p"
	.string "Los POKéMON deben actuar según su\n"
	.string "naturaleza y combatir por sí mismos.\p"
	.string "Debes confiar en tus POKéMON y\n"
	.string "observarlos.\p"
	.string "Si logras el honor de vencer a siete\n"
	.string "ENTRENADORES seguidos, te entregaremos\l"
	.string "Puntos de Batalla.\p"
	.string "Si quieres interrumpir tu desafío,\n"
	.string "por favor guarda la partida.\p"
	.string "Si no guardas antes de interrumpir,\n"
	.string "serás descalificado/a.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "Para derrotar al AMA del PALACIO\n"
	.string "y a siete ENTRENADORES seguidos…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "En honor al vínculo que compartes con\n"
	.string "tus POKéMON, te entregamos estos\l"
	.string "Punto(s) de Batalla.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "¿Te gustaría grabar tu último combate\n"
	.string "del PALACIO de BATALLA en tu PASE del\l"
	.string "FRENTE de BATALLA?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "Se muestran las reglas de la SALA de\n"
	.string "COMBATE.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "¿Qué apartado quieres leer?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "Aquí, los POKéMON deben pensar y\n"
	.string "combatir por sí mismos.\p"
	.string "A diferencia de lo que ocurre en la\n"
	.string "naturaleza, los POKéMON que viven con\l"
	.string "los humanos se comportan de forma\l"
	.string "diferente según su naturaleza.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "Según su naturaleza, un POKéMON puede\n"
	.string "preferir atacar sin importar qué.\p"
	.string "Otro POKéMON puede preferir protegerse\n"
	.string "de cualquier daño.\p"
	.string "Y otro más puede disfrutar confundiendo\n"
	.string "o molestando a sus rivales.\p"
	.string "Debido a su naturaleza, un POKéMON\n"
	.string "tendrá movimientos favoritos con los\l"
	.string "que se siente cómodo.\p"
	.string "También puede desagradarle ciertos\n"
	.string "movimientos con los que tiene dificultades.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "Hay movimientos ofensivos que infligen\n"
	.string "daño directo al rival.\p"
	.string "Hay movimientos defensivos que sirven\n"
	.string "para prepararse ante ataques enemigos o\l"
	.string "para curar PS, entre otras cosas.\p"
	.string "También hay otros movimientos algo\n"
	.string "extraños que pueden debilitar a los\l"
	.string "rivales con problemas de estado como\l"
	.string "el envenenamiento o la parálisis.\p"
	.string "Los POKéMON considerarán usar movimientos\n"
	.string "de estas tres categorías.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "Cuando no están bajo las órdenes de su\n"
	.string "ENTRENADOR, los POKéMON pueden no ser\l"
	.string "capaces de usar ciertos movimientos\l"
	.string "eficazmente.\p"
	.string "Un POKéMON no se siente cómodo usando\n"
	.string "ningún movimiento que le desagrade.\p"
	.string "Si un POKéMON solo conoce movimientos\n"
	.string "que no encajan con su naturaleza, a\l"
	.string "menudo no podrá dar lo mejor de sí.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "Según su naturaleza, un POKéMON puede\n"
	.string "empezar a usar movimientos que no\l"
	.string "encajan con su naturaleza cuando está\l"
	.string "en apuros.\p"
	.string "Si un POKéMON empieza a comportarse de\n"
	.string "forma extraña en un aprieto, obsérvalo\l"
	.string "con atención.$"

