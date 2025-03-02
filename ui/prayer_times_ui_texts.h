#ifndef _PRAYER_TIMES_UI_TEXTS_H
#define _PRAYER_TIMES_UI_TEXTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "prayertimes/prayertimes.h"

#define SCR_MAIN_LBL_HEADER_TITLE                               "Prayer Times 0000.00.00"
#define SCR_MAIN_LBL_HEADER_TITLE_FORMAT                        "Prayer Times %04d.%02d.%02d"
#define SCR_MAIN_LBL_TIMES_IMSAK_TITLE                          "IMSAK"
#define SCR_MAIN_LBL_TIMES_FAJR_TITLE                           "FAJR"
#define SCR_MAIN_LBL_TIMES_SUNRISE_TITLE                        "SUNRISE"
#define SCR_MAIN_LBL_TIMES_MIDDAY_TITLE                         "MIDDAY"
#define SCR_MAIN_LBL_TIMES_DUHUR_TITLE                          "DUHUR"
#define SCR_MAIN_LBL_TIMES_ASR_TITLE                            "ASR"
#define SCR_MAIN_LBL_TIMES_SUNSET_TITLE                         "SUNSET"
#define SCR_MAIN_LBL_TIMES_MAGHRIB_TITLE                        "MAGHRIB"
#define SCR_MAIN_LBL_TIMES_ISHA_TITLE                           "ISHA"
#define SCR_MAIN_LBL_TIMES_MIDNIGHT_TITLE                       "MIDNIGHT"
#define SCR_MAIN_LBL_TIMES_DAY_TITLE                            "DAY"
#define SCR_MAIN_LBL_TIMES_NIGHT_TITLE                          "NIGHT"
#define SCR_MAIN_LBL_TIMES_HOUR_VALUE                           "00:00:00"
#define SCR_MAIN_LBL_TIMES_HOUR_VALUE_FORMAT                    "%02d:%02d:%02d"

#define SCR_SETTINGS_HEADER_TITLE                               "Prayer Times Settings"
#define SCR_SETTINGS_LBL_ITEMS_CALC_METHOD_HEADER               "Calculation Method"
#define SCR_SETTINGS_LBL_ITEMS_ANGLES_HEADER                    "Angles"
#define SCR_SETTINGS_LBL_ITEMS_OFFSETS_HEADER                   "Offsets"
#define SCR_SETTINGS_LBL_ITEMS_JURISTIC_HEADER                  "Juristic Metod"
#define SCR_SETTINGS_LBL_ITEMS_HL_METHOD_HEADER                 "Higher Latatiude Method"
#define SCR_SETTINGS_LBL_ITEMS_MD_METHOD_HEADER                 "Midnight Method"
#define SCR_SETTINGS_LBL_ITEMS_LOCATION_HEADER                  "Location"
#define SCR_SETTINGS_LBL_ITEMS_DATE_HEADER                      "Date"
#define SCR_SETTINGS_LBL_ITEMS_TIME_ZONE_OFFSET_HEADER          "Time Zone Offset"

#define SCR_SETTINGS_LBL_CALC_METHOD                            "Calculation Method: "
#define SCR_SETTINGS_LBL_ANGLES_IMSAK                           "Imsak Angle: "
#define SCR_SETTINGS_LBL_ANGLES_FAJR                            "Fajr Angle: "
#define SCR_SETTINGS_LBL_ANGLES_MAGHRIB                         "Maghrib Angle: "
#define SCR_SETTINGS_LBL_ANGLES_ISHA                            "Isha Angle: "
#define SCR_SETTINGS_LBL_OFFSETS_IMSAK                          "Imsak Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_FAJR                           "Fajr Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_SUNRISE                        "Sunrise Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_DUHUR                          "Duhur Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_ASR                            "Asr Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_SUNSET                         "Sunset Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_MAGHRIB                        "Maghrib Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_ISHA                           "Isha Offset: "
#define SCR_SETTINGS_LBL_OFFSETS_MIDNIGHT                       "Midnight Offset: "
#define SCR_SETTINGS_LBL_JURISTIC                               "Juristic Method: "
#define SCR_SETTINGS_LBL_HL_METHOD                              "HiLat Method: "
#define SCR_SETTINGS_LBL_MD_METHOD                              "Midnight Method: "
#define SCR_SETTINGS_LBL_LOCATION_LATATIUDE                     "Latatiude: "
#define SCR_SETTINGS_LBL_LOCATION_LONGITUDE                     "Longitude: "
#define SCR_SETTINGS_LBL_LOCATION_ALTITUDE                      "Altitude: "
#define SCR_SETTINGS_LBL_DATE                                   "Date: "
#define SCR_SETTINGS_LBL_TIME_ZONE_OFFSET                       "Time Zone Offset: "

