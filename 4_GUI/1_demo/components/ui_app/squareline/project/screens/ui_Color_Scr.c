// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: esp32_gui

#include "../ui.h"

void ui_Color_Scr_screen_init(void)
{
    ui_Color_Scr = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Color_Scr, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Color_Scr, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Color_Scr, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dark_Mode_Switch_Color = lv_switch_create(ui_Color_Scr);
    lv_obj_set_width(ui_Dark_Mode_Switch_Color, 32);
    lv_obj_set_height(ui_Dark_Mode_Switch_Color, 15);
    lv_obj_set_x(ui_Dark_Mode_Switch_Color, 139);
    lv_obj_set_y(ui_Dark_Mode_Switch_Color, 107);
    lv_obj_set_align(ui_Dark_Mode_Switch_Color, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Dark_Mode_Switch_Color, LV_STATE_CHECKED);       /// States

    lv_obj_set_style_bg_color(ui_Dark_Mode_Switch_Color, lv_color_hex(0x6AC6A4), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Dark_Mode_Switch_Color, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_Dark_Mode_Label_Color = lv_label_create(ui_Color_Scr);
    lv_obj_set_width(ui_Dark_Mode_Label_Color, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Dark_Mode_Label_Color, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dark_Mode_Label_Color, 76);
    lv_obj_set_y(ui_Dark_Mode_Label_Color, 107);
    lv_obj_set_align(ui_Dark_Mode_Label_Color, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Dark_Mode_Label_Color, "Dark mode");
    lv_obj_set_style_text_color(ui_Dark_Mode_Label_Color, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Dark_Mode_Label_Color, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Dark_Mode_Label_Color, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_Dark_Mode_Label_Color, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Home_Btn_Color = lv_btn_create(ui_Color_Scr);
    lv_obj_set_width(ui_Home_Btn_Color, 36);
    lv_obj_set_height(ui_Home_Btn_Color, 31);
    lv_obj_set_x(ui_Home_Btn_Color, -133);
    lv_obj_set_y(ui_Home_Btn_Color, 94);
    lv_obj_set_align(ui_Home_Btn_Color, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Home_Btn_Color, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Home_Btn_Color, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Home_Btn_Color, lv_color_hex(0x6AC6A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home_Btn_Color, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home_Img_C = lv_img_create(ui_Home_Btn_Color);
    lv_img_set_src(ui_Home_Img_C, &ui_img_home_icon_png);
    lv_obj_set_width(ui_Home_Img_C, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Home_Img_C, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Home_Img_C, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Home_Img_C, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Home_Img_C, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Home_Img_C, 50);

    ui_BL_logo_Color = lv_img_create(ui_Color_Scr);
    lv_img_set_src(ui_BL_logo_Color, &ui_img_bl_logo_symbol_png);
    lv_obj_set_width(ui_BL_logo_Color, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BL_logo_Color, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_BL_logo_Color, 139);
    lv_obj_set_y(ui_BL_logo_Color, -101);
    lv_obj_set_align(ui_BL_logo_Color, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BL_logo_Color, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BL_logo_Color, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_BL_logo_Color, 50);

    ui_Colorwheel = lv_colorwheel_create(ui_Color_Scr, true);
    lv_obj_set_width(ui_Colorwheel, 150);
    lv_obj_set_height(ui_Colorwheel, 150);
    lv_obj_set_x(ui_Colorwheel, 60);
    lv_obj_set_y(ui_Colorwheel, -5);
    lv_obj_set_align(ui_Colorwheel, LV_ALIGN_CENTER);

    ui_LED_color_panel = lv_obj_create(ui_Color_Scr);
    lv_obj_set_width(ui_LED_color_panel, 139);
    lv_obj_set_height(ui_LED_color_panel, 31);
    lv_obj_set_x(ui_LED_color_panel, -83);
    lv_obj_set_y(ui_LED_color_panel, -75);
    lv_obj_set_align(ui_LED_color_panel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_LED_color_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_LED_color_panel, lv_color_hex(0x6AC6A4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LED_color_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LED_color_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LED_color_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LED_color_label = lv_label_create(ui_LED_color_panel);
    lv_obj_set_width(ui_LED_color_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LED_color_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LED_color_label, 2);
    lv_obj_set_y(ui_LED_color_label, 1);
    lv_obj_set_align(ui_LED_color_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LED_color_label, "LED color");
    lv_obj_set_style_text_font(ui_LED_color_label, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Dark_Mode_Switch_Color, ui_event_Dark_Mode_Switch_Color, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Home_Btn_Color, ui_event_Home_Btn_Color, LV_EVENT_ALL, NULL);

}
