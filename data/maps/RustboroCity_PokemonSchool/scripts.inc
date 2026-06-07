RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "La pizarra enumera los problemas de\n"
	.string "estado que pueden afectar a los POKéMON\l"
	.string "en combate.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "¿Sobre qué tema quieres leer?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON está envenenado, perderá\n"
	.string "PS de forma constante.\p"
	.string "Los efectos del veneno permanecen\n"
	.string "después del combate.\p"
	.string "Los PS de un POKéMON envenenado\n"
	.string "bajarán mientras viaja.\p"
	.string "Cura el envenenamiento usando un\n"
	.string "ANTÍDOTO.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON se paraliza, su\n"
	.string "VELOCIDAD disminuye.\p"
	.string "También puede ser que no pueda moverse\n"
	.string "mientras está en combate.\p"
	.string "La parálisis permanece después del\n"
	.string "combate. Cúrala usando un ANTIPARALIZ.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON se duerme, será incapaz\n"
	.string "de atacar.\p"
	.string "Un POKéMON puede despertarse por sí\n"
	.string "solo, pero si un combate termina\l"
	.string "mientras duerme, seguirá dormido.\p"
	.string "Despiértalo usando un DESPERTAR.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Una quemadura reduce el poder de\n"
	.string "ATAQUE, y reduce los PS de la víctima\l"
	.string "de forma constante.\p"
	.string "Una quemadura persiste después del\n"
	.string "combate. Cura una quemadura usando\l"
	.string "ANTIQUM.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Si un POKéMON se congela, queda\n"
	.string "completamente indefenso.\p"
	.string "Permanecerá congelado después del\n"
	.string "combate. Descongélalo usando un\l"
	.string "ANTIHIELO.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Los estudiantes que no estudian reciben\n"
	.string "un pequeño castigo de mi GARRA RÁPIDA.\p"
	.string "Si eres un buen estudiante o no se\n"
	.string "verá en la forma en que uses este\l"
	.string "objeto.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON que lleve la GARRA RÁPIDA\n"
	.string "ocasionalmente acelerará y podrá\l"
	.string "moverse antes que su oponente.\p"
	.string "Hay muchos otros objetos destinados a\n"
	.string "ser llevados por POKéMON.\p"
	.string "Solo con esos tendrás muchos temas\n"
	.string "para estudiar.$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Estoy intercambiando POKéMON con mi\n"
	.string "amigo ahora mismo.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Siempre quise un SEEDOT, y ¡por fin\n"
	.string "voy a conseguir uno!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Los POKéMON pueden llevar objetos,\n"
	.string "pero no saben qué hacer con objetos\l"
	.string "fabricados por humanos como POCIÓN y\l"
	.string "ANTÍDOTO.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "¿Sabes que algunos movimientos POKéMON\n"
	.string "pueden confundir a un POKéMON?\p"
	.string "Un POKéMON confundido a veces se\n"
	.string "atacará a sí mismo sin querer.\p"
	.string "Pero una vez que abandone el combate,\n"
	.string "volverá a la normalidad.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON que lleve una BAYA se\n"
	.string "curará a sí mismo…\p"
	.string "Hay muchos tipos de objetos que los\n"
	.string "POKéMON pueden llevar…\p"
	.string "Vaya, seguro que es difícil tomar\n"
	.string "apuntes…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Es el cuaderno de este estudiante…\p"
	.string "Los POKéMON se atrapan usando\n"
	.string "POKé BALLS.\p"
	.string "Hasta seis POKéMON pueden acompañar a\n"
	.string "un ENTRENADOR.\p"
	.string "Un ENTRENADOR es alguien que atrapa\n"
	.string "POKéMON, los cría y combate con ellos.\p"
	.string "La misión de un ENTRENADOR es derrotar\n"
	.string "a los fuertes ENTRENADORES que esperan\l"
	.string "a los retadores en los GIMNASIOS\l"
	.string "POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "¿Hola? ¿No nos hemos visto antes?\n"
	.string "Creo que en CIUDAD PETALIA.\p"
	.string "Déjame presentarme.\n"
	.string "Me llamo TRETO.\p"
	.string "He estado viajando por todas partes en\n"
	.string "busca de ENTRENADORES sobresalientes.\p"
	.string "Más concretamente, busco expertos en\n"
	.string "combates POKéMON.\p"
	.string "Entonces, ¿qué te trae a esta ESCUELA?\n"
	.string "¿También eres ENTRENADOR?\p"
	.string "Lo primero que deberías hacer es\n"
	.string "enseñarle a un POKéMON el movimiento\l"
	.string "CORTE.\p"
	.string "Si no recuerdo mal, alguien en este\n"
	.string "pueblo tiene CORTE.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "TRETO: Mmm…\p"
	.string "El nivel de talento de los estudiantes\n"
	.string "aquí es desconocido. El potencial está\l"
	.string "ahí.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "TRETO: ¿Oh, qué es eso?\p"
	.string "Es una MEDALLA PIEDRA, ¿verdad?\n"
	.string "Eso es bastante impresionante, diría yo.\p"
	.string "Pero, ya sabes, me habría encantado ver\n"
	.string "como combatías.\p"
	.string "Es difícil saber cómo eres como\n"
	.string "ENTRENADOR solo por una MEDALLA DE\l"
	.string "LIGA.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "¿Hola? ¿No nos hemos visto antes?\n"
	.string "Creo que en CIUDAD PETALIA.\p"
	.string "Déjame presentarme.\n"
	.string "Me llamo TRETO.\p"
	.string "He estado viajando por todas partes en\n"
	.string "busca de ENTRENADORES sobresalientes.\p"
	.string "Más concretamente, busco expertos en\n"
	.string "combates POKéMON.\p"
	.string "¿Oh, qué es eso?\n"
	.string "Es una MEDALLA PIEDRA, ¿verdad?\p"
	.string "Eso es bastante impresionante, diría yo,\n"
	.string "para un ENTRENADOR novato como tú.\p"
	.string "Pero, ya sabes, me habría encantado ver\n"
	.string "como combatías.\p"
	.string "Es difícil saber cómo eres como\n"
	.string "ENTRENADOR solo por una MEDALLA DE\l"
	.string "LIGA.$"

