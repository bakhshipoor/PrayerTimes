#include "scr_settings.h"
#include "prayer_times_ui_events.h"
#include "prayer_times_ui_texts.h"

static const char* calc_method_options = 
SCR_SETTINGS_CALC_METHOD_CUSTOM"\n"
SCR_SETTINGS_CALC_METHOD_ALGERIA_MOFA"\n"
SCR_SETTINGS_CALC_METHOD_AMERICA_NORTH"\n"
SCR_SETTINGS_CALC_METHOD_EGYPT_GAS"\n"
SCR_SETTINGS_CALC_METHOD_FRANCE_MUSLIM"\n"
SCR_SETTINGS_CALC_METHOD_INDONESIA_SIHAT"\n"
SCR_SETTINGS_CALC_METHOD_IRAN_QOM"\n"
SCR_SETTINGS_CALC_METHOD_IRAN_TEHRAN"\n"
SCR_SETTINGS_CALC_METHOD_KUWAIT"\n"
SCR_SETTINGS_CALC_METHOD_MALAYSIA"\n"
SCR_SETTINGS_CALC_METHOD_MECCA_UMMALQURA"\n"
SCR_SETTINGS_CALC_METHOD_MOROCCO"\n"
SCR_SETTINGS_CALC_METHOD_PAKISTAN_KARACHI"\n"
SCR_SETTINGS_CALC_METHOD_QATAR"\n"
SCR_SETTINGS_CALC_METHOD_RUSSIA_MUSLIM"\n"
SCR_SETTINGS_CALC_METHOD_SINGAPORE"\n"
SCR_SETTINGS_CALC_METHOD_TUNISIA_MOFA"\n"
SCR_SETTINGS_CALC_METHOD_TURKIYE_DIYANET"\n"
SCR_SETTINGS_CALC_METHOD_WORLD_LEAGUE;

static const char* juristic_method_options =
SCR_SETTINGS_JURISTIC_METHOD_STANDARD"\n"
SCR_SETTINGS_JURISTIC_METHOD_HANAFI;

static const char* hl_method_options =
SCR_SETTINGS_HL_METHOD_NONE"\n"
SCR_SETTINGS_HL_METHOD_NIGHTMIDDLE"\n"
SCR_SETTINGS_HL_ANGLEBASED"\n"
SCR_SETTINGS_HL_METHOD_ONESEVENTH;

static const char* md_method_options =
SCR_SETTINGS_MD_METHOD_STANDARD"\n"
SCR_SETTINGS_MD_METHOD_JAFARI;

static const char* scr_settings_calendar_years = "2030\n2029\n2028\n2027\n2026\n2025\n2024\n2023\n2022\n2021\n2020";

// Screens
lv_obj_t* scr_settings = NULL;

// Settings Screens Objects
lv_obj_t* obj_scr_settings_header = NULL;
lv_obj_t* btn_scr_settings_back = NULL;
lv_obj_t* lbl_scr_settings_back = NULL;
lv_obj_t* lbl_scr_settings_header = NULL;
lv_obj_t* obj_scr_settings_items = NULL;

lv_obj_t* obj_items_calc_method = NULL;
lv_obj_t* obj_items_angles = NULL;
lv_obj_t* obj_items_offsets = NULL;
lv_obj_t* obj_items_juristic = NULL;
lv_obj_t* obj_items_hl_method = NULL;
lv_obj_t* obj_items_md_method = NULL;
lv_obj_t* obj_items_location = NULL;
lv_obj_t* obj_items_date = NULL;
lv_obj_t* obj_items_time_zone_offset = NULL;

lv_obj_t* lbl_items_calc_method_header = NULL;
lv_obj_t* lbl_items_angles_header = NULL;
lv_obj_t* lbl_items_offsets_header = NULL;
lv_obj_t* lbl_items_juristic_header = NULL;
lv_obj_t* lbl_items_hl_method_header = NULL;
lv_obj_t* lbl_items_md_method_header = NULL;
lv_obj_t* lbl_items_location_header = NULL;
lv_obj_t* lbl_items_date_header = NULL;
lv_obj_t* lbl_items_time_zone_offset_header = NULL;

lv_obj_t* obj_items_calc_method_content_left = NULL;
lv_obj_t* obj_items_angles_content_left = NULL;
lv_obj_t* obj_items_offsets_content_left = NULL;
lv_obj_t* obj_items_juristic_content_left = NULL;
lv_obj_t* obj_items_hl_method_content_left = NULL;
lv_obj_t* obj_items_md_method_content_left = NULL;
lv_obj_t* obj_items_location_content_left = NULL;
lv_obj_t* obj_items_date_content_left = NULL;
lv_obj_t* obj_items_time_zone_offset_content_left = NULL;
lv_obj_t* obj_items_calc_method_content_right = NULL;
lv_obj_t* obj_items_angles_content_right = NULL;
lv_obj_t* obj_items_offsets_content_right = NULL;
lv_obj_t* obj_items_juristic_content_right = NULL;
lv_obj_t* obj_items_hl_method_content_right = NULL;
lv_obj_t* obj_items_md_method_content_right = NULL;
lv_obj_t* obj_items_location_content_right = NULL;
lv_obj_t* obj_items_date_content_right = NULL;
lv_obj_t* obj_items_time_zone_offset_content_right = NULL;

