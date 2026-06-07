SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "¡Soy el GURÚ ENERGÍA! ¡Me lanzaré a\n"
	.string "ello y te venderé lo que necesites!$"

SlateportCity_Text_OhYourPokemon:
	.string "¿Oh?\n"
	.string "Tu {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "¡Lo ha hecho de manera estupenda!\p"
	.string "Como recompensa, por favor dale esta\n"
	.string "CINTA ESFUERZO.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} ha recibido la CINTA ESFUERZO.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} le puso la CINTA ESFUERZO\n"
	.string "a {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Tienes que esforzarte un poco más.\p"
	.string "Si lo haces, le daré a tu POKéMON\n"
	.string "algo bueno.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "¡Oh! ¡Tu {STR_VAR_1}, esa CINTA\n"
	.string "ESFUERZO le queda muy bien!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La luz del faro alcanza a docenas de\n"
	.string "millas de distancia.\p"
	.string "Me pregunto si no asustará a los\n"
	.string "POKéMON del mar.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "¡Ooh, mira esto!\p"
	.string "Las algas que se pueden conseguir por\n"
	.string "estas partes son frescas y llenas de vida.\p"
	.string "¡Vaya, parece que incluso podrían\n"
	.string "erguirse y atacar!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Donde el agua es limpia, se reúnen los\n"
	.string "frutos de una cosecha abundante.\p"
	.string "Y donde se reúnen las personas, pronto\n"
	.string "surge un mercado.\p"
	.string "Así es como nace y crece un pueblo.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Comprar donde puedes respirar el aroma\n"
	.string "del océano…\p"
	.string "¡CIUDAD PORTUAL es un lugar tan\n"
	.string "maravilloso!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Si pones MUÑECOS o COJINES en el suelo,\n"
	.string "se ensuciarán.\p"
	.string "Voy a comprar LADRILLOS para que mis\n"
	.string "MUÑECOS y COJINES no se ensucien cuando\l"
	.string "los deje fuera.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "¡Wroooar! ¡Yo también voy a competir en\n"
	.string "la TIENDA DE BATALLA!\p"
	.string "¡Pero antes, necesito atrapar algunos\n"
	.string "POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Uf… Estoy hecho polvo…\p"
	.string "He venido andando desde CIUDAD\n"
	.string "MALVALONA.\n"
	.string "Pero, vaya, esta ciudad es enorme.\p"
	.string "Si lo hubiera sabido, habría venido en\n"
	.string "mi BICI.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "BABOR, el tipo que construyó el MUSEO,\n"
	.string "también es el líder de un equipo de\l"
	.string "exploración submarina.\p"
	.string "Así que todo el mundo le llama\n"
	.string "CAPITÁN BABOR.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "¿Qué es eso de allí?\n"
	.string "¿Esa fila tan larga…?$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Cuando era niño, visitaba el MUSEO a\n"
	.string "menudo.\p"
	.string "Solía soñar con los misterios del mar\n"
	.string "después de ver las exposiciones.$"

SlateportCity_Text_QuitPushing:
	.string "¡Oye, tú! ¡Deja de empujar!\n"
	.string "¡Esto es la cola, ¿no lo ves?$"

SlateportCity_Text_AquaHasPolicy:
	.string "El EQUIPO AQUA tiene una política de\n"
	.string "reunirse y dispersarse en el lugar de\l"
	.string "la operación.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Nuestro JEFE es brillante.\p"
	.string "¿Qué querría hacer con un MUSEO\n"
	.string "ahora?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "¿Cuál será el nuevo plan, me pregunto?\p"
	.string "Nuestro JEFE da miedo cuando se enfada,\n"
	.string "así que será mejor que no la líe…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Si hay algo que necesitamos en el\n"
	.string "MUSEO, ¡deberíamos llevárnoslo todo!$"

