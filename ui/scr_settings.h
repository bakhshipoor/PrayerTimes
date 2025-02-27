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
#define SETTINGS_ITEMS_HEADER_BG_COLOR 0xeccc68
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
   

    // Main Screen Styles
    extern lv_style_t style_scr_settings;
    extern lv_style_t style_obj_scr_settings_header;
    extern lv_style_t style_btn_scr_settings_back;
    extern lv_style_t style_lbl_scr_settings_back;
    extern lv_style_t style_lbl_scr_settings_header;
    extern lv_style_t style_obj_scr_settings_items;
    extern lv_style_t style_obj_scr_settings_items_section;
    extern lv_style_t style_obj_scr_settings_items_header;

    void scr_settings_create_objects(void);
    void scr_settings_style_init(void);
    void scr_settings_style_add(void);
    void scr_settings_init_objects(void);

#ifdef __cplusplus
}
#endif

#endif