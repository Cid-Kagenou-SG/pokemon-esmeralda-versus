RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mi POKéMON tiene una naturaleza\n"
	.string "INGENUA, y el de mi amigo tiene una\l"
	.string "naturaleza ALEGRE.\p"
	.string "¡Es fascinante cómo los POKéMON tienen\n"
	.string "personalidades!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Al igual que las personas, hay POKéMON\n"
	.string "macho y POKéMON hembra.\p"
	.string "Pero nadie parece tener ni idea de\n"
	.string "en qué se diferencian.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "¡El hombre de al lado me dio una MO!\p"
	.string "La usé para enseñar a mi POKéMON cómo\n"
	.string "CORTAR árboles delgados.$"

