#include <stdint.h>

/*                              RCC registers                                   */
typedef struct {
  struct type_CR          /*!< RCC clock control register,        Address offset: 0x00 */ 
    {
      int HSI_ON:1;  
      int HSI_RDY:1;
      int reserve0:1;
      int HSITRIM:5;
      int HSICAL:8;
      int HSE_ON:1;
      int HSE_RDY:1;
      int HSE_BYP:1;
      int CSS_ON:1;
      int reserve1:4;
      int PLL_ON:1;
      int PLL_RDY:1;
      int PLLI2S_ON:1;
      int PLLI2S_RDY:1;
      int PLLISAI_ON:1;
      int PLLISAI_RDY:1;
      int reserve2:2;
    }CR;                         

  struct type_PLLCFGR     /*!< RCC PLL configuration register,    Address offset: 0x04 */
    {
      unsigned int PLLM:6;
      unsigned int PLLN:9;
      unsigned int reserve0:1;
      unsigned int PLLP:2;
      unsigned int reserve1:4;
      unsigned int PLLSRC:1;
      unsigned int reserve2:1;
      unsigned int PLLQ:4;
      unsigned int reserve3:4;
    }PLLCFGR;                                     
 
  struct type_CFGR        /*!< RCC clock configuration register,  Address offset: 0x08 */ 
    {
      int SW:2;
      int SWS:2;
      int HPRE:4;
      int reserve0:2;
      int PPRE1:3;
      int PPRE2:3;
      int RTCPRE:5;
      int MCO1:2;
      int I2SSRC:1;
      int MCO1_PRE:3;
      int MCO2_PRE:3;
      int MCO2:2;
    }CFGR;                        
 
    unsigned int CIR;             /*!< RCC clock interrupt register,                                Address offset: 0x0C */
    unsigned int AHB1RSTR;        /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
    unsigned int AHB2RSTR;        /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
    unsigned int AHB3RSTR;        /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
    unsigned int RESERVED0;       /*!< Reserved, 0x1C                                                                    */
    unsigned int APB1RSTR;        /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
    unsigned int APB2RSTR;        /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
    unsigned int RESERVED1[2];    /*!< Reserved, 0x28-0x2C                                                               */

  struct type_AHB1ENR     /*!< RCC AHB1 peripheral clock register, Address offset: 0x30 */
    {
      int GPIO_AEN:1;
      int GPIO_BEN:1;
      int GPIO_CEN:1;
      int GPIO_DEN:1;
      int GPIO_EEN:1;
      int GPIO_FEN:1;
      int GPIO_GEN:1;
      int GPIO_HEN:1;
      int GPIO_IEN:1;
      int GPIO_JEN:1;
      int GPIO_KEN:1;
      int reserve0:1;
      int CRC_EN:1;              
      int reserve1:5;
      int BKPSRAMEN:1;           
      int reserve2:1; 
      int CCMDATARAMEN:1;
      int DMA1EN:1;
      int DMA2EN:1;
      int DMA2DEN:1;
      int reserve3:1;
      int ETHMACEN:1;
      int ETHMACTXEN:1;
      int ETHMACRXEN:1;
      int ETHMACPTPEN:1;
      int OTGHSEN:1;
      int OTGHSULPIEN:1;
      int reserve4:1;
    }AHB1ENR;                   
  
  struct type_AHB2ENR     /*!< RCC AHB2 peripheral clock register,  Address offset: 0x34 */
    {
      int DCMIEN:1;
      int reserve0:3;  
      int CRYPEN:1;
      int HASHEN:1;
      int RNGEN:1;
      int OTGFSEN:1;
      int reserve1:24;
    }AHB2ENR;

  struct type_AHB3ENR     /*!< RCC AHB3 peripheral clock register,  Address offset: 0x38 */
    {
      int FMCEN:1;
      int QSPIEN:1;
      int reserve0:30;
    }AHB3ENR;                      
 
  unsigned int RESERVED2; /*!< Reserved, 0x3C */
  
  struct type_APB1ENR     /*!< RCC APB1 peripheral clock enable register,  Address offset: 0x40 */
    {
      int TIM2EN:1;
      int TIM3EN:1;
      int TIM4EN:1;
      int TIM5EN:1;
      int TIM6EN:1;
      int TIM7EN:1;
      int TIM12EN:1;
      int TIM13EN:1;
      int TIM14EN:1;
      int LPTIM1EN:1;
      int reserve0:1;
      int WWDGEN:1;
      int reserve1:2;
      int SPI2EN:1;
      int SPI3EN:1;
      int SPDIFRXEN:1;
      int USART2EN:1;
      int USART3EN:1;
      int UART4EN:1;
      int UART5EN:1;
      int I2C1EN:1;
      int I2C2EN:1;
      int I2C3EN:1;
      int I2C4EN:1;
      int CAN1EN:1;
      int CAN2EN:1;
      int CECEN:1;
      int PWREN:1;
      int DACEN:1;
      int SPI7EN:1;
      int SPI8EN:1;
    }APB1ENR;                      

  struct type_APB2ENR     /*!< RCC APB2 peripheral clock enable register,  Address offset: 0x44 */
    {
      int TIM1EN:1;
      int TIM8EN:1;
      int reserve0:2;
      int USART1:1;
      int USART6:1;
      int reserve1:2;
      int ADC1EN:1;
      int ADC2EN:1;
      int ADC3EN:1;
      int SDMMC1EN:1;
      int SPI1EN:1;
      int SPI4EN:1;
      int SYSCFGREN:1;
      int reserve2:1;
      int TIM9EN:1;
      int TIM10EN:1;
      int TIM11EN:1;  
      int reserve3:1;
      int SPI5EN:1;
      int SPI6EN:1;      
      int SAI1EN:1;
      int SAI2EN:1;
      int reserve4:2;
      int LTDCEN:1;
      int reserve5:5;
    }APB2ENR;                      

  unsigned int RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  unsigned int AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  unsigned int AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  unsigned int AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  unsigned int RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  unsigned int APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  unsigned int APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  unsigned int RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */ 
  
  struct BDCR_Type            /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  {
    int LSEON:1;
    int LSERDY:1;
    int LSEBYP:1;
    int LSEDRV:2;    
    int reserve:3;
    int RTCSEL:2;
    int reserve1:5;
    int RTCEN:1;
    int BDRST:1;
    int reserve2:15;
  }BDCR;
 
  struct CSR_Type               /*!< RCC clock control & status register,                       Address offset: 0x74 */
  {
    int LSION:1;
    int LSIRDY:1;
    int reserve:22;
    int RMVF:1;
    int BORRSTF:1;
    int PINRSTF:1;
    int PORRSTF:1;
    int SFTRSTF:1;
    int WDGRSTF:1;
    int WWDGRSTF:1;
    int LPWRRSTF:1;
  }CSR;
  
  unsigned int RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  unsigned int SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  unsigned int PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  unsigned int PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
  unsigned int DCKCFGR1;    /*!< RCC dedicated clocks configuration register 1,                 Address offset: 0x8C */
  unsigned int DCKCFGR2;    /*!< RCC dedicated clocks configuration register 2,                 Address offset: 0x90 */
  
}RCC_Type;
/*                              GPIO registers                                   */
typedef struct
{
    struct type_MODER
  {
    int MODER0:2;
    int MODER1:2;
    int MODER2:2;
    int MODER3:2;
    int MODER4:2;
    int MODER5:2;
    int MODER6:2;
    int MODER7:2;
    int MODER8:2;
    int MODER9:2;
    int MODER10:2;
    int MODER11:2;
    int MODER12:2;
    int MODER13:2;
    int MODER14:2;
    int MODER15:2;
   }x_MODER; /*!< GPIO port mode register,   Address offset: 0x00 */
     
   struct type_OTYPER
  {
    int OT0:1;
    int OT1:1;
    int OT2:1;
    int OT3:1;
    int OT4:1;
    int OT5:1;
    int OT6:1;
    int OT7:1;
    int OT8:1;
    int OT9:1;
    int OT10:1;
    int OT11:1;
    int OT12:1;
    int OT13:1;
    int OT14:1;
    int OT15:1;
    int reserve:16;
   }x_OTYPER; /*!< GPIO port output type register,   Address offset: 0x04 */
   
    struct type_OSPEEDR
    {
      int OSPEEDR0:2;
      int OSPEEDR1:2;
      int OSPEEDR2:2;
      int OSPEEDR3:2;
      int OSPEEDR4:2;
      int OSPEEDR5:2;
      int OSPEEDR6:2;
      int OSPEEDR7:2;
      int OSPEEDR8:2;
      int OSPEEDR9:2;
      int OSPEEDR10:2;
      int OSPEEDR11:2;
      int OSPEEDR12:2;
      int OSPEEDR13:2;
      int OSPEEDR14:2;
      int OSPEEDR15:2;
     }x_OSPEEDR; /*!< GPIO port output speed register,   Address offset: 0x08 */
     
    struct type_PUPDR
    {
      int PUPDR0:2;
      int PUPDR1:2;
      int PUPDR2:2;
      int PUPDR3:2;
      int PUPDR4:2;
      int PUPDR5:2;
      int PUPDR6:2;
      int PUPDR7:2;
      int PUPDR8:2;
      int PUPDR9:2;
      int PUPDR10:2;
      int PUPDR11:2;
      int PUPDR12:2;
      int PUPDR13:2;
      int PUPDR14:2;
      int PUPDR15:2;
     }x_PUPDR; /*!< GPIO port pull-up/pull-down register,   Address offset: 0x0C */
     
       struct type_IDR
    {
      int IDR0:1;
      int IDR1:1;
      int IDR2:1;
      int IDR3:1;
      int IDR4:1;
      int IDR5:1;
      int IDR6:1;
      int IDR7:1;
      int IDR8:1;
      int IDR9:1;
      int IDR10:1;
      int IDR11:1;
      int IDR12:1;
      int IDR13:1;
      int IDR14:1;
      int IDR15:1;
      int reserve:16;
     }x_IDR; /*!< GPIO port input data register,   Address offset: 0x10 */
     
      struct type_ODR
    {
      int ODR0:1;
      int ODR1:1;
      int ODR2:1;
      int ODR3:1;
      int ODR4:1;
      int ODR5:1;
      int ODR6:1;
      int ODR7:1;
      int ODR8:1;
      int ODR9:1;
      int ODR10:1;
      int ODR11:1;
      int ODR12:1;
      int ODR13:1;
      int ODR14:1;
      int ODR15:1;
      int reserve:16;
     }x_ODR;  /*!< GPIO port output data register ,   Address offset: 0x14 */

     struct type_BSRR
  {
    int BS0:1;
    int BS1:1;
    int BS2:1;
    int BS3:1;
    int BS4:1;
    int BS5:1;
    int BS6:1;
    int BS7:1;
    int BS8:1;
    int BS9:1;
    int BS10:1;
    int BS11:1;
    int BS12:1;
    int BS13:1;
    int BS14:1;
    int BS15:1;
    int BR0:1;
    int BR1:1;
    int BR2:1;
    int BR3:1;
    int BR4:1;
    int BR5:1;
    int BR6:1;
    int BR7:1;
    int BR8:1;
    int BR9:1;
    int BR10:1;
    int BR11:1;
    int BR12:1;
    int BR13:1;
    int BR14:1;
    int BR15:1;
   }x_BSRR; /*!< GPIO port bit set/reset register ,   Address offset: 0x18 */
   
       struct type_LCKR
    {
      int LCK0:1;
      int LCK1:1;
      int LCK2:1;
      int LCK3:1;
      int LCK4:1;
      int LCK5:1;
      int LCK6:1;
      int LCK7:1;
      int LCK8:1;
      int LCK9:1;
      int LCK10:1;
      int LCK11:1;
      int LCK12:1;
      int LCK13:1;
      int LCK14:1;
      int LCK15:1;
      int LCKK:1;
      int reserve:15;
     }x_LCKR; /*!< GPIO port configuration lock register ,   Address offset: 0x1Ñ */
  
  struct type_AFRL
    {
      int AFR0:4;
      int AFR1:4;
      int AFR2:4;
      int AFR3:4;
      int AFR4:4;
      int AFR5:4;
      int AFR6:4;
      int AFR7:4;
     }x_AFRL; /*!< GPIO alternate function low register ,   Address offset: 0x20 */
     
       struct type_AFRH
    {
      int AFR8:4;
      int AFR9:4;
      int AFR10:4;
      int AFR11:4;
      int AFR12:4;
      int AFR13:4;
      int AFR14:4;
      int AFR15:4;
     }x_AFRH;  /*!< GPIO alternate function high register ,   Address offset: 0x24 */
     
}GPIO_Type;

