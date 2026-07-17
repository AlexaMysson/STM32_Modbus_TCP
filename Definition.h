#ifndef DEFINITION_H
#define DEFINITION_H
#include <stdint.h>

/******************************************************************************
 *
 * RCC registers
 *
 ******************************************************************************/
typedef struct {
  struct type_CR          /*!< RCC clock control register,        Address offset: 0x00 */ 
    {
      volatile uint32_t HSI_ON       :1;  
      volatile uint32_t HSI_RDY      :1;
      volatile uint32_t reserve0     :1;
      volatile uint32_t HSITRIM      :5;
      volatile uint32_t HSICAL       :8;
      volatile uint32_t HSE_ON       :1;
      volatile uint32_t HSE_RDY      :1;
      volatile uint32_t HSE_BYP      :1;
      volatile uint32_t CSS_ON       :1;
      volatile uint32_t reserve1     :4;
      volatile uint32_t PLL_ON       :1;
      volatile uint32_t PLL_RDY      :1;
      volatile uint32_t PLLI2S_ON    :1;
      volatile uint32_t PLLI2S_RDY   :1;
      volatile uint32_t PLLISAI_ON   :1;
      volatile uint32_t PLLISAI_RDY  :1;
      volatile uint32_t reserve2     :2;
    }CR;                         

  struct type_PLLCFGR     /*!< RCC PLL configuration register,    Address offset: 0x04 */
    {
      volatile uint32_t PLLM:6;
      volatile uint32_t PLLN:9;
      volatile uint32_t reserve0:1;
      volatile uint32_t PLLP:2;
      volatile uint32_t reserve1:4;
      volatile uint32_t PLLSRC:1;
      volatile uint32_t reserve2:1;
      volatile uint32_t PLLQ:4;
      volatile uint32_t reserve3:4;
    }PLLCFGR;                                     
 
  struct type_CFGR        /*!< RCC clock configuration register,  Address offset: 0x08 */ 
    {
      volatile uint32_t SW:2;
      volatile uint32_t SWS:2;
      volatile uint32_t HPRE:4;
      volatile uint32_t reserve0:2;
      volatile uint32_t PPRE1:3;
      volatile uint32_t PPRE2:3;
      volatile uint32_t RTCPRE:5;
      volatile uint32_t MCO1:2;
      volatile uint32_t I2SSRC:1;
      volatile uint32_t MCO1_PRE:3;
      volatile uint32_t MCO2_PRE:3;
      volatile uint32_t MCO2:2;
    }CFGR;                        
 
    volatile uint32_t CIR;             /*!< RCC clock interrupt register,                                Address offset: 0x0C */
    volatile uint32_t AHB1RSTR;        /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
    volatile uint32_t AHB2RSTR;        /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
    volatile uint32_t AHB3RSTR;        /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
    volatile uint32_t RESERVED0;       /*!< Reserved, 0x1C                                                                    */
    volatile uint32_t APB1RSTR;        /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
    volatile uint32_t APB2RSTR;        /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
    volatile uint32_t RESERVED1[2];    /*!< Reserved, 0x28-0x2C                                                               */

  struct type_AHB1ENR     /*!< RCC AHB1 peripheral clock register, Address offset: 0x30 */
    {
      volatile uint32_t GPIO_AEN:1;
      volatile uint32_t GPIO_BEN:1;
      volatile uint32_t GPIO_CEN:1;
      volatile uint32_t GPIO_DEN:1;
      volatile uint32_t GPIO_EEN:1;
      volatile uint32_t GPIO_FEN:1;
      volatile uint32_t GPIO_GEN:1;
      volatile uint32_t GPIO_HEN:1;
      volatile uint32_t GPIO_IEN:1;
      volatile uint32_t GPIO_JEN:1;
      volatile uint32_t GPIO_KEN:1;
      volatile uint32_t reserve0:1;
      volatile uint32_t CRC_EN:1;              
      volatile uint32_t reserve1:5;
      volatile uint32_t BKPSRAMEN:1;           
      volatile uint32_t reserve2:1; 
      volatile uint32_t DTCMRAMEN:1;
      volatile uint32_t DMA1EN:1;
      volatile uint32_t DMA2EN:1;
      volatile uint32_t DMA2DEN:1;
      volatile uint32_t reserve3:1;
      volatile uint32_t ETHMACEN:1;
      volatile uint32_t ETHMACTXEN:1;
      volatile uint32_t ETHMACRXEN:1;
      volatile uint32_t ETHMACPTPEN:1;
      volatile uint32_t OTGHSEN:1;
      volatile uint32_t OTGHSULPIEN:1;
      volatile uint32_t reserve4:1;
    }AHB1ENR;                   
  
  struct type_AHB2ENR     /*!< RCC AHB2 peripheral clock register,  Address offset: 0x34 */
    {
      volatile uint32_t DCMIEN:1;
      volatile uint32_t reserve0:3;  
      volatile uint32_t CRYPEN:1;
      volatile uint32_t HASHEN:1;
      volatile uint32_t RNGEN:1;
      volatile uint32_t OTGFSEN:1;
      volatile uint32_t reserve1:24;
    }AHB2ENR;

  struct type_AHB3ENR     /*!< RCC AHB3 peripheral clock register,  Address offset: 0x38 */
    {
      volatile uint32_t FMCEN:1;
      volatile uint32_t QSPIEN:1;
      volatile uint32_t reserve0:30;
    }AHB3ENR;                      
 
    volatile uint32_t RESERVED2; /*!< Reserved, 0x3C */
  
  struct type_APB1ENR     /*!< RCC APB1 peripheral clock enable register,  Address offset: 0x40 */
    {
      volatile uint32_t TIM2EN:1;
      volatile uint32_t TIM3EN:1;
      volatile uint32_t TIM4EN:1;
      volatile uint32_t TIM5EN:1;
      volatile uint32_t TIM6EN:1;
      volatile uint32_t TIM7EN:1;
      volatile uint32_t TIM12EN:1;
      volatile uint32_t TIM13EN:1;
      volatile uint32_t TIM14EN:1;
      volatile uint32_t LPTIM1EN:1;
      volatile uint32_t reserve0:1;
      volatile uint32_t WWDGEN:1;
      volatile uint32_t reserve1:2;
      volatile uint32_t SPI2EN:1;
      volatile uint32_t SPI3EN:1;
      volatile uint32_t SPDIFRXEN:1;
      volatile uint32_t USART2EN:1;
      volatile uint32_t USART3EN:1;
      volatile uint32_t UART4EN:1;
      volatile uint32_t UART5EN:1;
      volatile uint32_t I2C1EN:1;
      volatile uint32_t I2C2EN:1;
      volatile uint32_t I2C3EN:1;
      volatile uint32_t I2C4EN:1;
      volatile uint32_t CAN1EN:1;
      volatile uint32_t CAN2EN:1;
      volatile uint32_t CECEN:1;
      volatile uint32_t PWREN:1;
      volatile uint32_t DACEN:1;
      volatile uint32_t SPI7EN:1;
      volatile uint32_t SPI8EN:1;
    }APB1ENR;                      

  struct type_APB2ENR     /*!< RCC APB2 peripheral clock enable register,  Address offset: 0x44 */
    {
      volatile uint32_t TIM1EN:1;
      volatile uint32_t TIM8EN:1;
      volatile uint32_t reserve0:2;
      volatile uint32_t USART1:1;
      volatile uint32_t USART6:1;
      volatile uint32_t reserve1:2;
      volatile uint32_t ADC1EN:1;
      volatile uint32_t ADC2EN:1;
      volatile uint32_t ADC3EN:1;
      volatile uint32_t SDMMC1EN:1;
      volatile uint32_t SPI1EN:1;
      volatile uint32_t SPI4EN:1;
      volatile uint32_t SYSCFGREN:1;
      volatile uint32_t reserve2:1;
      volatile uint32_t TIM9EN:1;
      volatile uint32_t TIM10EN:1;
      volatile uint32_t TIM11EN:1;  
      volatile uint32_t reserve3:1;
      volatile uint32_t SPI5EN:1;
      volatile uint32_t SPI6EN:1;      
      volatile uint32_t SAI1EN:1;
      volatile uint32_t SAI2EN:1;
      volatile uint32_t reserve4:2;
      volatile uint32_t LTDCEN:1;
      volatile uint32_t reserve5:5;
    }APB2ENR;                      

    volatile uint32_t RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
    volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
    volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
    volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
    volatile uint32_t RESERVED4;     /*!< Reserved, 0x5C                                                                    */
    volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
    volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
    volatile uint32_t RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */ 
  
  struct BDCR_Type            /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  {
    volatile uint32_t LSEON:1;
    volatile uint32_t LSERDY:1;
    volatile uint32_t LSEBYP:1;
    volatile uint32_t LSEDRV:2;    
    volatile uint32_t reserve:3;
    volatile uint32_t RTCSEL:2;
    volatile uint32_t reserve1:5;
    volatile uint32_t RTCEN:1;
    volatile uint32_t BDRST:1;
    volatile uint32_t reserve2:15;
  }BDCR;
 
  struct CSR_Type               /*!< RCC clock control & status register,                       Address offset: 0x74 */
  {
    volatile uint32_t LSION:1;
    volatile uint32_t LSIRDY:1;
    volatile uint32_t reserve:22;
    volatile uint32_t RMVF:1;
    volatile uint32_t BORRSTF:1;
    volatile uint32_t PINRSTF:1;
    volatile uint32_t PORRSTF:1;
    volatile uint32_t SFTRSTF:1;
    volatile uint32_t WDGRSTF:1;
    volatile uint32_t WWDGRSTF:1;
    volatile uint32_t LPWRRSTF:1;
  }CSR;
  
    volatile uint32_t RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
    volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
    volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
    volatile uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
    volatile uint32_t DCKCFGR1;    /*!< RCC dedicated clocks configuration register 1,                 Address offset: 0x8C */
    volatile uint32_t DCKCFGR2;    /*!< RCC dedicated clocks configuration register 2,                 Address offset: 0x90 */
  
}RCC_Type;

