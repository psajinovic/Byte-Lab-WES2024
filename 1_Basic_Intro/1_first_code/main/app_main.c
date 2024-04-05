/**
 * @file app_main.c
 *
 * @brief First code example for ESP32.
 *
 * COPYRIGHT NOTICE: (c) 2024 Byte Lab Grupa d.o.o.
 * All rights reserved.
 */

//--------------------------------- INCLUDES ----------------------------------
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

//---------------------------------- MACROS -----------------------------------
#define DELAY_TIME_MS (5000U)

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------

//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------

//---------------------------- PRIVATE FUNCTIONS ------------------------------

//---------------------------- INTERRUPT HANDLERS -----------------------------

void app_main(void)
{
    uint32_t counter = 0;

    for(;;)
    {
        printf("[%ld] My first ESP32 code\n", counter++);

        vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);
    }
}
