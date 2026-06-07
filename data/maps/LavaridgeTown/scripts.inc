LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "AURA: ¡{PLAYER}{KUN}! ¡Cuánto tiempo!\p"
	.string "¿Oh? Mientras visitaba los manantiales\n"
	.string "termalas, has conseguido la Medalla del\l"
	.string "Gimnasio de Lavacalda.\p"
	.string "Debes de haber coleccionado buenos\n"
	.string "Pokémon…\l"
	.string "No, creo que has criado algunos.\p"
	.string "Supongo que estaría bien que tú\n"
	.string "tuvieras esto.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "AURA: Con esas Gaf. Aislan, no tendrás\n"
	.string "problemas para atravesar el desierto\l"
	.string "cerca de la Ruta 111.\p"
	.string "Pero, vaya, {PLAYER}{KUN}…\n"
	.string "Desafiando Gimnasios…\p"
	.string "¡Estás esforzándote mucho porque no\n"
	.string "quieres perder contra mí, apuesto!\p"
	.string "{PLAYER}{KUN}, creo que debería desafiar\n"
	.string "a tu padre en el Gimnasio de Petalia.\p"
	.string "¡Nos vemos!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRUNO: {PLAYER}, hola, hace tiempo.\n"
	.string "¿Qué tal?\p"
	.string "Mmm…\n"
	.string "Esa es una buena colección de Medallas.\p"
	.string "Vale, entonces.\n"
	.string "También puedes tener esto.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRUNO: Llévate eso contigo si planeas\n"
	.string "ir a ese desierto cerca de la Ruta 111.\p"
	.string "Debería haber algunos Pokémon que son\n"
	.string "exclusivamente habitantes del desierto.\l"
	.string "Podrías buscar por ahí.\p"
	.string "En cuanto a mí…\n"
	.string "Estoy considerando desafiar a Norman,\l"
	.string "el líder del Gimnasio de Petalia.\p"
	.string "A diferencia de ti, {PLAYER}, tu padre\n"
	.string "parece que realmente es duro.\p"
	.string "¡Nos vemos!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Tengo aquí un Huevo.\p"
	.string "Esperaba incubarlo cubriéndolo con\n"
	.string "arena caliente junto a los manantiales\l"
	.string "termales.\l"
	.string "Pero eso no parece ser suficiente…\p"
	.string "He oído que sería mejor si se mantuviera\n"
	.string "junto a Pokémon y se llevara consigo.\p"
	.string "Eres un entrenador, ¿verdad?\n"
	.string "Y tus Pokémon irradian vitalidad.\p"
	.string "Entonces, ¿qué dices?\n"
	.string "¿Quieres llevarte este Huevo para\l"
	.string "incubarlo?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "¡Bien! ¡Espero que camines mucho con\n"
	.string "este Huevo!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} recibió el Huevo.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "¿Oh? Tienes demasiados Pokémon.\n"
	.string "No hay espacio para este Huevo…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Como desees, entonces…\p"
	.string "Si cambias de opinión sobre incubar\n"
	.string "este Huevo, estaré aquí.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "De vez en cuando, se encuentra un Huevo\n"
	.string "en la Guardería Pokémon.\p"
	.string "O al menos eso dice el rumor.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Sacamos toda el agua caliente que\n"
	.string "necesitamos, y sin embargo los\l"
	.string "manantiales termales nunca se secan.\p"
	.string "¿No es mágico?\p"
	.string "Estos manantiales termales aparecen\n"
	.string "cerca de volcanes activos. Las venas de\l"
	.string "agua bajo tierra se calientan por el\l"
	.string "magma hasta brotar como manantiales\l"
	.string "termales.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Estar enterrado en esta arena caliente\n"
	.string "es…\l"
	.string "Uf…\p"
	.string "Tan cálido y celestial…\p"
	.string "¿Eh? ¡Gyaaah! ¡Ay!\p"
	.string "¡Un Pokémon me ha mordido el trasero!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, ¿te gustan los manantiales termales?\p"
	.string "Es sorprendente para alguien tan joven\n"
	.string "como tú.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Me baño en los manantiales termales\n"
	.string "todos los días.\p"
	.string "Quiero convertirme en una líder de\n"
	.string "Gimnasio hermosa y fuerte como Candela.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Si la gente metiera Pokémon en los\n"
	.string "manantiales termales, podría ser muy\l"
	.string "extraño.\p"
	.string "Vaya, podría ser un baño eléctrico, o\n"
	.string "un baño de burbujas, o incluso un baño\l"
	.string "de lava…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Dicen que estos manantiales termales son\n"
	.string "buenos para calmar la tensión nerviosa,\l"
	.string "aliviar los músculos doloridos, resolver\l"
	.string "problemas románticos y atraer dinero…$"

LavaridgeTown_Text_TownSign:
	.string "PUEBLO LAVACALDA\p"
	.string "“MANANTIALES TERMALES DEL CENTRO\n"
	.string "POKÉMON ¡Un lugar excelente para\l"
	.string "relajarse!”$"

LavaridgeTown_Text_GymSign:
	.string "GIMNASIO POKÉMON DE PUEBLO LAVACALDA\n"
	.string "LÍDER: CANDELA\l"
	.string "“¡Una con una pasión ardiente!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "TIENDA DE HIERBAS POKÉMON\n"
	.string "“¡Sabor amargo, mejor cura!”$"

