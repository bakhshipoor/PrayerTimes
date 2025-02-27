#include "scr_main.h"
#include "prayer_times_ui_events.h"

static const int32_t obj_times_row_dsc[] = { LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST };
static const int32_t obj_times_col_dsc[] = { LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST };

// Screens
lv_obj_t* scr_main = NULL;

// Main Screen Objects
lv_obj_t* obj_scr_main_header = NULL;
lv_obj_t* btn_settings = NULL;
lv_obj_t* lbl_settings = NULL;
lv_obj_t* lbl_information = NULL;
lv_obj_t* obj_times = NULL;
lv_obj_t* lbl_times_imsak_title = NULL;
lv_obj_t* lbl_times_fajr_title = NULL;
lv_obj_t* lbl_times_sunrise_title = NULL;
lv_obj_t* lbl_times_midday_title = NULL;
lv_obj_t* lbl_times_duhur_title = NULL;
lv_obj_t* lbl_times_asr_title = NULL;
lv_obj_t* lbl_times_sunset_title = NULL;
lv_obj_t* lbl_times_maghrib_title = NULL;
lv_obj_t* lbl_times_isha_title = NULL;
lv_obj_t* lbl_times_midnight_title = NULL;
lv_obj_t* lbl_times_day_title = NULL;
lv_obj_t* lbl_times_night_title = NULL;
lv_obj_t* lbl_times_imsak_hour = NULL;
lv_obj_t* lbl_times_fajr_hour = NULL;
lv_obj_t* lbl_times_sunrise_hour = NULL;
lv_obj_t* lbl_times_midday_hour = NULL;
lv_obj_t* lbl_times_duhur_hour = NULL;
lv_obj_t* lbl_times_asr_hour = NULL;
lv_obj_t* lbl_times_sunset_hour = NULL;
lv_obj_t* lbl_times_maghrib_hour = NULL;
lv_obj_t* lbl_times_isha_hour = NULL;
lv_obj_t* lbl_times_midnight_hour = NULL;
lv_obj_t* lbl_times_day_hour = NULL;
lv_obj_t* lbl_times_night_hour = NULL;

// Main Screen Styles
lv_style_t style_scr_main = { 0 };
lv_style_t style_obj_header = { 0 };
lv_style_t style_btn_settings = { 0 };
lv_style_t style_lbl_settings = { 0 };
lv_style_t style_lbl_information = { 0 };
lv_style_t style_obj_times = { 0 };
lv_style_t style_lbl_times_title = { 0 };
lv_style_t style_lbl_times_hour = { 0 };


void scr_main_create_objects(void)
{
    scr_main = lv_obj_create(NULL);
    obj_scr_main_header = lv_obj_create(scr_main);
    btn_settings = lv_button_create(obj_scr_main_header);
    lbl_settings = lv_label_create(btn_settings);
    lbl_information = lv_label_create(obj_scr_main_header);
    obj_times = lv_obj_create(scr_main);
    lbl_times_imsak_title = lv_label_create(obj_times);
    lbl_times_fajr_title = lv_label_create(obj_times);
    lbl_times_sunrise_title = lv_label_create(obj_times);
    lbl_times_midday_title = lv_label_create(obj_times);
    lbl_times_duhur_title = lv_label_create(obj_times);
    lbl_times_asr_title = lv_label_create(obj_times);
    lbl_times_sunset_title = lv_label_create(obj_times);
    lbl_times_maghrib_title = lv_label_create(obj_times);
    lbl_times_isha_title = lv_label_create(obj_times);
    lbl_times_midnight_title = lv_label_create(obj_times);
    lbl_times_day_title = lv_label_create(obj_times);
    lbl_times_night_title = lv_label_create(obj_times);
    lbl_times_imsak_hour = lv_label_create(obj_times);
    lbl_times_fajr_hour = lv_label_create(obj_times);
    lbl_times_sunrise_hour = lv_label_create(obj_times);
    lbl_times_midday_hour = lv_label_create(obj_times);
    lbl_times_duhur_hour = lv_label_create(obj_times);
    lbl_times_asr_hour = lv_label_create(obj_times);
    lbl_times_sunset_hour = lv_label_create(obj_times);
    lbl_times_maghrib_hour = lv_label_create(obj_times);
    lbl_times_isha_hour = lv_label_create(obj_times);
    lbl_times_midnight_hour = lv_label_create(obj_times);
    lbl_times_day_hour = lv_label_create(obj_times);
    lbl_times_night_hour = lv_label_create(obj_times);
}