SlateportCity_Text_DontButtIn:
	.string "¡Oye, tú!\n"
	.string "¡No te entrometas!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "¿Una fila larga, eh?\p"
	.string "Me recuerda a las veces que hacía cola\n"
	.string "para comprar juegos superventas…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "¿Por qué estamos haciendo cola y\n"
	.string "pagando?\n"
	.string "¡Deberíamos entrar a la fuerza!$"

SlateportCity_Text_WhatDoYouWant:
	.string "¿Qué?\n"
	.string "¿Qué quieres?$"

SlateportCity_Text_IllReadSignForYou:
	.string "¿Quieres leer este letrero?\n"
	.string "¡Te lo leeré yo!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Veamos…\p"
	.string "Um… Creo que dice algo como\n"
	.string "“la vida en el mar es infinita”.\p"
	.string "Sí, estoy bastante seguro de que\n"
	.string "eso es lo que dice.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grrr…\p"
	.string "Debería haber traído mi Game Boy\n"
	.string "Advance para no aburrirme en la cola…\p"
	.string "Grrr…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Cuando termine esta operación, ¡te\n"
	.string "llevaré a un balneario de aguas termales!\p"
	.string "Eso es lo que dijo nuestro líder.\n"
	.string "¡No puedo esperar!$"

SlateportCity_Text_SeaIsSoWet:
	.string "El mar es tan vasto…\p"
	.string "¿Podría el mar haber sido hecho por\n"
	.string "las lágrimas derramadas por los POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "¿Sabes qué hacen con los barcos viejos\n"
	.string "que se vuelven demasiado chirriantes\l"
	.string "para navegar?\p"
	.string "Los hunden en el mar para que se\n"
	.string "conviertan en hábitats para los POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Cada vez que vengo aquí, me dejo llevar\n"
	.string "y compro demasiado.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Si quieres cambiar el mote de tu\n"
	.string "POKéMON, tendrás que pedirle ayuda al\l"
	.string "INSPECTOR DE MOTES.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Cualquier POKéMON que consigas en un\n"
	.string "intercambio, no puedes cambiarle el\l"
	.string "mote.\p"
	.string "El amor del ENTRENADOR original por ese\n"
	.string "POKéMON está en el mote.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Recientemente, se construyó una TIENDA\n"
	.string "DE BATALLA en CIUDAD PORTUAL.\p"
	.string "Los GIMNASIOS son divertidos, pero la\n"
	.string "TIENDA DE BATALLA es alucinante a su\l"
	.string "manera.\p"
	.string "¡Deberías ir a buscar POKéMON fuertes\n"
	.string "para la TIENDA DE BATALLA!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Esperaba que fuera una estrella famosa\n"
	.string "para poder conseguir un autógrafo.\p"
	.string "Pero, ¿quién está siendo entrevistado\n"
	.string "ahí?\n"
	.string "¿No es el CAPITÁN BABOR?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Esa presentadora es tan guay\n"
	.string "y guapa.\p"
	.string "¡Cuando sea mayor, voy a ser\n"
	.string "periodista internacional!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "El CAPITÁN BABOR dice que han\n"
	.string "descubierto algo en el fondo del mar.\p"
	.string "¿Qué será?\n"
	.string "¿Qué podrá ser?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "¿Qué está pasando aquí?\p"
	.string "¿Ha vuelto el buen CAPITÁN con un\n"
	.string "pez gordo del fondo del mar?$"

SlateportCity_Text_AmIOnTV:
	.string "¡Oye! ¿Estás viendo?\n"
	.string "¿Salgo en la tele?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "¡Una entrevista en la tele! ¡Aquí!\n"
	.string "¡El CAPITÁN es una celebridad!$"

