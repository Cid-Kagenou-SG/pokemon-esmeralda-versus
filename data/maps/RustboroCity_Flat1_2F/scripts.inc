RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, es tan difícil cada día…\p"
	.string "¿Qué es lo difícil?\n"
	.string "¿Necesitas preguntarlo?\p"
	.string "Es intentar averiguar qué hacer para\n"
	.string "las comidas cada día.\p"
	.string "Realmente no es fácil inventar comidas\n"
	.string "todos los días.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "¡Oh, hola!\n"
	.string "Bienvenido a la casa de los PIMIENTA.\p"
	.string "Tengo una pregunta para ti.\n"
	.string "¿Alguna vez has cuidado niños?\p"
	.string "Ya ves, soy padre primerizo, así que\n"
	.string "criar a un niño es todo nuevo para mí.\p"
	.string "Y tengo un problema. Mi hija ANAPEL no\n"
	.string "ríe lo suficiente.\p"
	.string "Creo que se reiría para mí si le dijera\n"
	.string "algo gracioso.\p"
	.string "¿Conoces alguna palabra o frase graciosa\n"
	.string "que puedas contarme?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Últimamente he estado diciendo\n"
	.string "“{STR_VAR_1}” para divertirla.\p"
	.string "¿Conoces alguna palabra o frase mejor\n"
	.string "que podría funcionar?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, eso es maravilloso.\n"
	.string "Entonces, cuéntame tu sugerencia.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, ¿es eso cierto?\p"
	.string "Bueno, si se te ocurre una buena\n"
	.string "sugerencia, estoy todo oídos.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, ya veo.\n"
	.string "Bueno, probémoslo, ¿vale?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "¡Oh, sí! ¡Se está riendo!\n"
	.string "¡Oh, estoy tan contento como ella!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, ya veo.\n"
	.string "Bueno, probémoslo, ¿vale?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Mmm… No está sonriendo en absoluto.\n"
	.string "Quizás ANAPEL sea una niña muy seria…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, así que no conoces ninguna palabra\n"
	.string "buena. Será mejor que piense por mí\l"
	.string "mismo, entonces.\p"
	.string "Mmm…\n"
	.string "¿Qué tal “{STR_VAR_1}”?\l"
	.string "Veamos si eso funciona.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Mmm… No está sonriendo en absoluto.\n"
	.string "Quizás ANAPEL sea una niña muy seria…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, así que no conoces ninguna palabra\n"
	.string "buena. Supongo que intentaré divertirla\l"
	.string "con el dicho que usaba antes.\p"
	.string "En cualquier caso, si tienes una buena\n"
	.string "sugerencia, no dudes en decírmela, ¿vale?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "¡Gracias!\p"
	.string "¡Gracias a ti, mi querida ANAPEL se ha\n"
	.string "reído para mí!\p"
	.string "En realidad, puede que no parezca gran\n"
	.string "cosa, pero soy uno de los principales\l"
	.string "investigadores de la CORPORACIÓN DEVON.\p"
	.string "Así que, ¿qué tal si hago algo para\n"
	.string "agradecértelo?\p"
	.string "Ya sé, añadiré algunos nuevos diseños de\n"
	.string "fondo para las CAJAS del Sistema de\l"
	.string "Almacenamiento POKéMON del PC.\p"
	.string "En el menú de diseños de fondo,\n"
	.string "selecciona “AMIGOS”.\p"
	.string "Eso te dará acceso a los nuevos\n"
	.string "diseños de fondo.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "¡Es un MUÑECO de peluche de POKéMON!$"

