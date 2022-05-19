#ifndef RP2040_Gpio_H
#define RP2040_Gpio_H

#include "StdTypes.h"



//SIO REGISTERS :- Used For Digital Output,Input

#define SIO_GPIO_CPUID_RG      *((U32*)0xd0000000)           //Processor Core Identifier
#define SIO_GPIO_IN_RG         *((U32*)0xd0000004)          //GPIO Read Input regester  (R)
#define SIO_GPIO_OUT_RG        *((U32*)0xd0000010)         //GPIO Output regester (Read Modify Write) (W/R)
#define SIO_GPIO_OUT_SET_RG    *((U32*)0xd0000014)        //GPIO Output Atomic Bit-Set Register (W)
#define SIO_GPIO_OUT_CLR_RG     *((U32*)0xd0000018)       //GPIO Output Atomic Bit-Clear Register (W)
#define SIO_GPIO_OUT_XOR_RG     *((U32*)0xd000001C)      //GPIO Output Atomic XOR Register (W)
#define SIO_GPIO_OE_RG         *((U32*)0Xd0000020)     //GPIO Direction Register (1/0 → output/input) (Read Modify Write) (W/R)
#define SIO_GPIO_OE_SET_RG     *((U32*)0xd0000024)    //GPIO Atomic Bit-Set Direction Register (W)
#define SIO_GPIO_OE_CLR_RG     *((U32*)0xd0000028)   //GPIO Atomic Bit-Clear Direction Register (W)
#define SIO_GPIO_OE_XOR_RG     *((U32*)0xd000002C)  //GPIO Atomic XOR Direction Register (W)


//******************************************************************************************************************
//GPIO REGISTER ADDRESS  :- Used to Select Alternate Functions

#define CLR_Start 0x40014004

