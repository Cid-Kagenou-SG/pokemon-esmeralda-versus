FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "¡Las casas del árbol de Arborada son\n"
	.string "geniales!\p"
	.string "Creo que es el pueblo número uno para\n"
	.string "vivir junto a los Pokémon.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "Los Pokémon y las personas se han\n"
	.string "adaptado a la naturaleza para\l"
	.string "sobrevivir.\p"
	.string "No hay necesidad de hacer que la\n"
	.string "naturaleza se adapte a la forma en que\l"
	.string "queremos vivir.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON: ¡Zizallazo!$"

