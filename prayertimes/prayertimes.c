/*
 *  @file: PrayTimes.c
 *  @brief:
 *  @author: Hossein Bakhshipoor <h.bakhshipoor@gmail.com>
 *  @date: 2024-11-22
 *  @company: Behnix Co.
 *  @version: 1.0
 *  @copyright Copyright (c) 2024, Behnix Co.
 *  @license: Proprietary. All rights reserved.
 */

#include "PrayTimes.h"
#include "PrayMath.h"

Pray_Times_t* BX_PrayTimes;

static void Calculate_Pray_Times(Pray_Times_t* pray_times);
static void Calculate_Imsak(Pray_Times_t* pray_times);
static void Calculate_Fajr(Pray_Times_t* pray_times);
static void Calculate_Sunrise(Pray_Times_t* pray_times);
static void Calculate_Midday(Pray_Times_t* pray_times);
static void Calculate_Duhur(Pray_Times_t* pray_times);
static void Calculate_Asr(Pray_Times_t* pray_times);
static void Calculate_Sunset(Pray_Times_t* pray_times);
static void Calculate_Maghrib(Pray_Times_t* pray_times);
static void Calculate_Isha(Pray_Times_t* pray_times);
static void Calculate_Midnight(Pray_Times_t* pray_times);
static void Calculate_Day_Time(Pray_Times_t* pray_times);
static void Calculate_Night_Time(Pray_Times_t* pray_times);
static void Adjust_Higher_Latitude(Pray_Times_t* pray_times);
static double Get_Method_Angle(Pray_Times_t* pray_times, PT_Time_e time);

