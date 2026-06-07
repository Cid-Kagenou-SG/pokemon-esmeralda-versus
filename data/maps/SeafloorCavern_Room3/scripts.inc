SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "¡Ahahahaha!\p"
	.string "¿Cómo has conseguido llegar aquí sin\n"
	.string "submarino?\l"
	.string "¡Qué niño tan impresionante!\p"
	.string "Pero… No está bien que te entrometas\n"
	.string "por aquí.\p"
	.string "Y, además, quiero vengarme de lo que\n"
	.string "pasó en el INSTITUTO METEOROLÓGICO…\p"
	.string "¡Voy a darte una pequeña muestra de\n"
	.string "dolor! ¡Acostúmbrate a ello!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "¡Ahahahaha!\p"
	.string "¡Ay!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "¡Ahahahaha!\n"
	.string "Eres tan fuerte.\p"
	.string "Es terriblemente decepcionante que no\n"
	.string "seas un miembro del EQUIPO AQUA.\p"
	.string "Podrías haber disfrutado del mundo\n"
	.string "fabuloso que nuestro JEFE ha prometido\l"
	.string "como uno de nosotros…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Para que nuestro sueño se haga realidad,\n"
	.string "necesitamos el poder de los POKéMON.\p"
	.string "¡Pero entrometidos como tú usan el poder\n"
	.string "de los POKéMON para estorbarnos incluso\l"
	.string "en un lugar como este!\p"
	.string "¡La vida simplemente no funciona como\n"
	.string "necesitamos!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "¡Gua!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Sabes, no nos atrevemos a cuestionar\n"
	.string "los motivos de nuestro líder.\p"
	.string "Pero aquí estás tú, solo un mocoso,\n"
	.string "enfrentándote a nuestro JEFE.\p"
	.string "Quizás…\n"
	.string "Debes de ser alguien…$"

