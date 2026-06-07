LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Mmm, así que duplicaron a los huéspedes\n"
	.string "usando Pokémon como atracciones?\p"
	.string "Mmm, bueno, quizá debería hacer de un\n"
	.string "Pokémon mono la mascota de nuestro\l"
	.string "motel.\p"
	.string "Me pregunto si eso atraería a más\n"
	.string "huéspedes a quedarse con nosotros.$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, perdón, perdón!\n"
	.string "¡Estaba demasiado concentrado viendo\l"
	.string "la tele!\p"
	.string "Desde que ese Equipo Aqua vino al\n"
	.string "pueblo, los turistas se han mantenido\l"
	.string "alejados.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "¡Eh, abajo en frente!\n"
	.string "¡No puedo ver la tele!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "¡Increíble! ¿Me estás diciendo que un\n"
	.string "Pokémon encontró el objeto perdido de\l"
	.string "alguien?\p"
	.string "Eso es algo. Si tuviéramos algunos\n"
	.string "Pokémon inteligentes como ese…\p"
	.string "Podríamos recuperar cualquier cosa\n"
	.string "que nuestros huéspedes hayan extraviado…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, perdón, perdón!\n"
	.string "¡Estaba demasiado concentrado viendo\l"
	.string "la tele!\p"
	.string "He oído que alguien destrozó la\n"
	.string "Guarida Aqua.\p"
	.string "Gracias a eso, acabamos de reservar\n"
	.string "para un grupo grande.\p"
	.string "Era una empresa llamada… Ehm…\n"
	.string "GAME algo…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "¡Increíble! ¿Un Pokémon que cuidaba la\n"
	.string "casa atrapó a un ladrón?\p"
	.string "Eso es algo. Si tuviéramos un Pokémon\n"
	.string "duro como guardia de seguridad…\p"
	.string "Podríamos proporcionar mayor seguridad\n"
	.string "a nuestros huéspedes.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, perdón, perdón!\n"
	.string "¡Estaba demasiado concentrado viendo\l"
	.string "la tele.\p"
	.string "Oh, sí. Un grupo grande de huéspedes\n"
	.string "llegó hace un rato.\p"
	.string "Se registraron como GAME FREAK,\n"
	.string "así que supongo que deben hacer juegos.\p"
	.string "¡Uf, será mejor que me ponga a trabajar\n"
	.string "en su cena!$"