/******************************************************************************
 *
 * GPIO registers
 *
 ******************************************************************************/
typedef struct
{
    struct type_MODER
  {
    volatile uint32_t MODER0:2;
    volatile uint32_t MODER1:2;
    volatile uint32_t MODER2:2;
    volatile uint32_t MODER3:2;
    volatile uint32_t MODER4:2;
    volatile uint32_t MODER5:2;
    volatile uint32_t MODER6:2;
    volatile uint32_t MODER7:2;
    volatile uint32_t MODER8:2;
    volatile uint32_t MODER9:2;
    volatile uint32_t MODER10:2;
    volatile uint32_t MODER11:2;
    volatile uint32_t MODER12:2;
    volatile uint32_t MODER13:2;
    volatile uint32_t MODER14:2;
    volatile uint32_t MODER15:2;
   }x_MODER; /*!< GPIO port mode register,   Address offset: 0x00 */
     
   struct type_OTYPER
  {
    volatile uint32_t OT0:1;
    volatile uint32_t OT1:1;
    volatile uint32_t OT2:1;
    volatile uint32_t OT3:1;
    volatile uint32_t OT4:1;
    volatile uint32_t OT5:1;
    volatile uint32_t OT6:1;
    volatile uint32_t OT7:1;
    volatile uint32_t OT8:1;
    volatile uint32_t OT9:1;
    volatile uint32_t OT10:1;
    volatile uint32_t OT11:1;
    volatile uint32_t OT12:1;
    volatile uint32_t OT13:1;
    volatile uint32_t OT14:1;
    volatile uint32_t OT15:1;
    volatile uint32_t reserve:16;
   }x_OTYPER; /*!< GPIO port output type register,   Address offset: 0x04 */
   
    struct type_OSPEEDR
    {
      volatile uint32_t OSPEEDR0:2;
      volatile uint32_t OSPEEDR1:2;
      volatile uint32_t OSPEEDR2:2;
      volatile uint32_t OSPEEDR3:2;
      volatile uint32_t OSPEEDR4:2;
      volatile uint32_t OSPEEDR5:2;
      volatile uint32_t OSPEEDR6:2;
      volatile uint32_t OSPEEDR7:2;
      volatile uint32_t OSPEEDR8:2;
      volatile uint32_t OSPEEDR9:2;
      volatile uint32_t OSPEEDR10:2;
      volatile uint32_t OSPEEDR11:2;
      volatile uint32_t OSPEEDR12:2;
      volatile uint32_t OSPEEDR13:2;
      volatile uint32_t OSPEEDR14:2;
      volatile uint32_t OSPEEDR15:2;
     }x_OSPEEDR; /*!< GPIO port output speed register,   Address offset: 0x08 */
     
    struct type_PUPDR
    {
      volatile uint32_t PUPDR0:2;
      volatile uint32_t PUPDR1:2;
      volatile uint32_t PUPDR2:2;
      volatile uint32_t PUPDR3:2;
      volatile uint32_t PUPDR4:2;
      volatile uint32_t PUPDR5:2;
      volatile uint32_t PUPDR6:2;
      volatile uint32_t PUPDR7:2;
      volatile uint32_t PUPDR8:2;
      volatile uint32_t PUPDR9:2;
      volatile uint32_t PUPDR10:2;
      volatile uint32_t PUPDR11:2;
      volatile uint32_t PUPDR12:2;
      volatile uint32_t PUPDR13:2;
      volatile uint32_t PUPDR14:2;
      volatile uint32_t PUPDR15:2;
     }x_PUPDR; /*!< GPIO port pull-up/pull-down register,   Address offset: 0x0C */
     
       struct type_IDR
    {
      volatile uint32_t IDR0:1;
      volatile uint32_t IDR1:1;
      volatile uint32_t IDR2:1;
      volatile uint32_t IDR3:1;
      volatile uint32_t IDR4:1;
      volatile uint32_t IDR5:1;
      volatile uint32_t IDR6:1;
      volatile uint32_t IDR7:1;
      volatile uint32_t IDR8:1;
      volatile uint32_t IDR9:1;
      volatile uint32_t IDR10:1;
      volatile uint32_t IDR11:1;
      volatile uint32_t IDR12:1;
      volatile uint32_t IDR13:1;
      volatile uint32_t IDR14:1;
      volatile uint32_t IDR15:1;
      volatile uint32_t reserve:16;
     }x_IDR; /*!< GPIO port input data register,   Address offset: 0x10 */
     
      struct type_ODR
    {
      volatile uint32_t ODR0:1;
      volatile uint32_t ODR1:1;
      volatile uint32_t ODR2:1;
      volatile uint32_t ODR3:1;
      volatile uint32_t ODR4:1;
      volatile uint32_t ODR5:1;
      volatile uint32_t ODR6:1;
      volatile uint32_t ODR7:1;
      volatile uint32_t ODR8:1;
      volatile uint32_t ODR9:1;
      volatile uint32_t ODR10:1;
      volatile uint32_t ODR11:1;
      volatile uint32_t ODR12:1;
      volatile uint32_t ODR13:1;
      volatile uint32_t ODR14:1;
      volatile uint32_t ODR15:1;
      volatile uint32_t reserve:16;
     }x_ODR;  /*!< GPIO port output data register ,   Address offset: 0x14 */

     struct type_BSRR
  {
    volatile uint32_t BS0:1;
    volatile uint32_t BS1:1;
    volatile uint32_t BS2:1;
    volatile uint32_t BS3:1;
    volatile uint32_t BS4:1;
    volatile uint32_t BS5:1;
    volatile uint32_t BS6:1;
    volatile uint32_t BS7:1;
    volatile uint32_t BS8:1;
    volatile uint32_t BS9:1;
    volatile uint32_t BS10:1;
    volatile uint32_t BS11:1;
    volatile uint32_t BS12:1;
    volatile uint32_t BS13:1;
    volatile uint32_t BS14:1;
    volatile uint32_t BS15:1;
    volatile uint32_t BR0:1;
    volatile uint32_t BR1:1;
    volatile uint32_t BR2:1;
    volatile uint32_t BR3:1;
    volatile uint32_t BR4:1;
    volatile uint32_t BR5:1;
    volatile uint32_t BR6:1;
    volatile uint32_t BR7:1;
    volatile uint32_t BR8:1;
    volatile uint32_t BR9:1;
    volatile uint32_t BR10:1;
    volatile uint32_t BR11:1;
    volatile uint32_t BR12:1;
    volatile uint32_t BR13:1;
    volatile uint32_t BR14:1;
    volatile uint32_t BR15:1;
   }x_BSRR; /*!< GPIO port bit set/reset register ,   Address offset: 0x18 */
   
       struct type_LCKR
    {
      volatile uint32_t LCK0:1;
      volatile uint32_t LCK1:1;
      volatile uint32_t LCK2:1;
      volatile uint32_t LCK3:1;
      volatile uint32_t LCK4:1;
      volatile uint32_t LCK5:1;
      volatile uint32_t LCK6:1;
      volatile uint32_t LCK7:1;
      volatile uint32_t LCK8:1;
      volatile uint32_t LCK9:1;
      volatile uint32_t LCK10:1;
      volatile uint32_t LCK11:1;
      volatile uint32_t LCK12:1;
      volatile uint32_t LCK13:1;
      volatile uint32_t LCK14:1;
      volatile uint32_t LCK15:1;
      volatile uint32_t LCKK:1;
      volatile uint32_t reserve:15;
     }x_LCKR; /*!< GPIO port configuration lock register ,   Address offset: 0x1Ñ */
  
  struct type_AFRL
    {
      volatile uint32_t AFR0:4;
      volatile uint32_t AFR1:4;
      volatile uint32_t AFR2:4;
      volatile uint32_t AFR3:4;
      volatile uint32_t AFR4:4;
      volatile uint32_t AFR5:4;
      volatile uint32_t AFR6:4;
      volatile uint32_t AFR7:4;
     }x_AFRL; /*!< GPIO alternate function low register ,   Address offset: 0x20 */
     
       struct type_AFRH
    {
      volatile uint32_t AFR8:4;
      volatile uint32_t AFR9:4;
      volatile uint32_t AFR10:4;
      volatile uint32_t AFR11:4;
      volatile uint32_t AFR12:4;
      volatile uint32_t AFR13:4;
      volatile uint32_t AFR14:4;
      volatile uint32_t AFR15:4;
     }x_AFRH;  /*!< GPIO alternate function high register ,   Address offset: 0x24 */
     
}GPIO_Type;

