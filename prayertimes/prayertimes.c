#include <stdio.h>
#include <stdlib.h>
#include "prayertimes.h"
#include "prayertimes_math.h"

static pt_data_t* pt_data = NULL;

static void pt_calculate_pray_times(pt_data_t* pt_data);
static void pt_calculate_imsak(pt_data_t* pt_data);
static void pt_calculate_fajr(pt_data_t* pt_data);
static void pt_calculate_sunrise(pt_data_t* pt_data);
static void pt_calculate_midday(pt_data_t* pt_data);
static void pt_calculate_duhur(pt_data_t* pt_data);
static void pt_calculate_asr(pt_data_t* pt_data);
static void pt_calculate_sunset(pt_data_t* pt_data);
static void pt_calculate_maghrib(pt_data_t* pt_data);
static void pt_calculate_isha(pt_data_t* pt_data);
static void pt_calculate_midnight(pt_data_t* pt_data);
static void pt_calculate_day_time(pt_data_t* pt_data);
static void pt_calculate_night_time(pt_data_t* pt_data);
static void pt_adjust_higher_latitude(pt_data_t* pt_data);
static double pt_get_method_angle(pt_data_t* pt_data, pt_time_e time);
static uint16_t pt_calculate_days_in_month(uint16_t* year, uint16_t* month);
static bool pt_validate_date(pt_date_t* date);

