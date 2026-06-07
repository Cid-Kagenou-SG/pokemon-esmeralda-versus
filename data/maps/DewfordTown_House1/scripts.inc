DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Hay mucho que decir a favor de vivir en\n"
	.string "una pequeña isla como esta en armonía\l"
	.string "con los Pokémon y la familia.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Dejé el gran puerto de Ciudad Portual\n"
	.string "cuando me casé con mi marido aquí.\p"
	.string "La vida transcurre lentamente en esta\n"
	.string "pequeña isla. Pero estar rodeada por\l"
	.string "el hermoso mar, eso también es\l"
	.string "felicidad.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: ¡Sácame de aquí!$"

