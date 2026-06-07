TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Esta es la COLINA ENTRENADORES donde\n"
	.string "puedes disfrutar de combates en equipo\l"
	.string "con muchos ENTRENADORES.\p"
	.string "Lamentablemente, todavía estamos\n"
	.string "preparando las cosas. ¡Por favor,\l"
	.string "vuelve más tarde!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "¡Bienvenido!\p"
	.string "Esta es la COLINA ENTRENADORES donde\n"
	.string "puedes disfrutar de combates en equipo\l"
	.string "con muchos ENTRENADORES.$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "¿Es esta tu primera visita aquí?\p"
	.string "Antes de entrar, por favor guarda\n"
	.string "tu partida.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Veamos…\n"
	.string "Los ENTRENADORES que hay aquí ahora\l"
	.string "son…\p"
	.string "Hasta la planta n.º {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Veamos…\n"
	.string "Los ENTRENADORES que hay aquí ahora\l"
	.string "son…\p"
	.string "Parece que hay ENTRENADORES reunidos\n"
	.string "en cada habitación.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "¿Te gustaría desafiar a los\n"
	.string "ENTRENADORES que te esperan?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Registraré tu tiempo.\n"
	.string "¡Mucha suerte!\p"
	.string "¡A sus marcas…\p"
	.string "Listos…\p"
	.string "Ya!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "¡Por favor, vuelve a visitarnos!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Ha sido una pena.\p"
	.string "Creo que has hecho un esfuerzo\n"
	.string "tremendo en tus combates.\p"
	.string "¡Por favor, vuelve e inténtalo\n"
	.string "de nuevo!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Espero que des lo mejor de ti.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Cuando los ENTRENADORES cambian de\n"
	.string "sitio, el movimiento puede ser caótico.\p"
	.string "Para evitar el tumulto, hemos movido\n"
	.string "el mostrador de recepción aquí.\p"
	.string "Disculpa las molestias.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "¡Gracias por jugar!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Aquí en la COLINA ENTRENADORES,\n"
	.string "realizamos un evento llamado\l"
	.string "Contrarreloj.\p"
	.string "Es una carrera que mide cuánto tardas\n"
	.string "en llegar a nuestro dueño en la azotea\l"
	.string "desde este mostrador.\p"
	.string "Los mejores tiempos se publican en el\n"
	.string "Panel de Tiempos. Intenta competir con\l"
	.string "tus amigos.\p"
	.string "En los combates de ENTRENADORES del\n"
	.string "camino, no se otorgarán Puntos de\l"
	.string "Experiencia ni dinero.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, lo siento, pero parece que solo\n"
	.string "llevas un POKéMON contigo.\p"
	.string "Necesitarás al menos dos POKéMON\n"
	.string "para participar en este evento.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "¡Hum! ¡Hum!\p"
	.string "¡Por fin has venido!\n"
	.string "¡Sí, has llegado!\p"
	.string "¡Espera! ¡No lo digas!\n"
	.string "Sé por qué has venido hasta aquí\l"
	.string "solo.\p"
	.string "¡Querías verme a mí, el dueño de la\n"
	.string "COLINA ENTRENADORES, porque…\p"
	.string "¡Quieres formar un equipo conmigo!\n"
	.string "¡Uhuuu!\p"
	.string "…¿Eh?\n"
	.string "¿Eso no es?\p"
	.string "De todos modos, te he observado en tu\n"
	.string "camino hacia arriba. ¡Maravillosos\l"
	.string "combates! ¡Bravo, de verdad!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Para alguien tan maravilloso como tú,\n"
	.string "¡tengo el regalo más maravilloso!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh, no, ¡la MOCHILA está llena!\n"
	.string "¡Vuelve más tarde a por esto!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, ¡espera un momento! ¿Has llegado\n"
	.string "aquí maravillosamente rápido?\p"
	.string "¡Qué espléndido! ¡No tenías que darte\n"
	.string "tanta prisa por verme!\p"
	.string "¡Eso me encanta! Haré que actualicen\n"
	.string "el Panel de Tiempos en la recepción.$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Pero, oh…\n"
	.string "No has llegado muy rápido.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Quizás me complacería más si llegaras\n"
	.string "con más rapidez la próxima vez.\p"
	.string "Entonces, ¡me complacería formar un\n"
	.string "equipo contigo!\p"
	.string "¡Hasta que nos volvamos a encontrar,\n"
	.string "amigo!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "¡Hice construir la COLINA ENTRENADORES\n"
	.string "por una sola razón y solo una!\p"
	.string "¡Encontrar al compañero más adecuado\n"
	.string "con quien formar un equipo!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} seg.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "¿Quién sabe qué tipo de ENTRENADORES\n"
	.string "y combinaciones de POKéMON hay\l"
	.string "adelante?\p"
	.string "Lo único que sé es que apartaré a\n"
	.string "cualquiera que se interponga en mi\l"
	.string "camino.$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "He oído que ENTRENADORES duros de\n"
	.string "pelar vienen a esta COLINA\l"
	.string "ENTRENADORES de todas partes.\p"
	.string "¡Estoy deseando probar mis fuerzas!\p"
	.string "¡Apartaré a cualquiera que se interponga\n"
	.string "en mi camino!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "¿Ves el Panel de Tiempos de allí?\p"
	.string "Mis amigos y yo estamos intentando ver\n"
	.string "quién puede llegar arriba en el menor\l"
	.string "tiempo.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "¿Sabes cuándo van a abrir este lugar?\p"
	.string "Estoy esperando aquí para ser el\n"
	.string "primer desafiante de la historia.$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "¿Te gustaría volver al mostrador de\n"
	.string "recepción?$"
