RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "¡Eh, qué tal?\p"
	.string "¡Escucha, amigo!\n"
	.string "¿Te gustaría convertirte en CAMPEÓN?\p"
	.string "Yo no soy ENTRENADOR, no, pero seguro\n"
	.string "que puedo darte consejos para ganar.\p"
	.string "¡Pues ya está! ¡Nuestro objetivo será\n"
	.string "el CAMPEONATO POKéMON juntos!\p"
	.string "Es tu trabajo como ENTRENADOR conseguir\n"
	.string "MEDALLAS DE GIMNASIO, ¿verdad?\p"
	.string "¡Pero los LÍDERES DE GIMNASIO no son\n"
	.string "ningunos blandengues!\p"
	.string "¡Y ahí es donde entro yo!\n"
	.string "¡Estoy aquí para darte consejos de\l"
	.string "experto!\p"
	.string "PETRA, la LÍDER DE GIMNASIO, usa\n"
	.string "POKéMON de tipo ROCA.\p"
	.string "El tipo ROCA es muy resistente, pero\n"
	.string "no aguanta los movimientos de tipo\l"
	.string "AGUA y PLANTA.\p"
	.string "Ven a verme después, si derrotas a la\n"
	.string "LÍDER DE GIMNASIO.\p"
	.string "¡Venga, al ataque!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "¡Guau! ¡Qué victoria más emocionante!\n"
	.string "¡Mis ánimos deben de haber funcionado!\p"
	.string "¡Genial!\n"
	.string "Mira tu FICHA DE ENTRENADOR.\p"
	.string "La MEDALLA PIEDRA que has conseguido\n"
	.string "debería estar registrada correctamente\l"
	.string "en ella.\p"
	.string "En otras palabras…\p"
	.string "¡Has subido el primer escalón de\n"
	.string "las escaleras hacia el CAMPEONATO!\p"
	.string "¡Eso tiene que ser alucinante!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "¡No nos tomes a la ligera a los\n"
	.string "ENTRENADORES DEL GIMNASIO!\l"
	.string "¡Te mostraré por qué somos mejores!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Eras demasiado bueno para mí…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "¡No has visto ni una pizca del\n"
	.string "terrorífico poder del tipo ROCA!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Si no puedes vencerme, no tendrás\n"
	.string "ninguna posibilidad contra PETRA!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "¡Guau! ¡Tienes potencial!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "PETRA es varias veces más fuerte que yo.\p"
	.string "¡Más te vale estar alerta!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Puede que estemos en mitad de la ciudad,\n"
	.string "¿pero y qué?\p"
	.string "¡Mis POKéMON ROCA necesitan espacio\n"
	.string "para desatarse!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "¡Oh, vaya, vaya!\n"
	.string "¡Nuestro retador es todo un luchador!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Tengo que reconocérselo a nuestra LÍDER.\p"
	.string "Hizo falta inteligencia y sensatez para\n"
	.string "que ella eligiera el tipo ROCA a su\l"
	.string "temprana edad.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hola, soy PETRA, la LÍDER DEL GIMNASIO\n"
	.string "POKéMON DE CIUDAD FÉRRICA.\p"
	.string "Me convertí en LÍDER DE GIMNASIO para\n"
	.string "poder aplicar lo que aprendí en la\l"
	.string "ESCUELA DE ENTRENADORES POKéMON en\l"
	.string "combate.\p"
	.string "¿Me harías el favor de demostrarme\n"
	.string "cómo combaten tus POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Así que…\n"
	.string "he perdido…\p"
	.string "Parece que todavía tengo mucho más\n"
	.string "que aprender…\p"
	.string "Lo entiendo.\p"
	.string "Las reglas de la LIGA POKéMON establecen\n"
	.string "que los ENTRENADORES deben recibir esto\l"
	.string "si derrotan a un LÍDER DE GIMNASIO.\p"
	.string "Por favor, acepta la MEDALLA PIEDRA\n"
	.string "oficial de la LIGA POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} ha recibido la MEDALLA PIEDRA\n"
	.string "de PETRA.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "La MEDALLA PIEDRA aumenta el poder de\n"
	.string "ATAQUE de tus POKéMON.\p"
	.string "También les permite usar el movimiento\n"
	.string "MO CORTE fuera del combate.\p"
	.string "Por favor, toma esto también.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Esa MÁQUINA TÉCNICA, la MT39, contiene\n"
	.string "TUMBA ROCAS.\p"
	.string "No solo inflige daño lanzando rocas,\n"
	.string "sino que también reduce la VELOCIDAD.\p"
	.string "Si usas una MT, enseña el movimiento\n"
	.string "instantáneamente a un POKéMON.\p"
	.string "Recuerda, una MT solo se puede usar una\n"
	.string "vez, así que piénsalo antes de usarla.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Como eres tan fuerte, deberías\n"
	.string "desafiar a otros LÍDERES DE GIMNASIO.\p"
	.string "Combatiendo contra muchos ENTRENADORES,\n"
	.string "aprenderás muchas cosas.$"

RustboroCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON DE CIUDAD FÉRRICA$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON DE CIUDAD FÉRRICA\p"
	.string "ENTRENADORES CERTIFICADOS POR PETRA:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … ¡Beep!\p"
	.string "PETRA: Oh, hola, ¿{PLAYER}?\n"
	.string "Soy PETRA de CIUDAD FÉRRICA.\p"
	.string "He oído de MARCIAL que estás\n"
	.string "ascendiendo por las filas de los\l"
	.string "ENTRENADORES a una velocidad increíble.\p"
	.string "Bueno, preferiría no pensar que\n"
	.string "no puedo vencerte.\p"
	.string "Te prometo que pondré mi GIMNASIO a\n"
	.string "punto para que puedas desafiarnos de\l"
	.string "nuevo.\p"
	.string "¡Espero que estés deseando ese momento\n"
	.string "tanto como yo!\p"
	.string "… … … … … …\n"
	.string "… … … … … ¡Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Se ha registrado a la LÍDER DE GIMNASIO\n"
	.string "PETRA en el POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "PETRA: Me alegro mucho de verte de\n"
	.string "nuevo. Soy PETRA, la LÍDER DE GIMNASIO\l"
	.string "de aquí.\p"
	.string "Estoy segura de que ambos hemos\n"
	.string "experimentado muchos combates desde la\l"
	.string "última vez.\p"
	.string "Me gustaría ver cuánto hemos mejorado.\n"
	.string "¡Combamos!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "He perdido otra vez…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "PETRA: Todavía tengo mucho que aprender\n"
	.string "cuando se trata de combatir con POKéMON.\p"
	.string "¡Esa conciencia me hace amar los\n"
	.string "combates aún más!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "PETRA: Me alegro mucho de verte de\n"
	.string "nuevo. Soy PETRA, la LÍDER DE GIMNASIO\l"
	.string "de aquí.\p"
	.string "Estoy segura de que ambos hemos\n"
	.string "experimentado muchos combates desde la\l"
	.string "última vez.\p"
	.string "Me gustaría ver cuánto hemos\n"
	.string "mejorado…\p"
	.string "Oh, no…\n"
	.string "Solo llevas un POKéMON contigo.\p"
	.string "Por favor, vuelve con al menos un\n"
	.string "POKéMON más.$"