const PT_Calc_Method_t PT_Calc_Methods[PT_CM_TOTAL] = {
	// https://www.islamicfinder.org/prayer-times/
	// https://intime.ir/doc.html
	// http://praytimes.org/wiki/Calculation_Methods
	// https://mawaqit.net/
	{
		// 01. Algeria, Ministry of religious affairs and wakfs
		.Refrence = PT_CM_ALGERIA_MOFA,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 17.0},
		// 0
		.Offsets = {0},
	},
	{
		// 02. North America, Islamic Society of North America 
		.Refrence = PT_CM_AMERICA_NORTH,
		//                        Fajr:  15.0°, Maghrib:  0.833°, Isha:  15.0°
		.Angles = {.Imsak = 0.0, .Fajr = 15.0, .Maghrib = 0.833, .Isha = 15.0},
		// 0
		.Offsets = {0},
	},
	{
		// 03. Egypt, General Authority of Survey 
		.Refrence = PT_CM_EGYPT_GAS,
		//                        Fajr:  19.5°, Maghrib:  0.833°, Isha:  17.5°
		.Angles = {.Imsak = 0.0, .Fajr = 19.5, .Maghrib = 0.833, .Isha = 17.5},
		// 0
		.Offsets = {0},
	},
	{
		// 04. France, Muslims of France 
		.Refrence = PT_CM_FRANCE_MUSLIM,
		//                        Fajr:  12.0°, Maghrib:  0.833°, Isha:  12.0°
		.Angles = {.Imsak = 0.0, .Fajr = 12.0, .Maghrib = 0.833, .Isha = 12.0},
		// 0
		.Offsets = {0},
	},
	{
		// 05. Indonesia, Sihat Kemenag
		.Refrence = PT_CM_INDONESIA_SIHAT,
		//                        Fajr:  20.0°, Maghrib:  0.833°, Isha:  18.0°
		.Angles = {.Imsak = 0.0, .Fajr = 20.0, .Maghrib = 0.833, .Isha = 18.0},
		// 0
		.Offsets = {0},
	},
	{
		// 06. Iran, Qom, Leva Institute
		.Refrence = PT_CM_IRAN_QOM,
		//                        Fajr:  16.0°, Maghrib:  4.0°, Isha:  14.0°
		.Angles = {.Imsak = 0.0, .Fajr = 16.0, .Maghrib = 4.0, .Isha = 14.0},
		// 0
		.Offsets = {0},
	},
	{
		// 07. Iran, Tehran, Institute of Geophysics University of Tehran
		.Refrence = PT_CM_IRAN_TEHRAN,
		//                        Fajr:  17.7°, Maghrib:  4.5°, Isha:  14.0°
		.Angles = {.Imsak = 0.0, .Fajr = 17.7, .Maghrib = 4.5, .Isha = 14.0},
		// 0
		.Offsets = {0},
	},
	{
		// 08. Kuwait,
		.Refrence = PT_CM_KUWAIT,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.5°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 17.5},
		// 0
		.Offsets = {0},
	},
	{
		// 09. Malaysia, Jabatan Kemajuan Islam
		.Refrence = PT_CM_MALAYSIA,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  18.0°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 18.0},
		// 0
		.Offsets = {0},
	},
	{
		// 10. Mecca, Umm al - Qura University
		.Refrence = PT_CM_MECCA_UMMALQURA,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  0.833° + 90 minutes
		.Angles = {.Imsak = 0.0, .Fajr = 18.5, .Maghrib = 0.833, .Isha = 0.833},
		// Isha:  90 minutes
		.Offsets = {.Imsak = 0, .Fajr = 0, .Sunrise = 0, .Duhur = 1, .Asr = 0, .Sunset = 0, .Maghrib = 0, .Isha = 90, .Midnight = 0},
	},
	{
		// 11. Morocco, Ministry of wakfs and islamic affairs
		.Refrence = PT_CM_MOROCCO,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 17.0},
		// 0
		.Offsets = {0},
	},
	{
		// 12. Pakistan, University of Science of Karachi
		.Refrence = PT_CM_PAKISTAN_KARACHI,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  18.0°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 18.0},
		// 0
		.Offsets = {0},
	},
	{
		// 13. Qatar,
		.Refrence = PT_CM_QATAR,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  0.833°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 0.833},
		// Isha: 90 minutes
		.Offsets = {.Imsak = 0, .Fajr = 0, .Sunrise = 0, .Duhur = 1, .Asr = 0, .Sunset = 0, .Maghrib = 0, .Isha = 90, .Midnight = 0},
	},
	{
		// 14. Russia, Spiritual Administration of Muslims
		.Refrence = PT_CM_RUSSIA_MUSLIM,
		//                        Fajr:  16.0°, Maghrib:  0.833°, Isha:  15.0°
		.Angles = {.Imsak = 0.0, .Fajr = 16.0, .Maghrib = 0.833, .Isha = 15.0},
		// 0
		.Offsets = {0},
	},
	{
		// 15. Singapore, Majlis Ugama Islam
		.Refrence = PT_CM_SINGAPORE,
		//                        Fajr:  20.0°, Maghrib:  0.833°, Isha:  18.0°
		.Angles = {.Imsak = 0.0, .Fajr = 20.0, .Maghrib = 0.833, .Isha = 18.0},
		// 0
		.Offsets = {0},
	},
	{
		// 16. Tunisia, Ministry of Religious Affairs
		.Refrence = PT_CM_TUNISIA_MOFA,
		//                        Fajr:  10.0°, Maghrib:  0.833°, Isha:  10.0°
		.Angles = {.Imsak = 0.0, .Fajr = 10.0, .Maghrib = 0.833, .Isha = 10.0},
		// 0
		.Offsets = {0},
	},
	{
		// 17. Turkiye, Presidency of Religious Affairs
		.Refrence = PT_CM_TURKIYE_DIYANET,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 17.0},
		// sunrise: -7, dhuhr: 5, asr: 4, maghrib: 7 minutes
		.Offsets = {.Imsak = 0, .Fajr = 0, .Sunrise = -7, .Duhur = 5, .Asr = 4, .Sunset = 0, .Maghrib = 7, .Isha = 0, .Midnight = 0},
	},
	{
		// 18. World, World Islamic League
		.Refrence = PT_CM_WORLD_LEAGUE,
		//                        Fajr:  18.0°, Maghrib:  0.833°, Isha:  17.0°
		.Angles = {.Imsak = 0.0, .Fajr = 18.0, .Maghrib = 0.833, .Isha = 17.0},
		// 0
		.Offsets = {0},
	},
	{
		// 19. Custom
		.Refrence = PT_CM_CUSTOM,
		// 0
		.Angles = {0},
		// 0
		.Offsets = {0},
	},
};

