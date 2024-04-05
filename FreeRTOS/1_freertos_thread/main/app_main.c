/**
* @file app_main.c

* @brief Code example for FreeRTOS threads.

* @par Code example for FreeRTOS threads.
*
* COPYRIGHT NOTICE: (c) 2022 Byte Lab Grupa d.o.o.
* All rights reserved.
*/

//--------------------------------- INCLUDES ----------------------------------
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
//---------------------------------- MACROS -----------------------------------

#define GPIO_LED_BLUE    (14U)
#define GPIO_BIT_MASK(X) ((1ULL << (X)))

#define DELAY_MAIN_TASK_TIME_MS  (2000U)
#define DELAY_HELLO_TASK_TIME_MS (1000U)
#define DELAY_WORLD_TASK_TIME_MS (1000U)
//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
/**
 * @brief This function initializes received GPIO pin as an output.
 *
 * @param [in] pin GPIO number to be initialized.
 */
static void _led_init(uint8_t pin);

/**
 * @brief This function toggles LED.
 *
 * @param [in] pin The GPIO pin number (that controls LED) to be toggled.
 */
static void _led_toggle(uint8_t pin);

/**
 * @brief This function prints out "hello".
 *
 * @param [in] pvParameter This is the parameter that is passed to the task.
 */
static void _hello_task(void *pvParameter);

/**
 * @brief This function prints out "world!".
 *
 * @param [in] pvParameter This is the parameter that is passed to the task.
 */
static void _world_task(void *pvParameter);
//------------------------- STATIC DATA & CONSTANTWS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    _led_init(GPIO_LED_BLUE);
    xTaskCreate(&_hello_task, "hello_task", 2 * 1024, NULL, 5, NULL); /* All of these numbers should be MACROS or static const*/
    xTaskCreate(&_world_task, "world_task", 2 * 1024, NULL, 5, NULL);
    for(;;)
    {
        vTaskDelay(DELAY_MAIN_TASK_TIME_MS / portTICK_PERIOD_MS);
        _led_toggle(GPIO_LED_BLUE);
    }
}
//---------------------------- PRIVATE FUNCTIONS ------------------------------
static void _hello_task(void *pvParameter)
{
    for(;;)
    {
        printf("hello ");
        vTaskDelay(DELAY_HELLO_TASK_TIME_MS / portTICK_PERIOD_MS);
    }
}

static void _world_task(void *pvParameter)
{
    for(;;)
    {
        printf("world!\n");
        vTaskDelay(DELAY_WORLD_TASK_TIME_MS / portTICK_PERIOD_MS);
    }
}

static void _led_init(uint8_t pin)
{
    // zero-initialize the config structure.
    gpio_config_t io_conf = {};
    // disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    // set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    // bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = GPIO_BIT_MASK(pin);
    // disable pull-down mode
    io_conf.pull_down_en = 0;
    // disable pull-up mode
    io_conf.pull_up_en = 0;
    // configure GPIO with the given settings
    gpio_config(&io_conf);
}

static void _led_toggle(uint8_t pin)
{
    static uint32_t cntr = 0;
    gpio_set_level(pin, ++cntr % 2);
}
//---------------------------- INTERRUPT HANDLERS ------------------------------
