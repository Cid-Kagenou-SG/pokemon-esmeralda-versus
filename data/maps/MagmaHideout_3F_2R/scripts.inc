MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Entiendo todo lo que dice nuestro líder.\n"
	.string "Pero ¿sabes qué?\p"
	.string "Hacer cosas como desenterrar un\n"
	.string "Pokémon superancestral y robarle\l"
	.string "el Meteorito a alguien…\p"
	.string "Creo que nos estamos pasando un poco.\n"
	.string "¿Tú qué opinas?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Sí, creo que estamos haciendo algo\n"
	.string "mal de alguna forma.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Sabes, perder contra ti me ha aclarado\n"
	.string "la mente.\p"
	.string "La próxima vez que vea a nuestro líder,\n"
	.string "le voy a preguntar sobre lo que hacemos.$"

