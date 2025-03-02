#ifndef _PRAYER_TIMES_UI_UPDATE_H
#define _PRAYER_TIMES_UI_UPDATE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "prayertimes/prayertimes.h"


#define TEXT_BUFFER_SIZE                100ui8

#define ANGLE_IMSAK                     0ui8
#define ANGLE_FAJR                      1ui8
#define ANGLE_MAGHRIB                   2ui8
#define ANGLE_ISHA                      3ui8

#define OFFSET_IMSAK                    0ui8
#define OFFSET_FAJR                     1ui8
#define OFFSET_SUNRISE                  2ui8
#define OFFSET_DUHUR                    3ui8
#define OFFSET_ASR                      4ui8
#define OFFSET_SUNSET                   5ui8
#define OFFSET_MAGHRIB                  6ui8
#define OFFSET_ISHA                     7ui8
#define OFFSET_MIDNIGHT                 8ui8

#define LOCATION_LATATIUDE              0ui8
#define LOCATION_LONGITUDE              1ui8
#define LOCATION_ALTITUDE               2ui8

    extern char text_buf[TEXT_BUFFER_SIZE];

    extern pt_calc_method_e calc_method;
    extern pt_angles_t angles;
    extern pt_offsets_t offsets;
    extern pt_juristic_e jurictic_method;
    extern pt_hl_method_e hl_method;
    extern pt_midnight_method_e md_method;
    extern pt_location_t location;
    extern pt_date_t date;
    extern double tz_offset;
    extern pt_time_t time_zone_offset;

    extern pt_islamic_time_t islamic_time;

    void pt_ui_update_initial(void);
    void pt_ui_update_main_screen(void);
    void pt_ui_initial_settings_screen(void);

    void pt_ui_update_setting_calc_method(void);
    void pt_ui_update_setting_angles(void);
    void pt_ui_update_setting_offsets(void);
    void pt_ui_update_setting_jurictic_method(void);
    void pt_ui_update_setting_hl_method(void);
    void pt_ui_update_setting_md_method(void);
    void pt_ui_update_setting_location(void);
    void pt_ui_update_setting_date(void);
    void pt_ui_update_setting_time_zone(void);
    void pt_ui_update_prayer_times_angles(uint8_t varible, char* value);
    void pt_ui_update_prayer_times_offsets(uint8_t variable, char* value);
    void pt_ui_update_prayer_times_location(uint8_t variable, char* value);
    void pt_ui_update_prayer_times_date(char* value);
    void pt_ui_update_prayer_times_time_zone(char* value);

#ifdef __cplusplus
}
#endif

#endif