#define GPIO0_STATUS_RG 		*((U32*)0x40014000)
#define GPIO0_CTRL_RG			*((U32*)0x40014004)
#define GPIO1_STATUS_RG	        *((U32*)0x40014008)
#define GPIO1_CTRL_RG	        *((U32*)0x4001400C)
#define GPIO2_STATUS_RG	        *((U32*)0x40014010)
#define GPIO2_CTRL_RG		    *((U32*)0x40014014)
#define GPIO3_STATUS_RG	        *((U32*)0x40014018)
#define GPIO3_CTRL_RG		    *((U32*)0x4001401C)
#define GPIO4_STATUS_RG	        *((U32*)0x40014020)
#define GPIO4_CTRL_RG		    *((U32*)0x40014024)
#define GPIO5_STATUS_RG	        *((U32*)0x40014028)
#define GPIO5_CTRL_RG		    *((U32*)0x4001402C)
#define GPIO6_STATUS_RG	        *((U32*)0x40014030)
#define GPIO6_CTRL_RG		    *((U32*)0x40014034)
#define GPIO7_STATUS_RG	        *((U32*)0x40014038)
#define GPIO7_CTRL_RG		    *((U32*)0x4001403C)
#define GPIO8_STATUS_RG	        *((U32*)0x40014040)
#define GPIO8_CTRL_RG		    *((U32*)0x40014044)
#define GPIO9_STATUS_RG	        *((U32*)0x40014048)
#define GPIO9_CTRL_RG		    *((U32*)0x4001404C)
#define GPIO10_STATUS_RG	    *((U32*)0x40014050)
#define GPIO10_CTRL_RG		    *((U32*)0x40014054)
#define GPIO11_STATUS_RG	    *((U32*)0x40014058)
#define GPIO11_CTRL_RG		    *((U32*)0x4001405C)
#define GPIO12_STATUS_RG	    *((U32*)0x40014060)
#define GPIO12_CTRL_RG		    *((U32*)0x40014064)
#define GPIO13_STATUS_RG	    *((U32*)0x40014068)
#define GPIO13_CTRL_RG		    *((U32*)0x4001406C)
#define GPIO14_STATUS_RG		*((U32*)0x40014070)
#define GPIO14_CTRL_RG		    *((U32*)0x40014074)
#define GPIO15_STATUS_RG	    *((U32*)0x40014078)
#define GPIO15_CTRL_RG		    *((U32*)0x4001407C)
#define GPIO16_STATUS_RG	    *((U32*)0x40014080)
#define GPIO16_CTRL_RG		    *((U32*)0x40014084)
#define GPIO17_STATUS_RG	    *((U32*)0x40014088)
#define GPIO17_CTRL_RG		    *((U32*)0x4001408C)
#define GPIO18_STATUS_RG	    *((U32*)0x40014090)
#define GPIO18_CTRL_RG		    *((U32*)0x40014094)
#define GPIO19_STATUS_RG	    *((U32*)0x40014098)
#define GPIO19_CTRL_RG		    *((U32*)0x4001409C)
#define GPIO20_STATUS_RG	    *((U32*)0x400140A0)
#define GPIO20_CTRL_RG		    *((U32*)0x400140A4)
#define GPIO21_STATUS_RG	    *((U32*)0x400140A8)
#define GPIO21_CTRL_RG		    *((U32*)0x400140AC)
#define GPIO22_STATUS_RG	    *((U32*)0x400140B0)
#define GPIO22_CTRL_RG		    *((U32*)0x400140B4)
#define GPIO23_STATUS_RG	    *((U32*)0x400140B8)
#define GPIO23_CTRL_RG		    *((U32*)0x400140BC)
#define GPIO24_STATUS_RG	    *((U32*)0x400140C0)
#define GPIO24_CTRL_RG		    *((U32*)0x400140C4)
#define GPIO25_STATUS_RG	    *((U32*)0x400140C8)
#define GPIO25_CTRL_RG		    *((U32*)0x400140cc)
#define GPIO26_STATUS_RG	    *((U32*)0x400140D0)
#define GPIO26_CTRL_RG		    *((U32*)0x400140D4)
#define GPIO27_STATUS_RG	    *((U32*)0x400140D8)
#define GPIO27_CTRL_RG		    *((U32*)0x400140DC)
#define GPIO28_STATUS_RG	    *((U32*)0x400140E0)
#define GPIO28_CTRL_RG		    *((U32*)0x400140E4)
#define GPIO29_STATUS_RG	    *((U32*)0x400140E8)
#define GPIO29_CTRL_RG		    *((U32*)0x400140EC)
//--------------------------------------------------------------------
//GPIO INTERRUPTS REGISTERS

#define GPIO_INTR0_RG		    *((U32*)0x400140F0)
#define GPIO_INTR1_RG		    *((U32*)0x400140F4)
#define GPIO_INTR2_RG		    *((U32*)0x400140F8)
#define GPIO_INTR3_RG		    *((U32*)0x400140FC)

#define GPIO_PROC0_INT0_ENABLE_RG		    *((U32*)0x40014100)
#define GPIO_PROC0_INT1_ENABLE_RG		    *((U32*)0x40014104)
#define GPIO_PROC0_INT2_ENABLE_RG		    *((U32*)0x40014108)
#define GPIO_PROC0_INT3_ENABLE_RG		    *((U32*)0x4001410C)
#define GPIO_PROC0_INT0_FORCE_RG		    *((U32*)0x40014110)
#define GPIO_PROC0_INT1_FORCE_RG		    *((U32*)0x40014114)
#define GPIO_PROC0_INT2_FORCE_RG		    *((U32*)0x40014118)
#define GPIO_PROC0_INT3_FORCE_RG		    *((U32*)0x4001411C)
#define GPIO_PROC0_INT0_STATUS_RG		    *((U32*)0x40014120)
#define GPIO_PROC0_INT1_STATUS_RG		    *((U32*)0x40014124)
#define GPIO_PROC0_INT2_STATUS_RG		    *((U32*)0x40014128)
#define GPIO_PROC0_INT3_STATUS_RG		    *((U32*)0x4001412C)

