FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "¡Wrooooaaar! ¡Lo necesito!\n"
	.string "¡Tengo que conseguir un {STR_VAR_1}!\l"
	.string "¡Haré lo que sea por él!\p"
	.string "…Uh… ¿Has oído eso?\n"
	.string "¿Mi grito desde el fondo de mi corazón?\p"
	.string "Habiéndolo oído, intercambiarás tu\n"
	.string "{STR_VAR_1} por mi {STR_VAR_2},\l"
	.string "¿verdad?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "¡Oh, sí, claro que sí!\p"
	.string "¡{STR_VAR_1}, bienvenido!\n"
	.string "¡{STR_VAR_2}, cuídate!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Uh, no, no lo creo.\n"
	.string "Ese no es un {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "¿No? ¿No me lo intercambias?\n"
	.string "¿Incluso después de que te haya\l"
	.string "abierto mi corazón?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "¡Voy a hacer que Volbeat sea super\n"
	.string "fuerte desde este momento!\p"
	.string "¡Espero que hagas lo mismo con Plusle!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Intercambiar Pokémon con otros…\p"
	.string "Es como si estuvieras intercambiando\n"
	.string "tus propios recuerdos con otras personas.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: ¿Zebraa?$"

