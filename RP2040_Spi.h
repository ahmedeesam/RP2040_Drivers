#ifndef RP2040_SPI_H
#define RP2040_SPI_H

#include "StdTypes.h"

//Timers Registers addresses
//--------------------------U32
#define SPI0_BASE_                              0x4003c000
#define SPI0_CONTROL_RG_0             *((U32*)(SPI0_BASE_ + 0x000))  //SSPCR0
#define SPI0_CONTROL_RG_1             *((U32*)(SPI0_BASE_ + 0x004))  //SSPCR1
#define SPI0_DATA_RG                  *((U32*)(SPI0_BASE_ + 0x008))  //SSPDR
#define SPI0_STATUS_RG                *((U32*)(SPI0_BASE_ + 0x00C))  //SSPSR
#define SPI0_CLOCK_PRE_RG             *((U32*)(SPI0_BASE_ + 0x010))  //SSPCPSR
#define SPI0_INT_MASK_SET_CLEAR_RG    *((U32*)(SPI0_BASE_ + 0x014))  //SSPIMSC
#define SPI0_RAW_INT_STATUS_RG        *((U32*)(SPI0_BASE_ + 0x018))  //SSPRIS
#define SPI0_MASKED_INT_STATUS_RG     *((U32*)(SPI0_BASE_ + 0x01C))  //SSPMIS
#define SPI0_INT_CLEAR_RG             *((U32*)(SPI0_BASE_ + 0x020))  //SSPICR
#define SPI0_DMA_CONTROL_RG           *((U32*)(SPI0_BASE_ + 0x024))  //SSPDMACR
#define SPI0_PERIPHERAL_ID_RG_0       *((U32*)(SPI0_BASE_ + 0xFE0))  //SSPPERIPHID0
#define SPI0_PERIPHERAL_ID_RG_1       *((U32*)(SPI0_BASE_ + 0xFE4))  //SSPPERIPHID1
#define SPI0_PERIPHERAL_ID_RG_2       *((U32*)(SPI0_BASE_ + 0xFE8))  //SSPPERIPHID2
#define SPI0_PERIPHERAL_ID_RG_3       *((U32*)(SPI0_BASE_ + 0xFEC))  //SSPPERIPHID3
#define SPI0_PRIMECELL_ID_RG_0        *((U32*)(SPI0_BASE_ + 0xFF0))  //SSPPCELLID0
#define SPI0_PRIMECELL_ID_RG_1        *((U32*)(SPI0_BASE_ + 0xFF4))  //SSPPCELLID1
#define SPI0_PRIMECELL_ID_RG_2        *((U32*)(SPI0_BASE_ + 0xFF8))  //SSPPCELLID2
#define SPI0_PRIMECELL_ID_RG_3        *((U32*)(SPI0_BASE_ + 0xFFC))  //SSPPCELLID3

#define SPI1_BASE_                              0x40040000
#define SPI1_CONTROL_RG_0             *((U32*)(SPI1_BASE_ + 0x000))  //SSPCR0
#define SPI1_CONTROL_RG_1             *((U32*)(SPI1_BASE_ + 0x004))  //SSPCR1
#define SPI1_DATA_RG                  *((U32*)(SPI1_BASE_ + 0x008))  //SSPDR
#define SPI1_STATUS_RG                *((U32*)(SPI1_BASE_ + 0x00C))  //SSPSR
#define SPI1_CLOCK_PRE_RG             *((U32*)(SPI1_BASE_ + 0x010))  //SSPCPSR
#define SPI1_INT_MASK_SET_CLEAR_RG    *((U32*)(SPI1_BASE_ + 0x014))  //SSPIMSC
#define SPI1_RAW_INT_STATUS_RG        *((U32*)(SPI1_BASE_ + 0x018))  //SSPRIS
#define SPI1_MASKED_INT_STATUS_RG     *((U32*)(SPI1_BASE_ + 0x01C))  //SSPMIS
#define SPI1_INT_CLEAR_RG             *((U32*)(SPI1_BASE_ + 0x020))  //SSPICR
#define SPI1_DMA_CONTROL_RG           *((U32*)(SPI1_BASE_ + 0x024))  //SSPDMACR
#define SPI1_PERIPHERAL_ID_RG_0       *((U32*)(SPI1_BASE_ + 0xFE0))  //SSPPERIPHID0
#define SPI1_PERIPHERAL_ID_RG_1       *((U32*)(SPI1_BASE_ + 0xFE4))  //SSPPERIPHID1
#define SPI1_PERIPHERAL_ID_RG_2       *((U32*)(SPI1_BASE_ + 0xFE8))  //SSPPERIPHID2
#define SPI1_PERIPHERAL_ID_RG_3       *((U32*)(SPI1_BASE_ + 0xFEC))  //SSPPERIPHID3
#define SPI1_PRIMECELL_ID_RG_0        *((U32*)(SPI1_BASE_ + 0xFF0))  //SSPPCELLID0
#define SPI1_PRIMECELL_ID_RG_1        *((U32*)(SPI1_BASE_ + 0xFF4))  //SSPPCELLID1
#define SPI1_PRIMECELL_ID_RG_2        *((U32*)(SPI1_BASE_ + 0xFF8))  //SSPPCELLID2
#define SPI1_PRIMECELL_ID_RG_3        *((U32*)(SPI1_BASE_ + 0xFFC))  //SSPPCELLID3

