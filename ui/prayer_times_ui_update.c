#include "scr_main.h"
#include "scr_settings.h"
#include "prayer_times_ui_update.h"
#include "prayer_times_ui_texts.h"
#include "prayertimes/prayertimes.h"
#include "prayertimes/prayertimes_math.h"

char text_buf[TEXT_BUFFER_SIZE] = { 0 };

pt_islamic_time_t islamic_time = { 0 };

pt_calc_method_e calc_method = 0;
pt_angles_t angles = { 0 };
pt_offsets_t offsets = { 0 };
pt_juristic_e jurictic_method = 0;
pt_hl_method_e hl_method = 0;
pt_midnight_method_e md_method = 0;
pt_location_t location = { 0 };
pt_date_t date = { 0 };
double tz_offset = 0.0;
pt_time_t time_zone_offset = { 0 };

void pt_ui_update_initial(void)
{
    prayertimes_init();
    pt_ui_update_main_screen();
    pt_ui_initial_settings_screen();
}

void pt_ui_update_main_screen(void)
{
    pt_get_islamic_times(&islamic_time);
    date = pt_get_date();

    lv_label_set_text_fmt(lbl_information, SCR_MAIN_LBL_HEADER_TITLE_FORMAT, date.year, date.month, date.day);
    lv_label_set_text_fmt(lbl_times_imsak_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.imsak.hour, islamic_time.imsak.minute, islamic_time.imsak.second);
    lv_label_set_text_fmt(lbl_times_fajr_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.fajr.hour, islamic_time.fajr.minute, islamic_time.fajr.second);
    lv_label_set_text_fmt(lbl_times_sunrise_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.sunrise.hour, islamic_time.sunrise.minute, islamic_time.sunrise.second);
    lv_label_set_text_fmt(lbl_times_midday_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.midday.hour, islamic_time.midday.minute, islamic_time.midday.second);
    lv_label_set_text_fmt(lbl_times_duhur_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.dhuhr.hour, islamic_time.dhuhr.minute, islamic_time.dhuhr.second);
    lv_label_set_text_fmt(lbl_times_asr_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.asr.hour, islamic_time.asr.minute, islamic_time.asr.second);
    lv_label_set_text_fmt(lbl_times_sunset_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.sunset.hour, islamic_time.sunset.minute, islamic_time.sunset.second);
    lv_label_set_text_fmt(lbl_times_maghrib_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.maghrib.hour, islamic_time.maghrib.minute, islamic_time.maghrib.second);
    lv_label_set_text_fmt(lbl_times_isha_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.isha.hour, islamic_time.isha.minute, islamic_time.isha.second);
    lv_label_set_text_fmt(lbl_times_midnight_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.midnight.hour, islamic_time.midnight.minute, islamic_time.midnight.second);
    lv_label_set_text_fmt(lbl_times_day_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.day.hour, islamic_time.day.minute, islamic_time.day.second);
    lv_label_set_text_fmt(lbl_times_night_hour, SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT, islamic_time.night.hour, islamic_time.night.minute, islamic_time.night.second);
}

void pt_ui_initial_settings_screen(void)
{
    pt_ui_update_setting_calc_method();
    pt_ui_update_setting_angles();
    pt_ui_update_setting_offsets();
    pt_ui_update_setting_jurictic_method();
    pt_ui_update_setting_hl_method();
    pt_ui_update_setting_md_method();
    pt_ui_update_setting_location();
    pt_ui_update_setting_date();
    pt_ui_update_setting_time_zone();
}

void pt_ui_update_setting_calc_method(void)
{
    calc_method = pt_get_calc_method();

    lv_dropdown_set_selected(dd_calc_method, calc_method, LV_ANIM_OFF);
}

