#ifndef _PRAYER_TIMES_MATH_H
#define _PRAYER_TIMES_MATH_H

#ifdef __cplusplus
extern "C"
{
#endif

#define _USE_MATH_DEFINES

#include <stdint.h>
#include <stdbool.h>
#include <math.h>


double pt_fix_angle(double a);
double pt_fix_hour(double a);
double pt_fix(double a, double b);

double pt_degree_to_radian(double degrees);
double pt_radian_to_degree(double degrees);

double pt_sin(double d);
double pt_cos(double d);
double pt_tan(double d);

double pt_arcsin(double d);
double pt_arccos(double d);
double pt_arctan(double d);

double pt_arccot(double x);
double pt_arctan2(double x, double y);

double pt_jdn(uint16_t year, uint16_t month, uint16_t day, uint16_t hour);

void pt_double_to_time(double source_time, pt_time_t* destination_time);
double pt_time_to_double(int16_t hour, int16_t minute);
double pt_time_diff(double time1, double time2);

void pt_calculate_sun_position(uint32_t jdn, pt_data_t* pt_data);
double pt_calculate_sun_angle_time(double angle, pt_data_t* pray_timesn);
double pt_calculate_asr_angle_time(int factor, pt_data_t* pt_data);
double pt_calculate_sun_time_angle(double time, pt_data_t* pt_data);

#ifdef __cplusplus
}
#endif

#endif