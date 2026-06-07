Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Soy el MANIÁTICO DE LOS FÓSILES...\n"
	.string "Soy un buen tipo que ama los FÓSILES...\p"
	.string "¿Quieres un FÓSIL?\p"
	.string "Pero los FÓSILES de por aquí son todos\n"
	.string "míos... Ninguno para ti...\p"
	.string "Si no puedes vivir sin un FÓSIL, busca\n"
	.string "en el desierto donde hay rocas y arena\l"
	.string "que pueden ocultar FÓSILES...$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Has encontrado un FÓSIL, ¿verdad?\n"
	.string "Qué suerte... Es tan maravilloso...\p"
	.string "¿Qué vas a hacer con ese FÓSIL?\p"
	.string "Por lo que he oído, DEVON está\n"
	.string "investigando cómo revivir POKéMON a\l"
	.string "partir de FÓSILES...\p"
	.string "Yo amo mis FÓSILES, así que nunca haría\n"
	.string "algo así...$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Los FÓSILES son tan... Maravillosos...\n"
	.string "Es tan maravilloso...$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh...\n"
	.string "No es seguro por ahí...\p"
	.string "Estaba cavando, ya ves...\n"
	.string "Cuando toda la pared se derrumbó...\p"
	.string "Creo que ahora hay una cueva gigante\n"
	.string "debajo...\p"
	.string "Pero la he dejado en paz porque no creo\n"
	.string "que haya FÓSILES allí...$"

