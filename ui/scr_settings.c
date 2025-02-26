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

// Settings Screen Styles
lv_style_t style_scr_settings = { 0 };
lv_style_t style_obj_scr_settings_header = { 0 };
lv_style_t style_btn_scr_settings_back = { 0 };
lv_style_t style_lbl_scr_settings_back = { 0 };
lv_style_t style_lbl_scr_settings_header = { 0 };
lv_style_t style_obj_scr_settings_items = { 0 };

void scr_settings_create_objects(void)
{
    scr_settings = lv_obj_create(NULL);
    obj_scr_settings_header = lv_obj_create(scr_settings);
    btn_scr_settings_back = lv_button_create(obj_scr_settings_header);
    lbl_scr_settings_back = lv_label_create(btn_scr_settings_back);
    lbl_scr_settings_header = lv_label_create(obj_scr_settings_header);
    obj_scr_settings_items = lv_obj_create(scr_settings);
}

void scr_settings_style_init(void)
{
    lv_style_init(&style_scr_settings);
    lv_style_init(&style_obj_scr_settings_header);
    lv_style_init(&style_btn_scr_settings_back);
    lv_style_init(&style_lbl_scr_settings_back);
    lv_style_init(&style_lbl_scr_settings_header);
    lv_style_init(&style_obj_scr_settings_items);

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
}

void scr_settings_style_add(void)
{
    lv_obj_add_style(scr_settings, &style_scr_settings, LV_PART_MAIN);
    lv_obj_add_style(obj_scr_settings_header, &style_obj_scr_settings_header, LV_PART_MAIN);
    lv_obj_add_style(btn_scr_settings_back, &style_btn_scr_settings_back, LV_PART_MAIN);
    lv_obj_add_style(lbl_scr_settings_back, &style_lbl_scr_settings_back, LV_PART_MAIN);
    lv_obj_add_style(lbl_scr_settings_header, &style_lbl_scr_settings_header, LV_PART_MAIN);
    lv_obj_add_style(obj_scr_settings_items, &style_obj_scr_settings_items, LV_PART_MAIN);
}

void scr_settings_init_objects(void)
{
    
    lv_label_set_text(lbl_scr_settings_back, LV_SYMBOL_LEFT);
    lv_obj_add_event_cb(btn_scr_settings_back, scr_settings_btn_back_event, LV_EVENT_CLICKED, NULL);

    lv_label_set_text(lbl_scr_settings_header, "Prayer Times Settings");

}
