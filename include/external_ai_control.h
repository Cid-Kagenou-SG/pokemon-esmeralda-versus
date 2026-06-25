#ifndef GUARD_EXTERNAL_AI_CONTROL_H
#define GUARD_EXTERNAL_AI_CONTROL_H

extern u8 gExternalAICommand;
extern u8 gExternalAIParam;
extern u8 gExternalAITimeout;

bool8 HasExternalAICommand(void);
bool8 GetExternalAICommand(u8 *action, u8 *param);
void ResetExternalAI(void);
u8 TryGetExternalMoveChoice(void);

#endif