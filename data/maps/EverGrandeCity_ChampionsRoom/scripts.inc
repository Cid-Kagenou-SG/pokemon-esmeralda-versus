EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "PLUBIO: Bienvenido, {PLAYER}{KUN}.\p"
	.string "Ese incidente en Ciudad Arrecípolis…\n"
	.string "Fue un trabajo excelente, poner fin a\l"
	.string "esa crisis completamente por ti mismo.\p"
	.string "¡Ups!\p"
	.string "No sería justo decir que tú solo\n"
	.string "pusiste fin a la crisis.\p"
	.string "Superaste esa difícil situación\n"
	.string "trabajando como uno solo con tus\l"
	.string "Pokémon.\p"
	.string "Nosotros los entrenadores criamos a los\n"
	.string "Pokémon dándoles objetos y enseñándoles\l"
	.string "nuevas técnicas para el combate.\p"
	.string "Pero nosotros mismos también aprendemos\n"
	.string "muchas cosas de los Pokémon.\p"
	.string "Y es aquí donde tus logros son puestos\n"
	.string "a prueba contra lo que otros como tú\l"
	.string "han logrado.\p"
	.string "¡Ahora!\p"
	.string "¿Quién puede bailar con más elegancia\n"
	.string "con sus Pokémon en Hoenn?\p"
	.string "¡Muéstramelo aquí y ahora!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Yo, el Campeón, caigo derrotado…\p"
	.string "Fue un trabajo maravilloso.\n"
	.string "Fuiste elegante, irritantemente\l"
	.string "elegante. ¡Y aún así fue\l"
	.string "completamente glorioso!\p"
	.string "¡Mis felicitaciones, {PLAYER}{KUN}!\p"
	.string "¡Eres un entrenador Pokémon\n"
	.string "verdaderamente noble!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "PLUBIO: Los Pokémon que enviaste al\n"
	.string "combate…\p"
	.string "A veces bailaban como una brisa de\n"
	.string "primavera, y a veces golpeaban como el\l"
	.string "rayo.\p"
	.string "Fue con una elegancia ligera, pero\n"
	.string "segura, que guiaste a tus Pokémon.\p"
	.string "¡Incluso yo me sentí deslumbrado por tu\n"
	.string "actuación magistral!\p"
	.string "Ahora te encuentras en el glorioso pico\n"
	.string "de la Liga Pokémon.\p"
	.string "Ahora te proclamo el nuevo Campeón de\n"
	.string "la región de Hoenn…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "AURA: {PLAYER}{KUN}!\p"
	.string "Aquí tienes un consejo antes de que\n"
	.string "desafíes al Campeón…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "AURA: ¿Eh?\n"
	.string "¿Qué, qué, qué?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "¿Podría ser que…\l"
	.string "ya ha terminado?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRUNO: {PLAYER}!\p"
	.string "¿Qué te parece un consejo antes de que\n"
	.string "desafíes al Campeón?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRUNO: {PLAYER}…\p"
	.string "¿Me estás diciendo que…\n"
	.string "has vencido al Campeón?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. ABEDUL: ¿Ves?\n"
	.string "¿Qué te dije, {RIVAL}?\p"
	.string "¿No te dije que no necesitabas\n"
	.string "preocuparte por {PLAYER}{KUN}?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, por fin lo has conseguido.\p"
	.string "Cuando supe que habías derrotado a tu\n"
	.string "propio padre en el Gimnasio de Petalia,\l"
	.string "pensé que quizá tenías una oportunidad…\p"
	.string "Pero ¡pensar que realmente te has\n"
	.string "convertido en el Campeón!\p"
	.string "Ah, ¡sí!\p"
	.string "¿Qué fue de tu Pokédex?\n"
	.string "Aquí, déjame ver.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. ABEDUL: En fin,\n"
	.string "¡enhorabuena!\p"
	.string "¡Ahora, entra con orgullo en la sala\n"
	.string "final!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "PLUBIO: {PLAYER}{KUN}…\p"
	.string "No, permíteme reformularlo\n"
	.string "correctamente.\p"
	.string "¡El nuevo Campeón!\p"
	.string "Ven conmigo.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "PLUBIO: Lo siento, pero…\p"
	.string "Desde aquí, solo pueden entrar aquellos\n"
	.string "entrenadores que se han convertido en\l"
	.string "Campeones.\p"
	.string "Tendrás que esperar fuera con el\n"
	.string "Prof. Abedul.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "AURA: Uf…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "¡Solo bromeo! ¡Está bien!\n"
	.string "¡Esa es la regla!\p"
	.string "¡{PLAYER}{KUN}!\n"
	.string "¡Sinceramente, enhorabuena!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRUNO: ¡¿Quééé?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "No se puede hacer nada si esa es la\n"
	.string "regla.\p"
	.string "¡{PLAYER}, lo has hecho genial!\n"
	.string "¡Enhorabuena!$"