lv_obj_t* lbl_calc_method = NULL;
lv_obj_t* lbl_angle_imsak = NULL;
lv_obj_t* lbl_angle_fajr = NULL;
lv_obj_t* lbl_angle_maghrib = NULL;
lv_obj_t* lbl_angle_isha = NULL;
lv_obj_t* lbl_offset_imsak = NULL;
lv_obj_t* lbl_offset_fajr = NULL;
lv_obj_t* lbl_offset_sunrise = NULL;
lv_obj_t* lbl_offset_duhur = NULL;
lv_obj_t* lbl_offset_asr = NULL;
lv_obj_t* lbl_offset_sunset = NULL;
lv_obj_t* lbl_offset_maghrib = NULL;
lv_obj_t* lbl_offset_isha = NULL;
lv_obj_t* lbl_offset_midnight = NULL;
lv_obj_t* lbl_juristic = NULL;
lv_obj_t* lbl_hl_method = NULL;
lv_obj_t* lbl_md_method = NULL;
lv_obj_t* lbl_location_latitude = NULL;
lv_obj_t* lbl_location_longitude = NULL;
lv_obj_t* lbl_location_altitude = NULL;
lv_obj_t* lbl_date = NULL;
lv_obj_t* lbl_time_zone_offset = NULL;

lv_obj_t* dd_calc_method = NULL;
lv_obj_t* ta_angle_imsak = NULL;
lv_obj_t* ta_angle_fajr = NULL;
lv_obj_t* ta_angle_maghrib = NULL;
lv_obj_t* ta_angle_isha = NULL;
lv_obj_t* ta_offset_imsak = NULL;
lv_obj_t* ta_offset_fajr = NULL;
lv_obj_t* ta_offset_sunrise = NULL;
lv_obj_t* ta_offset_duhur = NULL;
lv_obj_t* ta_offset_asr = NULL;
lv_obj_t* ta_offset_sunset = NULL;
lv_obj_t* ta_offset_maghrib = NULL;
lv_obj_t* ta_offset_isha = NULL;
lv_obj_t* ta_offset_midnight = NULL;
lv_obj_t* dd_juristic = NULL;
lv_obj_t* dd_hl_method = NULL;
lv_obj_t* dd_md_method = NULL;
lv_obj_t* ta_location_latitude = NULL;
lv_obj_t* ta_location_longitude = NULL;
lv_obj_t* ta_location_altitude = NULL;
lv_obj_t* ta_date = NULL;
lv_obj_t* ta_time_zone_offset = NULL;

lv_obj_t* scr_settings_keyboard = NULL;
lv_obj_t* scr_settings_calendar = NULL;

// Settings Screen Styles
lv_style_t style_scr_settings = { 0 };
lv_style_t style_obj_scr_settings_header = { 0 };
lv_style_t style_btn_scr_settings_back = { 0 };
lv_style_t style_lbl_scr_settings_back = { 0 };
lv_style_t style_lbl_scr_settings_header = { 0 };
lv_style_t style_obj_scr_settings_items = { 0 };
lv_style_t style_obj_scr_settings_items_section = { 0 };
lv_style_t style_lbl_scr_settings_items_header = { 0 };
lv_style_t style_obj_scr_settings_items_content_left = { 0 };
lv_style_t style_obj_scr_settings_items_content_right = { 0 };
lv_style_t style_scr_settings_items_content_lbl = { 0 };
lv_style_t style_scr_settings_items_content_obj = { 0 };
lv_style_t style_scr_settings_keyboard = { 0 };
lv_style_t style_scr_settings_calendar = { 0 };

