LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "¡Eh, qué tal, {PLAYER}?\n"
	.string "¿Con rumbo al Campeonato?\p"
	.string "La líder del Gimnasio de Lavacalda,\n"
	.string "Candela, usa Pokémon de tipo Fuego.\p"
	.string "Su pasión por los Pokémon arde más\n"
	.string "fuerte y más caliente que un volcán.\p"
	.string "¡No te acerques demasiado o te\n"
	.string "quemarás! ¡Rocíala con agua y luego\l"
	.string "ataca!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "¡Guau! ¡Ha sido un combate\n"
	.string "ardientísimo!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "¡Ayayayayay!\n"
	.string "¡Qué calor!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Me ciega el sudor en los ojos…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Estar enterrado en arena caliente\n"
	.string "favorece la circulación.\p"
	.string "Es efectivo para curar el dolor de\n"
	.string "las articulaciones.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Estoy intentando aliviar mi estrés.\n"
	.string "¡No vengas a estresarme más!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "¡Espero que Candela te chamusque bien!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Uf…\p"
	.string "Si pasas demasiado tiempo enterrado en\n"
	.string "arena caliente, te agota…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Debes de estar cansado ya.\n"
	.string "Te gustaría descansar en la arena\l"
	.string "caliente, ¿verdad?\p"
	.string "Pero deberías saber que mantener la\n"
	.string "fuerza de voluntad es una habilidad\l"
	.string "importante para todos los entrenadores.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Juega con fuego y te quemarás…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Tus habilidades son reales…\n"
	.string "Pero nuestra líder Candela es fuerte.\p"
	.string "Si no tienes cuidado, te quemarás\n"
	.string "gravemente.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "¿Pueden tus Pokémon soportar\n"
	.string "392 grados de calor?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "No ardió lo suficientemente fuerte…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La temperatura del magma es de\n"
	.string "392 grados.\p"
	.string "Tus Pokémon me han vencido, así que\n"
	.string "deberían sobrevivir fácilmente en el\l"
	.string "magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Em…\n"
	.string "Vale, lucharé contigo.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, pero eres demasiado fuerte.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Voy a ser una entrenadora bonita y\n"
	.string "fuerte como Candela.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "¡Venga, espabila!\n"
	.string "¡Vamos antes de que se me enfríen\l"
	.string "los ánimos!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Hace tanto calor, y sin embargo mi\n"
	.string "corazón está helado…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Con el espíritu de combate que arde\n"
	.string "dentro de ti, puede que tengas una\l"
	.string "oportunidad contra nuestra líder.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "¿Ves cómo las llamas arden con fuerza?\n"
	.string "¡Se encienden anticipando mi victoria!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Algo no ha salido bien.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Bueno, ¿y qué? ¿Y qué?\n"
	.string "¡Puedo caminar sobre brasas descalzo!\p"
	.string "…Ni se te ocurra intentarlo.$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Tanto como amo las montañas,\n"
	.string "especialmente amo los volcanes.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Bueno, me parece que he perdido sin\n"
	.string "haber tenido nunca el control.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Me quedo aquí porque me convertí en\n"
	.string "fan del poder de Candela.\p"
	.string "Jejejeje.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Bienvenido… No, espera.\p"
	.string "Pequeño entrenador, me alegra ver que\n"
	.string "has llegado hasta aquí.\p"
	.string "Se me ha confiado la…\n"
	.string "No, espera.\p"
	.string "¡Soy Candela, y soy la líder de\n"
	.string "este Gimnasio!\p"
	.string "Eh…\n"
	.string "No te atrevas a subestimarme, aunque\l"
	.string "lleve poco tiempo siendo líder.\p"
	.string "Con las habilidades heredadas de mi\n"
	.string "abuelo, voy a, eh… ¡demostrarte los\l"
	.string "ardientes movimientos que hemos\l"
	.string "perfeccionado en esta tierra!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Supongo que me he esforzado demasiado…\p"
	.string "Yo… Solo recientemente me he\n"
	.string "convertido en líder de Gimnasio.\p"
	.string "Intenté demasiado ser alguien\n"
	.string "que no soy.\p"
	.string "Tengo que hacer las cosas a mi manera.\n"
	.string "Si no, mis Pokémon se confundirán.\p"
	.string "Gracias por enseñarme eso.\n"
	.string "Por eso, te mereces esto.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "¡{PLAYER} recibió la Medalla Calor\n"
	.string "de Candela!$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Si tienes una Medalla Calor, todos los\n"
	.string "Pokémon hasta el nivel 50, incluso los\l"
	.string "que obtengas en intercambios con otras\l"
	.string "personas, te obedecerán completamente.\p"
	.string "Y además, permite a los Pokémon usar el\n"
	.string "movimiento MO Fuerza fuera de combate.\p"
	.string "Esto es un recuerdo de mi agradecimiento.\n"
	.string "¡No seas tímido y tómalo!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "Esa MT50 contiene Sofoco.\p"
	.string "Ese movimiento inflige daño grave al\n"
	.string "oponente.\p"
	.string "Pero también reduce drásticamente el\n"
	.string "At. Esp. del Pokémon que lo usa. Puede\l"
	.string "que no sea adecuado para combates\l"
	.string "largos.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Se ha registrado a la líder del\n"
	.string "Gimnasio, Candela, en el PokéNav.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Tu poder me recuerda a alguien…\p"
	.string "¡Oh! ¡Ya sé! Luchas como Norman, el\n"
	.string "líder del Gimnasio de Petalia.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "GIMNASIO POKÉMON DE CIUDAD LAVACALDA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "GIMNASIO POKÉMON DE CIUDAD LAVACALDA\p"
	.string "ENTRENADORES CERTIFICADOS POR CANDELA:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "CANDELA: Perder un combate no me va a\n"
	.string "desanimar.\p"
	.string "Amo los Pokémon.\n"
	.string "Amo luchar.\l"
	.string "Y… ¡amo este Gimnasio!\p"
	.string "¡Intercambiemos movimientos\n"
	.string "supercalientes en otro combate!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "¡Uf!\n"
	.string "¡A punto de entrar en erupción!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "CANDELA: He perdido el combate,\n"
	.string "pero estoy completamente satisfecha.\p"
	.string "No es frecuente que pueda disfrutar de\n"
	.string "un combate tan caluroso.\p"
	.string "¡Tengamos otro así alguna vez!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "CANDELA: Perder un combate no me va a\n"
	.string "desanimar.\p"
	.string "Amo los Pokémon.\n"
	.string "Amo luchar.\l"
	.string "Y… ¡amo este Gimnasio!\p"
	.string "¡Intercambiemos movimientos\n"
	.string "supercalientes en otro combate!\p"
	.string "Oh, espera. ¿Solo llevas un Pokémon que\n"
	.string "pueda luchar?\p"
	.string "Odio decir esto, pero cuando vengas a\n"
	.string "verme, trae al menos dos Pokémon.$"
