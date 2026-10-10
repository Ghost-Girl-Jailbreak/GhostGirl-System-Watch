#pragma once

#include <xtl.h>

// SMC command IDs
#define SMC_CMD_READ_TEMPS   0x07
#define SMC_CMD_SET_FANSPEED 0x89
#define SMC_CMD_GET_FANSPEED 0x89  // some kernels use same ID for read/write

// Temperature reading structure
struct SMC_Temps {
    float cpu;      // CPU temperature in Celsius
    float gpu;      // GPU temperature in Celsius
    float edram;    // EDRAM temperature in Celsius
};

// Initialize SMC layer
bool SMC_Init();

// Shut down SMC layer
void SMC_Shutdown();

// Read temperatures
bool SMC_ReadTemps(SMC_Temps* outTemps);

// Read current fan speed (returns 0-100)
int SMC_GetFanSpeed();

// Set fan speed (0-100). Returns true on success.
bool SMC_SetFanSpeed(int percent);
