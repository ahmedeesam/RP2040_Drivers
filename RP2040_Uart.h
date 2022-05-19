#ifndef RP2040_UART_H
#define RP2040_UART_H

#include "StdTypes.h"
#include "hardware/address_mapped.h"
#include "hardware/platform_defs.h"
#include "hardware/uart.h"

#include "hardware/structs/uart.h"
#include "hardware/resets.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"

#include "pico/assert.h"
#include "pico.h"
#include "RP2040_Dma.h"

//Uart base addresses
#define UART0_BASe (*((U32*)0x40034000))
#define UART1_BASe (*((U32*)0x40038000))

//Uart0 addresses
#define UART0_Data_RG                 *((U32*)0x40034000)
#define UART0_Receive_Status_RG       *((U32*)0x40034004)
#define UART0_Flags_RG                *((U32*)0x40034018)
#define UART0_Integer_Baud_Rate_RG    *((U32*)0x40034024)
#define UART0_Fractional_Baud_Rate_RG *((U32*)0x40034028)
#define UART0_Line_Control_RG         *((U32*)0x4003402C)
#define UART0_Control_Register_RG     *((U32*)0x40034030)
#define UART0_PeriphID0_RG            *((U32*)0x40034FE0)

//Uart1 addresses
#define UART1_Data_RG                 *((U32*)0x40038000)
#define UART1_Receive_Status_RG       *((U32*)0x40038004)
#define UART1_Flags_RG                *((U32*)0x40038018)
#define UART1_Integer_Baud_Rate_RG    *((U32*)0x40038024)
#define UART1_Fractional_Baud_Rate_RG *((U32*)0x40038028)
#define UART1_Line_Control_RG         *((U32*)0x4003802C)
#define UART1_Control_Register_RG     *((U32*)0x40038030)
#define UART1_DMA_Control_Register_RG *((U32*)0x40038048)
#define UART1_PeriphID0_RG            *((U32*)0x400380E0)

//UART_Data_R BIT MAP :- The FIRST 8 bits for received data 
#define UART_Data_FE_B (U8)8
#define UART_Data_PE_B (U8)9
#define UART_Data_BE_B (U8)10
#define UART_Data_OE_B (U8)11

//UART_Receive_Status_R BIT MAP
#define UART_Status_FE_B (U8)0
#define UART_Status_PE_B (U8)1
#define UART_Status_BE_B (U8)2
#define UART_Status_OE_B (U8)3

//UART_Flag_R BIT MAP
#define UART_Flag_CTS_B  (U8)0                     //Clear to send
#define UART_Flag_DSR_B  (U8)1
#define UART_Flag_DCD_B  (U8)2
#define UART_Flag_BUSY_B (U8)3 
#define UART_Flag_RXFE_B (U8)4                //Reicive Fifo Empty
#define UART_Flag_TXFF_B (U8)5               //Transmit Fifo Full
#define UART_Flag_RXFF_B (U8)6              //Reicive Fifo Full
#define UART_Flag_TXFE_B (U8)7             //Transmit Fifo Empty

//UART_Line_Control_R BIT MAP
#define UART_Line_Control_BRK_B   (U8)0
#define UART_Line_Control_PEN_B   (U8)1       //Parity Enable, 1 enables
#define UART_Line_Control_EPS_B   (U8)2      //Even Parity Select
#define UART_Line_Control_STP2_B  (U8)3     //Enables two stop bits
#define UART_Line_Control_FEN_B   (U8)4    //Fifo Enable, 1 enables
#define UART_Line_Control_WLEN0_B (U8)5   //these two bits specifies word length , b11 = 8 bits b10 = 7 bits b01 = 6 bits b00 = 5 bits
#define UART_Line_Control_WLEN1_B (U8)6
#define UART_Line_Control_SPS_B   (U8)7   //Stick parity select

//UART_Control_Register_R BIT MAP
#define UART_Control_Register_UARTEN_B (U8)0                        //Enable Uart
#define UART_Control_Register_SIREN_B  (U8)1                        //Enable SIR
#define UART_Control_Register_SIRLP_B  (U8)2                       //Enable SIR Low Power
#define UART_Control_Register_LBE_B    (U8)7                        //Loopback enable
#define UART_Control_Register_TXE_B    (U8)8                       //Transmit enable
#define UART_Control_Register_RXE_B    (U8)9                      //Receive enable
#define UART_Control_Register_DTR_B    (U8)10                    //Data transmit ready
#define UART_Control_Register_RTS_B    (U8)11                   //Request to send
#define UART_Control_Register_OUT1_B   (U8)12                 //For DTE this can be used as Data Carrier Detect (DCD)
#define UART_Control_Register_OUT2_B   (U8)13                //For DTE this can be used as Ring Indicator (RI)
#define UART_Control_Register_RTSEN_B  (U8)14              //Request to send Enable
#define UART_Control_Register_CTSEN_B  (U8)15             //Clear to send Enable

//UART1_DMA_Control_Register_RG BIT MAP

typedef enum UART_DMA_CTR_BIT_MAP {
Receive_DMA_Enable,
Transmit_DMA_Enable,
}UART1_DMA_Enum;
 //********************************************************************************************************************************************
//Uart Functions Prototypes
void Uart_vInit1(void);
S8   Uart_vReceiveCh1(void);
void Uart_vSendCh1(S8 s8CharToSend);
void Uart_vSerialDebug1(S8 *ps8StringToDisplay);
void Uart_vReceiveCh1_Dma(void);
void Uart_DMA_vInit1(U16 u16NumberOfChar);
void Uart_vSerialDebug1_Dma(S8 *ps8StringToDisplay);

#endif