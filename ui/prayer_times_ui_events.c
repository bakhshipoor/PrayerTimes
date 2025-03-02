#include <stdio.h>
#include "prayer_times_ui_events.h"
#include "scr_main.h"
#include "scr_settings.h"
#include "prayer_times_ui_texts.h"
#include "prayer_times_ui_update.h"

char* ta_last_txt = NULL;
uint32_t ta_last_txt_len = 0;
uint32_t ta_last_cur_pos = 0;
char* ta_last_inserted_char = NULL;
bool ta_insert_status = 0;

static tz_offset_state_t tz_state;

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

void scr_settings_ta_float_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* ta = lv_event_get_target(e);
    lv_obj_t* kb = lv_event_get_user_data(e);
    uint32_t cur = lv_textarea_get_cursor_pos(ta);
    const char* ta_txt = lv_textarea_get_text(ta);
    uint32_t len = strlen(ta_txt);
    if (code == LV_EVENT_FOCUSED) 
    {
        if (lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD) 
        {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_add_flag(scr_settings_calendar, LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_scroll_to_view_recursive(ta, LV_ANIM_ON);
            lv_indev_wait_release(lv_event_get_param(e));
        }
    }
    else if (code == LV_EVENT_DEFOCUSED || code == LV_EVENT_READY || code == LV_EVENT_CANCEL)
    {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_indev_reset(NULL, ta);
        if (len < 2 && (ta_txt[0] == '-' || ta_txt[0] == '+'))
        {
            lv_textarea_set_text(ta, SCR_SETTINGS_TA_FLOAT_TEXT);
        }
        else if (len == 0)
        {
            lv_textarea_set_text(ta, SCR_SETTINGS_TA_FLOAT_TEXT);
        }

        if (ta == ta_angle_imsak)
        {
            pt_ui_update_prayer_times_angles(ANGLE_IMSAK, lv_textarea_get_text(ta));
        }
        else if (ta == ta_angle_fajr)
        {
            pt_ui_update_prayer_times_angles(ANGLE_FAJR, lv_textarea_get_text(ta));
        }
        else if (ta == ta_angle_maghrib)
        {
            pt_ui_update_prayer_times_angles(ANGLE_MAGHRIB, lv_textarea_get_text(ta));
        }
        else if (ta == ta_angle_isha)
        {
            pt_ui_update_prayer_times_angles(ANGLE_ISHA, lv_textarea_get_text(ta));
        }
        else if (ta == ta_location_latitude)
        {
            pt_ui_update_prayer_times_location(LOCATION_LATATIUDE, lv_textarea_get_text(ta));
        }
        else if (ta == ta_location_longitude)
        {
            pt_ui_update_prayer_times_location(LOCATION_LONGITUDE, lv_textarea_get_text(ta));
        }
    }
    else if (code == LV_EVENT_INSERT)
    {
        ta_last_txt = lv_textarea_get_text(ta);
        ta_last_txt_len = strlen(ta_last_txt);;
        ta_last_cur_pos = lv_textarea_get_cursor_pos(ta);
        ta_last_inserted_char = lv_event_get_param(e);
        ta_insert_status = true;
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    {
        if (ta_insert_status)
        {
            if (ta_last_inserted_char[0] > 0x1F && ta_last_inserted_char[0] < 0x7F)
            {
                if (ta_txt[0] != '-' && ta_txt[0] != '+')
                {
                    lv_textarea_set_cursor_pos(ta, 0);
                    lv_textarea_add_char(ta, '+');
                    lv_textarea_set_cursor_pos(ta, cur + 1);
                }
            }
            if (ta_last_cur_pos > 0 && (ta_last_inserted_char[0] == '-' || ta_last_inserted_char[0] == '+'))
            {
                lv_textarea_delete_char(ta);
            }
            ta_insert_status = false;
        }
    }
}

void scr_settings_ta_decimal_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* ta = lv_event_get_target(e);
    lv_obj_t* kb = lv_event_get_user_data(e);
    uint32_t cur = lv_textarea_get_cursor_pos(ta);
    const char* ta_txt = lv_textarea_get_text(ta);
    uint32_t len = strlen(ta_txt);
    if (code == LV_EVENT_FOCUSED)
    {
        if (lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD)
        {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_add_flag(scr_settings_calendar, LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_scroll_to_view_recursive(ta, LV_ANIM_ON);
            lv_indev_wait_release(lv_event_get_param(e));
        }
    }
    else if (code == LV_EVENT_DEFOCUSED || code == LV_EVENT_READY || code == LV_EVENT_CANCEL)
    {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_indev_reset(NULL, ta);
        if (len < 2 && (ta_txt[0] == '-' || ta_txt[0] == '+'))
        {
            lv_textarea_set_text(ta, SCR_SETTINGS_TA_DECIMAL_TEXT);
        }
        else if (len == 0)
        {
            lv_textarea_set_text(ta, SCR_SETTINGS_TA_DECIMAL_TEXT);
        }

        if (ta == ta_offset_imsak)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_IMSAK, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_fajr)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_FAJR, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_sunrise)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_SUNRISE, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_duhur)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_DUHUR, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_asr)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_ASR, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_sunset)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_SUNSET, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_maghrib)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_MAGHRIB, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_isha)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_ISHA, lv_textarea_get_text(ta));
        }
        else if (ta == ta_offset_midnight)
        {
            pt_ui_update_prayer_times_offsets(OFFSET_MIDNIGHT, lv_textarea_get_text(ta));
        }
        else if (ta == ta_location_altitude)
        {
            pt_ui_update_prayer_times_location(LOCATION_ALTITUDE, lv_textarea_get_text(ta));
        }
    }
    else if (code == LV_EVENT_INSERT)
    {
        ta_last_txt = lv_textarea_get_text(ta);
        ta_last_txt_len = strlen(ta_last_txt);;
        ta_last_cur_pos = lv_textarea_get_cursor_pos(ta);
        ta_last_inserted_char = lv_event_get_param(e);
        ta_insert_status = true;
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    {
        if (ta_insert_status)
        {
            if (ta_last_inserted_char[0] > 0x1F && ta_last_inserted_char[0] < 0x7F)
            {
                if (ta_txt[0] != '-' && ta_txt[0] != '+')
                {
                    lv_textarea_set_cursor_pos(ta, 0);
                    lv_textarea_add_char(ta, '+');
                    lv_textarea_set_cursor_pos(ta, cur + 1);
                }
            }
            if (ta_last_cur_pos > 0 && (ta_last_inserted_char[0] == '-' || ta_last_inserted_char[0] == '+'))
            {
                lv_textarea_delete_char(ta);
            }
            ta_insert_status = false;
        }
    }
}

