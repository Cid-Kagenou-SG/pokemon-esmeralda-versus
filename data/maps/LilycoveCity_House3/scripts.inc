LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "¡Oh, cielos! ¿Viajas sola?\n"
	.string "¡Pero si eres tan joven! ¡Qué valiente!\p"
	.string "¡Seguro que mis hijos podrían aprender\n"
	.string "una o dos cosas de ti!\p"
	.string "¿Yo? Soy una maestra de los PokéCubos.\p"
	.string "Si me lo tomo en serio un poquito, vaya,\n"
	.string "puedo preparar PokéCubos estupendos.\p"
	.string "¿Te gustaría aprender de mí,\n"
	.string "una maestra de los PokéCubos?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "¿Oh? ¿Estás segura?\p"
	.string "¡No deberías intentar hacerlo todo\n"
	.string "tú sola, cariño!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "¡Oh, bien! ¡Eres un alma inteligente!\n"
	.string "Esto es un poco largo, ¡así que escucha!\p"
	.string "¿Estás lista?\p"
	.string "Si miras los PokéCubos, deberías ver\n"
	.string "que se valoran por su suavidad.\p"
	.string "¡Cuanto menor sea la suavidad, mejor es!\n"
	.string "¡No lo olvides!\p"
	.string "Un buen PokéCubo tiene poca suavidad\n"
	.string "y un alto nivel.\p"
	.string "Un Pokémon también puede comer más\n"
	.string "PokéCubos buenos que los ordinarios.\p"
	.string "Y esto es importante.\p"
	.string "Si quieres hacer PokéCubos suaves,\n"
	.string "usa diferentes tipos de Bayas.\p"
	.string "No seas tacaña: los tipos de Bayas\n"
	.string "afectan la suavidad de los PokéCubos.\p"
	.string "Y otra cosa.\p"
	.string "Cuanta más gente mezclando Bayas,\n"
	.string "más suaves serán los PokéCubos.\p"
	.string "Por eso deberías hablar con otras\n"
	.string "personas y hacer PokéCubos juntos.\p"
	.string "Eso es todo lo que necesitas saber para\n"
	.string "hacer buenos PokéCubos.\p"
	.string "Si todo el mundo tuviera Pokémon que\n"
	.string "ama, PokéCubos suaves y una familia\l"
	.string "cariñosa, el mundo sería un lugar más\l"
	.string "feliz.\p"
	.string "¡No te rindas, cariño!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Cuando mi mujer dio a luz a cuatrillizos,\n"
	.string "ya puedes creerme que me quedé de una\n"
	.string "pieza.\p"
	.string "Pero, ahora, verlos jugar juntos,\n"
	.string "me hace feliz.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Vamos a tener Combates Múltiples, pero\n"
	.string "sé que voy a ganar.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Nos gusta mezclar cosas en la\n"
	.string "Esquina Récord.\p"
	.string "¿Pero qué es lo que se mezcla?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "¡Vamos a hacer super PokéCubos con una\n"
	.string "Licuabayas!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Quiero presumir de lo fuerte que es mi\n"
	.string "Pokémon, así que vamos a entrar en un\l"
	.string "Concurso juntos.$"

