Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Eres el primer entrenador que veo que\n"
	.string "despliega Pokémon con tanta maestría.\p"
	.string "Pero, debo decirte que mi hijo es\n"
	.string "más fuerte que tú.\p"
	.string "Incluso tomó el desafío de la\n"
	.string "Liga Pokémon, que conste.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Usamos este BRAZO MACHO para fortalecer\n"
	.string "a nuestros Pokémon de forma más\l"
	.string "efectiva durante el entrenamiento.\p"
	.string "Como nos has vencido a todos aquí,\n"
	.string "no sé si lo necesitas, pero nos\l"
	.string "gustaría que te quedaras con nuestro\l"
	.string "BRAZO MACHO.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Cuando se trata de combates Pokémon,\n"
	.string "solemos ser bastante apasionados.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Mamá es más fuerte que Papá.\p"
	.string "Yo soy más fuerte que Mamá.\p"
	.string "¡Y la Abuela es más fuerte que yo!\p"
	.string "Pero mi hermano mayor es incluso más\n"
	.string "fuerte que la Abuela.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "No cabe duda de que eres fuerte.\p"
	.string "Pero si lucharas contra mi nieto,\n"
	.string "acabarías llorando de frustración.\p"
	.string "Es mucho más fuerte que cualquier\n"
	.string "entrenador que conozca nuestra familia.\p"
	.string "Debe estar desafiando al Campeón de la\n"
	.string "Liga Pokémon para estas fechas.\p"
	.string "Conociendo a mi nieto, ¡ya podría ser\n"
	.string "el Campeón!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Mi nieto debe estar desafiando al\n"
	.string "Campeón de la Liga Pokémon para\l"
	.string "estas fechas.\p"
	.string "Conociendo a mi nieto, ¡ya podría ser\n"
	.string "el Campeón!$"