/******************************************************************************
 *
 * ETHERNET registers
 *
 ******************************************************************************/
typedef struct
{
    struct type_MACCR
  {
    volatile uint32_t reserve0:2;    
    volatile uint32_t RE:1;
    volatile uint32_t TE:1;
    volatile uint32_t DC:1;
    volatile uint32_t BL:2;
    volatile uint32_t APCS:1;
    volatile uint32_t reserve1:1;  
    volatile uint32_t RD:1;
    volatile uint32_t IPCO:1;
    volatile uint32_t DM:1;
    volatile uint32_t LM:1;
    volatile uint32_t ROD:1;
    volatile uint32_t FES:1;    
    volatile uint32_t reserve2:1;
    volatile uint32_t CSD:1;
    volatile uint32_t IFG:3;
    volatile uint32_t reserve3:2;
    volatile uint32_t JD:1;
    volatile uint32_t WD:1;
    volatile uint32_t reserve4:1;    
    volatile uint32_t CSTF:1;
    volatile uint32_t reserve5:6;
   } MACCR; /*!< Ethernet MAC configuration register ,   Address offset: 0x00 */
     
   struct type_MACFFR
  {
    volatile uint32_t PM:1;
    volatile uint32_t HU:1;
    volatile uint32_t HM:1;
    volatile uint32_t DAIF:1;
    volatile uint32_t PAM:1;
    volatile uint32_t BFD:1;
    volatile uint32_t PCF:2;
    volatile uint32_t SAIF:1;
    volatile uint32_t SAF:1;
    volatile uint32_t HPF:1;
    volatile uint32_t reserve:20;
    volatile uint32_t RA:1;
   }MACFFR; /*!< Ethernet MAC frame filter register,   Address offset: 0x04 */
   
    struct type_MACHTHR
    {
      volatile uint32_t HTH:32;
     }MACHTHR; /*!< Ethernet MAC hash table high register,   Address offset: 0x08 */
     
    struct type_MACHTLR
    {
      volatile uint32_t HTL:32;
     }x_MACHTLR; /*!< Ethernet MAC hash table low register,   Address offset: 0x0C */
     
    struct type_MACMIIAR
    {
      volatile uint32_t MB:1;
      volatile uint32_t MW:1;
      volatile uint32_t CR:4;
      volatile uint32_t MR:5;
      volatile uint32_t PA:5;
      volatile uint32_t reserve0:16;
     }MACMIIAR; /*!< Ethernet MAC MII address register,   Address offset: 0x10 */
     
      struct type_MACMIIDR
    {
      volatile uint32_t MD:16;
      volatile uint32_t reserve0:16;
     }MACMIIDR;  /*!< Ethernet MAC MII data register,   Address offset: 0x14 */

     struct type_MACFCR
  {
    volatile uint32_t FCB_BPA:1;
    volatile uint32_t TFCE:1;    
    volatile uint32_t RFCE:1;
    volatile uint32_t UPFD:1;
    volatile uint32_t PLT:2;
    volatile uint32_t reserve0:1;
    volatile uint32_t ZQPD:1;
    volatile uint32_t reserve1:8;
    volatile uint32_t PT:16;
   }MACFCR; /*!< Ethernet MAC flow control register,   Address offset: 0x18 */
   
     struct type_MACVLANTR
  {
    volatile uint32_t VLANTI:16;
    volatile uint32_t VLANTC:1;    
    volatile uint32_t reserve0:15;
   }MACVLANTR; /*!< Ethernet MAC VLAN tag register,   Address offset: 0x1C */
   
       volatile uint32_t RESERVED0[2];  /*!< Reserved, 0x20-0x24  */   
      
     struct type_MACRWUFFR
  {
    volatile uint32_t FRAME_FILTER:32;
   }MACRWUFFR; /*!< ,   Address offset: 0x28 */
      
     struct type_MACPMTCSR
  {
    volatile uint32_t PD:1;
    volatile uint32_t MPE:1;
    volatile uint32_t WFE:1;
    volatile uint32_t reserve0:2;
    volatile uint32_t MPR:1;    
    volatile uint32_t WFR:1;
    volatile uint32_t reserve1:2;
    volatile uint32_t GU:1;
    volatile uint32_t reserve2:21;
    volatile uint32_t WFFRPR:1;
   }MACPMTCSR; /*!< ,   Address offset: 0x2C */   
   
       volatile uint32_t RESERVED1;  /*!< Reserved, 0x30  */        
      
     struct type_MACDBGR
  {
    volatile uint32_t MMRPEA:1;
    volatile uint32_t MSFRWCS:2;
    volatile uint32_t reserve0:1;
    volatile uint32_t RFWRA:1;    
    volatile uint32_t FRRCS:2;
    volatile uint32_t RFFL:2;
    volatile uint32_t reserve1:6;
    volatile uint32_t MMTE:1;
    volatile uint32_t MTFCS:2;
    volatile uint32_t MTP:1;
    volatile uint32_t TFRS:2;
    volatile uint32_t TFWA:1;    
    volatile uint32_t reserve2:1;
    volatile uint32_t TFNEGU:1;
    volatile uint32_t TFF:1;
    volatile uint32_t reserve3:6;
   }MACDBGR; /*!< ,   Address offset: 0x34 */    
   
     struct type_MACSR
  {
    volatile uint32_t reserve0:3;    
    volatile uint32_t PMTS:1;
    volatile uint32_t MMCS:1;
    volatile uint32_t MMCRS:1;
    volatile uint32_t MMCTS:1;
    volatile uint32_t reserve1:2;
    volatile uint32_t TSTIM:1;
    volatile uint32_t reserve2:16;
   }MACSR; /*!< ,   Address offset: 0x38 */  
   
     struct type_MACIMR
  {
    volatile uint32_t reserve0:3;    
    volatile uint32_t PMTIM:1;
    volatile uint32_t reserve1:5;
    volatile uint32_t TSTIM:1;
    volatile uint32_t reserve2:22;
   }MACIMR; /*!< ,   Address offset: 0x3C */     
   
   
     struct type_MACA0HR
  {
    volatile uint32_t MACA0H:16;    
    volatile uint32_t reserve0:15;
    volatile uint32_t MO:1;
   }MACA0HR; /*!< ,   Address offset: 0x40 */   

   struct type_MACA0LR
  {
    volatile uint32_t MACA0L:32;    
   }MACA0LR; /*!< ,   Address offset: 0x44 */      
   
   struct type_MACA1HR
  {
    volatile uint32_t MACA1H:16; 
    volatile uint32_t reserve0:8;    
    volatile uint32_t MBC:6;
    volatile uint32_t SA:1;
    volatile uint32_t AE:1;    
   }MACA1HR; /*!< ,   Address offset: 0x48 */      
      
   struct type_MACA1LR
  {
    volatile uint32_t MACA1L:16;    
   }MACA1LR; /*!< ,   Address offset: 0x4C */         

   struct type_MACA2HR
  {
    volatile uint32_t MACA2H:16;
    volatile uint32_t reserve0:8;     
    volatile uint32_t MBC:6;
    volatile uint32_t SA:1;
    volatile uint32_t AE:1;            
   }MACA2HR; /*!< ,   Address offset: 0x50 */ 
      
   struct type_MACA2LR
  {
    volatile uint32_t MACA2L:16;    
   }MACA2LR; /*!< ,   Address offset: 0x54 */         

   struct type_MACA3HR
  {
    volatile uint32_t MACA3H:16;
    volatile uint32_t reserve0:8;     
    volatile uint32_t MBC:6;
    volatile uint32_t SA:1;
    volatile uint32_t AE:1;            
   }MACA3HR; /*!< ,   Address offset: 0x58 */    
      
   struct type_MACA3LR
  {
    volatile uint32_t MACA3L:16;    
   }MACA3LR; /*!< ,   Address offset: 0x5Ñ */   
   
     volatile uint32_t RESERVED2[40];  /*!< Reserved, 0x60-0x9Ñ  */   
      
   struct type_MMCCR
  {
    volatile uint32_t CR:1;   
    volatile uint32_t CSR:1;
    volatile uint32_t ROR:1;
    volatile uint32_t MCF:1;
    volatile uint32_t MCP:1;
    volatile uint32_t MCFHP:1;
    volatile uint32_t reserve0:26;    
   }MMCCR; /*!< ,   Address offset: 0x100 */   
      
   struct type_MMCRIR
  {
    volatile uint32_t reserve0:5;
    volatile uint32_t RFCES:1; 
    volatile uint32_t RFAES:1;     
    volatile uint32_t reserve1:10;
    volatile uint32_t RGUFS:1;     
    volatile uint32_t reserve2:14;
   }MMCRIR; /*!< ,   Address offset: 0x104 */      

   struct type_MMCTIR
  {
    volatile uint32_t reserve0:14;  
    volatile uint32_t GFSCS:1; 
    volatile uint32_t TGFMSCS:1; 
    volatile uint32_t reserve1:5;  
    volatile uint32_t MACA2L:1; 
    volatile uint32_t reserve2:10;  
   }MMCTIR; /*!< ,   Address offset: 0x108 */ 
   
   struct type_MMCRIMR
  {
    volatile uint32_t reserve0:5;  
    volatile uint32_t RFCEM:1;    
    volatile uint32_t RFAEM:1;       
    volatile uint32_t reserve1:10;     
    volatile uint32_t RGUFM:1;      
    volatile uint32_t reserve2:14;     
   }MMCRIMR; /*!< ,   Address offset: 0x10Ñ */
   
   struct type_MMCTIMR
  {
    volatile uint32_t reserve0:14;  
    volatile uint32_t TGFSCM:1;    
    volatile uint32_t TGFMSCM:1;       
    volatile uint32_t reserve1:5;     
    volatile uint32_t TGFM:1;      
    volatile uint32_t reserve2:10;  
   }MMCTIMR; /*!< ,   Address offset: 0x110 */ 

     volatile uint32_t RESERVED3[14];  /*!< Reserved, 0x114-0x148  */   

   struct type_MMCTGFSCCR
  {
    volatile uint32_t TGFSCC:32;    
   }MMCTGFSCCR; /*!< ,   Address offset: 0x14C */   
   
   struct type_MMCTGFMSCCR
  {
    volatile uint32_t TGFMSCC:32;    
   }MMCTGFMSCCR; /*!< ,   Address offset: 0x150 */   

     volatile uint32_t RESERVED4[5];  /*!< Reserved, 0x154-0x164  */ 
   
   struct type_MMCTGFCR
  {
    volatile uint32_t TGFC:32;    
   }MMCTGFCR; /*!< ,   Address offset: 0x168 */   
   
     volatile uint32_t RESERVED5[10];  /*!< Reserved, 0x16C-0x190  */ 
   
    struct type_MMCRFCECR
  {
    volatile uint32_t RFCEC:32;    
   }MMCRFCECR; /*!< ,   Address offset: 0x194*/ 
   
    struct type_MMCRFAECR
  {
    volatile uint32_t RFAEC:32;    
   }MMCRFAECR; /*!< ,   Address offset: 0x198*/ 
   
      volatile uint32_t RESERVED6[10];  /*!< Reserved, 0x19C-0x1C0  */ 
    
    struct type_MMCRGUFCR
  {
    volatile uint32_t RGUFC:32;    
   }MMCRGUFCR; /*!< ,   Address offset: 0x1Ñ4*/ 
   
      volatile uint32_t RESERVED7[334];  /*!< Reserved, 0x1Ñ8-0x6FÑ  */ 
   
    struct type_PTPTSCR
  {
    volatile uint32_t TSE:1;   
    volatile uint32_t TSFCU:1;  
    volatile uint32_t TSSTI:1;  
    volatile uint32_t TSSTU:1;      
    volatile uint32_t TSITE:1;
    volatile uint32_t TTSARU:1;  
    volatile uint32_t reserve0:2;      
    volatile uint32_t TSSARFE:1;      
    volatile uint32_t TSSSR:1; 
    volatile uint32_t TSPTPPSV2E:1; 
    volatile uint32_t TSSPTPOEFE:1; 
    volatile uint32_t TSSIPV6FE:1; 
    volatile uint32_t TSSIPV4FE:1; 
    volatile uint32_t TSSEME:1; 
    volatile uint32_t TSSMRME:1; 
    volatile uint32_t TSCNT:2; 
    volatile uint32_t TSPFFMAE:1; 
    volatile uint32_t reserve1:13;  
   }PTPTSCR; /*!< ,   Address offset: 0x700*/    
   
    struct type_PTPSSIR
  {
    volatile uint32_t STSSI:8;    
    volatile uint32_t reserve0:24; 
   }PTPSSIR; /*!< ,   Address offset: 0x704*/ 

    struct type_PTPTSHR
  {
    volatile uint32_t STS:32;     
   }PTPTSHR; /*!< ,   Address offset: 0x708*/ 
   
    struct type_PTPTSLR
  {
    volatile uint32_t STSS:31;  
    volatile uint32_t STPNS:1; 
   }PTPTSLR; /*!< ,   Address offset: 0x70C*/ 
   
    struct type_PTPTSHUR
  {
    volatile uint32_t TSUS:32;     
   }PTPTSHUR; /*!< ,   Address offset: 0x710*/ 

    struct type_PTPTSLUR
  {
    volatile uint32_t TSUSS:31;     
    volatile uint32_t TSUPNS:1; 
   }PTPTSLUR; /*!< ,   Address offset: 0x714*/    
   
    struct type_PTPTSAR
  {
    volatile uint32_t TSA:32;     
   }PTPTSAR; /*!< ,   Address offset: 0x718*/ 

    struct type_PTPTTHR
  {
    volatile uint32_t TTSH:32;     
   }PTPTTHR; /*!< ,   Address offset: 0x71C*/ 

    struct type_PTPTTLR
  {
    volatile uint32_t TTSL:32;     
   }PTPTTLR; /*!< ,   Address offset: 0x720*/ 

      volatile uint32_t RESERVED8[1];  /*!< Reserved, 0x724  */
    
   struct type_PTPTSSR
  {
    volatile uint32_t TSSO:1;     
    volatile uint32_t TSTTR:1;   
    volatile uint32_t reserve0:30;  
   }PTPTSSR; /*!< ,   Address offset: 0x728*/ 
    
      volatile uint32_t RESERVED9[565];  /*!< Reserved, 0x72C-0xFFC  */
    
   struct type_DMABMR
  {
    volatile uint32_t SR:1;     
    volatile uint32_t DA:1;   
    volatile uint32_t DSL:4;   
    volatile uint32_t EDFE:1; 
    volatile uint32_t PBL:5;       
    volatile uint32_t PM:2;  
    volatile uint32_t FB:1;   
    volatile uint32_t RDP:5;  
    volatile uint32_t USP:1;       
    volatile uint32_t FPM:1;
    volatile uint32_t AAB:1; 
    volatile uint32_t MB:1;   
    volatile uint32_t reserve0:5;  
   }DMABMR; /*!< ,   Address offset: 0x1000*/ 
   
   struct type_DMATPDR
  {
    volatile uint32_t TPD:32;     
   }DMATPDR; /*!< ,   Address offset: 0x1004*/    

   struct type_DMARPDR
  {
    volatile uint32_t RPD:32;     
   }DMARPDR; /*!< ,   Address offset: 0x1008*/    
   
   struct type_DMARDLAR
  {
    volatile uint32_t SRL:32;     
   }DMARDLAR; /*!< ,   Address offset: 0x100C*/     
   
   struct type_DMATDLAR
  {
    volatile uint32_t STL:32;     
   }DMATDLAR; /*!< ,   Address offset: 0x1010*/   
   
   struct type_DMASR
  {
    volatile uint32_t TS:1;     
    volatile uint32_t TPSS:1;   
    volatile uint32_t TBUS:1;   
    volatile uint32_t TJTS:1; 
    volatile uint32_t ROS:1;       
    volatile uint32_t TUS:1;  
    volatile uint32_t RS:1;   
    volatile uint32_t RBUS:1;  
    volatile uint32_t RPSS:1;       
    volatile uint32_t RWTS:1;
    volatile uint32_t ETS:1; 
    volatile uint32_t reserve0:1;     
    volatile uint32_t FBES:1;   
    volatile uint32_t ERS:1;  
    volatile uint32_t AIS:1;       
    volatile uint32_t NIS:1;
    volatile uint32_t RPS:3; 
    volatile uint32_t TPS:3;   
    volatile uint32_t EBS:3;  
    volatile uint32_t reserve1:1;     
    volatile uint32_t MMCS:1;       
    volatile uint32_t PMTS:1;
    volatile uint32_t TSTS:1;     
    volatile uint32_t reserve2:2; 
   }DMASR; /*!< ,   Address offset: 0x1014*/    
    
   struct type_DMAOMR
  {
    volatile uint32_t reserve0:1;     
    volatile uint32_t SR:1;     
    volatile uint32_t OSF:1;   
    volatile uint32_t RTC:2;
    volatile uint32_t reserve1:1; 
    volatile uint32_t FUGF:1; 
    volatile uint32_t FEF:1;       
    volatile uint32_t reserve2:5; 
    volatile uint32_t ST:1;   
    volatile uint32_t TTC:3;
    volatile uint32_t reserve3:3; 
    volatile uint32_t FTF:1;       
    volatile uint32_t TSF:1;
    volatile uint32_t reserve4:2; 
    volatile uint32_t DFRF:1; 
    volatile uint32_t RSF:1;
    volatile uint32_t DTCEFD:1; 
    volatile uint32_t reserve5:5;  
   }DMAOMR; /*!< ,   Address offset: 0x1018*/ 
   
   struct type_DMAIER
  {
    volatile uint32_t TIE:1;     
    volatile uint32_t TPSIE:1;     
    volatile uint32_t TBUIE:1;   
    volatile uint32_t TJTIE:1;
    volatile uint32_t ROIE:1; 
    volatile uint32_t TUIE:1; 
    volatile uint32_t RIE:1;       
    volatile uint32_t RBUIE:1; 
    volatile uint32_t RPSIE:1;   
    volatile uint32_t RWTIE:1;
    volatile uint32_t ETIE:1; 
    volatile uint32_t reserve0:2; 
    volatile uint32_t FBEIE:1; 
    volatile uint32_t ERIE:1;
    volatile uint32_t AISE:1; 
    volatile uint32_t NISE:1; 
    volatile uint32_t reserve1:5;  
   }DMAIER; /*!< ,   Address offset: 0x101C*/    
   
   struct type_DMAMFBOCR
  {
    volatile uint32_t MFC:16;     
    volatile uint32_t OMFC:1;     
    volatile uint32_t MFA:11;   
    volatile uint32_t OFOC:1;
    volatile uint32_t reserve1:3;  
   }DMAMFBOCR; /*!< ,   Address offset: 0x1020*/      
   
   struct type_DMARSWTR
  {
    volatile uint32_t RSWTC:8;        
    volatile uint32_t reserve0:24;  
   }DMARSWTR; /*!< ,   Address offset: 0x1024*/  
   
     volatile uint32_t RESERVED10[8];  /*!< Reserved, 0x1028-0x1044  */
   
   struct type_DMACHTDR
  {
    volatile uint32_t HTDAP:32;         
   }DMACHTDR; /*!< ,   Address offset: 0x1048*/  
   
   struct type_DMACHRDR
  {
    volatile uint32_t HRDAP:32;        
   }DMACHRDR; /*!< ,   Address offset: 0x104C*/  
   
   struct type_DMACHTBAR
  {
    volatile uint32_t HTBAP:32;        
   }DMACHTBAR; /*!< ,   Address offset: 0x1050*/  
   
   struct type_DMACHRBAR
  {
    volatile uint32_t HRBAP:32;        
   }DMACHRBAR; /*!< ,   Address offset: 0x1054*/  
   
}ETHERNET_Type;