void scr_settings_ta_date_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* ta = lv_event_get_target(e);
    lv_obj_t* cl = lv_event_get_user_data(e);
    const char* ta_txt = lv_textarea_get_text(ta);
    uint32_t len = strlen(ta_txt);
    if (code == LV_EVENT_FOCUSED)
    {
        lv_obj_remove_flag(cl, LV_OBJ_FLAG_HIDDEN);
        if (len < 10)
        {
            lv_textarea_set_text(ta, SCR_SETTINGS_TA_DATE_TEXT);
        }
        uint16_t year = 0, month = 0, day = 0;
        get_date_ta_text(lv_textarea_get_text(ta), &year, &month, &day);
        lv_calendar_set_today_date(cl, year, month, day);
        lv_calendar_set_month_shown(cl, year, month);
        static lv_calendar_date_t highlighted_days[1];
        highlighted_days[0].year = year;
        highlighted_days[0].month = month;
        highlighted_days[0].day = day;
        lv_calendar_set_highlighted_dates(cl, highlighted_days, 1);
    }
    else if (code == LV_EVENT_DEFOCUSED || code == LV_EVENT_READY || code == LV_EVENT_CANCEL)
    {
        //lv_obj_add_flag(cl, LV_OBJ_FLAG_HIDDEN);
        if (len < 10)
        {
            lv_textarea_set_text(ta, SCR_SETTINGS_TA_DATE_TEXT);
        }
        pt_ui_update_prayer_times_date(lv_textarea_get_text(ta));
    }
    else if (code == LV_EVENT_KEY)
    {
        uint32_t key = lv_indev_get_key(lv_indev_active());
        if (key == LV_KEY_BACKSPACE || key == LV_KEY_DEL)
        {
            lv_textarea_set_text(ta, "");
        }
        else if (key > 0x1F && key < 0x7F)
        {
            lv_textarea_delete_char(ta);
        }
    }
}