void pt_ui_update_setting_angles(void)
{
    angles = pt_get_angles();

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_FLOAT_TEXT_FORMAT, angles.imsak >= 0 ? '+' : '-', angles.imsak);
    lv_textarea_set_text(ta_angle_imsak, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_FLOAT_TEXT_FORMAT, angles.fajr >= 0 ? '+' : '-', angles.fajr);
    lv_textarea_set_text(ta_angle_fajr, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_FLOAT_TEXT_FORMAT, angles.maghrib >= 0 ? '+' : '-', angles.maghrib);
    lv_textarea_set_text(ta_angle_maghrib, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_FLOAT_TEXT_FORMAT, angles.isha >= 0 ? '+' : '-', angles.isha);
    lv_textarea_set_text(ta_angle_isha, text_buf);
}

void pt_ui_update_setting_offsets(void)
{
    offsets = pt_get_offsets();

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.imsak >= 0 ? '+' : '-', offsets.imsak);
    lv_textarea_set_text(ta_offset_imsak, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.fajr >= 0 ? '+' : '-', offsets.fajr);
    lv_textarea_set_text(ta_offset_fajr, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.sunrise >= 0 ? '+' : '-', offsets.sunrise);
    lv_textarea_set_text(ta_offset_sunrise, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.duhur >= 0 ? '+' : '-', offsets.duhur);
    lv_textarea_set_text(ta_offset_duhur, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.asr >= 0 ? '+' : '-', offsets.asr);
    lv_textarea_set_text(ta_offset_asr, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.sunset >= 0 ? '+' : '-', offsets.sunset);
    lv_textarea_set_text(ta_offset_sunset, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.maghrib >= 0 ? '+' : '-', offsets.maghrib);
    lv_textarea_set_text(ta_offset_maghrib, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.isha >= 0 ? '+' : '-', offsets.isha);
    lv_textarea_set_text(ta_offset_isha, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, offsets.midnight >= 0 ? '+' : '-', offsets.midnight);
    lv_textarea_set_text(ta_offset_midnight, text_buf);
}

void pt_ui_update_setting_jurictic_method(void)
{
    jurictic_method = pt_get_juristic_method();

    lv_dropdown_set_selected(dd_juristic, jurictic_method, LV_ANIM_OFF);
}

void pt_ui_update_setting_hl_method(void)
{
    hl_method = pt_get_hilat_method();

    lv_dropdown_set_selected(dd_hl_method, hl_method, LV_ANIM_OFF);
}

void pt_ui_update_setting_md_method(void)
{
    md_method = pt_get_midnight_method();

    lv_dropdown_set_selected(dd_md_method, md_method, LV_ANIM_OFF);
}

void pt_ui_update_setting_location(void)
{
    location = pt_get_location();

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_FLOAT_TEXT_FORMAT, location.latitude >= 0 ? '+' : '-', location.latitude);
    lv_textarea_set_text(ta_location_latitude, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_FLOAT_TEXT_FORMAT, location.longitude >= 0 ? '+' : '-', location.longitude);
    lv_textarea_set_text(ta_location_longitude, text_buf);

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT, location.altitude >= 0 ? '+' : '-', location.altitude);
    lv_textarea_set_text(ta_location_altitude, text_buf);
}

void pt_ui_update_setting_date(void)
{
    date = pt_get_date();

    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_DATE_TEXT_FORMAT, date.year, date.month, date.day);
    lv_textarea_set_text(ta_date, text_buf);
}

void pt_ui_update_setting_time_zone(void)
{
    tz_offset = pt_get_timezone_offset();

    pt_double_to_time(tz_offset, &time_zone_offset);
    lv_snprintf(text_buf, TEXT_BUFFER_SIZE, SCR_SETTINGS_TA_TIME_ZONE_OFFSET_TEXT_FORMAT, tz_offset >= 0 ? '+' : '-', time_zone_offset.hour, time_zone_offset.minute);
    lv_textarea_set_text(ta_time_zone_offset, text_buf);
}

