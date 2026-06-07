MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Yo también quiero ver a GROUDON, pero\n"
	.string "ni siquiera me dejan verle la cola…\p"
	.string "Me tiene muy frustrado.\p"
	.string "¡Oh, no!\n"
	.string "¡He soltado lo de GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Supongo que es imposible ganar si no\n"
	.string "tienes la mente tranquila…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Me pregunto si GROUDON tendrá cola.$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "¡Fuhahaha!\n"
	.string "¡Pronto! ¡Muy pronto!\l"
	.string "¡Nuestro gran objetivo se cumplirá!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "¿He llegado tan lejos para esto?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "¡Señor MAGNO!\n"
	.string "¡Un intruso se dirige hacia usted!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "¡Aún no has terminado!\n"
	.string "¡No pasarás por mí tan fácilmente!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "¿He sido tan fácil de derribar?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "V-vamos, un combate más…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "¡Jejeje!\n"
	.string "Has llegado hasta aquí, así que te lo\l"
	.string "diré.\p"
	.string "¡Así es!\n"
	.string "¡Más adelante, GROUDON está durmiendo!\p"
	.string "¡MAGNO fue a ver a GROUDON hace\n"
	.string "unos segundos!\p"
	.string "¡Va a despertar muy pronto!\n"
	.string "¡Je! ¡Jejeje!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Derrotado otra vez…\n"
	.string "Jeje…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Y mientras perdiste el tiempo conmigo,\n"
	.string "MAGNO debería haber despertado a\l"
	.string "GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAGNO: GROUDON…\p"
	.string "Nada podía despertarte de tu sueño\n"
	.string "bañado en magma…\p"
	.string "Esta ESFERA AZUL es lo que buscabas.\n"
	.string "¿No es así?\p"
	.string "Te he traído la ESFERA AZUL.\n"
	.string "¡Deja que su brillo te despierte!\p"
	.string "Y muéstrame…\n"
	.string "¡Muéstrame toda la extensión de tu\l"
	.string "poder!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAGNO: ¡GROUDON!\n"
	.string "¿Qué ocurre?\p"
	.string "¿No era la ESFERA AZUL la clave?\p"
	.string "¡GROUDON!\n"
	.string "¿Dónde has ido…?$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAGNO: Oh, ¿así que eras tú?\p"
	.string "Te he visto husmeando por aquí y por\n"
	.string "allá sin ser invitado…\p"
	.string "¡Ahora lo entiendo!\n"
	.string "¡Debes haber hecho algún truco sucio!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "¿Qué te hace tan hábil manejando\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAGNO: Tiene que haber alguna razón\n"
	.string "por la que GROUDON huyó…\p"
	.string "Eso es lo que estás intentando decir,\n"
	.string "¿no es así?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "¿Crees que no lo sabía?\p"
	.string "Con GROUDON fuera, ya no hay necesidad\n"
	.string "de este maldito volcán.\p"
	.string "Voy tras GROUDON, así que aquí nos\n"
	.string "despedimos.$"
