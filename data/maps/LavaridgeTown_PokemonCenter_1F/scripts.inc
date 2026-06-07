LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "Creo que los Pokémon se hacen más\n"
	.string "cercanos a sus entrenadores si pasan\l"
	.string "tiempo juntos.\p"
	.string "Cuanto más tiempo, mejor.\n"
	.string "Eso es lo que pienso.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "Es casi mágico cómo simplemente\n"
	.string "sentarse en un manantial termal te da\l"
	.string "energía.\p"
	.string "Ojalá pudiera dejar que mis Pokémon\n"
	.string "también se relajaran.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "¡Jojojo! Oye, chico, desde aquí puedes\n"
	.string "llegar a los manantiales termales.\p"
	.string "Si los Pokémon descansan, sus\n"
	.string "entrenadores también deberían hacerlo.$"

