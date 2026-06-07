PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Tú eres…\n"
	.string "Ah, debes de ser {PLAYER}{KUN}, ¿verdad?\p"
	.string "Gracias por jugar con Blasco hace\n"
	.string "un rato.\p"
	.string "Ha sido débil y enfermizo desde\n"
	.string "que era un bebé.\p"
	.string "Lo hemos enviado a quedarse con mis\n"
	.string "familiares en Pueblo Verdegal durante\l"
	.string "un tiempo.\p"
	.string "El aire es mucho más limpio allí\n"
	.string "que aquí.\p"
	.string "¿Qué? ¿Dónde está Blasco?\n"
	.string "Ya se ha ido, nuestro Blasco.\p"
	.string "Me pregunto dónde habrá llegado\n"
	.string "ya.$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Me pregunto cómo estará nuestro\n"
	.string "Blasco.$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Por favor, perdona que\n"
	.string "te hayamos traído aquí de esta manera.\p"
	.string "Pero nuestro Blasco se ha puesto muy\n"
	.string "saludable desde que fue a Pueblo\l"
	.string "Verdegal.\p"
	.string "¡Te lo debemos todo a ti!\p"
	.string "Cuando Blasco se fue del pueblo, le\n"
	.string "ayudaste a atrapar un Pokémon, ¿verdad?\p"
	.string "Creo que eso hizo que Blasco estuviera\n"
	.string "muy feliz.\p"
	.string "En realidad, no solo Blasco.\n"
	.string "A mí, su padre, también me hizo feliz.\p"
	.string "Feliz de que haya ganado un gran\n"
	.string "amigo como tú.\p"
	.string "Esto no es un soborno ni nada, pero\n"
	.string "me gustaría mucho que aceptaras esto.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Si tu Pokémon puede usar Surf, podrás\n"
	.string "ir a todo tipo de lugares.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "Blasco volverá a casa pronto.\n"
	.string "Estoy deseando verlo.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "¿Oh? ¿Conociste a Blasco en\n"
	.string "Ciudad Colosalia?\p"
	.string "Oh, {PLAYER}{KUN}, no seas tonto.\p"
	.string "Puede que se haya puesto saludable,\n"
	.string "pero no puede ir a un lugar tan lejano\l"
	.string "como ese solo.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Blasco estaba muy feliz cuando nos\n"
	.string "dijo que había atrapado un Pokémon.\p"
	.string "Hacía mucho tiempo que no lo veía\n"
	.string "sonreír así.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Quiero que guardes esto en secreto\n"
	.string "para mi marido…\p"
	.string "Pero nuestro Blasco se fue de Pueblo\n"
	.string "Verdegal sin decírselo a nadie.\p"
	.string "Sabes, Blasco es débil, pero\n"
	.string "sorprendentemente tiene una gran\l"
	.string "fuerza de voluntad.\p"
	.string "¡Estoy segura de que volverá sano y\n"
	.string "salvo algún día!$"