const pt_calc_method_t pt_calc_methods[PT_CM_TOTAL] = {
	// https://www.islamicfinder.org/prayer-times/
	// https://intime.ir/doc.html
	// http://praytimes.org/wiki/Calculation_Methods
	// https://mawaqit.net/
	{
		.refrence = PT_CM_CUSTOM,
		.angles = {0},
		.offsets = {0},
	},
	{
		// 01. Algeria, Ministry of religious affairs and wakfs
		.refrence = PT_CM_ALGERIA_MOFA,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 17.0},
		// 0
		.offsets = {0},
	},
	{
		// 02. North America, Islamic Society of North America 
		.refrence = PT_CM_AMERICA_NORTH,
		//                        Fajr:  15.0°, Maghrib:  0.833°, Isha:  15.0°
		.angles = {.imsak = 0.0, .fajr = 15.0, .maghrib = 0.833, .isha = 15.0},
		// 0
		.offsets = {0},
	},
	{
		// 03. Egypt, General Authority of Survey 
		.refrence = PT_CM_EGYPT_GAS,
		//                        Fajr:  19.5°, Maghrib:  0.833°, Isha:  17.5°
		.angles = {.imsak = 0.0, .fajr = 19.5, .maghrib = 0.833, .isha = 17.5},
		// 0
		.offsets = {0},
	},
	{
		// 04. France, Muslims of France 
		.refrence = PT_CM_FRANCE_MUSLIM,
		//                        Fajr:  12.0°, Maghrib:  0.833°, Isha:  12.0°
		.angles = {.imsak = 0.0, .fajr = 12.0, .maghrib = 0.833, .isha = 12.0},
		// 0
		.offsets = {0},
	},
	{
		// 05. Indonesia, Sihat Kemenag
		.refrence = PT_CM_INDONESIA_SIHAT,
		//                        Fajr:  20.0°, Maghrib:  0.833°, Isha:  18.0°
		.angles = {.imsak = 0.0, .fajr = 20.0, .maghrib = 0.833, .isha = 18.0},
		// 0
		.offsets = {0},
	},
	{
		// 06. Iran, Qom, Leva Institute
		.refrence = PT_CM_IRAN_QOM,
		//                        Fajr:  16.0°, Maghrib:  4.0°, Isha:  14.0°
		.angles = {.imsak = 0.0, .fajr = 16.0, .maghrib = 4.0, .isha = 14.0},
		// 0
		.offsets = {0},
	},
	{
		// 07. Iran, Tehran, Institute of Geophysics University of Tehran
		.refrence = PT_CM_IRAN_TEHRAN,
		//                        Fajr:  17.7°, Maghrib:  4.5°, Isha:  14.0°
		.angles = {.imsak = 0.0, .fajr = 17.7, .maghrib = 4.5, .isha = 14.0},
		// 0
		.offsets = {0},
	},
	{
		// 08. Kuwait,
		.refrence = PT_CM_KUWAIT,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.5°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 17.5},
		// 0
		.offsets = {0},
	},
	{
		// 09. Malaysia, Jabatan Kemajuan Islam
		.refrence = PT_CM_MALAYSIA,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  18.0°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 18.0},
		// 0
		.offsets = {0},
	},
	{
		// 10. Mecca, Umm al - Qura University
		.refrence = PT_CM_MECCA_UMMALQURA,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  0.833° + 90 minutes
		.angles = {.imsak = 0.0, .fajr = 18.5, .maghrib = 0.833, .isha = 0.833},
		// Isha:  90 minutes
		.offsets = {.imsak = 0, .fajr = 0, .sunrise = 0, .duhur = 1, .asr = 0, .sunset = 0, .maghrib = 0, .isha = 90, .midnight = 0},
	},
	{
		// 11. Morocco, Ministry of wakfs and islamic affairs
		.refrence = PT_CM_MOROCCO,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 17.0},
		// 0
		.offsets = {0},
	},
	{
		// 12. Pakistan, University of Science of Karachi
		.refrence = PT_CM_PAKISTAN_KARACHI,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  18.0°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 18.0},
		// 0
		.offsets = {0},
	},
	{
		// 13. Qatar,
		.refrence = PT_CM_QATAR,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  0.833°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 0.833},
		// Isha: 90 minutes
		.offsets = {.imsak = 0, .fajr = 0, .sunrise = 0, .duhur = 1, .asr = 0, .sunset = 0, .maghrib = 0, .isha = 90, .midnight = 0},
	},
	{
		// 14. Russia, Spiritual Administration of Muslims
		.refrence = PT_CM_RUSSIA_MUSLIM,
		//                        Fajr:  16.0°, Maghrib:  0.833°, Isha:  15.0°
		.angles = {.imsak = 0.0, .fajr = 16.0, .maghrib = 0.833, .isha = 15.0},
		// 0
		.offsets = {0},
	},
	{
		// 15. Singapore, Majlis Ugama Islam
		.refrence = PT_CM_SINGAPORE,
		//                        Fajr:  20.0°, Maghrib:  0.833°, Isha:  18.0°
		.angles = {.imsak = 0.0, .fajr = 20.0, .maghrib = 0.833, .isha = 18.0},
		// 0
		.offsets = {0},
	},
	{
		// 16. Tunisia, Ministry of Religious Affairs
		.refrence = PT_CM_TUNISIA_MOFA,
		//                        Fajr:  10.0°, Maghrib:  0.833°, Isha:  10.0°
		.angles = {.imsak = 0.0, .fajr = 10.0, .maghrib = 0.833, .isha = 10.0},
		// 0
		.offsets = {0},
	},
	{
		// 17. Turkiye, Presidency of Religious Affairs
		.refrence = PT_CM_TURKIYE_DIYANET,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 17.0},
		// sunrise: -7, dhuhr: 5, asr: 4, maghrib: 7 minutes
		.offsets = {.imsak = 0, .fajr = 0, .sunrise = -7, .duhur = 5, .asr = 4, .sunset = 0, .maghrib = 7, .isha = 0, .midnight = 0},
	},
	{
		// 18. World, World Islamic League
		.refrence = PT_CM_WORLD_LEAGUE,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.angles = {.imsak = 0.0, .fajr = 18.0, .maghrib = 0.833, .isha = 17.0},
		// 0
		.offsets = {0},
	},
};

bool prayertimes_init(void)
{
	if (pt_data != NULL)
	{
		free(pt_data);
		pt_data = NULL;
	}
	pt_data = (pt_data_t*)calloc(1, sizeof(pt_data_t));
	if (pt_data == NULL)
	{
		return false;
	}
	// Set Calculation Method
	pt_set_calc_method(PT_CM_IRAN_TEHRAN);
	// Set Juristic Method
	pt_set_juristic_method(PT_J_STANDARD);
	// Set Higher Latatiude Method
	pt_set_hilat_method(PT_HL_NONE);
	// Set Midnight Method
	pt_set_midnight_method(PT_MD_JAFARI);
	// Set Location
	pt_location_t location = { .latitude = 35.6892, .longitude = 51.3890, .altitude = 0 };
	pt_set_location(&location);
	// Set Date
	pt_date_t date = { .year = 2025, .month = 1, .day = 1 };
	pt_set_date(&date);
	// Set Time Zone Offset
	pt_set_timezone_offset(3.5);
	// Set Initial Status
	pt_data->is_init = true;
}

