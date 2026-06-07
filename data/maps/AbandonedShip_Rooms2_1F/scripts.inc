AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Mientras buscábamos tesoros,\n"
	.string "¡hemos descubierto a un ENTRENADOR!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: No hemos podido ganar incluso\n"
	.string "aunque trabajáramos juntos…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: No podemos encontrar ningún tesoro…\n"
	.string "¿Me pregunto si alguien ya se los ha llevado?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Ni siquiera tienes dos POKéMON.\n"
	.string "No puedes esperar vencernos así.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: ¿Oh?\n"
	.string "Estábamos buscando tesoros.\l"
	.string "¡Pero hemos descubierto a un ENTRENADOR en su lugar!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: ¡Ooh, qué fuerte!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: ¿Dónde estarán los tesoros?\p"
	.string "Ya he decidido qué voy a comprar\n"
	.string "¡cuando encontremos los tesoros!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Oh, ¿no tienes dos POKéMON?\n"
	.string "¡Tendremos que luchar en otra ocasión!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: ¡Oh, me pones de los nervios!\n"
	.string "¡Te voy a registrar por eso!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: Hemos estado buscando tesoros\n"
	.string "todo este tiempo.\p"
	.string "Nuestros POKéMON también se han vuelto más fuertes.\n"
	.string "Déjanos mostrártelo, ¿vale?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: ¡Eres fuerte, como siempre!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: No podemos encontrar ningún tesoro,\n"
	.string "perdemos en los combates POKéMON…\p"
	.string "Quiero irme a casa… Pero si digo eso,\n"
	.string "ella se enfada mucho conmigo…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Ni siquiera tienes dos POKéMON.\n"
	.string "No puedes esperar vencernos así.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: ¿Oh? ¡Nos volvemos a encontrar!\p"
	.string "Al igual que nosotros, tú tampoco has renunciado\n"
	.string "a buscar tesoros, ¿verdad?\p"
	.string "¿Quieres que el perdedor tenga que\n"
	.string "renunciar a la búsqueda?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: Oh, hemos perdido otra vez…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: No nos iremos hasta que entrenemos más\n"
	.string "a nuestros POKéMON y encontremos\l"
	.string "¡los tesoros que hay aquí!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Oh, ¿no tienes dos POKéMON?\n"
	.string "¡Tendremos que luchar en otra ocasión!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "No se me da bien nadar,\n"
	.string "¡pero se me dan bien los combates!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Vaya.\n"
	.string "Eso no ha salido muy bien.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Andar descalzo por este barco\n"
	.string "es bastante asqueroso.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "¡La fuerza y la compasión…\n"
	.string "son los tesoros de un ENTRENADOR!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, hay algo en ti\n"
	.string "que brilla.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "En una cabina de aquí a bordo,\n"
	.string "he visto algo brillar.$"
