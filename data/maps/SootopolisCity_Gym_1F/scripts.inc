SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "¡Eh! ¿Qué tal, {PLAYER}, camino del\n"
	.string "CAMPEONATO?\p"
	.string "El LÍDER DE GIMNASIO JUAN de\n"
	.string "ARRECÍPOLIS es un experto en POKéMON\l"
	.string "de tipo AGUA.\p"
	.string "Y, para llegar hasta JUAN, un suelo\n"
	.string "helado dificultará tu avance…\p"
	.string "Escucha, lo siento, pero eso es todo\n"
	.string "el consejo que tengo para ti.\p"
	.string "¡El resto del camino debes recorrerlo\n"
	.string "por tu cuenta!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "¡Vaya! ¡Has vencido incluso a JUAN,\n"
	.string "que se suponía que era el mejor de\l"
	.string "todo HOENN!\p"
	.string "¡Vale! Mira tu FICHA de ENTRENADOR.\p"
	.string "Si has conseguido todas las MEDALLAS,\n"
	.string "¡estás listo para el desafío de la\l"
	.string "LIGA POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Déjame preguntarte.\n"
	.string "¿Lo sabías?\l"
	.string "Ah, no debería ser tan reservado.\p"
	.string "Fui yo quien enseñó a PLUBIO todo lo\n"
	.string "que hay que saber sobre los POKéMON.\p"
	.string "En otro tiempo, había renunciado a mi\n"
	.string "puesto como LÍDER DE GIMNASIO.\p"
	.string "En mi lugar, había confiado el GIMNASIO\n"
	.string "a PLUBIO.\p"
	.string "Sin embargo, surgió una razón imperiosa\n"
	.string "para que volviera.\p"
	.string "Ah, pero basta de charla.\n"
	.string "Comencemos nuestro combate, ¿te parece?\p"
	.string "Por favor, serás testigo de nuestro\n"
	.string "arte.\p"
	.string "¡Una gran ilusión de agua esculpida\n"
	.string "por los POKéMON y por mí!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it gets put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "¡Ajajaja, excelente!\n"
	.string "Muy bien, eres el ganador.\p"
	.string "En ti, percibo el brillante resplandor\n"
	.string "de la habilidad que todo lo superará.\p"
	.string "Sin embargo, comparado conmigo o incluso\n"
	.string "con PLUBIO, te falta elegancia.\p"
	.string "Quizás debería prestarte mi atuendo?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "¡Jajaja, solo bromeaba!\p"
	.string "En lugar de mi ropa, te recompensaré\n"
	.string "con esto, ¡la MEDALLA LLUVIA!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} ha recibido la MEDALLA LLUVIA\n"
	.string "de JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Con la MEDALLA LLUVIA asegurarás la\n"
	.string "total obediencia de todos tus POKéMON\l"
	.string "a cada uno de tus comandos.\p"
	.string "La MEDALLA LLUVIA también permite usar\n"
	.string "el movimiento MO CASCADA para escalar\l"
	.string "muros de agua en cascada.\p"
	.string "Y, para que nunca olvides el combate\n"
	.string "que compartimos, toma esto…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La MÁQUINA TÉCNICA que te he entregado\n"
	.string "contiene HIDROPULSO.\p"
	.string "Al usarlo, confundirá ocasionalmente al\n"
	.string "objetivo con ondas ultrasónicas.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Se ha registrado al LÍDER DE GIMNASIO\n"
	.string "JUAN en el POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Los ENTRENADORES que han reunido todas\n"
	.string "las MEDALLAS DE GIMNASIO de HOENN deben\l"
	.string "dirigirse al destino final.\p"
	.string "La LIGA POKéMON.\p"
	.string "Viaja al extremo más oriental de HOENN,\n"
	.string "a la isla GRAN CÍA.\p"
	.string "Allí encontrarás la LIGA POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Solo queda una MEDALLA por obtener en\n"
	.string "HOENN.\p"
	.string "Si deseas desafiar la LIGA POKéMON,\n"
	.string "debes obtener la última MEDALLA del\l"
	.string "GIMNASIO de ARBORIA.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "GIMNASIO POKéMON DE CIUDAD ARRECÍPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD ARRECÍPOLIS\p"
	.string "ENTRENADORES CERTIFICADOS POR JUAN:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, este GIMNASIO había vuelto a\n"
	.string "su estado habitual de serenidad…\p"
	.string "¡Pero nuestro joven tifón ha vuelto\n"
	.string "para ponernos a prueba de nuevo!\p"
	.string "Bueno, amigo mío, ¡por supuesto!\p"
	.string "¡Estaré encantado de bailar contigo\n"
	.string "tantas veces como desees!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "¡Ajajaja, eres el ganador!\n"
	.string "¡Me has derrotado de nuevo!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Si te dijera que te convirtieras\n"
	.string "en mi aprendiz, seguro que te negarías.\p"
	.string "Me gustaría regalarte mi abrigo.\p"
	.string "Pero, de nuevo, te negarías.\n"
	.string "Me imagino que eso sería así.\p"
	.string "¡Y eso, amigo mío, es una señal cierta\n"
	.string "de nobleza!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, este GIMNASIO había vuelto a\n"
	.string "su estado habitual de serenidad…\p"
	.string "¡Pero nuestro joven tifón ha vuelto\n"
	.string "para ponernos a prueba de nuevo!\p"
	.string "Bueno, amigo mío, ¡por supuesto!\n"
	.string "Estaré encantado de bailar contigo…\p"
	.string "Ah, no, no, no.\n"
	.string "Solo llevas un POKéMON contigo.\p"
	.string "Desearía que volvieras con dos, o quizás\n"
	.string "más, POKéMON, por favor.$"