// Set Methods

bool pt_set_calc_method(pt_calc_method_e calc_method)
{
	if (pt_data == NULL)
	{
		return false;
	}
	if (calc_method < PT_CM_CUSTOM || calc_method >= PT_CM_TOTAL)
	{
		return false;
	}
	pt_data->settings.calc_method = calc_method;
	if (calc_method != PT_CM_CUSTOM)
	{
		pt_set_angles(&pt_calc_methods[calc_method].angles);
		pt_set_offsets(&pt_calc_methods[calc_method].offsets);
	}
	return true;
}

bool pt_set_angles(pt_angles_t* angles)
{
	if (pt_data == NULL)
	{
		return false;
	}
	pt_data->settings.angles.imsak = angles->imsak;
	pt_data->settings.angles.fajr = angles->fajr;
	pt_data->settings.angles.maghrib = angles->maghrib;
	pt_data->settings.angles.isha = angles->isha;
	return true;
}

bool pt_set_offsets(pt_offsets_t* offsets)
{
	if (pt_data == NULL)
	{
		return false;
	}
	pt_data->settings.offsets.imsak = offsets->imsak;
	pt_data->settings.offsets.fajr = offsets->fajr;
	pt_data->settings.offsets.sunrise = offsets->sunrise;
	pt_data->settings.offsets.duhur = offsets->duhur;
	pt_data->settings.offsets.asr = offsets->asr;
	pt_data->settings.offsets.sunset = offsets->sunset;
	pt_data->settings.offsets.maghrib = offsets->maghrib;
	pt_data->settings.offsets.isha = offsets->isha;
	pt_data->settings.offsets.midnight = offsets->midnight;
	return true;
}

bool pt_set_juristic_method(pt_juristic_e juristic)
{
	if (pt_data == NULL)
	{
		return false;
	}
	if (juristic < PT_J_STANDARD || juristic > PT_J_HANAFI)
	{
		return false;
	}
	pt_data->settings.juristic = juristic;
	return true;
}

bool pt_set_hilat_method(pt_hl_method_e hl_method)
{
	if (pt_data == NULL)
	{
		return false;
	}
	if (hl_method < PT_HL_NONE || hl_method > PT_HL_ONESEVENTH)
	{
		return false;
	}
	pt_data->settings.hl_method = hl_method;
	return true;
}

bool pt_set_midnight_method(pt_midnight_method_e md_method)
{
	if (pt_data == NULL)
	{
		return false;
	}
	if (md_method < PT_MD_STANDARD || md_method > PT_MD_JAFARI)
	{
		return false;
	}
	pt_data->settings.md_method = md_method;
	return true;
}

bool pt_set_location(pt_location_t* location)
{
	if (pt_data == NULL)
	{
		return false;
	}
	pt_data->settings.location.latitude = location->latitude;
	pt_data->settings.location.longitude = location->longitude;
	pt_data->settings.location.altitude = location->altitude;
	return true;
}

bool pt_set_date(pt_date_t* date)
{
	if (pt_data == NULL)
	{
		return false;
	}
	if (!pt_validate_date(date))
	{
		return false;
	}
	pt_data->settings.date.year = date->year;
	pt_data->settings.date.month = date->month;
	pt_data->settings.date.day = date->day;
	return true;
}

bool pt_set_timezone_offset(double tz_offset)
{
	if (pt_data == NULL)
	{
		return false;
	}
	pt_data->settings.time_zone_offset = tz_offset;
	return true;
}

// Get Methods

pt_calc_method_e pt_get_calc_method(void)
{
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.calc_method;
	}
	return PT_CM_ERROR;
}

pt_angles_t pt_get_angles(void)
{
	pt_angles_t angles = { 0 };
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.angles;
	}
	return angles;
}

pt_offsets_t pt_get_offsets(void)
{
	pt_offsets_t offsets = { 0 };
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.offsets;
	}
	return offsets;
}

pt_juristic_e pt_get_juristic_method(void)
{
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.juristic;
	}
	return PT_J_ERROR;
}

pt_hl_method_e pt_get_hilat_method(void)
{
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.hl_method;
	}
	return PT_HL_ERROR;
}

pt_midnight_method_e pt_get_midnight_method(void)
{
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.md_method;
	}
	return PT_MD_ERROR;
}

pt_location_t pt_get_location(void)
{
	pt_location_t location = { 0 };
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.location;
	}
	return location;
}

