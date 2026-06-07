SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Eres un ENTRENADOR POKéMON, ¿verdad?\p"
	.string "JUAN de ARRECÍPOLIS tiene muchos fans.\n"
	.string "¡Incluso más que su alumno PLUBIO!\p"
	.string "¿Tú tienes alguno?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, entonces debes de ser bastante\n"
	.string "fuerte.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, vaya…\n"
	.string "Eso es un poco triste.\p"
	.string "Esfuérzate un poco más para conseguir\n"
	.string "algún fan.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Fans de verdad vienen incluso de fuera\n"
	.string "de HOENN.\p"
	.string "Fue una auténtica locura cuando fui al\n"
	.string "CLUB DE FANS de CIUDAD CALAGUA.$"

