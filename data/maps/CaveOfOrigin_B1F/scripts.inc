CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, así que eres {PLAYER}{KUN}?\n"
	.string "He oído hablar de tus hazañas.\p"
	.string "Me llamo Plubio.\p"
	.string "Una vez fui el líder del Gimnasio de\n"
	.string "Arrecípolis, pero surgió algo.\p"
	.string "Así que ahora, he confiado la\n"
	.string "gestión del Gimnasio a mi mentor Juan.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Groudon y Kyogre, los dos Pokémon que\n"
	.string "están causando estragos aquí, se\l"
	.string "consideran Pokémon superancestrales.\p"
	.string "Pero no hay solo dos Pokémon\n"
	.string "superancestrales.\p"
	.string "Hay uno más en algún lugar.\p"
	.string "En algún lugar, hay un Pokémon\n"
	.string "superancestral llamado Rayquaza.\p"
	.string "Se dice que fue Rayquaza quien calmó a\n"
	.string "los dos combatientes en el pasado\l"
	.string "remoto.\p"
	.string "Pero incluso yo no tengo ni idea de\n"
	.string "dónde podría estar Rayquaza…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "PLUBIO: {PLAYER}{KUN}, ¿acaso sabes\n"
	.string "dónde está Rayquaza ahora?\p"
	.string "Si lo sabes, por favor, dímelo.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "PLUBIO: ¿La Cueva Ancestral?\p"
	.string "¡Pero eso está aquí mismo!\n"
	.string "¡Necesito que lo hagas mejor que eso!\p"
	.string "Por favor, necesito que pienses en\n"
	.string "dónde podría estar Rayquaza ahora.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "PLUBIO: ¿El Monte Pírico?\p"
	.string "Pero cuando me encontré con la anciana\n"
	.string "allí antes, no mencionó nada de eso.\p"
	.string "Dudo mucho que la anciana intentara\n"
	.string "ocultarme algo…\p"
	.string "{PLAYER}{KUN}, ¿podrías pensar en esto\n"
	.string "con más cuidado por mí?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "PLUBIO: ¿Eh? ¿No lo recuerdas?\n"
	.string "Mmm… Eso es un problema…\p"
	.string "¿No puedes recordarlo de alguna manera?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "PLUBIO: ¿El Pilar Celeste?\p"
	.string "¡Eso es!\n"
	.string "¡Debe ser el Pilar Celeste!\p"
	.string "{PLAYER}{KUN}, ¡no hay un momento que\n"
	.string "perder! ¡Nos dirigiremos al Pilar\l"
	.string "Celeste de inmediato!$"