pt_date_t pt_get_date(void)
{
	pt_date_t date = { 0 };
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.date;
	}
	return date;
}

double pt_get_timezone_offset(void)
{
	if (pt_data != NULL && pt_data->is_init == true)
	{
		return pt_data->settings.time_zone_offset;
	}
	return 0.0;
}

void pt_get_islamic_times(pt_islamic_time_t* islamic_time)
{
	if (pt_data == NULL || pt_data->is_init == false)
	{
		return;
	}
	pt_calculate_pray_times(pt_data);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_IMSAK], &islamic_time->imsak);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_FAJR], &islamic_time->fajr);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_SUNRISE], &islamic_time->sunrise);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_MIDDAY], &islamic_time->midday);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_DHUHR], &islamic_time->dhuhr);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_ASR], &islamic_time->asr);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_SUNSET], &islamic_time->sunset);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_MAGHRIB], &islamic_time->maghrib);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_ISHA], &islamic_time->isha);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_MIDNIGHT], &islamic_time->midnight);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_DAY], &islamic_time->day);
	pt_double_to_time(pt_data->calc_data.times[PT_TIME_NIGHT], &islamic_time->night);
}

static void pt_calculate_pray_times(pt_data_t* pt_data)
{
	// Calculate Sum Position
	pt_calculate_sun_position(pt_jdn(pt_data->settings.date.year, pt_data->settings.date.month, pt_data->settings.date.day, 0), pt_data);

	// Calculate Mid Day
	pt_calculate_midday(pt_data);

	// Calculate Duhur
	pt_calculate_duhur(pt_data);

	// Calculate Sunrise
	pt_calculate_sunrise(pt_data);

	// Calculate Sunset
	pt_calculate_sunset(pt_data);

	// Calculate Day Time
	pt_calculate_day_time(pt_data);

	// Calculate Night Time
	pt_calculate_night_time(pt_data);

	// Calculate Fajr
	pt_calculate_fajr(pt_data);

	// Calculate Imsak
	pt_calculate_imsak(pt_data);

	// Calculate Asr
	pt_calculate_asr(pt_data);

	// Maghrib
	pt_calculate_maghrib(pt_data);

	// Calculate Isha
	pt_calculate_isha(pt_data);

	// Calculate Midnight
	pt_calculate_midnight(pt_data);

	// Adjust Higher Latatiude
	pt_adjust_higher_latitude(pt_data);
}

static void pt_calculate_imsak(pt_data_t* pt_data)
{
	int16_t offset = 0;
	double angle = 0.0;
	double imsak = 0.0;

	offset = pt_data->settings.offsets.imsak;

	if (pt_data->settings.calc_method == PT_CM_CUSTOM)
	{
		angle = pt_data->settings.angles.imsak;
	}
	else
	{
		angle = pt_data->settings.angles.imsak;
	}

	if (angle > 0)
	{
		imsak = pt_data->calc_data.times[PT_TIME_DHUHR] - pt_calculate_sun_angle_time(angle, pt_data);
		imsak += pt_time_to_double(0, offset);
	}
	else
	{
		imsak = pt_data->calc_data.times[PT_TIME_FAJR] - pt_time_to_double(0, offset);
	}

	pt_data->calc_data.times[PT_TIME_IMSAK] = pt_fix_hour(imsak);
}

static void pt_calculate_fajr(pt_data_t* pt_data)
{
	int16_t offset = 0;
	double angle = 0.0;
	double fajr = 0.0;
	
	offset = pt_data->settings.offsets.fajr;

	if (pt_data->settings.calc_method == PT_CM_CUSTOM)
	{
		angle = pt_data->settings.angles.fajr;
	}
	else
	{
		angle = pt_data->settings.angles.fajr;
	}

	if (angle > 0)
	{
		fajr = pt_data->calc_data.times[PT_TIME_DHUHR] - pt_calculate_sun_angle_time(angle, pt_data);
	}
	else
	{
		fajr = pt_data->calc_data.times[PT_TIME_SUNRISE];
	}
	
	fajr += pt_time_to_double(0, offset);
	pt_data->calc_data.times[PT_TIME_FAJR] = pt_fix_hour(fajr);
}

