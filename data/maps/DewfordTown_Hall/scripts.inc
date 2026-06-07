DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "¿Qué está de moda? ¡Tiene que ser\n"
	.string "“{STR_VAR_1}”!\p"
	.string "¡No me puedo imaginar la vida sin\n"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "¿Qué está de moda? ¡Tiene que ser\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Pero me estoy aburriendo un poco de ello.\p"
	.string "Debería buscar la próxima gran cosa.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Le estoy enseñando a mi Pokémon sobre\n"
	.string "“{STR_VAR_1}”,\l"
	.string "pero no va bien.\p"
	.string "Es un poco demasiado, creo.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Ahora estoy estudiando lo que está de\n"
	.string "moda: “{STR_VAR_1}”.\p"
	.string "¿Es cierto que hay un vínculo profundo\n"
	.string "entre “{STR_VAR_1}”\l"
	.string "y “{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "¡Oh!\n"
	.string "¡Así que mi corazonada era correcta!\p"
	.string "Estoy un paso más cerca de estar a la\n"
	.string "moda y ser popular, ¡vamos!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "¿Qué?!\n"
	.string "¿Es así?!\p"
	.string "¡No es fácil para un tipo mayor como yo\n"
	.string "mantenerse al día con las modas!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Todo este asunto sobre\n"
	.string "“{STR_VAR_1}”…\l"
	.string "¿No hay un programa de televisión sobre\l"
	.string "ello?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Al otro lado del mar…\p"
	.string "¿Es “{STR_VAR_1}”\n"
	.string "aún más popular?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Colecciono merchandising oficial de\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Tengo muñecos oficiales de\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Ropa de marca oficial de\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Y libros de imágenes con licencia\n"
	.string "oficial de “{STR_VAR_1}”.\p"
	.string "Je, je, ¡son míos!\n"
	.string "¡No comparto nada contigo!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "IDENTIFICANDO BUEN\n"
	.string "“{STR_VAR_1}” Y\l"
	.string "MALO “{STR_VAR_1}”…\p"
	.string "EL VÍNCULO ENTRE\n"
	.string "“{STR_VAR_1}” Y\l"
	.string "LOS POKÉMON…\p"
	.string "“{STR_VAR_1}”\n"
	.string "ÚTIL…\p"
	.string "Está lleno de libros sobre\n"
	.string "“{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“EL GRITO DE\n"
	.string "{STR_VAR_1}” es el título.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“LA SONRISA DE\n"
	.string "{STR_VAR_1}” es el título.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Se titula “EL ÚLTIMO\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Se titula “EL NACIMIENTO DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "¡Vi “{STR_VAR_1}”!\n"
	.string "¿Guay, eh?\p"
	.string "¡Es, como, lo más guay que hay!\p"
	.string "¡Fue alucinante!\n"
	.string "¡Fue lo auténtico, oh, sí!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, no, no, no.\p"
	.string "Ese supuesto\n"
	.string "“{STR_VAR_1}”\l"
	.string "que afirmas haber visto, no lo es.\p"
	.string "El artículo auténtico es mucho más…\n"
	.string "¿Cómo debería decirlo?\l"
	.string "¡Más afilado, pero más suave!\p"
	.string "Ah, no importa. ¡Es asombroso!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Oye, escucha, compuse una canción\n"
	.string "principal para “{STR_VAR_1}”.\p"
	.string "“{STR_VAR_1}”\n"
	.string "está muy de moda ahora mismo.\p"
	.string "Vale, ¡escucha!\n"
	.string "… …\p"
	.string "¡Oh!\n"
	.string "¡{STR_VAR_1}!\p"
	.string "¡Maravilloso\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Me atrevería a decir, amigo, que te\n"
	.string "conviene trabajar en tu canto antes de\l"
	.string "meterte con “{STR_VAR_1}”.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "De todos modos, como decía antes,\n"
	.string "deberíamos juntarnos y organizar una\l"
	.string "fiesta de “{STR_VAR_1}”\l"
	.string "en la isla.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "¡Oh, una idea estupenda!\p"
	.string "¡Resolverá de una vez por todas quién es\n"
	.string "el mejor en “{STR_VAR_1}”.\l"
	.string "¡Brillante, de verdad!\p"
	.string "A partir de hoy, nuestras vidas girarán\n"
	.string "alrededor de “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Pero estaba pensando…\p"
	.string "¿No estarías de acuerdo en que\n"
	.string "“{STR_VAR_1}” ha\l"
	.string "pasado de ser algo de moda a ser parte\l"
	.string "de nuestra vida diaria?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "¿Disculpa?\n"
	.string "¿Eso mucho, qué?\p"
	.string "Sin embargo, es cierto que\n"
	.string "“{STR_VAR_1}”\l"
	.string "pesa mucho en tu mente, ya sea que\l"
	.string "estés despierto o dormido.\p"
	.string "Absolutamente, ¡eres el PROFESOR de\n"
	.string "“{STR_VAR_1}”,\l"
	.string "viejo amigo!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Si tú y yo formamos un dúo, ¡seremos\n"
	.string "invencibles en todo lo relacionado con\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "¡Exacto, amigo mío!\p"
	.string "¡Seremos el DÚO\n"
	.string "“{STR_VAR_1}”!\p"
	.string "¿No es una imagen madura?\n"
	.string "¡Jajaja!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Para mí, Bomba Lodo está en la cima de\n"
	.string "la popularidad. Es el indicado.\p"
	.string "¿Eh? ¿Me estás diciendo que no sabes\n"
	.string "sobre Bomba Lodo?\p"
	.string "Eso es francamente lamentable.\n"
	.string "Te daré una.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Me encanta Bomba Lodo.\p"
	.string "Pero los Pokémon con el movimiento\n"
	.string "“{STR_VAR_1}”\l"
	.string "también están de moda.$"

