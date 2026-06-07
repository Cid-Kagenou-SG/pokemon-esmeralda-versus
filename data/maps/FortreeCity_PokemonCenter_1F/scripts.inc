FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Escucha, chico, ¿estás trabajando en\n"
	.string "una Pokédex?\p"
	.string "Mmm… Ve a la Zona Safari.\n"
	.string "Esa es mi sugerencia.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "¿Has hecho algo en la\n"
	.string "Esquina Récord?\p"
	.string "Es bastante guay. Mezcla y combina\n"
	.string "los récords de los entrenadores.\p"
	.string "No sé muy bien cómo funciona,\n"
	.string "pero es genial. ¡Es emocionante, incluso!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, vaya, ¡tienes un PokéNav!\n"
	.string "¡Y es igual que el mío!\p"
	.string "¿Sabes sobre el sistema de\n"
	.string "Llamada de Búsqueda del PokéNav?\p"
	.string "Accede a él y podrás chatear con\n"
	.string "entrenadores registrados en cualquier\l"
	.string "momento.\p"
	.string "También te muestra qué entrenadores\n"
	.string "quieren una revancha contigo.\p"
	.string "¡Es realmente útil! ¡Esos tipos de\n"
	.string "Devon saben lo que hacen!$"

