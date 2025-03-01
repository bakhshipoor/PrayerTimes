#ifndef _PRAYER_TIMES_UI_UPDATE_H
#define _PRAYER_TIMES_UI_UPDATE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "prayertimes/prayertimes.h"


#define TEXT_BUFFER_SIZE        100

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


#ifdef __cplusplus
}
#endif

#endif