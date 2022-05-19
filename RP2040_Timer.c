#include "RP2040_Timer.h"
#include "RP2040_Arm_Registers.h"

void Timer_vSetDelayValue(U32 u32DelayValue)
{
    U32 Timer_Low  = TIMER_LOW_RAW_READ;
    U32 Timer_High = TIMER_HIGH_RAW_READ;
    U32 Computed_Delay = u32DelayValue + Timer_Low;
    while(Computed_Delay != Timer_Low)
    {
        Timer_Low  = TIMER_LOW_RAW_READ;
        Timer_High = TIMER_HIGH_RAW_READ;       
    }
}

void Timer_vEnableAlarm0INT(void)
{
    TIMER_INTERRUPTS_ENABLE |= (1<<TIMER_ARMED_INTER_ALARM_0);
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_0);
}

void Timer_vEnableAlarm1INT(void)
{
    TIMER_INTERRUPTS_ENABLE |= (1<<TIMER_ARMED_INTER_ALARM_1);
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_1);
}

void Timer_vEnableAlarm2INT(void)
{
    TIMER_INTERRUPTS_ENABLE |= (1<<TIMER_ARMED_INTER_ALARM_2);
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_2);
}

void Timer_vEnableAlarm3INT(void)
{
    TIMER_INTERRUPTS_ENABLE |= (1<<TIMER_ARMED_INTER_ALARM_3);
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_3);
}

void Timer_vSetAlarm0Value(U32 u32AlarmValue)
{
    U32 Computed_Delay = 0;
    U32 Timer_Low  = TIMER_LOW_RAW_READ;
    U32 Timer_High = TIMER_HIGH_RAW_READ;
    TIMER_ALARM0 = u32AlarmValue + Timer_Low;
}

void Timer_vSetAlarm1Value(U32 u32AlarmValue)
{
    U32 Computed_Delay = 0;
    U32 Timer_Low  = TIMER_LOW_RAW_READ;
    U32 Timer_High = TIMER_HIGH_RAW_READ;
    TIMER_ALARM1 = (u32AlarmValue*1000) + Timer_Low;
}

void Timer_vSetAlarm2Value(U32 u32AlarmValue)
{
    U32 Computed_Delay = 0;
    U32 Timer_Low  = TIMER_LOW_RAW_READ;
    U32 Timer_High = TIMER_HIGH_RAW_READ;
    TIMER_ALARM2 = u32AlarmValue + Timer_Low;
}

void Timer_vSetAlarm3Value(U32 u32AlarmValue)
{
    U32 Computed_Delay = 0;
    U32 Timer_Low  = TIMER_LOW_RAW_READ;
    U32 Timer_High = TIMER_HIGH_RAW_READ;
    TIMER_ALARM3 = u32AlarmValue + Timer_Low;
}

void Timer_vClearAlarmsFlag(U8 u8AlarmToClear)
{
    TIMER_RAW_INTERRUPTS |= (1<<u8AlarmToClear);
}