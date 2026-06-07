BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "¡Bujajajá!\p"
	.string "Aunque no lo parezca ahora, yo fui una\n"
	.string "entrenadora de armas tomar.\p"
	.string "¡Era la Campeona de Belleza más dura\n"
	.string "de todas, te lo digo yo!\p"
	.string "… … … … … …\p"
	.string "¿Qué pasa ahora?\n"
	.string "No me crees.\p"
	.string "No soy como esa fanfarrona de ahí.\n"
	.string "¡De verdad tengo talento!\p"
	.string "Déjame demostrártelo.\n"
	.string "Puedo enseñar a tus Pokémon movimientos\l"
	.string "especiales y a la vez monos.\p"
	.string "Pero mis lecciones no son gratis.\n"
	.string "¿Qué tal si pagas por los movimientos\l"
	.string "que enseño con unos poquitos Puntos de\l"
	.string "Batalla?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "¡Bujajajá!\p"
	.string "¿Has vuelto para aprender movimientos\n"
	.string "especiales y a la vez monos para tus\l"
	.string "Pokémon?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Vale, vale, ¡mira aquí!\n"
	.string "¿Qué movimiento debería enseñar?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "¿El movimiento {STR_VAR_1}, dices?\n"
	.string "Serán {STR_VAR_2} Puntos de Batalla, ¿vale?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Vale, vale, ahora elige el Pokémon\n"
	.string "al que debo enseñar el movimiento.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "¿Pero qué…?\n"
	.string "¡No tienes suficientes Puntos de\l"
	.string "Batalla!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "¿Ya ves lo habilidosa que soy?\n"
	.string "¡Te quedo con tus Puntos de Batalla,\l"
	.string "gracias!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "¿Qué dices?\n"
	.string "No quieres…\p"
	.string "Si quieres ver lo habilidosa que soy,\n"
	.string "¡ven a verme cuando quieras!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "¡Ihihihi!\p"
	.string "Sé que es difícil de ver ahora, pero yo\n"
	.string "fui una entrenadora fantástica.\p"
	.string "¡Era la Nadadora más invencible de\n"
	.string "todas, te lo digo yo!\p"
	.string "… … … … … …\p"
	.string "¿Qué pasa?\n"
	.string "No me crees.\p"
	.string "No soy como esa payasa de ahí.\n"
	.string "¡De verdad tengo experiencia!\p"
	.string "Puedo demostrártelo.\n"
	.string "Puedo enseñar a tus Pokémon movimientos\l"
	.string "duros y a la vez bonitos.\p"
	.string "Pero mis lecciones no son gratis.\n"
	.string "¿Qué tal si pagas por los movimientos\l"
	.string "que enseño con unos poquitos Puntos de\l"
	.string "Batalla?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "¡Ihihihi!\p"
	.string "¿Has venido a aprender movimientos\n"
	.string "duros y a la vez bonitos para tus\l"
	.string "Pokémon?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Esas señoras, la forma en que se\n"
	.string "insultan, probablemente piensas que no\l"
	.string "se llevan bien.\p"
	.string "Pero si eso fuera cierto, no se\n"
	.string "quedarían aquí juntas, ¿verdad?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Cuando era solo un Joven, esas señoras\n"
	.string "eran fuertes y hermosas.\p"
	.string "Eran ídolos entre nosotros los\n"
	.string "entrenadores.\p"
	.string "Incluso ahora, la edad no ha embotado\n"
	.string "sus habilidades.\p"
	.string "De hecho, los movimientos de sus Pokémon\n"
	.string "han llegado a ser aún más pulidos.\p"
	.string "Pero… Por alguna razón, no puedo evitar\n"
	.string "sentir esto…\p"
	.string "El tiempo es tan cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Recupera hasta la\n"
	.string "mitad de los PS\n"
	.string "máximos del usuario.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflige daño\n"
	.string "idéntico al nivel\n"
	.string "del usuario.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Recupera la mitad\n"
	.string "del daño infligido\n"
	.string "a un rival dormido.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un puñetazo fuerte\n"
	.string "lanzado con\n"
	.string "increíble potencia.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Una patada\n"
	.string "extremadamente\n"
	.string "potente.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Un golpe con todo\n"
	.string "el cuerpo que\n"
	.string "puede paralizar.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Se lanzan grandes\n"
	.string "rocas. Puede hacer\n"
	.string "retroceder.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Devuelve cualquier\n"
	.string "golpe físico con\n"
	.string "el doble de fuerza.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Una débil descarga\n"
	.string "eléctrica que\n"
	.string "paraliza al rival.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Una danza guerrera\n"
	.string "que aumenta mucho\n"
	.string "el Ataque.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Se enrosca para\n"
	.string "ocultar puntos\n"
	.string "débiles y subir la\l"
	.string "Defensa.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Un fuerte ataque\n"
	.string "que solo se puede\n"
	.string "usar dormido.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Arroja lodo a la\n"
	.string "cara del rival\n"
	.string "para bajarle la\l"
	.string "Precisión.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Rocía rayos en\n"
	.string "forma de estrella\n"
	.string "que no fallan.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Un ataque gélido\n"
	.string "que baja la\n"
	.string "Velocidad del rival.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Resiste cualquier\n"
	.string "ataque durante 1\n"
	.string "turno, dejando 1 PS.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copia los efectos\n"
	.string "del rival y se los\n"
	.string "da al usuario.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Un puñetazo helado\n"
	.string "que puede\n"
	.string "congelar al rival.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Un puñetazo\n"
	.string "electrificado que\n"
	.string "puede paralizar al\l"
	.string "rival.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Un puñetazo ardiente\n"
	.string "que puede quemar\n"
	.string "al rival.$"