/******************************************************************************
 *
 * Flash registers
 *
 ******************************************************************************/
typedef struct
{
    struct type_ACR
    {
          volatile uint32_t LATENCY :4;   
          volatile uint32_t reserve0:4;
          volatile uint32_t PRFTEN  :1;   
          volatile uint32_t ARTEN    :1;  
          volatile uint32_t reserve1    :1;   
          volatile uint32_t ARTRST   :1;   
          volatile uint32_t reserve2:20;
    } ACR;                         /*!< Flash access control register,   Address offset: 0x00 */

    volatile uint32_t KEYR;                 /*!< Flash key register,   Address offset: 0x04 */
    volatile uint32_t OPTKEYR;              /*!< Flash option key register,   Address offset: 0x08 */

    struct type_SR
    {
          volatile uint32_t EOP      :1;
          volatile uint32_t OPERR    :1;
          volatile uint32_t reserve0 :2;
          volatile uint32_t WRPERR   :1;
          volatile uint32_t PGAERR   :1;
          volatile uint32_t PGPERR   :1;
          volatile uint32_t PGSERR   :1;
          volatile uint32_t reserve1 :8;
          volatile uint32_t BSY      :1;
          volatile uint32_t reserve2 :15;
    } SR;                          /*!< Flash status register,    Address offset: 0x0C */

    struct type_FLASH_CR
    {
          volatile uint32_t PG       :1;
          volatile uint32_t SER      :1;
          volatile uint32_t MER      :1;
          volatile uint32_t SNB      :4;
          volatile uint32_t PSIZE    :2;
          volatile uint32_t reserve0 :5;
          volatile uint32_t STRT     :1;
          volatile uint32_t reserve1 :7;
          volatile uint32_t EOPIE    :1;
          volatile uint32_t ERRIE    :1;
          volatile uint32_t LOCK     :1;
          volatile uint32_t reserve2 :5;
    } CR;                          /*!< Flash control register,   Address offset: 0x10 */

    volatile uint32_t OPTCR;                /*!< Flash option control register,   Address offset: 0x14 */

    volatile uint32_t OPTCR1;               /*!< Flash option control register,   Address offset: 0x18 */

} FLASH_Type;