bool PrayTimes_Init(void)
{
	if (BX_PrayTimes != NULL)
	{
		return false;
	}
	BX_PrayTimes = (Pray_Times_t*)calloc(1, sizeof(Pray_Times_t));
	if (BX_PrayTimes == NULL)
	{
		return false;
	}
}


static void Calculate_Pray_Times(Pray_Times_t* pray_times)
{
	// Calculate Sum Position
	Calculate_Sun_Position(PT_JDN(pray_times->System_Data.Date.Year, pray_times->System_Data.Date.Month, pray_times->System_Data.Date.Day, 0), pray_times);

	// Calculate Mid Day
	Calculate_Midday(pray_times);

	// Calculate Duhur
	Calculate_Duhur(pray_times);

	// Calculate Sunrise
	Calculate_Sunrise(pray_times);

	// Calculate Sunset
	Calculate_Sunset(pray_times);

	// Calculate Day Time
	Calculate_Day_Time(pray_times);

	// Calculate Night Time
	Calculate_Night_Time(pray_times);

	// Calculate Fajr
	Calculate_Fajr(pray_times);

	// Calculate Imsak
	Calculate_Imsak(pray_times);

	// Calculate Asr
	Calculate_Asr(pray_times);

	// Maghrib
	Calculate_Maghrib(pray_times);

	// Calculate Isha
	Calculate_Isha(pray_times);

	// Calculate Midnight
	Calculate_Midnight(pray_times);

	// Adjust Higher Latatiude
	Adjust_Higher_Latitude(pray_times);

	for (int time_index = 0; time_index < PT_TIME_TOTAL; time_index++)
	{
		PT_Double_To_Time(pray_times->Calc_Data.Times[time_index], &pray_times->Times[time_index].Hour, &pray_times->Times[time_index].Minute);
	}
}

static void Calculate_Imsak(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	double angle = 0.0;
	double imsak = 0.0;

	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Imsak;
	offset += pray_times->User_Data.Offsets.Imsak;

	if (pray_times->User_Data.Calc_Method == PT_CM_CUSTOM)
	{
		angle = pray_times->User_Data.Angles.Imsak;
	}
	else
	{
		angle = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Imsak;
	}

	if (angle > 0)
	{
		imsak = pray_times->Calc_Data.Times[PT_TIME_DHUHR] - Calculate_Sun_Angle_Time(angle, pray_times);
		imsak += PT_Time_To_Double(0, offset);
	}
	else
	{
		imsak = pray_times->Calc_Data.Times[PT_TIME_FAJR] - PT_Time_To_Double(0, offset);
	}

	pray_times->Calc_Data.Times[PT_TIME_IMSAK] = imsak;
}

static void Calculate_Fajr(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	double angle = 0.0;
	double fajr = 0.0;
	
	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Fajr;
	offset += pray_times->User_Data.Offsets.Fajr;

	if (pray_times->User_Data.Calc_Method == PT_CM_CUSTOM)
	{
		angle = pray_times->User_Data.Angles.Fajr;
	}
	else
	{
		angle = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Fajr;
	}

	if (angle > 0)
	{
		fajr = pray_times->Calc_Data.Times[PT_TIME_DHUHR] - Calculate_Sun_Angle_Time(angle, pray_times);
	}
	else
	{
		fajr = pray_times->Calc_Data.Times[PT_TIME_SUNRISE];
	}
	
	fajr += PT_Time_To_Double(0, offset);
	pray_times->Calc_Data.Times[PT_TIME_FAJR] = fajr;
}

