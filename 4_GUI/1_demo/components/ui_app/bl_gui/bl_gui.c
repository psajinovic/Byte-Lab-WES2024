/**
 * @file bl_gui.c
 *
 * @brief This file is an example UI application that creates and loads screen
 *        with buttons and sliders
 *
 * COPYRIGHT NOTICE: (c) 2023 Byte Lab Grupa d.o.o.
 * All rights reserved.
 */

//--------------------------------- INCLUDES ----------------------------------
#include "bl_gui.h"
#include <stdio.h>

/* Littlevgl specific */
#include "lvgl.h"
#include "lvgl_helpers.h"
//---------------------------------- MACROS -----------------------------------

//-------------------------------- DATA TYPES ---------------------------------

//---------------------- PRIVATE FUNCTION PROTOTYPES --------------------------
/**
 * @brief This function handles events that happen on LVGL objects.
 *
 * @param [in] p_event Pointer to the event type.
 */
static void _event_handler(lv_event_t *p_event);

/**
 * @brief This function returns a dummy key value of 0.
 *
 * @return A dummy key.
 */
static uint8_t _keypad_get_key(void);

/**
 * @brief The function reads the state of the keypad and returns the key pressed.
 *
 * @param [in] p_indev_drv The driver descriptor.
 * @param [in] p_data This is the data structure that will be passed to the callback function.
 */
static void _keypad_read(lv_indev_drv_t *p_indev_drv, lv_indev_data_t *p_data);

/**
 * @brief This function creates and loads new screen.
 */
static void _goto_new_screen(void);

//------------------------- STATIC DATA & CONSTANTS ---------------------------

//------------------------------- GLOBAL DATA ---------------------------------

//------------------------------ PUBLIC FUNCTIONS -----------------------------
void bl_gui_init(void)
{
    /* Create buttons */
    lv_obj_t *p_label1;
    lv_obj_t *p_btn1 = lv_btn_create(lv_scr_act());
    lv_obj_align_to(p_btn1, NULL, LV_ALIGN_CENTER, 0, -80);
    p_label1 = lv_label_create(p_btn1);
    lv_label_set_text(p_label1, "Button 1");

    lv_obj_t *p_label2;
    lv_obj_t *p_btn2 = lv_btn_create(lv_scr_act());
    lv_obj_align_to(p_btn2, NULL, LV_ALIGN_CENTER, 0, -20);
    p_label2 = lv_label_create(p_btn2);
    lv_label_set_text(p_label2, "Button 2");

    // Add button 2 callback
    (void)lv_obj_add_event_cb(p_btn2, _event_handler, LV_EVENT_CLICKED, NULL);

    /*Create a slider*/
    lv_obj_t *p_slider = lv_slider_create(lv_scr_act());
    lv_obj_align_to(p_slider, NULL, LV_ALIGN_CENTER, 0, 50);
    (void)lv_obj_add_event_cb(p_slider, _event_handler, LV_EVENT_VALUE_CHANGED, NULL);

    /* Add widgets to group */
    lv_group_t *p_group = lv_group_create();
    lv_group_add_obj(p_group, p_btn1);
    lv_group_add_obj(p_group, p_btn2);
    lv_group_add_obj(p_group, p_slider);

    /* Initialize input device */
    static lv_indev_drv_t kb_drv;
    lv_indev_drv_init(&kb_drv);
    kb_drv.type            = LV_INDEV_TYPE_KEYPAD;
    kb_drv.read_cb         = _keypad_read;
    lv_indev_t *p_kb_indev = lv_indev_drv_register(&kb_drv);
    lv_indev_set_group(p_kb_indev, p_group);
}

//---------------------------- PRIVATE FUNCTIONS ------------------------------
static void _event_handler(lv_event_t *p_event)
{
    if(LV_EVENT_VALUE_CHANGED == p_event->code)
    {
        printf("Value: %ld\n", lv_slider_get_value(p_event->current_target));
    }
    else if(LV_EVENT_CLICKED == p_event->code)
    {
        printf("Button clicked, going to new screen\n");
        _goto_new_screen();
    }
    else
    {
        /* Do nothing.*/
    }
}

static uint8_t _keypad_get_key(void)
{
    uint8_t dummy_key = 0;
    return dummy_key;
}

static void _keypad_read(lv_indev_drv_t *p_indev_drv, lv_indev_data_t *p_data)
{
    static uint32_t last_key = 0;

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = _keypad_get_key();
    if(act_key != 0)
    {
        p_data->state = LV_INDEV_STATE_PR;

        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key)
        {
            case 1:
                act_key = LV_KEY_NEXT;
                break;
            case 2:
                act_key = LV_KEY_PREV;
                break;
            case 3:
                act_key = LV_KEY_LEFT;
                break;
            case 4:
                act_key = LV_KEY_RIGHT;
                break;
            case 5:
                act_key = LV_KEY_ENTER;
                break;
        }

        last_key = act_key;
    }
    else
    {
        p_data->state = LV_INDEV_STATE_REL;
    }

    p_data->key = last_key;
}

static void _goto_new_screen(void)
{
    // Create new screen
    lv_obj_t *p_screen2 = lv_obj_create(NULL);
    lv_obj_t *p_label3;
    lv_obj_t *p_btn3 = lv_btn_create(p_screen2);
    lv_obj_align_to(p_btn3, NULL, LV_ALIGN_CENTER, 0, 0);
    p_label3 = lv_label_create(p_btn3);
    lv_label_set_text(p_label3, "New Button");

    lv_scr_load(p_screen2);
}
//---------------------------- INTERRUPT HANDLERS -----------------------------
