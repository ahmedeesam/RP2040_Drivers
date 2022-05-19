#include "RP2040_Spi.h"

void SPI0_vReset()
{
    SPI0_CONTROL_RG_0 = 0;
    SPI0_CONTROL_RG_1 = 0;
    SPI0_CLOCK_PRE_RG = 0;
}

void SPI0_vFrameSIize(U8 u8FrameSizeToPass)
{
    if (u8FrameSizeToPass == DATA_SIZE_4)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_5)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_2_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_6)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_2_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_7)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_8)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_9)
    {
        SPI0_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_DSS_3_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_10)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_11)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_12)
    {
        SPI0_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_13)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_14)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_1_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_15)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_16)
    {
        SPI0_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    } 
}

void SPI0_vFrameFormat(U8 u8FrameFormatToPass)
{
    if (u8FrameFormatToPass == MOTOROLA_FORMAT)
    {
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_FRF_0_B)|(1<<SPI_CONTROL_0_FRF_1_B));
    }
    else    if (u8FrameFormatToPass == TI_FORMAT)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_FRF_0_B));
        //SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_FRF_1_B));
    }
    else    if (u8FrameFormatToPass == MICROWIRE_FORMAT)
    {
        SPI0_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_FRF_0_B)|(1<<SPI_CONTROL_0_FRF_1_B));
    }
}

void SPI0_vMotorolaMode(U8 u8MotorolaModeToPass)
{
    if (u8MotorolaModeToPass == SPO_0_SPH_0)
    {
        SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_SPO_B)|(1<<SPI_CONTROL_0_SPH_B));
    }
    else    if (u8MotorolaModeToPass == SPO_0_SPH_1)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_SPH_B));
        SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_SPO_B));
    }
    else    if (u8MotorolaModeToPass == SPO_1_SPH_0)
    {
        SPI0_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_SPO_B));
        SPI0_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_SPH_B));
    }
    else    if (u8MotorolaModeToPass == SPO_1_SPH_1)
    {
        SPI0_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_SPO_B)|(1<<SPI_CONTROL_0_SPH_B));
    }
}

void SPI0_vClkFreq(U8 u8ScrToPass, U8 u8CpsdvsrToPass)
{
    //SSPCLKOUT(SPI Clock) = (SSPCLK(Internal Clock, Default = 125 Mhz)/(CPSDVSR*(SCR*1)))
    SPI0_CONTROL_RG_0 &= 0xFF;
    SPI0_CONTROL_RG_0 |= (u8ScrToPass<<8); //Set SCR Value
    SPI0_CLOCK_PRE_RG |= (u8CpsdvsrToPass); //Set CPSDVSR Value
}

void SPI0_vEnModeSel(U8 u8SpiModeToPass, U8 u8SOutDisToPass)
{
    if (u8SpiModeToPass == SPI_MASTER_MODE)
    {
        SPI0_CONTROL_RG_1 &= ~(1<<SPI_CONTROL_1_MS_B);
    }
    else    if (u8SpiModeToPass == SPI_SLAVE_MODE)
    {
        SPI0_CONTROL_RG_1 |= (1<<SPI_CONTROL_1_MS_B);
    }

    if (u8SOutDisToPass == SPI_SOD_EN)
    {
        //SPI0_CONTROL_RG_1 &= ~(1<<SPI_CONTROL_1_SOD_B);
    }
    else    if (u8SOutDisToPass == SPI_SOD_DIS)
    {
        SPI0_CONTROL_RG_1 |= (1<<SPI_CONTROL_1_SOD_B);
    }

    SPI0_CONTROL_RG_1 |= (1<<SPI_CONTROL_1_SSE_B); //Enable SPI
}

void SPI0_vInit(U8 u8FrameSize, U8 u8FrameFormat, U8 u8MotorolaMode, U1 u8Scr, U8 u8Cpsdvsr, U8 u8SpiMode, U8 u8SOutDis)
{
    SPI0_vReset();
    SPI0_vFrameSIize(u8FrameSize);            //SET Frame Size
    SPI0_vFrameFormat(u8FrameFormat);       //Choose Format
    SPI0_vMotorolaMode(u8MotorolaMode);
    SPI0_vClkFreq(u8Scr , u8Cpsdvsr);
    SPI0_vEnModeSel(u8SpiMode, u8SOutDis);
}

void SPI1_vReset()
{
    SPI1_CONTROL_RG_0 = 0;
    SPI1_CONTROL_RG_1 = 0;
    SPI1_CLOCK_PRE_RG = 0;
}

void SPI1_vFrameSIize(U8 u8FrameSizeToPass)
{
    if (u8FrameSizeToPass == DATA_SIZE_4)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_5)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_2_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_6)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_2_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_7)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_8)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_3_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_9)
    {
        SPI1_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_DSS_3_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_10)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_11)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_12)
    {
        SPI1_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_2_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_13)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_14)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_1_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_15)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_DSS_0_B));
    }
    else    if (u8FrameSizeToPass == DATA_SIZE_16)
    {
        SPI1_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_DSS_0_B)|(1<<SPI_CONTROL_0_DSS_1_B)|(1<<SPI_CONTROL_0_DSS_2_B)|(1<<SPI_CONTROL_0_DSS_3_B));
    } 
}

