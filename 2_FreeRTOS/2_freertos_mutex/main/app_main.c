/**
 * @file app_main.c
 *
 * @brief Code example for FreeRTOS MUTEX.
 *
 * COPYRIGHT NOTICE: (c) 2024 Byte Lab Grupa d.o.o.
 * All rights reserved.
 */

//--------------------------------- INCLUDES ----------------------------------
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"

//---------------------------------- MACROS -----------------------------------
#define GPIO_LED_BLUE               (14U)
#define GPIO_BIT_MASK(X)           (1ULL << (X))

#define MAIN_TASK_DELAY_MS         (2000U)
#define TASK_DELAY_MS              (1000U)

#define TASK_STACK_SIZE            (2048U)
#define TASK_PRIORITY              (5U)

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
 * @brief Task that increments a shared counter with mutex protection.
 *
 * This task acquires a mutex to safely increment a shared variable and logs the value.
 *
 * @param[in] p_param Unused task parameter.
 */
static void _task_a(void *p_param);

/**
 * @brief Another task that also modifies the shared counter.
 *
 * Similar to _task_a, but runs independently to demonstrate mutual exclusion.
 *
 * @param[in] p_param Unused task parameter.
 */
static void _task_b(void *p_param);

//------------------------- STATIC DATA & CONSTANTS ---------------------------
static SemaphoreHandle_t mutex_handle = NULL;
static uint32_t s_shared_counter = 0;
static const char *TAG = "mutex_example";

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void app_main(void)
{
    _led_init(GPIO_LED_BLUE);

    mutex_handle = xSemaphoreCreateMutex();
    if (NULL == mutex_handle)
    {
        ESP_LOGE(TAG, "Failed to create mutex");
        return;
    }

    xTaskCreate(&_task_a, "Task_A", TASK_STACK_SIZE, NULL, TASK_PRIORITY, NULL);
    xTaskCreate(&_task_b, "Task_B", TASK_STACK_SIZE, NULL, TASK_PRIORITY, NULL);

    for (;;)
    {
        vTaskDelay(MAIN_TASK_DELAY_MS / portTICK_PERIOD_MS);
        _led_toggle(GPIO_LED_BLUE);
    }
}

//---------------------------- PRIVATE FUNCTIONS ------------------------------

static void _task_a(void *p_param)
{
    (void)p_param;

    for (;;)
    {
        if (pdTRUE == xSemaphoreTake(mutex_handle, portMAX_DELAY))
        {
            s_shared_counter++;
            ESP_LOGI(TAG, "[Task A] shared_counter = %lu", s_shared_counter);
            xSemaphoreGive(mutex_handle);
        }

        vTaskDelay(TASK_DELAY_MS / portTICK_PERIOD_MS);
    }
}

static void _task_b(void *p_param)
{
    (void)p_param;

    for (;;)
    {
        if (pdTRUE == xSemaphoreTake(mutex_handle, portMAX_DELAY))
        {
            s_shared_counter++;
            ESP_LOGI(TAG, "[Task B] shared_counter = %lu", s_shared_counter);
            xSemaphoreGive(mutex_handle);
        }

        vTaskDelay(TASK_DELAY_MS / portTICK_PERIOD_MS);
    }
}

static void _led_init(uint8_t pin)
{
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = GPIO_BIT_MASK(pin),
        .pull_down_en = 0,
        .pull_up_en = 0,
    };
    gpio_config(&io_conf);
}

static void _led_toggle(uint8_t pin)
{
    static uint32_t cntr = 0;
    gpio_set_level(pin, (++cntr % 2U));
}
