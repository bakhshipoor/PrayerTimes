#ifndef _PRAYER_TIMES_UI_EVENTS_H
#define _PRAYER_TIMES_UI_EVENTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

    typedef struct {
        const char* last_text;
        uint32_t cursor_pos;
        const char* inserted_char;
        bool insert_active;
    } tz_offset_state_t;

    void scr_main_btn_settings_event(lv_event_t* e);
    void scr_settings_btn_back_event(lv_event_t* e);
    void scr_settings_ta_float_event(lv_event_t* e);
    void scr_settings_ta_decimal_event(lv_event_t* e);
    void scr_settings_ta_date_event(lv_event_t* e);
    void scr_settings_ta_timezone_event(lv_event_t* e);
    void scr_settings_dd_event(lv_event_t* e);
    void scr_settings_kb_event(lv_event_t* e);
    void scr_settings_cl_event(lv_event_t* e);

    void get_date_ta_text(const char* ta_txt, uint16_t* year, uint16_t* month, uint16_t* day);
    int get_colon_pos(const char* ta_txt);
    bool validate_time_format(const char* text);
    void fix_time_format(lv_obj_t* ta);

#ifdef __cplusplus
}
#endif

#endif