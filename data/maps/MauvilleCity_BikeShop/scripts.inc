MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Vaya, vaya, ¿qué tenemos aquí?\n"
	.string "¡Un cliente con mucha energía!\p"
	.string "¿Yo? Puedes llamarme RODOLFO.\n"
	.string "Soy el dueño de esta tienda de bicicletas.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RODOLFO: Tus zapatillas para correr…\n"
	.string "Están terriblemente sucias.\p"
	.string "¿Has venido de muy lejos?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RODOLFO: ¿Es eso cierto?\p"
	.string "Entonces, supongo que no necesitas\n"
	.string "ninguna de mis BICIS.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RODOLFO: Mmm, mmm… … … … …\p"
	.string "¿Dices que has venido hasta aquí desde\n"
	.string "VILLA RAÍZ?\p"
	.string "¡Vaya!\n"
	.string "¡Eso es una barbaridad de lejos!\p"
	.string "Si tuvieras una de mis BICIS, podrías ir\n"
	.string "a cualquier parte fácilmente mientras\l"
	.string "sientes la suave caricia del viento.\p"
	.string "¡Te lo digo yo!\n"
	.string "¡Te daré una BICI!\p"
	.string "Oh, ¡espera un segundo!\p"
	.string "¡Olvidé decirte que hay dos tipos de\n"
	.string "BICIS!\p"
	.string "¡Son la BICI CARRERA y\n"
	.string "la BICI ACRO!\p"
	.string "¡La BICI CARRERA es para ciclistas que\n"
	.string "quieren sentir el viento con su cuerpo!\p"
	.string "¡Y una BICI ACRO es para quienes\n"
	.string "prefieren montar con técnica!\p"
	.string "Soy un verdadero encanto, así que puedes\n"
	.string "quedarte con la que más te guste.\p"
	.string "¿Cuál eliges?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} eligió la BICI CARRERA.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} eligió la BICI ACRO.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RODOLFO: Si te entra el gusanillo de\n"
	.string "cambiar de BICI, ¡ven a verme!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RODOLFO: ¿Oh? ¿Estabas pensando en\n"
	.string "cambiar de BICI?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RODOLFO: ¡Vale, no hay problema!\n"
	.string "¡Te cambio la BICI!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} cambió la BICI CARRERA por\n"
	.string "una BICI ACRO.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} cambió la BICI ACRO por\n"
	.string "una BICI CARRERA.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RODOLFO: ¡Bien, bien!\n"
	.string "¡Me alegra que te guste!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "¿Oh? ¿Qué ha pasado con la BICI que te\n"
	.string "di?\p"
	.string "Oh, ya entiendo, la guardaste usando tu PC.\p"
	.string "Bueno, sácala del almacenamiento del PC,\n"
	.string "¡y estaré encantado de cambiártela!\p"
	.string "¡Que el viento siempre esté a tu favor en\n"
	.string "tu aventura!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Estoy aprendiendo sobre BICIS mientras\n"
	.string "trabajo aquí.\p"
	.string "Si necesitas consejos sobre cómo montar\n"
	.string "tu BICI, hay un par de manuales al fondo.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Es un manual sobre la BICI CARRERA.\p"
	.string "¿Qué página quieres leer?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "La BICI se mueve en la dirección en que\n"
	.string "se presiona la cruz de control.\p"
	.string "Una vez que empieza a rodar, acelerará.\p"
	.string "Para detenerla, suelta la cruz de control.\n"
	.string "La BICI irá frenando hasta pararse.\p"
	.string "¿Quieres leer otra página?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "La BICI CARRERA es rápida, pero no puede\n"
	.string "frenar muy rápido.\p"
	.string "Se complica un poco para tomar curvas.\p"
	.string "Suelta la cruz de control un poco antes\n"
	.string "de la curva y reduce la velocidad.\p"
	.string "¿Quieres leer otra página?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Hay pequeñas pendientes de arena\n"
	.string "por toda la región de HOENN.\p"
	.string "La arena suelta y desmenuzada hace\n"
	.string "imposible subir normalmente.\p"
	.string "Pero si tienes una BICI CARRERA, puedes\n"
	.string "subir a toda velocidad por una pendiente\l"
	.string "de arena.\p"
	.string "¿Quieres leer otra página?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Es un manual sobre la BICI ACRO.\p"
	.string "¿Qué página quieres leer?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Presiona el botón B mientras montas,\n"
	.string "y la rueda delantera se levanta.\p"
	.string "Puedes rodar con la rueda delantera\n"
	.string "arriba usando la cruz de control.\p"
	.string "Esta técnica se llama caballito.\p"
	.string "¿Quieres leer otra página?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Manteniendo presionado el botón B,\n"
	.string "tu BICI puede saltar en el sitio.\p"
	.string "Esta técnica se llama salto conejito.\p"
	.string "También puedes montar mientras saltas.\p"
	.string "¿Quieres leer otra página?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Presiona el botón B y la cruz de control\n"
	.string "al mismo tiempo para saltar.\p"
	.string "Presiona la cruz de control hacia los\n"
	.string "lados para saltar de lado.\p"
	.string "Presiónala hacia atrás para hacer que la\n"
	.string "BICI cambie de dirección mientras salta.\p"
	.string "¿Quieres leer otra página?$"

