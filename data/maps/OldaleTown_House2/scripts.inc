OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Cuando los Pokémon combaten, acaban\n"
	.string "subiendo de nivel y haciéndose más\l"
	.string "fuertes.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Si los Pokémon que te acompañan se hacen\n"
	.string "más fuertes, podrás ir más lejos de\l"
	.string "aquí.$"

