#ifndef RP2040_DMA_H
#define RP2040_DMA_H
#include "StdTypes.h"

#define DMA_BASE_                              0x50000000
#define DMA_CH0_READ_ADDR             *((U32*)(DMA_BASE_ + 0x000))
#define DMA_CH0_WRITE_ADDR            *((U32*)(DMA_BASE_ + 0x004))
#define DMA_CH0_TRANS_COUNT           *((U32*)(DMA_BASE_ + 0x008))
#define DMA_CH0_CTRL_TRIG             *((U32*)(DMA_BASE_ + 0x00C))

#define DMA_CH1_READ_ADDR             *((U32*)(DMA_BASE_ + 0x040))
#define DMA_CH1_WRITE_ADDR            *((U32*)(DMA_BASE_ + 0x044))
#define DMA_CH1_TRANS_COUNT           *((U32*)(DMA_BASE_ + 0x048))
#define DMA_CH1_CTRL_TRIG             *((U32*)(DMA_BASE_ + 0x04C))

typedef enum DMA_CTRL_BIT_MAP {
    DMA_CTRL_Channel_Enable,
    DMA_CTRL_HIGH_PRIORITY,
    DMA_CTRL_DATA_SIZE_0,
    DMA_CTRL_DATA_SIZE_1,
    DMA_CTRL_INCR_READ,
    DMA_CTRL_INCR_WRITE,
    DMA_CTRL_RING_SIZE_0,
    DMA_CTRL_RING_SIZE_1,
    DMA_CTRL_RING_SIZE_2,
    DMA_CTRL_RING_SIZE_3,
    DMA_CTRL_RING_SEL,
    DMA_CTRL_CHAIN_TO_0,
    DMA_CTRL_CHAIN_TO_1,
    DMA_CTRL_CHAIN_TO_2,
    DMA_CTRL_CHAIN_TO_3,
    DMA_CTRL_TREQ_SEL_0,
    DMA_CTRL_TREQ_SEL_1,
    DMA_CTRL_TREQ_SEL_2,
    DMA_CTRL_TREQ_SEL_3,
    DMA_CTRL_TREQ_SEL_4,
    DMA_CTRL_TREQ_SEL_5,
    DMA_CTRL_IRQ_QUIET,
    DMA_CTRL_BSWAP,
    DMA_CTRL_SNIFF_EN,
    DMA_CTRL_BUSY,
    Reserved_25,
    Reserved_26,
    Reserved_27,
    Reserved_28,
    DMA_CTRL_WRITE_ERROR,
    DMA_CTRL_READ_ERROR,
    DMA_CTRL_AHB_ERROR,
}DMA_ENUM;

#endif