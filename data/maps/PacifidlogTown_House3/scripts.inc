PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "¡Mira este {STR_VAR_2}!\p"
	.string "¡Es el {STR_VAR_2} que atrapé ayer\n"
	.string "para celebrar mi cumpleaños!\p"
	.string "¡Oh, veo que lo quieres!\n"
	.string "¡Después de todo, no tiene precio!\p"
	.string "Te diré algo. Quizás estaría dispuesto\n"
	.string "a cambiarlo por un {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "¿Oh, así que este es un {STR_VAR_1}?\p"
	.string "Es algo así como un {STR_VAR_2},\n"
	.string "pero es sutilmente diferente.\p"
	.string "¡Gracias!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "¡No, no, no! No aceptaré nada menos\n"
	.string "que un {STR_VAR_1} de verdad.$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "¿Oh, así que no vas a seguir adelante\n"
	.string "con esto?\p"
	.string "No pasa nada. No estoy desesperado por\n"
	.string "hacer un intercambio ni nada.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Sé que podría ir a buscar uno por mi\n"
	.string "cuenta, pero...\p"
	.string "Pero realmente quería conseguir un BAGON\n"
	.string "que otro entrenador hubiera atrapado...$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "¿Es eso una Pokédex?\p"
	.string "¿Has llegado a conocer muchos Pokémon\n"
	.string "diferentes?\p"
	.string "Ojalá fuera como tú.$"

