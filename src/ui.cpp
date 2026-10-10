#include "ui.h"
#include "config.h"
#include <stdio.h>

// ============================================================
//  GhostGirl System Watch — UI Layer
// ============================================================
//
//  NOTE: Plan-only. Real rendering will use XUI or a custom
//  Direct3D renderer once the XDK is installed.
//
//  For now, output goes to the debug console for testing.
// ============================================================

bool UI_Init() {
    return true;
}

void UI_Shutdown() {
    // Nothing to clean up yet.
}

void DrawMainScreen(const SMC_Temps& temps, int fanSpeed, int selectedRow) {
    // ---- Real implementation (once XDK is available) ----
    // Use XUI or Direct3D to draw:
    //   "GhostGirl System Watch"
    //   "CPU:   XX.X C"
    //   "GPU:   XX.X C"
    //   "EDRAM: XX.X C"
    //   "Fan:   XX %"
    //   "[D-Pad Up/Down] Fan speed  [A] Exit"

    // ---- Placeholder ----
    char buffer[256];
    sprintf_s(buffer, 256,
        "GhostGirl System Watch | CPU: %.1fC  GPU: %.1fC  EDRAM: %.1fC  Fan: %d%%",
        temps.cpu, temps.gpu, temps.edram, fanSpeed);
    OutputDebugStringA(buffer);
    OutputDebugStringA("\n");
}

void DrawMessage(const char* line1, const char* line2) {
    OutputDebugStringA(line1);
    OutputDebugStringA("\n");
    if (line2) {
        OutputDebugStringA(line2);
        OutputDebugStringA("\n");
    }
}
