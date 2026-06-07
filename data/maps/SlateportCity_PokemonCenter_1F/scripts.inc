SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "¿Quieres un consejo para combatir?\p"
	.string "Yo diría que es criar diferentes tipos\n"
	.string "de POKéMON de forma equilibrada.\p"
	.string "No sirve de nada hacer fuerte solo a\n"
	.string "un POKéMON.\p"
	.string "Si tiene una desventaja de tipo,\n"
	.string "puede que no tenga ninguna posibilidad.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "Intercambio POKéMON con mis amigos.\p"
	.string "¡Si un POKéMON intercambiado lleva un\n"
	.string "objeto, me hace el doble de feliz!$"

