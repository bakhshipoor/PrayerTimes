#include "prayer_times_ui_events.h"
#include "scr_main.h"
#include "scr_settings.h"

void scr_main_btn_settings_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        lv_screen_load(scr_settings);
    }
}

void scr_settings_btn_back_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    if (code == LV_EVENT_CLICKED)
    {
        lv_screen_load(scr_main);
    }
}