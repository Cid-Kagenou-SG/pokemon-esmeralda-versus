FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Nadie me cree, pero vi un Pokémon\n"
	.string "gigantesco en el cielo.\p"
	.string "Parecía retorcerse mientras volaba\n"
	.string "hacia la Ruta 131.\p"
	.string "Por cierto… Snif…\n"
	.string "Um… Tú, eh… hueles a quemado.\p"
	.string "¿Has estado en un volcán o algo así?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Quiero ir al Gimnasio Pokémon, pero\n"
	.string "algo está bloqueando el camino.\p"
	.string "Después de todo el esfuerzo que hice\n"
	.string "entrenando en la Ruta 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Tengo conmigo a mi Pokémon del que\n"
	.string "estoy orgulloso. Esta vez, venceré a\l"
	.string "Alana.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "El suelo absorbe el agua de lluvia, y\n"
	.string "los árboles crecen bebiendo esa agua…\p"
	.string "Nuestra Ciudad Arborada existe porque\n"
	.string "hay tanto agua como tierra.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "La ciudad consiste en casas construidas\n"
	.string "sobre árboles.\p"
	.string "Quizá debido a ese estilo de vida,\n"
	.string "todos están sanos y llenos de vida.\p"
	.string "Vaya, incluso yo, siento como si\n"
	.string "hubiera rejuvenecido treinta años.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Vivir encima de los árboles está bien.\p"
	.string "Pero a veces los Pokémon bicho entran\n"
	.string "por las ventanas. Puede ser muy\l"
	.string "sorprendente.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Hay Pokémon que evolucionan cuando los\n"
	.string "intercambias. Eso es lo que he oído.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Algo invisible está en el camino.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Algo invisible está en el camino.\p"
	.string "¿Quieres usar el Detector Devon?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un Pokémon invisible se volvió\n"
	.string "completamente visible!\p"
	.string "¡El Pokémon asustado huyó!$"

FortreeCity_Text_CitySign:
	.string "CIUDAD ARBORADA\n"
	.string "“La ciudad de las copas de los árboles\l"
	.string "que juega con la naturaleza.”$"

FortreeCity_Text_GymSign:
	.string "GIMNASIO POKÉMON DE CIUDAD ARBORADA\n"
	.string "LÍDER: ALANA\p"
	.string "“La usuaria de pájaros que despega\n"
	.string "hacia el mundo.”$"

