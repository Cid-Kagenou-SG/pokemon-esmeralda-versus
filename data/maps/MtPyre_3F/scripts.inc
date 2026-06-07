MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "¡La rica atmósfera de la montaña ha\n"
	.string "elevado mi poder psíquico!\p"
	.string "Un simple niño como tú…\n"
	.string "¿Sueñas con ganar?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Me ahogo en la autocompasión…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Mis poderes psíquicos han crecido\n"
	.string "varias veces, pero…$"

MtPyre_3F_Text_KaylaIntro:
	.string "¡Ahahahaha!\p"
	.string "Este no es un lugar para niños, y mucho\n"
	.string "menos para ti!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "He perdido tan limpiamente…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Esto significa que mi entrenamiento\n"
	.string "todavía no es suficiente…\p"
	.string "Tengo que seguir trabajando hacia la\n"
	.string "cumbre…\p"
	.string "¡Vamos, yo puedo!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "¿Por qué has venido aquí?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "¡Eso ha sido increíble!\n"
	.string "Eres un entrenador muy especial.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Los Pokémon que ya no están en este\n"
	.string "mundo. Los Pokémon que están contigo\l"
	.string "ahora.\p"
	.string "Y los Pokémon que conocerás en el\n"
	.string "futuro…\p"
	.string "Todos deben ser igualmente apreciados.\n"
	.string "Por favor, recuerda eso.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Me gustaría ver tus Pokémon cuando\n"
	.string "hayan crecido un poco más…\p"
	.string "Por favor, necesito ver tu PokéNav.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, eres tú…\p"
	.string "¿Has venido a mostrarme tus Pokémon\n"
	.string "crecidos?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "¡Qué increíble!\n"
	.string "Eres una persona especial.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Los Pokémon que ya no están en este\n"
	.string "mundo. Los Pokémon que están contigo\l"
	.string "ahora.\p"
	.string "Y los Pokémon que conocerás en el\n"
	.string "futuro…\p"
	.string "Todos deben ser igualmente apreciados.\n"
	.string "Veo que lo has recordado.$"

