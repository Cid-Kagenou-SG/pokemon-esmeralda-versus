MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "¡El Revivir es fantástico!\p"
	.string "Dáselo a un Pokémon debilitado,\n"
	.string "y el Pokémon se levantará.\p"
	.string "Pero ten cuidado, el Revivir no restaura\n"
	.string "los PP gastados de los movimientos.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "El Máx. Repelente mantiene alejados a\n"
	.string "todos los Pokémon débiles.\p"
	.string "De todos los repelentes, dura\n"
	.string "más tiempo.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "La Malla Ball y la Buceo Ball son Poké\n"
	.string "Balls raras que solo se fabrican en\l"
	.string "Algaria.\p"
	.string "Una Malla Ball es efectiva contra\n"
	.string "Pokémon de tipo Bicho y Agua.\p"
	.string "Una Buceo Ball funciona mejor con\n"
	.string "Pokémon en el fondo del mar.$"

