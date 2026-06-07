AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Los barcos de este tipo son raros, así que\n"
	.string "estoy echando un vistazo.\p"
	.string "Mmm, mmm…\n"
	.string "Parece que hay más cabinas…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "¿Qué demonios te ha llevado a venir aquí?\n"
	.string "¡Debes de ser muy curioso!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "No solo curioso, sino también fuerte…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "El hombre de al lado…\p"
	.string "Dice que solo está de visita,\n"
	.string "pero no me lo creo.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "¡Eres un ENTRENADOR tan duro!\n"
	.string "¡Déjame registrarte como recuerdo!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "¿Qué demonios te ha llevado a volver?\n"
	.string "¡Debes de ser realmente muy curioso!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "¿No eres demasiado fuerte?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "¡Estoy segura de que ese hombre está tramando algo!\n"
	.string "¡Se comporta de forma tan sospechosa!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "¡Waaah!\n"
	.string "¡Me han encontrado! …¿Eh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, no eres mi madre.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Me he metido en problemas con mi madre, así que\n"
	.string "he huido. ¡No le digas a nadie dónde estoy!$"

