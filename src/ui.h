#pragma once

#include "smc.h"

// Draw the main monitoring screen
void DrawMainScreen(const SMC_Temps& temps, int fanSpeed, int selectedRow);

// Draw a simple message (used for exit / errors)
void DrawMessage(const char* line1, const char* line2);

// Initialize rendering
bool UI_Init();

// Shut down rendering
void UI_Shutdown();
