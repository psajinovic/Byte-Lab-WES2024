/**
 * @file app_main.c
 *
 * @brief Code example for FreeRTOS timers.
 *
 * COPYRIGHT NOTICE: (c) 2024 Byte Lab Grupa d.o.o.
 * All rights reserved.
 */

//--------------------------------- INCLUDES ----------------------------------
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include <stdio.h>

//---------------------------------- MACROS -----------------------------------
#define GPIO_LED_BLUE    (14U)
#define GPIO_BIT_MASK(X) ((1ULL << (X)))

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
 * @brief This function is a callback for software timer, it toggles the LED.
 *
 * @param [in] p_timer Timer handle for the timer that invoked the callback.
 */
static void _led_timer_cb(TimerHandle_t p_timer);

//------------------------- STATIC DATA & CONSTANTS ---------------------------
static TimerHandle_t p_led_timer_hndl = NULL;

static const uint32_t led_timer_period_ms = 500u;
//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    _led_init(GPIO_LED_BLUE);

    p_led_timer_hndl = xTimerCreate("led_timer", (led_timer_period_ms / portTICK_PERIOD_MS), pdTRUE, NULL, _led_timer_cb);

    xTimerStart(p_led_timer_hndl, 0);

    vTaskSuspend(NULL);
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

static void _led_toggle(uint8_t pin)
{
    static uint32_t cntr = 0;
    gpio_set_level(pin, ++cntr % 2);
}
//---------------------------- INTERRUPT HANDLERS ------------------------------
static void _led_timer_cb(TimerHandle_t p_timer)
{
    _led_toggle(GPIO_LED_BLUE);

    xTimerResetFromISR(p_led_timer_hndl, NULL);
}
