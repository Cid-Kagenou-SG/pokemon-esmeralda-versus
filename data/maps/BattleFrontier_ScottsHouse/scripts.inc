BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
	.string "TRETO: Bueno, ¡hola y bienvenido!\n"
	.string "Je, je… Perdona por el espacio\l"
	.string "reducido.\p"
	.string "En fin, {PLAYER}{KUN}, permíteme\n"
	.string "darte la bienvenida formal al\l"
	.string "Frente Batalla.\p"
	.string "Este es mi sueño hecho realidad.\n"
	.string "Me ha llevado años y años, pero\l"
	.string "finalmente le he dado forma a mi sueño.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "Reflexionando, fue un viaje\n"
	.string "terriblemente largo…\p"
	.string "Dejé mi hogar solo en busca de\n"
	.string "entrenadores fuertes.\p"
	.string "Nadie puede imaginar el esfuerzo ni el\n"
	.string "tiempo que me llevó hacer esto realidad.$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "Pero eso ya es pasado.\n"
	.string "¡No tiene sentido quedarse en ello!\p"
	.string "Todo lo que quiero es que disfrutes\n"
	.string "combatiendo hasta saciarte aquí.\p"
	.string "{PLAYER}{KUN}, quiero que tengas esto\n"
	.string "como recuerdo de todas las veces que\l"
	.string "nuestros caminos se cruzaron en\l"
	.string "nuestros viajes.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} obtuvo\n"
	.string "{STR_VAR_1} Punto(s) de Batalla.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "TRETO: Puedes comprobar tus Puntos de\n"
	.string "Batalla en tu Pase del Frente.\p"
	.string "Cuanto más éxito tengas aquí en el\n"
	.string "Frente Batalla, más Puntos de Batalla\l"
	.string "acumularás.\p"
	.string "Usa tus Puntos de Batalla como mejor te\n"
	.string "parezca, como intercambiarlos por\l"
	.string "objetos.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "¡Espero grandes cosas de ti!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
	.string "TRETO: Cada entrenador es un\n"
	.string "individuo. Todos llevan vidas\l"
	.string "propias.\p"
	.string "Pero cuando están en un combate,\n"
	.string "no importa quiénes son.\p"
	.string "¡Todos son iguales!\p"
	.string "Amo la pureza del combate, donde\n"
	.string "todos son iguales.\p"
	.string "Por eso voy por todas partes buscando\n"
	.string "entrenadores que se tomen en serio los\l"
	.string "combates, e invitándolos aquí.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "TRETO: ¿Has conocido a alguno de los\n"
	.string "Ases del Frente?\p"
	.string "Mejor aún, ¿has obtenido algún símbolo\n"
	.string "de ellos?\p"
	.string "Elegí personalmente a los Ases del\n"
	.string "Frente como los entrenadores más duros\l"
	.string "de cualquier lugar.\p"
	.string "Pero estoy seguro de que ver lo duro\n"
	.string "que eres sorprenderá incluso a ellos.$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "TRETO: No solo entrenas para combatir,\n"
	.string "¿verdad?\p"
	.string "Creo recordar que también trabajabas en\n"
	.string "una Pokédex.\p"
	.string "Bueno, ¿adivina qué?\p"
	.string "Puede que te encuentres con Pokémon\n"
	.string "salvajes en algún lugar del Frente\l"
	.string "Batalla…\l"
	.string "¡Fufufu!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
	.string "TRETO: ¿Estás disfrutando en el\n"
	.string "Frente Batalla?\p"
	.string "…Espera un segundo…\n"
	.string "¡Oh!\p"
	.string "¡Tu Pase del Frente!\n"
	.string "¡Has coleccionado el conjunto completo\l"
	.string "de símbolos plateados!\p"
	.string "¡Eso es más que impresionante!\n"
	.string "¡Eres duro, tal como sospechaba!\p"
	.string "Normalmente, no haría algo así, pero\n"
	.string "¡esta es una ocasión especial!\p"
	.string "Quiero que tengas esto.\n"
	.string "Estoy seguro de que podrás darle un\l"
	.string "buen uso.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
	.string "TRETO: Espero que estés disfrutando de\n"
	.string "todo en el Frente Batalla.\p"
	.string "…Espera un segundo…\n"
	.string "¡Oh, mis ojos incrédulos!\p"
	.string "¡Tu Pase del Frente!\n"
	.string "¡Has reunido el conjunto completo de\l"
	.string "símbolos dorados!\p"
	.string "¡Eso es más que estupendo!\n"
	.string "¡Eres increíble, tal como sospechaba!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, ¡tienes que aceptar esto!\p"
	.string "Creo que serás capaz de apreciar el\n"
	.string "valor de mi regalo.$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "Debo decir que tengo el don de\n"
	.string "reconocer a un buen entrenador cuando\l"
	.string "lo veo.\p"
	.string "¡Me alegro tanto de haber tenido la\n"
	.string "previsión de traerte aquí!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "Tu Bolsillo Bayas parece estar\n"
	.string "rebosante.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "TRETO: Oh, ¡he oído hablar de ti!\n"
	.string "¡Cómo dominaste la Torre Batalla!\l"
	.string "¿Venciste a más de 50 entrenadores\l"
	.string "seguidos?\p"
	.string "¡Eso es fantástico!\n"
	.string "¡Quiero que tengas esto!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "TRETO: ¡Oh, Dios! ¡He oído hablar de ti!\n"
	.string "¡Cómo arrasaste en la Torre Batalla!\l"
	.string "¿Venciste a más de 100 entrenadores\l"
	.string "seguidos?\p"
	.string "¡Eso es ridículamente espectacular!\n"
	.string "¡Tienes que tener esto!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "¡Estaré esperando oír cosas aún\n"
	.string "mayores sobre ti!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "Ups, bueno, si tienes demasiadas cosas,\n"
	.string "vuelve más tarde por esto.$"