void scr_settings_ta_timezone_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* ta = lv_event_get_target(e);
    lv_obj_t* kb = lv_event_get_user_data(e);
    uint32_t cur = lv_textarea_get_cursor_pos(ta);
    char* ta_txt = lv_textarea_get_text(ta);
    uint32_t len = strlen(ta_txt);
    if (code == LV_EVENT_FOCUSED)
    {
        if (lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD)
        {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_add_flag(scr_settings_calendar, LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
            lv_obj_scroll_to_view_recursive(ta, LV_ANIM_ON);
            lv_indev_wait_release(lv_event_get_param(e));
        }
    }
    else if (code == LV_EVENT_DEFOCUSED || code == LV_EVENT_READY || code == LV_EVENT_CANCEL)
    {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_indev_reset(NULL, ta);
        fix_time_format(ta);
        pt_ui_update_prayer_times_time_zone(lv_textarea_get_text(ta));
    }
    else if (code == LV_EVENT_INSERT)
    {
        ta_last_txt = lv_textarea_get_text(ta);
        ta_last_txt_len = strlen(ta_last_txt);;
        ta_last_cur_pos = lv_textarea_get_cursor_pos(ta);
        ta_last_inserted_char = lv_event_get_param(e);
        ta_insert_status = true;
    }
    else if (code == LV_EVENT_KEY)
    {
        if (lv_indev_get_key(lv_indev_active()) == 0x3A)
        {
            lv_textarea_delete_char(ta);
        }
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    {
        if (ta_insert_status)
        {
            ta_insert_status = false;
            if ((ta_last_inserted_char[0] > 0x2F && ta_last_inserted_char[0] < 0x3A))
            {
                int digit = ta_last_inserted_char[0] - 0x30;
                if ((ta_last_cur_pos == 0 && ta_last_txt_len > 0) && (ta_last_txt[0] == '-' || ta_last_txt[0] == '+'))
                {
                    lv_textarea_delete_char(ta);
                    return;
                }

                ta_txt = lv_textarea_get_text(ta);
                len = strlen(ta_txt);
                cur = lv_textarea_get_cursor_pos(ta);
                if (ta_last_cur_pos < 2)
                {
                    if (digit > 2)
                    {
                        lv_textarea_delete_char(ta);
                    }
                }
                else if (ta_last_cur_pos == 2)
                {
                    if (ta_txt[1] == '2')
                    {
                        if (digit > 4)
                        {
                            lv_textarea_delete_char(ta);
                        }
                    }
                }
                else if (ta_last_cur_pos == 3)
                {
                    if (digit > 5)
                    {
                        lv_textarea_delete_char(ta);
                    }
                }
                else if (ta_last_cur_pos == 4)
                {
                    if (digit > 5)
                    {
                        lv_textarea_delete_char(ta);
                    }
                }

                ta_txt = lv_textarea_get_text(ta);
                len = strlen(ta_txt);
                cur = lv_textarea_get_cursor_pos(ta);
                if (len > 5 && get_colon_pos(ta_txt) == -1)
                {
                    lv_textarea_delete_char(ta);
                }

                ta_txt = lv_textarea_get_text(ta);
                len = strlen(ta_txt);
                cur = lv_textarea_get_cursor_pos(ta);
                int colon_pos = get_colon_pos(ta_txt);
                if (colon_pos != -1)
                {
                    lv_textarea_set_cursor_pos(ta, colon_pos);
                    lv_textarea_delete_char_forward(ta);
                    lv_textarea_set_cursor_pos(ta, cur);
                }


                ta_txt = lv_textarea_get_text(ta);
                len = strlen(ta_txt);
                //cur = lv_textarea_get_cursor_pos(ta);
                if (len > 2 && get_colon_pos(ta_txt) == -1)
                {
                    lv_textarea_set_cursor_pos(ta, 3);
                    lv_textarea_add_char(ta, ':');
                    lv_textarea_set_cursor_pos(ta, cur + 1);
                }
                
                if (ta_txt[0] != '-' && ta_txt[0] != '+')
                {
                    lv_textarea_set_cursor_pos(ta, 0);
                    lv_textarea_add_char(ta, '+');
                    lv_textarea_set_cursor_pos(ta, cur + 1);
                }

                if (ta_last_inserted_char != NULL && ta_last_cur_pos > 0 && (ta_last_inserted_char[0] == '-' || ta_last_inserted_char[0] == '+'))
                {
                    lv_textarea_delete_char(ta);
                }
            }
        }
    }
}

void scr_settings_dd_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* dd = lv_event_get_target(e);
    int x = 0;
    if (code == LV_EVENT_VALUE_CHANGED)
    {
        if (dd == dd_calc_method)
        {
            pt_set_calc_method(lv_dropdown_get_selected(dd));
            pt_ui_update_setting_angles();
            pt_ui_update_setting_offsets();
            pt_ui_update_main_screen();
        }
        else if (dd == dd_juristic)
        {
            pt_set_juristic_method(lv_dropdown_get_selected(dd));
            pt_ui_update_main_screen();
        }
        else if (dd == dd_hl_method)
        {
            pt_set_hilat_method(lv_dropdown_get_selected(dd));
            pt_ui_update_main_screen();
        }
        else if (dd == dd_md_method)
        {
            pt_set_midnight_method(lv_dropdown_get_selected(dd));
            pt_ui_update_main_screen();
        }
    }
}

