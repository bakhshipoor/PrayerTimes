#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "lvgl\lvgl.h"
#include "LvglWindowsIconResource\LvglWindowsIconResource.h"
#include "prayer_times_ui.h"
#include "scr_main.h"
#include "scr_settings.h"
#include "prayer_times_ui_texts.h"
#include "prayer_times_ui_update.h"

#ifdef _WIN32

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

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
        L"Prayer Times",
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
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

    prayer_times_ui();

    while (1)
    {
        lv_task_handler();
        lv_delay_ms(5);
    }

    return 0;
}

#endif

void prayer_times_ui(void)
{
    scr_main_create_objects();
    scr_main_style_init();
    scr_main_style_add();
    scr_main_init_objects();

    scr_settings_create_objects();
    scr_settings_style_init();
    scr_settings_style_add();
    scr_settings_init_objects();

    pt_ui_update_initial();

    lv_screen_load(scr_main);
}