static void Calculate_Sunrise(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	double angle = 0.833 + (0.0347 * sqrt(pray_times->User_Data.Location.Altitude));
	double sunrise = 0.0;

	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Sunrise;
	offset += pray_times->User_Data.Offsets.Sunrise;

	sunrise = pray_times->Calc_Data.Times[PT_TIME_MIDDAY] - Calculate_Sun_Angle_Time(angle, pray_times);
	sunrise += PT_Time_To_Double(0, offset);
	pray_times->Calc_Data.Times[PT_TIME_SUNRISE] = sunrise;
}

static void Calculate_Midday(Pray_Times_t* pray_times)
{
	pray_times->Calc_Data.Times[PT_TIME_MIDDAY] = PT_Fix_Hour(12.0 - pray_times->Calc_Data.Sun_Positin.EquationTime + (pray_times->System_Data.Time_Zone - (pray_times->User_Data.Location.Longitude / 15.0)));
}

static void Calculate_Duhur(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Duhur;
	offset += pray_times->User_Data.Offsets.Duhur;
	double duhur = pray_times->Calc_Data.Times[PT_TIME_MIDDAY] + PT_Time_To_Double(0, offset);
	pray_times->Calc_Data.Times[PT_TIME_DHUHR] = duhur;
}

static void Calculate_Asr(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	int factor = 0.0;
	double asr = 0.0;
	
	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Asr;
	offset += pray_times->User_Data.Offsets.Asr;

	if (pray_times->User_Data.Juristic == PT_J_STANDARD)
	{
		factor = 1;
	}
	else
	{
		factor = 2;
	}
	asr = pray_times->Calc_Data.Times[PT_TIME_DHUHR] + Calculate_Asr_Angle_Time(factor, pray_times);
	asr += PT_Time_To_Double(0, offset);
	pray_times->Calc_Data.Times[PT_TIME_ASR] = asr;
}

static void Calculate_Sunset(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	double angle = 0.833 + (0.0347 * sqrt(pray_times->User_Data.Location.Altitude));
	double sunset = 0.0;

	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Sunset;
	offset += pray_times->User_Data.Offsets.Sunset;

	sunset = pray_times->Calc_Data.Times[PT_TIME_MIDDAY] + Calculate_Sun_Angle_Time(angle, pray_times);
	sunset += PT_Time_To_Double(0, offset);
	pray_times->Calc_Data.Times[PT_TIME_SUNSET] = sunset;
}

static void Calculate_Maghrib(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	double angle = 0.0;
	double maghrib = 0.0;

	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Maghrib;
	offset += pray_times->User_Data.Offsets.Maghrib;

	if (pray_times->User_Data.Calc_Method == PT_CM_CUSTOM)
	{
		angle = pray_times->User_Data.Angles.Maghrib;
	}
	else
	{
		angle = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Maghrib;
	}

	if (angle > 0)
	{
		maghrib = pray_times->Calc_Data.Times[PT_TIME_DHUHR] + Calculate_Sun_Angle_Time(angle, pray_times);
	}
	else
	{
		maghrib = pray_times->Calc_Data.Times[PT_TIME_SUNSET];
	}

	maghrib += PT_Time_To_Double(0, offset);
	pray_times->Calc_Data.Times[PT_TIME_MAGHRIB] = maghrib;
}