void scr_settings_kb_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_keyboard_t* kb = (lv_keyboard_t*)lv_event_get_target(e);
    if (code == LV_EVENT_PRESSED)
    {
        //uint32_t key_id = lv_keyboard_get_selected_button(kb);
        //const char* key = lv_keyboard_get_button_text(kb, key_id);
        //if (strcmp(key,LV_SYMBOL_OK)==0 || strcmp(key, LV_SYMBOL_KEYBOARD) == 0)
        //{
        //    lv_keyboard_set_textarea(kb, NULL);
        //    lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        //    
        //}
    }
}

void scr_settings_cl_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* ta = lv_event_get_user_data(e);
    lv_obj_t* obj = lv_event_get_current_target(e);
    if (code == LV_EVENT_VALUE_CHANGED) 
    {
        lv_calendar_date_t d;
        lv_calendar_get_pressed_date(obj, &d);
        char buf[32];
        lv_snprintf(buf, sizeof(buf), "%04d.%02d.%02d", d.year, d.month, d.day);
        lv_textarea_set_text(ta, buf);
        lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        pt_ui_update_prayer_times_date(lv_textarea_get_text(ta));
    }
}

void get_date_ta_text(const char* ta_txt, uint16_t* year, uint16_t* month, uint16_t* day)
{
    uint32_t y=0, m=0, d=0;
    int len = sscanf(ta_txt, "%d.%d.%d", &y, &m, &d);
    *year = y;
    *month = m;
    *day = d;
}

int get_colon_pos(const char* ta_txt)
{
    const char* pos = strchr(ta_txt, ':');
    return pos ? (pos - ta_txt) : -1;
}

bool validate_time_format(const char* text) 
{
    size_t len = strlen(text);
    if (len != 6) return false;

    if (text[0] != '+' && text[0] != '-') return false;

    int hours = (text[1] - '0') * 10 + (text[2] - '0');
    if (hours > SCR_SETTINGS_TA_MAX_HOURS) return false;

    if (text[3] != ':') return false;

    int minutes = (text[4] - '0') * 10 + (text[5] - '0');
    if (minutes > SCR_SETTINGS_TA_MAX_MINUTES) return false;

    return true;
}

void fix_time_format(lv_obj_t* ta) 
{
    const char* text = lv_textarea_get_text(ta);
    size_t len = strlen(text);

    if (len == 0) 
    {
        lv_textarea_set_text(ta, SCR_SETTINGS_TA_TIME_ZONE_OFFSET_TEXT);
        return;
    }

    char temp[7] = { 0 };
    strncpy(temp, text, sizeof(temp) - 1);

    if (temp[0] != '+' && temp[0] != '-') 
    {
        memmove(temp + 1, temp, strlen(temp) + 1);
        temp[0] = '+';
    }

    if (len >= 3 && temp[3] != ':') 
    {
        memmove(temp + 4, temp + 3, strlen(temp + 3) + 1);
        temp[3] = ':';
    }

    while (strlen(temp) < 6) 
    {
        strcat(temp, "0");
    }

    if (!validate_time_format(temp)) 
    {
        lv_textarea_set_text(ta, SCR_SETTINGS_TA_TIME_ZONE_OFFSET_TEXT);
    }
    else 
    {
        lv_textarea_set_text(ta, temp);
    }
}

