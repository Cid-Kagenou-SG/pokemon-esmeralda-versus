SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MONTE PÍRICO…\p"
	.string "En su cima hay dos esferas colocadas una al lado\n"
	.string "de la otra. ¿Lo sabías?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Sí, dos esferas una al lado de la otra…\p"
	.string "Verlas juntas…\n"
	.string "Es de algún modo reconfortante…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "¿Es eso cierto?\n"
	.string "Quizás deberías ir a verlo…$"

