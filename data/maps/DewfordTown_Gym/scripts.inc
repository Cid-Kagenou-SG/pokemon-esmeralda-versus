DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Oye, ¿qué tal, {PLAYER}? ¿Con rumbo al\n"
	.string "Campeonato?\p"
	.string "El líder del Gimnasio de Pueblo Azuliza,\n"
	.string "Marcial, comanda Pokémon de tipo Lucha.\p"
	.string "Enfrentarte a él con Pokémon de tipo\n"
	.string "Normal es pedir problemas.\p"
	.string "Los Pokémon de Lucha darán una paliza\n"
	.string "seria a los Pokémon de tipo Normal,\l"
	.string "¡así que ten cuidado!\p"
	.string "Lo que es peor, el Gimnasio está tan\n"
	.string "oscuro como el fondo del océano.\p"
	.string "Pero se hará más brillante después de\n"
	.string "derrotar a los entrenadores que se\l"
	.string "interponen en tu camino.\p"
	.string "Oye, vale, ¡adelante!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "¡Guau! ¡Se ha vuelto demasiado brillante\n"
	.string "aquí dentro!\p"
	.string "¡Tu futuro también es brillante!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "¡La fuerza lo es todo!\n"
	.string "¡Vamos!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "No hay suficiente fuerza…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "¡Tu habilidad superó mi fuerza!\n"
	.string "¡Tu técnica es encomiable!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "¡No hay necesidad de que Marcial se\n"
	.string "involucre!\p"
	.string "¡Te aplastaré!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Pero… ¿Cómo?\n"
	.string "¿Cómo he podido perder tan fácilmente?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "No voy a desperdiciar esta derrota.\n"
	.string "La usaré para motivarme a entrenar!\p"
	.string "Algún día me convertiré en líder de\n"
	.string "Gimnasio…\p"
	.string "No, ¡me convertiré en el Campeón de la\n"
	.string "Liga Pokémon!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "¡No te atrevas a despreciarme!\n"
	.string "¡No es mi culpa si lloras!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "¡Buaaaaaaaah!\n"
	.string "¡He perdido!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Lucho en la oscuridad para fortalecer\n"
	.string "mi corazón.\p"
	.string "Pero como está tan oscuro, nunca puedo\n"
	.string "ver la cara de Marcial…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "¿Estás tropezando en la oscuridad?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, tú…\n"
	.string "¡No quiero saber nada de ti!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "¡Mereces perderte y terminar de nuevo\n"
	.string "en la entrada!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "¡Te mostraré el coraje de un hombre\n"
	.string "marinero!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "¿Cómo ha pasado esto?\n"
	.string "¡No es propio de mí perder así!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh, ¡sí! Eres digno de ver a nuestro\n"
	.string "líder del Gimnasio.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Si pretendes pasar, ¡tiene que ser\n"
	.string "a través de mí!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "¡Grrrrr!\n"
	.string "¡Vastamente superado!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "¡Ganas!\n"
	.string "¡Ve a por esa Medalla!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "¡Soy Marcial!\n"
	.string "¡El líder del Gimnasio de Pueblo\l"
	.string "Azuliza!\p"
	.string "He sido moldeado por las olas bravas de\n"
	.string "estas partes, y me he vuelto duro en la\l"
	.string "cueva a oscuras.\p"
	.string "¿Así que querías desafiarme?\n"
	.string "¡Déjame ver de qué estás hecho!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "¡Guau, vaya! ¡Hiciste un chapuzón mucho\n"
	.string "mayor de lo que esperaba!\p"
	.string "¡Me inundaste!\p"
	.string "Vale, me has pillado.\n"
	.string "¡Toma esta Medalla de Gimnasio!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "¡{PLAYER} recibió la Medalla Puño\n"
	.string "de Marcial!$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "La Medalla Puño hace que todos los\n"
	.string "Pokémon hasta el nivel 30, incluso los\l"
	.string "que obtengas en intercambios, obedezcan\l"
	.string "sin cuestionar.\p"
	.string "Y además, podrás usar el movimiento MO\n"
	.string "Destello fuera de combate.\p"
	.string "Si quieres, usa también esta Máquina\n"
	.string "Técnica.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Esa MT08 contiene Corpulencia.\p"
	.string "Es un movimiento que aumenta tanto el\n"
	.string "Ataque como la Defensa.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Se ha registrado al líder del Gimnasio,\n"
	.string "Marcial, en el PokéNav.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Puedo ver tu talento convirtiéndose en\n"
	.string "una ola gigante que causará una tormenta\l"
	.string "de asombro entre los entrenadores algún\l"
	.string "día.$"

DewfordTown_Gym_Text_GymStatue:
	.string "GIMNASIO POKÉMON DE PUEBLO AZULIZA$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKÉMON DE PUEBLO AZULIZA\p"
	.string "ENTRENADORES CERTIFICADOS POR MARCIAL:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "MARCIAL: Una ola puede retirarse, pero\n"
	.string "siempre vuelve a la orilla.\p"
	.string "Una ola gigante de talento como tú…\n"
	.string "¡Sabía que volverías!\p"
	.string "¡Muéstrame cuánto más alto has\n"
	.string "subido!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "¡Guau!\n"
	.string "¡Inundado otra vez!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "MARCIAL: Luchar es vasto y profundo.\n"
	.string "No puedes ver el fondo.\l"
	.string "¡Es como el mar de Hoenn!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "MARCIAL: Una ola puede retirarse, pero\n"
	.string "siempre vuelve a la orilla.\p"
	.string "Una ola gigante de talento como tú…\n"
	.string "¡Sabía que volverías!\p"
	.string "¿Oh? Solo llevas un Pokémon que puede\n"
	.string "luchar.\p"
	.string "Lo siento, pero me gustaría que\n"
	.string "volvieras con al menos dos Pokémon.$"
