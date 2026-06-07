PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "El Sistema de Almacenamiento de\n"
	.string "Pokémon del PC…\p"
	.string "¡El que lo inventó debe de ser un\n"
	.string "auténtico genio de la informática!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Cuando mi Pokémon se comió una\n"
	.string "Baya Aranja, ¡recuperó PS!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Hay muchos tipos de Pokémon.\p"
	.string "Todos los tipos tienen sus puntos\n"
	.string "fuertes y débiles frente a otros tipos.\p"
	.string "Dependiendo de los tipos de Pokémon,\n"
	.string "un combate puede ser fácil o difícil.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Por ejemplo, tu Treecko\n"
	.string "es de tipo Planta.\p"
	.string "Es fuerte contra los tipos Agua y\n"
	.string "Tierra.\p"
	.string "Pero es débil contra los Pokémon\n"
	.string "de tipo Fuego.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Por ejemplo, tu Torchic\n"
	.string "es de tipo Fuego.\p"
	.string "Es fuerte contra los tipos Planta y\n"
	.string "Bicho.\p"
	.string "Pero es débil contra los Pokémon\n"
	.string "de tipo Agua.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Por ejemplo, tu Mudkip\n"
	.string "es de tipo Agua.\p"
	.string "Es fuerte contra el tipo Fuego.\p"
	.string "Pero es débil contra los Pokémon\n"
	.string "de tipo Planta y Eléctrico.$"