void scr_settings_create_objects(void)
{
    scr_settings = lv_obj_create(NULL);
    obj_scr_settings_header = lv_obj_create(scr_settings);
    btn_scr_settings_back = lv_button_create(obj_scr_settings_header);
    lbl_scr_settings_back = lv_label_create(btn_scr_settings_back);
    lbl_scr_settings_header = lv_label_create(obj_scr_settings_header);
    obj_scr_settings_items = lv_obj_create(scr_settings);

    obj_items_calc_method = lv_obj_create(obj_scr_settings_items);
    obj_items_angles = lv_obj_create(obj_scr_settings_items);
    obj_items_offsets = lv_obj_create(obj_scr_settings_items);
    obj_items_juristic = lv_obj_create(obj_scr_settings_items);
    obj_items_hl_method = lv_obj_create(obj_scr_settings_items);
    obj_items_md_method = lv_obj_create(obj_scr_settings_items);
    obj_items_location = lv_obj_create(obj_scr_settings_items);
    obj_items_date = lv_obj_create(obj_scr_settings_items);
    obj_items_time_zone_offset = lv_obj_create(obj_scr_settings_items);

    lbl_items_calc_method_header = lv_label_create(obj_items_calc_method);
    lbl_items_angles_header = lv_label_create(obj_items_angles);
    lbl_items_offsets_header = lv_label_create(obj_items_offsets);
    lbl_items_juristic_header = lv_label_create(obj_items_juristic);
    lbl_items_hl_method_header = lv_label_create(obj_items_hl_method);
    lbl_items_md_method_header = lv_label_create(obj_items_md_method);
    lbl_items_location_header = lv_label_create(obj_items_location);
    lbl_items_date_header = lv_label_create(obj_items_date);
    lbl_items_time_zone_offset_header = lv_label_create(obj_items_time_zone_offset);

    obj_items_calc_method_content_left = lv_obj_create(obj_items_calc_method);
    obj_items_angles_content_left = lv_obj_create(obj_items_angles);
    obj_items_offsets_content_left = lv_obj_create(obj_items_offsets);
    obj_items_juristic_content_left = lv_obj_create(obj_items_juristic);
    obj_items_hl_method_content_left = lv_obj_create(obj_items_hl_method);
    obj_items_md_method_content_left = lv_obj_create(obj_items_md_method);
    obj_items_location_content_left = lv_obj_create(obj_items_location);
    obj_items_date_content_left = lv_obj_create(obj_items_date);
    obj_items_time_zone_offset_content_left = lv_obj_create(obj_items_time_zone_offset); 
    obj_items_calc_method_content_right = lv_obj_create(obj_items_calc_method);
    obj_items_angles_content_right = lv_obj_create(obj_items_angles);
    obj_items_offsets_content_right = lv_obj_create(obj_items_offsets);
    obj_items_juristic_content_right = lv_obj_create(obj_items_juristic);
    obj_items_hl_method_content_right = lv_obj_create(obj_items_hl_method);
    obj_items_md_method_content_right = lv_obj_create(obj_items_md_method);
    obj_items_location_content_right = lv_obj_create(obj_items_location);
    obj_items_date_content_right = lv_obj_create(obj_items_date);
    obj_items_time_zone_offset_content_right = lv_obj_create(obj_items_time_zone_offset);

    lbl_calc_method = lv_label_create(obj_items_calc_method_content_left);
    lbl_angle_imsak = lv_label_create(obj_items_angles_content_left);
    lbl_angle_fajr = lv_label_create(obj_items_angles_content_left);
    lbl_angle_maghrib = lv_label_create(obj_items_angles_content_left);
    lbl_angle_isha = lv_label_create(obj_items_angles_content_left);
    lbl_offset_imsak = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_fajr = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_sunrise = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_duhur = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_asr = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_sunset = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_maghrib = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_isha = lv_label_create(obj_items_offsets_content_left);
    lbl_offset_midnight = lv_label_create(obj_items_offsets_content_left);
    lbl_juristic = lv_label_create(obj_items_juristic_content_left);
    lbl_hl_method = lv_label_create(obj_items_hl_method_content_left);
    lbl_md_method = lv_label_create(obj_items_md_method_content_left);
    lbl_location_latitude = lv_label_create(obj_items_location_content_left);
    lbl_location_longitude = lv_label_create(obj_items_location_content_left);
    lbl_location_altitude = lv_label_create(obj_items_location_content_left);
    lbl_date = lv_label_create(obj_items_date_content_left);
    lbl_time_zone_offset = lv_label_create(obj_items_time_zone_offset_content_left);

    dd_calc_method = lv_dropdown_create(obj_items_calc_method_content_right);
    ta_angle_imsak = lv_textarea_create(obj_items_angles_content_right);
    ta_angle_fajr = lv_textarea_create(obj_items_angles_content_right);
    ta_angle_maghrib = lv_textarea_create(obj_items_angles_content_right);
    ta_angle_isha = lv_textarea_create(obj_items_angles_content_right);
    ta_offset_imsak = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_fajr = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_sunrise = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_duhur = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_asr = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_sunset = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_maghrib = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_isha = lv_textarea_create(obj_items_offsets_content_right);
    ta_offset_midnight = lv_textarea_create(obj_items_offsets_content_right);
    dd_juristic = lv_dropdown_create(obj_items_juristic_content_right);
    dd_hl_method = lv_dropdown_create(obj_items_hl_method_content_right);
    dd_md_method = lv_dropdown_create(obj_items_md_method_content_right);
    ta_location_latitude = lv_textarea_create(obj_items_location_content_right);
    ta_location_longitude = lv_textarea_create(obj_items_location_content_right);
    ta_location_altitude = lv_textarea_create(obj_items_location_content_right);
    ta_date = lv_textarea_create(obj_items_date_content_right);
    ta_time_zone_offset = lv_textarea_create(obj_items_time_zone_offset_content_right);

    scr_settings_keyboard = lv_keyboard_create(scr_settings);

    scr_settings_calendar = lv_calendar_create(scr_settings);
}

