FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Oye, ¿qué tal, {PLAYER}?\n"
	.string "¿Con rumbo al Campeonato?\p"
	.string "La líder del Gimnasio de Arborada,\n"
	.string "Alana, es una maestra de los Pokémon\l"
	.string "de tipo Volador.\p"
	.string "Te espera al fondo de este Gimnasio,\n"
	.string "detrás de las puertas giratorias.\p"
	.string "Espera a nuevos retadores que\n"
	.string "intenten despegar.\p"
	.string "¡Vale, adelante!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "¡Lo conseguiste!\n"
	.string "¡Has despegado!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "¡Contempla el elegante estilo de\n"
	.string "combate de los Pokémon pájaro!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Tú…\n"
	.string "Eres fuerte…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Un entrenador tiene que ser listo para\n"
	.string "seguir los giros inesperados de los\l"
	.string "acontecimientos.\p"
	.string "¿Tienes la astucia para llegar a\n"
	.string "nuestra líder?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Los amantes de los Pokémon pájaro\n"
	.string "aspiran a unirse a este Gimnasio.\p"
	.string "Como miembro del Gimnasio de Arborada,\n"
	.string "¡no se me permite perder!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Fue demasiada carga para mí\n"
	.string "soportar…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "El mundo es enorme y hay innumerables\n"
	.string "entrenadores fuertes.\p"
	.string "Voy a seguir entrenando y hacerme\n"
	.string "aún más fuerte.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "¡No hay necesidad de que Alana, nuestra\n"
	.string "líder del Gimnasio, se ocupe de ti!\p"
	.string "¡Yo soy más que suficiente para ti!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "Alana, yo…\n"
	.string "¡He perdido!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "Alana es mona y es fuerte.\n"
	.string "¡Es la líder definitiva!\p"
	.string "Rubor…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "¡Alana me enseñó personalmente!\n"
	.string "¡No me vencerás fácilmente!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Me han vencido…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Gracias a Alana, la gente de Arborada\n"
	.string "puede vivir sin miedo.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Cuando Alana entra en combate, su rostro\n"
	.string "brilla con una determinación hermosa…\p"
	.string "¡No te dejaré presenciar esa\n"
	.string "encantadora visión!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "¡Urk!\n"
	.string "No pude detenerte.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "¡Más te vale tener cuidado! ¡No te\n"
	.string "distraigas mirando a Alana o te\l"
	.string "estrellarás en un montón!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Más te vale saber que hay todo tipo de\n"
	.string "Pokémon de tipo Volador.\p"
	.string "Lo sabes, ¿verdad?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "¡Parece que sabes de lo que hablas!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Claro, me has vencido bien.\n"
	.string "Pero ¡más te vale tener cuidado! Los\l"
	.string "Pokémon de nuestra líder Alana van en\l"
	.string "serio.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Soy Alana. Soy la líder del\n"
	.string "Gimnasio Pokémon de Arborada.\p"
	.string "Me he convertido en una con los Pokémon\n"
	.string "pájaro y he surcado los cielos…\p"
	.string "Por muy duro que sea el combate, hemos\n"
	.string "triunfado con elegancia…\p"
	.string "¡Presencia la elegante coreografía de\n"
	.string "los Pokémon pájaro y yo!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Nunca antes había visto un entrenador\n"
	.string "comandar Pokémon con más elegancia que\l"
	.string "yo…\p"
	.string "En reconocimiento de tu destreza,\n"
	.string "te presento esta Medalla de Gimnasio.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "¡{PLAYER} recibió la Medalla Pluma\n"
	.string "de Alana!$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Con la Medalla Pluma, todos los Pokémon\n"
	.string "hasta el nivel 70, incluso los recibidos\l"
	.string "mediante intercambios, obedecerán todas\l"
	.string "tus órdenes.\p"
	.string "También podrás usar el movimiento MO\n"
	.string "Vuelo fuera de combate.\p"
	.string "Y esto…\n"
	.string "Esto es un regalo de mi parte.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "La MT40 contiene Golpe Aéreo.\p"
	.string "Su velocidad…\n"
	.string "Ningún Pokémon debería poder evitarla.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Se ha registrado a la líder del\n"
	.string "Gimnasio, Alana, en el PokéNav.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Aunque caí ante ti, seguiré dedicada a\n"
	.string "los Pokémon pájaro.$"

FortreeCity_Gym_Text_GymStatue:
	.string "GIMNASIO POKÉMON DE CIUDAD ARBORADA$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "GIMNASIO POKÉMON DE CIUDAD ARBORADA\p"
	.string "ENTRENADORES CERTIFICADOS POR ALANA:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "ALANA: Los humanos nunca podemos escapar\n"
	.string "de la atracción gravitatoria del suelo.\p"
	.string "Pero al esforzarnos por la excelencia,\n"
	.string "¡tenemos el poder de elevarnos!\p"
	.string "Has escalado la cima como el\n"
	.string "Campeón reinante.\p"
	.string "¡Por favor, permíteme ver tu poder en\n"
	.string "pleno vuelo!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "No logré alcanzar tu altura otra vez…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "ALANA: Aunque he perdido, las alas de mi\n"
	.string "corazón permanecen intactas.\p"
	.string "Puedo levantarme y elevarme una y otra\n"
	.string "vez.\p"
	.string "¡Estoy convencida de ello!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "ALANA: Los humanos nunca podemos escapar\n"
	.string "de la atracción gravitatoria del suelo.\p"
	.string "Pero al esforzarnos por la excelencia,\n"
	.string "¡tenemos el poder de elevarnos!\p"
	.string "Has escalado la cima como el\n"
	.string "Campeón reinante.\p"
	.string "¡Por favor, permíteme ver tu poder en\n"
	.string "pleno vuelo!\p"
	.string "Oh, no… ¿Solo llevas un Pokémon\n"
	.string "contigo?\p"
	.string "Por favor, vuelve con al menos dos\n"
	.string "Pokémon.$"
