set(COMPONENT_SRCS "ui_app.c" "bl_gui/bl_gui.c" "lvgl_demo/lvgl_demo.c" 
                    "squareline/project/ui.c" 
                    "squareline/project/images/ui_img_bl_logo_symbol_png.c"
                    "squareline/project/images/ui_img_colorwheel_icon_png.c"
                    "squareline/project/images/ui_img_settings_icon_png.c"
                    "squareline/project/images/ui_img_home_icon_png.c"
                    "squareline/project/ui_helpers.c"
                    "squareline/project/ui_events.c"
                    "squareline/project/screens/ui_Home_Scr.c"
                    "squareline/project/screens/ui_Color_Scr.c"
                    "squareline/project/screens/ui_Settings_Scr.c")

set(COMPONENT_ADD_INCLUDEDIRS "")
set(COMPONENT_PRIV_REQUIRES lvgl lvgl_esp32_drivers)

register_component()
