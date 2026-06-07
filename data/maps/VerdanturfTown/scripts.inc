VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Mi papá me lo contó.\p"
	.string "Dice que este túnel está lleno de\n"
	.string "POKéMON tímidos.\p"
	.string "Se asustan mucho con los ruidos fuertes y\n"
	.string "arman un gran alboroto.\p"
	.string "Así que tuvieron que detener el gran\n"
	.string "proyecto del túnel.\p"
	.string "Pero hay un hombre. ¡Está intentando cavar\n"
	.string "el túnel él solo!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Había un hombre que cavó un túnel para\n"
	.string "la mujer que amaba.\p"
	.string "La verdad es que no lo entiendo, ¡pero bueno!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Por la forma en que soplan los vientos, la ceniza volcánica\n"
	.string "nunca llega a esta dirección.\p"
	.string "El aire aquí es limpio y delicioso.\n"
	.string "Vivir aquí debería hacer maravillas incluso\l"
	.string "para personas frágiles y enfermizas.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Mis POKéMON y yo llevamos una\n"
	.string "racha ganadora impresionante.\p"
	.string "Así que he decidido estrenarme en la\n"
	.string "TIENDA DE BATALLA de este pueblo.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "¿Has visto la cueva que hay junto a la\n"
	.string "TIENDA POKéMON?\p"
	.string "Hay un tipo ahí dentro que está intentando\n"
	.string "romper las rocas para poder abrirse paso\l"
	.string "hasta el otro lado.\p"
	.string "Sería genial si pudiéramos atravesarla…\n"
	.string "Así sería más fácil visitar FÉRRICA.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Esa cueva junto a la TIENDA POKéMON\n"
	.string "ahora es un túnel que lleva al otro lado.\p"
	.string "Es genial: ahora es fácil ir a comprar\n"
	.string "nuevos productos DEVON en FÉRRICA.$"

VerdanturfTown_Text_TownSign:
	.string "PUEBLO VERDEGAL\p"
	.string "“Las tierras altas azotadas por el viento con la\n"
	.string "dulce fragancia de la hierba.”$"

VerdanturfTown_Text_WandasHouse:
	.string "CASA DE CLARA$"

VerdanturfTown_Text_BattleTentSign:
	.string "TIENDA DE BATALLA DE VERDEGAL\n"
	.string "“¡Deleita tus ojos con las batallas!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TÚNEL FERVEGAL\n"
	.string "“Conecta FÉRRICA y VERDEGAL\p"
	.string "“El proyecto del túnel ha sido\n"
	.string "cancelado.”$"

