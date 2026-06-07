PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "El mar entre Pueblo Pacífico y Ciudad\n"
	.string "Portual tiene una corriente muy fuerte.\p"
	.string "Si decides usar Surf, podrías acabar\n"
	.string "arrastrado a otro sitio.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "¿Ves? ¿No es genial?\n"
	.string "¡Estas casas están sobre el agua!\p"
	.string "¡Yo nací aquí!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "¿El Pilar Celeste?\p"
	.string "...Ah, te refieres a esa torre muy, muy\n"
	.string "alta que está un poco más allá.\p"
	.string "Si me lo preguntas, yo no la subiría.\n"
	.string "Da demasiado miedo subir tan alto.\p"
	.string "La vida a nivel del mar en Pueblo\n"
	.string "Pacífico, eso me va de perlas.$"

PacifidlogTown_Text_TownSign:
	.string "Pueblo Pacífico\p"
	.string "“Donde el sol de la mañana sonríe\n"
	.string "sobre las aguas.”$"