/******************************************************************************
 *
 * SYSCFG registers
 *
 ******************************************************************************/
typedef struct
{
    struct type_MEMRMP
    {
          volatile uint32_t MEM_BOOT :1;  
          volatile uint32_t reserve0 :9;

          volatile uint32_t SWP_FMC  :2;   
          volatile uint32_t reserve1:20;
    } MEMRMP;                         /*!< SYSCFG memory remap register,    Address offset: 0x00 */

    struct type_PMC
    {
          volatile uint32_t reserve0 :16;
          volatile uint32_t ADCxDC2  :3;
          volatile uint32_t reserve1 :4;
          volatile uint32_t MII_RMII_SEL   :1;
          volatile uint32_t reserve2 :8;
    } PMC;                          /*!< SYSCFG peripheral mode configuration register,    Address offset: 0x04 */

    struct type_EXTICR1
    {
          volatile uint32_t EXTI0    :4;
          volatile uint32_t EXTI1    :4;
          volatile uint32_t EXTI2    :4;
          volatile uint32_t EXTI3    :4;
          volatile uint32_t reserve0 :16;
    } EXTICR1;                          /*!< SYSCFG external volatile uint32_terrupt configuration register 1,      Address offset: 0x08 */
    
    struct type_EXTICR2
    {
          volatile uint32_t EXTI4    :4;
          volatile uint32_t EXTI5    :4;
          volatile uint32_t EXTI6    :4;
          volatile uint32_t EXTI7    :4;
          volatile uint32_t reserve0 :16;
    } EXTICR2;                          /*!< SYSCFG external volatile uint32_terrupt configuration register 2,      Address offset: 0x0C */
    
    struct type_EXTICR3
    {
          volatile uint32_t EXTI8    :4;
          volatile uint32_t EXTI9    :4;
          volatile uint32_t EXTI10    :4;
          volatile uint32_t EXTI11    :4;
          volatile uint32_t reserve0 :16;
    } EXTICR3;                          /*!< SYSCFG external volatile uint32_terrupt configuration register 3,      Address offset: 0x10 */

    struct type_EXTICR4
    {
          volatile uint32_t EXTI12    :4;
          volatile uint32_t EXTI13    :4;
          volatile uint32_t EXTI14    :4;
          volatile uint32_t EXTI15    :4;
          volatile uint32_t reserve0 :16;
    } EXTICR4;                          /*!< SYSCFG external volatile uint32_terrupt configuration register 4,      Address offset: 0x14 */
    
      volatile uint32_t RESERVED0[2];  /*!< Reserved, 0x18-0x1C                                                               */
    
    struct type_CMPCR
    {
          volatile uint32_t CMP_PD    :1;
          volatile uint32_t reserve0 :7;
          volatile uint32_t READY    :1;
          volatile uint32_t reserve1 :23;
    }CMPCR;                          /*!< Compensation cell control register,      Address offset: 0x20 */

} SYSCFG_Type;

extern RCC_Type  *RCC;

extern GPIO_Type *GPIOA;
extern GPIO_Type *GPIOB;
extern GPIO_Type *GPIOC;
extern GPIO_Type *GPIOD;
extern GPIO_Type *GPIOE;
extern GPIO_Type *GPIOF;
extern GPIO_Type *GPIOG;
extern GPIO_Type *GPIOH;
extern GPIO_Type *GPIOI;
extern GPIO_Type *GPIOJ;
extern GPIO_Type *GPIOK;

extern FLASH_Type *FLASH;
extern ETHERNET_Type *ETH;
extern SYSCFG_Type *SYSCFG;

#endif