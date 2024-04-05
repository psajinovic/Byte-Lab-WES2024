/**
 * @file app_main.c
 *
 * @brief Code example for controlling LED BLUE on Byte Lab Dev Kit board.
 *
 * COPYRIGHT NOTICE: (c) 2024 Byte Lab Grupa d.o.o.
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

#define DELAY_TIME_MS (1000U)
//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
/**
 * @brief This function initializes received GPIO pin as an output.
 *
 * @param [in] pin GPIO number to be initialized.
 */
static void _led_init(uint8_t pin);

/**
 * @brief This function turns on the LED.
 *
 * @param [in] pin The GPIO pin number (that controls LED) to be turned on.
 */
static void _led_on(uint8_t pin);

/**
 * @brief This function turns off the LED.
 *
 * @param [in] pin The GPIO pin number (that controls LED) to be turned off.
 */
static void _led_off(uint8_t pin);
//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    _led_init(GPIO_LED_BLUE);

    for(;;)
    {
        _led_on(GPIO_LED_BLUE);
        vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);

        _led_off(GPIO_LED_BLUE);
        vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);
    }
}

//---------------------------- PRIVATE FUNCTIONS ------------------------------
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

static void _led_on(uint8_t pin)
{
    gpio_set_level(pin, 1U);
}

static void _led_off(uint8_t pin)
{
    gpio_set_level(pin, 0U);
}

//---------------------------- INTERRUPT HANDLERS ------------------------------
