LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Mi mujer está calentando un Huevo en\n"
	.string "los manantiales termales. Esto es lo\l"
	.string "que me ha dicho.\p"
	.string "Dejó dos Pokémon en la Guardería.\n"
	.string "¡Y encontraron ese Huevo!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: ¡Me vengoooo!$"

