#include "RP2040_Gpio.h"
#include "RP2040_Arm_Registers.h"

U8 GPIO_u8DigitalInput(U8 u8PinNumber)
{
    U8 input = 0;
    if ((SIO_GPIO_IN_RG & (1<<u8PinNumber)) != 0)
    {
        input = 1;
    }
    else
    {
        input = 0;
    }
    return input;
}

void GPIO_vDigitalOutput(U8 u8PinNumber , U8 u8PinState)
{
    if (u8PinState == 0)
    {
        SIO_GPIO_OUT_CLR_RG |= (1<<u8PinNumber);
    }
    else if (u8PinState == 1)
    {
        SIO_GPIO_OUT_SET_RG |= (1<<u8PinNumber);
    }
}

void GPIO_vOutputEnable(U8 u8PinNumber , U8 u8PinState)
{
    if (u8PinState == 0)
    {
        SIO_GPIO_OE_CLR_RG |= (1<<u8PinNumber);
    }
    else if (u8PinState == 1)
    {
        SIO_GPIO_OE_SET_RG |= (1<<u8PinNumber);
    }    
}

void GPIO_vAltrSelect(U8 u8PinNumber , U8 u8PinState)
{
    SIO_GPIO_OE_CLR_RG  = (1<<u8PinNumber);
    SIO_GPIO_OUT_CLR_RG = (1<<u8PinNumber);
    *((U32*)(CLR_Start + (u8PinNumber*8))) = u8PinState; 
}

void GPIO_vPullUpEnable(U8 u8PinNumber)
{
    *((U32*)(GPIO_Pad_Ctrl_Start + (u8PinNumber*4))) &= ~(1<<GPIOX_Pad_control_PDE_B); //Disabling Pull Down Resistor First
    *((U32*)(GPIO_Pad_Ctrl_Start + (u8PinNumber*4))) |= (1<<GPIOX_Pad_control_PUE_B);
}

void GPIO_vLevelLowProc0IntEnable(U8 u8PinNumber)
{
    if ((u8PinNumber >= 0) && (u8PinNumber <= 7))
    {
        GPIO_PROC0_INT0_ENABLE_RG |= (1<<(u8PinNumber*4));
    }
    else if ((u8PinNumber >= 8) && (u8PinNumber <= 15))
    {
        GPIO_PROC0_INT1_ENABLE_RG |= (1<<((u8PinNumber - 8)*4));
    }
    else if ((u8PinNumber >= 16) && (u8PinNumber <= 23))
    {
        GPIO_PROC0_INT2_ENABLE_RG |= (1<<((u8PinNumber - 16)*4));
    }
    else if ((u8PinNumber >= 24) && (u8PinNumber <= 29))
    {
        GPIO_PROC0_INT3_ENABLE_RG |= (1<<((u8PinNumber - 24)*4));
    }
    NVIC_Interrupt_Clear_Pending_RG = (1<<INTERRUPT_13); 
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_13); // For IO_IRQ 
}

void GPIO_vLevelHighProc0IntEnable(U8 u8PinNumber)
{
    if ((u8PinNumber >= 0) && (u8PinNumber <= 7))
    {
        GPIO_PROC0_INT0_ENABLE_RG |= (1<<((u8PinNumber*4) + 1));
    }
    else if ((u8PinNumber >= 8) && (u8PinNumber <= 15))
    {
        GPIO_PROC0_INT1_ENABLE_RG |= (1<<(((u8PinNumber - 8)*4) + 1));
    }
    else if ((u8PinNumber >= 16) && (u8PinNumber <= 23))
    {
        GPIO_PROC0_INT2_ENABLE_RG |= (1<<(((u8PinNumber - 16)*4) + 1));
    }
    else if ((u8PinNumber >= 24) && (u8PinNumber <= 29))
    {
        GPIO_PROC0_INT3_ENABLE_RG |= (1<<(((u8PinNumber - 24)*4) + 1));
    }   
    NVIC_Interrupt_Clear_Pending_RG = (1<<INTERRUPT_13); 
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_13); // For IO_IRQ 
}

void GPIO_vEdgeLowProc0IntEnable(U8 u8PinNumber)
{
    if ((u8PinNumber >= 0) && (u8PinNumber <= 7))
    {
        GPIO_PROC0_INT0_ENABLE_RG |= (1<<((u8PinNumber*4) + 2));
    }
    else if ((u8PinNumber >= 8) && (u8PinNumber <= 15))
    {
        GPIO_PROC0_INT1_ENABLE_RG |= (1<<(((u8PinNumber - 8)*4) + 2));
    }
    else if ((u8PinNumber >= 16) && (u8PinNumber <= 23))
    {
        GPIO_PROC0_INT2_ENABLE_RG |= (1<<(((u8PinNumber - 16)*4) + 2));
    }
    else if ((u8PinNumber >= 24) && (u8PinNumber <= 29))
    {
        GPIO_PROC0_INT3_ENABLE_RG |= (1<<(((u8PinNumber - 24)*4) + 2));
    } 
    NVIC_Interrupt_Clear_Pending_RG = (1<<INTERRUPT_13); 
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_13); // For IO_IRQ    
}

void GPIO_vEdgeHighProc0IntEnable(U8 u8PinNumber)
{
    if ((u8PinNumber >= 0) && (u8PinNumber <= 7))
    {
        GPIO_PROC0_INT0_ENABLE_RG |= (1<<((u8PinNumber*4) + 3));
    }
    else if ((u8PinNumber >= 8) && (u8PinNumber <= 15))
    {
        GPIO_PROC0_INT1_ENABLE_RG |= (1<<(((u8PinNumber - 8)*4) + 3));
    }
    else if ((u8PinNumber >= 16) && (u8PinNumber <= 23))
    {
        GPIO_PROC0_INT2_ENABLE_RG |= (1<<(((u8PinNumber - 16)*4) + 3));
    }
    else if ((u8PinNumber >= 24) && (u8PinNumber <= 29))
    {
        GPIO_PROC0_INT3_ENABLE_RG |= (1<<(((u8PinNumber - 24)*4) + 3));
    }     
    NVIC_Interrupt_Clear_Pending_RG = (1<<INTERRUPT_13); 
    NVIC_Interrupt_Set_Enable_RG = (1<<INTERRUPT_13); // For IO_IRQ 
}