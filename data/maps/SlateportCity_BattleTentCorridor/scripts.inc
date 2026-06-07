SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "¿Quieres un sabroso consejito para\n"
	.string "los CONCURSOS?\p"
	.string "Usar cierto movimiento después de otro\n"
	.string "cierto tipo de movimiento a veces llama\l"
	.string "más la atención.\p"
	.string "Si sabes lo que haces, puedes\n"
	.string "conseguir muchos puntos de exibición.\p"
	.string "Por supuesto, tus rivales pueden intentar\n"
	.string "perturbar la actuación de tu POKéMON.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Mi papá es JUEZ de CONCURSO.\p"
	.string "Me pregunto qué debería ser cuando sea\n"
	.string "mayor, ¿JUEZ o LÍDER DE GIMNASIO?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Oye, tío, estoy como supercabreado,\n"
	.string "ya sabes. Como, ya sabes, solo quería\l"
	.string "saber por qué mi POKéMON nunca ganaba,\l"
	.string "ya sabes, como, ¿oye?\p"
	.string "Así que, como, le di mi opinión al JUEZ,\n"
	.string "ya sabes, es gratis.\p"
	.string "¡Y no me quiso escuchar, como, oye!\n"
	.string "¡Así que, como, qué palo, tío!\p"
	.string "¡Oye, como, tú! ¡Cierra el pico, vale?\n"
	.string "Simplemente, ya sabes, ¡toma esto!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Eso es, como, la MT41, ¿sabes?\n"
	.string "Oye, es TORMENTO, ¿me oyes?\p"
	.string "Como, no deja que el otro tipo use\n"
	.string "el mismo movimiento dos veces seguidas,\l"
	.string "¿entiendes?\p"
	.string "Oye, ahora, escúchame bien, como,\n"
	.string "¡no te estoy poniendo un tormento!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "PRESENTADOR: ¡Oh, cielos!\n"
	.string "¡Pero si es un POKéMON estupendo!\p"
	.string "¡Por favor! ¡Acérquese y participe\n"
	.string "en nuestros magníficos CONCURSOS!\p"
	.string "¡Lo hará bien! ¡Estoy seguro!\n"
	.string "¡Mis ojos nunca me fallan!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JUEZ: ¡Bueno, hola!\n"
	.string "¡Veo que eres un ENTRENADOR!\p"
	.string "Entonces, no estaría bien que te\n"
	.string "perdieras un CONCURSO POKéMON.\p"
	.string "¡Consigue un PASE de CONCURSO en\n"
	.string "PUEBLO VERDEGAL y entra cuando quieras!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "¡Es hora de la exibición!\n"
	.string "¿Con qué debería empezar?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "No prestaron mucha atención a la\n"
	.string "exibición de mi POKéMON…\p"
	.string "Hum, ese JUEZ, no sabe reconocer\n"
	.string "algo bueno cuando lo ve.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "¡Oh, hola! Debes ser un fan serio para\n"
	.string "acercarte tanto a la acción.\p"
	.string "Te recompensaré tu entusiasmo con\n"
	.string "este sabio consejo.\p"
	.string "Si un movimiento funciona muy bien,\n"
	.string "el público se emocionará.\p"
	.string "El POKéMON que haga su exibición\n"
	.string "justo cuando todo el mundo esté\l"
	.string "emocionado…\p"
	.string "Bueno, ¡seguro que algo bueno tiene\n"
	.string "que pasar!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "¡No puedo hacer esto! Estoy más\n"
	.string "nervioso que mi POKéMON.\p"
	.string "¡Estoy temblando y me late el corazón\n"
	.string "a mil por hora!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Un combate y un CONCURSO no son lo\n"
	.string "mismo, pero se parecen.\p"
	.string "Necesitas esforzarte y creer en el\n"
	.string "POKéMON que has criado.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Ese POKéMON parece estar en plena\n"
	.string "forma, ¿eh?\p"
	.string "Un POKéMON que lo hace bien en la\n"
	.string "evaluación secundaria parece estar\l"
	.string "más relajado cuando hace exibiciones.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "¿Puedes mirar esa triste escena?\p"
	.string "¡Je, mi POKéMON es absolutamente mejor\n"
	.string "que ese montón!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "¿No sientes el impulso de moverte con\n"
	.string "los POKéMON cuando hacen una exibición\l"
	.string "llena de energía?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "CONCURSOS POKéMON\n"
	.string "¡ESCENARIO RANGO HÍPER!$"

