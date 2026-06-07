PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Mmmm…\n"
	.string "No hay ni uno…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hola, ¿has visto algún Pokémon llamado\n"
	.string "Shroomish por aquí?\p"
	.string "Me encanta ese Pokémon.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Te iba a tender una emboscada, pero\n"
	.string "tuviste que quedarte dando vueltas por\l"
	.string "el Bosque Petalia una eternidad, ¿verdad?\p"
	.string "¡Me cansé de esperar, así que aquí estoy!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "¡Tú! ¡Investigador de Devon!\p"
	.string "¡Entrégame esos papeles!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "¡Aaaaaaay!\p"
	.string "¡Tú eres un Entrenador Pokémon, verdad?\n"
	.string "¡Tienes que ayudarme, por favor!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "¿Eh? ¿Qué crees que estás haciendo?\n"
	.string "¿Vas a protegerle?\p"
	.string "¡Ninguno que se cruce en el camino del\n"
	.string "Equipo Aqua sale bien librado, aunque no\l"
	.string "levante dos palmos del suelo!\p"
	.string "¡Ven a que te dé jarabe de palo!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "¡Esto tiene que ser una broma!\n"
	.string "¡Eres muy fuerte!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Brrrr… Hay que tener valor para\n"
	.string "entrometerse en los planes del\l"
	.string "Equipo Aqua…\p"
	.string "¡Vuelve a luchar conmigo!\p"
	.string "Bueno, eso me gustaría, pero no me queda\n"
	.string "ni un Pokémon en forma…\p"
	.string "Y, oye, nosotros del Equipo Aqua también\n"
	.string "estamos tras algo en Ciudad Férrica.\p"
	.string "¡Por hoy te perdono la vida!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ufff…\n"
	.string "¡Ha estado a punto!\p"
	.string "Gracias a ti no me ha robado estos\n"
	.string "papeles importantes.\p"
	.string "¡Ya sé! Te daré una Super Ball como\n"
	.string "agradecimiento.$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "¿No ha dicho ese matón del Equipo Aqua\n"
	.string "que también estaban tras algo en\l"
	.string "Ciudad Férrica?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "¡Oh, no! ¡Es una crisis!\n"
	.string "¡No puedo perder el tiempo!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Llevas un montón de objetos.\n"
	.string "No puedo darte esta Super Ball.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "¡He atrapado un montón de Pokémon!\p"
	.string "¡Adelante, vosotros podéis!\n"
	.string "¡Vivan los Pokémon bicho!$"

PetalburgWoods_Text_ICouldntWin:
	.string "A pesar de tener todos estos Pokémon,\n"
	.string "he perdido miserablemente…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Como he atrapado tantísimos Pokémon,\n"
	.string "ya no me queda ni una Poké Ball.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Si llevas Pokémon bicho a la escuela,\n"
	.string "te haces con un club de fans.$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "¡Si quiero conservar mi club de fans,\n"
	.string "no puedo perder!$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Si tienes un Pokémon bicho grande,\n"
	.string "la gente parece que te respeta más.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Mis Pokémon bicho han evolucionado.\n"
	.string "¡Ahora recuperaré mi club de fans!\p"
	.string "¡Te registro en mi PokéNav!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Mis Pokémon bicho han evolucionado.\n"
	.string "¡Ahora recuperaré mi club de fans!\p"
	.string "¡Te registro en mi PokéNav!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mis Pokémon bicho han evolucionado.\n"
	.string "¡Ahora recuperaré mi club de fans!$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "¡Si quiero conservar mi club de fans,\n"
	.string "no puedo perder!$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Consigues un club de fans si tus Pokémon\n"
	.string "son fuertes, ¿no es así?\l"
	.string "Por eso me he entrenado mucho.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "¡Hola! ¿Qué tal están tus Pokémon?\p"
	.string "Si están débiles y quieres evitar los\n"
	.string "combates, aléjate de las zonas con\l"
	.string "hierba alta.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "A veces hay cosas en el suelo, aunque\n"
	.string "no puedas verlas.\p"
	.string "Por eso siempre tengo los ojos abiertos\n"
	.string "cuando voy de paseo.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "¡Oye, qué pasada!\n"
	.string "¡Es la Medalla del Gimnasio de Ciudad\l"
	.string "Férrica!\p"
	.string "Seguro que eres un Entrenador.\n"
	.string "Deberías probar a usar este objeto.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "Es una Semilla Milagro.\n"
	.string "Si un Pokémon la lleva equipada, sus\l"
	.string "movimientos de tipo Planta se vuelven\l"
	.string "más fuertes.\p"
	.string "Además de la Semilla Milagro, creo que\n"
	.string "hay otros objetos útiles que los Pokémon\l"
	.string "pueden llevar equipados.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "Pistas Entrenador\p"
	.string "Cuando un Pokémon hace acto de presencia\n"
	.string "en un combate, recibe puntos de\l"
	.string "experiencia.\p"
	.string "Si quieres entrenar sin riesgos a un\n"
	.string "Pokémon débil, ponlo al principio de la\l"
	.string "lista de equipo.\p"
	.string "En cuanto empiece el combate,\n"
	.string "sustitúyelo. Así ganará puntos de\l"
	.string "experiencia sin sufrir ningún daño.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "Pistas Entrenador\p"
	.string "Además de los Puntos de Salud (PS), los\n"
	.string "Pokémon tienen puntos de poder (PP), que\l"
	.string "necesitan para realizar movimientos\l"
	.string "durante el combate.\p"
	.string "Si un Pokémon se queda sin PP, hay que\n"
	.string "llevarlo a un Centro Pokémon.$"

