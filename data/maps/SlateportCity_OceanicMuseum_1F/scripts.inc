SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Bienvenido al MUSEO OCEANOGRÁFICO.\p"
	.string "La entrada cuesta 50¥.\n"
	.string "¿Quieres entrar?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Disfruta de la visita.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "¿Oh? Lo siento, pero parece que no\n"
	.string "tienes suficiente dinero.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "¿Oh? ¿Vienes con el grupo que entró\n"
	.string "antes?\p"
	.string "Eres el único que se ha retrasado.\n"
	.string "¡Será mejor que vayas a alcanzarlos!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "¡El EQUIPO AQUA existe para el bien\n"
	.string "de todos!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Nos ordenaron reunirnos aquí,\n"
	.string "así que lo hicimos, pero…\p"
	.string "Nuestro JEFE, la pieza clave, no está.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "¿Si me llevara las cosas de aquí,\n"
	.string "me haría rico?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Lo que aprenda aquí, puedo usarlo para\n"
	.string "actos malvados…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "¡Si nuestros secuaces no hubieran\n"
	.string "estropeado las cosas en FÉRRICA, no\l"
	.string "estaríamos aquí!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "No tenía 50¥, así que me costó mucho\n"
	.string "pasar por la recepcionista.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Quiero aprender sobre el mar y usar\n"
	.string "ese conocimiento para combatir.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "¡Me emociono y me derrito cuando veo\n"
	.string "el mar!\p"
	.string "Para mí, el CAPITÁN BABOR es el\n"
	.string "modelo a seguir número uno.$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "El mar es vasto sin fin e\n"
	.string "infinitamente profundo…\p"
	.string "Debe haber muchos POKéMON que\n"
	.string "desconocemos.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Quiero un POKéMON de mar.\p"
	.string "Creo que sería fresco y agradable\n"
	.string "abrazarlo.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "¡Aaaay!\n"
	.string "¿Qué haces tú aquí?\p"
	.string "¿Yo? Soy el miembro del EQUIPO AQUA\n"
	.string "al que derrotaste antes, ¿recuerdas?\l"
	.string "¡En el TÚNEL FERVEGAL!\p"
	.string "¡Toma, toma esto!\n"
	.string "¡Tienes que perdonarme!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Esa MT te queda mejor a ti que a mí.\p"
	.string "¡Espero no volver a verte nunca!\n"
	.string "¡Uajajaja!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "¡Venga ya!\n"
	.string "¡Tienes que tomar esto y dejarme ir!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Un fluido azul gira en espiral dentro\n"
	.string "de un recipiente de cristal.\p"
	.string "“Este es un experimento para crear un\n"
	.string "TORBELLINO artificialmente usando el\l"
	.string "viento.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Una bola roja sube y baja dentro de un\n"
	.string "recipiente de cristal.\p"
	.string "“Este es un experimento que simula una\n"
	.string "CASCADA usando la flotabilidad de la\l"
	.string "bola.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Es una muestra de suelo del fondo\n"
	.string "oceánico.\p"
	.string "“Durante muchos años, los restos de\n"
	.string "seres vivos se asientan en el fondo del\l"
	.string "mar, formando capas sedimentarias.\p"
	.string "“Al analizar estas capas, se revela\n"
	.string "el antiguo pasado.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Es una muestra de arena de playa.\p"
	.string "“Las piedras de las montañas son\n"
	.string "arrastradas por los ríos, donde se\l"
	.string "desgastan y trituran.\p"
	.string "“Se reducen a granos y acaban\n"
	.string "convirtiéndose en arena de playa.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“MINIDATO OCEANOGRÁFICO 1\n"
	.string "¿Por qué el agua de mar es azul?\p"
	.string "“La luz se compone de muchos colores.\p"
	.string "“Cuando la luz atraviesa el agua,\n"
	.string "la mayoría de los colores se pierden.\p"
	.string "“Sin embargo, la luz azul conserva su\n"
	.string "color, haciendo que el mar parezca azul.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“MINIDATO OCEANOGRÁFICO 2\n"
	.string "¿Por qué el mar es salado?\p"
	.string "“El agua de mar contiene sal disuelta\n"
	.string "en forma de iones de sodio y cloro.\p"
	.string "“Estos iones se filtran de las rocas\n"
	.string "y son arrastrados al mar por la lluvia.\p"
	.string "“La concentración de sal disuelta\n"
	.string "hace que el mar sea salado.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“MINIDATO OCEANOGRÁFICO 3\n"
	.string "¿Qué es más grande? ¿El mar o la tierra?\p"
	.string "“El mar cubre aproximadamente el 70% de\n"
	.string "el planeta, y el resto es tierra.\p"
	.string "“Por tanto, el mar es más del doble de\n"
	.string "grande que la tierra.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Es un fósil con surcos ondulados.\p"
	.string "“El suelo del fondo oceánico es\n"
	.string "arrastrado por la marea.\p"
	.string "“El agua de mar en movimiento marca el\n"
	.string "suelo con pequeños surcos y valles.\p"
	.string "“Si este suelo se fosiliza, se denomina\n"
	.string "marca de ondulación.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Una máquina extraña gira bajo una\n"
	.string "cúpula de cristal.\p"
	.string "Quizás sirva para medir la profundidad\n"
	.string "de algo…$"

