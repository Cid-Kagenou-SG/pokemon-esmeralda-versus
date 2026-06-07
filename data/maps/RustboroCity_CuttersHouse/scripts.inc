RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Esa expresión decidida…\n"
	.string "Esa forma ágil de moverte…\l"
	.string "Y tus POKéMON bien entrenados…\p"
	.string "¡Obviamente eres un ENTRENADOR\n"
	.string "habilidoso!\p"
	.string "No, espera, no digas nada.\n"
	.string "Puedo saberlo solo con mirarte.\p"
	.string "Estoy seguro de que podrás poner esta\n"
	.string "MÁQUINA OCULTA a buen uso.\p"
	.string "No hace falta que seas modesto o tímido.\n"
	.string "¡Venga, tómala!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Esa MÁQUINA OCULTA, o MO para abreviar,\n"
	.string "es CORTE.\p"
	.string "Un movimiento MO es uno que puede ser\n"
	.string "usado por los POKéMON fuera del combate.\p"
	.string "Cualquier POKéMON que haya aprendido\n"
	.string "CORTE puede talar árboles delgados si\l"
	.string "el ENTRENADOR ha conseguido la MEDALLA\l"
	.string "PIEDRA.\p"
	.string "Y, a diferencia de una MT, una MO puede\n"
	.string "usarse más de una vez.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Cuando estaban ampliando la ciudad de\n"
	.string "FÉRRICA, mi papá ayudó.\p"
	.string "Hizo que su POKéMON usara CORTE para\n"
	.string "limpiar la tierra de árboles.$"

