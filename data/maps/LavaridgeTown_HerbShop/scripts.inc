LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "¡Bienvenido a la Tienda de Hierbas,\n"
	.string "hogar de medicinas efectivas y\l"
	.string "baratas!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "¿Has venido a ver hierbas medicinales\n"
	.string "a Lavacalda?\p"
	.string "Eso es bastante loable.\p"
	.string "¡Me caes bien! ¡Toma esto!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Ese Carbón que te he dado se usa para\n"
	.string "hacer hierbas medicinales.\p"
	.string "También hace maravillas si se lo das\n"
	.string "a un Pokémon.\p"
	.string "Intensifica el poder de los movimientos\n"
	.string "de tipo Fuego.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Las hierbas medicinales funcionan\n"
	.string "impresionantemente bien.\p"
	.string "Pero tus Pokémon te odiarán por ello.\n"
	.string "¡Debe ser horriblemente amarga!$"