static void Calculate_Isha(Pray_Times_t* pray_times)
{
	int16_t offset = 0;
	double angle = 0.0;
	double isha = 0.0;

	offset = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Offsets.Isha;
	offset += pray_times->User_Data.Offsets.Isha;

	if (pray_times->User_Data.Calc_Method == PT_CM_CUSTOM)
	{
		angle = pray_times->User_Data.Angles.Isha;
	}
	else
	{
		angle = PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Isha;
	}

	if (angle > 0)
	{
		isha = pray_times->Calc_Data.Times[PT_TIME_DHUHR] + Calculate_Sun_Angle_Time(angle, pray_times);
	}
	else
	{
		isha = pray_times->Calc_Data.Times[PT_TIME_MAGHRIB];
	}
	
	isha += PT_Time_To_Double(0, offset);
	pray_times->Calc_Data.Times[PT_TIME_ISHA] = isha;
}

static void Calculate_Midnight(Pray_Times_t* pray_times)
{
	double midnight = 0.0;
	if (pray_times->User_Data.MD_Method == PT_MD_STANDARD)
	{
		midnight = pray_times->Calc_Data.Times[PT_TIME_SUNSET] + (PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_SUNSET], pray_times->Calc_Data.Times[PT_TIME_SUNRISE]) / 2);
	}
	else
	{
		midnight = pray_times->Calc_Data.Times[PT_TIME_SUNSET] + (PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_SUNSET], pray_times->Calc_Data.Times[PT_TIME_FAJR]) / 2);
	}

	pray_times->Calc_Data.Times[PT_TIME_MIDNIGHT] = midnight;
}

static void Calculate_Day_Time(Pray_Times_t* pray_times)
{
	double Day_time = 0.0;

	Day_time = PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_SUNRISE], pray_times->Calc_Data.Times[PT_TIME_SUNSET]);

	pray_times->Calc_Data.Times[PT_TIME_DAY] = Day_time;
}

static void Calculate_Night_Time(Pray_Times_t* pray_times)
{
	double night_time = 0.0;
	
	night_time = PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_SUNSET], pray_times->Calc_Data.Times[PT_TIME_SUNRISE]);
	
	pray_times->Calc_Data.Times[PT_TIME_NIGHT] = night_time;
}

static void Adjust_Higher_Latitude(Pray_Times_t* pray_times)
{
	double portion_imsak = 0.0;
	double portion_fajr = 0.0;
	double portion_maghrib = 0.0;
	double portion_isha = 0.0;
	double time_diff = 0.0;

	if (pray_times->User_Data.HL_Method < PT_HL_NIGHTMIDDLE || pray_times->User_Data.HL_Method > PT_HL_ONESEVENTH)
	{
		return;
	}
	else if (pray_times->User_Data.HL_Method == PT_HL_NIGHTMIDDLE)
	{
		portion_imsak = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 2;
		portion_fajr = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 2;
		portion_maghrib = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 2;
		portion_isha = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 2;
	}
	else if (pray_times->User_Data.HL_Method == PT_HL_ANGLEBASED)
	{
		portion_imsak = Get_Method_Angle(pray_times, PT_TIME_IMSAK) * pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 60;
		portion_fajr = Get_Method_Angle(pray_times, PT_TIME_FAJR) * pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 60;
		portion_maghrib = Get_Method_Angle(pray_times, PT_TIME_MAGHRIB) * pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 60;
		portion_isha = Get_Method_Angle(pray_times, PT_TIME_ISHA) * pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 60;
	}
	else if (pray_times->User_Data.HL_Method == PT_HL_ONESEVENTH)
	{
		portion_imsak = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 7;
		portion_fajr = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 7;
		portion_maghrib = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 7;
		portion_isha = pray_times->Calc_Data.Times[PT_TIME_NIGHT] / 7;
	}

	time_diff = PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_IMSAK], pray_times->Calc_Data.Times[PT_TIME_SUNRISE]);
	if (time_diff > portion_imsak)
	{
		pray_times->Calc_Data.Times[PT_TIME_IMSAK] = pray_times->Calc_Data.Times[PT_TIME_SUNRISE] - portion_imsak;
	}

	time_diff = PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_FAJR], pray_times->Calc_Data.Times[PT_TIME_SUNRISE]);
	if (time_diff > portion_fajr)
	{
		pray_times->Calc_Data.Times[PT_TIME_FAJR] = pray_times->Calc_Data.Times[PT_TIME_SUNRISE] - portion_fajr;
	}

	time_diff = PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_SUNSET], pray_times->Calc_Data.Times[PT_TIME_MAGHRIB]);
	if (time_diff > portion_maghrib)
	{
		pray_times->Calc_Data.Times[PT_TIME_MAGHRIB] = pray_times->Calc_Data.Times[PT_TIME_SUNSET] + portion_maghrib;
	}

	time_diff = PT_Time_Diff(pray_times->Calc_Data.Times[PT_TIME_SUNSET], pray_times->Calc_Data.Times[PT_TIME_ISHA]);
	if (time_diff > portion_isha)
	{
		pray_times->Calc_Data.Times[PT_TIME_ISHA] = pray_times->Calc_Data.Times[PT_TIME_SUNSET] + portion_isha;
	}
}

