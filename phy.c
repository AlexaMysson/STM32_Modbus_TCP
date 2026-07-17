#include "phy.h"


uint16_t PHY_Read(uint8_t Register)
{
    while(ETH->MACMIIAR.MB);

    ETH->MACMIIAR.CR = 5;
    ETH->MACMIIAR.MR = Register;
    ETH->MACMIIAR.PA = PHY_ADDRESS;
    ETH->MACMIIAR.MW = 0;
    ETH->MACMIIAR.MB = 1;

    while(ETH->MACMIIAR.MB);

    return ETH->MACMIIDR.MD;
}

void PHY_Write(uint8_t Register, uint16_t Data)
{
    while(ETH->MACMIIAR.MB);

    ETH->MACMIIDR.MD = Data;

    ETH->MACMIIAR.CR = 5;
    ETH->MACMIIAR.MR = Register;
    ETH->MACMIIAR.PA = PHY_ADDRESS;
    ETH->MACMIIAR.MW = 1;
    ETH->MACMIIAR.MB = 1;

    while(ETH->MACMIIAR.MB);
}

void PHY_Init(void)
{
    uint16_t ID1;
    uint16_t Status;

    ID1   = PHY_Read(PHY_ID1);

    if(ID1 != 0x0007)
    {
        while(1);
    }

    while(1)
    {
        Status = PHY_Read(PHY_BSR);

        if(Status & (1 << 2))
        {
            break;
        }
    }
}