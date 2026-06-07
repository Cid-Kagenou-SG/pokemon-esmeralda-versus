Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mi hermano mayor es el MANIÁTICO DE LOS\n"
	.string "FÓSILES... Es un buen tipo que ama los\l"
	.string "FÓSILES...\p"
	.string "También le encanta cavar agujeros...\n"
	.string "Él cavó este agujero por sí mismo...\p"
	.string "Puedes quedarte con esto, para que puedas\n"
	.string "usar EXCAVAR como mi hermano mayor...$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Si haces que un Pokémon use EXCAVAR\n"
	.string "dentro de una cueva, vuelves a la\l"
	.string "entrada...$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Rocas de formas peculiares llenan\n"
	.string "la vitrina...$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSICIÓN DE LOS ESTRATOS...\n"
	.string "CÓMO LA LLUVIA MOLDEA LA TIERRA...\l"
	.string "PIEDRAS, SUELO Y ROCA...\p"
	.string "Está atiborrado de libros.$"