#define GPIO_PROC1_INT0_ENABLE_RG		    *((U32*)0x40014130)
#define GPIO_PROC1_INT1_ENABLE_RG		    *((U32*)0x40014134)
#define GPIO_PROC1_INT2_ENABLE_RG		    *((U32*)0x40014138)
#define GPIO_PROC1_INT3_ENABLE_RG		    *((U32*)0x4001413C)
#define GPIO_PROC1_INT0_FORCE_RG		    *((U32*)0x40014140)
#define GPIO_PROC1_INT1_FORCE_RG		    *((U32*)0x40014114)
#define GPIO_PROC1_INT2_FORCE_RG		    *((U32*)0x40014148)
#define GPIO_PROC1_INT3_FORCE_RG		    *((U32*)0x4001414C)
#define GPIO_PROC1_INT0_STATUS_RG		    *((U32*)0x40014150)
#define GPIO_PROC1_INT1_STATUS_RG		    *((U32*)0x40014154)
#define GPIO_PROC1_INT2_STATUS_RG		    *((U32*)0x40014158)
#define GPIO_PROC1_INT3_STATUS_RG		    *((U32*)0x4001415C)
//--------------------------------------------------------------------

//GPIOX_STATUS_RG BIT MAP
#define GPIOX_STATUS_OutFROMPERI_B (U8)8         //output signal from selected peripheral, before register override is applied
#define GPIOX_STATUS_OutTOPAD_B    (U8)9        //output signal to pad after register override is applied
#define GPIOX_STATUS_OEFROMPERI_B  (U8)12      //output enable from selected peripheral, before register override is applied
#define GPIOX_STATUS_OETOPAD_B     (U8)13     //output enable to pad after register override is applied
#define GPIOX_STATUS_INFROMPAD_B   (U8)17    //input signal from pad, before override is applied
#define GPIOX_STATUS_INTOPERI_B    (U8)19   //input signal to peripheral, after override is applied
#define GPIOX_STATUS_IRQFROMPAD_B  (U8)24  //interrupt from pad before override is applied
#define GPIOX_STATUS_IRQTOPROC_B   (U8)26 //interrupt to processors, after override is applied

