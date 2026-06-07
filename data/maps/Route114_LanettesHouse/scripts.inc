Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: ¡Anda! ¡{PLAYER}{KUN}!\p"
	.string "Perdona que esté todo tan desordenado…\n"
	.string "Cuando me absorbe la investigación,\l"
	.string "las cosas acaban así…\p"
	.string "Me da mucha vergüenza… Por favor, no\n"
	.string "se lo digas a nadie. Y, como pago por tu\l"
	.string "silencio, toma esto.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "¿Puedo darte un consejo sobre mi\n"
	.string "Sistema de Almacenamiento de POKéMON?\p"
	.string "Deberías organizar tus CAJAS para que\n"
	.string "puedas saber qué POKéMON hay en cada una.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Son las notas de investigación de LANETTE.\n"
	.string "Hay información sobre las CAJAS.\p"
	.string "Diseñar CAJAS con capacidad para 30 POKéMON.\p"
	.string "Cada ENTRENADOR debería poder almacenar\n"
	.string "420 POKéMON en el sistema del PC.\p"
	.string "¿Sigues leyendo?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Añadir un sistema de marcas para que\n"
	.string "sea más fácil organizar los POKéMON.\p"
	.string "Hacer que se puedan cambiar el nombre y el\n"
	.string "diseño del fondo de cada CAJA para que los\l"
	.string "POKéMON almacenados se sientan a gusto.\p"
	.string "¿Sigues leyendo?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Al almacenar un POKéMON, este debe\n"
	.string "enviarse a la última CAJA consultada.\p"
	.string "Si esa CAJA está llena, el POKéMON recibido\n"
	.string "se almacena en la siguiente CAJA.\p"
	.string "En otras palabras, cuando se consulta una\n"
	.string "CAJA, se selecciona automáticamente como\l"
	.string "la CAJA a la que se envían los POKéMON.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} cerró el cuaderno.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Hay un correo electrónico de alguien en\n"
	.string "el PC.\p"
	.string "“… … … … … … …\p"
	.string "“Tu Sistema de Almacenamiento ofrece más\n"
	.string "comodidad que el mío.\p"
	.string "“Tiene muchas funciones fáciles de usar\n"
	.string "que también lo hacen divertido y útil.\p"
	.string "“Me enorgullece haber participado\n"
	.string "en su desarrollo.\p"
	.string "“Espero que sigas investigando\n"
	.string "Sistemas de Almacenamiento.\p"
	.string "“De BILL\n"
	.string "… … … … … … … …”$"

