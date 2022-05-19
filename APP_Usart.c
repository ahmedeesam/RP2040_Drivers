#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "RP2040_Arm_Registers.h"
#include "RP2040_Gpio.h"
#include "RP2040_Timer.h"
#include "RP2040_Uart.h"
#include "RP2040_Spi.h"
#include "RP2040_Dma.h"
#include "hardware/irq.h"

U32 u8HighLowChecker = 0;
U32 u8HighLowCheck = (1<<25);

/*void __isr isr_irq13(void)
{
     if ((GPIO_PROC0_INT1_STATUS_RG & (1<<GPIO_2_10_18_26_LEVEL_HIGH)) != 0)
     {
        if (u8HighLowChecker == 0) 
        {
            GPIO_vDigitalOutput(25 ,1);
            u8HighLowChecker = 1;
        }
        else if (u8HighLowChecker == 1)
        {
            GPIO_vDigitalOutput(25 ,0);
            u8HighLowChecker = 0;
        }
     }
}*/

/* void __isr isr_irq0(void)
 {
     if (u8HighLowChecker == 0) 
     {
        GPIO_u8DigitalOutput(25 ,1);
        GPIO_u8DigitalOutput(8 ,1);
        u8HighLowChecker = 1;
     }
     else if (u8HighLowChecker == 1)
    {
        GPIO_u8DigitalOutput(25 ,0);
        GPIO_u8DigitalOutput(8 ,0);
        u8HighLowChecker = 0;
    }
    Timer_vSetAlarm0Value(1000*500); 
    Timer_vClearAlarmsFlag(0); //To Stop Entering ISR After Interrupt Execution
 }*/
char MES[] = "Wait For Me";
int main(void)
{
    //Timer_vEnableAlarm0INT();
    //NVIC_Interrupt_Priority_RG_0 = 0;

    Uart_vInit1();
    Uart_DMA_vInit1(10);
    //GPIO_vAltrSelect(8 , 1); // For SPI0
    //GPIO_vAltrSelect(9 , 1);
    //GPIO_vOutputEnable(9 , 1);
    //GPIO_vAltrSelect(10 , 1);
    //GPIO_vOutputEnable(10 , 1);
    //GPIO_vAltrSelect(11 , 1);
    //GPIO_vOutputEnable(11 , 1);
    //SPI1_vInit(DATA_SIZE_8, TI_FORMAT, SPO_0_SPH_0, (U1)200, 250,SPI_MASTER_MODE, SPI_SOD_DIS);

    /*GPIO_vAltrSelect(25 , 5);
    GPIO_vOutputEnable(25 , 1);
    GPIO_vAltrSelect(10 , 5);
    GPIO_vPullUpEnable(10);*/
    //GPIO_vLevelHighProc0IntEnable(10);
    //GPIO_u8OutputEnable(8 , 1);
    //Timer_vSetAlarm0Value(1000*500);
    while (1)
    {  
        Uart_vSerialDebug1_Dma(MES);
        //Uart_vReceiveCh1_Dma();

       // SPI1_vSendOneFrame(0x25); 
    
        //Timer_vSetAlarm0Value(1000);

        //Uart_vSerialDebug1("It Works!");

        /*if (GPIO_u8DigitalInput(10) == 1)    
        {
            DMA_CH1_READ_ADDR = (U32)&u8HighLowChecker;
            DMA_CH1_CTRL_TRIG |= (1<<DMA_CTRL_Channel_Enable);
            while ((DMA_CH1_CTRL_TRIG & (1<<DMA_CTRL_BUSY)));
            DMA_CH1_CTRL_TRIG &= ~(1<<DMA_CTRL_Channel_Enable);             
        }
        else
        {
            DMA_CH1_READ_ADDR = (U32)&u8HighLowCheck;
            //DMA_CH0_CTRL_TRIG = ((1<<DMA_CTRL_Channel_Enable)|(1<<DMA_CTRL_DATA_SIZE_1));
            DMA_CH1_CTRL_TRIG |= (1<<DMA_CTRL_Channel_Enable);
            while ((DMA_CH1_CTRL_TRIG & (1<<DMA_CTRL_BUSY)));
            DMA_CH1_CTRL_TRIG &= ~(1<<DMA_CTRL_Channel_Enable);
        }*/
    }
}