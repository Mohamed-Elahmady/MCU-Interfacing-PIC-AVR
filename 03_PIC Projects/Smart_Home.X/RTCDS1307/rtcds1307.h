/* 
 * File:   rtcds1307.h
 * Author: mohammedel-ahmady
 *
 * Created on October 18, 2025, 10:51 AM
 */

#ifndef RTCDS1307_H
#define	RTCDS1307_H

#include "../configurations/i2c.h"

typedef struct{
    uint8 Hrs;
    uint8 Min;
    uint8 Sec;
    uint8 Year;
    uint8 Month;
    uint8 Day;
}rtc_t;

rtc_t RTC_DS1307_Get_Date_Time(void); 

#endif	/* RTCDS1307_H */