//--------------------------------------------------------------------
/* GPIO Alternate function table

 *  GPIO   | F1       | F2        | F3       | F4     | F5  | F6   | F7   | F8            | F9
 *  -------|----------|-----------|----------|--------|-----|------|------|---------------|----
 *  0      | SPI0 RX  | UART0 TX  | I2C0 SDA | PWM0 A | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  1      | SPI0 CSn | UART0 RX  | I2C0 SCL | PWM0 B | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  2      | SPI0 SCK | UART0 CTS | I2C1 SDA | PWM1 A | SIO | PIO0 | PIO1 |               | USB VBUS EN
 *  3      | SPI0 TX  | UART0 RTS | I2C1 SCL | PWM1 B | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  4      | SPI0 RX  | UART1 TX  | I2C0 SDA | PWM2 A | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  5      | SPI0 CSn | UART1 RX  | I2C0 SCL | PWM2 B | SIO | PIO0 | PIO1 |               | USB VBUS EN
 *  6      | SPI0 SCK | UART1 CTS | I2C1 SDA | PWM3 A | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  7      | SPI0 TX  | UART1 RTS | I2C1 SCL | PWM3 B | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  8      | SPI1 RX  | UART1 TX  | I2C0 SDA | PWM4 A | SIO | PIO0 | PIO1 |               | USB VBUS EN
 *  9      | SPI1 CSn | UART1 RX  | I2C0 SCL | PWM4 B | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  10     | SPI1 SCK | UART1 CTS | I2C1 SDA | PWM5 A | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  11     | SPI1 TX  | UART1 RTS | I2C1 SCL | PWM5 B | SIO | PIO0 | PIO1 |               | USB VBUS EN
 *  12     | SPI1 RX  | UART0 TX  | I2C0 SDA | PWM6 A | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  13     | SPI1 CSn | UART0 RX  | I2C0 SCL | PWM6 B | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  14     | SPI1 SCK | UART0 CTS | I2C1 SDA | PWM7 A | SIO | PIO0 | PIO1 |               | USB VBUS EN
 *  15     | SPI1 TX  | UART0 RTS | I2C1 SCL | PWM7 B | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  16     | SPI0 RX  | UART0 TX  | I2C0 SDA | PWM0 A | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  17     | SPI0 CSn | UART0 RX  | I2C0 SCL | PWM0 B | SIO | PIO0 | PIO1 |               | USB VBUS EN
 *  18     | SPI0 SCK | UART0 CTS | I2C1 SDA | PWM1 A | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  19     | SPI0 TX  | UART0 RTS | I2C1 SCL | PWM1 B | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  20     | SPI0 RX  | UART1 TX  | I2C0 SDA | PWM2 A | SIO | PIO0 | PIO1 | CLOCK GPIN0   | USB VBUS EN
 *  21     | SPI0 CSn | UART1 RX  | I2C0 SCL | PWM2 B | SIO | PIO0 | PIO1 | CLOCK GPOut0  | USB OVCUR DET
 *  22     | SPI0 SCK | UART1 CTS | I2C1 SDA | PWM3 A | SIO | PIO0 | PIO1 | CLOCK GPIN1   | USB VBUS DET
 *  23     | SPI0 TX  | UART1 RTS | I2C1 SCL | PWM3 B | SIO | PIO0 | PIO1 | CLOCK GPOut1  | USB VBUS EN
 *  24     | SPI1 RX  | UART1 TX  | I2C0 SDA | PWM4 A | SIO | PIO0 | PIO1 | CLOCK GPOut2  | USB OVCUR DET
 *  25     | SPI1 CSn | UART1 RX  | I2C0 SCL | PWM4 B | SIO | PIO0 | PIO1 | CLOCK GPOut3  | USB VBUS DET
 *  26     | SPI1 SCK | UART1 CTS | I2C1 SDA | PWM5 A | SIO | PIO0 | PIO1 |               | USB VBUS EN
 *  27     | SPI1 TX  | UART1 RTS | I2C1 SCL | PWM5 B | SIO | PIO0 | PIO1 |               | USB OVCUR DET
 *  28     | SPI1 RX  | UART0 TX  | I2C0 SDA | PWM6 A | SIO | PIO0 | PIO1 |               | USB VBUS DET
 *  29     | SPI1 CSn | UART0 RX  | I2C0 SCL | PWM6 B | SIO | PIO0 | PIO1 |               | USB VBUS EN
 */

//GPIOX_CTRL_RG BIT MAP

#define GPIOX_CTRL_FUNCSEL0_B  (U8)0 //See GPIO function table for available functions
#define GPIOX_CTRL_FUNCSEL1_B  (U8)1 
#define GPIOX_CTRL_FUNCSEL2_B  (U8)2 
#define GPIOX_CTRL_FUNCSEL3_B  (U8)3 
#define GPIOX_CTRL_FUNCSEL4_B  (U8)4 
#define GPIOX_CTRL_FUNCSEL5_B  (U8)5 
#define GPIOX_CTRL_OutOVER0_B  (U8)8 //00 → drive output from peripheral signal selected by funcsel , 01 → drive output from inverse of
#define GPIOX_CTRL_OutOVER1_B  (U8)9 //peripheral signal selected by funcsel ,  10 → drive output low , 11 → drive output high
#define GPIOX_CTRL_OEOVER0_B   (U8)12 //00 → drive output enable from peripheral signal selected by funcsel , 01 → drive output enable from inverse of 
#define GPIOX_CTRL_OEOVER1_B   (U8)13 //peripheral signal selected by funcsel , 10 → disable output , 11 → enable output
#define GPIOX_CTRL_INOVER0_B   (U8)16 //00 → don’t invert the peri input , 01 → invert the peri input 
#define GPIOX_CTRL_INOVER1_B   (U8)17 //10 → drive peri input low        , 11 → drive peri input high
#define GPIOX_CTRL_IRQOVER0_B  (U8)28 //00 → don’t invert the interrupt , 01 → invert the interrupt 
#define GPIOX_CTRL_IRQOVER1_B  (U8)29 //10 → drive interrupt low        , 11 → drive interrupt high

//******************************************************************************************************************
#define GPIO_Pad_Ctrl_Start                 0x4001C004

