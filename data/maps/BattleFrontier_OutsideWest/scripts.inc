BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "¡Esta es la Cúpula Batalla!\n"
	.string "¡Tu camino hacia la superestrella\l"
	.string "invencible!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "¡Esta es la Fábrica Batalla!\n"
	.string "¡Busca los Pokémon más duros!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "¡Esta es la Sierpe Batalla!\n"
	.string "¡Elige uno de los tres caminos!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Esta es la Torre Batalla.\p"
	.string "Los entrenadores traen sus Pokémon\n"
	.string "mejor criados para combates por\l"
	.string "eliminatorias.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Hola, ¿estás aquí para el ferry?\n"
	.string "¿Puedo ver tu billete?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} no tiene el billete…\p"
	.string "Lo siento mucho.\p"
	.string "Debes tener un billete para subir\n"
	.string "al ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} mostró el billete.\p"
	.string "¡Perfecto! ¡Eso es todo lo que\n"
	.string "necesitas!\p"
	.string "¿Y a dónde te gustaría ir?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "¡Entonces, Ciudad Portual!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "¡Entonces, Ciudad Calagua!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "¡Navega con nosotros en otra ocasión!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Por favor, sube al ferry y espera la\n"
	.string "salida.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Entonces, ¿a dónde te gustaría ir?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Soy el mejor de todos mis amigos.\n"
	.string "Pero aquí…\l"
	.string "¡He sido inútil!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Quiero ir a la Torre Batalla, pero no\n"
	.string "la encuentro aunque tengo un mapa del\l"
	.string "Frente Batalla.\p"
	.string "¡Este lugar es demasiado grande!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Quería aceptar un desafío en cuanto\n"
	.string "llegara aquí.\p"
	.string "Pero en el camino me mareé…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "No es que cualquiera pueda venir aquí,\n"
	.string "¿sabes?\p"
	.string "Solo aquellos entrenadores que han sido\n"
	.string "reconocidos como duros son traídos aquí.\p"
	.string "Por eso muchos entrenadores ni siquiera\n"
	.string "saben del Frente Batalla.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Oye, hermano…\p"
	.string "¿Estás seguro de que podemos hacer\n"
	.string "desafíos incluso si no tenemos Pokémon?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Uh…\n"
	.string "Seguro que estará bien.\p"
	.string "Creo…\p"
	.string "¿Pero recuerdas a ese tipo grande y\n"
	.string "aterrador? Dijo: “¡Te prestaré Pokémon!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Esa es la Fábrica Batalla. Puedes\n"
	.string "alquilar Pokémon fuertes allí.\p"
	.string "Pero me hace preguntarme.\n"
	.string "¿Quién está criando esos Pokémon de\l"
	.string "alquiler?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Me da miedo entrar en la Sierpe Batalla\n"
	.string "por culpa de Seviper…\p"
	.string "P-pero he venido hasta aquí, así que voy\n"
	.string "a intentar conquistar todo.\l"
	.string "…Escalofrío…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "¡Juguemos a piedra, papel o tijera!\n"
	.string "¡Una, dos, tres!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "¡Yay! ¡He ganado!\n"
	.string "¡Aceptaré el desafío de la Sierpe\l"
	.string "Batalla!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, no…\n"
	.string "He perdido.\p"
	.string "Supongo que no tengo mucha suerte hoy.\n"
	.string "Pospondré mi desafío de la Sierpe\l"
	.string "Batalla hasta mañana.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Creo que soy la única persona aquí que,\n"
	.string "por alguna razón desconocida, elegiría\l"
	.string "pescar en lugar de luchar.\p"
	.string "¿Eh? ¿No se puede pescar nada aquí?\n"
	.string "Eso es decepcionante…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Hoy voy a seguir luchando, pase lo que\n"
	.string "pase, hasta que consiga un Símbolo.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "¿Oh? ¿Vas a desafiar la Cúpula\n"
	.string "Batalla?\p"
	.string "Te deseo la mejor de las suertes.\n"
	.string "Que ambos ganemos y nos encontremos\l"
	.string "en los desafíos.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "¡Abuelo, por aquí!\n"
	.string "¡La Cúpula Batalla está aquí!\l"
	.string "¡Vamos, abuelo!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, ¿así que esta es la Cúpula\n"
	.string "Batalla?\p"
	.string "¡No dejaré que los caballeros me\n"
	.string "venzan!\p"
	.string "Pero ¿dónde está la entrada?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Hace no mucho tiempo no había nada\n"
	.string "aquí.\p"
	.string "Pero, ¡mira este lugar ahora! ¡Increíble!\n"
	.string "Traeré a mi madre para que lo vea.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "¡Por fin he llegado al Frente Batalla!\p"
	.string "¡Seguro que llamaré la atención con\n"
	.string "mi aspecto y habilidad!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Ñam, ñam…\p"
	.string "Parece que esta plaza está llena de\n"
	.string "gente dura.\p"
	.string "Ñam, ñam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Cruj, ñam…\p"
	.string "Hace un tiempo, conocí a una chica\n"
	.string "mayor en la Sierpe Batalla.\p"
	.string "Tenía unos ojos que daban miedo de\n"
	.string "una manera realmente terca.\p"
	.string "Cruj, ñam…\p"
	.string "Se puso furiosa: “¿¡Vas a dejar de\n"
	.string "comer!?” Y me dio una paliza.\p"
	.string "Fue una experiencia aterradora de\n"
	.string "verdad.\p"
	.string "Cruj, ñam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "¿Eh? ¿Te escuchas a ti mismo?\n"
	.string "¡Eso no es nada!\p"
	.string "Vaya, la última vez que le animé,\n"
	.string "nuestras miradas se cruzaron y saltaron\l"
	.string "chispas.$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "¡¿Quééééé?!\n"
	.string "¡Pfft!\p"
	.string "¡Eso solo pasó porque me senté\n"
	.string "junto a ti!\p"
	.string "El As de la Cúpula solo miró hacia\n"
	.string "nosotros porque mi animación era tan\l"
	.string "fuerte.$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "¡Oh, cállate!\n"
	.string "¡Baja esa bulla!\p"
	.string "¡Vosotros, fans de ocasión, deberíais\n"
	.string "animar a algún líder de Gimnasio!\p"
	.string "¡El As de la Cúpula es mío!\n"
	.string "¡Mi único ídolo!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Esas personas discutiendo allí…\p"
	.string "Es difícil de creer, pero una vez\n"
	.string "fueron entrenadores, y buenos.\p"
	.string "Solían ser increíblemente duros y\n"
	.string "también eran famosos.\p"
	.string "Pero fueron destrozados por un cierto\n"
	.string "entrenador en un torneo.\p"
	.string "Fueron tan completamente vapuleados que\n"
	.string "se enamoraron del entrenador.\p"
	.string "Ahora son solo fans del entrenador.\n"
	.string "Van a animar a su ídolo a la Cúpula\l"
	.string "Batalla todos los días.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Escuché un rumor de que alguien vio un\n"
	.string "Pokémon con una cola inusualmente larga\l"
	.string "en algún lugar del Frente Batalla.\p"
	.string "Debe ser adorable. Estoy seguro…\p"
	.string "Oh, los desafíos pueden esperar. Me siento\n"
	.string "impulsado a encontrar la encantadora\l"
	.string "criatura.$"

