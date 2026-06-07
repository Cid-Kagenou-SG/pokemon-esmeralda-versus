BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, LOCALID_NONE, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Este es un mensaje de muestra.$"

gText_BattlePyramidConfirmRest::
	.string "Tu búsqueda en la PIRÁMIDE BATALLA\n"
	.string "se guardará para que puedas descansar\l"
	.string "ahora. ¿Estás de acuerdo?$"

gText_BattlePyramidConfirmRetire::
	.string "¿Seguro/a que quieres abandonar tu\n"
	.string "búsqueda en la PIRÁMIDE?$"

BattlePyramid_Text_ExitHintUp1::
	.string "La salida de esta planta está en\n"
	.string "esa dirección: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "La salida de esta planta está en\n"
	.string "esa dirección: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "La salida de esta planta está en\n"
	.string "esa dirección: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "La salida de esta planta está en\n"
	.string "esa dirección: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "La salida de esta planta está en\n"
	.string "dirección {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "La salida de esta planta está en\n"
	.string "dirección {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "La salida de esta planta está en\n"
	.string "dirección {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "La salida de esta planta está en\n"
	.string "dirección {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "La salida está por\n"
	.string "allí, hacia {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "La salida está por\n"
	.string "allí, hacia {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "La salida está por\n"
	.string "allí, hacia {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "La salida está por\n"
	.string "allí, hacia {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "En esta planta, la salida está en\n"
	.string "algún lugar en dirección {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "En esta planta, la salida está en\n"
	.string "algún lugar en dirección {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "En esta planta, la salida está en\n"
	.string "algún lugar en dirección {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "En esta planta, la salida está en\n"
	.string "algún lugar en dirección {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "¿La salida?\n"
	.string "Está hacia {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "¿La salida?\n"
	.string "Está hacia {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "¿La salida?\n"
	.string "Está hacia {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "¿La salida?\n"
	.string "Está hacia {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "La salida resulta estar en\n"
	.string "dirección {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "La salida resulta estar en\n"
	.string "dirección {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "La salida resulta estar en\n"
	.string "dirección {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "La salida resulta estar en\n"
	.string "dirección {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan ocho objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan siete objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan seis objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan cinco objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan cuatro objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan tres objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Quedan dos objetos por\n"
	.string "encontrar.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "¿Buscas objetos?\p"
	.string "Queda un objeto por\n"
	.string "encontrar.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "¿Buscas objetos?\p"
	.string "¡No queda nada por\n"
	.string "encontrar!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Hay ocho objetos\n"
	.string "escondidos por aquí.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Quedan siete objetos\n"
	.string "escondidos por aquí.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Quedan seis objetos\n"
	.string "escondidos por aquí.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Quedan cinco objetos\n"
	.string "escondidos por aquí.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Quedan cuatro objetos\n"
	.string "escondidos por aquí.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Quedan tres objetos\n"
	.string "escondidos por aquí.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Quedan dos objetos\n"
	.string "escondidos por aquí.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "Solo queda un objeto\n"
	.string "escondido por aquí.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Como has ganado, te diré\n"
	.string "un pequeño secreto.\p"
	.string "No queda ningún objeto\n"
	.string "escondido por aquí.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que quedan ocho objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que quedan siete objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que quedan seis objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que quedan cinco objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que quedan cuatro objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que quedan tres objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que quedan dos objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que solo queda un objeto\n"
	.string "esperando ser encontrado en esta\l"
	.string "planta.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "¿Cómo va tu reserva de objetos?\p"
	.string "Creo que no quedan más objetos\n"
	.string "esperando ser encontrados en esta\l"
	.string "planta. ¡Cuídate!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que hay ocho objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que hay siete objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que hay seis objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que hay cinco objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que hay cuatro objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que hay tres objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que hay dos objetos más\n"
	.string "en el suelo.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que solo queda un objeto más\n"
	.string "en el suelo.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Eres fuerte, así que te has ganado\n"
	.string "una pista.\p"
	.string "Parece que no quedan más\n"
	.string "objetos en el suelo.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay ocho objetos…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay siete objetos…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay seis objetos…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay cinco objetos…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay cuatro objetos…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay tres objetos…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay dos objetos…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que hay un objeto…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "En esta planta de la PIRÁMIDE,\n"
	.string "he oído que no hay objetos…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan ocho objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan siete objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan seis objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan cinco objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan cuatro objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan tres objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que quedan dos objetos más\n"
	.string "en esta planta.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que queda un objeto más\n"
	.string "en esta planta.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "¿Has recogido algún objeto?\p"
	.string "Creo que no quedan más objetos\n"
	.string "en esta planta.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡Pero todavía quedan siete ENTRENADORES\n"
	.string "duros además de mí!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡Pero todavía quedan seis ENTRENADORES\n"
	.string "duros además de mí!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡Pero todavía quedan cinco ENTRENADORES\n"
	.string "duros además de mí!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡Pero todavía quedan cuatro ENTRENADORES\n"
	.string "duros además de mí!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡Pero todavía quedan tres ENTRENADORES\n"
	.string "duros además de mí!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡Pero todavía quedan dos ENTRENADORES\n"
	.string "duros además de mí!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡Pero todavía queda un ENTRENADOR\n"
	.string "duro además de mí!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "¡Eras realmente impresionante!\p"
	.string "¡No queda nadie que pueda\n"
	.string "derrotarte!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero quedan siete ENTRENADORES!\n"
	.string "¡Alguien te hará morder el polvo!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero quedan seis ENTRENADORES!\n"
	.string "¡Alguien te hará morder el polvo!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero quedan cinco ENTRENADORES!\n"
	.string "¡Alguien te hará morder el polvo!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero quedan cuatro ENTRENADORES!\n"
	.string "¡Alguien te hará morder el polvo!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero quedan tres ENTRENADORES!\n"
	.string "¡Alguien te hará morder el polvo!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero quedan dos ENTRENADORES!\n"
	.string "¡Alguien te hará morder el polvo!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero queda un ENTRENADOR!\n"
	.string "¡Estoy seguro/a de que te hará morder\l"
	.string "el polvo!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "¡Esto es tan decepcionante!\p"
	.string "¡Pero no quedan más ENTRENADORES\n"
	.string "que puedan enfrentarse a ti!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "¡Pero quedan siete ENTRENADORES más\n"
	.string "en esta planta. ¿Podrás vencerlos a\l"
	.string "todos?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "¡Pero quedan seis ENTRENADORES más\n"
	.string "en esta planta. ¿Podrás vencerlos a\l"
	.string "todos?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "¡Pero quedan cinco ENTRENADORES más\n"
	.string "en esta planta. ¿Podrás vencerlos a\l"
	.string "todos?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "¡Pero quedan cuatro ENTRENADORES más\n"
	.string "en esta planta. ¿Podrás vencerlos a\l"
	.string "todos?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "¡Pero quedan tres ENTRENADORES más\n"
	.string "en esta planta. ¿Podrás vencerlos a\l"
	.string "todos?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "¡Pero quedan dos ENTRENADORES más\n"
	.string "en esta planta. ¿Podrás vencerlos a\l"
	.string "ambos?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "¡Pero todavía queda un ENTRENADOR más\n"
	.string "en esta planta. ¿Podrás prevalecer?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "¡Eso es bastante impresionante!\p"
	.string "Has superado a todos los ENTRENADORES\n"
	.string "de esta planta.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Quizás podrías barrer con los siete\n"
	.string "ENTRENADORES que quedan en esta\l"
	.string "planta.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Quizás podrías barrer con los seis\n"
	.string "ENTRENADORES que quedan en esta\l"
	.string "planta.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Quizás podrías barrer con los cinco\n"
	.string "ENTRENADORES que quedan en esta\l"
	.string "planta.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Quizás podrías barrer con los cuatro\n"
	.string "ENTRENADORES que quedan en esta\l"
	.string "planta.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Quizás podrías barrer con los tres\n"
	.string "ENTRENADORES que quedan en esta\l"
	.string "planta.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Quizás podrías barrer con los dos\n"
	.string "ENTRENADORES que quedan en esta\l"
	.string "planta.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Quizás podrías completar tu barrido\n"
	.string "con el único ENTRENADOR que queda en\l"
	.string "esta planta.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "No queda ni una sola persona que\n"
	.string "pueda derrotarte ahora…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Puede que tengas lo que hace falta para\n"
	.string "vencer a los siete ENTRENADORES\l"
	.string "expertos que quedan.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Puede que tengas lo que hace falta para\n"
	.string "vencer a los seis ENTRENADORES\l"
	.string "expertos que quedan.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Puede que tengas lo que hace falta para\n"
	.string "vencer a los cinco ENTRENADORES\l"
	.string "expertos que quedan.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Puede que tengas lo que hace falta para\n"
	.string "vencer a los cuatro ENTRENADORES\l"
	.string "expertos que quedan.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Puede que tengas lo que hace falta para\n"
	.string "vencer a los tres ENTRENADORES\l"
	.string "expertos que quedan.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Puede que tengas lo que hace falta para\n"
	.string "vencer a los dos ENTRENADORES\l"
	.string "expertos que quedan.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Puede que tengas lo que hace falta para\n"
	.string "vencer al único ENTRENADOR experto que\l"
	.string "queda.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Tus habilidades son incuestionables.\p"
	.string "No quedan más ENTRENADORES aquí\n"
	.string "que tengan alguna posibilidad de\l"
	.string "vencerte.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "¿Podrás seguir ganando contra los\n"
	.string "siete ENTRENADORES que quedan?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "¿Podrás seguir ganando contra los\n"
	.string "seis ENTRENADORES que quedan?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "¿Podrás seguir ganando contra los\n"
	.string "cinco ENTRENADORES que quedan?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "¿Podrás seguir ganando contra los\n"
	.string "cuatro ENTRENADORES que quedan?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "¿Podrás seguir ganando contra los\n"
	.string "tres ENTRENADORES que quedan?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "¿Podrás seguir ganando contra los\n"
	.string "dos ENTRENADORES que quedan?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "¿Podrás seguir ganando contra el\n"
	.string "último ENTRENADOR que queda?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "No quedan ENTRENADORES que puedan\n"
	.string "enfrentarse a ti ahora…$"