//***************************************************************************************************
//SPI_CONTROL_RG_0 BIT MAP

#define SPI_CONTROL_0_DSS_0_B         (U8)0    //Data Size Select: 0011 4-bit data, 0100 5-bit data,
#define SPI_CONTROL_0_DSS_1_B         (U8)1   //0101 6-bit data, 0110 7-bit data, 0111 8-bit data,
#define SPI_CONTROL_0_DSS_2_B         (U8)2  //1000 9-bit data, 1001 10-bit data, 1010 11-bit data, 1011 12-bit data,
#define SPI_CONTROL_0_DSS_3_B         (U8)3 //1100 13-bit data, 1101 14-bit data, 1110 15-bit data, 1111 16-bit data.

#define SPI_CONTROL_0_FRF_0_B         (U8)4  //Frame format: 00 Motorola SPI frame format. 
#define SPI_CONTROL_0_FRF_1_B         (U8)5 //01 TI synchronous serial frame format, 10 National Microwire frame format.

#define SPI_CONTROL_0_SPO_B           (U8)6 //SSPCLKOUT polarity, applicable to Motorola SPI frame format only, 0 for Low in IDLE, 1 for High
#define SPI_CONTROL_0_SPH_B           (U8)7 //SSPCLKOUT phase, applicable to Motorola SPI frame format only

#define SPI_SCR_0              (U8)8 //Serial clock rate
#define SPI_SCR_1              (U8)9
#define SPI_SCR_2              (U8)10
#define SPI_SCR_3              (U8)11
#define SPI_SCR_4              (U8)12
#define SPI_SCR_5              (U8)13
#define SPI_SCR_6              (U8)14
#define SPI_SCR_7              (U8)15

//***************************************************************************************************
//SPI_CONTROL_RG_1 BIT MAP

#define SPI_CONTROL_1_LBM_B         (U8)0 // Loop back mode: 0 Normal serial port operation enabled
#define SPI_CONTROL_1_SSE_B         (U8)1 // Synchronous serial port enable: 0 SSP operation disabled, 1 SSP operation enabled
#define SPI_CONTROL_1_MS_B          (U8)2 // Master or slave mode select.
//0 Device configured as master, default. 1 Device configured as slave, modified only when the PrimeCell SSP is disabled
#define SPI_CONTROL_1_SOD_B         (U8)3 //Slave-mode output disable, Used In multiple-slave systems.

//***************************************************************************************************
//SPI_DATA_RG BIT MAP

/*
DATA :- 15:0, Transmit/Receive FIFO: Read Receive FIFO. Write Transmit FIFO. You must right-justify data when the
PrimeCell SSP is programmed for a data size that is less than 16 bits. Unused bits at the top are ignored by transmit 
logic. The receive logic automatically rightjustifies.
*/

//***************************************************************************************************
//SPI_STATUS_RG BIT MAP

#define SPI_STATUS_TFE_B      (U8)0 //Transmit FIFO empty,    1: Transmit FIFO is empty
#define SPI_STATUS_TNF_B      (U8)1 //Transmit FIFO not full, 1: Transmit FIFO is not full.
#define SPI_STATUS_RNE_B      (U8)2 //Receive FIFO empty,     1: Receive FIFO is empty
#define SPI_STATUS_RFE_B      (U8)3 //Receive FIFO not full,  1: Receive FIFO is not full.
#define SPI_STATUS_BSY_B      (U8)4 //PrimeCell SSP busy flag, 1 SSP is currently transmitting and/or receiving a frame or the
//transmit FIFO is not empty, 0 SSP is idle.

//***************************************************************************************************
//SPI_CLOCK_PRE_RG BIT MAP

/*
7:0 CPSDVSR
Clock prescale divisor. Must be an even number from 2-254,
depending on the frequency of SSPCLK.
The least significant bit always returns zero on reads.
*/

//***************************************************************************************************
//SPI_INT_MASK_SET_CLEAR_RG BIT MAP

