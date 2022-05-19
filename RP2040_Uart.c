#include "RP2040_Uart.h"
#include "RP2040_Gpio.h"

void Uart_vInit1(void)
{
    UART1_Integer_Baud_Rate_RG = 813;
    UART1_Fractional_Baud_Rate_RG = 51;
    GPIO_vAltrSelect(4 , 2); //TX
    GPIO_vAltrSelect(5 , 2); //RX
    UART1_Line_Control_RG |= ((1<<UART_Line_Control_WLEN0_B)|(1<<UART_Line_Control_WLEN1_B));
    UART1_Control_Register_RG |= ((1<<UART_Control_Register_UARTEN_B)|(1<<UART_Control_Register_RXE_B)|(1<<UART_Control_Register_TXE_B));
}

void Uart_DMA_vInit1(U16 u16NumberOfChar)
{
    UART1_DMA_Control_Register_RG |= ((1<<Receive_DMA_Enable)|(1<<Transmit_DMA_Enable));
    //DMA_CH1_READ_ADDR = 0x40038000; //UART Data Register
    DMA_CH1_WRITE_ADDR = 0x40038000; //To Write To Data Register
    DMA_CH1_TRANS_COUNT = u16NumberOfChar;
    DMA_CH1_CTRL_TRIG = 0x00; //For one byte data
}

S8 Uart_vReceiveCh1(void)
{
    while(!(UART1_Flags_RG & (1<<UART_Flag_RXFF_B)));
    return UART1_Data_RG;
}
void Uart_vSendCh1(S8 s8CharToSend)
{
    while(!(UART1_Flags_RG & (1<<UART_Flag_TXFE_B)));
    UART1_Data_RG = s8CharToSend;
}

void Uart_vSerialDebug1(S8 *ps8StringToDisplay)
{
	while (*ps8StringToDisplay != '\0')
	{
		Uart_vSendCh1(*ps8StringToDisplay);
		ps8StringToDisplay++;
	}
}

void Uart_vReceiveCh1_Dma(void)
{
    while(!(UART1_Flags_RG & (1<<UART_Flag_RXFF_B))); //wait until Receive buffer not empty
    DMA_CH1_CTRL_TRIG |= (1<<DMA_CTRL_Channel_Enable); //Trigger/Enable Dma
    while ((DMA_CH1_CTRL_TRIG & (1<<DMA_CTRL_BUSY))); //wait Until Finish
    DMA_CH1_CTRL_TRIG &= ~(1<<DMA_CTRL_Channel_Enable); //Stop Dma
}

void Uart_vSerialDebug1_Dma(S8 *ps8StringToDisplay)
{
    S16 u16NumberOfChar = 10;
    DMA_CH1_READ_ADDR = (U32)ps8StringToDisplay; //UART Data Register
    DMA_CH1_TRANS_COUNT = u16NumberOfChar;
    DMA_CH1_CTRL_TRIG = ((1<<DMA_CTRL_Channel_Enable)|(1<<DMA_CTRL_INCR_READ)|(1<<DMA_CTRL_DATA_SIZE_1));
    /*	while (*ps8StringToDisplay != '\0')
	{
		u16NumberOfChar++;
	}*/
    while ((DMA_CH1_CTRL_TRIG & (1<<DMA_CTRL_BUSY))); //wait Until Finish
    DMA_CH1_CTRL_TRIG &= ~(1<<DMA_CTRL_Channel_Enable); //Stop Dma    
}