#define SCR_SETTINGS_TA_MAX_LENGHT_FLOAT                        12
#define SCR_SETTINGS_TA_MAX_LENGHT_DECIMAL                      5
#define SCR_SETTINGS_TA_MAX_LENGHT_DATE                         10
#define SCR_SETTINGS_TA_MAX_LENGHT_HOUR                         6
#define SCR_SETTINGS_TA_ACCEPTED_CHARS_FLOAT                    "0123456789.+-"
#define SCR_SETTINGS_TA_ACCEPTED_CHARS_DECIMAL                  "0123456789+-"
#define SCR_SETTINGS_TA_ACCEPTED_CHARS_DATE                     "0123456789."
#define SCR_SETTINGS_TA_ACCEPTED_CHARS_HOUR                     "0123456789:+-"
#define SCR_SETTINGS_TA_MAX_HOURS                               23
#define SCR_SETTINGS_TA_MAX_MINUTES                             59

#define SCR_SETTINGS_TA_ANGLES_IMSAK_PLACEHOLDER                "Imsak Angle e.g: 19.5"
#define SCR_SETTINGS_TA_ANGLES_FAJR_PLACEHOLDER                 "Fajr Angle e.g: 17.7"
#define SCR_SETTINGS_TA_ANGLES_MAGHRIB_PLACEHOLDER              "Maghrib Angle e.g: 4.5"
#define SCR_SETTINGS_TA_ANGLES_ISHA_PLACEHOLDER                 "Isha Angle e.g: 14.0"
#define SCR_SETTINGS_TA_OFFSETS_IMSAK_PLACEHOLDER               "Imsak Offset in minutes e.g: -2"
#define SCR_SETTINGS_TA_OFFSETS_FAJR_PLACEHOLDER                "Fajr Offset in minutes e.g: 3"
#define SCR_SETTINGS_TA_OFFSETS_SUNRISE_PLACEHOLDER             "Sunrise Offset in minutes e.g: 0"
#define SCR_SETTINGS_TA_OFFSETS_DUHUR_PLACEHOLDER               "Duhur Offset in minutes e.g: 3"
#define SCR_SETTINGS_TA_OFFSETS_ASR_PLACEHOLDER                 "Asr Offset in minutes e.g: 2"
#define SCR_SETTINGS_TA_OFFSETS_SUNSET_PLACEHOLDER              "Sunset Offset in minutes e.g: 0"
#define SCR_SETTINGS_TA_OFFSETS_MAGHRIB_PLACEHOLDER             "Maghrib Offset in minutes e.g: 3"
#define SCR_SETTINGS_TA_OFFSETS_ISHA_PLACEHOLDER                "Isha Offset in minutes e.g: 1"
#define SCR_SETTINGS_TA_OFFSETS_MIDNIGHT_PLACEHOLDER            "Midnight Offset in minutes e.g: 3"
#define SCR_SETTINGS_TA_LOCATION_LATATIUDE_PLACEHOLDER          "Latatiude e.g: 35.6892"
#define SCR_SETTINGS_TA_LOCATION_LONGITUDE_PLACEHOLDER          "Longitude e.g: 51.3890"
#define SCR_SETTINGS_TA_LOCATION_ALTITUDE_PLACEHOLDER           "Altitude in meter e.g: 1200"
#define SCR_SETTINGS_TA_DATE_PLACEHOLDER                        "Date in Gregorian e.g: 2025.02.25"
#define SCR_SETTINGS_TA_TIME_ZONE_OFFSET_PLACEHOLDER            "Time Zone Offset e.g: 03:30"

