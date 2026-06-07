MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "¡No! ¡Esos matones del Equipo Magma\n"
	.string "han llegado antes que nosotros!\p"
	.string "¡No podemos quedarnos atrás!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Pensaba que eras uno de los del Magma\n"
	.string "que había vuelto...$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Sí, eres fuerte...\n"
	.string "¡Pero somos muchos!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "¡Ja!\n"
	.string "¡Qué mala suerte para ti!\p"
	.string "Si hubieras venido antes, solo habrías\n"
	.string "tenido que luchar contra los débiles del\l"
	.string "Equipo Magma.\p"
	.string "¡Pero como has llegado ahora, te toca\n"
	.string "enfrentarte a los duros como nosotros!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Uf... Debería haberte dejado que te\n"
	.string "enfrentaras primero al Equipo Magma...$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "¡No sabes nada!\n"
	.string "¿Entonces por qué te metes con nosotros?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Tú...\n"
	.string "Te vimos en el Monte Cenizo.\p"
	.string "No perteneces a ningún equipo,\n"
	.string "¿por qué estás aquí?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Si vas a meterte con alguien,\n"
	.string "que sea con el Equipo Magma...$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Je, ¡no importa!\n"
	.string "¡Nos hemos ganado algo de tiempo!\p"
	.string "¡El jefe ya debe haber conseguido lo\n"
	.string "que buscaba!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "¡Oh, ya sé!\n"
	.string "¡Intentaste unirte al Equipo Magma,\l"
	.string "pero no te quisieron!\p"
	.string "¡Pues no pienses que te dejaremos\n"
	.string "unirte a nuestro Equipo Aqua!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Si quieres unirte al Equipo Aqua tanto\n"
	.string "como eso, podemos considerarlo...$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Tenemos una gran combinación entre\n"
	.string "nosotros, los miembros, y nuestro jefe.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "AQUILES: El Magno del Equipo Magma se\n"
	.string "nos adelantó, pero nosotros también\l"
	.string "conseguimos lo que queríamos.\p"
	.string "¡La Esfera Roja guardada en el Monte\n"
	.string "Pírico... Yo, Aquiles, ¡ahora la tengo en\l"
	.string "mi poder!\p"
	.string "¡Je, je, je... Ahora podremos llevar a\n"
	.string "cabo nuestro objetivo final!\p"
	.string "¡Vale, equipo!\n"
	.string "¡Nos retiramos!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, no...\n"
	.string "Esto no puede estar pasando...\p"
	.string "No solo la Esfera Azul, sino también\n"
	.string "la Esfera Roja han sido robadas...\p"
	.string "La Esfera Azul y la Esfera Roja nunca\n"
	.string "deben separarse. Deben estar juntas.\p"
	.string "¿Qué intentan hacer esos hombres con\n"
	.string "las dos Esferas?\p"
	.string "...\p"
	.string "Oh, sí. ¿Fue el Equipo Magma el que vino\n"
	.string "y se llevó la Esfera Azul primero?\p"
	.string "Bueno, en su prisa, dejaron esto\n"
	.string "atrás.\p"
	.string "No me imagino qué puede ser\n"
	.string "exactamente.\p"
	.string "Me gustaría que lo tuvieras tú.\n"
	.string "Quizás te sea útil de alguna manera.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "La Esfera Azul y la Esfera Roja robadas\n"
	.string "por esos hombres siniestros...\p"
	.string "Nunca deben separarse...\n"
	.string "Temo que ocurra algo terrible...$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, Dios mío...\p"
	.string "¿Dices que tanto Groudon como Kyogre\n"
	.string "han sido despertados?\p"
	.string "Se dice que la Esfera Azul y la Esfera\n"
	.string "Roja calmaban la furia de los dos\l"
	.string "Pokémon...\p"
	.string "También se dice que el verdadero dueño\n"
	.string "de las Esferas aún existe.\p"
	.string "Sin embargo, nadie sabe quién, o qué\n"
	.string "exactamente, es al que pertenecen las\l"
	.string "Esferas.\p"
	.string "Podría ser un humano, o quizás un\n"
	.string "Pokémon, pero nadie lo sabe.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Los dos hombres que se llevaron las\n"
	.string "Esferas volvieron para devolverlas por\l"
	.string "su propia voluntad.\p"
	.string "Esos hombres...\n"
	.string "Quizás no sean tan malvados después de\l"
	.string "todo...$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Las encarnaciones de la tierra, el mar\n"
	.string "y el cielo...\p"
	.string "Se dice que esa es la identidad de los\n"
	.string "Pokémon superancestrales...\p"
	.string "De la misma manera que nosotros, los\n"
	.string "humanos y los Pokémon, tenemos vida,\l"
	.string "nuestro mundo también está vivo...\p"
	.string "Los Pokémon superancestrales nos han\n"
	.string "enseñado eso...$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "El Monte Pírico es donde calmamos los\n"
	.string "espíritus de los Pokémon que han\l"
	.string "fallecido...\p"
	.string "Este es un lugar elevado desde donde se\n"
	.string "puede ver toda Hoenn...\p"
	.string "Los espíritus desencarnados de los\n"
	.string "Pokémon deben encontrar consuelo aquí...\p"
	.string "¿Es casualidad que estés aquí...\p"
	.string "¿Quieres escuchar mi historia? Una\n"
	.string "historia contada desde hace mucho en la\l"
	.string "región de Hoenn?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Ocurrió hace mucho, mucho tiempo...\p"
	.string "El mundo fue sacudido por un feroz\n"
	.string "enfrentamiento entre el Pokémon de la\l"
	.string "tierra y el Pokémon del mar...\p"
	.string "El Pokémon de la tierra levantó\n"
	.string "montañas y creó continentes...\p"
	.string "El Pokémon del mar levantó enormes\n"
	.string "olas y talló océanos...\p"
	.string "Su feroz duelo se prolongó sin fin.\p"
	.string "El mundo fue engullido por masivos\n"
	.string "incendios y violentas tormentas.\p"
	.string "La Esfera Azul y la Esfera Roja pusieron\n"
	.string "fin a la calamidad.\p"
	.string "La luz emanada de las dos Esferas calmó\n"
	.string "a los adversarios enfurecidos.\p"
	.string "La pareja, hecha dócil, se sumergió en\n"
	.string "lo profundo del mar donde finalmente\l"
	.string "desapareció...$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Ya veo...\n"
	.string "Bueno, eso también está bien...$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAGNO: {PLAYER}...\p"
	.string "...\p"
	.string "...$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Es mi papel transmitir las leyendas de\n"
	.string "Hoenn a las generaciones futuras.\p"
	.string "Y la crisis que acaba de terminar en\n"
	.string "Ciudad Algaria reescribió una leyenda...\p"
	.string "¿Tienes tiempo para escuchar la nueva\n"
	.string "leyenda de Hoenn?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Ocurrió hace mucho, mucho tiempo...\p"
	.string "El mundo fue sacudido por un feroz\n"
	.string "enfrentamiento entre el Pokémon de la\l"
	.string "tierra y el Pokémon del mar...\p"
	.string "El Pokémon de la tierra levantó\n"
	.string "montañas y creó continentes...\p"
	.string "El Pokémon de la tierra levantó enormes\n"
	.string "olas y talló océanos...\p"
	.string "Su feroz duelo se prolongó sin fin.\p"
	.string "El mundo fue engullido por masivos\n"
	.string "fuegos y violentas tormentas.\p"
	.string "Fue entonces cuando el Pokémon del cielo\n"
	.string "descendió de una tormenta.\p"
	.string "El Pokémon, brillando con un intenso\n"
	.string "color verde, calmó a los dos Pokémon\l"
	.string "enfurecidos.\p"
	.string "Luego, cumplido su deber, el Pokémon\n"
	.string "verde voló hacia el azul infinito...$"

