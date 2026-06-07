SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Hay una cama…\n"
	.string "Vamos a descansar un poco.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Navego a menudo a CIUDAD CALAGUA.\p"
	.string "Me gusta asistir a CONCURSOS,\n"
	.string "ya ves.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "¡Ha sido un combate agradable!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Me emociona mucho imaginar qué tipos\n"
	.string "de POKéMON veré en el próximo\l"
	.string "CONCURSO. ¡La expectación es emocionante!$"

SSTidalRooms_Text_MicahIntro:
	.string "¿Tus amigos son fuertes?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Tus amigos son, en efecto, fuertes.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Los amigos no tienen por qué ser humanos.\n"
	.string "¡Para mí, los POKéMON son amigos preciados!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Niño…\n"
	.string "¿Has llamado a la puerta?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Una derrota debe aceptarse sin prisa\n"
	.string "ni pánico.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Estar nunca alterado en cualquier situación\n"
	.string "es el código de conducta del CABALALLERO.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Me siento un poco tímido, pero…\n"
	.string "¡Te mostraremos nuestro poder amoroso!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Suspiro…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: ¡Es la primera vez que nuestro poder\n"
	.string "amoroso no ha prevalecido!\l"
	.string "¡Debes ser un ENTRENADOR increíble!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: ¿Solo tienes un POKéMON?\n"
	.string "¿No es eso demasiado solitario?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Me siento un poco tonta, pero…\n"
	.string "¡Te mostraremos nuestro poder amoroso!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: ¡Oh, vaya!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: ¡No puedo creerlo!\n"
	.string "Nuestro poder amoroso ha fallado…\l"
	.string "¡Debes ser un ENTRENADOR increíble!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Quería combatir…\n"
	.string "Pero ni siquiera tienes dos POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, has venido justo a tiempo.\p"
	.string "Estoy aburrido, ya ves.\n"
	.string "Puedes entretenerme.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Eso servirá.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Quizás le pida a Padre que me compre\n"
	.string "un yate.\l"
	.string "¡Un yate para mí y mis POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, eres un ENTRENADOR adorable.\n"
	.string "¿Te apetece tomar té?\l"
	.string "¿O prefieres combatir?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Ya veo.\n"
	.string "Eres del tipo activo.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Un crucero por el mundo en un trasatlántico\n"
	.string "de lujo tiene su encanto, debo decir…\p"
	.string "Pero debo admitir que hay un lado atractivo\n"
	.string "en recorrer HOENN en ferry.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Eh… ¡Hola! Yo… ¡No estoy actuando\n"
	.string "sospechosamente! Eh… ¡Toma esto! ¡Es gratis!\p"

SSTidalRooms_Text_ExplainSnatch:
	.string "ROBO roba los efectos beneficiosos\n"
	.string "de ciertos movimientos antes de que\l"
	.string "puedan ser usados por un rival.$"