SlateportCity_Text_BigSmileForCamera:
	.string "MAYA: Vale, CAPITÁN BABOR, ¡una gran\n"
	.string "sonrisa para la cámara!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "DAVINA: Ya veo, ya veo. Ha tenido una\n"
	.string "experiencia de lo más valiosa…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPITÁN BABOR: Sí, en efecto. Tenemos\n"
	.string "la intención de seguir adelante con\l"
	.string "nuestra exploración.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "DAVINA: Eso es maravilloso, CAPITÁN\n"
	.string "BABOR. Gracias por sacar tiempo de\l"
	.string "su ajetreada agenda para hablar con\l"
	.string "nosotros.\p"
	.string "¡Esperamos poder entrevistarle de\n"
	.string "nuevo con noticias de más descubrimientos!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPITÁN BABOR: Uf…\p"
	.string "Era la primera vez que me grababan para\n"
	.string "la tele. Eso me puso nervioso.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "¡Oh! ¡{PLAYER}{KUN}!\n"
	.string "¡Estás estupendo!\p"
	.string "Hicimos un gran descubrimiento en\n"
	.string "nuestra última exploración del fondo\l"
	.string "del mar.\p"
	.string "Encontramos una caverna submarina en\n"
	.string "la RUTA 128.\p"
	.string "Creemos que es el hábitat de un POKéMON\n"
	.string "que se dice que se extinguió hace mucho.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "CAPITÁN BABOR, supongo.\p"
	.string "¡Nosotros, el EQUIPO AQUA, tomaremos\n"
	.string "el control de su submarino!\p"
	.string "¡Sus objeciones carecen de sentido!\n"
	.string "¡Esperamos su total cooperación!\p"
	.string "Fufufu…\n"
	.string "¡Solo mire y aprenda lo que el EQUIPO\l"
	.string "AQUA tiene planeado!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPITÁN BABOR: ¿Qué ha sido todo eso?\p"
	.string "Sonaba como alguien usando un\n"
	.string "megáfono…\p"
	.string "¿De dónde ha venido?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "¡Viene del PUERTO!\p"
	.string "¡El submarino!\n"
	.string "¡Están intentando llevárselo!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "¡{PLAYER}{KUN}!\n"
	.string "¡Por favor, ven conmigo!$"

SlateportCity_Text_BattleTentSign:
	.string "TIENDA DE BATALLA SEDE DE CIUDAD\n"
	.string "PORTUAL\p"
	.string "“¡Encuéntralo! ¡El POKéMON definitivo!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "ASTILLEROS BABOR\p"
	.string "“Se busca: Marinero capaz de navegar\n"
	.string "en todas las corrientes.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "ASTILLEROS BABOR\p"
	.string "“El ferry S.S. TITAL está a punto de\n"
	.string "terminarse para servir los puertos de\l"
	.string "CIUDAD PORTUAL y CIUDAD CALAGUA.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "ASTILLEROS BABOR\p"
	.string "“El embarque del ferry S.S. TITAL de la\n"
	.string "línea CIUDAD PORTUAL-CIUDAD CALAGUA se\l"
	.string "realiza en el PUERTO.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "CLUB DE FANS DE POKéMON\p"
	.string "“¡Llamando a todos los fans de los\n"
	.string "POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“El mar sin fin sostiene\n"
	.string "toda la vida.”\p"
	.string "MUSEO OCEANOGRÁFICO$"

SlateportCity_Text_CitySign:
	.string "CIUDAD PORTUAL\p"
	.string "“El puerto donde las personas y los\n"
	.string "POKéMON se cruzan.”$"

SlateportCity_Text_MarketSign:
	.string "MERCADO DE CIUDAD PORTUAL\p"
	.string "“¡Objetos únicos que no encontrarás en\n"
	.string "ningún otro sitio!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PUERTO DE CIUDAD PORTUAL\p"
	.string "“El ferry S.S. TITAL está en\n"
	.string "construcción en los ASTILLEROS.\p"
	.string "“El servicio está programado para\n"
	.string "comenzar próximamente.”$"

SlateportCity_Text_HarborSign:
	.string "PUERTO DE CIUDAD PORTUAL\p"
	.string "“Disfruta de un encantador crucero en\n"
	.string "el ferry S.S. TITAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "CASA DEL INSPECTOR DE MOTES\p"
	.string "“Se evalúan los motes de los POKéMON.”$"