#define SCR_SETTINGS_TA_FLOAT_TEXT                              "+0.0"
#define SCR_SETTINGS_TA_DECIMAL_TEXT                            "+0"
#define SCR_SETTINGS_TA_DATE_TEXT                               "2025.01.01"
#define SCR_SETTINGS_TA_TIME_ZONE_OFFSET_TEXT                   "+00:00"

#define SCR_SETTINGS_TA_FLOAT_TEXT_FORMAT                       "%c%f"
#define SCR_SETTINGS_TA_DECIMAL_TEXT_FORMAT                     "%c%d"
#define SCR_SETTINGS_TA_DATE_TEXT_FORMAT                        "%04d.%02d.%02d"
#define SCR_SETTINGS_TA_TIME_ZONE_OFFSET_TEXT_FORMAT            "%c%02d:%02d"

#define SCR_SETTINGS_CALC_METHOD_CUSTOM                         "Custom"  
#define SCR_SETTINGS_CALC_METHOD_ALGERIA_MOFA                   "Algeria"
#define SCR_SETTINGS_CALC_METHOD_AMERICA_NORTH                  "North America"
#define SCR_SETTINGS_CALC_METHOD_EGYPT_GAS                      "Egypt"
#define SCR_SETTINGS_CALC_METHOD_FRANCE_MUSLIM                  "France"
#define SCR_SETTINGS_CALC_METHOD_INDONESIA_SIHAT                "Indonesia"
#define SCR_SETTINGS_CALC_METHOD_IRAN_QOM                       "Iran, Qom"
#define SCR_SETTINGS_CALC_METHOD_IRAN_TEHRAN                    "Iran, Tehran"
#define SCR_SETTINGS_CALC_METHOD_KUWAIT                         "Kuwait"
#define SCR_SETTINGS_CALC_METHOD_MALAYSIA                       "Malaysia"
#define SCR_SETTINGS_CALC_METHOD_MECCA_UMMALQURA                "Mecca"
#define SCR_SETTINGS_CALC_METHOD_MOROCCO                        "Morocco"
#define SCR_SETTINGS_CALC_METHOD_PAKISTAN_KARACHI               "Pakistan"
#define SCR_SETTINGS_CALC_METHOD_QATAR                          "Qatar"
#define SCR_SETTINGS_CALC_METHOD_RUSSIA_MUSLIM                  "Russia"
#define SCR_SETTINGS_CALC_METHOD_SINGAPORE                      "Singapore"
#define SCR_SETTINGS_CALC_METHOD_TUNISIA_MOFA                   "Tunisia"
#define SCR_SETTINGS_CALC_METHOD_TURKIYE_DIYANET                "Turkiye"
#define SCR_SETTINGS_CALC_METHOD_WORLD_LEAGUE                   "World"

#define SCR_SETTINGS_JURISTIC_METHOD_STANDARD                   "Standard"
#define SCR_SETTINGS_JURISTIC_METHOD_HANAFI                     "Hanafi"

#define SCR_SETTINGS_HL_METHOD_NONE                             "No adjustment"
#define SCR_SETTINGS_HL_METHOD_NIGHTMIDDLE                      "Middle of night"
#define SCR_SETTINGS_HL_ANGLEBASED                              "Angle/60th of night"
#define SCR_SETTINGS_HL_METHOD_ONESEVENTH                       "1/7th of night"

#define SCR_SETTINGS_MD_METHOD_STANDARD                         "Mid Sunset to Sunrise"
#define SCR_SETTINGS_MD_METHOD_JAFARI                           "Mid Sunset to Fajr"

#ifdef __cplusplus
}
#endif

#endif