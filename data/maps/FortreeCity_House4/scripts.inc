FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "Al estar junto a los Pokémon, la gente\n"
	.string "hace cada vez más amigos.\p"
	.string "Y eso acerca más el mundo. ¡Creo que\n"
	.string "es maravilloso!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "¡Allí!\n"
	.string "¡Vamos, Pokémon pájaro!$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Je, je, le he pedido a mi Wingull que\n"
	.string "haga un recado por mí.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "¡Bien!\n"
	.string "¡Bienvenido de vuelta, Wingull!\p"
	.string "¿Eh? ¿Qué es esto?\n"
	.string "¿Qué lleva en el pico?\p"
	.string "¿Una Hierba Mental?\n"
	.string "Debe de haberla recogido en algún sitio.\p"
	.string "Pero no soy entrenador, así que puedes\n"
	.string "quedártela tú.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Gracias a mi Wingull, tengo amigos que\n"
	.string "viven lejos.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL: ¡Ogeeer!$"

