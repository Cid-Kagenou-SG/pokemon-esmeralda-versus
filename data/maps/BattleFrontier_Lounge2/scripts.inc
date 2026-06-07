BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "¡Hola! Cuando se trata de noticias sobre\n"
	.string "el Frente Batalla, soy el número 1.\p"
	.string "Puedes considerarme el\n"
	.string "Maniático del Frente.\p"
	.string "Solo para confirmar, pero eres un\n"
	.string "entrenador, ¿verdad?\p"
	.string "Con gusto compartiré las noticias más\n"
	.string "calientes que he recopilado sobre el\l"
	.string "Frente Batalla.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "¡Hola! ¿Has venido a preguntarme sobre\n"
	.string "las últimas noticias? Oh, ¡vale!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "¿Y bien? ¿Y bien? ¿Y bien?\p"
	.string "Seguro que mi información te ha sido\n"
	.string "muy útil, ¿verdad?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Veamos…\p"
	.string "Parece que {STR_VAR_1}\n"
	.string "es el lugar más de moda.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Veamos…\p"
	.string "Parece que la Torre Batalla\n"
	.string "{STR_VAR_1} es la más popular.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "¡Apuesto a que no sabías esto!\p"
	.string "Uno de esos entrenadores de élite que\n"
	.string "Treto llama los Ases del Frente está\l"
	.string "ahí.\p"
	.string "Es esta entrenadora misteriosa llamada\n"
	.string "la Dama de la Torre que dirige el lugar.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "¿Has luchado contra la Dama de la Torre?\p"
	.string "Cuando está midiendo a su oponente,\n"
	.string "aparentemente usa estos Pokémon:\p"
	.string "Un Pokémon Psi de tipo Psíquico,\n"
	.string "un Pokémon Volcán de tipo Fuego,\l"
	.string "y un Pokémon Dormilón de tipo Normal.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "¿Has luchado contra la Dama de la Torre\n"
	.string "cuando va en serio?\p"
	.string "Cuando lucha a tope,\n"
	.string "aparentemente usa estos Pokémon:\p"
	.string "Un Pokémon Eón de tipo Dragón y Psíquico,\n"
	.string "un Pokémon Trueno de tipo Eléctrico,\l"
	.string "y un Pokémon Dormilón de tipo Normal.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "¡Apuesto a que no sabías esto!\p"
	.string "Uno de esos entrenadores de élite que\n"
	.string "Treto llama los Ases del Frente está\l"
	.string "ahí.\p"
	.string "Es este entrenador extravagante llamado\n"
	.string "el As de la Cúpula que dirige el lugar.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "¿Has luchado contra el As de la Cúpula?\p"
	.string "Cuando se toma a la ligera al oponente,\n"
	.string "usa estos tres Pokémon:\p"
	.string "Un Pokémon Dragón de tipo Dragón y\n"
	.string "Volador,\n"
	.string "un Pokémon Pez Lodo de tipo Agua y\l"
	.string "Tierra,\l"
	.string "y un Pokémon Llama de tipo Fuego y\l"
	.string "Volador.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "¿Has luchado contra el As de la Cúpula\n"
	.string "cuando va en serio?\p"
	.string "Cuando demuestra su estrategia,\n"
	.string "usa estos tres Pokémon:\p"
	.string "Un Pokémon Eón de tipo Dragón y\n"
	.string "Volador,\n"
	.string "un Pokémon Pez Lodo de tipo Agua y\l"
	.string "Tierra,\l"
	.string "y un Pokémon Pierna de Hierro de tipo\l"
	.string "Acero y Psíquico.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "¡Apuesto a que no sabías esto!\p"
	.string "Uno de esos entrenadores de élite que\n"
	.string "Treto llama los Ases del Frente está\l"
	.string "ahí.\p"
	.string "Es este entrenador rarito llamado\n"
	.string "el Jefe de Fábrica que dirige el lugar.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "¿Ya has luchado contra el Jefe de\n"
	.string "Fábrica?\p"
	.string "Déjame pensar… Cuando va a luchar,\n"
	.string "simplemente consigue tres Pokémon de\l"
	.string "alquiler.\p"
	.string "Lucha bajo prácticamente las mismas\n"
	.string "condiciones que tú.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "¿Has luchado contra el Jefe de Fábrica\n"
	.string "cuando va en serio?\p"
	.string "Cuando va en serio a luchar,\n"
	.string "todavía consigue tres Pokémon de alquiler.\p"
	.string "Lucha bajo prácticamente las mismas\n"
	.string "condiciones que tú.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "¡Apuesto a que no sabías esto!\p"
	.string "Uno de esos entrenadores de élite que\n"
	.string "Treto llama los Ases del Frente está\l"
	.string "ahí.\p"
	.string "Es esta entrenadora aterradora llamada\n"
	.string "la Reina de la Sierpe que dirige el lugar.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "¿Has luchado contra la Reina de la\n"
	.string "Sierpe antes?\p"
	.string "Cuando está de buen humor, dicen que\n"
	.string "usa estos tres Pokémon:\p"
	.string "Un Pokémon Colmillo Serpiente de tipo\n"
	.string "Veneno,\n"
	.string "un Pokémon Moho de tipo Bicho y Roca,\l"
	.string "y un Pokémon Tierno de tipo Agua.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "¿Has luchado contra la Reina de la\n"
	.string "Sierpe cuando va en serio?\p"
	.string "Cuando está seriamente molesta, dicen\n"
	.string "que usa estos tres Pokémon:\p"
	.string "Un Pokémon Colmillo Serpiente de tipo\n"
	.string "Veneno,\n"
	.string "un Pokémon Serpiente de Hierro de tipo\l"
	.string "Acero y Tierra,\l"
	.string "y un Pokémon Atroz de tipo Agua y\l"
	.string "Volador.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "¡Apuesto a que no sabías esto!\p"
	.string "Uno de esos entrenadores de élite que\n"
	.string "Treto llama los Ases del Frente está\l"
	.string "ahí.\p"
	.string "Es esta entrenadora mona llamada\n"
	.string "la Magnate del Dojo que dirige el lugar.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "¿Has luchado contra la Magnate del Dojo\n"
	.string "antes?\p"
	.string "Cuando está evaluando la habilidad del\n"
	.string "enemigo, supuestamente usa estos\l"
	.string "Pokémon:\p"
	.string "Un Pokémon Cuerno Único de tipo Bicho\n"
	.string "y Lucha,\n"
	.string "un Pokémon Luz de Luna de tipo Siniestro,\l"
	.string "y un Pokémon Mudanza de tipo Bicho y\l"
	.string "Fantasma.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "¿Has luchado contra la Magnate del Dojo\n"
	.string "cuando va en serio?\p"
	.string "Cuando lucha en serio,\n"
	.string "supuestamente usa estos Pokémon:\p"
	.string "Un Pokémon Luz de Luna de tipo Siniestro,\n"
	.string "un Pokémon Sombra de tipo Fantasma y\l"
	.string "Veneno,\n"
	.string "y un Pokémon Seta de tipo Planta y\l"
	.string "Lucha.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "¡Apuesto a que no sabías esto!\p"
	.string "Uno de esos entrenadores de élite que\n"
	.string "Treto llama los Ases del Frente está\l"
	.string "ahí.\p"
	.string "Es este entrenador siniestro llamado\n"
	.string "el Experto del Palacio que dirige el lugar.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "¿Has luchado contra el Experto del\n"
	.string "Palacio antes?\p"
	.string "Cuando está probando el espíritu del\n"
	.string "oponente, se dice que usa estos Pokémon:\p"
	.string "Un Pokémon Murciélago de tipo Veneno y\n"
	.string "Volador,\n"
	.string "un Pokémon Perezoso de tipo Normal,\l"
	.string "y un Pokémon Transporte de tipo Agua y\l"
	.string "Hielo.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "¿Has luchado contra el Experto del\n"
	.string "Palacio cuando va en serio?\p"
	.string "Cuando arroja toda su fuerza en el\n"
	.string "combate, se dice que usa estos Pokémon:\p"
	.string "Un Pokémon Legendario de tipo Fuego,\n"
	.string "un Pokémon Perezoso de tipo Normal,\l"
	.string "y un Pokémon Aurora de tipo Agua.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "¡Apuesto a que no sabías esto!\p"
	.string "Uno de esos entrenadores de élite que\n"
	.string "Treto llama los Ases del Frente está\l"
	.string "ahí.\p"
	.string "Es este entrenador ardiente llamado\n"
	.string "el Rey de la Pirámide que dirige el lugar.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "¿Has luchado contra el Rey de la\n"
	.string "Pirámide antes?\p"
	.string "Cuando está comprobando el poder del\n"
	.string "enemigo, aparentemente usa estos Pokémon:\p"
	.string "Un Pokémon Cima Roca de tipo Roca,\n"
	.string "un Pokémon Iceberg de tipo Hielo,\l"
	.string "y un Pokémon Hierro de tipo Acero.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "¿Has luchado contra el Rey de la\n"
	.string "Pirámide cuando va en serio?\p"
	.string "Cuando está cargado de poder ardiente,\n"
	.string "aparentemente usa estos Pokémon:\p"
	.string "Un Pokémon Congelación de tipo Hielo y\n"
	.string "Volador,\n"
	.string "un Pokémon Eléctrico de tipo Eléctrico y\l"
	.string "Volador,\l"
	.string "y un Pokémon Llama de tipo Fuego y\l"
	.string "Volador.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Claro, hay varios lugares donde puedes\n"
	.string "participar en Batallas Dobles.\p"
	.string "Pero las Salas de Batalla Doble de la\n"
	.string "Torre Batalla son, digamos, ¡básicas!\p"
	.string "Es donde deberías aprender cómo se\n"
	.string "juegan las Batallas Dobles aquí en el\l"
	.string "Frente Batalla.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Cuídate en los combates aquí.\p"
	.string "He oído que hay entrenadores que tienen\n"
	.string "estrategias desarrolladas solo para\l"
	.string "Batallas Dobles.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Una vez que estés seguro y cómodo con\n"
	.string "las Batallas Dobles aquí, deberías\l"
	.string "pensar en desafiar otros lugares que\l"
	.string "ofrecen Batallas Dobles.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Todo tipo de entrenadores se reúnen en\n"
	.string "el Salón de Batalla.\p"
	.string "Solo piensa: ¡puedes encontrarte con tus\n"
	.string "amigos o seguidores!\l"
	.string "¡Deberías mirar bien!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Si estás con un amigo, dirígete a la\n"
	.string "Sala de Batallas Multi Link.\p"
	.string "¡Si juegas con un amigo fuerte, puedes\n"
	.string "esperar encontrarte con oponentes duros!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "¡Qué increíble poder de recopilación de\n"
	.string "noticias! ¡Mi mentor no tiene igual!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "¡Qué increíbles poderes de observación!\n"
	.string "¡Mi mentor no tiene igual!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "¡Qué increíble poder de persuasión!\n"
	.string "¡Mi mentor no tiene igual!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…¿Qué es este lugar?\n"
	.string "Me está asustando…$"

