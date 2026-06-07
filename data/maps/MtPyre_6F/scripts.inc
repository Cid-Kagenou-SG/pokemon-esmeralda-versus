MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Cuando estoy aquí…\n"
	.string "Un extraño poder fluye hacia mí…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "El poder se está desvaneciendo…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Quizás el poder proviene de los\n"
	.string "espíritus de los Pokémon que duermen\l"
	.string "agitados aquí…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… Perdí el combate, pero…\n"
	.string "Tengo esta pequeña habilidad…\p"
	.string "Sin siquiera tocar tu PokéNav…\n"
	.string "¡Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Detrás de ti…\n"
	.string "¿Qué es…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Algo se desvaneció…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Los Pokémon que descansan aquí…\n"
	.string "A veces, juegan…$"

MtPyre_6F_Text_CedricIntro:
	.string "¿Has perdido el norte?\n"
	.string "¡No temas, porque yo estoy aquí!$"

MtPyre_6F_Text_CedricDefeat:
	.string "¿No estabas perdido?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Tenía la sensación de que un entrenador\n"
	.string "perdido estaría asustado y fácil de\l"
	.string "vencer.\p"
	.string "Es sucio y no lo intentaré otra vez…$"

