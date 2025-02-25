#include "prayertimes.h"
#include "prayertimes_math.h"

double pt_fix_angle(double a)
{
	return pt_fix(a, 360);
}

double pt_fix_hour(double a)
{
	return pt_fix(a, 24);
}

double pt_fix(double a, double b)
{
	a = a - b * (floor(a / b));
	return (a < 0) ? a + b : a;
}

double pt_degree_to_radian(double degrees)
{
	return (degrees * M_PI) / 180.0;
}

double pt_radian_to_degree(double radians)
{
	return (radians * 180) / M_PI;
}

double pt_sin(double d)
{
	return sin(pt_degree_to_radian(d));
}

double pt_cos(double d)
{
	return cos(pt_degree_to_radian(d));
}

double pt_tan(double d)
{
	return tan(pt_degree_to_radian(d));
}

double pt_arcsin(double d)
{
	return pt_radian_to_degree(asin(d));
}

double pt_arccos(double d)
{
	return pt_radian_to_degree(acos(d));
}

double pt_arctan(double d)
{
	return pt_radian_to_degree(atan(d));
}

double pt_arccot(double x)
{
	return pt_radian_to_degree(atan(1 / x));
}

double pt_arctan2(double x, double y)
{
	return pt_radian_to_degree(atan2(x, y));
}

double pt_jdn(uint16_t year, uint16_t month, uint16_t day, uint16_t hour)
{
	if (month <= 2) {
		year -= 1;
		month += 12;
	};
	double A = floor(year / 100);
	double B = 2 - A + floor(A / 4);

	double JD = floor(365.25 * (year + 4716)) + floor(30.6001 * (month + 1)) + day + B - 1524.5;
	return JD;
}

void pt_double_to_time(double source_time, pt_time_t* destination_time)
{
	double h, m, s;
	destination_time->hour = (uint16_t)source_time;
	h = floor(source_time);
	m = (source_time - h) * 60;
	destination_time->minute = (uint16_t)m;
	s = (m - floor(m)) * 60;
	destination_time->second = (uint16_t)s;
}

double pt_time_to_double(int16_t hour, int16_t minute)
{
	double h, m;
	h = (double)hour;
	m = (double)minute;
	return ((h * 3600.0) + (m * 60.0)) / 3600.0;
}

double pt_time_diff(double time1, double time2)
{
	return pt_fix_hour(time2 - time1);
}

void pt_calculate_sun_position(uint32_t JDN, pt_data_t* pt_data)
{
	double jdn = JDN - 2451544.0 ; // JDN( 2000-01-01 @ 00:00:00 AM ) = 2451544.5  // 2451545.0

	double g = pt_fix_angle(357.529 + (0.98560028 * jdn));
	double q = pt_fix_angle(280.459 + (0.98564736 * jdn));
	double L = pt_fix_angle(q + (1.915 * pt_sin(g)) + (0.020 * pt_sin(2.0 * g)));

	double R = 1.00014 - (0.01671 * pt_cos(g)) - (0.00014 * pt_cos(2.0 * g));
	double e = 23.439 - (0.00000036 * jdn);
	double RA = pt_arctan2(pt_cos(e) * pt_sin(L), pt_cos(L)) / 15.0;

	pt_data->calc_data.sun_positin.declination_sun = pt_arcsin(pt_sin(e) * pt_sin(L));    // declination of the Sun
	pt_data->calc_data.sun_positin.equation_time = (q / 15.0) - pt_fix_hour(RA);          // equation of time
}

double pt_calculate_sun_angle_time(double angle, pt_data_t* pt_data)
{
	return (1.0 / 15.0) * pt_arccos((-pt_sin(angle) - pt_sin(pt_data->settings.location.latitude) * pt_sin(pt_data->calc_data.sun_positin.declination_sun)) / (pt_cos(pt_data->settings.location.latitude) * pt_cos(pt_data->calc_data.sun_positin.declination_sun)));

}

double pt_calculate_asr_angle_time(int factor, pt_data_t* pt_data)
{
	double angle = 0 - pt_arccot(factor + pt_tan(fabs(pt_data->settings.location.latitude - pt_data->calc_data.sun_positin.declination_sun)));
	return (pt_calculate_sun_angle_time(angle, pt_data));
}

double pt_calculate_sun_time_angle(double time, pt_data_t* pt_data)
{
	return pt_arcsin(-pt_cos(15.0 * time) * pt_cos(pt_data->settings.location.latitude) * pt_cos(pt_data->calc_data.sun_positin.declination_sun) - pt_sin(pt_data->settings.location.latitude) * pt_sin(pt_data->calc_data.sun_positin.declination_sun));
}

