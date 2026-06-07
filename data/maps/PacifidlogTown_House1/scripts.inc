PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "En la región de Hoenn, hay tres Pokémon\n"
	.string "que representan el poder de la roca, el\l"
	.string "hielo y el acero.\p"
	.string "Se dice que cada uno de ellos se oculta\n"
	.string "en lo más profundo de una cueva.\p"
	.string "Esa es la historia que oí cuando era\n"
	.string "un niño pequeño.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“Seis puntos abren tres puertas.”\p"
	.string "El abuelo solía decir eso, pero no sé\n"
	.string "a qué se refería.$"

