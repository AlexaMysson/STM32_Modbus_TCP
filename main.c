#include "Definition.h"
#include <stdint.h>

RCC_Type* RCC = (RCC_Type*)0x40023800;
GPIO_Type* GPIOA = (GPIO_Type*)0x40020000;
GPIO_Type* GPIOB = (GPIO_Type*)0x40020400;
GPIO_Type* GPIOC = (GPIO_Type*)0x40020800;
GPIO_Type* GPIOD = (GPIO_Type*)0x40020C00;
ETHERNET_Type* ETH = (ETHERNET_Type*)0x40028000;

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

void ETH_Init(void)
{
    // Сброс контроллера (SWR в DMABMR)
    ETH->DMABMR.SR = 0x1;
    while (ETH->DMABMR.SR);

    // Настройка MACCR
    ETH->MACCR.RE   = 0x1;      // Приём включён
    ETH->MACCR.TE   = 0x1;      // Передача включена
    ETH->MACCR.DM   = 0x1;      // Полный дуплекс
    ETH->MACCR.FES  = 0x1;      // 100 Мбит/с (1 = 100 Мбит)
    ETH->MACCR.IPCO = 0x1;      // автоотключение контрольной суммы IPv4
    ETH->MACCR.APCS = 0x1;      // автоматическое добавление/удаление PAD/CRC
    ETH->MACCR.WD   = 0x0;      // разрешить watchdog
    ETH->MACCR.JD   = 0x0;      // отключить Jumbo

    // Фильтрация кадров (MACFFR)
    ETH->MACFFR.PM  = 0x0;      // не promiscuous
    ETH->MACFFR.HU  = 0x0;      // отключить хэш unicast
    ETH->MACFFR.HM  = 0x0;      // отключить хэш multicast
    ETH->MACFFR.BFD = 0x0;      // пропускать broadcast
    ETH->MACFFR.PCF = 0x0;      // пропускать управляющие кадры

    // Установка MAC-адреса (пример 00:11:22:33:44:55)
    ETH->MACA0LR.MACA0L = 0x33221100;
    ETH->MACA0HR.MACA0H = 0x5544;
    ETH->MACA0HR.MO = 0x1;      // принять кадры для этого адреса

    // Настройка DMA
    ETH->DMABMR.DA   = 0;      // выравнивание адресов
    ETH->DMABMR.DSL  = 0;      // смещение дескрипторов
    ETH->DMABMR.PBL  = 1;      // длина пакетного режима
    ETH->DMABMR.FB   = 1;      // фиксированный приоритет
    ETH->DMABMR.MB   = 1;      // смешанный режим
    ETH->DMABMR.USP  = 0;      // обычный приоритет

    // Включаем приём и передачу через DMAOMR
    ETH->DMAOMR.ST   = 1;      // Start transmission
    ETH->DMAOMR.SR   = 1;      // Start reception
}


int main(void)
{
    SystemInit();
    
    // Включение тактирования
    RCC->AHB1ENR.GPIO_AEN = 0x1;  // GPIOA
    RCC->AHB1ENR.GPIO_BEN = 0x1;  // GPIOB
    RCC->AHB1ENR.GPIO_CEN = 0x1;  // GPIOC
    RCC->AHB1ENR.GPIO_DEN = 0x1;  // GPIOD
    
    RCC->AHB1ENR.ETHMACEN = 0x1;    // Ethernet
    
    // Настройка пинов Ethernet в режим Alternate Function (AF11)
    
    // PA1 - ETH_REF_CLK(AF11)
    GPIOA->x_MODER.MODER1 = 0x2;        // Alternate function
    GPIOA->x_AFRL.AFR1  = 0xB;        // ETH_REF_CLK(AF11)
    GPIOA->x_OSPEEDR.OSPEEDR1 = 0x3;    // High speed
    
    // PA2 - ETH_MDIO(AF11)
    GPIOA->x_MODER.MODER2 = 0x2;        // Alternate function
    GPIOA->x_AFRL.AFR2  = 0xB;        // ETH_MDIO(AF11)
    GPIOA->x_OSPEEDR.OSPEEDR2 = 0x3;    // High speed    
    
    // PA7 - ETH_CRS_DV
    GPIOA->x_MODER.MODER7 = 0x2;        // Alternate function
    GPIOA->x_AFRL.AFR7  = 0xB;        // ETH_CRS_DV(AF11)
    GPIOA->x_OSPEEDR.OSPEEDR7 = 0x3;    // High speed 
    
    // PB11 - ETH_TX_EN
    GPIOB->x_MODER.MODER11 = 0x2;        // Alternate function
    GPIOB->x_AFRH.AFR11  = 0xB;         // ETH_TX_EN(AF11)
    GPIOB->x_OSPEEDR.OSPEEDR11 = 0x3;    // High speed 
    
    // PB12 - ETH_TXD0
    GPIOB->x_MODER.MODER12 = 0x2;        // Alternate function
    GPIOB->x_AFRH.AFR12  = 0xB;       // ETH_TXD0(AF11)
    GPIOB->x_OSPEEDR.OSPEEDR12 = 0x3;    // High speed 
    
    // PB13 - ETH_TXD1
    GPIOB->x_MODER.MODER13 = 0x2;      // Alternate function
    GPIOB->x_AFRH.AFR13  = 0xB;       // ETH_TXD1(AF11)
    GPIOB->x_OSPEEDR.OSPEEDR13 = 0x3;  // High speed 
    
    // PC1  - ETH_MDC
    GPIOC->x_MODER.MODER1 = 0x2;      // Alternate function
    GPIOC->x_AFRL.AFR1  = 0xB;       // ETH_MDC(AF11)
    GPIOC->x_OSPEEDR.OSPEEDR1 = 0x3;  // High speed 
    
    // PC4 - ETH_RXD0
    GPIOC->x_MODER.MODER4 = 0x2;      // Alternate function
    GPIOC->x_AFRL.AFR4  = 0xB;       // ETH_RXD0(AF11)
    GPIOC->x_OSPEEDR.OSPEEDR4 = 0x3;  // High speed 

    // PC5 - ETH_RXD1
    GPIOC->x_MODER.MODER5 = 0x2;      // Alternate function
    GPIOC->x_AFRL.AFR5  = 0xB;       // ETH_ETH_RXD1(AF11)
    GPIOC->x_OSPEEDR.OSPEEDR5 = 0x3;  // High speed 
}  



