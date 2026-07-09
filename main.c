#include "Definition.h"
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

void delay(volatile uint32_t t)
{
    while(t--);
}

void SystemInit(void)
{
    RCC->CR.HSE_ON = 1;

    while(!RCC->CR.HSE_RDY);

    FLASH->ACR.LATENCY = 3;
    FLASH->ACR.PRFTEN  = 1;
    FLASH->ACR.ICEN    = 1;
    FLASH->ACR.DCEN    = 1;

    RCC->PLLCFGR.PLLSRC = 1;     // HSE
    RCC->PLLCFGR.PLLM   = 25;
    RCC->PLLCFGR.PLLN   = 216;
    RCC->PLLCFGR.PLLP   = 0;     // /2

    RCC->CFGR.HPRE  = 0x0;   // AHB = SYSCLK

    RCC->CFGR.PPRE1 = 0x5;   // APB1 = /2 = 54 МГц

    RCC->CFGR.PPRE2 = 0x0;   // APB2 = /1 = 108 МГц

    RCC->CR.PLL_ON = 1;

    while(!RCC->CR.PLL_RDY);

    RCC->CFGR.SW = 0x2;

    while(RCC->CFGR.SWS != 0x2);

}

int main(void)
{
    SystemInit();

    RCC->AHB1ENR.ETHMACEN   = 1;
    RCC->AHB1ENR.ETHMACTXEN = 1;
    RCC->AHB1ENR.ETHMACRXEN = 1;
    
    /* Включение тактирования GPIOI */
    RCC->AHB1ENR.GPIO_IEN = 1;

    /* Настройка PI1 как выхода */

    GPIOI->x_MODER.MODER1 = 1;

    GPIOI->x_OTYPER.OT1 = 0;

    GPIOI->x_OSPEEDR.OSPEEDR1 = 2;

    GPIOI->x_PUPDR.PUPDR1 = 0;

    while(1)
    {
        GPIOI->x_BSRR.BS1 = 1;

        delay(5000000);

        GPIOI->x_BSRR.BR1 = 1;

        delay(5000000);
    }
}