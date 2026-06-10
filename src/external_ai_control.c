#include "global.h"
#include "battle.h"
#include "external_ai_control.h"

// Variables en EWRAM que Lua puede escribir directamente
EWRAM_DATA u8 gExternalAICommand = 0;  // 0=nada, 1=movimiento, 2=cambio
EWRAM_DATA u8 gExternalAIParam = 0;    // slot del movimiento (0-3) o Pokemon (0-5)
EWRAM_DATA u8 gExternalAITimeout = 0;  // frames restantes para timeout

bool8 HasExternalAICommand(void)
{
    return gExternalAICommand != 0;
}

bool8 GetExternalAICommand(u8 *action, u8 *param)
{
    if (gExternalAICommand == 0)
        return FALSE;

    *action = gExternalAICommand;
    *param = gExternalAIParam;

    // Limpiar comando para no repetir
    gExternalAICommand = 0;
    gExternalAIParam = 0;

    return TRUE;
}

void ResetExternalAI(void)
{
    gExternalAICommand = 0;
    gExternalAIParam = 0;
    gExternalAITimeout = 0;
}

// Nueva funcion para ser llamada desde BattleAI_ChooseMoveOrAction
// Retorna 0xFF si no hay comando, o el indice del movimiento si hay
u8 TryGetExternalMoveChoice(void)
{
    u8 extAction, extParam;
    if (!GetExternalAICommand(&extAction, &extParam))
        return 0xFF;

    if (extAction == 1) // movimiento
    {
        return extParam;
    }
    else if (extAction == 2) // cambio
    {
        // Para cambio, retornamos 0xFE como codigo especial
        return 0xFE;
    }

    return 0xFF;
}