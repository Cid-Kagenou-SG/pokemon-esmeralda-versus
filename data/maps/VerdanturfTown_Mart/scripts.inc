VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
   .string "En cualquier combate Pokémon, el\n"
   .string "Ataque X Especial es crucial.\p"
   .string "Aumenta el poder de algunos movimientos,\n"
   .string "aunque solo sea para un combate.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
   .string "Parece que no venden guías de estrategia\n"
   .string "ganadora para la Tienda de Batalla...\p"
   .string "Parece que al final hay que confiar en\n"
   .string "el propio ingenio...$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
   .string "La Nido Ball funciona mejor con\n"
   .string "Pokémon debilitados.\p"
   .string "Verdegal es el único lugar donde\n"
   .string "puedes comprarla.$"

