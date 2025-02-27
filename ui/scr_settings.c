#include "scr_settings.h"
#include "prayer_times_ui_events.h"

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

// Settings Screen Styles
lv_style_t style_scr_settings = { 0 };
lv_style_t style_obj_scr_settings_header = { 0 };
lv_style_t style_btn_scr_settings_back = { 0 };
lv_style_t style_lbl_scr_settings_back = { 0 };
lv_style_t style_lbl_scr_settings_header = { 0 };
lv_style_t style_obj_scr_settings_items = { 0 };
lv_style_t style_obj_scr_settings_items_section = { 0 };
lv_style_t style_obj_scr_settings_items_header = { 0 };

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

    lbl_items_calc_method_header = lv_label_create(obj_items_calc_method);;
    lbl_items_angles_header = lv_label_create(obj_items_angles);;
    lbl_items_offsets_header = lv_label_create(obj_items_offsets);;
    lbl_items_juristic_header = lv_label_create(obj_items_juristic);;
    lbl_items_hl_method_header = lv_label_create(obj_items_hl_method);;
    lbl_items_md_method_header = lv_label_create(obj_items_md_method);;
    lbl_items_location_header = lv_label_create(obj_items_location);;
    lbl_items_date_header = lv_label_create(obj_items_date);;
    lbl_items_time_zone_offset_header = lv_label_create(obj_items_time_zone_offset);;
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
    lv_style_init(&style_obj_scr_settings_items_header);

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

    lv_style_set_size(&style_obj_scr_settings_items_section, lv_pct(100), 100);//LV_SIZE_CONTENT
    lv_style_set_pad_all(&style_obj_scr_settings_items_section, 0);
    lv_style_set_border_color(&style_obj_scr_settings_items_section, lv_color_hex(SETTINGS_SCREEN_BG_COLOR));

    lv_style_set_size(&style_obj_scr_settings_items_header, lv_pct(100), 30);
    lv_style_set_bg_color(&style_obj_scr_settings_items_header, lv_color_hex(SETTINGS_ITEMS_HEADER_BG_COLOR));
    lv_style_set_bg_opa(&style_obj_scr_settings_items_header, LV_OPA_100);
    lv_style_set_text_font(&style_obj_scr_settings_items_header, &lv_font_montserrat_18);
    lv_style_set_pad_all(&style_obj_scr_settings_items_header, 6);
    lv_style_set_text_align(&style_obj_scr_settings_items_header, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_color(&style_obj_scr_settings_items_header, lv_color_hex(SETTINGS_ITEMS_HEADER_TEXT_COLOR));
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

    lv_obj_add_style(lbl_items_calc_method_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_angles_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_offsets_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_juristic_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_hl_method_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_md_method_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_location_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_date_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
    lv_obj_add_style(lbl_items_time_zone_offset_header, &style_obj_scr_settings_items_header, LV_PART_MAIN);
}

void scr_settings_init_objects(void)
{
    
    lv_label_set_text(lbl_scr_settings_back, LV_SYMBOL_LEFT);
    lv_obj_add_event_cb(btn_scr_settings_back, scr_settings_btn_back_event, LV_EVENT_CLICKED, NULL);

    lv_label_set_text_static(lbl_scr_settings_header, "Prayer Times Settings");
    
    lv_label_set_text_static(lbl_items_calc_method_header, "Calculation Method");
    lv_label_set_text_static(lbl_items_angles_header, "Angles");
    lv_label_set_text_static(lbl_items_offsets_header, "Offsets");
    lv_label_set_text_static(lbl_items_juristic_header, "Juristic Metod");
    lv_label_set_text_static(lbl_items_hl_method_header, "Higher Latatiude Method");
    lv_label_set_text_static(lbl_items_md_method_header, "Midnight Method");
    lv_label_set_text_static(lbl_items_location_header, "Your Location & City");
    lv_label_set_text_static(lbl_items_date_header, "Date");
    lv_label_set_text_static(lbl_items_time_zone_offset_header, "Time Zone Offset");
}
