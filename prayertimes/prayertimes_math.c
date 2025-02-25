
/*
 *  @file: PrayMath.c
 *  @brief:
 *  @author: Hossein Bakhshipoor <h.bakhshipoor@gmail.com>
 *  @date: 2024-11-24
 *  @company: Behnix Co.
 *  @version: 1.0
 *  @copyright Copyright (c) 2024, Behnix Co.
 *  @license: Proprietary. All rights reserved.
 */

#include "PrayTimes.h"
#include "PrayMath.h"

double PT_Fix_Angle(double a)
{
	return PT_Fix(a, 360);
}

double PT_Fix_Hour(double a)
{
	return PT_Fix(a, 24);
}

double PT_Fix(double a, double b)
{
	a = a - b * (floor(a / b));
	return (a < 0) ? a + b : a;
}

double PT_DTR(double degrees)
{
	return (degrees * M_PI) / 180.0;
}

double PT_RTD(double radians)
{
	return (radians * 180) / M_PI;
}

double PT_Sin(double d)
{
	return sin(PT_DTR(d));
}

double PT_Cos(double d)
{
	return cos(PT_DTR(d));
}

double PT_Tan(double d)
{
	return tan(PT_DTR(d));
}

double PT_ArcSin(double d)
{
	return PT_RTD(asin(d));
}

double PT_ArcCos(double d)
{
	return PT_RTD(acos(d));
}

double PT_ArcTan(double d)
{
	return PT_RTD(atan(d));
}

double PT_ArcCot(double x)
{
	return PT_RTD(atan(1 / x));
}

double PT_ArcTan2(double x, double y)
{
	return PT_RTD(atan2(x, y));
}

double PT_JDN(uint16_t year, uint16_t month, uint16_t day, uint16_t hour)
{
	double y, m, d, h;
	y = (double)year;
	m = (double)month;
	d = (double)day;
	h = (double)hour;
	double mm = ((m - 14) / 12);
	double jdn = (1461 * (y + 4800 + mm) / 4) + ((367 * (m - 2 - 12 * mm)) / 12) - ((3 * ((y + 4900 + mm) / 100)) / 4) + d - 32075 + ((h - 12) / 24);
	return jdn;
}

void PT_Double_To_Time(double time, uint16_t* hour, uint16_t* minute)
{
	double h, m, s;
	*hour = (uint16_t)time;
	h = floor(time);
	m = (time - h) * 60;
	*minute = (uint16_t)m;
	s = (m - floor(m)) * 60;
	if (s > 30.0)
	{
		*minute += 1;
		if (*minute > 59)
		{
			*minute = 0;
			*hour += 1;
		}
	}
}

double PT_Time_To_Double(int16_t hour, int16_t minute)
{
	double h, m;
	h = (double)hour;
	m = (double)minute;
	return ((h * 3600.0) + (m * 60.0)) / 3600.0;
}

double PT_Time_Diff(double time1, double time2)
{
	return PT_Fix_Hour(time2 - time1);
}

void Calculate_Sun_Position(uint32_t JDN, Pray_Times_t* pray_times)
{
	double jdn = JDN - 2451544.5; // JDN( 2000-01-01 @ 00:00:00 AM ) = 2451544.5 

	double g = PT_Fix_Angle(357.529 + (0.98560028 * jdn));
	double q = PT_Fix_Angle(280.459 + (0.98564736 * jdn));
	double L = PT_Fix_Angle(q + (1.915 * PT_Sin(g)) + (0.020 * PT_Sin(2.0 * g)));

	double R = 1.00014 - (0.01671 * PT_Cos(g)) - (0.00014 * PT_Cos(2.0 * g));
	double e = 23.439 - (0.00000036 * jdn);
	double RA = PT_ArcTan2(PT_Cos(e) * PT_Sin(L), PT_Cos(L)) / 15.0;

	pray_times->Calc_Data.Sun_Positin.DeclinationSun = PT_ArcSin(PT_Sin(e) * PT_Sin(L));    // declination of the Sun
	pray_times->Calc_Data.Sun_Positin.EquationTime = (q / 15.0) - PT_Fix_Hour(RA);          // equation of time
}

double Calculate_Sun_Angle_Time(double angle, Pray_Times_t* pray_times)
{
	return (1.0 / 15.0) * PT_ArcCos((-PT_Sin(angle) - PT_Sin(pray_times->User_Data.Location.Latitude) * PT_Sin(pray_times->Calc_Data.Sun_Positin.DeclinationSun)) / (PT_Cos(pray_times->User_Data.Location.Latitude) * PT_Cos(pray_times->Calc_Data.Sun_Positin.DeclinationSun)));

}

double Calculate_Asr_Angle_Time(int factor, Pray_Times_t* pray_times)
{
	double angle = 0 - PT_ArcCot(factor + PT_Tan(fabs(pray_times->User_Data.Location.Latitude - pray_times->Calc_Data.Sun_Positin.DeclinationSun)));
	return (Calculate_Sun_Angle_Time(angle, pray_times));
}

double Calculate_Sun_Time_Angle(double time, Pray_Times_t* pray_times)
{
	return PT_ArcSin(-PT_Cos(15.0 * time) * PT_Cos(pray_times->User_Data.Location.Latitude) * PT_Cos(pray_times->Calc_Data.Sun_Positin.DeclinationSun) - PT_Sin(pray_times->User_Data.Location.Latitude) * PT_Sin(pray_times->Calc_Data.Sun_Positin.DeclinationSun));
}

