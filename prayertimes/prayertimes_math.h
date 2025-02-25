
/*
 *  @file: PrayMath.h
 *  @brief:
 *  @author: Hossein Bakhshipoor <h.bakhshipoor@gmail.com>
 *  @date: 2024-11-24
 *  @company: Behnix Co.
 *  @version: 1.0
 *  @copyright Copyright (c) 2024, Behnix Co.
 *  @license: Proprietary. All rights reserved.
 */

#ifndef PrayMath__h
#define PrayMath__h

#ifdef __cplusplus
extern "C"
{
#endif

#define _USE_MATH_DEFINES

#include <stdint.h>
#include <stdbool.h>
#include <math.h>


double PT_Fix_Angle(double a);
double PT_Fix_Hour(double a);
double PT_Fix(double a, double b);

double PT_DTR(double degrees);
double PT_RTD(double degrees);

double PT_Sin(double d);
double PT_Cos(double d);
double PT_Tan(double d);

double PT_ArcSin(double d);
double PT_ArcCos(double d);
double PT_ArcTan(double d);

double PT_ArcCot(double x);
double PT_ArcTan2(double x, double y);

double PT_JDN(uint16_t year, uint16_t month, uint16_t day, uint16_t hour);

void PT_Double_To_Time(double time, uint16_t* hour, uint16_t* minute);
double PT_Time_To_Double(int16_t hour, int16_t minute);
double PT_Time_Diff(double time1, double time2);

void Calculate_Sun_Position(uint32_t jdn, Pray_Times_t* pray_times);
double Calculate_Sun_Angle_Time(double angle, Pray_Times_t* pray_timesn);
double Calculate_Asr_Angle_Time(int factor, Pray_Times_t* pray_times);
double Calculate_Sun_Time_Angle(double time, Pray_Times_t* pray_times);

#ifdef __cplusplus
}
#endif

#endif