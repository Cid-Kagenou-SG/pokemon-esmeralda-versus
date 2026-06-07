Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} escribió el código secreto\n"
	.string "en la puerta.\p"
	.string "“MAESTRO TRETA es fabuloso.”\n"
	.string "… … … … … … … …\p"
	.string "¡La cerradura se ha abierto!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "¡Voy a abrirme paso a la victoria con\n"
	.string "el CORTE que acabamos de aprender!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "¿Por qué te lo tomas tan en serio?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "¡Nunca me canso de cortar y cortar!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Entré en esta casa rara por\n"
	.string "accidente…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Y ahora he perdido…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Me he perdido, he perdido un combate y\n"
	.string "ahora estoy todavía más perdido… No puedo\n"
	.string "salir…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "¿Quién es el MAESTRO TRETA?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "¡He perdido mientras estaba perdido en\n"
	.string "mis pensamientos!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "¡Eres fuerte!\n"
	.string "¿Quién eres tú?$"

