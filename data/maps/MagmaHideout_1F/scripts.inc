MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Cuando el Equipo Magma hace lista, nos\n"
	.string "asignan puestos de guardia importantes\l"
	.string "en el orden en que nos alineamos.\p"
	.string "Por eso estoy atrapado en esta esquina.\n"
	.string "¡Siempre llego tarde a la lista!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "¡También llego siempre tarde a los\n"
	.string "entrenamientos!\p"
	.string "Odio decirlo, pero soy un inútil…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Vale, intentaré esforzarme un poco más\n"
	.string "a partir de ahora…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Nuestro líder nos dijo que caváramos en\n"
	.string "el Monte Cenizo, así que cavamos y cavamos.\p"
	.string "Y en el proceso de cavar, nos encontramos\n"
	.string "con algo que nos voló la cabeza.\p"
	.string "¿Qué encontramos?\p"
	.string "¡Fuhahaha!\n"
	.string "¡Te lo diré si me ganas!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "¡Arrgh!\n"
	.string "¡Derrotado!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Al final no te lo diré.\n"
	.string "¡Lo descubrirás cuando llegues allí!\p"
	.string "Es mejor que guardes las sorpresas\n"
	.string "para el final, ¿no crees?$"