SlateportCity_Text_ExplainBerries:
	.string "Si un POKéMON salvaje se lastima, se\n"
	.string "cura mordiendo BAYAS.\p"
	.string "¿Lo sabías?\p"
	.string "Alguien vio eso y tuvo la idea de hacer\n"
	.string "medicina con BAYAS.\p"
	.string "¿Lo sabías?\p"
	.string "Para convertir BAYAS en medicina, deben\n"
	.string "ser machacadas en polvo.\p"
	.string "¿Lo sabías?\p"
	.string "¡Parece que te interesan las BAYAS!\p"
	.string "Tengo algo bueno para alguien\n"
	.string "como tú.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Recientemente he instalado máquinas en\n"
	.string "los CENTROS POKéMON para machacar BAYAS.\p"
	.string "Las MACHACABAYAS están en la ZONA\n"
	.string "DIRECTA de la planta de arriba.\p"
	.string "¿Lo sabías?\p"
	.string "¿Podrías hacer POLVO DE BAYA para mí\n"
	.string "usando esas máquinas?\p"
	.string "Puedo hacerte todo tipo de medicinas si\n"
	.string "me traes mucho POLVO DE BAYA.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "¿Me has traído algo de\n"
	.string "POLVO DE BAYA?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "¿Por qué te gustaría cambiarlo?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Vale, ¿quieres cambiar tu POLVO DE BAYA\n"
	.string "por un {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oh, cielos. No tienes suficiente\n"
	.string "POLVO DE BAYA.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Este es un POLVO DE BAYA fino.\n"
	.string "Hará una medicina excelente.\p"
	.string "¿Te gustaría cambiar más de tu\n"
	.string "POLVO DE BAYA por algo más?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "¡Vale! ¡Cuando consigas más POLVO DE\n"
	.string "BAYA, tráemelo, por favor!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Vuelve si quieres cambiar tu POLVO DE\n"
	.string "BAYA por alguna medicina.\p"
	.string "Siempre estoy montando un bazar aquí.\p"
	.string "¿Lo sabías?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "TRETO: ¿Eh?\n"
	.string "Seguro que te he visto en algún sitio\l"
	.string "antes.\p"
	.string "¿Me he presentado contigo?\n"
	.string "Si no, me llamo TRETO.\p"
	.string "Acabo de ver al EQUIPO AQUA salir\n"
	.string "corriendo de aquí como si les hubieran\l"
	.string "picado.\p"
	.string "Déjame adivinar… ¿tú los has\n"
	.string "ahuyentado?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "TRETO: Mmm…\n"
	.string "Quizás, solo quizás, este ENTRENADOR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "TRETO: ¡Vale! Creo que vas a ser un\n"
	.string "buen amigo.\p"
	.string "Así que, registremos el uno al otro en\n"
	.string "nuestros POKéNAV.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Se ha registrado a esta persona llamada\n"
	.string "TRETO en el POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "TRETO: Lo que me gustaría es ir contigo,\n"
	.string "pero también quiero vigilar los talentos\l"
	.string "de otras personas.\p"
	.string "Así que, me iré a recorrer otros pueblos\n"
	.string "un poco más.\p"
	.string "¡Nos vemos, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "TRETO: ¡Oh, hola!\n"
	.string "¡Si no es {PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, déjame adivinar… ¿vas a\n"
	.string "aceptar el desafío de la TIENDA DE\l"
	.string "BATALLA?\p"
	.string "¡Sí! ¡Es una buena idea!\n"
	.string "¡Es una idea realmente genial!\p"
	.string "¡Después de todo, un ENTRENADOR fuerte\n"
	.string "es la pareja perfecta para la TIENDA\l"
	.string "DE BATALLA!\p"
	.string "¡Dale lo mejor de ti!$"
