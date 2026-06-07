GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Oye, tú.\n"
	.string "Se pone muy oscuro más adelante.\l"
	.string "Será difícil intentar explorar.\p"
	.string "Ese chico que pasó antes…\n"
	.string "Máximo, creo que era.\p"
	.string "Sabía usar Destello, así que debería\n"
	.string "estar bien, pero…\p"
	.string "Bueno, para nosotros los montañeros,\n"
	.string "ayudar a los que encontramos es\l"
	.string "nuestro lema.\p"
	.string "Toma, te lo doy.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Enseña ese movimiento oculto Destello\n"
	.string "a un Pokémon y úsalo.\p"
	.string "Ilumina incluso la oscuridad más\n"
	.string "densa de las cuevas.\p"
	.string "Pero, para usarlo, necesitas la Medalla\n"
	.string "del Gimnasio de Pueblo Azuliza.$"