/*                               ETHERNET registers                                   */
typedef struct
{
    struct type_MACCR
  {
    int reserve0:2;    
    int RE:1;
    int TE:1;
    int DC:1;
    int BL:2;
    int APCS:1;
    int reserve1:1;  
    int RD:1;
    int IPCO:1;
    int DM:1;
    int LM:1;
    int ROD:1;
    int FES:1;    
    int reserve2:1;
    int CSD:1;
    int IFG:3;
    int reserve3:2;
    int JD:1;
    int WD:1;
    int reserve4:1;    
    int CSTF:1;
    int reserve5:6;
   } MACCR; /*!< Ethernet MAC configuration register ,   Address offset: 0x00 */
     
   struct type_MACFFR
  {
    int PM:1;
    int HU:1;
    int HM:1;
    int DAIF:1;
    int PAM:1;
    int BFD:1;
    int PCF:2;
    int SAIF:1;
    int SAF:1;
    int HPF:1;
    int reserve:21;
   }MACFFR; /*!< Ethernet MAC frame filter register,   Address offset: 0x04 */
   
    struct type_MACHTHR
    {
      int HTH:32;
     }MACHTHR; /*!< Ethernet MAC hash table high register,   Address offset: 0x08 */
     
    struct type_MACHTLR
    {
      int HTL:32;
     }x_MACHTLR; /*!< Ethernet MAC hash table low register,   Address offset: 0x0C */
     
    struct type_MACMIIAR
    {
      int MB:1;
      int MW:1;
      int CR:4;
      int MR:5;
      int PA:5;
      int reserve0:16;
     }MACMIIAR; /*!< Ethernet MAC MII address register,   Address offset: 0x10 */
     
      struct type_MACMIIDR
    {
      int MD:16;
      int reserve0:16;
     }MACMIIDR;  /*!< Ethernet MAC MII data register,   Address offset: 0x14 */

     struct type_MACFCR
  {
    int FCB_BPA:1;
    int TFCE:1;    
    int RFCE:1;
    int UPFD:1;
    int PLT:2;
    int reserve0:1;
    int ZQPD:1;
    int reserve1:8;
    int PT:16;
   }MACFCR; /*!< Ethernet MAC flow control register,   Address offset: 0x18 */
   
     struct type_MACVLANTR
  {
    int VLANTI:16;
    int VLANTC:1;    
    int reserve0:15;
   }MACVLANTR; /*!< Ethernet MAC VLAN tag register,   Address offset: 0x1C */
   
     unsigned int RESERVED0[2];  /*!< Reserved, 0x20-0x24  */   
      
     struct type_MACRWUFFR
  {
    int FRAME_FILTER:32;
   }MACRWUFFR; /*!< ,   Address offset: 0x28 */
      
     struct type_MACPMTCSR
  {
    int PD:1;
    int MPE:1;
    int WFE:1;
    int reserve0:2;
    int MPR:1;    
    int WFR:1;
    int reserve1:2;
    int GU:1;
    int reserve2:21;
    int WFFRPR:1;
   }MACPMTCSR; /*!< ,   Address offset: 0x2C */   
   
     unsigned int RESERVED1;  /*!< Reserved, 0x30  */        
      
     struct type_MACDBGR
  {
    int MMRPEA:1;
    int MSFRWCS:2;
    int reserve0:1;
    int RFWRA:1;    
    int FRRCS:2;
    int RFFL:2;
    int reserve1:6;
    int MMTE:1;
    int MTFCS:2;
    int MTP:1;
    int TFRS:2;
    int TFWA:1;    
    int reserve2:1;
    int TFNEGU:1;
    int TFF:1;
    int reserve3:6;
   }MACDBGR; /*!< ,   Address offset: 0x34 */    
   
     struct type_MACSR
  {
    int reserve0:3;    
    int PMTS:1;
    int MMCS:1;
    int MMCRS:1;
    int MMCTS:1;
    int reserve1:2;
    int TSTIM:1;
    int reserve2:16;
   }MACSR; /*!< ,   Address offset: 0x38 */  
   
     struct type_MACA0HR
  {
    int MACA0H:16;    
    int reserve0:15;
    int MO:1;
   }MACA0HR; /*!< ,   Address offset: 0x40 */   

   struct type_MACA0LR
  {
    int MACA0L:32;    
   }MACA0LR; /*!< ,   Address offset: 0x44 */      
   
   struct type_MACA1HR
  {
    int MACA1H:16; 
    int reserve0:8;    
    int MBC:6;
    int SA:1;
    int AE:1;    
   }MACA1HR; /*!< ,   Address offset: 0x48 */      
      
   struct type_MACA1LR
  {
    int MACA1L:16;    
   }MACA1LR; /*!< ,   Address offset: 0x4C */         

   struct type_MACA2HR
  {
    int MACA2H:16;
    int reserve0:8;     
    int MBC:6;
    int SA:1;
    int AE:1;            
   }MACA2HR; /*!< ,   Address offset: 0x50 */ 
      
   struct type_MACA2LR
  {
    int MACA2L:16;    
   }MACA2LR; /*!< ,   Address offset: 0x54 */         

   struct type_MACA3HR
  {
    int MACA3H:16;
    int reserve0:8;     
    int MBC:6;
    int SA:1;
    int AE:1;            
   }MACA3HR; /*!< ,   Address offset: 0x58 */    
      
   struct type_MACA3LR
  {
    int MACA3L:16;    
   }MACA3LR; /*!< ,   Address offset: 0x5Ñ */   
   
   unsigned int RESERVED2[16];  /*!< Reserved, 0x60-0x9Ñ  */   
      
   struct type_MMCCR
  {
    int CR:1;   
    int CSR:1;
    int ROR:1;
    int MCF:1;
    int MCP:1;
    int MCFHP:1;
    int reserve0:26;    
   }MMCCR; /*!< ,   Address offset: 0x100 */   
      
   struct type_MMCRIR
  {
    int reserve0:5;
    int RFCES:1; 
    int RFAES:1;     
    int reserve1:10;
    int RGUFS:1;     
    int reserve2:14;
   }MMCRIR; /*!< ,   Address offset: 0x104 */      

   struct type_MMCTIR
  {
    int reserve0:14;  
    int GFSCS:1; 
    int TGFMSCS:1; 
    int reserve1:5;  
    int MACA2L:1; 
    int reserve2:10;  
   }MMCTIR; /*!< ,   Address offset: 0x108 */ 
   
   struct type_MMCRIMR
  {
    int reserve0:5;  
    int RFCEM:1;    
    int RFAEM:1;       
    int reserve1:10;     
    int RGUFM:1;      
    int reserve2:14;     
   }MMCRIMR; /*!< ,   Address offset: 0x10Ñ */
   
   struct type_MMCTIMR
  {
    int reserve0:14;  
    int TGFSCM:1;    
    int TGFMSCM:1;       
    int reserve1:5;     
    int TGFM:1;      
    int reserve2:10;  
   }MMCTIMR; /*!< ,   Address offset: 0x110 */ 

   unsigned int RESERVED3[14];  /*!< Reserved, 0x114-0x148  */   

   struct type_MMCTGFSCCR
  {
    int TGFSCC:32;    
   }MMCTGFSCCR; /*!< ,   Address offset: 0x14C */   
   
   struct type_MMCTGFMSCCR
  {
    int TGFMSCC:32;    
   }MMCTGFMSCCR; /*!< ,   Address offset: 0x150 */   

   unsigned int RESERVED4[5];  /*!< Reserved, 0x154-0x164  */ 
   
   struct type_MMCTGFCR
  {
    int TGFC:32;    
   }MMCTGFCR; /*!< ,   Address offset: 0x168 */   
   
   unsigned int RESERVED5[10];  /*!< Reserved, 0x16C-0x190  */ 
   
    struct type_MMCRFCECR
  {
    int RFCEC:32;    
   }MMCRFCECR; /*!< ,   Address offset: 0x194*/ 
   
    struct type_MMCRFAECR
  {
    int RFAEC:32;    
   }MMCRFAECR; /*!< ,   Address offset: 0x198*/ 
   
    unsigned int RESERVED6[10];  /*!< Reserved, 0x19C-0x1C0  */ 
    
    struct type_MMCRGUFCR
  {
    int RGUFC:32;    
   }MMCRGUFCR; /*!< ,   Address offset: 0x1Ñ4*/ 
   
    unsigned int RESERVED7[334];  /*!< Reserved, 0x1Ñ8-0x6FÑ  */ 
   
    struct type_PTPTSCR
  {
    int TSE:1;   
    int TSFCU:1;  
    int TSSTI:1;  
    int TSSTU:1;      
    int TSITE:1;
    int TTSARU:1;  
    int reserve0:2;      
    int TSSARFE:1;      
    int TSSSR:1; 
    int TSPTPPSV2E:1; 
    int TSSPTPOEFE:1; 
    int TSSIPV6FE:1; 
    int TSSIPV4FE:1; 
    int TSSEME:1; 
    int TSSMRME:1; 
    int TSCNT:2; 
    int TSPFFMAE:1; 
    int reserve1:13;  
   }PTPTSCR; /*!< ,   Address offset: 0x700*/    
   
    struct type_PTPSSIR
  {
    int STSSI:8;    
    int reserve0:24; 
   }PTPSSIR; /*!< ,   Address offset: 0x704*/ 

    struct type_PTPTSHR
  {
    int STS:32;     
   }PTPTSHR; /*!< ,   Address offset: 0x708*/ 
   
    struct type_PTPTSLR
  {
    int STSS:31;  
    int STPNS:1; 
   }PTPTSLR; /*!< ,   Address offset: 0x70C*/ 
   
    struct type_PTPTSHUR
  {
    int TSUS:32;     
   }PTPTSHUR; /*!< ,   Address offset: 0x710*/ 

    struct type_PTPTSLUR
  {
    int TSUSS:31;     
    int TSUPNS:1; 
   }PTPTSLUR; /*!< ,   Address offset: 0x714*/    
   
    struct type_PTPTSAR
  {
    int TSA:32;     
   }PTPTSAR; /*!< ,   Address offset: 0x718*/ 

    struct type_PTPTTHR
  {
    int TTSH:32;     
   }PTPTTHR; /*!< ,   Address offset: 0x71C*/ 

    struct type_PTPTTLR
  {
    int TTSL:32;     
   }PTPTTLR; /*!< ,   Address offset: 0x720*/ 

    unsigned int RESERVED8[1];  /*!< Reserved, 0x724  */
    
   struct type_PTPTSSR
  {
    int TSSO:1;     
    int TSTTR:1;   
    int reserve0:30;  
   }PTPTSSR; /*!< ,   Address offset: 0x728*/ 
    
    unsigned int RESERVED9[564];  /*!< Reserved, 0x72C-0xFFC  */
    
   struct type_DMABMR
  {
    int SR:1;     
    int DA:1;   
    int DSL:4;   
    int EDFE:1; 
    int PBL:5;       
    int PM:2;  
    int FB:1;   
    int RDP:5;  
    int USP:1;       
    int FPM:1;
    int AAB:1; 
    int MB:1;   
    int reserve0:5;  
   }DMABMR; /*!< ,   Address offset: 0x1000*/ 
   
   struct type_DMATPDR
  {
    int TPD:32;     
   }DMATPDR; /*!< ,   Address offset: 0x1004*/    

   struct type_DMARPDR
  {
    int RPD:32;     
   }DMARPDR; /*!< ,   Address offset: 0x1008*/    
   
   struct type_DMARDLAR
  {
    uint32_t RDL:32;     
   }DMARDLAR; /*!< ,   Address offset: 0x100C*/     
   
   struct type_DMATDLAR
  {
    uint32_t TDL:32;     
   }DMATDLAR; /*!< ,   Address offset: 0x1010*/   
   
//    uint32_t DMASR; 
   struct type_DMASR
  {
    int TS:1;     
    int TPSS:1;   
    int TBUS:1;   
    int TJTS:1; 
    int ROS:1;       
    int TUS:1;  
    int RS:1;   
    int RBUS:1;  
    int RPSS:1;       
    int RWTS:1;
    int ETS:1; 
    int reserve0:1;     
    int FBES:1;   
    int ERS:1;  
    int AIS:1;       
    int NIS:1;
    int RPS:3; 
    int TPS:3;   
    int EBS:3;  
    int reserve1:1;     
    int MMCS:1;       
    int PMTS:1;
    int TSTS:1;     
    int reserve2:2; 
   }DMASR; /*!< ,   Address offset: 0x1014*/    
    
   struct type_DMAOMR
  {
    int reserve0:1;     
    int SR:1;     
    int OSF:1;   
    int RTC:2;
    int reserve1:1; 
    int FUGF:1; 
    int FEF:1;       
    int reserve2:5; 
    int ST:1;   
    int TTC:3;
    int reserve3:3; 
    int FTF:1;       
    int TSF:1;
    int reserve4:2; 
    int DFRF:1; 
    int RSF:1;
    int DTCEFD:1; 
    int reserve5:5;  
   }DMAOMR; /*!< ,   Address offset: 0x1018*/ 
   
   struct type_DMAIER
  {
    int TIE:1;     
    int TPSIE:1;     
    int TBUIE:1;   
    int TJTIE:1;
    int ROIE:1; 
    int TUIE:1; 
    int RIE:1;       
    int RBUIE:1; 
    int RPSIE:1;   
    int RWTIE:1;
    int ETIE:1; 
    int reserve0:2; 
    int FBEIE:1; 
    int ERIE:1;
    int AISE:1; 
    int NISE:1; 
    int reserve1:5;  
   }DMAIER; /*!< ,   Address offset: 0x101C*/    
   
   struct type_DMAMFBOCR
  {
    int MFC:16;     
    int OMFC:1;     
    int MFA:11;   
    int OFOC:1;
    int reserve1:3;  
   }DMAMFBOCR; /*!< ,   Address offset: 0x1020*/      
   
   struct type_DMARSWTR
  {
    int RSWTC:8;        
    int reserve0:24;  
   }DMARSWTR; /*!< ,   Address offset: 0x1024*/  
   
   unsigned int RESERVED10[8];  /*!< Reserved, 0x1028-0x1044  */
   
   struct type_DMACHTDR
  {
    int HTDAP:32;         
   }DMACHTDR; /*!< ,   Address offset: 0x1048*/  
   
   struct type_DMACHRDR
  {
    int HRDAP:32;        
   }DMACHRDR; /*!< ,   Address offset: 0x104C*/  
   
   struct type_DMACHTBAR
  {
    int HTBAP:32;        
   }DMACHTBAR; /*!< ,   Address offset: 0x1050*/  
   
   struct type_DMACHRBAR
  {
    int HRBAP:32;        
   }DMACHRBAR; /*!< ,   Address offset: 0x1054*/  
   
}ETHERNET_Type;

