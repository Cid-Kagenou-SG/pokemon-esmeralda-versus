SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "¡No necesitamos a un crío por aquí!\n"
	.string "¡Vete a casa de una vez!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Quiero irme a casa…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Quiero conseguir un ascenso para poder\n"
	.string "mandar a los RECLUTAS…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Ese submarino… Es diminuto por dentro.\n"
	.string "¡Me duele todo el cuerpo!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "¡Perder me duele!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Ese submarino que robamos, tío,\n"
	.string "es una tortura como transporte.\l"
	.string "¡Está demasiado apretado ahí dentro!$"

