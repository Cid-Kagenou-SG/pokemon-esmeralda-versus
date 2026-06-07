SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Mmm… Si esto va aquí, y eso va allá…\p"
	.string "Entonces, ¿dónde va esta cosa?\n"
	.string "¿Y qué hay de ese cacharro?\p"
	.string "¡Aaarg! ¡No le encuentro ni pies ni\n"
	.string "cabeza!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "¿Mmm?\n"
	.string "Hola, soy MUELLE.\p"
	.string "El CAPITÁN BABOR me encargó diseñar\n"
	.string "un ferry.\p"
	.string "¡Oh! Eso de ahí…\n"
	.string "¿Son PRODUCTOS DEVON?\p"
	.string "Pero, mmm…\n"
	.string "Eso no servirá…\p"
	.string "El CAPITÁN BABOR se ha ido a algún\n"
	.string "sitio. Dijo que tenía algo de trabajo\l"
	.string "que hacer.\p"
	.string "¿Podrías ir a buscar al CAPITÁN BABOR\n"
	.string "y entregarle eso?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "MUELLE: ¿Dónde se habrá metido el\n"
	.string "CAPITÁN BABOR?\p"
	.string "¿Podrías ir a buscar al CAPITÁN BABOR\n"
	.string "y entregarle ese paquete?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "MUELLE: La construcción naval es un arte.\p"
	.string "Muchas cosas no se pueden resolver solo\n"
	.string "con cálculos.\p"
	.string "Realmente me vendría bien el consejo de\n"
	.string "un veterano que conozca los mares…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "MUELLE: ¡Hola! El SR. ARENQUE se ha\n"
	.string "unido a nosotros para echarnos una mano.\p"
	.string "Gracias al veterano marinero, el ferry\n"
	.string "está tomando forma poco a poco.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "MUELLE: ¡El ferry por fin está listo!\p"
	.string "¡El nuevo S.S. TITAL es verdaderamente\n"
	.string "una maravilla de la tecnología!\p"
	.string "Pero, tengo la sensación de que podemos\n"
	.string "hacer algo aún mejor.\p"
	.string "Ya sabes, el avance de la tecnología\n"
	.string "nunca termina.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "SR. ARENQUE: ¡Ah, {PLAYER}{KUN}!\n"
	.string "¡Cuánto tiempo!\p"
	.string "¡Arrr, desde que te conocí, este viejo\n"
	.string "lobo de mar se ha sentido lleno de energía!\p"
	.string "Así que he decidido ayudar a MUELLE a\n"
	.string "hacer un ferry.\p"
	.string "¡Arrr, después de todo, un ferry podría\n"
	.string "transportar a mucha gente.\p"
	.string "Pero, ya sabes, ese MUELLE es realmente\n"
	.string "alguien especial.\p"
	.string "Con su don para la tecnología y mi\n"
	.string "experiencia, estoy seguro de que podemos\l"
	.string "construir un gran barco, ¡arr!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Las estaciones, el tiempo, dónde se sitúa\n"
	.string "la luna en el cielo…\p"
	.string "Estas y otras condiciones hacen que el mar\n"
	.string "cambie de expresión.\p"
	.string "¡Así es!\n"
	.string "¡El mar es como un ser vivo!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Me mareo en el mar con mucha facilidad.\n"
	.string "Así que me toca ayudar aquí en su lugar.$"
