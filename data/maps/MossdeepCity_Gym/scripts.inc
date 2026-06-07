MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "¡Eh, qué tal, futuro campeón {PLAYER}?\p"
	.string "Los líderes de gimnasio de aquí usan\n"
	.string "Pokémon de tipo Psíquico.\p"
	.string "Si te enfrentas a ellos con Pokémon\n"
	.string "de tipo Lucha o Veneno, ¡te infligirán\l"
	.string "un daño horrible!\p"
	.string "Además, vendrán a por ti con ataques\n"
	.string "combinados extraordinarios.\p"
	.string "Si quieres ganar, tendrás que mostrarles\n"
	.string "lo unido que estás con tus Pokémon.\l"
	.string "¡Adelante!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "¡Vaya, eres asombroso!\n"
	.string "¡Eres un gran entrenador!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "¡Los combates dependen de la fuerza de\n"
	.string "tu espíritu! ¡Los de espíritu débil\l"
	.string "nunca ganarán!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "¡He perdido!\n"
	.string "¡Debo templar mi espíritu de nuevo!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Los indecisos pierden.\n"
	.string "Esa es mi advertencia para ti.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "¡Déjame ver tu talento!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "¡Posees un talento espectacular!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Si hay prodigios en el mundo,\n"
	.string "nuestros líderes de gimnasio lo son.\p"
	.string "Sin embargo, puede que tengas aún más\n"
	.string "talento que ellos…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… ¡Mira cómo levito una Poké\n"
	.string "Ball telequinéticamente!\p"
	.string "¡Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "A veces, estoy desincronizado…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "¡Mis habilidades de combate Pokémon\n"
	.string "también están desincronizadas!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Una Poké Ball era demasiado pesada para\n"
	.string "levitarla psíquicamente. Pero este\l"
	.string "pelo de polvo…\p"
	.string "¡Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "¡No, no hago trampa!\n"
	.string "¡No le he soplado! ¡De verdad!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Cuando pierdas contra mí, no seas\n"
	.string "demasiado duro contigo mismo.\p"
	.string "No es que seas débil, ¡es que yo soy\n"
	.string "demasiado fuerte!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "¡Eres simplemente demasiado fuerte!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "No me voy a deprimir por perder. Solo\n"
	.string "necesito entrenar más duro.\p"
	.string "¡El pensamiento positivo, ese es mi\n"
	.string "punto fuerte!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Lo veo…\n"
	.string "Veo tu futuro…\p"
	.string "¡Si me derrotas, te diré tu futuro!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "¡Me rindo!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Librarás un combate tremendamente\n"
	.string "intenso con nuestros líderes de\l"
	.string "gimnasio…\p"
	.string "El resultado…\n"
	.string "¡No te lo diré yo!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Los caminos que has recorrido…\n"
	.string "Lo que has experimentado…\p"
	.string "¡Ven a por mí con todo lo que has\n"
	.string "aprendido!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "¡Has recorrido un camino de grandeza!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Un futuro brillante espera a quienes\n"
	.string "han trabajado diligentemente.\p"
	.string "Para quienes holgazanean, solo hay\n"
	.string "desesperación al final.\p"
	.string "El mundo da vueltas…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "¡Incluso arriesgando mi vida, ganaré\n"
	.string "este combate!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Lo que haces…\n"
	.string "Me horroriza…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Cómo te atreves a derrotarme…\p"
	.string "No será culpa mía si te ocurre algo\n"
	.string "horrible…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Jojojo.\p"
	.string "Necesito que te muestre lo tenaz que\n"
	.string "puede ser el tipo Psíquico.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "¡Oh! ¡Dios mío!\n"
	.string "¡Tu estilo de combate es fantástico!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Yo… yo no dejo que la derrota me\n"
	.string "afecte, por muy mala que sea.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "¡Déjame mostrarte un momento perfectamente\n"
	.string "horrible y aterrador!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "¡N-nooooo!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "¡Tu vitalidad es contagiosa!\n"
	.string "¡Aléjate de mí rápidamente!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Puede que esté pasado de moda, pero te\n"
	.string "sugiero que no me trates con condescendencia.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "¡Ah, desbordas el poder de la juventud!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Parece que no pude superar tu energía\n"
	.string "juvenil.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "¡No vas a llegar al final!\n"
	.string "¡No si puedo evitarlo!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "¿Cómo puedes ser tan ridículamente\n"
	.string "fuerte?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Humph. Puedes ser fuerte, pero no eres\n"
	.string "adecuado para el tipo Psíquico.\p"
	.string "¡Tu manera de combatir es de alguna\n"
	.string "forma brutal!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "¡Wroooar! ¡Prueba el poder de mi súper\n"
	.string "combate Pokémon!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "¡Oh!\n"
	.string "¡Acabado!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "¡Muy bien! Creo que desarrollaré un\n"
	.string "poder especial invencible de Pokémon\l"
	.string "la próxima vez.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "VITO: Jejeje… ¿Te sorprendió?\p"
	.string "LETI: Fufufu… ¿Te sorprendió?\p"
	.string "VITO: ¿Que hay dos líderes de gimnasio?\n"
	.string "LETI: ¿Que hay dos líderes de gimnasio?\p"
	.string "VITO: ¡Somos gemelos!\n"
	.string "LETI: ¡Somos gemelos!\p"
	.string "VITO: No necesitamos hablar porque…\n"
	.string "LETI: Podemos determinar lo que…\p"
	.string "VITO: El otro está pensando…\n"
	.string "LETI: ¡Todo en nuestras mentes!\p"
	.string "VITO: Esta combinación nuestra…\n"
	.string "LETI: ¿Puedes vencerla?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "VITO: ¿¡Qué?! Nuestra combinación…\n"
	.string "LETI: ¡Ha sido destrozada!\p"
	.string "VITO: No se puede evitar. Has ganado…\n"
	.string "LETI: Así que, en reconocimiento, toma esto.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} recibió la Medalla Mente\n"
	.string "de Vito y Leti.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "VITO: La Medalla Mente potencia el Ataque\n"
	.string "Especial y la Defensa Especial de los\l"
	.string "Pokémon.\p"
	.string "LETI: También te permite usar el movimiento\n"
	.string "MO Buceo fuera de combate.\p"
	.string "VITO: Deberías tomar esto también.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "VITO: Esa MT04 contiene…\n"
	.string "LETI: ¡Paz Mental!\p"
	.string "VITO: Aumenta el Ataque Especial y…\n"
	.string "LETI: ¡Aumenta la Defensa Especial!\p"
	.string "VITO: Es un movimiento perfecto…\n"
	.string "LETI: ¡Para Pokémon Psíquicos!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Registrados los líderes de gimnasio\n"
	.string "Vito y Leti en el PokéNav.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "VITO: Parece que el vínculo entre tú y\n"
	.string "tus Pokémon es mucho más fuerte que el\l"
	.string "vínculo que compartimos como gemelos.\p"
	.string "LETI: ¡Te volverás aún más fuerte!\n"
	.string "Lo sabemos porque hemos combatido contigo.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "VITO: Jejeje… ¿Te sorprendió?\p"
	.string "LETI: ¿Que hay dos líderes de gimnasio?\p"
	.string "VITO: Vaya, solo tienes uno…\n"
	.string "LETI: Pokémon que pueda combatir.\p"
	.string "VITO: ¡No podemos combatir así!\p"
	.string "LETI: Si quieres desafiarnos, trae más\n"
	.string "Pokémon.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "Gimnasio Pokémon de Ciudad Algaria$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "Gimnasio Pokémon de Ciudad Algaria\p"
	.string "Entrenadores certificados por Leti y Vito:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "VITO: Pokémon…\n"
	.string "LETI: Pokémon…\p"
	.string "VITO: Cambiando la composición del equipo…\n"
	.string "LETI: El estilo de combate cambia.\p"
	.string "VITO: Pero yo…\n"
	.string "LETI: Pero yo…\p"
	.string "VITO: ¡Siempre estaré con Leti!\n"
	.string "LETI: ¡Siempre estaré con Vito!\p"
	.string "VITO: Nuestra combinación…\n"
	.string "LETI: ¡Te la mostraremos una y otra vez!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "VITO: Tú y tus Pokémon…\n"
	.string "LETI: ¡Es como si fuerais hermanos!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "VITO: Puedes derribarnos,\n"
	.string "¡pero nunca nos quedaremos abajo!\p"
	.string "LETI: Porque los dos,\n"
	.string "siempre nos apoyamos mutuamente.$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "VITO: Has vuelto otra vez…\n"
	.string "LETI: Has vuelto otra vez…\p"
	.string "VITO: Para darnos una revancha.\n"
	.string "LETI: Para darnos una revancha.\p"
	.string "VITO: Pero…\n"
	.string "LETI: Para nuestro combate…\p"
	.string "VITO: ¡Solo has traído un Pokémon!\n"
	.string "LETI: ¡Solo has traído un Pokémon!\p"
	.string "VITO: Necesitamos que traigas al menos…\n"
	.string "LETI: Dos Pokémon cuando vuelvas.$"
