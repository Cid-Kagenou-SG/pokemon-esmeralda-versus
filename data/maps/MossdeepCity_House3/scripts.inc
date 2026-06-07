MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "¡Eh, entrenador!\n"
	.string "¡Una Súper Caña es realmente súper!\p"
	.string "Diga lo que diga, ¡esta cosa puede\n"
	.string "atrapar Pokémon del fondo del mar!\p"
	.string "¿Qué te parece?\n"
	.string "La quieres, ¿verdad?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "¡Claro que sí!\n"
	.string "¡Después de todo, una Súper Caña es\l"
	.string "realmente súper!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Si hay agua, ¡prueba a lanzar tu Caña\n"
	.string "y mira qué pica!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "¿Eh?\n"
	.string "¿No te gusta pescar?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "¡Ve a por los Pokémon del fondo del mar\n"
	.string "con tu Súper Caña!$"

