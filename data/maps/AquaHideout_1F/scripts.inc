AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "¿Qué? ¿Qué? ¿Qué quieres con el\n"
	.string "EQUIPO AQUA?\p"
	.string "¡Nuestro JEFE no está aquí! ¡Se ha ido\n"
	.string "a robar algo importante!\p"
	.string "… …\n"
	.string "¿Adónde se ha ido?\p"
	.string "¡Ja, ja, ja! ¿De verdad crees que te\n"
	.string "diría algo tan crucial?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "¿Qué? ¿Qué?\n"
	.string "¿Eres un SOLDADO del EQUIPO MAGMA?\p"
	.string "He oído que el EQUIPO MAGMA está intentando\n"
	.string "despertar a un POKéMON alucinante en su\l"
	.string "ESCONDITE.\p"
	.string "¿Pero dónde estará su ESCONDITE?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "¿Qué? ¿Qué? ¿Qué quieres con el\n"
	.string "EQUIPO AQUA?\p"
	.string "¡Nuestro JEFE no está aquí!\n"
	.string "¡Se ha ido a robar un submarino!\p"
	.string "… …\n"
	.string "¿Adónde se ha ido?\p"
	.string "¡Ja, ja, ja! ¿De verdad crees que te\n"
	.string "diría algo tan crucial?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "¿Qué? ¿Qué? ¿Qué quieres con el\n"
	.string "EQUIPO AQUA?\p"
	.string "¡Nuestro JEFE no está aquí! ¡Se ha ido\n"
	.string "al MONTE PÍRICO en la RUTA 122!\p"
	.string "… …\n"
	.string "¿Por qué se ha ido?\p"
	.string "¡Ja, ja, ja! ¿De verdad crees que te\n"
	.string "diría algo tan crucial?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "¿Qué? ¿Qué?\n"
	.string "¿Eres un SOLDADO del EQUIPO MAGMA?\p"
	.string "He oído que el EQUIPO MAGMA va tras\n"
	.string "un POKéMON alucinante en el MONTE CENIZO.\p"
	.string "¿Pero cómo es ese POKéMON?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "¿Qué? ¿Qué? ¿Qué quieres con el\n"
	.string "EQUIPO AQUA?\p"
	.string "¡Nuestro JEFE no está aquí!\n"
	.string "¡Se ha ido a CIUDAD PORTUAL!\p"
	.string "… …\n"
	.string "¿Por qué se ha ido?\p"
	.string "¡Ja, ja, ja! ¿De verdad crees que te\n"
	.string "diría algo tan crucial?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "¡Ay, ay, ay!\n"
	.string "¡He detectado a un personaje sospechoso!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "¡He perdido!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "He perdido por el EQUIPO,\n"
	.string "pero he cumplido mi misión…$"

