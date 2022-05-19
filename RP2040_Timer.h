#ifndef RP2040_TIMER_H
#define RP2040_TIMER_H

#include "StdTypes.h"

//Timers Registers addresses
//--------------------------
#define TIMER_BASE_                         0x40054000
#define TIMER_HIGH_WRITE           *((U32*)(TIMER_BASE_ + 0x00)) //Write to bits 63:32 of time always write timelw before timehw
#define TIMER_LOW_WRITE            *((U32*)(TIMER_BASE_ + 0x04)) //Write to bits 31:0 of time writes do not get copied to time until timehw is written
#define TIMER_HIGH_READ            *((U32*)(TIMER_BASE_ + 0x08)) //Read from bits 63:32 of time always read timelr before timehr
#define TIMER_LOW_READ             *((U32*)(TIMER_BASE_ + 0x0C)) //Read from bits 31:0 of time
#define TIMER_ALARM0               *((U32*)(TIMER_BASE_ + 0x10)) //ARM Alarm0 Once Written, Once armed, the alarm fires when TIMER_ALARM0 == TIMELR
//The alarm will disarm itself once it fires, and can be disarmed early using the ARMED status register
#define TIMER_ALARM1               *((U32*)(TIMER_BASE_ + 0x14))
#define TIMER_ALARM2               *((U32*)(TIMER_BASE_ + 0x18))
#define TIMER_ALARM3               *((U32*)(TIMER_BASE_ + 0x1C))
//--------------------------------------------------------------------------------
#define TIMER_ARMED                *((U32*)(TIMER_BASE_ + 0x20))//Indicates the armed/disarmed status of each alarm.
/*A write to the corresponding ALARMx register arms the alarm.
Alarms automatically disarm upon firing, but writing ones here
will disarm immediately without waiting to fire.*/
//--------------------------------------------------------------------------------
#define TIMER_HIGH_RAW_READ        *((U32*)(TIMER_BASE_ + 0x24)) //Raw read from bits 63:32 of time (no side effects)
#define TIMER_LOW_RAW_READ         *((U32*)(TIMER_BASE_ + 0x28)) //Raw read from bits 31:0 of time (no side effects)
#define TIMER_DBEUG_PAUSE          *((U32*)(TIMER_BASE_ + 0x2C)) //Set bits high to enable pause when the corresponding debug ports are active
#define TIMER_PAUSE                *((U32*)(TIMER_BASE_ + 0x30)) //Set high to pause the timer
#define TIMER_RAW_INTERRUPTS       *((U32*)(TIMER_BASE_ + 0x34))
#define TIMER_INTERRUPTS_ENABLE    *((U32*)(TIMER_BASE_ + 0x38))
#define TIMER_INTERRUPTS_FORCE     *((U32*)(TIMER_BASE_ + 0x3C))
#define TIMER_INTERRUPTS_STATUS    *((U32*)(TIMER_BASE_ + 0x40)) //Interrupt status after masking & forcing

//*******************************************************************************************************************************
//TIMER_PAUSE BIT MAP, 31:1 Reserved

#define PAUSE_TIMER (U8)0 //Set high to pause the timer
//*******************************************************************************************************************************
//TIMER_ARMED, TIMER_RAW_INTERRUPTS, TIMER_INTERRUPTS_ENABLE,TIMER_INTERRUPTS_FORCE and TIMER_INTERRUPTS_STATUS BIT MAP

#define TIMER_ARMED_INTER_ALARM_3 (U8)3 
#define TIMER_ARMED_INTER_ALARM_2 (U8)2 
#define TIMER_ARMED_INTER_ALARM_1 (U8)1 
#define TIMER_ARMED_INTER_ALARM_0 (U8)0 
//*******************************************************************************************************************************
//Timer Functions Prototypes
void Timer_vSetDelayValue(U32 u32DelayValue);
void Timer_vEnableAlarm0INT(void);
void Timer_vEnableAlarm1INT(void);
void Timer_vEnableAlarm2INT(void);
void Timer_vEnableAlarm3INT(void);
void Timer_vSetAlarm0Value(U32 u32AlarmValue);
void Timer_vSetAlarm1Value(U32 u32AlarmValue);
void Timer_vSetAlarm2Value(U32 u32AlarmValue);
void Timer_vSetAlarm3Value(U32 u32AlarmValue);
void Timer_vClearAlarmsFlag(U8 u8AlarmToClear); //0 for Alarm_0, 1 for Alarm_1, 2 for Alarm_2, 3 for Alarm_3


#endif