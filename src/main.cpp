#include <xtl.h>
#include "config.h"
#include "smc.h"
#include "ui.h"

// ============================================================
//  GhostGirl System Watch — Main Entry Point
// ============================================================

int main() {
    // ---- Init ----
    if (!SMC_Init()) {
        return 1;
    }
    if (!UI_Init()) {
        SMC_Shutdown();
        return 1;
    }

    // ---- State ----
    SMC_Temps temps = {0};
    int fanSpeed = SMC_GetFanSpeed();
    bool running = true;

    // ---- Main Loop ----
    while (running) {
        // Read temps
        SMC_ReadTemps(&temps);
        fanSpeed = SMC_GetFanSpeed();

        // Draw
        DrawMainScreen(temps, fanSpeed, 0);

        // ---- Handle Controller Input ----
        XINPUT_STATE state;
        ZeroMemory(&state, sizeof(state));

        if (XInputGetState(0, &state) == ERROR_SUCCESS) {
            WORD buttons = state.Gamepad.wButtons;

            // Increase fan speed
            if (buttons & XINPUT_GAMEPAD_DPAD_UP) {
                int newSpeed = fanSpeed + FAN_STEP;
                if (newSpeed > FAN_MAX) newSpeed = FAN_MAX;
                SMC_SetFanSpeed(newSpeed);
                Sleep(INPUT_DEBOUNCE_MS);
            }

            // Decrease fan speed
            if (buttons & XINPUT_GAMEPAD_DPAD_DOWN) {
                int newSpeed = fanSpeed - FAN_STEP;
                if (newSpeed < FAN_MIN) newSpeed = FAN_MIN;
                SMC_SetFanSpeed(newSpeed);
                Sleep(INPUT_DEBOUNCE_MS);
            }

            // Reset to default
            if (buttons & XINPUT_GAMEPAD_Y) {
                SMC_SetFanSpeed(FAN_DEFAULT);
                Sleep(INPUT_DEBOUNCE_MS);
            }

            // Exit
            if (buttons & XINPUT_GAMEPAD_A) {
                running = false;
            }
        }

        Sleep(UPDATE_INTERVAL_MS);
    }

    // ---- Cleanup ----
    DrawMessage("Exiting...", nullptr);
    UI_Shutdown();
    SMC_Shutdown();
    return 0;
}
