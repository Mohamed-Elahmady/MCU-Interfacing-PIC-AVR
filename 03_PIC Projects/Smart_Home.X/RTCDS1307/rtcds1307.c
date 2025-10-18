/* 
 * File:   rtcds1307.c
 * Author: mohammedel-ahmady
 *
 * Created on October 18, 2025, 10:51 AM
 */

#include "rtcds1307.h"

static rtc_t rtc_temp;

static uint8 RTC_Get_Sec(void);
static uint8 RTC_Get_Min(void);
static uint8 RTC_Get_Hrs(void);
static uint8 RTC_Get_Day(void);
static uint8 RTC_Get_Mon(void);
static uint8 RTC_Get_Year(void);


rtc_t RTC_DS1307_Get_Date_Time(void){
    rtc_temp.Sec = RTC_Get_Sec();
    rtc_temp.Min = RTC_Get_Min();
    rtc_temp.Hrs = RTC_Get_Hrs();
    rtc_temp.Day = RTC_Get_Day();
    rtc_temp.Month = RTC_Get_Mon();
    rtc_temp.Year = RTC_Get_Year();
    
    return rtc_temp;
}

static uint8 RTC_Get_Sec(void){
    uint8 sec = I2C_ReadByteRegister(0x68, 0x00);
    return sec;
}
static uint8 RTC_Get_Min(void){
    uint8 min = I2C_ReadByteRegister(0x68, 0x01);
    return min;
}
static uint8 RTC_Get_Hrs(void){
    uint8 hrs = I2C_ReadByteRegister(0x68, 0x02);
    return hrs;
}
static uint8 RTC_Get_Day(void){
    uint8 day = I2C_ReadByteRegister(0x68, 0x04);
    return day;
}
static uint8 RTC_Get_Mon(void){
    uint8 mon = I2C_ReadByteRegister(0x68, 0x05);
    return mon;
}
static uint8 RTC_Get_Year(void){
    uint8 yrs = I2C_ReadByteRegister(0x68 , 0x06);
    return yrs;
}