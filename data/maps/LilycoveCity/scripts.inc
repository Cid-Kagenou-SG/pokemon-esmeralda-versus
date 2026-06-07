LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "AURA: Oh, ¿{PLAYER}{KUN}?\n"
	.string "¿También estás de compras?\p"
	.string "He comprado un montón de muñecos y\n"
	.string "posters.\p"
	.string "Por supuesto, también he atrapado\n"
	.string "muchos Pokémon y los estoy criando\l"
	.string "bien.\p"
	.string "En realidad, me preocupa más si tú\n"
	.string "estás criando bien a tus Pokémon,\l"
	.string "{PLAYER}{KUN}.\p"
	.string "Vamos a luchar para que me enseñes\n"
	.string "tus Pokémon, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "AURA: Oh, ¿por qué? {PLAYER}{KUN}, ¿no\n"
	.string "has estado criando a tus Pokémon?\p"
	.string "Eso no es muy buena imagen para un\n"
	.string "entrenador…$"

LilycoveCity_Text_MayBattleMe:
	.string "AURA: Venga, lucha conmigo para que\n"
	.string "pueda ver tus Pokémon.$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "AURA: Los Pokémon que he criado no\n"
	.string "serán derrotados por los tuyos,\l"
	.string "{PLAYER}{KUN}.$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Recuerdo el combate que tuvimos en la\n"
	.string "Ruta 103, {PLAYER}{KUN}.\p"
	.string "Ese combate te ayudó a volverte tan\n"
	.string "fuerte, {PLAYER}{KUN}, ¿verdad?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "AURA: Estoy pensando en volver a\n"
	.string "Villa Raíz pronto.\p"
	.string "He atrapado un buen grupo de Pokémon\n"
	.string "y mi Pokédex va bien, así que voy a\l"
	.string "casa a enseñárselo a mi padre.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, ¿qué vas a hacer?\p"
	.string "¿Recoger todas las medallas de gimnasio\n"
	.string "y enfrentarte a la Liga Pokémon?\p"
	.string "Bueno, mientras tú recoges medallas,\n"
	.string "{PLAYER}{KUN}, yo voy a trabajar en mi\l"
	.string "Pokédex. ¡La completaré antes que tú!\p"
	.string "¡Nos vemos!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, ¿qué vas a hacer?\p"
	.string "¿Vas a enfrentarte a la Liga Pokémon?\p"
	.string "O, ¿vas a completar tu Pokédex?\p"
	.string "Puede que haya perdido contra ti en\n"
	.string "combate, pero ¡terminaré mi Pokédex\l"
	.string "antes que tú!\p"
	.string "¡Nos vemos!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, ¿qué vas a hacer?\p"
	.string "¿Vas a enfrentarte al Frente Batalla?\p"
	.string "O, ¿vas a completar tu Pokédex?\p"
	.string "Puede que haya perdido contra ti en\n"
	.string "combate, pero ¡terminaré mi Pokédex\l"
	.string "antes que tú!\p"
	.string "¡Nos vemos!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRUNO: Oh, hola, {PLAYER}.\p"
	.string "Estoy haciendo un recado para mi\n"
	.string "padre. No, no estoy comprando muñecos.\p"
	.string "En fin, hace tiempo que no nos vemos.\p"
	.string "¿Quieres luchar para ver quién ha\n"
	.string "estado criando mejor a sus Pokémon?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRUNO: Oh, ¿qué pasa?\n"
	.string "¿No tienes confianza?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRUNO: ¿Quieres luchar para ver quién\n"
	.string "ha estado criando mejor a sus Pokémon?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRUNO: Vaya, pero sabes que no voy a\n"
	.string "perder contra ti, {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Humph…\n"
	.string "Has criado mucho.\p"
	.string "Eso pica un poco: yo tenía ventaja\n"
	.string "como entrenador…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRUNO: Yo…\n"
	.string "Pienso volver a Villa Raíz.\p"
	.string "Sabes que estoy ayudando a mi padre con\n"
	.string "su Pokédex. Va bastante bien, así que\l"
	.string "debería ir a enseñárselo.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, ¿qué vas a hacer?\p"
	.string "¿Recoger todas las medallas de gimnasio\n"
	.string "y enfrentarte a la Liga Pokémon?\p"
	.string "Quizá yo también lo haga…\p"
	.string "Bueno, en fin, ¡ánimo!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, ¿qué vas a hacer?\p"
	.string "Como eres tan fuerte, ¿vas a\n"
	.string "enfrentarte a la Liga Pokémon?\p"
	.string "Je, incluso yo, si entreno un poco más\n"
	.string "a mis Pokémon, debería ser más fuerte\l"
	.string "que tú, {PLAYER}.\p"
	.string "Bueno, en fin, ¡ánimo!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, ¿qué vas a hacer?\p"
	.string "¿Vas a enfrentarte al Frente Batalla?\p"
	.string "O, ¿vas a completar tu Pokédex?\p"
	.string "Como eres tan fuerte, deberías\n"
	.string "plantértelo con el Frente Batalla.\p"
	.string "Je, si entreno un poco más a mis\n"
	.string "Pokémon, seré más fuerte que tú,\l"
	.string "{PLAYER}.\p"
	.string "Quizá yo también debería ir al\n"
	.string "Frente Batalla.\p"
	.string "Bueno, en fin, ¡ánimo!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Jijiji…\p"
	.string "Hoy hemos movido más botín a nuestra\n"
	.string "guarida secreta…\p"
	.string "¿Q-Quién eres tú?!\n"
	.string "¡Estaba hablando solo!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Soy solo un recluta, así que no sé lo\n"
	.string "que piensa el jefe…\p"
	.string "Pero siendo del Equipo Aqua, sé que\n"
	.string "tendré la oportunidad de hacer cosas\l"
	.string "grandes.\p"
	.string "¿Q-Quién eres tú?!\n"
	.string "¡Estaba hablando solo!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "¡Eh, tú!\p"
	.string "¡No te acerques a la cueva de la cala!\p"
	.string "¿Por qué? ¡No necesitas una razón!\n"
	.string "¡Soy un adulto, así que hazme caso!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Si todo este mundo se convierte en\n"
	.string "nuestro, del Equipo Aqua, también será\l"
	.string "un lugar más feliz para los Pokémon.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "¡Allí! ¡Wailmer!\n"
	.string "¡Salta fuera del agua ahora!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "¿Eh? ¿Qué quieres?\p"
	.string "Estás estropeando nuestro entrenamiento,\n"
	.string "así que ¿podrías, ya sabes, largarte?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Hay un Salón de Concursos Pokémon\n"
	.string "justo en este pueblo.\p"
	.string "Eso significa que vendrán Pokémon bien\n"
	.string "criados de todo el país.\p"
	.string "¡Mi corazón se llena de emoción!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "¿Has visto esa extraña cueva en la\n"
	.string "cala del borde del pueblo?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Voy a enseñar nuevos movimientos a mis\n"
	.string "Pokémon para participar en un Concurso.\p"
	.string "Así que voy a ver al Quita-Movimientos\n"
	.string "para que olviden los movimientos MO.$"