static void pt_calculate_sunrise(pt_data_t* pt_data)
{
	int16_t offset = 0;
	double angle = 0.833 + (0.0347 * sqrt(pt_data->settings.location.altitude));
	double sunrise = 0.0;

	offset = pt_data->settings.offsets.sunrise;

	sunrise = pt_data->calc_data.times[PT_TIME_MIDDAY] - pt_calculate_sun_angle_time(angle, pt_data);
	sunrise += pt_time_to_double(0, offset);
	pt_data->calc_data.times[PT_TIME_SUNRISE] = pt_fix_hour(sunrise);
}

static void pt_calculate_midday(pt_data_t* pt_data)
{
	pt_data->calc_data.times[PT_TIME_MIDDAY] = pt_fix_hour(12.0 - pt_data->calc_data.sun_positin.equation_time + (pt_data->settings.time_zone_offset - (pt_data->settings.location.longitude / 15.0)));
}

static void pt_calculate_duhur(pt_data_t* pt_data)
{
	int16_t offset = 0;
	offset = pt_data->settings.offsets.duhur;
	double duhur = pt_data->calc_data.times[PT_TIME_MIDDAY] + pt_time_to_double(0, offset);
	pt_data->calc_data.times[PT_TIME_DHUHR] = pt_fix_hour(duhur);
}

static void pt_calculate_asr(pt_data_t* pt_data)
{
	int16_t offset = 0;
	int factor = 0.0;
	double asr = 0.0;
	
	offset = pt_data->settings.offsets.asr;

	if (pt_data->settings.juristic == PT_J_STANDARD)
	{
		factor = 1;
	}
	else
	{
		factor = 2;
	}
	asr = pt_data->calc_data.times[PT_TIME_DHUHR] + pt_calculate_asr_angle_time(factor, pt_data);
	asr += pt_time_to_double(0, offset);
	pt_data->calc_data.times[PT_TIME_ASR] = pt_fix_hour(asr);
}

static void pt_calculate_sunset(pt_data_t* pt_data)
{
	int16_t offset = 0;
	double angle = 0.833 + (0.0347 * sqrt(pt_data->settings.location.altitude));
	double sunset = 0.0;

	offset = pt_data->settings.offsets.sunset;

	sunset = pt_data->calc_data.times[PT_TIME_MIDDAY] + pt_calculate_sun_angle_time(angle, pt_data);
	sunset += pt_time_to_double(0, offset);
	pt_data->calc_data.times[PT_TIME_SUNSET] = pt_fix_hour(sunset);
}

static void pt_calculate_maghrib(pt_data_t* pt_data)
{
	int16_t offset = 0;
	double angle = 0.0;
	double maghrib = 0.0;

	offset = pt_data->settings.offsets.maghrib;

	if (pt_data->settings.calc_method == PT_CM_CUSTOM)
	{
		angle = pt_data->settings.angles.maghrib;
	}
	else
	{
		angle = pt_data->settings.angles.maghrib;
	}

	if (angle > 0)
	{
		maghrib = pt_data->calc_data.times[PT_TIME_DHUHR] + pt_calculate_sun_angle_time(angle, pt_data);
	}
	else
	{
		maghrib = pt_data->calc_data.times[PT_TIME_SUNSET];
	}

	maghrib += pt_time_to_double(0, offset);
	pt_data->calc_data.times[PT_TIME_MAGHRIB] = pt_fix_hour(maghrib);
}

static void pt_calculate_isha(pt_data_t* pt_data)
{
	int16_t offset = 0;
	double angle = 0.0;
	double isha = 0.0;

	offset = pt_data->settings.offsets.isha;

	if (pt_data->settings.calc_method == PT_CM_CUSTOM)
	{
		angle = pt_data->settings.angles.isha;
	}
	else
	{
		angle = pt_data->settings.angles.isha;
	}

	if (angle > 0)
	{
		isha = pt_data->calc_data.times[PT_TIME_DHUHR] + pt_calculate_sun_angle_time(angle, pt_data);
	}
	else
	{
		isha = pt_data->calc_data.times[PT_TIME_MAGHRIB];
	}
	
	isha += pt_time_to_double(0, offset);
	pt_data->calc_data.times[PT_TIME_ISHA] = pt_fix_hour(isha);
}

