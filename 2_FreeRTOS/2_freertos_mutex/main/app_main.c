/**
 * @file app_main.c
 *
 * @brief Code example for FreeRTOS MUTEX.
 *
 * COPYRIGHT NOTICE: (c) 2024 Byte Lab Grupa d.o.o.
 * All rights reserved.
 */

//--------------------------------- INCLUDES ----------------------------------
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <freertos/semphr.h>
#include <stdio.h>

//---------------------------------- MACROS -----------------------------------
#define DELAY_HELLO_TASK_TIME_MS (1000U)
#define DELAY_WORLD_TASK_TIME_MS (1000U)

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
/**
 * @brief This function runs while the "hello_task" is active.
 *
 * @param [in] p_parameter This is the parameter that is passed to the task.
 */
static void _hello_task(void *p_parameter);

/**
 * @brief This function runs while the "world_task" is active.
 *
 * @param [in] p_parameter This is the parameter that is passed to the task.
 */
static void _world_task(void *p_parameter);

//------------------------- STATIC DATA & CONSTANTS ---------------------------
static SemaphoreHandle_t p_mutex;

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    // Create Mutex.
    p_mutex = xSemaphoreCreateMutex();

    // Create threads.
    xTaskCreate(&_hello_task, "hello_task", 2 * 1024, NULL, 4, NULL); /* All of these numbers should be MACROS or static const*/
    xTaskCreate(&_world_task, "world_task", 2 * 1024, NULL, 3, NULL);

    vTaskSuspend(NULL);
}

//---------------------------- PRIVATE FUNCTIONS ------------------------------

// #define MUTEX_ON

static void _hello_task(void *p_parameter)
{
    for(;;)
    {
#ifdef MUTEX_ON
        xSemaphoreTake(p_mutex, portMAX_DELAY);
#endif // MUTEX ON

        printf("hello");
        vTaskDelay(DELAY_HELLO_TASK_TIME_MS / portTICK_PERIOD_MS);
        printf(" ... hello end\n");

#ifdef MUTEX_ON
        xSemaphoreGive(p_mutex);
#endif // MUTEX ON

        // Give a chance to another task.
        vTaskDelay(0);
    }
}

static void _world_task(void *p_parameter)
{
    for(;;)
    {
#ifdef MUTEX_ON
        xSemaphoreTake(p_mutex, portMAX_DELAY);
#endif // MUTEX ON

        printf("World");
        vTaskDelay(DELAY_WORLD_TASK_TIME_MS / portTICK_PERIOD_MS);
        printf(" ... world end\n");

#ifdef MUTEX_ON
        xSemaphoreGive(p_mutex);
#endif // MUTEX ON
    }
}

//---------------------------- INTERRUPT HANDLERS ------------------------------