/*==========================
      FLASH registers
==========================*/

typedef struct
{
    struct type_ACR
    {
        unsigned int LATENCY :4;   // Flash wait states
        unsigned int reserve0:4;

        unsigned int PRFTEN  :1;   // Prefetch enable
        unsigned int ICEN    :1;   // Instruction cache enable
        unsigned int DCEN    :1;   // Data cache enable

        unsigned int ICRST   :1;   // Instruction cache reset
        unsigned int DCRST   :1;   // Data cache reset

        unsigned int reserve1:19;
    } ACR;                         /*!< Address offset: 0x00 */

    uint32_t KEYR;                 /*!< Address offset: 0x04 */
    uint32_t OPTKEYR;              /*!< Address offset: 0x08 */

    struct type_SR
    {
        unsigned int EOP      :1;
        unsigned int OPERR    :1;
        unsigned int reserve0 :2;
        unsigned int WRPERR   :1;
        unsigned int PGAERR   :1;
        unsigned int PGPERR   :1;
        unsigned int PGSERR   :1;
        unsigned int reserve1 :8;
        unsigned int BSY      :1;
        unsigned int reserve2 :15;
    } SR;                          /*!< Address offset: 0x0C */

    struct type_FLASH_CR
    {
        unsigned int PG       :1;
        unsigned int SER      :1;
        unsigned int MER      :1;
        unsigned int SNB      :4;
        unsigned int PSIZE    :2;
        unsigned int reserve0 :5;
        unsigned int STRT     :1;
        unsigned int reserve1 :7;
        unsigned int EOPIE    :1;
        unsigned int ERRIE    :1;
        unsigned int LOCK     :1;
        unsigned int reserve2 :5;
    } CR;                          /*!< Address offset: 0x10 */

    uint32_t OPTCR;                /*!< Address offset: 0x14 */

    uint32_t OPTCR1;               /*!< Address offset: 0x18 */

} FLASH_Type;
