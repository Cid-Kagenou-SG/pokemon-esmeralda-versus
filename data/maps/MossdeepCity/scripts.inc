MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
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

MossdeepCity_Movement_ScottExitEast:
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

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Me dio esto Mero, pero no sé para qué\n"
	.string "sirve.\p"
	.string "Creo que se llama Roca del Rey.\n"
	.string "¿La quieres?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "¿Por qué la querrías?\n"
	.string "Eres raro.\p"
	.string "Puedes quedártela, pero guárdalo en\n"
	.string "secreto para Mero.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "¡La casa de Mero está justo ahí!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Sí, ¿verdad que sí? ¿Qué se supone que\n"
	.string "debes hacer con una roca rara?$"

MossdeepCity_Text_WailmerWatching:
	.string "Alrededor de Algaria, puedes ver\n"
	.string "Wailmer salvajes.\p"
	.string "Se llama, eh…\n"
	.string "¿Cómo era ahora…?\p"
	.string "¡WAI, WAI, WAI…\p"
	.string "¡Observación de Wailmer!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "El Centro Espacial de la isla ha estado\n"
	.string "lanzando cohetes enormes.\p"
	.string "Ha habido algún tipo de alboroto sobre\n"
	.string "una carta que recibieron recientemente.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "El Centro Espacial de la isla ha estado\n"
	.string "lanzando cohetes enormes.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Escuché de un compañero marinero que el\n"
	.string "Equipo Aqua montó su base en Ciudad\l"
	.string "Calagua.\p"
	.string "También escuché que alguien apareció y\n"
	.string "los barrió del mapa.\p"
	.string "Pero aquí en Algaria, el Equipo Magma\n"
	.string "nos ha tenido en la mira.\p"
	.string "Si quieres saber qué están tramando,\n"
	.string "ve al Centro Espacial.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Soy un marinero, así que el mar es\n"
	.string "obviamente más importante para mí.\p"
	.string "Pero ¿sabes? Cuando vuelvo a tierra\n"
	.string "después de un largo viaje, ¡siento\l"
	.string "alivio!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "¿No sería genial?\p"
	.string "¿Si el mundo entero estuviera cubierto\n"
	.string "de plantas y flores como esta isla?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Toda la vida necesita el mar para vivir,\n"
	.string "aunque haga su hogar en la tierra.\p"
	.string "La vida, tras seguir su curso, se\n"
	.string "convierte en suelo y vuelve a la tierra.\p"
	.string "Y el mar siempre está conectado a la\n"
	.string "tierra.\p"
	.string "Sí, como la misma orilla de aquí.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Un viaje en barco está bien.\p"
	.string "Pero cruzar el mar con Pokémon usando\n"
	.string "Surf…\p"
	.string "¡Eso es un viaje estimulante!\n"
	.string "¿No estás de acuerdo, jovencito?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Esta roca tiene un significado especial\n"
	.string "para la gente del Centro Espacial.\p"
	.string "La pusieron aquí como deseo de que sus\n"
	.string "cohetes vuelen con seguridad.\p"
	.string "Cuando pides un deseo, ¿qué usas?\n"
	.string "¿Deseas sobre una estrella?\p"
	.string "Yo uso una etiqueta de deseo para\n"
	.string "hacerlo realidad.\n"
	.string "Eso es lo que hago.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "Es una roca blanca.$"

MossdeepCity_Text_GymSign:
	.string "Gimnasio Pokémon de Ciudad Algaria\n"
	.string "Líderes: Leti y Vito\p"
	.string "“¡La combinación mística!”$"

MossdeepCity_Text_CitySign:
	.string "Ciudad Algaria\n"
	.string "“Nuestro lema: ¡Querer a los Pokémon!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "Centro Espacial de Algaria\n"
	.string "“El lugar más cercano al espacio.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "TRETO: {PLAYER}{KUN}, ¿te sientes bien?\n"
	.string "¡Yo estoy genial!\p"
	.string "Había oído que el líder de gimnasio de\n"
	.string "Algaria era bastante fuerte, así que\l"
	.string "decidí venir a echar un vistazo.\p"
	.string "Pero hay algo raro en esta ciudad.\p"
	.string "La gente habla de una carta de advertencia\n"
	.string "y del Centro Espacial…\p"
	.string "Aunque no creo que me concierna en\n"
	.string "absoluto.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… Se siente genial dejar que las\n"
	.string "olas laven mis pies…\p"
	.string "Hablando de olas, ¿sabes esa ciudad\n"
	.string "isla Ciudad Colosalia?\p"
	.string "Creo que el gimnasio de allí tuvo un\n"
	.string "nuevo líder.\p"
	.string "La gente me dice que el nuevo líder\n"
	.string "fue una vez mentor de Plubio.$"

