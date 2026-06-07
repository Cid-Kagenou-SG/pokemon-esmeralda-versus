MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "El poder que tiene este meteorito es\n"
	.string "enorme... Si se amplifica con esta\l"
	.string "máquina, la actividad volcánica del\l"
	.string "Monte Cenizo se intensificará de\l"
	.string "inmediato... Su energía inundará el\l"
	.string "cráter y entonces... Jua, jua, jua...$"

MtChimney_Text_MaxieIntro:
	.string "MAGNO: ¿Eh? ¿Quién eres tú?\p"
	.string "...\p"
	.string "He oído a Aquiles quejarse de alguien\n"
	.string "que intentaba tirar por la borda los\l"
	.string "terribles designios del Equipo Aqua.\p"
	.string "Seguro que hablaba de ti.\p"
	.string "¡Ja! ¿Y también buscas problemas con\n"
	.string "nosotros, el Equipo Magma?\p"
	.string "Escúchame bien. Desde siempre los seres\n"
	.string "vivos han necesitado la tierra para\l"
	.string "vivir.\p"
	.string "¡La tierra lo es todo! ¡Su importancia\n"
	.string "es vital!\p"
	.string "Por eso el Equipo Magma se está\n"
	.string "dedicando a expandir la tierra firme.\p"
	.string "¡Es por el bien de la humanidad y de\n"
	.string "los Pokémon!\p"
	.string "Y por eso necesitamos el poder que\n"
	.string "duerme en esa montaña...\p"
	.string "¡Oh! No debería haberte dicho eso.\p"
	.string "Total, no es asunto tuyo.\n"
	.string "¡Pero no importa!\p"
	.string "¡Ahora sufrirás las consecuencias de\n"
	.string "haberte entrometido en nuestros planes!$"

MtChimney_Text_MaxieDefeat:
	.string "¡¿Qué?!\p"
	.string "¡¿A mí, el gran Magno, me han dado una\n"
	.string "lección?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAGNO: Ya basta. Esta vez has ganado.\p"
	.string "Pero no pienses que es la última vez que\n"
	.string "oirás hablar del Equipo Magma.\p"
	.string "Jua, jua, jua...\p"
	.string "El meteorito no importa. Si logramos\n"
	.string "hacernos con la esfera... Jua, jua...$"

MtChimney_Text_TabithaIntro:
	.string "¡Je, je, je! ¡Así que has llegado hasta\n"
	.string "aquí!\p"
	.string "¡Pero ya es demasiado tarde!\n"
	.string "¡He entregado el meteorito de la\l"
	.string "Cascada Meteoro al jefe!$"

MtChimney_Text_TabithaDefeat:
	.string "Ji, ji, ji...\p"
	.string "Mi derrota es irrelevante. Si el jefe\n"
	.string "logra despertar a esa cosa...$"

MtChimney_Text_TabithaPostBattle:
	.string "¡Jefe, date prisa!\n"
	.string "¡Transmítele la energía al meteorito!\p"
	.string "Ji, ji, ji...$"

MtChimney_Text_Grunt2Intro:
	.string "Nosotros, los del Equipo Magma, estamos\n"
	.string "trabajando mucho a beneficio de todos.\p"
	.string "Porque si hay más tierra, habrá más\n"
	.string "sitios donde vivir.\p"
	.string "¡Todo el mundo será más feliz!$"

MtChimney_Text_Grunt2Defeat:
	.string "¿Eh?\n"
	.string "¿Qué quieres decir con que he perdido?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Nuestro jefe dice que todo el mundo será\n"
	.string "más feliz.\p"
	.string "¿Pero por qué todo el mundo parece\n"
	.string "llevarnos la contraria?$"

MtChimney_Text_Grunt1Intro:
	.string "¡Si la tierra fuera más vasta, podría\n"
	.string "tener una casona sólo para mí!\p"
	.string "¡La construiré sobre terreno volcánico!$"

MtChimney_Text_Grunt1Defeat:
	.string "Ya me he quedado sin casona...$"

