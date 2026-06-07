VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "BLASCO: He perdido ante ti, {PLAYER}, pero\n"
	.string "ya no me siento decaído.\p"
	.string "Porque tengo un nuevo propósito en la\n"
	.string "vida. Junto con mi RALTS, voy a\l"
	.string "desafiar los GIMNASIOS POKéMON y\l"
	.string "convertirme en un gran ENTRENADOR.\p"
	.string "Por favor, obsérvame, {PLAYER}.\n"
	.string "Voy a ser más fuerte que tú.\p"
	.string "Cuando lo haga, voy a desafiarte\n"
	.string "a otro combate.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "BLASCO: Por favor, obsérvame, {PLAYER}.\n"
	.string "Voy a ser más fuerte que tú.\p"
	.string "Cuando lo haga, voy a desafiarte\n"
	.string "a otro combate.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "TÍO: ¡Oh! ¡{PLAYER}{KUN}!\n"
	.string "BLASCO está al lado.\p"
	.string "Pero, chico, hay algo que tengo que\n"
	.string "decirte.\p"
	.string "Este entorno natural está haciendo\n"
	.string "maravillas por la salud de BLASCO.\p"
	.string "Quizás no sea solo el entorno.\n"
	.string "Podrían ser los POKéMON los que le\l"
	.string "están dando esperanza al chico.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "BLASCO se ha ido…\n"
	.string "Se ha escapado por su cuenta…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "TÍO: ¿Es eso cierto?\n"
	.string "BLASCO se ha ido tan lejos completamente\l"
	.string "solo…\p"
	.string "Bueno, tengo que reconocérselo: es el\n"
	.string "hijo de mi hermano pequeño.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: ¿Tú eres?\n"
	.string "¡Oh, claro, ya entiendo!\p"
	.string "Eres el {PLAYER} de quien BLASCO me\n"
	.string "estaba hablando.\p"
	.string "Soy la prima de BLASCO.\n"
	.string "¡Encantada de conocerte!\p"
	.string "Creo que BLASCO se ha vuelto mucho más\n"
	.string "animado y saludable desde que vino aquí.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: No te preocupes por BLASCO.\n"
	.string "Estará bien.\p"
	.string "Conozco a mi primo pequeño, y tiene\n"
	.string "POKéMON con él, también.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Gracias a ti, puedo ver a mi novia\n"
	.string "todos los días.\l"
	.string "¿Contento? ¡Ya lo creo!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "El novio de mi hija es una persona\n"
	.string "muy determinada y apasionada.\p"
	.string "Ha estado cavando un túnel sin parar\n"
	.string "solo para poder ver a mi hija.\p"
	.string "Mi hija está un poco preocupada,\n"
	.string "así que va al túnel a menudo.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Es increíble. ¡El novio de mi hija\n"
	.string "estaba cavando el túnel a mano!\p"
	.string "¡Es tan alucinante!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Si algo le pasara a BLASCO, nunca\n"
	.string "podría mirar a los ojos a sus padres\l"
	.string "en PETALIA…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "¿BLASCO estaba en CIUDAD CALAGUA?\p"
	.string "¡Sus padres en PETALIA se quedarían\n"
	.string "asombrados al enterarse!$"

