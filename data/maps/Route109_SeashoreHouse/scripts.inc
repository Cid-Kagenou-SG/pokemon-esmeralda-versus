Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Soy el dueño de la CASA DE LA PLAYA.\n"
	.string "Pero puedes llamarme SEÑOR MAR.\p"
	.string "Lo que más me gusta es ver combates\n"
	.string "Pokémon ardientes.\p"
	.string "¡Déjame ver que tu corazón arde con\n"
	.string "fuerza!\p"
	.string "Si puedes vencer a todos los entrenadores\n"
	.string "de aquí, te recompensaré por tus esfuerzos.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "¡Muéstrame combates ardientes!\p"
	.string "¡Dirijo esta CASA DE LA PLAYA solo\n"
	.string "por esa razón!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "¡Estás ardiendo!\n"
	.string "¡Esos combates han sido ardientes!\l"
	.string "¡Estoy más que satisfecho!\p"
	.string "Como agradecimiento por mostrarme tu\n"
	.string "ardiente racha, quiero que te quedes con\l"
	.string "esto.\p"
	.string "¡Son media docena de botellas de\n"
	.string "REFRESCO!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, pero oye, tu MOCHILA está llena.\n"
	.string "Me quedaré con esto por ti.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "¿Quieres comprar REFRESCO?\n"
	.string "¡A los Pokémon les encanta!\p"
	.string "¡Solo ¥300 la botella!\n"
	.string "¡Compra algunas!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "¡Aquí tienes!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "No tienes dinero.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "¿No?\n"
	.string "Qué pena.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Si buscas un combate en la CASA DE LA\n"
	.string "PLAYA, no encontrarás entrenador más\l"
	.string "ardiente que yo, compañero.$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "¡Ese ha sido un combate ardiente!\n"
	.string "¡Acepto esa derrota, compañero!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Cuando estoy en Ciudad Portual, disfruto\n"
	.string "de combates ardientes y REFRESCO bien\l"
	.string "frío.$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Los combates aburridos no merecen la\n"
	.string "pena.\p"
	.string "¡Los combates ardientes son los que\n"
	.string "fortalecen a entrenadores y Pokémon!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "¡Eso ha sido ardiente!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Uf, me ha dado sed.\n"
	.string "Quizá me tome un REFRESCO.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "¡Voy a mostrarte lo geniales que son mis\n"
	.string "Pokémon, pero no llores!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…He perdido, pero no lloraré…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Si uno de mis Pokémon supiera el\n"
	.string "movimiento para llevarme sobre el agua\l"
	.string "a lomos suyos, podría deshacerme de este\l"
	.string "flotador.$"

