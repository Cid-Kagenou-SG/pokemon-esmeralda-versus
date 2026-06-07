DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "¡Contempla esto!\p"
	.string "Es un Pañuelo Seda. ¡Está a la última\n"
	.string "en moda, sí!\p"
	.string "¡Oh, puedo ver tus ojos brillando!\n"
	.string "¡Aprecias mi deslumbrante estilo!\p"
	.string "¡Oh, eres un encanto!\n"
	.string "¡Toma, quiero que te lo quedes!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, ¿no tienes espacio?\p"
	.string "Ahora, escucha bien, ¡este Pañuelo es\n"
	.string "imprescindible! ¡Vendería todos mis\l"
	.string "objetos para conseguirlo!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "El Pañuelo Seda aumenta el poder de los\n"
	.string "movimientos de tipo Normal.\p"
	.string "¡Es un Pañuelo maravilloso que le irá\n"
	.string "bien a casi todos los Pokémon!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Vaya, te has molestado en cruzar el mar\n"
	.string "para visitar Pueblo Azuliza.\p"
	.string "¿Quizá viniste aquí porque oíste hablar\n"
	.string "de Marcial?\p"
	.string "Es tan guay…\n"
	.string "Todo el mundo lo idolatra.$"

