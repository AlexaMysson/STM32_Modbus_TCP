#include "Definition.h"
#include "phy.h"
#include "ethernet.h"
#include <stdint.h>

RCC_Type  *RCC   = (RCC_Type *)0x40023800;
GPIO_Type *GPIOA = (GPIO_Type *)0x40020000;
GPIO_Type *GPIOB = (GPIO_Type *)0x40020400;
GPIO_Type *GPIOC = (GPIO_Type *)0x40020800;
GPIO_Type *GPIOD = (GPIO_Type *)0x40020C00;
GPIO_Type *GPIOE = (GPIO_Type *)0x40021000;
GPIO_Type *GPIOF = (GPIO_Type *)0x40021400;
GPIO_Type *GPIOG = (GPIO_Type *)0x40021800;
GPIO_Type *GPIOH = (GPIO_Type *)0x40021C00;
GPIO_Type *GPIOI = (GPIO_Type *)0x40022000;
GPIO_Type *GPIOJ = (GPIO_Type *)0x40022400;
GPIO_Type *GPIOK = (GPIO_Type *)0x40022800;
FLASH_Type *FLASH = (FLASH_Type *)0x40023C00;
ETHERNET_Type *ETH = (ETHERNET_Type *)0x40028000;
SYSCFG_Type *SYSCFG = (SYSCFG_Type*)0x40013800;

void delay(volatile uint32_t t)
{
    while (t--);
}

void SystemInit(void)
{
    RCC->CR.HSE_ON = 1;
    while (!RCC->CR.HSE_RDY);

    FLASH->ACR.LATENCY = 3;
    FLASH->ACR.PRFTEN  = 1;

    RCC->PLLCFGR.PLLSRC = 1;
    RCC->PLLCFGR.PLLM   = 25;
    RCC->PLLCFGR.PLLN   = 216;
    RCC->PLLCFGR.PLLP   = 0;

    RCC->CFGR.HPRE  = 0x0;
    RCC->CFGR.PPRE1 = 0x5;
    RCC->CFGR.PPRE2 = 0x0;

    RCC->CR.PLL_ON = 1;
    while (!RCC->CR.PLL_RDY);

    RCC->CFGR.SW = 0x2;
    while (RCC->CFGR.SWS != 0x2);
}

void TactInit(void)
{
    RCC->AHB1ENR.GPIO_AEN = 1;
    RCC->AHB1ENR.GPIO_CEN = 1;
    RCC->AHB1ENR.GPIO_GEN = 1;
    RCC->AHB1ENR.GPIO_IEN = 1;

    RCC->APB2ENR.SYSCFGREN = 1;

    SYSCFG->PMC.MII_RMII_SEL = 1;

    RCC->AHB1ENR.ETHMACEN   = 1;
    RCC->AHB1ENR.ETHMACTXEN = 1;
    RCC->AHB1ENR.ETHMACRXEN = 1;

    for(volatile uint32_t i = 0; i < 100000; i++);
}

void GPIOInit(void)
{
    // PA1 REF_CLK
    GPIOA->x_MODER.MODER1 = 2;
    GPIOA->x_AFRL.AFR1 = 11;
    GPIOA->x_OSPEEDR.OSPEEDR1 = 3;
    GPIOA->x_PUPDR.PUPDR1 = 0;

    // PA2 MDIO
    GPIOA->x_MODER.MODER2 = 2;
    GPIOA->x_AFRL.AFR2 = 11;
    GPIOA->x_OSPEEDR.OSPEEDR2 = 3;
    GPIOA->x_PUPDR.PUPDR2 = 0;

    // PA7 CRS_DV
    GPIOA->x_MODER.MODER7 = 2;
    GPIOA->x_AFRL.AFR7 = 11;
    GPIOA->x_OSPEEDR.OSPEEDR7 = 3;
    GPIOA->x_PUPDR.PUPDR7 = 0;

    // PC1 MDC
    GPIOC->x_MODER.MODER1 = 2;
    GPIOC->x_AFRL.AFR1 = 11;
    GPIOC->x_OSPEEDR.OSPEEDR1 = 3;
    GPIOC->x_PUPDR.PUPDR1 = 0;

    // PC4 RXD0
    GPIOC->x_MODER.MODER4 = 2;
    GPIOC->x_AFRL.AFR4 = 11;
    GPIOC->x_OSPEEDR.OSPEEDR4 = 3;
    GPIOC->x_PUPDR.PUPDR4 = 0;

    // PC5 RXD1
    GPIOC->x_MODER.MODER5 = 2;
    GPIOC->x_AFRL.AFR5 = 11;
    GPIOC->x_OSPEEDR.OSPEEDR5 = 3;
    GPIOC->x_PUPDR.PUPDR5 = 0;

    // PG11 TX_EN
    GPIOG->x_MODER.MODER11 = 2;
    GPIOG->x_AFRH.AFR11 = 11;
    GPIOG->x_OSPEEDR.OSPEEDR11 = 3;
    GPIOG->x_PUPDR.PUPDR11 = 0;

    // PG13 TXD0
    GPIOG->x_MODER.MODER13 = 2;
    GPIOG->x_AFRH.AFR13 = 11;
    GPIOG->x_OSPEEDR.OSPEEDR13 = 3;
    GPIOG->x_PUPDR.PUPDR13 = 0;

    // PG14 TXD1
    GPIOG->x_MODER.MODER14 = 2;
    GPIOG->x_AFRH.AFR14 = 11;
    GPIOG->x_OSPEEDR.OSPEEDR14 = 3;
    GPIOG->x_PUPDR.PUPDR14 = 0;

    // PI1 как выход (для индикации)
    GPIOI->x_MODER.MODER1 = 1;
    GPIOI->x_OTYPER.OT1 = 0;
    GPIOI->x_OSPEEDR.OSPEEDR1 = 2;
    GPIOI->x_PUPDR.PUPDR1 = 0;
}

int main(void)
{
    SystemInit();

    TactInit();

    GPIOInit();
    
    PHY_Init();

    ETH_MAC_Init();

    ETH_SetMACAddress();

    ETH_TXDescriptorInit(); 

    ETH_RXDescriptorInit();

    ETH_SetDMADescriptors();

    ETH_DMAStart();
   
    while(1)
    {
      ETH_Poll();
    }
}