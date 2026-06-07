SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "AQUILES: Alto ahí.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "AQUILES: Fufufu…\n"
	.string "Así que eras tú, después de todo.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "AQUILES: ¡Contemplad!\p"
	.string "¡Ved qué hermoso es, la forma dormida\n"
	.string "del POKéMON ancestral KYOGRE!\p"
	.string "He esperado tanto tiempo a que llegara\n"
	.string "este día…$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "AQUILES: Me sorprende cómo has\n"
	.string "conseguido perseguirme hasta aquí.\p"
	.string "Pero eso se ha acabado.\p"
	.string "Para la realización de mi sueño,\n"
	.string "¡debes desaparecer ahora!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "¿Qué?!\n"
	.string "¡¿He perdido contra un simple crío como\l"
	.string "tú?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "AQUILES: Fufufu…\p"
	.string "Te felicito. Debo reconocer que eres\n"
	.string "verdaderamente dotado.\p"
	.string "¡Pero!\n"
	.string "¡Tengo esto en mi posesión!\p"
	.string "¡Con esta ESFERA ROJA, puedo hacer que\n"
	.string "KYOGRE…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "¡La ESFERA ROJA de repente empezó a\n"
	.string "brillar por sí sola!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "AQUILES: ¿Qué?!\p"
	.string "No he hecho nada.\n"
	.string "¿Por qué la ESFERA ROJA…?\p"
	.string "¿Adónde ha ido KYOGRE?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "AQUILES: ¿Mmm? Es un mensaje de\n"
	.string "nuestros miembros de fuera…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "AQUILES: Sí, ¿qué pasa?\p"
	.string "Mmm…\n"
	.string "¿Está lloviendo mucho?\p"
	.string "Bien… Eso debería haber pasado.\n"
	.string "Por eso despertamos a KYOGRE,\l"
	.string "para realizar la visión del EQUIPO AQUA\l"
	.string "de expandir el mar.\p"
	.string "¿Qué?!\p"
	.string "¿Está lloviendo mucho más de lo que\n"
	.string "habíamos previsto? ¿Estás en peligro?\p"
	.string "Eso no puede ser…\n"
	.string "Eso simplemente no es posible…\p"
	.string "¡Mantén la posición y vigila la\n"
	.string "situación!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "AQUILES: Hay algo que no va bien…\p"
	.string "La ESFERA ROJA debería despertar y\n"
	.string "controlar a KYOGRE…\p"
	.string "Pero… ¿Por qué?\n"
	.string "¿Por qué KYOGRE ha desaparecido?\p"
	.string "¿¡Por qué?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MÁXIMO: ¿Qué has provocado?\p"
	.string "AQUILES… Por fin has despertado a\n"
	.string "KYOGRE, ¿verdad?\p"
	.string "¿Qué le pasará al mundo si este diluvio\n"
	.string "continúa por toda la eternidad?\p"
	.string "¡La masa terrestre del mundo se ahogará\n"
	.string "en el mar cada vez más profundo…$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "AQUILES: ¿Q-qué?!\n"
	.string "¡No te pongas tan altivo conmigo!\p"
	.string "¿No fuiste tú, el EQUIPO MAGMA, quien\n"
	.string "enfureció a GROUDON?\p"
	.string "Mientras tenga esta ESFERA ROJA,\n"
	.string "debería poder controlar a KYOGRE…\p"
	.string "Debería poder controlarlo…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MÁXIMO: ¡No tenemos tiempo para discutir\n"
	.string "sobre eso aquí!\p"
	.string "¡Sal fuera y míralo con tus propios ojos!\p"
	.string "¡Mira si lo que has provocado es el\n"
	.string "mundo que deseábamos!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MÁXIMO: {PLAYER}, vamos, ¡tú también\n"
	.string "tienes que salir de aquí!$"