LilycoveCity_Text_ImFromKanto:
	.string "Vengo de Kanto.\p"
	.string "La región de Hoenn es hermosa con toda\n"
	.string "su agua y naturaleza verde.\p"
	.string "¿Eh? Espera un segundo…\p"
	.string "¿Podría haber Pokémon raros que vivan\n"
	.string "solo en esta zona?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "El Equipo Aqua ha estado entrenando a\n"
	.string "sus Wailmer en la cala.\p"
	.string "¡Nosotros los marineros no podemos\n"
	.string "sacar nuestros barcos al mar con ellos\l"
	.string "en medio!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "¡Ahoy, lo sabías?\p"
	.string "¡Alguien ha echado al Equipo Aqua de\n"
	.string "en medio por nosotros!\p"
	.string "Eso ha hecho que los Wailmer salgan de\n"
	.string "la cala, así que podemos sacar nuestros\l"
	.string "barcos otra vez.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Estaba echando una siesta relajante en\n"
	.string "la posada de la orilla escuchando las\l"
	.string "olas…\p"
	.string "¡Cuando alguien robó mi Pokémon!\p"
	.string "¿Quién es el secuestrador?\n"
	.string "¿El Equipo Aqua? ¿Es el Equipo Aqua?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Mi Pokémon desaparecido…\n"
	.string "¡Ha vuelto sin que me diera cuenta!$"

