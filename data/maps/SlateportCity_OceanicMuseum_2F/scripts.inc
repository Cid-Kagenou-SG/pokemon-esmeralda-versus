SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "¿Sí? Si buscas a BABOR, ese soy yo.\p"
	.string "¡Ah! Esos deben ser los componentes que\n"
	.string "pedí al SR. PIEDRA de DEVON.\p"
	.string "¡Gracias! ¡Genial!\n"
	.string "Ya podemos preparar nuestra expedición.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "¡Je, je, je, alto ahí!\n"
	.string "¡Nos quedamos con esos componentes!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPITÁN BABOR: ¿Q-qué?\n"
	.string "¿Quiénes sois vosotros?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "¡Somos el EQUIPO AQUA!\p"
	.string "¡Nuestro JEFE quiere esos componentes!\n"
	.string "¡Cierra el pico y entrégalos!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "¡Aaaay!\n"
	.string "¡Un niño me ha vencido!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, hombre, qué desastre…\n"
	.string "El JEFE se va a poner furioso…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "¡Hum, llorica patético!\n"
	.string "¡Déjame ocuparme de esto!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "¿Qué?\n"
	.string "¡Yo también he perdido!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "¿Y ahora qué? Si no conseguimos los\n"
	.string "componentes, ¡estamos listos!\p"
	.string "Arrgh, ¡no contaba con que un mocoso\n"
	.string "entrometido nos estorbiera!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "He venido a ver qué estaba tardando\n"
	.string "tanto en robar unos componentes, y vosotros,\l"
	.string "inútiles, os ha retenido un simple crío?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Somos el EQUIPO AQUA,\n"
	.string "¡y amamos el mar!\p"
	.string "Y yo soy el líder del EQUIPO AQUA,\n"
	.string "¡AQUILES!\p"
	.string "¿Por qué te entrometes en nuestros\n"
	.string "asuntos?\p"
	.string "…¡No! ¡No puede ser!\n"
	.string "¿No serás del EQUIPO MAGMA?\p"
	.string "Espera, eso no puede ser.\n"
	.string "No vistes como ellos.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Los POKéMON, las personas… Toda vida\n"
	.string "depende del mar.\p"
	.string "Por eso, el EQUIPO AQUA se dedica a\n"
	.string "la expansión del mar.\p"
	.string "¿No estás de acuerdo? Lo que hacemos\n"
	.string "es una empresa magnífica.\p"
	.string "Ah, en fin…\n"
	.string "Todavía eres demasiado joven para\l"
	.string "entender nuestro noble objetivo.\p"
	.string "Pero te advierto: ni se te ocurra\n"
	.string "entrometerte de nuevo en nuestros planes.\p"
	.string "¡Las consecuencias te costarán\n"
	.string "muy caro!\p"
	.string "¡Y no lo olvides!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPITÁN BABOR: Eres…\n"
	.string "Ah, vale, eres {PLAYER}{KUN}…\p"
	.string "¡En cualquier caso, ha sido una\n"
	.string "situación tensa! ¡Gracias por salvarnos!\p"
	.string "Ah, sí, casi olvido que incluso trajiste\n"
	.string "los componentes de DEVON.$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPITÁN BABOR: ¡Uups!\n"
	.string "¡No hay tiempo que perder!\p"
	.string "Tenemos que emprender nuestra expedición\n"
	.string "al fondo del mar muy pronto.\p"
	.string "Gracias de nuevo, pero ahora tengo\n"
	.string "que irme.\p"
	.string "Siéntete libre de dar una vuelta y\n"
	.string "mirar nuestras instalaciones.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "He visto una maqueta de un barco aquí.\p"
	.string "Me ha recordado a la NAO ABANDONADA\n"
	.string "cerca de PUEBLO AZULIZA…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "¡No te atrevas a correr dentro del\n"
	.string "MUSEO!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "¡Guau, el submarino es alucinante!\n"
	.string "¡Quiero montar en él!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“MUESTRA DE CALIDAD DEL AGUA 1”, dice\n"
	.string "la etiqueta.\p"
	.string "El mar está todo conectado, pero el\n"
	.string "agua parece diferir según la región.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“MUESTRA DE CALIDAD DEL AGUA 2”, dice\n"
	.string "la etiqueta.\p"
	.string "¿La salinidad del agua de mar también\n"
	.string "difiere según la región?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Una pelota de goma se expande y\n"
	.string "se contrae.\p"
	.string "“En el mar, el propio peso del agua\n"
	.string "ejerce presión.\p"
	.string "“En aguas poco profundas, la presión\n"
	.string "no es muy fuerte.\p"
	.string "“Sin embargo, en aguas extremadamente\n"
	.string "profundas, la presión puede llegar a ser\l"
	.string "incluso de decenas de miles de toneladas\l"
	.string "sobre una pequeña área.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MAQUETA DE LA REGIÓN DE HOENN”\p"
	.string "Es una maqueta en miniatura de la\n"
	.string "región de HOENN.\p"
	.string "¿Dónde está PUEBLO ESCASO en esto?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Es una exposición sobre el flujo del\n"
	.string "agua de mar.\p"
	.string "“Cerca del fondo del mar, el agua fluye\n"
	.string "debido a diferencias en factores como\l"
	.string "la temperatura y la salinidad.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Es una exposición sobre el flujo del\n"
	.string "agua de mar.\p"
	.string "“Hacia la superficie, el agua de mar fluye\n"
	.string "como corrientes impulsadas por los vientos.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“EL FERRY S.S. TITAL\p"
	.string "“Una réplica a escala del barco en\n"
	.string "construcción en los ASTILLEROS BABOR.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“SUBMARINO EXPLORADOR 1\p"
	.string "“Una réplica del submarino de exploración\n"
	.string "del fondo oceánico de alto rendimiento.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“CÁPSULA SUMERGIBLE\p"
	.string "“Una réplica de una cápsula compacta y\n"
	.string "no tripulada para exploración del fondo\l"
	.string "marino.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“Una réplica del trasatlántico de lujo\n"
	.string "que da la vuelta al mundo.”$"

