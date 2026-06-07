BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "¡Esta es la Torre Batalla!\n"
	.string "¡Mantén la racha de victorias como\l"
	.string "el entrenador más duro!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "¡Este es el Palacio Batalla!\n"
	.string "¡Mantén los ojos en los combates\l"
	.string "Pokémon!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "¡Este es el Dojo Batalla!\n"
	.string "¡Que se reúnan los equipos más duros!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "¡Esta es la Pirámide Batalla!\n"
	.string "¡Avanza a través de la Búsqueda de\l"
	.string "Batalla!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "SALÓN DE CLASIFICACIÓN DEL FRENTE\n"
	.string "BATALLA\p"
	.string "¡Fija tu mirada en nuevos récords!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "CENTRO DE SERVICIOS DE INTERCAMBIO DE\n"
	.string "PUNTOS DE BATALLA\p"
	.string "¡Intercambia tus Puntos de Batalla!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "¡Wow!\n"
	.string "¡Es enorme!\p"
	.string "La Torre Batalla se siente especial.\n"
	.string "Es diferente de las demás.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Mi gran ambición es conquistar tanto el\n"
	.string "Frente Batalla como la Liga Pokémon.\p"
	.string "Y si mi sueño se hace realidad…\p"
	.string "Yo… Voy a preguntarle a Mimi de al lado\n"
	.string "si quiere ser mi amiga.$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "¡La Pirámide Batalla es demasiado dura!\n"
	.string "¡Simplemente no puedo llegar a la cima!\p"
	.string "Como no me quedan opciones, quizá pueda\n"
	.string "escalar el exterior…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Prospero en la oscuridad…\n"
	.string "Sí… ¿Qué me merece?\l"
	.string "Nada más que la Pirámide Batalla…\p"
	.string "¿Qué dices de vagar en la oscuridad y\n"
	.string "en la desesperación total y absoluta?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "No dormí durante una semana, pero luego\n"
	.string "monté el equipo definitivo.\p"
	.string "No me veo perdiendo, en serio.\n"
	.string "¡Vamos a asaltar el Dojo Batalla!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "¿Treto también te trajo aquí?\n"
	.string "¿Qué pasa con ese tipo?\p"
	.string "Parece que realmente sabe cómo detectar\n"
	.string "entrenadores talentosos, pero…\p"
	.string "Nunca lo he visto luchar en persona.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "¡Zigg!\n"
	.string "¡Creo en ti, pequeño compañero!\p"
	.string "¡Haré cualquier golosina deliciosa que\n"
	.string "te guste si ganas!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "Zigzagoon parece distraído…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "La gente me llama entrometido, pero no\n"
	.string "puedo evitarlo.\p"
	.string "¡Tu gorra está torcida!\n"
	.string "Oh, no, ¡basura en el suelo!\l"
	.string "¡Ups, es casi la hora de cenar!\p"
	.string "No sé si podré aguantar solo mirar en\n"
	.string "el Palacio Batalla…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Puede que no parezca impresionante ahora,\n"
	.string "pero una vez vencí a un líder de\l"
	.string "Gimnasio.\p"
	.string "Quién sabe, quizá debería intentar\n"
	.string "otro golpe de gloria.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Soy rápido en mi Bici, y eso también\n"
	.string "va para la forma en que lucho.\p"
	.string "¡Gano combates en un abrir y cerrar de\n"
	.string "ojos!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Soy mejor que mi papá en Pokémon.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "¡Vamos, mi pequeño dulce!\n"
	.string "¡Ve a acumular algunas victorias para\l"
	.string "papá!\p"
	.string "Eres igual que tu madre, ¡así que vas\n"
	.string "a dominar!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "No fue fácil llegar aquí, pero había\n"
	.string "oído hablar de una chica guapísima en el\l"
	.string "Dojo Batalla.\p"
	.string "En lugar de ella, ¿sabes qué encontré?\p"
	.string "¡Una multitud entera de artistas\n"
	.string "marciales sudorosos, apestosos y\l"
	.string "primitivos!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "A veces veo a este anciano que parece\n"
	.string "muy importante entrando allí.\p"
	.string "Tiene unos Pokémon realmente\n"
	.string "increíbles. Parece muy agradable.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "¿Lo sabes?\n"
	.string "¿La leyenda de la Pirámide Batalla?\p"
	.string "Cuando venga un entrenador seguro que\n"
	.string "alcance la cúspide dorada, aparecerá un\l"
	.string "hombre entre hombres.\p"
	.string "¿No conoces esa leyenda?\n"
	.string "¡Bueno, claro que no!\l"
	.string "¡Acabo de inventarla!\p"
	.string "¿Qué se supone que significa?\n"
	.string "Eso, amigo mío, no puedo decirlo.$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "¡Hombre! ¡Oh, hombre!\n"
	.string "¡Nunca había perdido antes!\p"
	.string "¡Pero me destrozaron sin ninguna\n"
	.string "salvación!\p"
	.string "¿Y luego me dicen que no tengo ningún\n"
	.string "talento? ¡Hombre!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Este tipo se encontró con un entrenador\n"
	.string "horriblemente duro mientras estaba en el\l"
	.string "desafío de la Torre Batalla.\p"
	.string "Ahora míralo…\p"
	.string "Necesitas ser cauteloso si alguna vez\n"
	.string "decides ir a la Torre Batalla.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "¡Sí!\n"
	.string "¡Por fin tengo suficientes Puntos de\l"
	.string "Batalla!\p"
	.string "Supongo que cambiaré por otra muñeca\n"
	.string "de peluche gigante.$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "¡Oh, sí, vale!\n"
	.string "¡Así que este es el Salón de\l"
	.string "Clasificación!\p"
	.string "Me gustaría pasar a la historia como\n"
	.string "un supercampeón y tener mi nombre\l"
	.string "registrado aquí para la posteridad.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Contigo a mi lado, puedo hacer cualquier\n"
	.string "cosa.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, cariño, eres tan maravilloso.\p"
	.string "¡Ooh, no puedo esperar más!\p"
	.string "¡Vamos a una Sala de Batallas Múltiples\n"
	.string "ahora mismo!\p"
	.string "Si nos juntamos en el Salón de Batalla,\n"
	.string "el poder de nuestro amor superará a\l"
	.string "todos los que encontremos.\p"
	.string "Vaya, ante nosotros, cariño, todo\n"
	.string "caerá como fichas de dominó.$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "El Frente Batalla no es exclusivamente\n"
	.string "para entrenadores duros.\p"
	.string "Muchas personas con habilidades\n"
	.string "especiales han sido invitadas, parece.\p"
	.string "Ese hombre Treto…\p"
	.string "Puede que haya construido este lugar\n"
	.string "para servir a un objetivo más grande…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Disculpa, jovencito.\n"
	.string "¿Tienes buena vista?\p"
	.string "Hay un árbol extraño más allá de aquí, y\n"
	.string "a mis ojos cansados parece moverse.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Disculpa, jovencito.\n"
	.string "¿Tienes buena memoria?\p"
	.string "Tengo la sensación de que una vez hubo\n"
	.string "un árbol extraño más allá de aquí.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Yo…\n"
	.string "¡Lo vi!\p"
	.string "¡Había un Pokémon pegajoso con una cola\n"
	.string "larga más adelante!\p"
	.string "¡Estaba escondido bajo una roca y me\n"
	.string "miraba fijamente!$"
