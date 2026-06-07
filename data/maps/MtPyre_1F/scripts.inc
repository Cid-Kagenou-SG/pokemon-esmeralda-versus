MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Todo tipo de seres deambulan por las\n"
	.string "laderas del Monte Pírico…\p"
	.string "No se sabe qué puede pasar.\n"
	.string "Toma esto. Es por tu propio bien.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Haz que un Pokémon lleve equipada esa\n"
	.string "Amuleto.\p"
	.string "Ayudará a ahuyentar a los Pokémon\n"
	.string "salvajes.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "¿Has venido a rendir homenaje a los\n"
	.string "espíritus de los Pokémon fallecidos?\p"
	.string "Debes querer mucho a tus Pokémon.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Este es el lugar de descanso final de mi\n"
	.string "Zigzagoon. Lo quería mucho…$"