MtChimney_Text_Grunt1PostBattle:
	.string "¡Alguien tan joven como tú no tendría\n"
	.string "que estar aquí!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Ese molesto Equipo Aqua...\n"
	.string "¡Siempre se entrometen en nuestros\l"
	.string "planes!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "¡Los meteoritos tienen un poder\n"
	.string "increíble!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "¡Será mejor que no te metas con\n"
	.string "nosotros!\p"
	.string "¡Estamos intentando despertar a esa\n"
	.string "cosa por el bien de todos!$"

MtChimney_Text_AquasNameSimilar:
	.string "¡Somos el Equipo Magma!\p"
	.string "¡Son el Equipo Aqua!\p"
	.string "¡Me saca de quicio que usen un nombre\n"
	.string "parecido al nuestro!$"

MtChimney_Text_DouseThemInFire:
	.string "¡Sí!\n"
	.string "¡Abrasadlos con fuego!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "¡Vamos a seguir creando más tierra!$"

MtChimney_Text_Bufoh:
	.string "¡Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "AQUILES: Grr, {PLAYER}!\n"
	.string "¡Debía suponer que aparecerías!\p"
	.string "¡Mira con tus propios ojos lo que los\n"
	.string "fanáticos del Equipo Magma están\l"
	.string "tramando!\p"
	.string "¡Están intentando inyectar el poder del\n"
	.string "meteorito robado en el volcán!\p"
	.string "¡Hacer algo así provocaría la erupción\n"
	.string "del volcán!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "AQUILES: Grrr...\p"
	.string "Quiero detener a ese Magno, ¡pero no\n"
	.string "puedo!\p"
	.string "¡No cuando tengo las manos ocupadas\n"
	.string "luchando contra tres oponentes a la vez!$"

MtChimney_Text_ArchieThankYou:
	.string "AQUILES: {PLAYER}!\n"
	.string "¡Gracias!\p"
	.string "¡Con tu ayuda, hemos frustrado los\n"
	.string "planes destructivos del Equipo Magma!\p"
	.string "Pero... Tú...\n"
	.string "¿De qué lado estás?\p"
	.string "Ah, no importa.\p"
	.string "Permaneceremos vigilantes y seguiremos\n"
	.string "persiguiendo al Equipo Magma.\p"
	.string "{PLAYER}, ¡nos volveremos a ver!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Maldita sea... ¡El Equipo Magma nos\n"
	.string "supera en número!\p"
	.string "¡No podemos con ellos!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "¡Si expanden la tierra, habrá menos\n"
	.string "hábitats para los Pokémon de tipo Agua!$"

MtChimney_Text_MagmasNameSimilar:
	.string "¡Somos el Equipo Aqua!\p"
	.string "¡Son el Equipo Magma!\p"
	.string "¡Me quema que usen un nombre tan\n"
	.string "parecido al nuestro!$"

MtChimney_Text_Bushaa:
	.string "¡Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "Las Galletas Lava son la especialidad\n"
	.string "local del Monte Cenizo.\p"
	.string "Prueba una. Cuestan sólo 200¥.$"

MtChimney_Text_ThankYouDear:
	.string "¡Gracias, cariño!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, cariño. No puedes comprar nada si\n"
	.string "no tienes dinero.$"

MtChimney_Text_OhFineThen:
	.string "Oh, vale entonces.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "Un meteorito está colocado en una\n"
	.string "máquina misteriosa...\p"
	.string "La máquina parece estar almacenando\n"
	.string "energía en el meteorito.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Un meteorito está colocado en una\n"
	.string "máquina misteriosa...\p"
	.string "¿Quieres quitar el meteorito?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} quitó el meteorito de la\n"
	.string "máquina misteriosa.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} dejó el meteorito donde\n"
	.string "estaba.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Esta máquina misteriosa...\n"
	.string "No responde en absoluto.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} SENDA ÍGNEA\n"
	.string "PUEBLO LAVACALDA AL FRENTE$"