static void pt_calculate_midnight(pt_data_t* pt_data)
{
	double midnight = 0.0;
	if (pt_data->settings.md_method == PT_MD_STANDARD)
	{
		midnight = pt_data->calc_data.times[PT_TIME_SUNSET] + (pt_time_diff(pt_data->calc_data.times[PT_TIME_SUNSET], pt_data->calc_data.times[PT_TIME_SUNRISE]) / 2);
	}
	else
	{
		midnight = pt_data->calc_data.times[PT_TIME_SUNSET] + (pt_time_diff(pt_data->calc_data.times[PT_TIME_SUNSET], pt_data->calc_data.times[PT_TIME_FAJR]) / 2);
	}

	pt_data->calc_data.times[PT_TIME_MIDNIGHT] = pt_fix_hour(midnight);
}

static void pt_calculate_day_time(pt_data_t* pt_data)
{
	double Day_time = 0.0;

	Day_time = pt_time_diff(pt_data->calc_data.times[PT_TIME_SUNRISE], pt_data->calc_data.times[PT_TIME_SUNSET]);

	pt_data->calc_data.times[PT_TIME_DAY] = pt_fix_hour(Day_time);
}

static void pt_calculate_night_time(pt_data_t* pt_data)
{
	double night_time = 0.0;
	
	night_time = pt_time_diff(pt_data->calc_data.times[PT_TIME_SUNSET], pt_data->calc_data.times[PT_TIME_SUNRISE]);
	
	pt_data->calc_data.times[PT_TIME_NIGHT] = pt_fix_hour(night_time);
}

static void pt_adjust_higher_latitude(pt_data_t* pt_data)
{
	double portion_imsak = 0.0;
	double portion_fajr = 0.0;
	double portion_maghrib = 0.0;
	double portion_isha = 0.0;
	double time_diff = 0.0;

	if (pt_data->settings.hl_method < PT_HL_NIGHTMIDDLE || pt_data->settings.hl_method > PT_HL_ONESEVENTH)
	{
		return;
	}
	else if (pt_data->settings.hl_method == PT_HL_NIGHTMIDDLE)
	{
		portion_imsak = pt_data->calc_data.times[PT_TIME_NIGHT] / 2;
		portion_fajr = pt_data->calc_data.times[PT_TIME_NIGHT] / 2;
		portion_maghrib = pt_data->calc_data.times[PT_TIME_NIGHT] / 2;
		portion_isha = pt_data->calc_data.times[PT_TIME_NIGHT] / 2;
	}
	else if (pt_data->settings.hl_method == PT_HL_ANGLEBASED)
	{
		portion_imsak = pt_get_method_angle(pt_data, PT_TIME_IMSAK) * pt_data->calc_data.times[PT_TIME_NIGHT] / 60;
		portion_fajr = pt_get_method_angle(pt_data, PT_TIME_FAJR) * pt_data->calc_data.times[PT_TIME_NIGHT] / 60;
		portion_maghrib = pt_get_method_angle(pt_data, PT_TIME_MAGHRIB) * pt_data->calc_data.times[PT_TIME_NIGHT] / 60;
		portion_isha = pt_get_method_angle(pt_data, PT_TIME_ISHA) * pt_data->calc_data.times[PT_TIME_NIGHT] / 60;
	}
	else if (pt_data->settings.hl_method == PT_HL_ONESEVENTH)
	{
		portion_imsak = pt_data->calc_data.times[PT_TIME_NIGHT] / 7;
		portion_fajr = pt_data->calc_data.times[PT_TIME_NIGHT] / 7;
		portion_maghrib = pt_data->calc_data.times[PT_TIME_NIGHT] / 7;
		portion_isha = pt_data->calc_data.times[PT_TIME_NIGHT] / 7;
	}

	time_diff = pt_time_diff(pt_data->calc_data.times[PT_TIME_IMSAK], pt_data->calc_data.times[PT_TIME_SUNRISE]);
	if (time_diff > portion_imsak)
	{
		pt_data->calc_data.times[PT_TIME_IMSAK] = pt_fix_hour(pt_data->calc_data.times[PT_TIME_SUNRISE] - portion_imsak);
	}

	time_diff = pt_time_diff(pt_data->calc_data.times[PT_TIME_FAJR], pt_data->calc_data.times[PT_TIME_SUNRISE]);
	if (time_diff > portion_fajr)
	{
		pt_data->calc_data.times[PT_TIME_FAJR] = pt_fix_hour(pt_data->calc_data.times[PT_TIME_SUNRISE] - portion_fajr);
	}

	time_diff = pt_time_diff(pt_data->calc_data.times[PT_TIME_SUNSET], pt_data->calc_data.times[PT_TIME_MAGHRIB]);
	if (time_diff > portion_maghrib)
	{
		pt_data->calc_data.times[PT_TIME_MAGHRIB] = pt_fix_hour(pt_data->calc_data.times[PT_TIME_SUNSET] + portion_maghrib);
	}

	time_diff = pt_time_diff(pt_data->calc_data.times[PT_TIME_SUNSET], pt_data->calc_data.times[PT_TIME_ISHA]);
	if (time_diff > portion_isha)
	{
		pt_data->calc_data.times[PT_TIME_ISHA] = pt_fix_hour(pt_data->calc_data.times[PT_TIME_SUNSET] + portion_isha);
	}
}

