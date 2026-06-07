Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Ese TÚNEL FERVEGAL de ahí…\p"
	.string "Al principio, teníamos un enorme equipo\n"
	.string "de trabajo perforando roca con la\l"
	.string "maquinaria más moderna. Pero tuvimos\l"
	.string "que detenernos.\p"
	.string "Resulta que tendríamos un efecto\n"
	.string "negativo en los POKéMON salvajes de la\l"
	.string "zona.\p"
	.string "Así que no nos queda más que\n"
	.string "holgazanear aquí sin hacer nada.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Hay un hombre cavando su camino hacia\n"
	.string "VERDEGAL completamente solo.\l"
	.string "Está desesperado por abrirse paso.\p"
	.string "Dice que si cava poquito a poco sin\n"
	.string "usar máquinas, no molestará a los\l"
	.string "POKéMON, y evitará dañar el entorno\l"
	.string "natural.\p"
	.string "Me pregunto si ya habrá conseguido\n"
	.string "atravesarlo.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Para ir a VERDEGAL sin usar este\n"
	.string "TÚNEL, tendrías que cruzar el mar hasta\l"
	.string "AZULIZA, navegar hasta PORTUAL, y luego\l"
	.string "viajar por MALVALONA.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "¿Has oído? ¡El TÚNEL a VERDEGAL ha\n"
	.string "sido perforado!\p"
	.string "A veces, si esperas con suficiente\n"
	.string "fuerza, los sueños se hacen realidad.$"