MtChimney_Text_ShelbyIntro:
	.string "He estado en las fuentes termales y he\n"
	.string "descansado mis pobres huesos.\l"
	.string "¡Ahora me siento fuerte como un toro!$"

MtChimney_Text_ShelbyDefeat:
	.string "Vaya, vaya, vaya...\n"
	.string "Tienes un estilo increíble luchando.$"

MtChimney_Text_ShelbyPostBattle:
	.string "Bueno, bueno, he perdido. No puedo\n"
	.string "llamarme experta ahora, ¿verdad?$"

MtChimney_Text_ShelbyRegister:
	.string "Gracias, niño. Ha sido divertido, como\n"
	.string "si estuviera luchando contra mi propio\l"
	.string "nieto.\p"
	.string "Por favor, ven a verme otra vez para\n"
	.string "una revancha.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Si eres capaz de fundir tu corazón con\n"
	.string "los de tus Pokémon, sin duda lograrás\l"
	.string "todo lo que te propongas.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Vaya, vaya, vaya...\n"
	.string "Tienes un estilo increíble luchando.$"

MtChimney_Text_ShelbyPostRematch:
	.string "Es posible que tu corazón y los de tus\n"
	.string "Pokémon sean sólo uno.$"

MtChimney_Text_MelissaIntro:
	.string "Tengo fuego en las venas, cariño.\n"
	.string "¡No puedo soportarlo! ¡Tengo que luchar!$"

MtChimney_Text_MelissaDefeat:
	.string "¡Ooh, ha sido un combate ardiente!$"

MtChimney_Text_MelissaPostBattle:
	.string "¡El calor del Monte Cenizo me anima,\n"
	.string "cariño!$"

MtChimney_Text_SheilaIntro:
	.string "¡Por fin he llegado al Monte Cenizo!\n"
	.string "¡Y ahora quiero un combate Pokémon!$"

MtChimney_Text_SheilaDefeat:
	.string "Tu manera de luchar...\n"
	.string "¡es como una erupción volcánica!$"

MtChimney_Text_SheilaPostBattle:
	.string "Pues sí, por fin he llegado al Monte\n"
	.string "Cenizo y no me voy a dedicar sólo a\l"
	.string "hacer visitas...\p"
	.string "También quiero luchar un poquito y\n"
	.string "comprar galletas de recuerdo.$"

MtChimney_Text_ShirleyIntro:
	.string "Desde que fui a los baños termales, me\n"
	.string "siento como nueva.\l"
	.string "¡Seguro que te gano!$"

MtChimney_Text_ShirleyDefeat:
	.string "¡Achís!\n"
	.string "¡Creo que he pillado frío!$"

MtChimney_Text_ShirleyPostBattle:
	.string "Mejor me vuelvo a los baños termales.\n"
	.string "¿Te apuntas?\p"
	.string "¡Sólo bromeaba!$"

MtChimney_Text_SawyerIntro:
	.string "¡Este es un monte estupendo! ¡Lleno de\n"
	.string "gente ardiente para hacer compañía!$"

MtChimney_Text_SawyerDefeat:
	.string "¡Oh, tú también eres un auténtico\n"
	.string "fuego!$"

MtChimney_Text_SawyerPostBattle:
	.string "Creo que necesito un baño en las Fuentes\n"
	.string "Termales de Pueblo Lavacalda con los\l"
	.string "lugareños.$"

MtChimney_Text_SawyerRegister:
	.string "Me gustan los fueguitos como tú.\n"
	.string "Déjame registrarte en mi PokéNav.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Estoy felizmente rodeado de gente\n"
	.string "ardiente por estas partes. ¡No perderé!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "¡Cielos, sigues siendo el mismo fuego\n"
	.string "de antes!$"

MtChimney_Text_SawyerPostRematch:
	.string "En realidad, hace mucho calor aquí.\n"
	.string "Voy demasiado abrigado para estas\l"
	.string "tierras.$"