static double pt_get_method_angle(pt_data_t* pt_data, pt_time_e time)
{
	if (pt_data->settings.calc_method == PT_CM_CUSTOM)
	{
		if (time == PT_TIME_IMSAK)
		{
			if (pt_data->settings.angles.imsak > 0)
			{
				return pt_data->settings.angles.imsak;
			}
			else
			{
				return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_IMSAK], pt_data);
			}
		}
		else if (time == PT_TIME_FAJR)
		{
			if (pt_data->settings.angles.fajr > 0)
			{
				return pt_data->settings.angles.fajr;
			}
			else
			{
				return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_FAJR], pt_data);
			}
		}
		else if (time == PT_TIME_MAGHRIB)
		{
			if (pt_data->settings.angles.maghrib > 0)
			{
				return pt_data->settings.angles.maghrib;
			}
			else
			{
				return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_MAGHRIB], pt_data);
			}
		}
		else if (time == PT_TIME_ISHA)
		{
			if (pt_data->settings.angles.isha > 0)
			{
				return pt_data->settings.angles.isha;
			}
			else
			{
				return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_ISHA], pt_data);
			}
		}
	}
	else
	{
		if (pt_data->settings.calc_method < PT_CM_CUSTOM && pt_data->settings.calc_method >= PT_CM_ALGERIA_MOFA)
		{
			if (time == PT_TIME_IMSAK)
			{
				if (pt_data->settings.angles.imsak > 0)
				{
					return pt_data->settings.angles.imsak;
				}
				else
				{
					return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_DHUHR] - pt_data->calc_data.times[PT_TIME_IMSAK], pt_data);
				}
			}
			else if (time == PT_TIME_FAJR)
			{
				if (pt_data->settings.angles.fajr > 0)
				{
					return pt_data->settings.angles.fajr;
				}
				else
				{
					return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_DHUHR] - pt_data->calc_data.times[PT_TIME_FAJR], pt_data);
				}
			}
			else if (time == PT_TIME_MAGHRIB)
			{
				if (pt_data->settings.angles.maghrib > 0)
				{
					return pt_data->settings.angles.maghrib;
				}
				else
				{
					return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_MAGHRIB] - pt_data->calc_data.times[PT_TIME_DHUHR], pt_data);
				}
			}
			else if (time == PT_TIME_ISHA)
			{
				if (pt_data->settings.angles.isha > 0)
				{
					return pt_data->settings.angles.isha;
				}
				else
				{
					return pt_calculate_sun_time_angle(pt_data->calc_data.times[PT_TIME_ISHA] - pt_data->calc_data.times[PT_TIME_DHUHR], pt_data);
				}
			}
		}
	}
	return 0.0;
}

static uint16_t pt_calculate_days_in_month(uint16_t* year, uint16_t* month)
{
	static const uint16_t days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (*month < 1 || *month > 12)
	{
		return 0;
	}

	uint16_t days = days_in_month[*month - 1];
	if (*month == 2 && ((*year % 4 == 0 && *year % 100 != 0) || (*year % 400 == 0)))
	{
		days = 29;
	}

	return days;
}

static bool pt_validate_date(pt_date_t* date)
{
	// http://praytimes.org/calculation
	// The above two astronomical measures can be obtained accurately from The Star Almanac, or can be calculated approximately. 
	// The following algorithm from U.S. Naval Observatory computes the Sun's angular coordinates to an accuracy of about 1 arcminute within two centuries of 2000.
	if (date->year < 2000 || date->year > 2200)
	{
		return false;
	}
	uint16_t days = pt_calculate_days_in_month(&date->year, &date->month);
	if (days == 0 || date->day<1 || date->day>days)
	{
		return false;
	}
	return true;
}