Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "El JEFE se interesó en la investigación\n"
	.string "que están haciendo aquí, así que nos\l"
	.string "envió.\p"
	.string "¡Deja de entrometerte!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Maldita sea…\n"
	.string "Derrotado por un crío…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Nuestro JEFE lo sabe todo.\p"
	.string "Pero yo solo soy un RECLUTA. ¿Qué voy a\n"
	.string "saber de lo que está pensando?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "¿Eh?\n"
	.string "¿Qué hace un crío aquí?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "¿Eh?\n"
	.string "¡¿He perdido?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, no…\n"
	.string "Me van a echar una bronca por perder\l"
	.string "contra un crío…\p"
	.string "Será mejor que eche una siesta en la\n"
	.string "cama…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "¡Mientras dormía, todos se fueron\n"
	.string "arriba!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "¡Guau, eres muy fuerte!\p"
	.string "¡Ojalá pudiera ser un ENTRENADOR POKéMON\n"
	.string "como tú!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Al PROFESOR le encanta la lluvia.\n"
	.string "Eso es un hecho.\p"
	.string "Pero si sigue lloviendo, la gente tendrá\n"
	.string "problemas. Eso es otro hecho.\p"
	.string "Y por eso, el PROFESOR está estudiando\n"
	.string "si la lluvia puede ponerse a buen uso.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "En la segunda planta del INSTITUTO\n"
	.string "estudiamos los patrones meteorológicos\l"
	.string "de la región de HOENN.\p"
	.string "Últimamente hemos notado casos\n"
	.string "temporales y aislados de sequías y\l"
	.string "lluvias torrenciales…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "¡Hola!\n"
	.string "¡Nos has salvado con tus acciones!\p"
	.string "Lo que no entiendo es qué demonios\n"
	.string "estaban tramando los del AQUA.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Hay una cama…\n"
	.string "Vamos a descansar un poco.$"