void pt_ui_update_prayer_times_angles(uint8_t variable, const char* value)
{
    double val = 0.0;
    angles = pt_get_angles();
    
    switch (variable)
    {
    case ANGLE_IMSAK:
        val = atof(value);
        if (val != angles.imsak)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            angles.imsak = val;
        }
        break;
    case ANGLE_FAJR:
        val = atof(value);
        if (val != angles.fajr)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            angles.fajr = val;
        }
        break;
    case ANGLE_MAGHRIB:
        val = atof(value);
        if (val != angles.maghrib)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            angles.maghrib = val;
        }
        break;
    case ANGLE_ISHA:
        val = atof(value);
        if (val != angles.isha)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            angles.isha = val;
        }
        break;
    default:
        break;
    }
    pt_set_angles(&angles);
    pt_ui_update_main_screen();
}

void pt_ui_update_prayer_times_offsets(uint8_t variable, const char* value)
{
    int16_t val = 0;
    offsets = pt_get_offsets();
    switch (variable)
    {
    case OFFSET_IMSAK:
        val = (int16_t)atoi(value);
        if (val != offsets.imsak)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.imsak = val;
        }
        break;
    case OFFSET_FAJR:
        val = (int16_t)atoi(value);
        if (val != offsets.fajr)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.fajr = val;
        }
        break;
    case OFFSET_SUNRISE:
        val = (int16_t)atoi(value);
        if (val != offsets.sunrise)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.sunrise = val;
        }
        break;
    case OFFSET_DUHUR:
        val = (int16_t)atoi(value);
        if (val != offsets.duhur)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.duhur = val;
        }
        break;
    case OFFSET_ASR:
        val = (int16_t)atoi(value);
        if (val != offsets.asr)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.asr = val;
        }
        break;
    case OFFSET_SUNSET:
        val = (int16_t)atoi(value);
        if (val != offsets.sunset)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.sunset = val;
        }
        break;
    case OFFSET_MAGHRIB:
        val = (int16_t)atoi(value);
        if (val != offsets.maghrib)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.maghrib = val;
        }
        break;
    case OFFSET_ISHA:
        val = (int16_t)atoi(value);
        if (val != offsets.isha)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.isha = val;
        }
        break;
    case OFFSET_MIDNIGHT:
        val = (int16_t)atoi(value);
        if (val != offsets.midnight)
        {
            lv_dropdown_set_selected(dd_calc_method, PT_CM_CUSTOM, LV_ANIM_OFF);
            offsets.midnight = val;
        }
        break;
    default:
        break;
    }
    pt_set_offsets(&offsets);
    pt_ui_update_main_screen();
}

void pt_ui_update_prayer_times_location(uint8_t variable, const char* value)
{
    location = pt_get_location();
    switch (variable)
    {
    case LOCATION_LATATIUDE:
        location.latitude = atof(value);
        break;
    case LOCATION_LONGITUDE:
        location.longitude = atof(value);
        break;
    case LOCATION_ALTITUDE:
        location.altitude = atof(value);
        break;
    default:
        break;
    }
    pt_set_location(&location);
    pt_ui_update_main_screen();
}

void pt_ui_update_prayer_times_date(const char* value)
{
    uint32_t y = 0, m = 0, d = 0;
    int len = sscanf(value, "%d.%d.%d", &y, &m, &d);
    date.year = (uint16_t)y;
    date.month = (uint16_t)m;
    date.day = (uint16_t)d;
    pt_set_date(&date);
    pt_ui_update_main_screen();
}

void pt_ui_update_prayer_times_time_zone(const char* value)
{
    uint32_t h = 0, m = 0;
    char sign = 0;
    int len = sscanf(value, "%c%d:%d", &sign, &h, &m);
    tz_offset = pt_time_to_double((int16_t)h, (int16_t)m);
    if (sign == '-')
    {
        tz_offset *= -1.0;
    }
    pt_set_timezone_offset(tz_offset);
    pt_ui_update_main_screen();
}