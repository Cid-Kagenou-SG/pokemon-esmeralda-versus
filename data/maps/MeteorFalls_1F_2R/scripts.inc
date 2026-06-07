MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Aquí es donde los usuarios de Pokémon\n"
	.string "de tipo Dragón entrenamos.\p"
	.string "Incluso el Campeón viene.\n"
	.string "¿Ahora entiendes lo especial que es\l"
	.string "este lugar?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "¡Uf!\n"
	.string "¡No esperaba que fueras tan fuerte!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "El camino por delante sigue siendo largo\n"
	.string "y duro.\p"
	.string "¿Cuándo serán mi Pokémon y yo los\n"
	.string "mejores?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Quiero saber más sobre tu poder.\n"
	.string "Déjame registrarte en mi PokéNav.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Desde que nos conocimos, hemos entrenado\n"
	.string "duro con la vista puesta en el número\l"
	.string "uno.\p"
	.string "¡Ayúdanos a ver cuánto más fuertes nos\n"
	.string "hemos vuelto!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "¡Uf!\n"
	.string "¡No esperaba que fueras tan fuerte!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Obviamente has seguido con tu\n"
	.string "entrenamiento Pokémon.\p"
	.string "Mientras tú sigas siendo fuerte, yo\n"
	.string "también puedo volverme más fuerte!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JUAN: Siempre hemos combatido con\n"
	.string "Pokémon juntos como pareja.\l"
	.string "Tenemos confianza en nosotros mismos.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JUAN: Oh, Dios mío.\n"
	.string "Hemos perdido, querida esposa.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JUAN: Llevamos cincuenta años casados.\p"
	.string "Ahora que lo pienso, todavía no le he\n"
	.string "ganado a mi querida esposa en un combate.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JUAN: Bueno, bueno, ¡qué joven\n"
	.string "entrenador!\p"
	.string "¿Quieres combatir con nosotros? Si es\n"
	.string "así, tendrás que volver con más Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JUAN: Joven entrenador, si surge la\n"
	.string "oportunidad, ¿combatirás con nosotros\l"
	.string "otra vez?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Llevamos cincuenta años casados.\p"
	.string "El vínculo que compartimos como pareja\n"
	.string "nunca podría romperse.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Oh, querido.\n"
	.string "Hemos perdido, mi querido esposo.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Cincuenta años de matrimonio…\p"
	.string "Si alguna vez discutíamos, siempre lo\n"
	.string "arreglábamos con un combate Pokémon…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Bueno, bueno, ¿no eres un joven\n"
	.string "entrenador?\p"
	.string "Si te gustaría combatir con nosotros,\n"
	.string "tendrás que volver con más Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JUAN: Siempre hemos combatido con\n"
	.string "Pokémon juntos como pareja.\l"
	.string "Tenemos confianza en nosotros mismos.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JUAN: Oh, Dios mío.\n"
	.string "Hemos perdido, querida esposa.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JUAN: Cincuenta años de matrimonio…\p"
	.string "En retrospectiva, mi querida esposa y\n"
	.string "yo, combatíamos día tras día…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JUAN: Bueno, bueno, ¡qué joven\n"
	.string "entrenador!\p"
	.string "¿Quieres combatir con nosotros? Si es\n"
	.string "así, tendrás que volver con más Pokémon.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Llevamos cincuenta años casados.\p"
	.string "Nos hemos apoyado mutuamente todo ese\n"
	.string "tiempo. Nos hemos hecho fuertes.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Oh, querido.\n"
	.string "Hemos perdido, mi querido esposo.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Cincuenta años de matrimonio…\n"
	.string "Han pasado muchas cosas.\p"
	.string "Espero que sigamos haciendo recuerdos\n"
	.string "felices juntos.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Bueno, bueno, ¿no eres un joven\n"
	.string "entrenador?\p"
	.string "Si te gustaría combatir con nosotros,\n"
	.string "tendrás que volver con más Pokémon.$"

