#ifndef PHY_H
#define PHY_H

#include <stdint.h>
#include "Definition.h"

#define ETH_MACMIIAR (*(volatile uint32_t *)0x40028010)
#define ETH_MACMIIDR (*(volatile uint32_t *)0x40028014)

#define PHY_ADDRESS             0

#define PHY_BCR                 0
#define PHY_BSR                 1
#define PHY_ID1                 2
#define PHY_ID2                 3

#define PHY_SPECIAL_CONTROL     31

uint16_t PHY_Read(uint8_t Register);

void PHY_Write(uint8_t Register,uint16_t Data); 

void PHY_Init(void); 

#endif