VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "He entrenado con toda mi familia,\n"
	.string "¡todos nosotros!\l"
	.string "¡No voy a perder ante nadie!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "¿¿Mejor que mi familia??\n"
	.string "¿¿Es eso posible??$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "Era mejor que todos en mi familia.\n"
	.string "Nunca había perdido antes…\p"
	.string "He perdido mi confianza…\n"
	.string "Quizás vuelva a casa…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "Había oído que había un niño pequeño\n"
	.string "pero duro por aquí. ¿Te refieren a ti?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "¡El pequeñajo es duro!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Los rumores que oí, ese niño pequeño\n"
	.string "pero duro es de CIUDAD PETALIA.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Debes estar un poco cansado.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "¡Ni signos de cansancio en absoluto!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "La RUTA VICTORIA y la LIGA POKéMON\n"
	.string "son desafíos largos y agotadores.\l"
	.string "¡Ten cuidado con el cansancio!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "No deberías confiarte solo porque\n"
	.string "tienes muchas MEDALLAS.\p"
	.string "Siempre va a haber alguien que\n"
	.string "sea mejor que tú.$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "¡Eres mejor que yo!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Contempla tus MEDALLAS reunidas y\n"
	.string "recuerda a los ENTRENADORES a los que\l"
	.string "te has enfrentado.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "He llegado hasta aquí, pero la tensión\n"
	.string "me está dando un dolor de estómago\l"
	.string "terrible…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ooh…\n"
	.string "Duele…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "No puedo evitar ponerme tenso sabiendo\n"
	.string "que me estoy acercando a la LIGA\l"
	.string "POKéMON.\p"
	.string "Todo lo que puedo hacer es fingir calma.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "La élite entre la élite se reúne en\n"
	.string "esta cueva.\p"
	.string "¿Cómo lo estás llevando?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "¡Ni el más mínimo desconcierto!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "¡Sí que tienes agallas! ¡Eso me gusta!\n"
	.string "¡Sigue así!$"