static double Get_Method_Angle(Pray_Times_t* pray_times, PT_Time_e time)
{
	if (pray_times->User_Data.Calc_Method == PT_CM_CUSTOM)
	{
		if (time == PT_TIME_IMSAK)
		{
			if (pray_times->User_Data.Angles.Imsak > 0)
			{
				return pray_times->User_Data.Angles.Imsak;
			}
			else
			{
				return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_IMSAK], pray_times);
			}
		}
		else if (time == PT_TIME_FAJR)
		{
			if (pray_times->User_Data.Angles.Fajr > 0)
			{
				return pray_times->User_Data.Angles.Fajr;
			}
			else
			{
				return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_FAJR], pray_times);
			}
		}
		else if (time == PT_TIME_MAGHRIB)
		{
			if (pray_times->User_Data.Angles.Maghrib > 0)
			{
				return pray_times->User_Data.Angles.Maghrib;
			}
			else
			{
				return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_MAGHRIB], pray_times);
			}
		}
		else if (time == PT_TIME_ISHA)
		{
			if (pray_times->User_Data.Angles.Isha > 0)
			{
				return pray_times->User_Data.Angles.Isha;
			}
			else
			{
				return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_ISHA], pray_times);
			}
		}
	}
	else
	{
		if (pray_times->User_Data.Calc_Method < PT_CM_CUSTOM && pray_times->User_Data.Calc_Method >= PT_CM_ALGERIA_MOFA)
		{
			if (time == PT_TIME_IMSAK)
			{
				if (PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Imsak > 0)
				{
					return PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Imsak;
				}
				else
				{
					return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_DHUHR] - pray_times->Calc_Data.Times[PT_TIME_IMSAK], pray_times);
				}
			}
			else if (time == PT_TIME_FAJR)
			{
				if (PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Fajr > 0)
				{
					return PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Fajr;
				}
				else
				{
					return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_DHUHR] - pray_times->Calc_Data.Times[PT_TIME_FAJR], pray_times);
				}
			}
			else if (time == PT_TIME_MAGHRIB)
			{
				if (PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Maghrib > 0)
				{
					return PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Maghrib;
				}
				else
				{
					return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_MAGHRIB] - pray_times->Calc_Data.Times[PT_TIME_DHUHR], pray_times);
				}
			}
			else if (time == PT_TIME_ISHA)
			{
				if (PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Isha > 0)
				{
					return PT_Calc_Methods[pray_times->User_Data.Calc_Method].Angles.Isha;
				}
				else
				{
					return Calculate_Sun_Time_Angle(pray_times->Calc_Data.Times[PT_TIME_ISHA] - pray_times->Calc_Data.Times[PT_TIME_DHUHR], pray_times);
				}
			}
		}
	}
	return 0.0;
}