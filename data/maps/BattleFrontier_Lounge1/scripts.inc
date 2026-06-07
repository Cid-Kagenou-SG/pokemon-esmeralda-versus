BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "¡Llevo 70 años criando Pokémon!\n"
	.string "Soy el hombre al que veneran como\l"
	.string "¡el legendario criador de Pokémon\l"
	.string "número uno!\p"
	.string "Si alguna vez llegas a tener tanta\n"
	.string "experiencia como yo, verás las\l"
	.string "habilidades de los Pokémon de un\l"
	.string "vistazo.\p"
	.string "Eres un entrenador. ¿No te interesa\n"
	.string "conocer las habilidades de tus\l"
	.string "propios Pokémon?\p"
	.string "¡Aquí!\n"
	.string "¡Echemos un vistazo a tus Pokémon!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Mmm…\p"
	.string "En general, describiría a éste\n"
	.string "como de habilidad media.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Mmm…\p"
	.string "En general, describiría a éste\n"
	.string "como de habilidad algo superior a la\l"
	.string "media.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Mmm…\p"
	.string "En general, diría que éste tiene\n"
	.string "una habilidad bastante impresionante.$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Mmm…\p"
	.string "En general, diría que éste tiene\n"
	.string "una habilidad maravillosamente\l"
	.string "extraordinaria.$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Por cierto, su mejor característica,\n"
	.string "diría yo, es su PS…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Por cierto, su mejor característica,\n"
	.string "diría yo, es su Ataque…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Por cierto, su mejor característica,\n"
	.string "diría yo, es su Defensa…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Por cierto, su mejor característica,\n"
	.string "diría yo, es su At. Esp.…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Por cierto, su mejor característica,\n"
	.string "diría yo, es su Def. Esp.…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Por cierto, su mejor característica,\n"
	.string "diría yo, es su Velocidad…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Esa característica es bastante buena.\n"
	.string "…Mmm… Así es como lo llamo.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Esa característica es bastante\n"
	.string "impresionante.\n"
	.string "…Mmm… Así es como lo llamo.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "¡Esa característica es extraordinaria!\n"
	.string "…Mmm… Así es como lo llamo.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "¡Es impecable! ¡Una cosa de perfección!\n"
	.string "…Mmm… Así es como lo llamo.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "¿Qué?\n"
	.string "¿No tienes tiempo para mis consejos?\p"
	.string "¡Siempre deberías estar deseoso de\n"
	.string "aprender de las experiencias de tus\l"
	.string "mayores!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Sí, ¿qué pasa ahora?\p"
	.string "¡Tengo asuntos que atender!\n"
	.string "¡Déjalo para la próxima vez!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "¡Ah, jovencito! ¿Te intrigan las\n"
	.string "habilidades de tus Pokémon?\p"
	.string "¡Aquí, aquí!\n"
	.string "¡Echemos un vistazo a tus Pokémon!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Soy un experto, pero ni siquiera yo\n"
	.string "puedo saber nada sobre un Pokémon que\l"
	.string "aún no ha nacido.\p"
	.string "¡Muéstrame un Pokémon!\n"
	.string "¡Necesito ver un Pokémon!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "¡Dijo que mi Pokémon es extraordinario!\n"
	.string "¡Me alegro de haberlo criado con\l"
	.string "cuidado!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "¡Dijo que mi Pokémon es extraordinario!\n"
	.string "Pero no hice nada especial criándolo…$"

