OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Ese PC de la esquina es para que lo use\n"
	.string "cualquier entrenador Pokémon.\p"
	.string "Naturalmente, eso significa que tú también\n"
	.string "puedes usarlo.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "¡Los Centros Pokémon son geniales!\p"
	.string "Puedes usar sus servicios todo lo que\n"
	.string "quieras, y todo es gratis.\l"
	.string "¡Nunca tienes que preocuparte!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "El Club Inalámbrico Pokémon de la\n"
	.string "planta de arriba se construyó hace poco.\p"
	.string "Pero dicen que todavía están haciendo\n"
	.string "ajustes.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "El Club Inalámbrico Pokémon de la\n"
	.string "planta de arriba se construyó hace poco.\p"
	.string "Yo intercambié Pokémon enseguida.$"

