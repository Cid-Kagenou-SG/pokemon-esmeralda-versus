SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "¡Ejem! Soy el PRESIDENTE del\n"
	.string "CLUB DE FANS de POKéMON!\p"
	.string "Como PRESIDENTE, soy naturalmente\n"
	.string "el más importante.\p"
	.string "¡Nadie puede superarme cuando se trata\n"
	.string "de criar POKéMON. ¡Nadie!\p"
	.string "Bueno, déjame contarte sobre los\n"
	.string "CONCURSOS POKéMON.\p"
	.string "¡Son eventos donde puedes mostrar\n"
	.string "tus POKéMON al mundo entero!\p"
	.string "Sin embargo, se celebran en pueblos\n"
	.string "lejanos, así que no puedo participar\l"
	.string "tan a menudo como quisiera.\p"
	.string "Por eso nos reunimos aquí para mostrar\n"
	.string "nuestros POKéMON, y que otros nos\l"
	.string "muestren los suyos.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "El POKéMON de un ENTRENADOR que ha\n"
	.string "participado en un CONCURSO POKéMON…\l"
	.string "Eso me gustaría ver.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "¡Ejem! Veo que has participado en\n"
	.string "¡un CONCURSO POKéMON!\p"
	.string "¡Por favor! ¡Permíteme examinar cómo\n"
	.string "has criado a tu POKéMON.\p"
	.string "Me llena de alegría ver POKéMON criados\n"
	.string "por otros ENTRENADORES.\p"
	.string "Las expresiones felices de los POKéMON\n"
	.string "criados con el cuidado adecuado…\p"
	.string "Los ojos bondadosos del ENTRENADOR que\n"
	.string "nutrió y crió al POKéMON…\p"
	.string "Solo de pensarlo, mi corazón se llena\n"
	.string "de una alegría abrumadora.\p"
	.string "¡Oh! ¡Te pido mil disculpas!\n"
	.string "¡Perdóname por hablar tanto!\p"
	.string "¡Por favor! ¡Permíteme examinar cuánto\n"
	.string "ha crecido tu POKéMON!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "¿Cómo está creciendo tu POKéMON?\n"
	.string "Permíteme examinarlo.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Mmm, mmm…\n"
	.string "Ya veo…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmmm… No está mal, pero tampoco\n"
	.string "está bien…\p"
	.string "¡Tú, como ENTRENADOR, debes esforzarte\n"
	.string "más en criar a este POKéMON!\p"
	.string "Por ejemplo, ¿qué te parece si le das\n"
	.string "más {POKEBLOCK}S?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Oh, cielos…\p"
	.string "Tu POKéMON está creciendo muy bien,\n"
	.string "así que mereces una recompensa.\p"
	.string "Lamentablemente, no tienes espacio en\n"
	.string "la MOCHILA para esto.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "¡Tu {STR_VAR_1} está creciendo de una\n"
	.string "manera realmente impresionante!\l"
	.string "¡Es un ejemplar magnífico!\p"
	.string "¡Pero! Si le dieras esto,\n"
	.string "¡crecería aún mejor! ¡De verdad!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Haz que un POKéMON lleve ese PAÑUELO\n"
	.string "ROJO.\p"
	.string "¡Todo el mundo reconocerá el carisma\n"
	.string "de ese POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Haz que un POKéMON lleve ese PAÑUELO\n"
	.string "AZUL.\p"
	.string "¡Su belleza se acentuará mucho\n"
	.string "más que ahora!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Haz que un POKéMON lleve ese PAÑUELO\n"
	.string "ROSA.\p"
	.string "¡Resaltará aún más la dulzura\n"
	.string "del POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Haz que un POKéMON lleve ese PAÑUELO\n"
	.string "VERDE.\p"
	.string "¡Eso realzará la\n"
	.string "ingeniosidad del POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Haz que un POKéMON lleve ese PAÑUELO\n"
	.string "AMARILLO.\p"
	.string "¡Aumentará la dureza de tu POKéMON\n"
	.string "muchísimo más!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Lo siento, pero no tengo nada más que\n"
	.string "darte. ¡Nada en absoluto!\p"
	.string "Después de todo, tienes el don de criar\n"
	.string "POKéMON sin necesidad de recurrir a\l"
	.string "ningún objeto.$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "Me encanta ver POKéMON que quieren\n"
	.string "a sus ENTRENADORES.\p"
	.string "Los POKéMON son muy sensibles a los\n"
	.string "sentimientos de sus ENTRENADORES.\p"
	.string "Si tratas a tus POKéMON con cariño y\n"
	.string "atención, te querrán a cambio.\p"
	.string "Cuando tus POKéMON lleguen a quererte,\n"
	.string "por favor ven a enseñármelos.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Tu POKéMON te quiere muchísimo.\p"
	.string "Para ti, un ENTRENADOR tan compasivo,\n"
	.string "¡un regalo del CLUB DE FANS!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "Los POKéMON son muy sensibles a los\n"
	.string "sentimientos de sus ENTRENADORES.\p"
	.string "Si tratas a tus POKéMON con cariño y\n"
	.string "atención, te querrán a cambio.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Si dejas que un POKéMON se debilite\n"
	.string "constantemente en combate, empezará\l"
	.string "a odiarlo.\p"
	.string "Pronto, confiará menos en el\n"
	.string "ENTRENADOR.\p"
	.string "En otras palabras, ciertamente no le\n"
	.string "caerás muy bien.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "¿Les gusta a los POKéMON que les uses\n"
	.string "objetos?\p"
	.string "El mío se puso muy contento cuando le di\n"
	.string "PROTEÍNA.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Goooooooooooo…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: Kyuuu…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Me pica, Me pica$"

