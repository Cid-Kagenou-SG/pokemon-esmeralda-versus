BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "Había alguien aquí usando un Pokémon\n"
	.string "que nunca había visto antes.\p"
	.string "Al menos no lo aprendí en la Escuela\n"
	.string "de Entrenadores.\p"
	.string "Me pregunto dónde se pueden atrapar\n"
	.string "Pokémon como ese.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "¡Vale! ¡Siguiente parada, el Dojo\n"
	.string "Batalla! Mejor saco los Pokémon\l"
	.string "adecuados del Sistema de Almacenamiento\l"
	.string "de PC.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Ji, ji… Voy a pasar por todos los\n"
	.string "desafíos con solo este pequeño.$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: ¡Miauuu miaaaauuu!$"

