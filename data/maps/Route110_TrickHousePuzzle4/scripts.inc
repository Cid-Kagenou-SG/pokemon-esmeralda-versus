Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} escribió el código secreto\n"
	.string "en la puerta.\p"
	.string "“MAESTRO TRETA es guay.”\n"
	.string "… … … … … … … …\p"
	.string "¡La cerradura se ha abierto!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Me da mucha pereza pensar. ¡Solo\n"
	.string "quería luchar!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Aunque haya perdido, ¡sigo prefiriendo\n"
	.string "luchar sobre todas las cosas!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "¿No estás de acuerdo? Irías a cualquier\n"
	.string "sitio con tal de encontrar entrenadores.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "¡Je! Rocas como estas, ¡puedo apartarlas\n"
	.string "con un dedo!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Sé empujar rocas, pero no sé resolver\n"
	.string "el puzzle…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "No basta con ser musculoso… También\n"
	.string "hay que usar la cabeza. ¡Sé listo!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La CASA TRETA se está poniendo más\n"
	.string "complicada, ¿verdad?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "¡Aaay!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "¿Alguien ha llegado hasta el final?$"

