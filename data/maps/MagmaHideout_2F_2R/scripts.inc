MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "No tengo nada en contra de ti.\n"
	.string "¡Solo sigo órdenes!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "Puede que haya perdido, pero…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "¡Hemos desenterrado algo increíble!\n"
	.string "¡Y conseguimos la ESFERA AZUL!\p"
	.string "Solo falta que nuestro líder…\n"
	.string "Fufufu… ¡Fwajajaja!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "No soporto el calor. Quizá debería\n"
	.string "haberme unido al Equipo Aqua…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Sí, puede que realmente no sea apto\n"
	.string "para el Equipo Magma…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "¿No echas de menos el mar estando en\n"
	.string "un sitio como este?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "A veces se oyen temblores aquí.\p"
	.string "¿Será el volcán retumbando?\n"
	.string "O será GROU…\p"
	.string "¡Ups!\n"
	.string "No, no, ¡olvídalo!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Eres un luchador ardiente.\n"
	.string "¡Como un volcán!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Esta vez has ganado por casualidad,\n"
	.string "pero eso no importa.\p"
	.string "¡El objetivo del Equipo Magma está a\n"
	.string "punto de cumplirse!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Uno de los nuestros se ha vuelto loco\n"
	.string "porque ha perdido su EMBLEMA MAGMA…\p"
	.string "¡Espera un momento!\n"
	.string "¿Fuiste tú quien lo encontró?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "Me cuesta creerlo…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "Tengo la sensación de que nuestro plan\n"
	.string "va a terminar en fracaso…$"

