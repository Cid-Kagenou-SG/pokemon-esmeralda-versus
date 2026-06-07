VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Solo de pensar que me estoy acercando\n"
	.string "a la LIGA POKéMON…\p"
	.string "Me está entrando pánico escénico…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "No he podido hacer nada…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "La LIGA POKéMON se ha vuelto a\n"
	.string "alejar… Qué decepción…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Para abrirte paso por la LIGA\n"
	.string "POKéMON, necesitas la confianza de\l"
	.string "tus POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Vuestra relación se basa en una\n"
	.string "confianza sólida.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Al estar juntos todo el tiempo, la\n"
	.string "confianza crece entre los POKéMON y\l"
	.string "los ENTRENADORES.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Este no es el objetivo. Es solo un\n"
	.string "lugar de paso hacia la LIGA POKéMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "¡Así se hace!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "¡Lo harás bien, seguro!\n"
	.string "¡Tus POKéMON están todos deseando\l"
	.string "seguir adelante!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "¡Mis POKéMON son de una\n"
	.string "inspiración cósmica!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Nunca había conocido a nadie como tú.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Incluso fuera del combate, siento un\n"
	.string "poder increíble emanando de ti y tus\l"
	.string "POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Vale, ¡no hace falta ponerse a la\n"
	.string "defensiva! ¡Relájate, vamos con calma!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "¡Guau!\n"
	.string "¡Maravilloso!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Claro, esta es la RUTA VICTORIA.\p"
	.string "Pero no es tan diferente del camino\n"
	.string "que has recorrido hasta ahora.\p"
	.string "¡Intenta disfrutar de lo que queda\n"
	.string "de camino!$"