void scr_main_style_init(void)
{
    lv_style_init(&style_scr_main);
    lv_style_init(&style_obj_header);
    lv_style_init(&style_btn_settings);
    lv_style_init(&style_lbl_settings);
    lv_style_init(&style_lbl_information);
    lv_style_init(&style_obj_times);
    lv_style_init(&style_lbl_times_title);
    lv_style_init(&style_lbl_times_hour);

    lv_style_set_bg_color(&style_scr_main, lv_color_hex(MAIN_SCREEN_BG_COLOR));
    lv_style_set_text_color(&style_scr_main, lv_color_hex(0x000000));

    lv_style_set_size(&style_obj_header, lv_pct(100), lv_pct(30));
    lv_style_set_bg_color(&style_obj_header, lv_color_hex(MAIN_HEADER_BG_COLOR));
    lv_style_set_border_width(&style_obj_header, 0);
    lv_style_set_radius(&style_obj_header, 0);
    lv_style_set_align(&style_obj_header, LV_ALIGN_TOP_MID);
    lv_style_set_pad_all(&style_obj_header, 0);

    lv_style_set_y(&style_btn_settings, lv_pct(10));
    lv_style_set_x(&style_btn_settings, lv_pct(5));
    lv_style_set_width(&style_btn_settings, lv_pct(10));
    lv_style_set_height(&style_btn_settings, lv_pct(46));
    lv_style_set_pad_all(&style_btn_settings, 0);
    lv_style_set_pad_top(&style_btn_settings, 4);
    lv_style_set_text_align(&style_btn_settings, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_opa(&style_btn_settings, 0);
    lv_style_set_shadow_offset_y(&style_btn_settings, 0);
    lv_style_set_shadow_opa(&style_btn_settings, 0);

    lv_style_set_size(&style_lbl_settings, lv_pct(100), lv_pct(100));
    lv_style_set_text_font(&style_lbl_settings, &lv_font_montserrat_28);
    lv_style_set_align(&style_lbl_settings, LV_ALIGN_CENTER);
    lv_style_set_text_align(&style_lbl_settings, LV_TEXT_ALIGN_CENTER);

    lv_style_set_y(&style_lbl_information, lv_pct(10));
    lv_style_set_x(&style_lbl_information, lv_pct(17));
    lv_style_set_width(&style_lbl_information, lv_pct(75));
    lv_style_set_height(&style_lbl_information, lv_pct(46));
    lv_style_set_text_align(&style_lbl_information, LV_TEXT_ALIGN_LEFT);
    lv_style_set_pad_top(&style_lbl_information, 10);
    lv_style_set_text_font(&style_lbl_information, &lv_font_montserrat_18);
    lv_style_set_text_color(&style_lbl_information, lv_color_hex(MAIN_TIMES_BG_COLOR));

    lv_style_set_size(&style_obj_times, lv_pct(90), lv_pct(75));
    lv_style_set_bg_color(&style_obj_times, lv_color_hex(MAIN_TIMES_BG_COLOR));
    lv_style_set_border_width(&style_obj_times, 0);
    lv_style_set_radius(&style_obj_times, 10);
    lv_style_set_align(&style_obj_times, LV_ALIGN_TOP_MID);
    lv_style_set_y(&style_obj_times, lv_pct(20));
    lv_style_set_pad_row(&style_obj_times, 5);
    lv_style_set_pad_column(&style_obj_times, 5);
    lv_style_set_shadow_color(&style_obj_times, lv_color_hex(0x000000));
    lv_style_set_shadow_offset_x(&style_obj_times, 0);
    lv_style_set_shadow_offset_y(&style_obj_times, 0);
    lv_style_set_shadow_width(&style_obj_times, 10);
    lv_style_set_shadow_spread(&style_obj_times, 2);
    lv_style_set_shadow_opa(&style_obj_times, LV_OPA_20);

    lv_style_set_size(&style_lbl_times_title, lv_pct(100), lv_pct(100));
    lv_style_set_text_align(&style_lbl_times_title, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_color(&style_lbl_times_title, lv_color_hex(MAIN_LBL_TIMES_TITLE_BG_COLOR));
    lv_style_set_bg_opa(&style_lbl_times_title, LV_OPA_100);
    lv_style_set_radius(&style_lbl_times_title, 5);
    lv_style_set_pad_top(&style_lbl_times_title, 3);
    lv_style_set_text_font(&style_lbl_times_title, &lv_font_montserrat_14);
    lv_style_set_border_color(&style_lbl_times_title, lv_color_hex(MAIN_SCREEN_BG_COLOR));
    lv_style_set_border_width(&style_lbl_times_title, 2);
    lv_style_set_border_side(&style_lbl_times_title, LV_BORDER_SIDE_FULL);

    lv_style_set_size(&style_lbl_times_hour, lv_pct(100), lv_pct(100));
    lv_style_set_text_align(&style_lbl_times_hour, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_color(&style_lbl_times_hour, lv_color_hex(MAIN_LBL_TIMES_HOUR_BG_COLOR));
    lv_style_set_bg_opa(&style_lbl_times_hour, LV_OPA_100);
    lv_style_set_radius(&style_lbl_times_hour, 5);
    lv_style_set_pad_top(&style_lbl_times_hour, 5);
    lv_style_set_text_font(&style_lbl_times_hour, &lv_font_montserrat_12);
    //lv_style_set_bg_opa(&style_lbl_times_hour, LV_OPA_50);
}

void scr_main_style_add(void)
{
    lv_obj_add_style(scr_main, &style_scr_main, LV_PART_MAIN);
    lv_obj_add_style(obj_scr_main_header, &style_obj_header, LV_PART_MAIN);
    lv_obj_add_style(btn_settings, &style_btn_settings, LV_PART_MAIN);
    lv_obj_add_style(lbl_settings, &style_lbl_settings, LV_PART_MAIN);
    lv_obj_add_style(lbl_information, &style_lbl_information, LV_PART_MAIN);
    lv_obj_add_style(obj_times, &style_obj_times, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_imsak_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_fajr_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_sunrise_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_midday_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_duhur_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_asr_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_sunset_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_maghrib_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_isha_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_midnight_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_day_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_night_title, &style_lbl_times_title, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_imsak_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_fajr_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_sunrise_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_midday_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_duhur_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_asr_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_sunset_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_maghrib_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_isha_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_midnight_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_day_hour, &style_lbl_times_hour, LV_PART_MAIN);
    lv_obj_add_style(lbl_times_night_hour, &style_lbl_times_hour, LV_PART_MAIN);
}

void scr_main_init_objects(void)
{
    lv_label_set_text(lbl_settings, LV_SYMBOL_SETTINGS);
    lv_obj_add_event_cb(btn_settings, scr_main_btn_settings_event, LV_EVENT_CLICKED, NULL);

    lv_label_set_text_static(lbl_information, "Prayer Times 2025-02-26 Tehran");

    //lv_obj_set_scrollbar_mode(obj_times, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_grid_dsc_array(obj_times, obj_times_col_dsc, obj_times_row_dsc);

    lv_label_set_text_static(lbl_times_imsak_title, "IMSAK");
    lv_obj_set_grid_cell(lbl_times_imsak_title, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    lv_label_set_text_static(lbl_times_fajr_title, "FAJR");
    lv_obj_set_grid_cell(lbl_times_fajr_title, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    lv_label_set_text_static(lbl_times_sunrise_title, "SUNRISE");
    lv_obj_set_grid_cell(lbl_times_sunrise_title, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    lv_label_set_text_static(lbl_times_midday_title, "MIDDAY");
    lv_obj_set_grid_cell(lbl_times_midday_title, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    lv_label_set_text_static(lbl_times_duhur_title, "DUHUR");
    lv_obj_set_grid_cell(lbl_times_duhur_title, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    lv_label_set_text_static(lbl_times_asr_title, "ASR");
    lv_obj_set_grid_cell(lbl_times_asr_title, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    lv_label_set_text_static(lbl_times_sunset_title, "SUNSET");
    lv_obj_set_grid_cell(lbl_times_sunset_title, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    lv_label_set_text_static(lbl_times_maghrib_title, "MAGHRIB");
    lv_obj_set_grid_cell(lbl_times_maghrib_title, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    lv_label_set_text_static(lbl_times_isha_title, "ISHA");
    lv_obj_set_grid_cell(lbl_times_isha_title, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 4, 1);

    lv_label_set_text_static(lbl_times_midnight_title, "MIDNIGHT");
    lv_obj_set_grid_cell(lbl_times_midnight_title, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 4, 1);

    lv_label_set_text_static(lbl_times_day_title, "DAY");
    lv_obj_set_grid_cell(lbl_times_day_title, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 4, 1);

    lv_label_set_text_static(lbl_times_night_title, "NIGHT");
    lv_obj_set_grid_cell(lbl_times_night_title, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_STRETCH, 4, 1);



    lv_label_set_text(lbl_times_imsak_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_imsak_hour, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    lv_label_set_text(lbl_times_fajr_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_fajr_hour, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    lv_label_set_text(lbl_times_sunrise_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_sunrise_hour, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    lv_label_set_text(lbl_times_midday_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_midday_hour, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    lv_label_set_text(lbl_times_duhur_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_duhur_hour, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 3, 1);

    lv_label_set_text(lbl_times_asr_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_asr_hour, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 3, 1);

    lv_label_set_text(lbl_times_sunset_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_sunset_hour, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 3, 1);

    lv_label_set_text(lbl_times_maghrib_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_maghrib_hour, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_STRETCH, 3, 1);

    lv_label_set_text(lbl_times_isha_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_isha_hour, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 5, 1);

    lv_label_set_text(lbl_times_midnight_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_midnight_hour, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 5, 1);

    lv_label_set_text(lbl_times_day_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_day_hour, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 5, 1);

    lv_label_set_text(lbl_times_night_hour, "00:00:00");
    lv_obj_set_grid_cell(lbl_times_night_hour, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_STRETCH, 5, 1);
}
