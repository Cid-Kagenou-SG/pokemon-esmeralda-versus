MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Cuando era joven, recorrí el mundo como\n"
	.string "entrenador Pokémon.\p"
	.string "Ahora que me he convertido en un viejo\n"
	.string "buitre, mi única diversión es observar\l"
	.string "a los jóvenes entrenadores combatir.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "La puerta parece estar cerrada.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un entrenador llamado {STR_VAR_1} está\n"
	.string "visitando mi casa.\p"
	.string "¿Te gustaría desafiar a\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "¿No vas a combatir? Estoy decepcionado\n"
	.string "de no poder verte combatir…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, bien, bien!\p"
	.string "Pero mi casa no es muy resistente.\p"
	.string "¿Podría pedirte que lo limites a un\n"
	.string "combate de 3 contra 3?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Antes de que combatáis, deberíais\n"
	.string "guardar vuestro progreso.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "¡Espero ver un buen combate!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Así que terminó en empate.\p"
	.string "¡Fue un combate brillante en el que\n"
	.string "ninguno de los dos cedió ni un paso!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "¡Fue superlativo!\p"
	.string "¡Vaya, fue como verme a mí mismo en\n"
	.string "mi juventud!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, ¡qué mala suerte para ti!\p"
	.string "Pero fue un buen combate.\n"
	.string "Espero que puedas ganar la próxima vez.$"
