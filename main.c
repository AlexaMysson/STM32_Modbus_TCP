#include "Definition.h"
#include <stdint.h>

RCC_Type* RCC = (RCC_Type*)0x40023800;
GPIO_Type* GPIOA = (GPIO_Type*)0x40020000;
GPIO_Type* GPIOB = (GPIO_Type*)0x40020400;
GPIO_Type* GPIOC = (GPIO_Type*)0x40020800;
GPIO_Type* GPIOD = (GPIO_Type*)0x40020C00;
ETHERNET_Type* Ethernet = (ETHERNET_Type*)0x40028000;

void SystemInit(void)
{
    // Включение HSE и ожидание готовности
    RCC->CR.HSE_ON = 0x1;
    while(!RCC->CR.HSE_RDY);
    
    for(volatile int k = 0; k < 10000; ++k);

    // Настройка источника PLL
    RCC->PLLCFGR.PLLSRC = 0x1; // HSE как источник PLL

    RCC->PLLCFGR.PLLSRC = 1;          // HSE как источник
    RCC->PLLCFGR.PLLM   = 25;         // Делитель 25  (25/25 = 1 МГц на вход VCO)
    RCC->PLLCFGR.PLLN   = 432;        // Множитель 432 (1 * 432 = 432 МГц VCO)
    RCC->PLLCFGR.PLLP   = 0;          // Делитель PLLP = 2 (432/2 = 216 МГц)

    // Сброс bypass режима
    RCC->CR.HSE_BYP = 0x0;

    // Настройка делителей шин
    RCC->CFGR.HPRE  = 0;              // AHB = SYSCLK (макс. 216 МГц)
    RCC->CFGR.PPRE1 = 4;              // APB1 = SYSCLK/4 = 54 МГц (макс. 54 МГц)
    RCC->CFGR.PPRE2 = 0;              // APB2 = SYSCLK = 108 МГц (макс. 108 МГц)
    
    // Включение PLL и ожидание готовности
    RCC->CR.PLL_ON = 0x1;
    while(!RCC->CR.PLL_RDY);
    
    for(volatile int k = 0; k < 500000; ++k);

    // Переключение на PLL
    RCC->CFGR.SW = 0x2;
    while(RCC->CFGR.SWS != 0x2);
}


int main(void)
{
    SystemInit();
}
