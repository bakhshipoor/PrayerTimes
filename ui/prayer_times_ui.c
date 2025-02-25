#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "lvgl\lvgl.h"
#include "LvglWindowsIconResource\LvglWindowsIconResource.h"
#include "prayertimes/prayertimes.h"
#include "prayer_times_ui.h"

static lv_obj_t* scr_Main;

static lv_style_t style_lbl_times = { 0 };

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{

    lv_init();

#if LV_TXT_ENC == LV_TXT_ENC_UTF8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    int32_t zoom_level = 100;
    bool allow_dpi_override = true;
    bool simulator_mode = true;
    lv_display_t* display = lv_windows_create_display(
        L"Time Zone",
        480,
        272,
        zoom_level,
        allow_dpi_override,
        simulator_mode);
    if (!display)
    {
        return -1;
    }

    HWND window_handle = lv_windows_get_display_window_handle(display);
    if (!window_handle)
    {
        return -1;
    }

    HICON icon_handle = LoadIconW(
        GetModuleHandleW(NULL),
        MAKEINTRESOURCE(IDI_LVGL_WINDOWS));
    if (icon_handle)
    {
        SendMessageW(
            window_handle,
            WM_SETICON,
            TRUE,
            (LPARAM)icon_handle);
        SendMessageW(
            window_handle,
            WM_SETICON,
            FALSE,
            (LPARAM)icon_handle);
    }

    lv_indev_t* pointer_indev = lv_windows_acquire_pointer_indev(display);
    if (!pointer_indev)
    {
        return -1;
    }

    lv_indev_t* keypad_indev = lv_windows_acquire_keypad_indev(display);
    if (!keypad_indev)
    {
        return -1;
    }

    lv_indev_t* encoder_indev = lv_windows_acquire_encoder_indev(display);
    if (!encoder_indev)
    {
        return -1;
    }
    lv_task_handler();


    lv_theme_t* theme = lv_theme_default_init(display, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(display, theme);

    scr_Main = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr_Main, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_text_color(scr_Main, lv_color_hex(0x000000), 0);
    lv_screen_load(scr_Main);

    prayertimes_init();
    pt_islamic_time_t islamic_time = { 0 };
    pt_get_islamic_times(islamic_time);

    prayer_times_ui();

    while (1)
    {
        lv_task_handler();
        lv_delay_ms(5);

    }

    return 0;
}

void prayer_times_ui(void)
{
    lv_obj_t* obj_header = lv_obj_create(lv_screen_active());
    lv_obj_set_size(obj_header, lv_pct(100), lv_pct(30));
    lv_obj_set_style_bg_color(obj_header, lv_color_hex(0x999999), 0);
}

void style_init(void)
{

}