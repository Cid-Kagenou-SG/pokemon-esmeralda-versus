MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Los recuerdos de mi querido Skitty…\n"
	.string "Se me llenan los ojos de solo pensarlo.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ay, ay… Hay agujeros en el suelo aquí\n"
	.string "y allá.\p"
	.string "No me di cuenta y me caí del piso de\n"
	.string "arriba.$"

MtPyre_2F_Text_MarkIntro:
	.string "¡Eh! ¿Estás buscando Pokémon?\n"
	.string "¡Has venido detrás de mí! ¡Qué grosero!$"

MtPyre_2F_Text_MarkDefeat:
	.string "¡Aaaaaaah!\n"
	.string "Lo siento, ¡perdóname, por favor!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "La gente no viene aquí a menudo, así que\n"
	.string "pensé que habría Pokémon raros.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUCAS: Estamos aquí por un reto.\p"
	.string "Je, je, si le demuestro lo guay que soy,\n"
	.string "se enamorará de mí. ¡Lo sé!\p"
	.string "¡Ya sé! ¡Te aplastaré y le demostraré\n"
	.string "lo guay que soy!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUCAS: ¡Vaya!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUCAS: Bueno, hemos perdido, ¡pero no\n"
	.string "pasa nada! Estoy aquí a tu lado.\l"
	.string "¡Superaremos este reto juntos!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUCAS: Si quieres enfrentarte a mí, trae\n"
	.string "más Pokémon.\p"
	.string "Si no, ¡no podré presumirle a mi chica\n"
	.string "de lo guay que soy!$"

MtPyre_2F_Text_DezIntro:
	.string "DES: He venido aquí por un reto con mi\n"
	.string "novio.\p"
	.string "Da mucho miedo, pero estoy con mi novio.\n"
	.string "No pasa nada.\p"
	.string "¡Ya sé! ¡Haré que mi novio parezca guay\n"
	.string "derrotándote!$"

MtPyre_2F_Text_DezDefeat:
	.string "DES: ¡Buaaaaaah! ¡Tengo miedo!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DES: Somos muy cariñosos, ¡así que no nos\n"
	.string "importa perder!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DES: Si quieres desafiarnos, deberías\n"
	.string "traer al menos dos Pokémon.\p"
	.string "Mi novio es fuerte.\n"
	.string "Un solo Pokémon no servirá de nada.$"

MtPyre_2F_Text_LeahIntro:
	.string "Eres una cara desconocida…\n"
	.string "¡Vete antes de que te ocurra algo!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Mmm…\n"
	.string "Eres resistente.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Mi familia ha sido entrenadora aquí\n"
	.string "desde los tiempos de mi bisabuela…\p"
	.string "Es mi deber proteger esta\n"
	.string "montaña…$"

MtPyre_2F_Text_ZanderIntro:
	.string "¡Kiyaaaaah!\n"
	.string "¡Tengo miedo!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "¡Nooooooo!\n"
	.string "¡He perdido los nervios!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Me asusto cada vez que veo algo\n"
	.string "moverse…\p"
	.string "No debería haber venido aquí a\n"
	.string "entrenar…$"

