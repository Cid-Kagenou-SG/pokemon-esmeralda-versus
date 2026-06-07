SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "¡Arrrgh! ¡Estoy harto y hecho polvo de\n"
	.string "limpiar este lugar enorme!\p"
	.string "¡Vamos a echar un combate rápido!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "¡Hermanito, he perdido!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "¡Somos los HERMANOS LIMPIEZA!\p"
	.string "¡El mayor echa el detergente y el\n"
	.string "pequeño frega!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Este es el fondo del casco del barco.\n"
	.string "Hay mucho espacio.\l"
	.string "No hay problema para un combate POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "¡Hermano mayor, he perdido!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "¡Somos los HERMANOS LIMPIEZA!\p"
	.string "¡El mayor echa el detergente y el\n"
	.string "pequeño frega!$"