LilycoveCity_Text_ImArtDealer:
	.string "Soy un comerciante de arte.\p"
	.string "Compro y vendo arte fino,\n"
	.string "especialmente pinturas.\p"
	.string "He oído que el Museo de aquí tiene\n"
	.string "obras magníficas en exposición…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Incluso cuando envejecemos y nos\n"
	.string "arrugamos, el mar sigue siendo joven\l"
	.string "para siempre con el brillante fulgor\l"
	.string "de la vida…\p"
	.string "Jojojo jojojojojo…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Hace sesenta años que mi marido me\n"
	.string "pidió matrimonio aquí.\l"
	.string "El mar sigue siendo tan hermoso como\l"
	.string "siempre.\p"
	.string "Jujuju jujujujuju…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, ¿sabes de esa peculiar cueva en\n"
	.string "esta cala?\p"
	.string "Eso era una formación natural, pero\n"
	.string "luego vino ese grupo del Equipo Aqua\l"
	.string "y la renovaron.\p"
	.string "¡Se hacen llamar los “amantes de la\n"
	.string "naturaleza del Equipo Aqua”!\p"
	.string "¡Pero lo que hacen y lo que dicen no\n"
	.string "concuerdan en absoluto!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Esa cueva en la cala…\p"
	.string "No me di cuenta enseguida, pero\n"
	.string "está completamente vacía ahora.\p"
	.string "Ese grupo del Equipo Aqua debe de\n"
	.string "haberse ido para siempre.$"

LilycoveCity_Text_CitySign:
	.string "CIUDAD CALAGUA\p"
	.string "“Donde la tierra termina y\n"
	.string "el mar comienza.”$"

LilycoveCity_Text_ContestHallSign:
	.string "SALÓN DE CONCURSOS POKÉMON\n"
	.string "“¡El lugar de reunión de los\n"
	.string "entrenadores!”$"

LilycoveCity_Text_MotelSign:
	.string "MOTEL CALA LILIA\p"
	.string "“Recuérdanos como la Cala Lilia de\n"
	.string "Ciudad Calagua.”$"

LilycoveCity_Text_MuseumSign:
	.string "MUSEO DE CIUDAD CALAGUA\p"
	.string "“¡Exhibición de Obras Maestras\n"
	.string "Pokémon!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSEO DE CIUDAD CALAGUA\p"
	.string "“¡Exhibición de la Colección Pokémon\n"
	.string "de {PLAYER}!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "PUERTO DE CIUDAD CALAGUA\p"
	.string "“El ferry S.S. Marea está en\n"
	.string "construcción en Ciudad Portual.\p"
	.string "“El servicio comenzará\n"
	.string "próximamente.”$"

LilycoveCity_Text_HarborSign:
	.string "PUERTO DE CIUDAD CALAGUA\p"
	.string "“Disfruta de un encantador crucero en\n"
	.string "el ferry S.S. Marea.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "CLUB DE FANS DE ENTRENADORES POKÉMON\p"
	.string "Los nombres de los entrenadores están\n"
	.string "garabateados por todo el letrero…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "CENTRO COMERCIAL DE CIUDAD CALAGUA\p"
	.string "“¡Rebosante de grandes productos\n"
	.string "y emoción!\p"
	.string "“¡Un gran lugar para encontrar\n"
	.string "aquello que necesitas!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "CASA DEL QUITA-MOVIMIENTOS\p"
	.string "“Se eliminan los movimientos Pokémon\n"
	.string "no deseados.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "¿Sabes de la máquina Licuabayas?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "La gente tiene que trabajar junta para\n"
	.string "hacerla girar más rápido.\p"
	.string "Cuanto más rápido la hagas girar, mejores\n"
	.string "PokéCubos conseguirás, he oído.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Se usa para hacer un tipo de caramelo\n"
	.string "llamado PokéCubo.\p"
	.string "Si le das un buen PokéCubo a un Pokémon,\n"
	.string "su condición mejorará mucho.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "He oído que hay una torre en algún\n"
	.string "lugar de las rutas marítimas.\p"
	.string "Se llama Pilar Celeste, he oído.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Vi una torre muy alta en algún lugar\n"
	.string "de la Ruta 131.\p"
	.string "¿Podría ser…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Acabamos de llegar aquí en nuestras\n"
	.string "vacaciones de luna de miel.\p"
	.string "Por casualidad vimos un Pokémon de tipo\n"
	.string "Dragón volando muy alto en el cielo.\p"
	.string "¿Viven Pokémon tan guays como ese en\n"
	.string "la región de Hoenn?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "En nuestra luna de miel, prometimos ver\n"
	.string "tantos Pokémon raros como pudiéramos.\p"
	.string "Así que nos alegró mucho ver un Pokémon\n"
	.string "raro en cuanto llegamos.\p"
	.string "Quiero decir, ¡estamos totalmente\n"
	.string "felices!$"