void scr_settings_style_init(void)
{
    lv_style_init(&style_scr_settings);
    lv_style_init(&style_obj_scr_settings_header);
    lv_style_init(&style_btn_scr_settings_back);
    lv_style_init(&style_lbl_scr_settings_back);
    lv_style_init(&style_lbl_scr_settings_header);
    lv_style_init(&style_obj_scr_settings_items);
    lv_style_init(&style_obj_scr_settings_items_section);
    lv_style_init(&style_lbl_scr_settings_items_header);
    lv_style_init(&style_obj_scr_settings_items_content_left);
    lv_style_init(&style_obj_scr_settings_items_content_right);
    lv_style_init(&style_scr_settings_items_content_lbl);
    lv_style_init(&style_scr_settings_items_content_obj);
    lv_style_init(&style_scr_settings_keyboard);
    lv_style_init(&style_scr_settings_calendar);

    lv_style_set_bg_color(&style_scr_settings, lv_color_hex(SETTINGS_SCREEN_BG_COLOR));
    lv_style_set_text_color(&style_scr_settings, lv_color_hex(0x000000));

    lv_style_set_size(&style_obj_scr_settings_header, lv_pct(100), lv_pct(30));
    lv_style_set_bg_color(&style_obj_scr_settings_header, lv_color_hex(SETTINGS_HEADER_BG_COLOR));
    lv_style_set_border_width(&style_obj_scr_settings_header, 0);
    lv_style_set_radius(&style_obj_scr_settings_header, 0);
    lv_style_set_align(&style_obj_scr_settings_header, LV_ALIGN_TOP_MID);
    lv_style_set_pad_all(&style_obj_scr_settings_header, 0);

    lv_style_set_y(&style_btn_scr_settings_back, lv_pct(10));
    lv_style_set_x(&style_btn_scr_settings_back, lv_pct(5));
    lv_style_set_width(&style_btn_scr_settings_back, lv_pct(10));
    lv_style_set_height(&style_btn_scr_settings_back, lv_pct(46));
    lv_style_set_pad_all(&style_btn_scr_settings_back, 0);
    lv_style_set_pad_top(&style_btn_scr_settings_back, 4);
    lv_style_set_text_align(&style_btn_scr_settings_back, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_opa(&style_btn_scr_settings_back, 0);
    lv_style_set_shadow_offset_y(&style_btn_scr_settings_back, 0);
    lv_style_set_shadow_opa(&style_btn_scr_settings_back, 0);

    lv_style_set_size(&style_lbl_scr_settings_back, lv_pct(100), lv_pct(100));
    lv_style_set_text_font(&style_lbl_scr_settings_back, &lv_font_montserrat_28);
    lv_style_set_align(&style_lbl_scr_settings_back, LV_ALIGN_CENTER);
    lv_style_set_text_align(&style_lbl_scr_settings_back, LV_TEXT_ALIGN_CENTER);

    lv_style_set_y(&style_lbl_scr_settings_header, lv_pct(10));
    lv_style_set_x(&style_lbl_scr_settings_header, lv_pct(17));
    lv_style_set_width(&style_lbl_scr_settings_header, lv_pct(75));
    lv_style_set_height(&style_lbl_scr_settings_header, lv_pct(46));
    lv_style_set_text_align(&style_lbl_scr_settings_header, LV_TEXT_ALIGN_LEFT);
    lv_style_set_pad_top(&style_lbl_scr_settings_header, 10);
    lv_style_set_text_font(&style_lbl_scr_settings_header, &lv_font_montserrat_18);
    lv_style_set_text_color(&style_lbl_scr_settings_header, lv_color_hex(SETTINGS_ITEMS_BG_COLOR));

    lv_style_set_size(&style_obj_scr_settings_items, lv_pct(90), lv_pct(75));
    lv_style_set_bg_color(&style_obj_scr_settings_items, lv_color_hex(SETTINGS_ITEMS_BG_COLOR));
    lv_style_set_border_width(&style_obj_scr_settings_items, 0);
    lv_style_set_radius(&style_obj_scr_settings_items, 10);
    lv_style_set_align(&style_obj_scr_settings_items, LV_ALIGN_TOP_MID);
    lv_style_set_y(&style_obj_scr_settings_items, lv_pct(20));
    lv_style_set_pad_row(&style_obj_scr_settings_items, 5);
    lv_style_set_pad_column(&style_obj_scr_settings_items, 5);
    lv_style_set_shadow_color(&style_obj_scr_settings_items, lv_color_hex(0x000000));
    lv_style_set_shadow_offset_x(&style_obj_scr_settings_items, 0);
    lv_style_set_shadow_offset_y(&style_obj_scr_settings_items, 0);
    lv_style_set_shadow_width(&style_obj_scr_settings_items, 10);
    lv_style_set_shadow_spread(&style_obj_scr_settings_items, 2);
    lv_style_set_shadow_opa(&style_obj_scr_settings_items, LV_OPA_20);
    lv_style_set_flex_flow(&style_obj_scr_settings_items, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(&style_obj_scr_settings_items, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_style_set_layout(&style_obj_scr_settings_items, LV_LAYOUT_FLEX);

    lv_style_set_size(&style_obj_scr_settings_items_section, lv_pct(100), LV_SIZE_CONTENT);
    lv_style_set_pad_all(&style_obj_scr_settings_items_section, 0);
    lv_style_set_bg_color(&style_obj_scr_settings_items_section, lv_color_hex(SETTINGS_ITEMS_SECTION_BG_COLOR));
    lv_style_set_border_color(&style_obj_scr_settings_items_section, lv_color_hex(SETTINGS_SCREEN_BG_COLOR));
    lv_style_set_flex_flow(&style_obj_scr_settings_items_section, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(&style_obj_scr_settings_items_section, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_style_set_layout(&style_obj_scr_settings_items_section, LV_LAYOUT_FLEX);
    lv_style_set_pad_row(&style_obj_scr_settings_items_section, 5);

    lv_style_set_size(&style_lbl_scr_settings_items_header, lv_pct(100), 30);
    lv_style_set_bg_color(&style_lbl_scr_settings_items_header, lv_color_hex(SETTINGS_ITEMS_HEADER_BG_COLOR));
    lv_style_set_bg_opa(&style_lbl_scr_settings_items_header, LV_OPA_100);
    lv_style_set_text_font(&style_lbl_scr_settings_items_header, &lv_font_montserrat_18);
    lv_style_set_pad_all(&style_lbl_scr_settings_items_header, 6);
    lv_style_set_text_align(&style_lbl_scr_settings_items_header, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_color(&style_lbl_scr_settings_items_header, lv_color_hex(SETTINGS_ITEMS_HEADER_TEXT_COLOR));

    lv_style_set_height(&style_obj_scr_settings_items_content_left, LV_SIZE_CONTENT);
    lv_style_set_border_width(&style_obj_scr_settings_items_content_left, 0);
    lv_style_set_bg_opa(&style_obj_scr_settings_items_content_left, LV_OPA_0);
    lv_style_set_pad_left(&style_obj_scr_settings_items_content_left, 0);
    lv_style_set_pad_right(&style_obj_scr_settings_items_content_left, 0);
    lv_style_set_pad_bottom(&style_obj_scr_settings_items_content_left, 5);
    lv_style_set_flex_grow(&style_obj_scr_settings_items_content_left, 2);
    lv_style_set_flex_flow(&style_obj_scr_settings_items_content_left, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(&style_obj_scr_settings_items_content_left, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_style_set_layout(&style_obj_scr_settings_items_content_left, LV_LAYOUT_FLEX);

    lv_style_set_height(&style_obj_scr_settings_items_content_right, LV_SIZE_CONTENT);
    lv_style_set_border_width(&style_obj_scr_settings_items_content_right, 0);
    lv_style_set_bg_opa(&style_obj_scr_settings_items_content_right, LV_OPA_0);
    lv_style_set_pad_left(&style_obj_scr_settings_items_content_right, 5);
    lv_style_set_pad_right(&style_obj_scr_settings_items_content_right, 5);
    lv_style_set_pad_bottom(&style_obj_scr_settings_items_content_right, 5);
    lv_style_set_flex_grow(&style_obj_scr_settings_items_content_right, 3);
    lv_style_set_flex_flow(&style_obj_scr_settings_items_content_right, LV_FLEX_FLOW_ROW_WRAP);
    lv_style_set_flex_main_place(&style_obj_scr_settings_items_content_right, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_style_set_layout(&style_obj_scr_settings_items_content_right, LV_LAYOUT_FLEX);

    lv_style_set_size(&style_scr_settings_items_content_lbl, lv_pct(100), 40);
    lv_style_set_text_font(&style_scr_settings_items_content_lbl, &lv_font_montserrat_12);
    lv_style_set_pad_all(&style_scr_settings_items_content_lbl, 14);

    lv_style_set_size(&style_scr_settings_items_content_obj, lv_pct(100), 40);
    lv_style_set_text_font(&style_scr_settings_items_content_obj, &lv_font_montserrat_12);

    lv_style_set_size(&style_scr_settings_keyboard, lv_pct(35), lv_pct(75));
    lv_style_set_text_font(&style_scr_settings_keyboard, &lv_font_montserrat_14);
    lv_style_set_radius(&style_scr_settings_keyboard, 10);
    lv_style_set_bg_opa(&style_scr_settings_keyboard, LV_OPA_90);

    lv_style_set_size(&style_scr_settings_calendar, lv_pct(35), lv_pct(75));
    lv_style_set_text_font(&style_scr_settings_calendar, &lv_font_montserrat_12);
    lv_style_set_radius(&style_scr_settings_calendar, 10);
    lv_style_set_bg_opa(&style_scr_settings_calendar, LV_OPA_90);

}

void scr_settings_style_add(void)
{
    lv_obj_add_style(scr_settings, &style_scr_settings, LV_PART_MAIN);
    lv_obj_add_style(obj_scr_settings_header, &style_obj_scr_settings_header, LV_PART_MAIN);
    lv_obj_add_style(btn_scr_settings_back, &style_btn_scr_settings_back, LV_PART_MAIN);
    lv_obj_add_style(lbl_scr_settings_back, &style_lbl_scr_settings_back, LV_PART_MAIN);
    lv_obj_add_style(lbl_scr_settings_header, &style_lbl_scr_settings_header, LV_PART_MAIN);
    lv_obj_add_style(obj_scr_settings_items, &style_obj_scr_settings_items, LV_PART_MAIN);

    lv_obj_add_style(obj_items_calc_method, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_angles, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_offsets, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_juristic, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_hl_method, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_md_method, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_location, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_date, &style_obj_scr_settings_items_section, LV_PART_MAIN);
    lv_obj_add_style(obj_items_time_zone_offset, &style_obj_scr_settings_items_section, LV_PART_MAIN);

    lv_obj_add_style(lbl_items_calc_method_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_angles_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_offsets_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_juristic_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_hl_method_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_md_method_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_location_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_date_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_time_zone_offset_header, &style_lbl_scr_settings_items_header, LV_PART_MAIN);

    lv_obj_add_style(obj_items_calc_method_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_angles_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_offsets_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_juristic_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_hl_method_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_md_method_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_location_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_date_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);
    lv_obj_add_style(obj_items_time_zone_offset_content_left, &style_obj_scr_settings_items_content_left, LV_PART_MAIN);

    lv_obj_add_style(obj_items_calc_method_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_angles_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_offsets_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_juristic_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_hl_method_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_md_method_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_location_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_date_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);
    lv_obj_add_style(obj_items_time_zone_offset_content_right, &style_obj_scr_settings_items_content_right, LV_PART_MAIN);

    lv_obj_add_style(lbl_calc_method, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_angle_imsak, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_angle_fajr, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_angle_maghrib, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_angle_isha, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_imsak, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_fajr, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_sunrise, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_duhur, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_asr, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_sunset, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_maghrib, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_isha, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_offset_midnight, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_juristic, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_hl_method, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_md_method, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_location_latitude, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_location_longitude, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_location_altitude, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_date, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
    lv_obj_add_style(lbl_time_zone_offset, &style_scr_settings_items_content_lbl, LV_PART_MAIN);
        
    lv_obj_add_style(dd_calc_method, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_angle_imsak, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_angle_fajr, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_angle_maghrib, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_angle_isha, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_imsak, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_fajr, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_sunrise, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_duhur, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_asr, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_sunset, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_maghrib, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_isha, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_offset_midnight, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(dd_juristic, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(dd_hl_method, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(dd_md_method, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_location_longitude, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_location_latitude, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_location_altitude, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_date, &style_scr_settings_items_content_obj, LV_PART_MAIN);
    lv_obj_add_style(ta_time_zone_offset, &style_scr_settings_items_content_obj, LV_PART_MAIN);

    lv_obj_add_style(scr_settings_keyboard, &style_scr_settings_keyboard, LV_PART_MAIN);

    lv_obj_add_style(scr_settings_calendar, &style_scr_settings_calendar, LV_PART_MAIN);
}

void scr_settings_init_objects(void)
{
    
    lv_label_set_text(lbl_scr_settings_back, LV_SYMBOL_LEFT);
    lv_obj_add_event_cb(btn_scr_settings_back, scr_settings_btn_back_event, LV_EVENT_CLICKED, NULL);

    lv_label_set_text_static(lbl_scr_settings_header, SCR_SETTINGS_HEADER_TITLE);
    
    lv_label_set_text_static(lbl_items_calc_method_header, SCR_SETTINGS_LBL_ITEMS_CALC_METHOD_HEADER);
    lv_label_set_text_static(lbl_items_angles_header, SCR_SETTINGS_LBL_ITEMS_ANGLES_HEADER);
    lv_label_set_text_static(lbl_items_offsets_header, SCR_SETTINGS_LBL_ITEMS_OFFSETS_HEADER);
    lv_label_set_text_static(lbl_items_juristic_header, SCR_SETTINGS_LBL_ITEMS_JURISTIC_HEADER);
    lv_label_set_text_static(lbl_items_hl_method_header, SCR_SETTINGS_LBL_ITEMS_HL_METHOD_HEADER);
    lv_label_set_text_static(lbl_items_md_method_header, SCR_SETTINGS_LBL_ITEMS_MD_METHOD_HEADER);
    lv_label_set_text_static(lbl_items_location_header, SCR_SETTINGS_LBL_ITEMS_LOCATION_HEADER);
    lv_label_set_text_static(lbl_items_date_header, SCR_SETTINGS_LBL_ITEMS_DATE_HEADER);
    lv_label_set_text_static(lbl_items_time_zone_offset_header, SCR_SETTINGS_LBL_ITEMS_TIME_ZONE_OFFSET_HEADER);

    lv_label_set_text_static(lbl_calc_method, SCR_SETTINGS_LBL_CALC_METHOD);
    lv_label_set_text_static(lbl_angle_imsak, SCR_SETTINGS_LBL_ANGLES_IMSAK);
    lv_label_set_text_static(lbl_angle_fajr, SCR_SETTINGS_LBL_ANGLES_FAJR);
    lv_label_set_text_static(lbl_angle_maghrib, SCR_SETTINGS_LBL_ANGLES_MAGHRIB);
    lv_label_set_text_static(lbl_angle_isha, SCR_SETTINGS_LBL_ANGLES_ISHA);
    lv_label_set_text_static(lbl_offset_imsak, SCR_SETTINGS_LBL_OFFSETS_IMSAK);
    lv_label_set_text_static(lbl_offset_fajr, SCR_SETTINGS_LBL_OFFSETS_FAJR);
    lv_label_set_text_static(lbl_offset_sunrise, SCR_SETTINGS_LBL_OFFSETS_SUNRISE);
    lv_label_set_text_static(lbl_offset_duhur, SCR_SETTINGS_LBL_OFFSETS_DUHUR);
    lv_label_set_text_static(lbl_offset_asr, SCR_SETTINGS_LBL_OFFSETS_ASR);
    lv_label_set_text_static(lbl_offset_sunset, SCR_SETTINGS_LBL_OFFSETS_SUNSET);
    lv_label_set_text_static(lbl_offset_maghrib, SCR_SETTINGS_LBL_OFFSETS_MAGHRIB);
    lv_label_set_text_static(lbl_offset_isha, SCR_SETTINGS_LBL_OFFSETS_ISHA);
    lv_label_set_text_static(lbl_offset_midnight, SCR_SETTINGS_LBL_OFFSETS_MIDNIGHT);
    lv_label_set_text_static(lbl_juristic, SCR_SETTINGS_LBL_JURISTIC);
    lv_label_set_text_static(lbl_hl_method, SCR_SETTINGS_LBL_HL_METHOD);
    lv_label_set_text_static(lbl_md_method, SCR_SETTINGS_LBL_MD_METHOD);
    lv_label_set_text_static(lbl_location_latitude, SCR_SETTINGS_LBL_LOCATION_LATATIUDE);
    lv_label_set_text_static(lbl_location_longitude, SCR_SETTINGS_LBL_LOCATION_LONGITUDE);
    lv_label_set_text_static(lbl_location_altitude, SCR_SETTINGS_LBL_LOCATION_ALTITUDE);
    lv_label_set_text_static(lbl_date, SCR_SETTINGS_LBL_DATE);
    lv_label_set_text_static(lbl_time_zone_offset, SCR_SETTINGS_LBL_TIME_ZONE_OFFSET);

    lv_textarea_set_one_line(ta_angle_imsak, true);
    lv_textarea_set_placeholder_text(ta_angle_imsak, SCR_SETTINGS_TA_ANGLES_IMSAK_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_angle_imsak, SCR_SETTINGS_TA_ACCEPTED_CHARS_FLOAT);
    lv_textarea_set_max_length(ta_angle_imsak, SCR_SETTINGS_TA_MAX_LENGHT_FLOAT);

    lv_textarea_set_one_line(ta_angle_fajr, true);
    lv_textarea_set_placeholder_text(ta_angle_fajr, SCR_SETTINGS_TA_ANGLES_FAJR_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_angle_fajr, SCR_SETTINGS_TA_ACCEPTED_CHARS_FLOAT);
    lv_textarea_set_max_length(ta_angle_fajr, SCR_SETTINGS_TA_MAX_LENGHT_FLOAT);

    lv_textarea_set_one_line(ta_angle_maghrib, true);
    lv_textarea_set_placeholder_text(ta_angle_maghrib, SCR_SETTINGS_TA_ANGLES_MAGHRIB_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_angle_maghrib, SCR_SETTINGS_TA_ACCEPTED_CHARS_FLOAT);
    lv_textarea_set_max_length(ta_angle_maghrib, SCR_SETTINGS_TA_MAX_LENGHT_FLOAT);

    lv_textarea_set_one_line(ta_angle_isha, true);
    lv_textarea_set_placeholder_text(ta_angle_isha, SCR_SETTINGS_TA_ANGLES_ISHA_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_angle_isha, SCR_SETTINGS_TA_ACCEPTED_CHARS_FLOAT);
    lv_textarea_set_max_length(ta_angle_isha, SCR_SETTINGS_TA_MAX_LENGHT_FLOAT);

    lv_textarea_set_one_line(ta_offset_imsak, true);
    lv_textarea_set_placeholder_text(ta_offset_imsak, SCR_SETTINGS_TA_OFFSETS_IMSAK_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_imsak, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_imsak, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_fajr, true);
    lv_textarea_set_placeholder_text(ta_offset_fajr, SCR_SETTINGS_TA_OFFSETS_FAJR_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_fajr, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_fajr, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_sunrise, true);
    lv_textarea_set_placeholder_text(ta_offset_sunrise, SCR_SETTINGS_TA_OFFSETS_SUNRISE_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_sunrise, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_sunrise, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_duhur, true);
    lv_textarea_set_placeholder_text(ta_offset_duhur, SCR_SETTINGS_TA_OFFSETS_DUHUR_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_duhur, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_duhur, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_asr, true);
    lv_textarea_set_placeholder_text(ta_offset_asr, SCR_SETTINGS_TA_OFFSETS_ASR_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_asr, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_asr, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_sunset, true);
    lv_textarea_set_placeholder_text(ta_offset_sunset, SCR_SETTINGS_TA_OFFSETS_SUNSET_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_sunset, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_sunset, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_maghrib, true);
    lv_textarea_set_placeholder_text(ta_offset_maghrib, SCR_SETTINGS_TA_OFFSETS_MAGHRIB_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_maghrib, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_maghrib, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_isha, true);
    lv_textarea_set_placeholder_text(ta_offset_isha, SCR_SETTINGS_TA_OFFSETS_ISHA_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_isha, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_isha, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_offset_midnight, true);
    lv_textarea_set_placeholder_text(ta_offset_midnight, SCR_SETTINGS_TA_OFFSETS_MIDNIGHT_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_offset_midnight, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_offset_midnight, SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL);

    lv_textarea_set_one_line(ta_location_latitude, true);
    lv_textarea_set_placeholder_text(ta_location_latitude, SCR_SETTINGS_TA_LOCATION_LATATIUDE_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_location_latitude, SCR_SETTINGS_TA_ACCEPTED_CHARS_FLOAT);
    lv_textarea_set_max_length(ta_location_latitude, SCR_SETTINGS_TA_MAX_LENGHT_FLOAT);

    lv_textarea_set_one_line(ta_location_longitude, true);
    lv_textarea_set_placeholder_text(ta_location_longitude, SCR_SETTINGS_TA_LOCATION_LONGITUDE_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_location_longitude, SCR_SETTINGS_TA_ACCEPTED_CHARS_FLOAT);
    lv_textarea_set_max_length(ta_location_longitude, SCR_SETTINGS_TA_MAX_LENGHT_FLOAT);

    lv_textarea_set_one_line(ta_location_altitude, true);
    lv_textarea_set_placeholder_text(ta_location_altitude, SCR_SETTINGS_TA_LOCATION_ALTITUDE_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_location_altitude, SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL);
    lv_textarea_set_max_length(ta_location_altitude, SCR_SETTINGS_TA_MAX_LENGHT_FLOAT);

    lv_textarea_set_one_line(ta_date, true);
    lv_textarea_set_placeholder_text(ta_date, SCR_SETTINGS_TA_DATE_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_date, SCR_SETTINGS_TA_ACCEPTED_CHARS_DATE);
    lv_textarea_set_max_length(ta_date, SCR_SETTINGS_TA_MAX_LENGHT_DATE);

    lv_textarea_set_one_line(ta_time_zone_offset, true);
    lv_textarea_set_placeholder_text(ta_time_zone_offset, SCR_SETTINGS_TA_TIME_ZONE_OFFSET_PLACEHOLDER);
    lv_textarea_set_accepted_chars(ta_time_zone_offset, SCR_SETTINGS_TA_ACCEPTED_CHARS_HOUR);
    lv_textarea_set_max_length(ta_time_zone_offset, SCR_SETTINGS_TA_MAX_LENGHT_HOUR);

    lv_dropdown_set_options_static(dd_calc_method, calc_method_options);
    lv_dropdown_set_dir(dd_calc_method, LV_DIR_LEFT);
    lv_dropdown_set_symbol(dd_calc_method, LV_SYMBOL_LEFT);

    lv_dropdown_set_options_static(dd_juristic, juristic_method_options);
    lv_dropdown_set_dir(dd_juristic, LV_DIR_LEFT);
    lv_dropdown_set_symbol(dd_juristic, LV_SYMBOL_LEFT);

    lv_dropdown_set_options_static(dd_hl_method, hl_method_options);
    lv_dropdown_set_dir(dd_hl_method, LV_DIR_LEFT);
    lv_dropdown_set_symbol(dd_hl_method, LV_SYMBOL_LEFT);

    lv_dropdown_set_options_static(dd_md_method, md_method_options);
    lv_dropdown_set_dir(dd_md_method, LV_DIR_LEFT);
    lv_dropdown_set_symbol(dd_md_method, LV_SYMBOL_LEFT);

    lv_obj_add_event_cb(ta_angle_imsak, scr_settings_ta_float_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_angle_fajr, scr_settings_ta_float_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_angle_maghrib, scr_settings_ta_float_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_angle_isha, scr_settings_ta_float_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_imsak, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_fajr, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_sunrise, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_duhur, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_asr, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_sunset, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_maghrib, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_isha, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_offset_midnight, scr_settings_ta_decimal_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_location_latitude, scr_settings_ta_float_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_location_longitude, scr_settings_ta_float_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_location_altitude, scr_settings_ta_float_event, LV_EVENT_ALL, scr_settings_keyboard);
    lv_obj_add_event_cb(ta_date, scr_settings_ta_date_event, LV_EVENT_ALL, scr_settings_calendar);
    lv_obj_add_event_cb(ta_time_zone_offset, scr_settings_ta_timezone_event, LV_EVENT_ALL, scr_settings_keyboard);
    
    lv_obj_add_event_cb(dd_calc_method, scr_settings_dd_event, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(dd_juristic, scr_settings_dd_event, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(dd_hl_method, scr_settings_dd_event, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(dd_md_method, scr_settings_dd_event, LV_EVENT_ALL, NULL);

    
    lv_keyboard_set_mode(scr_settings_keyboard, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_align(scr_settings_keyboard, LV_ALIGN_TOP_LEFT);
    lv_obj_set_x(scr_settings_keyboard, lv_pct(5));
    lv_obj_set_y(scr_settings_keyboard, lv_pct(20));
    lv_obj_add_flag(scr_settings_keyboard, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(scr_settings_keyboard, scr_settings_kb_event, LV_EVENT_ALL, NULL);

    lv_obj_set_align(scr_settings_calendar, LV_ALIGN_TOP_LEFT);
    lv_obj_set_x(scr_settings_calendar, lv_pct(5));
    lv_obj_set_y(scr_settings_calendar, lv_pct(20));
    lv_calendar_header_dropdown_create(scr_settings_calendar);
    lv_calendar_header_dropdown_set_year_list(scr_settings_calendar, scr_settings_calendar_years);
    lv_calendar_set_month_shown(scr_settings_calendar, 2025, 02);
    lv_obj_add_flag(scr_settings_calendar, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_event_cb(scr_settings_calendar, scr_settings_cl_event, LV_EVENT_ALL, ta_date);
}
















