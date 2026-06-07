BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "¡Donde se pone a prueba el valor de\n"
	.string "los ENTRENADORES!\p"
	.string "¡Bienvenido/a a la PIRÁMIDE BATALLA!\p"
	.string "Soy su guía para la\n"
	.string "Búsqueda de la Batalla.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "¿Tiene el valor necesario para emprender\n"
	.string "el desafío de la Búsqueda de la Batalla?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "¡Esperamos su desafío en el futuro!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "La Búsqueda de la Batalla es un evento\n"
	.string "de combate en el que debe explorar la\l"
	.string "PIRÁMIDE e intentar llegar a la cima.\p"
	.string "En la PIRÁMIDE hay siete plantas de\n"
	.string "laberintos, todos ellos llenos no solo\l"
	.string "de ENTRENADORES diestros, sino también\l"
	.string "de POKéMON salvajes.\p"
	.string "Debe entrar con tres POKéMON,\n"
	.string "ninguno de ellos llevando un objeto.\p"
	.string "Durante su ascenso, se le proporcionará\n"
	.string "un BOLSO de BATALLA para los objetos.\p"
	.string "Si fracasa en su desafío, cualquier\n"
	.string "objeto colocado en el BOLSO de BATALLA\l"
	.string "desaparecerá.\p"
	.string "Si quiere interrumpir su desafío,\n"
	.string "debe seleccionar “DESCANSAR” y guardar\l"
	.string "la partida.\p"
	.string "Si no guarda antes de interrumpir,\n"
	.string "será descalificado/a.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "La PIRÁMIDE ofrece dos cursos:\n"
	.string "Nivel 50 y Nivel Libre.\l"
	.string "¿Cuál va a elegir?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Muy bien. Ahora seleccione los tres\n"
	.string "POKéMON que desean acompañarle.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "¡Un pequeño problema, aventurero/a!\p"
	.string "Parece que no tiene los tres POKéMON\n"
	.string "cualificados para el desafío.\p"
	.string "Recuerde también quitar todos los\n"
	.string "objetos a sus POKéMON.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Cuando esté preparado/a, hable\n"
	.string "conmigo.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "¡Un pequeño problema, aventurero/a!\p"
	.string "Parece que no tiene los tres POKéMON\n"
	.string "cualificados para el desafío.\p"
	.string "Los tres POKéMON deben ser distintos\n"
	.string "y de Nivel 50 o inferior cada uno.\p"
	.string "Recuerde también quitar todos los\n"
	.string "objetos a sus POKéMON.\p"
	.string "Los HUEVOS{STR_VAR_1} no son válidos.\p"
	.string "Cuando esté preparado/a, hable\n"
	.string "conmigo.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Antes de entrar en la PIRÁMIDE BATALLA,\n"
	.string "debe guardarse la partida. ¿Está de\l"
	.string "acuerdo?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Muy bien. Ahora le acompañaré al\n"
	.string "interior de la PIRÁMIDE BATALLA.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Guardaremos su MOCHILA mientras\n"
	.string "explora, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "A cambio, tome este BOLSO de BATALLA,\n"
	.string "el que usó anteriormente.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "A cambio, tome este\n"
	.string "BOLSO de BATALLA.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} cambió la MOCHILA por\n"
	.string "el BOLSO de BATALLA.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Cuando pise este panel del suelo,\n"
	.string "será transportado/a a una planta\l"
	.string "superior de la PIRÁMIDE.\p"
	.string "¡Espero que su búsqueda transcurra\n"
	.string "sin contratiempos!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "¡Un problema grave, explorador/a!\p"
	.string "No guardó la partida antes de terminar\n"
	.string "su desafío la última vez.\p"
	.string "En consecuencia, su desafío ha sido\n"
	.string "descalificado, lo siento.\p"
	.string "Aquí tiene la MOCHILA que le hemos\n"
	.string "estado guardando.\p"
	.string "{PLAYER} recuperó la MOCHILA.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "¡Excelente verle de vuelta!\p"
	.string "¡Ha conquistado la PIRÁMIDE!\n"
	.string "¡Qué espléndido!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, un pequeño problema.\p"
	.string "Al menos un POKéMON lleva un objeto.\p"
	.string "Lamento decir que los objetos obtenidos\n"
	.string "en la PIRÁMIDE no pueden ser llevados\l"
	.string "fuera.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Todos los objetos que lleven sus\n"
	.string "POKéMON se moverán a su BOLSO de\l"
	.string "BATALLA, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Lamento decir que el BOLSO de BATALLA\n"
	.string "no puede guardar todos sus objetos.\p"
	.string "Seleccione los objetos que guardará en\n"
	.string "el BOLSO de BATALLA y los que llevarán\l"
	.string "sus POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Al menos un POKéMON todavía lleva\n"
	.string "un objeto.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Seleccione los objetos que guardará en\n"
	.string "el BOLSO de BATALLA y los que llevarán\l"
	.string "sus POKéMON.$"

