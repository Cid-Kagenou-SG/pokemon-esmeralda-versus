@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Este Pokémon ya ganó el Concurso\n"
	.string "de Belleza aquí.\p"
	.string "¿Y sabes qué? ¡Hoy le he hecho\n"
	.string "ganar el Concurso de Ingenio!\p"
	.string "Mis habilidades me asustan\n"
	.string "incluso a mí…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "He participado en un montón de\n"
	.string "Concursos, así que ya me sé el truco.\p"
	.string "Si estás en un Concurso de Carisma,\n"
	.string "los movimientos de tipo Carisma\l"
	.string "quedan muy bien.\p"
	.string "Pero los movimientos de Dulzura o\n"
	.string "de Ingenio no caen tan bien, por ejemplo.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Ese chico que ganó antes tenía un\n"
	.string "montón de PokéCubos diferentes.\p"
	.string "¿Se podrá ganar si tienes tantos\n"
	.string "de esos?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "¡Vaya, este sitio es enorme!\p"
	.string "La tensión que se respira… No se\n"
	.string "parece en nada a un Salón de\l"
	.string "Concursos de un pueblo perdido.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "PRESENTADOR: ¡Vale, entrenadores\n"
	.string "de Pokémon de tipo Ingenio, estáis\l"
	.string "listos?!\p"
	.string "¡Dad lo mejor de vosotros!\n"
	.string "¡A lucirse!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JUEZ: ¿Os está gustando el Concurso?\p"
	.string "¡Volved con tres amigos y todos\n"
	.string "podréis participar en un Concurso!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ay, ay, ay, ay…\n"
	.string "Me he apuntado al Concurso equivocado.\p"
	.string "He inscrito a este Pokémon tan duro\n"
	.string "en el Concurso de Ingenio…\p"
	.string "Venga, impresiónalos con un\n"
	.string "Demolición que parezca inteligente.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "He pasado muchos años, y toda mi\n"
	.string "sabiduría, criando a este Pokémon\l"
	.string "para que fuera listo.\p"
	.string "No será fácil que lo supere el\n"
	.string "Pokémon de un mocoso.\p"
	.string "Mi querida esposa, ¿lo estás viendo?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "¡Ahí está!\p"
	.string "¡Si mi Pokémon hace un movimiento de\n"
	.string "Ingenio ahora, el público se volverá\l"
	.string "loco!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "¡Oh, por favor, no!\p"
	.string "El Chupavidas de mi querido ZUBAT\n"
	.string "es tan mono que no paraba de usarlo.\p"
	.string "¡Pero esta gente mala no lo aprecia\n"
	.string "en absoluto!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "¡Kiyaaaah! ¡Eres precioso, abuelo!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Aunque los entrenadores inscriban el\n"
	.string "mismo tipo de Pokémon, todos parecen\l"
	.string "usar movimientos diferentes para\l"
	.string "lucirse.\p"
	.string "Es como cuando la gente tiene\n"
	.string "diferentes estilos para luchar.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Creo que los Pokémon parecen más\n"
	.string "listos que sus entrenadores. Y con\l"
	.string "mucho.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Al fin y al cabo, sigo amando los\n"
	.string "Concursos de Ingenio.\p"
	.string "Ese verde intelectual…\n"
	.string "Es tan… Tan… Genial.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "PRESENTADOR: ¿También te apuntas al\n"
	.string "Concurso de Belleza? ¡Buena suerte!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JUEZ: ¡Ah, cada Pokémon aquí es un\n"
	.string "modelo de belleza intacta!\p"
	.string "¡Vaya, casi me olvido de puntuarlos!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un Pokémon tan bello…\n"
	.string "No hay otro igual.\p"
	.string "Los ojos de todos se clavarán en\n"
	.string "mi belleza.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "¡Waaaah!\p"
	.string "He cepillado y arreglado a mi Pokémon\n"
	.string "con mucho cuidado para este Concurso…\p"
	.string "Pero me he pasado…\n"
	.string "El pelaje de mi Pokémon se ha\l"
	.string "quedado todo desaliñado…\p"
	.string "¿Qué hago?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Este Rayo Aurora es tan deslumbrante\n"
	.string "que el JUEZ no podrá verlo.\p"
	.string "Eh, espera un segundo…\n"
	.string "¡Entonces no tendría sentido!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Este Pokémon tan mono se parece a mí\n"
	.string "cuando era joven.\p"
	.string "En cuanto lo he dicho, mi marido se\n"
	.string "ha atragantado con el café que estaba\l"
	.string "bebiendo.\p"
	.string "¿He dicho algo gracioso?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "¿Sabes? Si gano un Concurso de\n"
	.string "Belleza, claro que me hace feliz.\l"
	.string "Más de lo normal, eso sí.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "¡Wahahahah!\p"
	.string "¿Vas a echar un vistazo a todos\n"
	.string "esos Pokémon tan guapos?\l"
	.string "¡Me encanta este tipo de lujo!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "No siempre se puede ganar solo con\n"
	.string "belleza.\p"
	.string "Tienes que cepillar a tu Pokémon para\n"
	.string "que esté bonito y brillante como el\l"
	.string "mío.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "PRESENTADOR: ¡Oh-oh! ¡Hola!\n"
	.string "¡Estamos en medio de un Concurso!\p"
	.string "Por favor, apúntate en nuestro\n"
	.string "mostrador de inscripciones y ven,\l"
	.string "¿vale?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JUEZ: ¡Oh, qué exhibiciones tan\n"
	.string "encantadoras y monas!\p"
	.string "¡Oh, Dios mío! ¡Qué exhibición de\n"
	.string "Deporte Acuático tan adorable!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, no… Mi dulce AZURILL se ha\n"
	.string "distraído con otro Pokémon.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Mi Pokémon nunca ha ganado en un\n"
	.string "combate, pero ¡mételo en un Concurso\l"
	.string "y míralo!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "El Danza Pétalo de mi Pokémon es una\n"
	.string "maravilla de elegancia.\p"
	.string "No dejaré que nadie perturbe su\n"
	.string "actuación.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Los Pokémon de todos son muy monos.\p"
	.string "Sin embargo, si mi Pokémon hiciera\n"
	.string "una exhibición de Dulzura…\p"
	.string "Estoy seguro de que sería mucho más\n"
	.string "mono que los demás.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mi hijo está en este Concurso.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "¡Vamos, cariño. Tú puedes!\n"
	.string "¡Tu Pokémon es el mejor!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Creo que esa chica de allí es la más\n"
	.string "mona de todas.\p"
	.string "¿Qué dices? ¿Que están juzgando a\n"
	.string "los Pokémon por su aspecto?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Oh, ver todos esos Pokémon tan monos\n"
	.string "me dan ganas de tener uno.\p"
	.string "¡Voy a ir a atrapar algunos!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "ESCENARIO DEL CONCURSO DE BELLEZA\n"
	.string "¡DEJATE SEDUCIR POR LA BELLEZA!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "ESCENARIO DEL CONCURSO DE DULZURA\n"
	.string "¡ENCANTATE CON LA DULZURA!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "ESCENARIO DEL CONCURSO DE INGENIO\n"
	.string "¡IMPRESIONATE CON EL INGENIO!$"

