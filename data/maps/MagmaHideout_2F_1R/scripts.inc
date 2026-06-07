MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "¿Qué, qué, qué?\p"
	.string "¡Solo los miembros del Equipo Magma\n"
	.string "deberían estar aquí!\p"
	.string "Pero no llevas el uniforme del\n"
	.string "Equipo Magma…\p"
	.string "¡Me resultas sospechoso!\n"
	.string "¡Lucha conmigo!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Mi orgullo como miembro del Equipo Magma…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Si sufres de escalofríos, deberías\n"
	.string "unirte al Equipo Magma.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "¡Alto ahí!\p"
	.string "¿De verdad esperas que me quede callado\n"
	.string "y te deje pasar sin más?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "¡Ooh, guau!\n"
	.string "¡Me rindo!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Quizá habría sido mejor si te hubiera\n"
	.string "dejado pasar sin desafiarte…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "¡Ajá!\n"
	.string "¡Un intruso!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "¡Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ya he perdido.\p"
	.string "¿De verdad necesito seguir corriendo\n"
	.string "en círculos?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "¡Oh, oh!\n"
	.string "¡Un intruso!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Murmur…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "En realidad, no soy ningún experto\n"
	.string "en los combates…$"

