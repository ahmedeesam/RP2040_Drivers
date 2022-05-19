#ifndef RP2040_ARM_REGISTERS_H
#define RP2040_ARM_REGISTERS_H

#include "StdTypes.h"

//ARM Cortex-M0+ registers

#define Cortex_M0_BASE 0xE0000000
#define NVIC_Interrupt_Set_Enable_RG            *((U32*)(Cortex_M0_BASE + 0xE100))
#define NVIC_Interrupt_Clear_Enable_RG          *((U32*)(Cortex_M0_BASE + 0xE180))
#define NVIC_Interrupt_Set_Pending_Enable_RG    *((U32*)(Cortex_M0_BASE + 0xE200))
#define NVIC_Interrupt_Clear_Pending_RG         *((U32*)(Cortex_M0_BASE + 0xE280))
/*
NVIC_Interrupt_Set_Enable_RG (How To Configure)

Interrupt set-enable bits.
Write:
0 = No effect.
1 = Enable interrupt.
Read:
0 = Interrupt disabled.
1 = Interrupt enabled.
---------------------------------------------------
NVIC_Interrupt_Clear_Enable_RG (How To Configure)

Interrupt clear-enable bits.
Write:
0 = No effect.
1 = Disable interrupt.
Read:
0 = Interrupt disabled.
1 = Interrupt enabled.
---------------------------------------------------
NVIC_Interrupt_Set_Pending_Enable_RG (How To Configure)

Interrupt set-pending bits.
Write:
0 = No effect.
1 = Changes interrupt state to pending.
Read:
0 = Interrupt is not pending.
1 = Interrupt is pending.
Note: Writing 1 to the NVIC_ISPR bit corresponding to:
An interrupt that is pending has no effect.
A disabled interrupt sets the state of that interrupt to
pending.
---------------------------------------------------
NVIC_Interrupt_Clear_Pending_RG (How To Configure)

Interrupt clear-pending bits.
Write:
0 = No effect.
1 = Removes pending state and interrupt.
Read:
0 = Interrupt is not pending.
1 = Interrupt is pending.
---------------------------------------------------
*/
#define NVIC_Interrupt_Priority_RG_0            *((U32*)(Cortex_M0_BASE + 0xE400))
#define NVIC_Interrupt_Priority_RG_1            *((U32*)(Cortex_M0_BASE + 0xE404))
#define NVIC_Interrupt_Priority_RG_2            *((U32*)(Cortex_M0_BASE + 0xE408))
#define NVIC_Interrupt_Priority_RG_3            *((U32*)(Cortex_M0_BASE + 0xE40c))
#define NVIC_Interrupt_Priority_RG_4            *((U32*)(Cortex_M0_BASE + 0xE410))
#define NVIC_Interrupt_Priority_RG_5            *((U32*)(Cortex_M0_BASE + 0xE414))
#define NVIC_Interrupt_Priority_RG_6            *((U32*)(Cortex_M0_BASE + 0xE418))
#define NVIC_Interrupt_Priority_RG_7            *((U32*)(Cortex_M0_BASE + 0xE41C))
#define CPUID                                   *((U32*)(Cortex_M0_BASE + 0xED00))
#define Interrupt_Control_and_State_RG          *((U32*)(Cortex_M0_BASE + 0xED04))
#define Vector_Table_Offset_RG                  *((U32*)(Cortex_M0_BASE + 0xED08))
#define Application_Interrupt_Reset_Control_RG  *((U32*)(Cortex_M0_BASE + 0xED0C))
#define System_Control_RG                       *((U32*)(Cortex_M0_BASE + 0xED10))
#define Configuration_Control_RG                *((U32*)(Cortex_M0_BASE + 0xED14))
#define System_Handler_Priority_RG_2            *((U32*)(Cortex_M0_BASE + 0xED1C))
#define System_Handler_Priority_RG_3            *((U32*)(Cortex_M0_BASE + 0xED20))
#define System_Handler_Control_State_RG         *((U32*)(Cortex_M0_BASE + 0xED24))
//**************************************************************************************************
//NVIC_Interrupt_Set_Enable_RG, NVIC_Interrupt_Clear_Enable_RG, NVIC_Interrupt_Set_Pending_Enable_RG and NVIC_Interrupt_Clear_Pending_RG BIT MAP

#define INTERRUPT_0  (U8)0
#define INTERRUPT_1  (U8)1
#define INTERRUPT_2  (U8)2
#define INTERRUPT_3  (U8)3
#define INTERRUPT_4  (U8)4
#define INTERRUPT_5  (U8)5
#define INTERRUPT_6  (U8)6
#define INTERRUPT_7  (U8)7
#define INTERRUPT_8  (U8)8
#define INTERRUPT_9  (U8)9
#define INTERRUPT_10 (U8)10
#define INTERRUPT_11 (U8)11
#define INTERRUPT_12 (U8)12
#define INTERRUPT_13 (U8)13
#define INTERRUPT_14 (U8)14
#define INTERRUPT_15 (U8)15
#define INTERRUPT_16 (U8)16
#define INTERRUPT_17 (U8)17
#define INTERRUPT_18 (U8)18
#define INTERRUPT_19 (U8)19
#define INTERRUPT_20 (U8)20
#define INTERRUPT_21 (U8)21
#define INTERRUPT_22 (U8)22
#define INTERRUPT_23 (U8)23
#define INTERRUPT_24 (U8)24
#define INTERRUPT_25 (U8)25
#define INTERRUPT_26 (U8)26
#define INTERRUPT_27 (U8)27
#define INTERRUPT_28 (U8)28
#define INTERRUPT_29 (U8)29
#define INTERRUPT_30 (U8)30
#define INTERRUPT_31 (U8)31
//**********************************************************************************************************************
/*
NVIC_Interrupt_Priority_RG_0, NVIC_Interrupt_Priority_RG_1, NVIC_Interrupt_Priority_RG_2,
NVIC_Interrupt_Priority_RG_3, NVIC_Interrupt_Priority_RG_4, NVIC_Interrupt_Priority_RG_5
NVIC_Interrupt_Priority_RG_6, NVIC_Interrupt_Priority_RG_7 BIT MAP

Use These Registers to assign a priority from 0 to 3 to each of the available interrupts.
0 is the highest priority, and 3 is the lowest.
Note: Writing 1 to an NVIC_ICPR bit does not affect the active state of the corresponding interrupt.
These registers are only word-accessible
*/
#define Int_0_4_8_12_16_20_24_28_Priority_B_0  (U8)6
#define Int_0_4_8_12_16_20_24_28_Priority_B_1  (U8)7
#define Int_1_5_9_13_17_21_25_29_Priority_B_0  (U8)14
#define Int_1_5_9_13_17_21_25_29_Priority_B_1  (U8)15
#define Int_2_6_10_14_18_22_26_30_Priority_B_0 (U8)22
#define Int_2_6_10_14_18_22_26_30_Priority_B_1 (U8)23
#define Int_3_7_11_15_19_23_27_31_Priority_B_0 (U8)30
#define Int_3_7_11_15_19_23_27_31_Priority_B_1 (U8)31
//***********************************************************************************************************************
//Interrupt_Control_and_State_RG 



//***********************************************************************************************************************

#endif