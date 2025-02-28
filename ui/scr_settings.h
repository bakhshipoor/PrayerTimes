#ifndef _PRAYER_TIMES_UI_SCR_SETTINGS_H
#define _PRAYER_TIMES_UI_SCR_SETTINGS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define SETTINGS_SCREEN_BG_COLOR 0xCED6E0
#define SETTINGS_HEADER_BG_COLOR 0x2F3542
#define SETTINGS_ITEMS_BG_COLOR 0xF1F2F6
#define SETTINGS_ITEMS_SECTION_BG_COLOR 0xFFEAA7
#define SETTINGS_ITEMS_HEADER_BG_COLOR 0xFDCB6E
#define SETTINGS_ITEMS_HEADER_TEXT_COLOR 0x2f3542

    // Screens
    extern lv_obj_t* scr_settings;

    // Settings Screen Objects
    extern lv_obj_t* obj_scr_settings_header;
    extern lv_obj_t* btn_scr_settings_back;
    extern lv_obj_t* lbl_scr_settings_back;
    extern lv_obj_t* lbl_scr_settings_header;
    extern lv_obj_t* obj_scr_settings_items;
    extern lv_obj_t* obj_items_calc_method;
    extern lv_obj_t* obj_items_angles;
    extern lv_obj_t* obj_items_offsets;
    extern lv_obj_t* obj_items_juristic;
    extern lv_obj_t* obj_items_hl_method;
    extern lv_obj_t* obj_items_md_method;
    extern lv_obj_t* obj_items_location;
    extern lv_obj_t* obj_items_date;
    extern lv_obj_t* obj_items_time_zone_offset;

    extern lv_obj_t* lbl_items_calc_method_header;
    extern lv_obj_t* lbl_items_angles_header;
    extern lv_obj_t* lbl_items_offsets_header;
    extern lv_obj_t* lbl_items_juristic_header;
    extern lv_obj_t* lbl_items_hl_method_header;
    extern lv_obj_t* lbl_items_md_method_header;
    extern lv_obj_t* lbl_items_location_header;
    extern lv_obj_t* lbl_items_date_header;
    extern lv_obj_t* lbl_items_time_zone_offset_header;

    extern lv_obj_t* obj_items_calc_method_content_left;
    extern lv_obj_t* obj_items_angles_content_left;
    extern lv_obj_t* obj_items_offsets_content_left;
    extern lv_obj_t* obj_items_juristic_content_left;
    extern lv_obj_t* obj_items_hl_method_content_left;
    extern lv_obj_t* obj_items_md_method_content_left;
    extern lv_obj_t* obj_items_location_content_left;
    extern lv_obj_t* obj_items_date_content_left;
    extern lv_obj_t* obj_items_time_zone_offset_content_left;
    extern lv_obj_t* obj_items_calc_method_content_right;
    extern lv_obj_t* obj_items_angles_content_right;
    extern lv_obj_t* obj_items_offsets_content_right;
    extern lv_obj_t* obj_items_juristic_content_right;
    extern lv_obj_t* obj_items_hl_method_content_right;
    extern lv_obj_t* obj_items_md_method_content_right;
    extern lv_obj_t* obj_items_location_content_right;
    extern lv_obj_t* obj_items_date_content_right;
    extern lv_obj_t* obj_items_time_zone_offset_content_right;

    extern lv_obj_t* lbl_calc_method;
    extern lv_obj_t* lbl_angle_imsak;
    extern lv_obj_t* lbl_angle_fajr;
    extern lv_obj_t* lbl_angle_maghrib;
    extern lv_obj_t* lbl_angle_isha;
    extern lv_obj_t* lbl_offset_imsak;
    extern lv_obj_t* lbl_offset_fajr;
    extern lv_obj_t* lbl_offset_sunrise;
    extern lv_obj_t* lbl_offset_duhur;
    extern lv_obj_t* lbl_offset_asr;
    extern lv_obj_t* lbl_offset_sunset;
    extern lv_obj_t* lbl_offset_maghrib;
    extern lv_obj_t* lbl_offset_isha;
    extern lv_obj_t* lbl_offset_midnight;
    extern lv_obj_t* lbl_juristic;
    extern lv_obj_t* lbl_hl_method;
    extern lv_obj_t* lbl_md_method;
    extern lv_obj_t* lbl_location_latitude;
    extern lv_obj_t* lbl_location_longitude;
    extern lv_obj_t* lbl_location_altitude;
    extern lv_obj_t* lbl_date;
    extern lv_obj_t* lbl_time_zone_offset;

    extern lv_obj_t* dd_calc_method;
    extern lv_obj_t* ta_angle_imsak;
    extern lv_obj_t* ta_angle_fajr;
    extern lv_obj_t* ta_angle_maghrib;
    extern lv_obj_t* ta_angle_isha;
    extern lv_obj_t* ta_offset_imsak;
    extern lv_obj_t* ta_offset_fajr;
    extern lv_obj_t* ta_offset_sunrise;
    extern lv_obj_t* ta_offset_duhur;
    extern lv_obj_t* ta_offset_asr;
    extern lv_obj_t* ta_offset_sunset;
    extern lv_obj_t* ta_offset_maghrib;
    extern lv_obj_t* ta_offset_isha;
    extern lv_obj_t* ta_offset_midnight;
    extern lv_obj_t* dd_juristic;
    extern lv_obj_t* dd_hl_method;
    extern lv_obj_t* dd_md_method;
    extern lv_obj_t* ta_location_latitude;
    extern lv_obj_t* ta_location_longitude;
    extern lv_obj_t* ta_location_altitude;
    extern lv_obj_t* ta_date;
    extern lv_obj_t* ta_time_zone_offset;
   
    extern lv_obj_t* scr_settings_keyboard;
    extern lv_obj_t* scr_settings_calendar;

    // Settings Screen Styles
    extern lv_style_t style_scr_settings;
    extern lv_style_t style_obj_scr_settings_header;
    extern lv_style_t style_btn_scr_settings_back;
    extern lv_style_t style_lbl_scr_settings_back;
    extern lv_style_t style_lbl_scr_settings_header;
    extern lv_style_t style_obj_scr_settings_items;
    extern lv_style_t style_obj_scr_settings_items_section;
    extern lv_style_t style_lbl_scr_settings_items_header;
    extern lv_style_t style_obj_scr_settings_items_content_left;
    extern lv_style_t style_obj_scr_settings_items_content_right;
    extern lv_style_t style_scr_settings_items_content_lbl;
    extern lv_style_t style_scr_settings_items_content_obj;
    extern lv_style_t style_scr_settings_keyboard;
    extern lv_style_t style_scr_settings_calendar;

    void scr_settings_create_objects(void);
    void scr_settings_style_init(void);
    void scr_settings_style_add(void);
    void scr_settings_init_objects(void);

#ifdef __cplusplus
}
#endif

#endif