void SPI1_vFrameFormat(U8 u8FrameFormatToPass)
{
    if (u8FrameFormatToPass == MOTOROLA_FORMAT)
    {
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_FRF_0_B)|(1<<SPI_CONTROL_0_FRF_1_B));
    }
    else    if (u8FrameFormatToPass == TI_FORMAT)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_FRF_0_B));
        //SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_FRF_1_B));
    }
    else    if (u8FrameFormatToPass == MICROWIRE_FORMAT)
    {
        SPI1_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_FRF_0_B)|(1<<SPI_CONTROL_0_FRF_1_B));
    }
}

void SPI1_vMotorolaMode(U8 u8MotorolaModeToPass)
{
    if (u8MotorolaModeToPass == SPO_0_SPH_0)
    {
        SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_SPO_B)|(1<<SPI_CONTROL_0_SPH_B));
    }
    else    if (u8MotorolaModeToPass == SPO_0_SPH_1)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_SPH_B));
        SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_SPO_B));
    }
    else    if (u8MotorolaModeToPass == SPO_1_SPH_0)
    {
        SPI1_CONTROL_RG_0 |=  ((1<<SPI_CONTROL_0_SPO_B));
        SPI1_CONTROL_RG_0 &= ~((1<<SPI_CONTROL_0_SPH_B));
    }
    else    if (u8MotorolaModeToPass == SPO_1_SPH_1)
    {
        SPI1_CONTROL_RG_0 |= ((1<<SPI_CONTROL_0_SPO_B)|(1<<SPI_CONTROL_0_SPH_B));
    }
}

void SPI1_vClkFreq(U8 u8ScrToPass, U8 u8CpsdvsrToPass)
{
    //SSPCLKOUT(SPI Clock) = (SSPCLK(Internal Clock, Default = 125 Mhz)/(CPSDVSR*(SCR*1)))
    SPI1_CONTROL_RG_0 &= 0xFF;
    SPI1_CONTROL_RG_0 |= (u8ScrToPass<<8); //Set SCR Value
    SPI1_CLOCK_PRE_RG |= (u8CpsdvsrToPass); //Set CPSDVSR Value
}

void SPI1_vEnModeSel(U8 u8SpiModeToPass, U8 u8SOutDisToPass)
{
    if (u8SpiModeToPass == SPI_MASTER_MODE)
    {
        SPI1_CONTROL_RG_1 &= ~(1<<SPI_CONTROL_1_MS_B);
    }
    else    if (u8SpiModeToPass == SPI_SLAVE_MODE)
    {
        SPI1_CONTROL_RG_1 |= (1<<SPI_CONTROL_1_MS_B);
    }

    if (u8SOutDisToPass == SPI_SOD_EN)
    {
        //SPI1_CONTROL_RG_1 &= ~(1<<SPI_CONTROL_1_SOD_B);
    }
    else    if (u8SOutDisToPass == SPI_SOD_DIS)
    {
        SPI1_CONTROL_RG_1 |= (1<<SPI_CONTROL_1_SOD_B);
    }

    SPI1_CONTROL_RG_1 |= (1<<SPI_CONTROL_1_SSE_B); //Enable SPI
}

void SPI1_vInit(U8 u8FrameSize, U8 u8FrameFormat, U8 u8MotorolaMode, U1 u8Scr, U8 u8Cpsdvsr, U8 u8SpiMode, U8 u8SOutDis)
{
    SPI1_vReset();
    SPI1_vFrameSIize(u8FrameSize);            //SET Frame Size
    SPI1_vFrameFormat(u8FrameFormat);       //Choose Format
    SPI1_vMotorolaMode(u8MotorolaMode);
    SPI1_vClkFreq(u8Scr , u8Cpsdvsr);
    SPI1_vEnModeSel(u8SpiMode, u8SOutDis);
}

void SPI1_vSendOneFrame(U16 u16DataToSend)
{
    while ((SPI1_STATUS_RG & (1<<SPI_STATUS_TFE_B)) == 0);
    SPI1_DATA_RG = u16DataToSend;
    while ((SPI1_STATUS_RG & (1<<SPI_STATUS_BSY_B)) != 0);
}

void SPI1_vSendMultipleFrames(U1 *u16ArrDataToSend)
{
    while (*u16ArrDataToSend != '\0')
    {
        while ((SPI1_STATUS_RG & (1<<SPI_STATUS_TFE_B)) == 0);
        SPI1_DATA_RG = *u16ArrDataToSend;
        while ((SPI1_STATUS_RG & (1<<SPI_STATUS_BSY_B)) != 0);
        u16ArrDataToSend++;
    }
}