#define GPIO_VOLTAGE_SELECT_RG      *((U32*)0x4001C000)
#define GPIO0_Pad_control_RG 		*((U32*)0x4001C004)
#define GPIO1_Pad_control_RG 		*((U32*)0x4001C008)
#define GPIO2_Pad_control_RG 		*((U32*)0x4001C00C)
#define GPIO3_Pad_control_RG 		*((U32*)0x4001C010)
#define GPIO4_Pad_control_RG 		*((U32*)0x4001C014)
#define GPIO5_Pad_control_RG 		*((U32*)0x4001C018)
#define GPIO6_Pad_control_RG 		*((U32*)0x4001C01C)
#define GPIO7_Pad_control_RG 		*((U32*)0x4001C020)
#define GPIO8_Pad_control_RG 		*((U32*)0x4001C024)
#define GPIO9_Pad_control_RG 		*((U32*)0x4001C028)
#define GPIO10_Pad_control_RG 		*((U32*)0x4001C02C)
#define GPIO11_Pad_control_RG 		*((U32*)0x4001C030)
#define GPIO12_Pad_control_RG 		*((U32*)0x4001C034)
#define GPIO13_Pad_control_RG 		*((U32*)0x4001C038)
#define GPIO14_Pad_control_RG 		*((U32*)0x4001C03C)
#define GPIO15_Pad_control_RG 		*((U32*)0x4001C040)
#define GPIO16_Pad_control_RG 		*((U32*)0x4001C044)
#define GPIO17_Pad_control_RG 		*((U32*)0x4001C048)
#define GPIO18_Pad_control_RG 		*((U32*)0x4001C04C)
#define GPIO19_Pad_control_RG 		*((U32*)0x4001C050)
#define GPIO20_Pad_control_RG 		*((U32*)0x4001C054)
#define GPIO21_Pad_control_RG 		*((U32*)0x4001C058)
#define GPIO22_Pad_control_RG 		*((U32*)0x4001C05C)
#define GPIO23_Pad_control_RG 		*((U32*)0x4001C060)
#define GPIO24_Pad_control_RG 		*((U32*)0x4001C064)
#define GPIO25_Pad_control_RG 		*((U32*)0x4001C068)
#define GPIO26_Pad_control_RG 		*((U32*)0x4001C06C)
#define GPIO27_Pad_control_RG 		*((U32*)0x4001C070)
#define GPIO28_Pad_control_RG 		*((U32*)0x4001C074)
#define GPIO29_Pad_control_RG 		*((U32*)0x4001C078)
#define GPIO_SWCLK_RG               *((U32*)0x4001C07C)
#define GPIO_SWD_RG                 *((U32*)0x4001C080)

//-----------------------------------------------------------------------
//GPIO_VOLTAGE_SELECT_RG BIT MAP

#define GPIO_VOLTAGE_SELECT_B  (U8)0 // 0 → Set voltage to 3.3V (DVDD >= 2V5) , 1 → Set voltage to 1.8V (DVDD <= 1V8)

//-----------------------------------------------------------------------
//GPIO_Pad_control_RG , GPIO_SWCLK_control_RG , GPIO_SWD_control_RG BIT MAP

#define GPIOX_Pad_control_SLEWFAST_B (U8)0        //Slew rate control. 1 = Fast, 0 = Slow
#define GPIOX_Pad_control_SCHMITT_B  (U8)1       //Enable schmitt trigger
#define GPIOX_Pad_control_PDE_B      (U8)2      //Pull down enable
#define GPIOX_Pad_control_PUE_B      (U8)3     //Pull up enable
#define GPIOX_Pad_control_DRIVE0_B   (U8)4    //Drive strength :- 00 → 2mA , 01 → 4mA , 10 → 8mA , 11 → 12mA
#define GPIOX_Pad_control_DRIVE1_B   (U8)5   //
#define GPIOX_Pad_control_IE_B       (U8)6  //Input enable
#define GPIOX_Pad_control_OD_B       (U8)7 //Output disable. Has priority over output enable from peripherals

