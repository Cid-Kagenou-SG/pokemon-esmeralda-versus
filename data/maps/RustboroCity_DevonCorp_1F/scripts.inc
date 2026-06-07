RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Hola y bienvenido a la CORPORACIÓN\n"
	.string "DEVON.\p"
	.string "Nos enorgullecemos de producir objetos\n"
	.string "y medicinas que mejoran tu vida.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Uno de nuestros investigadores\n"
	.string "tontamente se ha llevado un robo de un\l"
	.string "paquete importante.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "¡Oye, esas ZAPATILLAS DE CORRER!\n"
	.string "¡Son uno de nuestros productos!\p"
	.string "Me hace feliz ver a alguien usando algo\n"
	.string "que hemos fabricado.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Ese paquete robado…\p"
	.string "Bueno, claro que es importante, pero no\n"
	.string "es algo que cualquiera pueda usar.\p"
	.string "En mi opinión, ese ladrón no debía de\n"
	.string "ser muy listo.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Parece que han recuperado los\n"
	.string "PRODUCTOS DEVON robados.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Lo siento, solo las personas\n"
	.string "autorizadas pueden entrar aquí.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Es más que tonto.\n"
	.string "¿Cómo nos han podido robar?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "¡Hola!\n"
	.string "¡Siempre serás bienvenido aquí!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Muestras de rocas y metal están\n"
	.string "exhibidas en la vitrina.\p"
	.string "Hay un panel con algo escrito\n"
	.string "en él…\p"
	.string "“La CORPORACIÓN DEVON comenzó como\n"
	.string "productora de piedras de canteras.\p"
	.string "“La empresa también producía hierro de\n"
	.string "limaduras en la arena.\p"
	.string "“Desde ese humilde comienzo como\n"
	.string "productora de materias primas, DEVON\l"
	.string "se desarrolló.\p"
	.string "“DEVON es ahora un fabricante de una\n"
	.string "amplia gama de productos industriales.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Prototipos y productos de prueba llenan\n"
	.string "la vitrina.\p"
	.string "Hay un panel con una descripción…\p"
	.string "“Además de productos industriales,\n"
	.string "DEVON ahora comercializa productos\l"
	.string "variados y farmacéuticos para un mejor\l"
	.string "estilo de vida.\p"
	.string "“Recientemente, DEVON ha comenzado a\n"
	.string "comercializar herramientas para\l"
	.string "ENTRENADORES POKéMON, incluyendo\l"
	.string "POKé BALLS y sistemas POKéNAV.”$"

