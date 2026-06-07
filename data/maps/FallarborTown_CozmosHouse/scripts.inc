FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COSMO: Oh…\n"
	.string "Nunca debería haberme dejado engañar\l"
	.string "para decirle al Equipo Magma dónde se\l"
	.string "pueden encontrar Meteoritos…\p"
	.string "Ese Meteorito de la Cascada Meteoro…\n"
	.string "Nunca será mío ahora…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "¡Oh!\n"
	.string "¿Eh?\p"
	.string "Ese objeto…\p"
	.string "¿Podría ser?\p"
	.string "¿Es el Meteorito que el Equipo Magma\n"
	.string "tomó de la Cascada Meteoro?\p"
	.string "Por favor, ¿puedo quedármelo?\p"
	.string "No te lo pido gratis.\n"
	.string "¿Qué tal a cambio de esta MT?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COSMO: Esta MT representa mi\n"
	.string "sentimiento de gratitud.\l"
	.string "¡Por favor, úsala!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COSMO: Oh, no puedo creerlo.\n"
	.string "¡Esto es realmente, realmente genial!\p"
	.string "¡Esto realmente va a ayudar a mi\n"
	.string "investigación!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COSMO: Oh, pero…\n"
	.string "Estoy aplastado por la decepción…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COSMO: Por favor, ¿puedo quedarme\n"
	.string "ese Meteorito?\p"
	.string "No te lo pido gratis.\n"
	.string "¿Qué tal a cambio de esta MT?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "El Prof. Cosmo se fue a la Cascada\n"
	.string "Meteoro en la Ruta 114 con algunas\l"
	.string "personas del Equipo Magma.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Pobre Prof. Cosmo…\n"
	.string "Está tan deprimido… Me da pena.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Mira al Prof. Cosmo…\n"
	.string "¡Está tan feliz! Creo que es adorable.$"

