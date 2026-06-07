AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Je, je, je…\p"
	.string "¿Ya has llegado hasta aquí?\n"
	.string "¡Te hemos subestimado!\p"
	.string "¡Pero esto se acaba!\p"
	.string "Soy de una categoría superior a los SOLDADOS\n"
	.string "a los que te has enfrentado hasta ahora.\p"
	.string "No voy a perder el tiempo.\n"
	.string "¡Voy a pulverizarte!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Je, je, je…\n"
	.string "Así que yo también he perdido…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "¡Je, je, je!\p"
	.string "¡Mientras te entretenía, nuestro JEFE\n"
	.string "ha terminado sus preparativos!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "¡Je, je, je!\p"
	.string "¡Nuestro JEFE ya ha partido hacia una\n"
	.string "cueva en el fondo del mar!\p"
	.string "¡Si vas a ir tras él, será mejor que\n"
	.string "busques en el inmenso mar que hay más allá\l"
	.string "de CALAGUA!\p"
	.string "¿Pero lo encontrarás?\n"
	.string "¡Je, je, je!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "¡Ja, ja, ja! ¡Me cansé de esperar!\n"
	.string "¡Tú me debes un combate!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Cansado de esperar…\n"
	.string "Perdido y aturdido…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "JEFE…\n"
	.string "¿Es esto suficiente?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "¡Los paneles de teletransporte son el\n"
	.string "orgullo del ESCONDITE!\p"
	.string "¡No tienes ni idea de dónde estás,\n"
	.string "verdad?\p"
	.string "¡Confundir y agotar al enemigo, para luego\n"
	.string "darle el golpe de gracia! ¡Ese es nuestro plan!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "¿Qué te pasa?\n"
	.string "¡No pareces cansado en absoluto!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Eso me recuerda… No recuerdo dónde\n"
	.string "dejé la MASTER BALL.\p"
	.string "Si no la vigilo, nuestro JEFE\n"
	.string "me va a regañar…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Cuando me uní al EQUIPO AQUA, lo primero\n"
	.string "que tuve que aprender fue cómo funcionan\l"
	.string "estos paneles de teletransporte.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Estaba demasiado ocupado pensando en\n"
	.string "los paneles de teletransporte…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Tendré que aprender a combatir de\n"
	.string "forma más efectiva…$"
