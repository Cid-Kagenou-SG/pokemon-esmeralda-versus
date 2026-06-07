PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "No puedo ver la Isla Espejismo hoy…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "¡Oh! ¡Dios mío!\n"
	.string "¡Puedo ver la Isla Espejismo hoy!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "Isla Espejismo…\p"
	.string "Debe hacerse visible e invisible\n"
	.string "dependiendo de las condiciones\l"
	.string "meteorológicas que hacen aparecer\l"
	.string "espejismos.\p"
	.string "¿O es que realmente aparece y\n"
	.string "desaparece?$"

