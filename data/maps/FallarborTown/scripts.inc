FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Algo está pasando,\n"
	.string "¡y no me gusta!\p"
	.string "He visto personajes sospechosos\n"
	.string "entrando y saliendo de la casa del\l"
	.string "Prof. Cosmo…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Esta región ha sido conocida por los\n"
	.string "meteoritos desde tiempos antiguos.\p"
	.string "Dicen que la Cascada Meteoro fue\n"
	.string "excavada por un meteorito que cayó hace\l"
	.string "mucho tiempo.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "¡Mira! ¡Mira!\n"
	.string "¡Este es mi precioso Azurill!\p"
	.string "¡Es suave, liso y mullido!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "¿Ya has desafiado a Candela, la líder\n"
	.string "del Gimnasio de Lavacalda?\p"
	.string "El abuelo de la chica era famoso.\n"
	.string "Fue uno de los Alto Mando de la Liga\l"
	.string "Pokémon en algún momento.\p"
	.string "No me sorprendería ver que Candela se\n"
	.string "convierte en una gran entrenadora por\l"
	.string "sí misma.$"

FallarborTown_Text_BattleTentSign:
	.string "TIENDA DE BATALLA DE PUEBLO PARDAL\n"
	.string "“¡Que se reúnan los mejores equipos!”$"

FallarborTown_Text_TownSign:
	.string "PUEBLO PARDAL\n"
	.string "“Una comunidad agrícola con pequeños\n"
	.string "huertos.”$"

FallarborTown_Text_MoveTutorSign:
	.string "CASA DEL RECUERDA-MOVIMIENTOS\n"
	.string "“Nuevos movimientos enseñados a los\n"
	.string "Pokémon.”$"

