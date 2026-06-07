VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "No puedes considerarte un auténtico\n"
	.string "entrenador si no tienes fe en tus\l"
	.string "Pokémon.\p"
	.string "Solo aquellos que son capaces de creer\n"
	.string "en sus Pokémon de combate pueden llegar\l"
	.string "hasta el final.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "La razón por la que alguien visitaría\n"
	.string "Verdegal...\p"
	.string "Es la Tienda de Batalla. Eso se da por\n"
	.string "sentado.\p"
	.string "¿O hay alguien aquí a quien has venido\n"
	.string "a ver?$"

