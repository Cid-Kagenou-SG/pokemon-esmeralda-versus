MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Si tuviera una BICI, ir a CIUDAD PORTUAL\n"
	.string "a comprar sería pan comido.\p"
	.string "Podría comprar una CARTA PUERTO en la\n"
	.string "TIENDA POKéMON de CIUDAD PORTUAL…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "¡Oh! ¿Tienes una CARTA PUERTO?\n"
	.string "¿Quieres cambiarla por una CAJA FICHAS?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "¡Oh, estoy tan contento!\n"
	.string "¡Vale, te cambio la CAJA FICHAS!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Esa CAJA FICHAS se puede usar\n"
	.string "en el CASINO.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, qué pena.\p"
	.string "Se necesita una CAJA FICHAS para\n"
	.string "jugar en el CASINO.$"

