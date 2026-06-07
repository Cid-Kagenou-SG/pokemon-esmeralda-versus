LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Soy el DISEÑADOR DE JUEGOS.\p"
	.string "Oh, ¿es cierto?\n"
	.string "¿Estás trabajando en una Pokédex?\p"
	.string "Es difícil intentar completarla,\n"
	.string "pero no te rindas.\p"
	.string "Si la completas, por favor ven a\n"
	.string "enseñármela.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "¡Guau! ¡Eso es increíble!\n"
	.string "¡Sí, es totalmente increíble!\p"
	.string "¡Esta Pokédex está completamente\n"
	.string "llena!\p"
	.string "¡Realmente debes amar a los Pokémon!\p"
	.string "¡Estoy tan impresionado!\p"
	.string "¡Déjame darte algo en reconocimiento\n"
	.string "de tu hazaña!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "¿Yo? ¿Me estás hablando a mí?\n"
	.string "Soy el PROGRAMADOR.\p"
	.string "Me pregunto cómo serán las\n"
	.string "TRAGAPERRAS aquí.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "¡Soy el ARTISTA GRÁFICO! ¿No son\n"
	.string "interesantes los Pokémon de Hoenn?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Las chicas TUBER, son monas, ¿eh?\n"
	.string "Luchar contra una TUBER mona…\p"
	.string "¡Uf, es tan increíble!\p"
	.string "¡Y las GEMELAS! ¿No son monas?\n"
	.string "Un combate 2 contra 2 con GEMELAS…\p"
	.string "¡Uf, es insoportablemente divertido!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brisa marina me hace cosquillas en el\n"
	.string "corazón. ¡Se siente maravilloso aquí!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Nunca sabes cuándo y dónde la gente te\n"
	.string "desafiará.\p"
	.string "Por eso nunca salgo de casa sin mi\n"
	.string "GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "TRETO: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … ¿¡Eh!?\n"
	.string "¡Oh, perdón, perdón! ¡Me había quedado\l"
	.string "dormido!\p"
	.string "He venido a ver este asunto de los\n"
	.string "Concursos Pokémon.\p"
	.string "Tengo que admitir que parece bastante\n"
	.string "entretenido, pero…\p"
	.string "Considérame un purista: prefiero los\n"
	.string "combates y los entrenadores duros.\p"
	.string "Pero eso es solo yo.\p"
	.string "{PLAYER}{KUN}, espero que disfrutes de todo,\n"
	.string "como los GIMNASIOS, los CONCURSOS, la\l"
	.string "TIENDA BATALLA, ¡todo el paquete!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "TRETO: Creo que sí requiere estrategia\n"
	.string "ganar un Concurso.\p"
	.string "Diseñar estrategias para los Concursos\n"
	.string "es una forma de convertirse en un mejor\l"
	.string "entrenador, diría yo.$"

