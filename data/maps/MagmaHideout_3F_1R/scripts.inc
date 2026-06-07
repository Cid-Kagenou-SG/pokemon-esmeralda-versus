MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "¿Qué he hecho yo para merecer este\n"
	.string "puesto de guardia?\p"
	.string "¡Se me está quemando la oreja\n"
	.string "izquierda!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Me está dando un golpe de calor…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "¿No te parece raro que llevemos\n"
	.string "capuchas en este volcán lleno de magma?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Nos unimos para ayudar a nuestro líder\n"
	.string "a cumplir su fantástica visión.\p"
	.string "No me importa si eres del Equipo Aqua\n"
	.string "o si eres solo un crío de paso.\p"
	.string "¡Nadie se interpone en nuestro camino\n"
	.string "y sale impune!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "¡Oh, no!\n"
	.string "¡No eres de fiar en absoluto!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Escúchame.\n"
	.string "¡El Equipo Magma tiene razón!\p"
	.string "No escuches al Equipo Aqua.\n"
	.string "¡No creas sus mentiras!$"

