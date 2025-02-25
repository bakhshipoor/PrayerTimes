#ifndef _PRAYER_TIMES_H
#define _PRAYER_TIMES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

	typedef enum pt_time_enum
	{
		PT_TIME_IMSAK = 0,
		PT_TIME_FAJR,
		PT_TIME_SUNRISE,
		PT_TIME_MIDDAY,
		PT_TIME_DHUHR,
		PT_TIME_ASR,
		PT_TIME_SUNSET,
		PT_TIME_MAGHRIB,
		PT_TIME_ISHA,
		PT_TIME_MIDNIGHT,
		PT_TIME_DAY,
		PT_TIME_NIGHT,

		PT_TIME_TOTAL
	}pt_time_e;

	typedef enum pt_calc_method_refrence_enum
	{
		PT_CM_ALGERIA_MOFA,            // 01. Algeria,        Ministry of religious affairs and wakfs                |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 17.000°
		PT_CM_AMERICA_NORTH,           // 02. North America,  Islamic Society of North America                       |  Fajr: 15.000°, Maghrib: 00.833°, Isha: 15.000°
		PT_CM_EGYPT_GAS,               // 03. Egypt,          General Authority of Survey                            |  Fajr: 19.500°, Maghrib: 00.833°, Isha: 17.500°
		PT_CM_FRANCE_MUSLIM,           // 04. France,         Muslims of France                                      |  Fajr: 12.000°, Maghrib: 00.833°, Isha: 12.000°
		PT_CM_INDONESIA_SIHAT,         // 05. Indonesia,      Sihat Kemenag                                          |  Fajr: 20.000°, Maghrib: 00.833°, Isha: 18.000°
		PT_CM_IRAN_QOM,                // 06. Iran,           Qom, Leva Institute                                    |  Fajr: 16.000°, Maghrib: 04.000°, Isha: 14.000°
		PT_CM_IRAN_TEHRAN,             // 07. Iran,           Tehran, Institute of Geophysics University of Tehran   |  Fajr: 17.700°, Maghrib: 04.500°, Isha: 14.000°
		PT_CM_KUWAIT,                  // 08. Kuwait,                                                                |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 17.500°
		PT_CM_MALAYSIA,                // 09. Malaysia,       Jabatan Kemajuan Islam                                 |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 18.000°
		PT_CM_MECCA_UMMALQURA,         // 10. Mecca,          Umm al - Qura University                               |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 00.833° + 90 minutes
		PT_CM_MOROCCO,                 // 11. Morocco,        Ministry of wakfs and islamic affairs                  |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 17.000°
		PT_CM_PAKISTAN_KARACHI,        // 12. Pakistan,       University of Science of Karachi                       |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 18.000°
		PT_CM_QATAR,                   // 13. Qatar,                                                                 |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 00.833° + 90 minutes
		PT_CM_RUSSIA_MUSLIM,           // 14. Russia,         Spiritual Administration of Muslims                    |  Fajr: 16.000°, Maghrib: 00.833°, Isha: 15.000°
		PT_CM_SINGAPORE,               // 15. Singapore,      Majlis Ugama Islam                                     |  Fajr: 20.000°, Maghrib: 00.833°, Isha: 18.000°
		PT_CM_TUNISIA_MOFA,            // 16. Tunisia,        Ministry of Religious Affairs                          |  Fajr: 10.000°, Maghrib: 00.833°, Isha: 10.000°
		PT_CM_TURKIYE_DIYANET,         // 17. Turkiye,        Presidency of Religious Affairs                        |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 17.000°
		PT_CM_WORLD_LEAGUE,            // 18. World,          World Islamic League                                   |  Fajr: 18.000°, Maghrib: 00.833°, Isha: 17.000°
		PT_CM_CUSTOM,                  // 19. Custom                                                                 |  Fajr: 00.000°, Maghrib: 00.000°, Isha: 00.000°

		PT_CM_TOTAL
	}pt_calc_method_refrence_e;

	typedef enum pt_juristic_enum
	{
		PT_J_STANDARD = 0, // Shafi`i, Maliki, Ja`fari, Hanbali
		PT_J_HANAFI,
	}pt_juristic_e;

	typedef enum pt_higher_latitudes_method_enum
	{
		PT_HL_NONE = 0,       // No adjustment
		PT_HL_NIGHTMIDDLE,    // middle of night
		PT_HL_ANGLEBASED,     // angle/60th of night
		PT_HL_ONESEVENTH,     // 1/7th of night
	}pt_hl_method_e;

	typedef enum pt_midnight_method_enum
	{
		PT_MD_STANDARD = 0,    // Mid Sunset to Sunrise
		PT_MD_JAFARI,          // Mid Sunset to Fajr
	}pt_midnight_method_e;

	typedef struct pt_date_struct
	{
		uint16_t year;
		uint16_t month;
		uint16_t day;
	}pt_date_t;

	typedef struct pt_time_struct
	{
		uint16_t hour;
		uint16_t minute;
		uint16_t second;
	}pt_time_t;

	typedef struct pt_location_struct
	{
		double latitude;
		double longitude;
		double altitude;
	}pt_location_t;

	typedef struct pt_angles_struct
	{
		float imsak;
		float fajr;
		float maghrib;
		float isha;
	}pt_angles_t;

	typedef struct pt_offsets_struct
	{
		int16_t imsak;
		int16_t fajr;
		int16_t sunrise;
		int16_t duhur;
		int16_t asr;
		int16_t sunset;
		int16_t maghrib;
		int16_t isha;
		int16_t midnight;
	}pt_offsets_t;

	typedef struct pt_calc_method_struct
	{
		pt_calc_method_refrence_e refrence;
		pt_angles_t angles;
		pt_offsets_t offsets;
	}pt_calc_method_t;

	typedef struct sun_position_struct
	{
		double declination_sun;
		double equation_time;
	}sun_position_t;

	typedef struct pt_calc_data_struct
	{
		sun_position_t sun_positin;
		double times[PT_TIME_TOTAL];
	}pt_calc_data_t;

	typedef struct pt_user_data_struct
	{
		pt_calc_method_refrence_e calc_method;
		pt_angles_t angles;
		pt_offsets_t offsets;
		pt_juristic_e juristic;
		pt_hl_method_e hl_method;
		pt_midnight_method_e md_method;
		pt_location_t location;
	}pt_user_data_t;

	typedef struct pt_system_data_struct
	{
		pt_date_t date;
		double time_zone_offset;
	}pt_system_data_t;

	typedef struct Pray_Times_Struct
	{
		// User Data
		pt_user_data_t user_data;
		// System Data
		pt_system_data_t system_data;
		// Calculated Data
		pt_calc_data_t calc_data;
		// Output Data
		pt_time_t times[PT_TIME_TOTAL];
	}pray_times_t;


	extern pray_times_t* pray_times;

	bool praytimes_Init(void);
	
#ifdef __cplusplus
}
#endif

#endif