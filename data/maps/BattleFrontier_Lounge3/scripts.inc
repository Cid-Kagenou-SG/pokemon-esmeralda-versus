BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "…¿Qué quieres?\p"
	.string "¿No ves que estamos bastante ocupados\n"
	.string "aquí? ¿No puede esperar tu asunto\l"
	.string "hasta más tarde?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…¿Eh?\n"
	.string "Tú me pareces un entrenador duro.\p"
	.string "Je, je…\n"
	.string "Escucha, tengo una propuesta.\p"
	.string "Tenemos un pequeño grupo aquí, y\n"
	.string "jugamos un pequeño juego con lo que\l"
	.string "pasa en el Frente Batalla.\p"
	.string "Las reglas son realmente sencillas.\p"
	.string "Primero, elegimos una de las\n"
	.string "instalaciones del Frente Batalla.\p"
	.string "Luego, cada uno elegimos un entrenador\n"
	.string "diferente que esté aceptando el desafío\l"
	.string "de esa instalación, y apostamos con\l"
	.string "nuestros Puntos de Batalla.\p"
	.string "El tipo que apostó por el entrenador\n"
	.string "con el mejor récord se lleva todos los\l"
	.string "Puntos de Batalla del bote.\p"
	.string "Suena sencillo, ¿eh?\n"
	.string "Así que, en fin…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a desafiar las Salas de Batalla Simple\l"
	.string "de la Torre Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a desafiar las Salas de Batalla Doble\l"
	.string "de la Torre Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a desafiar las Salas de Batalla Multi\l"
	.string "de la Torre Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a participar en el Torneo de Batalla\l"
	.string "Simple de la Cúpula Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a participar en el Torneo de Batalla\l"
	.string "Doble de la Cúpula Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a participar en el Torneo de Intercambio\l"
	.string "de Batalla Simple de la Fábrica Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a participar en el Torneo de Intercambio\l"
	.string "de Batalla Doble de la Fábrica Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a desafiar las Salas de Batalla Simple\l"
	.string "del Palacio Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a desafiar las Salas de Batalla Doble\l"
	.string "del Palacio Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a participar en el Torneo KO del Dojo\l"
	.string "Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a participar en la Elección de Batalla\l"
	.string "de la Sierpe Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Lo que busco es un entrenador que vaya\n"
	.string "a participar en la Búsqueda de Batalla\l"
	.string "de la Pirámide Batalla.\p"
	.string "Pero hasta ahora, no he visto a un\n"
	.string "entrenador que tenga esa cualidad\l"
	.string "ganadora.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Me encargaré de que tú también te\n"
	.string "beneficies.\p"
	.string "Así que, ¿qué tal?\n"
	.string "¿Qué tal si participas en ese evento\l"
	.string "por mí?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Muy bien, eso es perfecto.\n"
	.string "Así que, eh… ¿Qué tal si me prestas\l"
	.string "algunos de tus Puntos de Batalla?\p"
	.string "Confía en mí, te mostraré mi gratitud\n"
	.string "después.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Genial, genial.\n"
	.string "Así que, ¿cuánto puedes prestarme?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, no, no, no.\n"
	.string "¡No tienes suficientes Puntos de\l"
	.string "Batalla!\p"
	.string "Ojalá no hicieras el tonto y no\n"
	.string "perdieras el tiempo de todos.$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "¡Je, je! Muchas gracias.\n"
	.string "Así que, ¡vamos allá!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "¡Ve a las Salas de Batalla Simple de\n"
	.string "la Torre Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "¡Ve a las Salas de Batalla Doble de\n"
	.string "la Torre Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "¡Ve a las Salas de Batalla Multi de\n"
	.string "la Torre Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "¡Ve al Torneo de Batalla Simple de la\n"
	.string "Cúpula Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "¡Ve al Torneo de Batalla Doble de la\n"
	.string "Cúpula Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "¡Ve al Torneo de Intercambio de Batalla\n"
	.string "Simple de la Fábrica Batalla cuanto\l"
	.string "antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "¡Ve al Torneo de Intercambio de Batalla\n"
	.string "Doble de la Fábrica Batalla cuanto\l"
	.string "antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "¡Ve a las Salas de Batalla Simple del\n"
	.string "Palacio Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "¡Ve a las Salas de Batalla Doble del\n"
	.string "Palacio Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "¡Ve al Torneo KO del Dojo Batalla\n"
	.string "cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "¡Ve a la Elección de Batalla de la\n"
	.string "Sierpe Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "¡Ve a la Búsqueda de Batalla de la\n"
	.string "Pirámide Batalla cuanto antes!\p"
	.string "¡Es una situación de victoria obligada!\n"
	.string "¡No la cagues!\l"
	.string "¡Ambos futuros dependen de ti!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, eres tú…\n"
	.string "Buen intento…\p"
	.string "Odio decírtelo, pero no puedo devolverte\n"
	.string "tus Puntos de Batalla…\p"
	.string "Supongo que tendremos que dejar que nos\n"
	.string "motiven para esforzarnos más la próxima\l"
	.string "vez.$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "¡Oh, sí!\n"
	.string "¡Hola, campeón!\p"
	.string "¡Sabía que podías!\n"
	.string "¡Sabía que lo harías!\l"
	.string "¡Ambos somos grandes ganadores!\p"
	.string "Te devolveré tus Puntos de Batalla y,\n"
	.string "por supuesto, un pequeño extra de mi\l"
	.string "parte.$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} obtuvo\n"
	.string "{STR_VAR_1} Puntos de Batalla.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Si te apetece otro desafío,\n"
	.string "¡por favor, piensa en mí!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "¿No te interesa? No deberías tener\n"
	.string "tanto miedo de arriesgarte.$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "¡He apostado por el entrenador\n"
	.string "equivocado otra vez!\p"
	.string "Quizá debería estar luchando\n"
	.string "normalmente como todo el mundo…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Ese entrenador…\p"
	.string "Es bueno, pero se pone nervioso\n"
	.string "demasiado fácilmente para sobrevivir\l"
	.string "en la Cúpula Batalla…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "¡Ji, ji!\n"
	.string "¡Sé reconocer a un ganador cuando lo\l"
	.string "veo!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Esos entrenadores…\n"
	.string "¿Qué están haciendo?\l"
	.string "Deberían estar aceptando desafíos.$"