@ Sin usar
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} devolvió todo lo que\n"
	.string "llevaban los POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "El BOLSO de BATALLA que usó se guardará\n"
	.string "a la espera de su próximo desafío.\p"
	.string "{PLAYER} entregó el BOLSO de BATALLA\n"
	.string "para recuperar la MOCHILA.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Debo registrar sus resultados.\n"
	.string "Espere, por favor.$"

@ Sin usar
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "Como recuerdo por haber conquistado\n"
	.string "la PIRÁMIDE BATALLA, tome esto.$"

@ Sin usar
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} recibió el premio\n"
	.string "{STR_VAR_1}.$"

@ Sin usar
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah…\n"
	.string "Su MOCHILA parece estar llena.\p"
	.string "Vuelva después de haber organizado\n"
	.string "el contenido de su MOCHILA.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Qué decepción para usted…\p"
	.string "Aquí tiene la MOCHILA que le hemos\n"
	.string "estado guardando.\p"
	.string "{PLAYER} recuperó la MOCHILA.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "¡Esperamos su próximo desafío!$"

@ Sin usar
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "¡Le estábamos esperando!\p"
	.string "Aquí tiene su premio por haber\n"
	.string "conquistado la PIRÁMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Bienvenido/a…\p"
	.string "Me complace decirle qué desgracias\n"
	.string "le aguardan en la PIRÁMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "¡Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Veo una lluvia de chispas…\p"
	.string "…Y en ella veo a sus POKéMON\n"
	.string "luchando contra la parálisis…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Veo veneno…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "los efectos del veneno…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Veo llamas rojas brillantes…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "las quemaduras…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Siento la tremenda presión de una ira\n"
	.string "no correspondida…\p"
	.string "Es una maldición…\p"
	.string "…Y veo a sus POKéMON sin Puntos de\n"
	.string "Poder y sin más remedio que usar\l"
	.string "COMBATE…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Veo POKéMON elevándose por los aires…\p"
	.string "…Y veo a sus POKéMON frustrados por\n"
	.string "los movimientos de tipo TIERRA\l"
	.string "inútiles…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Siento una energía tremenda emanando\n"
	.string "del suelo…\p"
	.string "…Y veo a sus POKéMON incapaces de\n"
	.string "escapar de las garras de ese poder…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Veo POKéMON de tipo HIELO…\p"
	.string "…Y veo a sus POKéMON luchando contra\n"
	.string "los efectos congelantes del hielo…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Veo una lluvia de movimientos que\n"
	.string "ponen en peligro al usuario…\p"
	.string "…Y veo a sus POKéMON cayendo\n"
	.string "ante ellos…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Veo POKéMON de tipo PSÍQUICO…\p"
	.string "…Y veo a sus POKéMON atormentados\n"
	.string "por movimientos PSÍQUICOS…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Veo POKéMON de tipo ROCA…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "movimientos de tipo ROCA…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Veo POKéMON de tipo LUCHA…\p"
	.string "…Y veo a sus POKéMON apaleados\n"
	.string "por movimientos de tipo LUCHA…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "DANZA LLUVIA… DÍA SOLEADO…\n"
	.string "TORMENTA ARENA… GRANIZO…\p"
	.string "Veo POKéMON que se vuelven más\n"
	.string "fuertes con el clima…\p"
	.string "…Y veo a sus POKéMON desconcertados\n"
	.string "por diferentes tipos de movimientos…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Veo POKéMON de tipo BICHO…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "diferentes tipos de ataques…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Veo POKéMON de tipo SINIESTRO…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "movimientos de tipo SINIESTRO…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Veo POKéMON de tipo AGUA…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "movimientos de tipo AGUA…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Veo POKéMON de tipo FANTASMA…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "movimientos de tipo FANTASMA…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Veo POKéMON de tipo ACERO…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "movimientos enormemente poderosos…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Veo POKéMON voladores…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "movimientos enormemente poderosos…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Veo a aquellos que han evolucionado\n"
	.string "gracias al poder de las piedras…\p"
	.string "También siento fuego, agua\n"
	.string "y electricidad…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "esos tres poderes…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Veo POKéMON de tipo NORMAL…\p"
	.string "…Y veo a sus POKéMON sufriendo\n"
	.string "movimientos enormemente poderosos…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Ya sea que crea en mis predicciones\n"
	.string "o no, la elección es suya…\p"
	.string "El futuro puede cambiarse en cualquier\n"
	.string "momento… Le deseo un buen viaje…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "¿Lo sabía?\p"
	.string "Si corre rápido, los ENTRENADORES\n"
	.string "pueden notarlo/a y perseguirle para\l"
	.string "combatir.\p"
	.string "Así que, si quiere evitar a los\n"
	.string "ENTRENADORES, no les llame la\l"
	.string "atención, sino pase desapercibido/a\l"
	.string "con cautela y silencio.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "¡Aaaaaaaaarrrrgh!\p"
	.string "¡Tenía un montón de objetos, pero los\n"
	.string "perdí todos cuando perdí!\p"
	.string "¡Aaaaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "¡Bienvenido/a de vuelta!\n"
	.string "¡Ha hecho lo impensable!\p"
	.string "¡Ha derrotado al REY de la PIRÁMIDE\n"
	.string "y ha conquistado la PIRÁMIDE BATALLA!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "¡Joven explorador/a!\n"
	.string "En reconocimiento a su valor, le\l"
	.string "otorgamos estos Punto(s) de Batalla!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Se muestran las reglas de la Búsqueda\n"
	.string "de la Batalla.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "¿Qué apartado quiere leer?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Cuando se conquista la PIRÁMIDE, los\n"
	.string "POKéMON salvajes que aparecen en ella\l"
	.string "son reemplazados por otros tipos\l"
	.string "diferentes.\p"
	.string "Explore, observe y aprenda qué tipos\n"
	.string "de POKéMON salvajes puede encontrar.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Los ENTRENADORES le están esperando\n"
	.string "dentro de la PIRÁMIDE.\p"
	.string "En cada planta hay hasta ocho\n"
	.string "ENTRENADORES.\p"
	.string "Cuando derrote a un ENTRENADOR,\n"
	.string "obtendrá una pista útil para su\l"
	.string "aventura.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Los laberintos de la PIRÁMIDE se\n"
	.string "reorganizan cada vez que entra en\l"
	.string "ella.\p"
	.string "Los laberintos están pobremente\n"
	.string "iluminados. Debe avanzar con\l"
	.string "precaución.\p"
	.string "La luz se hace más brillante cada vez\n"
	.string "que derrota a un POKéMON salvaje o a\l"
	.string "un ENTRENADOR.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "El BOLSO de BATALLA sirve como su\n"
	.string "MOCHILA mientras está en la PIRÁMIDE.\p"
	.string "Hay dos BOLSOS de BATALLA separados:\n"
	.string "uno para la aventura de Nivel 50 y\l"
	.string "otro para la de Nivel Libre.\p"
	.string "Cada uno puede contener hasta 99\n"
	.string "unidades de diez tipos de objetos.\p"
	.string "El contenido del BOLSO de BATALLA se\n"
	.string "pierde si fracasa en su búsqueda.$"

