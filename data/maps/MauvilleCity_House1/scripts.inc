MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "¡Yuju!\p"
	.string "He oído que la gente me llama el TÍO\n"
	.string "GOLPE ROCA, pero me parece un poco\l"
	.string "degradante.\p"
	.string "Creo que merezco un poco más de\n"
	.string "respeto, algo así como el SEÑOR\l"
	.string "GOLPE ROCA.\p"
	.string "¡Yuju!\p"
	.string "En fin, tus Pokémon parecen bastante\n"
	.string "fuertes.\p"
	.string "¡Me gustan!\n"
	.string "¡Toma esta MÁQUINA OCULTA!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Esa MO contiene GOLPE ROCA.\p"
	.string "Si te encuentras con grandes rocas\n"
	.string "que bloqueen tu camino…\p"
	.string "¡Pues usa ese movimiento de MO y\n"
	.string "machácalas para apartarlas de tu\l"
	.string "camino!\p"
	.string "¡Eso es! ¡Aplasta las rocas, digo yo!\n"
	.string "¡Yuju!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah, sí, si rompes una roca, puede que\n"
	.string "un Pokémon salga volando de su\l"
	.string "escondite.\p"
	.string "¡Yuju!$"