#define SPI_INT_MASK_RORIM_B             (U8)0 //Receive overrun interrupt mask
#define SPI_INT_MASK_RTIM_B              (U8)1 //Receive timeout interrupt mask
#define SPI_INT_MASK_RXIM_B              (U8)2 //Receive FIFO interrupt mask
#define SPI_INT_MASK_TXIM_B              (U8)3 //Transmit FIFO interrupt mask

//***************************************************************************************************
//SPI_RAW_INT_STATUS_RG BIT MAP

#define SPI_RAW_INT_ST_RORRIS_B             (U8)0 //State of SSPRORINTR interrupt
#define SPI_RAW_INT_ST_RTRIS_B              (U8)1 //State of SSPRTINTR interrupt
#define SPI_RAW_INT_ST_RXRIS_B              (U8)2 //State of SSPRXINTR interrupt
#define SPI_RAW_INT_ST_TXRIS_B              (U8)3 //State of SSPTXINTR interrupt

//***************************************************************************************************
//SPI_MASKED_INT_STATUS_RG BIT MAP

#define SPI_MASKED_INT_ST_RORMIS_B             (U8)0 //State of receive over run masked interrupt
#define SPI_MASKED_INT_ST_RTMIS_B              (U8)1 //State of receive timeout masked interrupt
#define SPI_MASKED_INT_ST_RXMIS_B              (U8)2 //State of receive  FIFO masked interrupt
#define SPI_MASKED_INT_ST_TXMIS_B              (U8)3 //State of transmit FIFO masked interrupt

//***************************************************************************************************
//SPI_INT_CLEAR_RG BIT MAP

#define SPI_INT_CLEAR_RORIC_B             (U8)0 //Clears the SSPRORINTR interrupt
#define SPI_INT_CLEAR_RTIC_B              (U8)1 //Clears the SSPRTINTR interrupt
//***************************************************************************************************



#define DATA_SIZE_4      (U8)4
#define DATA_SIZE_5      (U8)5
#define DATA_SIZE_6      (U8)6
#define DATA_SIZE_7      (U8)7
#define DATA_SIZE_8      (U8)8
#define DATA_SIZE_9      (U8)9
#define DATA_SIZE_10     (U8)10
#define DATA_SIZE_11     (U8)11
#define DATA_SIZE_12     (U8)12
#define DATA_SIZE_13     (U8)13
#define DATA_SIZE_14     (U8)14
#define DATA_SIZE_15     (U8)15
#define DATA_SIZE_16     (U8)16
#define MOTOROLA_FORMAT  (U8)17
#define TI_FORMAT        (U8)18
#define MICROWIRE_FORMAT (U8)19
#define SPO_0_SPH_0      (U8)20
#define SPO_0_SPH_1      (U8)21
#define SPO_1_SPH_0      (U8)22
#define SPO_1_SPH_1      (U8)23
#define SPI_MASTER_MODE  (U8)24
#define SPI_SLAVE_MODE   (U8)25
#define SPI_SOD_EN       (U8)26
#define SPI_SOD_DIS      (U8)27
//***************************************************************************************************
//SPI Functions Prototypes
void SPI0_vReset();
void SPI0_vFrameSIize(U8 u8FrameSizeToPass);
void SPI0_vFrameFormat(U8 u8FrameFormatToPass);
void SPI0_vMotorolaMode(U8 u8MotorolaModeToPass);
void SPI0_vClkFreq(U8 u8ScrToPass, U8 u8CpsdvsrToPass);
void SPI0_vEnModeSel(U8 u8SpiModeToPass, U8 u8SOutDisToPass);
void SPI0_vInit(U8 u8FrameSize, U8 u8FrameFormat, U8 u8MotorolaMode, U1 u8Scr, U8 u8Cpsdvsr, U8 u8SpiMode, U8 u8SOutDis);
void SPI1_vReset();
void SPI1_vFrameSIize(U8 u8FrameSizeToPass);
void SPI1_vFrameFormat(U8 u8FrameFormatToPass);
void SPI1_vMotorolaMode(U8 u8MotorolaModeToPass);
void SPI1_vClkFreq(U8 u8ScrToPass, U8 u8CpsdvsrToPass);
void SPI1_vEnModeSel(U8 u8SpiModeToPass, U8 u8SOutDisToPass);
void SPI1_vInit(U8 u8FrameSize, U8 u8FrameFormat, U8 u8MotorolaMode, U1 u8Scr, U8 u8Cpsdvsr, U8 u8SpiMode, U8 u8SOutDis);
void SPI1_vSendOneFrame(U16 u16DataToSend);
void SPI1_vSendMultipleFrames(U1 *u16ArrDataToSend);


#endif
