#ifndef _PRAYER_TIMES_UI_SCR_MAIN_H
#define _PRAYER_TIMES_UI_SCR_MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define MAIN_SCREEN_BG_COLOR 0xCED6E0
#define MAIN_HEADER_BG_COLOR 0x2F3542
#define MAIN_TIMES_BG_COLOR 0xF1F2F6
#define MAIN_LBL_TIMES_TITLE_BG_COLOR 0xFDCB6E
#define MAIN_LBL_TIMES_HOUR_BG_COLOR 0xFFEAA7

    // Screens
    extern lv_obj_t* scr_main;

    // Main Screen Objects
    extern lv_obj_t* obj_scr_main_header;
    extern lv_obj_t* btn_settings;
    extern lv_obj_t* lbl_settings;
    extern lv_obj_t* lbl_information;
    extern lv_obj_t* obj_times;
    extern lv_obj_t* lbl_times_imsak_title;
    extern lv_obj_t* lbl_times_fajr_title;
    extern lv_obj_t* lbl_times_sunrise_title;
    extern lv_obj_t* lbl_times_midday_title;
    extern lv_obj_t* lbl_times_duhur_title;
    extern lv_obj_t* lbl_times_asr_title;
    extern lv_obj_t* lbl_times_sunset_title;
    extern lv_obj_t* lbl_times_maghrib_title;
    extern lv_obj_t* lbl_times_isha_title;
    extern lv_obj_t* lbl_times_midnight_title;
    extern lv_obj_t* lbl_times_day_title;
    extern lv_obj_t* lbl_times_night_title;
    extern lv_obj_t* lbl_times_imsak_hour;
    extern lv_obj_t* lbl_times_fajr_hour;
    extern lv_obj_t* lbl_times_sunrise_hour;
    extern lv_obj_t* lbl_times_midday_hour;
    extern lv_obj_t* lbl_times_duhur_hour;
    extern lv_obj_t* lbl_times_asr_hour;
    extern lv_obj_t* lbl_times_sunset_hour;
    extern lv_obj_t* lbl_times_maghrib_hour;
    extern lv_obj_t* lbl_times_isha_hour;
    extern lv_obj_t* lbl_times_midnight_hour;
    extern lv_obj_t* lbl_times_day_hour;
    extern lv_obj_t* lbl_times_night_hour;

    // Main Screen Styles
    extern lv_style_t style_scr_main;
    extern lv_style_t style_obj_header;
    extern lv_style_t style_btn_settings;
    extern lv_style_t style_lbl_settings;
    extern lv_style_t style_lbl_information;
    extern lv_style_t style_obj_times;
    extern lv_style_t style_lbl_times_title;
    extern lv_style_t style_lbl_times_hour;

    void scr_main_create_objects(void);
    void scr_main_style_init(void);
    void scr_main_style_add(void);
    void scr_main_init_objects(void);

#ifdef __cplusplus
}
#endif

#endif