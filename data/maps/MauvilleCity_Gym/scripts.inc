MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "¡Eh, {PLAYER}! ¿Cómo te va, futuro\n"
	.string "CAMPEÓN?\p"
	.string "ERICO, el LÍDER del GIMNASIO de\n"
	.string "MALVALONA, usa POKéMON de tipo\l"
	.string "ELÉCTRICO.\p"
	.string "Si le desafías con POKéMON de tipo\n"
	.string "AGUA, ¡te los va a freír! ¡Zzzzt!\p"
	.string "Y encima ha puesto puertas controladas\n"
	.string "por interruptores por todo el GIMNASIO.\l"
	.string "¡Qué excéntrico!\p"
	.string "¡Venga, tú puedes!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "¡Guau, eres electrizante!\n"
	.string "¡Has abierto la puerta a base de energía!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Mi alma eléctrica destrozará tus\n"
	.string "sueños, ¡oh, yeah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "Eso ha sido eléctrico a tope,\n"
	.string "amplificado y sobrecargado, tío.$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "Los POKéMON y el rock van del corazón,\n"
	.string "¡oh, yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "¡He entrenado con ERICO!\n"
	.string "¡No perderé tan fácilmente!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Desenchufado y apagado…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "ERICO, nuestro LÍDER de GIMNASIO, lleva\n"
	.string "muchísimo tiempo en esto.\p"
	.string "Luchaba incluso antes de que naciera\n"
	.string "tu padre, ese viejo cascarrabias.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "¡Este GIMNASIO tiene trampas!\n"
	.string "¿A que es divertido?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Perder no es divertido…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "ERICO dice que le gusta poner pequeñas\n"
	.string "trampas con interruptores.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Con mi encanto y los movimientos de mis\n"
	.string "POKéMON, ¡te dejaré pasmado!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "¡Estoy pasmada por tu fuerza!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "He oído que MALVALONA fue fundada por\n"
	.string "ERICO.\p"
	.string "Era ENTRENADOR mucho antes de que\n"
	.string "nosotros lo fuéramos.\l"
	.string "¡Debe saber un montón de cosas!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "¡Me encantan las cosas brillantes!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "Se me han quedado los ojos bizcos…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "La frente de ERICO, del GIMNASIO de\n"
	.string "MALVALONA, brilla. ¡Me pone contento!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "He abandonado mis planes para\n"
	.string "convertir la ciudad, sí.\p"
	.string "Así que he dedicado mi tiempo a hacer\n"
	.string "trampas con puertas en mi GIMNASIO.\p"
	.string "¿Eh? ¿Qué haces aquí?\p"
	.string "¿Cómo? ¿Dices que has superado todas\n"
	.string "mis puertas trucadas?\p"
	.string "¡Ja, ja, ja, ja!\n"
	.string "¡Eso sí que es divertido!\p"
	.string "Entonces yo, ERICO, el LÍDER del\n"
	.string "GIMNASIO de MALVALONA, ¡te voy a\l"
	.string "electrizar!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "¡Ja, ja, ja, ja!\n"
	.string "¡Vale, he perdido!\p"
	.string "¡Al final me has emocionado!\n"
	.string "¡Toma esta MEDALLA!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "¡{PLAYER} recibió la MEDALLA DÍNAMO\n"
	.string "de ERICO!$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Con la MEDALLA DÍNAMO, tus POKéMON\n"
	.string "podrán usar GOLPE ROCA fuera del\l"
	.string "combate.\p"
	.string "Y además hará que tus POKéMON sean\n"
	.string "un poquito más rápidos.\p"
	.string "Mmm…\n"
	.string "¡Toma esto también!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "Esa MT34 contiene ONDA VOLTIO.\p"
	.string "¡Es un movimiento de fiar que nunca\n"
	.string "falla! ¡Puedes contar con él!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Se ha registrado al LÍDER de GIMNASIO\n"
	.string "ERICO en el POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "¡Me llena de optimismo ver a un joven\n"
	.string "ENTRENADOR con tanto futuro como tú!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "¡Ja, ja, ja, ja!\n"
	.string "¡Adelante, muchacho, y esfuerzate!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKéMON de CIUDAD MALVALONA$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKéMON de CIUDAD MALVALONA\p"
	.string "ENTRENADORES CERTIFICADOS por ERICO:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "ERICO: ¡Ah, ja! ¡Por fin has venido!\n"
	.string "Sé lo que quieres.\l"
	.string "¡Quieres luchar contra mis POKéMON!\p"
	.string "¡Ja, ja, ja, ja!\p"
	.string "¡Te voy a hacer saltar chispas!\n"
	.string "¡No digas que no te lo advertí!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Uf…\n"
	.string "Se nos han agotado las pilas…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "ERICO: Tendremos que recargar las\n"
	.string "pilas otra vez.\p"
	.string "Cuando estemos a tope, aceptaremos\n"
	.string "tu desafío encantados.\p"
	.string "Así que vuelve por aquí de vez en\n"
	.string "cuando, ¿vale?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "ERICO: ¡Ah, ja! ¡Por fin has venido!\n"
	.string "Sé lo que quieres.\l"
	.string "¡Quieres luchar contra mis POKéMON!\p"
	.string "¡Ja, ja, ja, ja!\p"
	.string "¡Espera!\n"
	.string "¡Solo llevas un POKéMON contigo!\p"
	.string "Vuelve cuando tengas dos o más\n"
	.string "POKéMON, ¿vale?$"

