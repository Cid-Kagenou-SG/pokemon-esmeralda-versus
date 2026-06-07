PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "Norman se convirtió en el nuevo\n"
	.string "Líder de Gimnasio de nuestro pueblo.\p"
	.string "Creo que hizo venir a su familia desde\n"
	.string "algún lugar muy lejano.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "Luché contra Norman una vez, pero, uf,\n"
	.string "era demasiado fuerte.\p"
	.string "¿Cómo te lo diría?\p"
	.string "Tuve la sensación de que vive\n"
	.string "para los Pokémon.$"

