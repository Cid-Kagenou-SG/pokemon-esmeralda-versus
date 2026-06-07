BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_PIKE_LOBBY_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "Donde la suerte de los ENTRENADORES\n"
	.string "se pone a prueba…\p"
	.string "Bienvenido/a al PIQUE de BATALLA…\p"
	.string "Soy tu guía en el PIQUE de BATALLA…$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "¿Quieres aceptar el desafío de la\n"
	.string "Elección de Batalla?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Aquí realizamos un evento que llamamos\n"
	.string "la Elección de Batalla.\p"
	.string "Las reglas de la Elección de Batalla\n"
	.string "son muy simples…\p"
	.string "Elige uno de los tres caminos y abre\n"
	.string "te paso hasta la sala final al final\l"
	.string "del PIQUE de BATALLA. Eso es todo.\p"
	.string "Sin embargo, lo que ocurra en el camino\n"
	.string "elegido depende enteramente de la\l"
	.string "suerte del desafiante…\p"
	.string "Si llegas a la meta, serás recompensado\n"
	.string "con Puntos de Batalla.\p"
	.string "Si quieres interrumpir tu desafío,\n"
	.string "por favor habla con nuestro personal\l"
	.string "en las salas grandes del camino.\p"
	.string "Si no guardas antes de interrumpir,\n"
	.string "serás descalificado/a.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "Esperamos verte en otra ocasión…$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "Puedes elegir entre dos cursos:\n"
	.string "Nivel 50 y Nivel Libre.\l"
	.string "¿Cuál desafiarás?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "Te pido disculpas, pero…\p"
	.string "No tienes tres POKéMON válidos para\n"
	.string "el evento de Elección de Batalla.\p"
	.string "Debes tener tres POKéMON distintos de\n"
	.string "Nivel 50 o inferior para entrar.\p"
	.string "Además, deben llevar objetos de\n"
	.string "diferentes tipos.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Por favor, ven a verme cuando estés\n"
	.string "preparado/a…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Te pido disculpas, pero…\p"
	.string "No tienes tres POKéMON válidos para\n"
	.string "el evento de Elección de Batalla.\p"
	.string "Debes tener tres POKéMON distintos\n"
	.string "para entrar.\p"
	.string "Además, deben llevar objetos de\n"
	.string "diferentes tipos.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Por favor, ven a verme cuando estés\n"
	.string "preparado/a…$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Por favor, elige los tres POKéMON que\n"
	.string "deseas inscribir en el desafío…$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Antes de comenzar tu desafío de\n"
	.string "Elección de Batalla, debo guardar la\l"
	.string "partida. ¿Es eso aceptable?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Por favor, pasa por aquí…$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "Tu desafío ha terminado…\p"
	.string "Registraré tus resultados.\n"
	.string "Espera, por favor…$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "Has completado el desafío…\p"
	.string "Debo decir… Pareces poseer suerte\n"
	.string "en abundancia…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "Registraré tus resultados.\n"
	.string "Espera, por favor…$"

@ Sin usar
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "Para conmemorar tu finalización del\n"
	.string "desafío de Elección de Batalla, te\l"
	.string "otorgamos estos Punto(s) de Batalla…$"

@ Sin usar
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "Parece que has alcanzado el límite de\n"
	.string "Puntos de Batalla…\p"
	.string "Por favor, canjea algunos Puntos de\n"
	.string "Batalla por premios, y luego vuelve…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "Te pido disculpas, pero…\p"
	.string "No guardaste antes de abandonar tu\n"
	.string "desafío la última vez.\p"
	.string "Debido a ello, tu desafío hasta el\n"
	.string "momento ha sido descalificado. Lo\l"
	.string "siento…$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Enhorabuena…\p"
	.string "Has arrebatado la victoria a la REINA\n"
	.string "del PIQUE y has completado el evento…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "En reconocimiento a tu asombrosa\n"
	.string "suerte, te otorgamos estos Punto(s)\l"
	.string "de Batalla…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "¡Arrgh! ¡He perdido mi oportunidad!\n"
	.string "¡Estaba a una sala de la meta!\p"
	.string "En este lugar, más te vale tener\n"
	.string "cuidado con el veneno, el congelamiento\l"
	.string "y demás.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "He completado el desafío 10 veces\n"
	.string "ya, pero nunca he tenido que combatir\l"
	.string "contra un ENTRENADOR ni una vez.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "¡Escucha! ¡Escucha!\p"
	.string "¿No crees que las habilidades\n"
	.string "especiales de los POKéMON serán útiles\l"
	.string "aquí?$"

@ Sin usar
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "¿Qué es este lugar tan extraño?\n"
	.string "¡No logro entenderlo en absoluto!\p"
	.string "He aceptado el desafío un montón de\n"
	.string "veces, pero solo me encuentro con\l"
	.string "ENTRENADORES sea cual sea el camino que\l"
	.string "elija.$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "Se muestran las reglas de la Elección\n"
	.string "de Batalla.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "¿Qué apartado quieres leer?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "La MOCHILA y el POKéNAV no pueden ser\n"
	.string "usados durante un desafío de Elección\l"
	.string "de Batalla.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "Durante un desafío de Elección de\n"
	.string "Batalla, cualquier BAYA o HIERBA que\l"
	.string "lleve un POKéMON solo será efectiva\l"
	.string "una vez.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "Durante un desafío de Elección de\n"
	.string "Batalla, el orden de los POKéMON no\l"
	.string "puede ser cambiado.\p"
	.string "El orden debe establecerse antes de\n"
	.string "comenzar tu desafío.$"

