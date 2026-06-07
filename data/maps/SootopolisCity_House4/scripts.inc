SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Escucha y te contaré algo bueno.\p"
	.string "Se supone que hay una ruina antigua\n"
	.string "en el mar de por aquí.\p"
	.string "Podría haber tesoros esperando a ser\n"
	.string "descubiertos allí abajo.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Tesoros antiguos…\p"
	.string "Sería bonito que existieran, pero\n"
	.string "aunque no fuera así, sería tan hermoso\l"
	.string "dar un paseo bajo el agua con mis\l"
	.string "POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Marurii.$"