//-----------------------------------------------------------------------
/*
GPIO_INTRX_RG, GPIO_PROC(0,1)_INT0_ENABLE_RG, GPIO_PROC(0,1)_INT0_FORCE_RG, GPIO_PROC(0,1)_INT0_STATUS_RG BIT MAP
INTR0, GPIO_PROC(0,1)_INT0_ENABLE_RG, GPIO_PROC(0,1)_INT0_FORCE_RG, GPIO_PROC(0,1)_INT0_STATUS_RG Is For PIN0 to PIN7
INTR1, GPIO_PROC(0,1)_INT1_ENABLE_RG, GPIO_PROC(0,1)_INT1_FORCE_RG, GPIO_PROC(0,1)_INT1_STATUS_RG Is For PIN8 to PIN15
INTR2, GPIO_PROC(0,1)_INT2_ENABLE_RG, GPIO_PROC(0,1)_INT2_FORCE_RG, GPIO_PROC(0,1)_INT2_STATUS_RG Is For PIN16 to PIN23
INTR3, GPIO_PROC(0,1)_INT3_ENABLE_RG, GPIO_PROC(0,1)_INT3_FORCE_RG, GPIO_PROC(0,1)_INT3_STATUS_RG Is For PIN24 to PIN29
*/
typedef enum GpioINT {
    GPIO_0_8_16_24_LEVEL_LOW,
    GPIO_0_8_16_24_LEVEL_HIGH,
    GPIO_0_8_16_24_EDGE_LOW,
    GPIO_0_8_16_24_EDGE_HIGH,
    GPIO_1_9_17_25_LEVEL_LOW,
    GPIO_1_9_17_25_LEVEL_HIGH,
    GPIO_1_9_17_25_EDGE_LOW,
    GPIO_1_9_17_25_EDGE_HIGH,
    GPIO_2_10_18_26_LEVEL_LOW,
    GPIO_2_10_18_26_LEVEL_HIGH,
    GPIO_2_10_18_26_EDGE_LOW,
    GPIO_2_10_18_26_EDGE_HIGH,
    GPIO_3_11_19_27_LEVEL_LOW,
    GPIO_3_11_19_27_LEVEL_HIGH,
    GPIO_3_11_19_27_EDGE_LOW,
    GPIO_3_11_19_27_EDGE_HIGH,
    GPIO_4_12_20_28_LEVEL_LOW,
    GPIO_4_12_20_28_LEVEL_HIGH,
    GPIO_4_12_20_28_EDGE_LOW,
    GPIO_4_12_20_28_EDGE_HIGH,
    GPIO_5_13_21_29_LEVEL_LOW,
    GPIO_5_13_21_29_LEVEL_HIGH,
    GPIO_5_13_21_29_EDGE_LOW,
    GPIO_5_13_21_29_EDGE_HIGH,
    GPIO_6_14_22_LEVEL_LOW,
    GPIO_6_14_22_LEVEL_HIGH,
    GPIO_6_14_22_EDGE_LOW,
    GPIO_6_14_22_EDGE_HIGH,
    GPIO_7_15_23_LEVEL_LOW,
    GPIO_7_15_23_LEVEL_HIGH,
    GPIO_7_15_23_EDGE_LOW,
    GPIO_7_15_23_EDGE_HIGH,     
}GPIO_INT_MODE;

 //******************************************************************************************************************
//GPIO Functions Prototypes

void GPIO_vOutputEnable (U8 u8PinNumber , U8 u8PinState);
U8   GPIO_u8DigitalInput (U8 u8PinNumber);
void GPIO_vDigitalOutput(U8 u8PinNumber , U8 u8PinState);
void GPIO_vAltrSelect   (U8 u8PinNumber , U8 u8PinState);
void GPIO_vPullUpEnable(U8 u8PinNumber);
void GPIO_vLevelLowProc0IntEnable(U8 u8PinNumber);
void GPIO_vLevelHighProc0IntEnable(U8 u8PinNumber);
void GPIO_vEdgeLowProc0IntEnable(U8 u8PinNumber);
void GPIO_vEdgeHighProc0IntEnable(U8 u8PinNumber);

#endif