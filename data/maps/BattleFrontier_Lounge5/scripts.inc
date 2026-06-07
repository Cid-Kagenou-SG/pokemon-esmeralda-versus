BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "¡Je, je!\n"
	.string "¡Puedo saber lo que piensan los Pokémon!\p"
	.string "¡Por favor!\n"
	.string "¿Puedo ver tus Pokémon?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "¡Buuu!\n"
	.string "¡Tacaño!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "¡Luchará incluso si tiene muchas\l"
	.string "heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta ser astuto!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡contraatacará!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se preocupará por sí mismo!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "¡Luchará incluso si tiene muchas\l"
	.string "heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Mmm…\p"
	.string "¡Este dice que se cuida a sí mismo!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡contraatacará!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta ser astuto!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se preocupará por sí mismo!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "¡Luchará incluso si tiene muchas\l"
	.string "heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta ser astuto!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡contraatacará!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se preocupará por sí mismo!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta ser astuto!\n"
	.string "¡Dice que le gusta ser astuto incluso\l"
	.string "si tiene muchas heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se volverá astuto!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "¡Luchará incluso si tiene muchas\l"
	.string "heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta ser astuto!\n"
	.string "¡Dice que le gusta ser astuto incluso\l"
	.string "si tiene muchas heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta ser astuto!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se preocupará por sí mismo!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Mmm…\p"
	.string "¡Este dice que se cuida a sí mismo!\n"
	.string "¡Dice que se preocupa por sí mismo\l"
	.string "tenga o no muchas heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Mmm…\p"
	.string "¡Este dice que se cuida a sí mismo!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se volverá astuto!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Mmm…\p"
	.string "¡Este dice que se cuida a sí mismo!\n"
	.string "¡Dice que se preocupa por sí mismo\l"
	.string "incluso si tiene muchas heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta ser astuto!\n"
	.string "¡Dice que le gusta ser astuto incluso\l"
	.string "si tiene muchas heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Mmm…\p"
	.string "¡Este dice que se cuida a sí mismo!\n"
	.string "¡Dice que se preocupa por sí mismo\l"
	.string "incluso si tiene muchas heridas!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Mmm…\p"
	.string "¡Este dice que se cuida a sí mismo!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡contraatacará!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Mmm…\p"
	.string "¡Este dice que le gusta luchar!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se volverá astuto!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Mmm…\p"
	.string "¡Este dice que se cuida a sí mismo!\n"
	.string "Pero si recibe muchas heridas,\l"
	.string "¡se volverá astuto!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "¡Qué tonto! ¡Un Huevo está dormido!\n"
	.string "¡No puedo hablar con él!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "¡Qué encantador!\n"
	.string "¡Esa pequeña dice que puede entender\l"
	.string "a los Pokémon!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "Tengo la sensación de que la pequeña\n"
	.string "está diciendo algo profundo.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "¡Yo sé algo!\p"
	.string "¡Esa pequeña juega mucho en la casa\n"
	.string "roja!$"

