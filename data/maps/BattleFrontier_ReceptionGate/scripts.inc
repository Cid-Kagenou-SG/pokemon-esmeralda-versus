BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "¿Es tu primera vez aquí?\n"
	.string "¡Por aquí, por favor!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "¡La vanguardia de los combates Pokémon!\n"
	.string "¡Bienvenido al Frente Batalla!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Para un visitante por primera vez, emitimos\n"
	.string "el Pase del Frente.\p"
	.string "Sirve para usar en todas las instalaciones\n"
	.string "del Frente Batalla.\p"
	.string "¡Aquí tienes!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} obtuvo\n"
	.string "el Pase del Frente.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} colocó la Tarjeta de Entrenador\n"
	.string "en el Pase del Frente.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "¡Esperamos que disfrutes de todo lo que\n"
	.string "el Frente Batalla tiene para ofrecer!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: ¡Vaya, si es {PLAYER}{KUN}!\n"
	.string "¡Has venido hasta aquí!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUÍA: ¡Oh! ¡Señor Treto, señor!\n"
	.string "¡Buenos días, señor!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "TRETO: Me alegra mucho verte aquí,\n"
	.string "¡de verdad!\p"
	.string "Espero que te tomes tu tiempo y explores\n"
	.string "por todas partes.\p"
	.string "Naturalmente, espero que también\n"
	.string "experimentes la esencia pura del combate.\p"
	.string "También tengo mi residencia aquí, así\n"
	.string "que siéntete libre de visitarme si\l"
	.string "tienes tiempo.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Soy tu guía de las diversas instalaciones\n"
	.string "aquí en el Frente Batalla.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "¿Sobre cuál te gustaría informarte?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "Es la torre gigantesca considerada el\n"
	.string "símbolo del Frente Batalla.\p"
	.string "Hay cuatro tipos de Salas de Batalla\n"
	.string "en la torre para Batallas Simples, Dobles,\l"
	.string "Multi y Multi Link.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "La Cúpula Batalla es el gran edificio\n"
	.string "con forma de huevo gigante.\p"
	.string "Se celebran eventos llamados Torneos de\n"
	.string "Batalla en esta instalación.\p"
	.string "Los Torneos de Batalla se ofrecen en dos\n"
	.string "cursos: para Batallas Simples y Dobles.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "El Palacio Batalla es el edificio rojo\n"
	.string "a la derecha del Frente Batalla.\p"
	.string "Hay dos tipos de Salas de Batalla para\n"
	.string "Batallas Simples y Dobles.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "El Dojo Batalla es el edificio similar a\n"
	.string "un dojo a la derecha del centro del\l"
	.string "Frente Batalla.\p"
	.string "Un evento llamado Torneo KO se celebra\n"
	.string "en el Dojo Batalla.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "La Fábrica Batalla es el gran edificio\n"
	.string "más cercano a nosotros.\p"
	.string "Se lleva a cabo un evento llamado\n"
	.string "Intercambio de Batalla.\p"
	.string "El evento Intercambio de Batalla se\n"
	.string "ofrece en dos cursos para Batallas\l"
	.string "Simples y Dobles.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "La Sierpe Batalla es el edificio con forma\n"
	.string "de Pokémon a la izquierda del centro\l"
	.string "del Frente Batalla.\p"
	.string "Se lleva a cabo un evento llamado\n"
	.string "Elección de Batalla.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "La Pirámide Batalla es la enorme pirámide.\p"
	.string "Se lleva a cabo un evento llamado\n"
	.string "Búsqueda de Batalla.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "El Salón de Clasificación está ubicado\n"
	.string "cerca de la Torre Batalla.\p"
	.string "Allí, puedes ver los registros más\n"
	.string "fantásticos dejados por los entrenadores\l"
	.string "que se enfrentaron a los muchos desafíos\l"
	.string "del Frente Batalla.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "El Centro de Servicios de Intercambio está\n"
	.string "cerca de la Torre Batalla.\p"
	.string "Los Puntos de Batalla que has ganado en\n"
	.string "el Frente Batalla pueden ser intercambiados\l"
	.string "por fabulosos premios allí.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Soy tu guía de las reglas básicas que son\n"
	.string "comunes a todos los desafíos ofrecidos\l"
	.string "por las instalaciones del Frente Batalla.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "¿Sobre qué te gustaría informarte?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Todos los desafíos en las instalaciones\n"
	.string "del Frente Batalla vienen en dos cursos:\l"
	.string "Nivel 50 y Nivel Libre.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "El curso Nivel 50 está abierto a Pokémon\n"
	.string "hasta e incluyendo el nivel 50.\p"
	.string "Por favor, ten en cuenta que ningún\n"
	.string "entrenador al que te enfrentes tendrá\l"
	.string "Pokémon por debajo del nivel 50.\p"
	.string "Este curso es el nivel de entrada para\n"
	.string "los combates en el Frente Batalla.\p"
	.string "Para empezar, esperamos que desafíes\n"
	.string "este curso.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "El curso Nivel Libre no impone ningún\n"
	.string "límite en los niveles de los Pokémon\l"
	.string "que entren en los desafíos.\p"
	.string "Los niveles de tus oponentes se ajustarán\n"
	.string "para coincidir con los niveles de tus\l"
	.string "Pokémon.\p"
	.string "Sin embargo, ningún entrenador al que\n"
	.string "te enfrentes tendrá Pokémon por debajo\l"
	.string "del nivel 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Prácticamente cualquier tipo de Pokémon\n"
	.string "puede aceptar los desafíos en todas las\l"
	.string "instalaciones.\p"
	.string "Sin embargo, los Huevos y ciertos tipos\n"
	.string "de Pokémon no están permitidos.\p"
	.string "El número de Pokémon requeridos para los\n"
	.string "desafíos dependerá de la instalación.\p"
	.string "En todas las instalaciones, sin embargo,\n"
	.string "no se permiten dos o más del mismo tipo\l"
	.string "de Pokémon.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Al entrar en un desafío en una instalación\n"
	.string "del Frente Batalla, los Pokémon no pueden\l"
	.string "llevar el mismo tipo de objeto.\p"
	.string "Por favor, asegúrate de que todos los\n"
	.string "Pokémon que entren en un desafío lleven\l"
	.string "objetos diferentes.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Soy tu guía del Pase del Frente.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "¿Sobre cuál te gustaría informarte?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Hay siete instalaciones en el\n"
	.string "Frente Batalla.\p"
	.string "Los entrenadores que ganen reconocimiento\n"
	.string "por sus habilidades pueden ser recompensados\l"
	.string "con símbolos de cada una de las\l"
	.string "instalaciones.\p"
	.string "Para ganar un símbolo, los entrenadores\n"
	.string "pueden necesitar derrotar a otros\l"
	.string "entrenadores seguidos, y pueden necesitar\l"
	.string "ganar eventos repetidamente.\p"
	.string "Ciertamente no es fácil ganar símbolos.\n"
	.string "¡Te deseo la mejor de las suertes!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Es posible grabar una batalla en tu\n"
	.string "Pase del Frente.\p"
	.string "Puedes grabar una batalla que tuviste\n"
	.string "con un amigo o amigos.\p"
	.string "O puedes grabar una batalla llevada a\n"
	.string "cabo en el Frente Batalla excluyendo\l"
	.string "los combates en la Sierpe Batalla o la\l"
	.string "Pirámide Batalla.\p"
	.string "Puedes elegir grabar tu combate al final\n"
	.string "de una batalla.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Los Puntos de Batalla son recompensas\n"
	.string "dadas a los entrenadores que combatieron\l"
	.string "de manera destacada en el Frente Batalla.\p"
	.string "Puedes canjear tus Puntos de Batalla por\n"
	.string "premios en el Centro de Servicios de\l"
	.string "Intercambio.$"

