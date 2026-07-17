#ifndef ETHERNET_H
#define ETHERNET_H

#include "Definition.h"
#include <stdint.h>

#define ETH_TX_DESC_COUNT        4
#define ETH_RX_DESC_COUNT        4
#define ETH_MAX_PACKET_SIZE    1524
#define ETH_TX_BUFFER_SIZE     1524
#define ETH_RX_BUFFER_SIZE     1524

#pragma pack(push,1)
typedef struct
{
    struct
    {
        uint32_t DB       :1; //Устанавливается, если передача была отложена из-за занятости среды (носителя).
        uint32_t UF       :1; //Ошибка недополнения – данные не поступили в FIFO передатчика вовремя (обычно из-за низкой пропускной способности шины).
        uint32_t ED       :1; //Превышение времени отсрочки – передача откладывалась дольше допустимого (только для полудуплекса).
        uint32_t CC       :4; //Счётчик коллизий (4 бита) – количество коллизий, произошедших при передаче кадра (для полудуплекса).
        uint32_t VF       :1; //Указывает, что переданный кадр содержал тег VLAN (устанавливается, если в кадре присутствовал VLAN-тег).

        uint32_t EC       :1; //Превышение допустимого числа коллизий (обычно 16) – передача прервана.
        uint32_t LCO      :1; //Потеря несущей во время передачи.
        uint32_t NC       :1; //Отсутствие несущей во время передачи.
        uint32_t LCA      :1; //
        uint32_t IPE      :1; //        
        uint32_t FF       :1; //кадр был сброшен (из-за ошибки).         
        uint32_t JT       :1; //превышение времени передачи (джаббер).   
        uint32_t ES       :1; //общая ошибка.   
        
        uint32_t IHE      :1; //ошибка в IP заголовке (если включена проверка).    
        uint32_t TTSS     :1; //       
        uint32_t reserve0 :2;
        uint32_t TCH      :1; //если 1, то Buffer2 содержит адрес следующего дескриптора (цепочка), если 0 – Buffer2 содержит адрес второго буфера (для разрывного буфера).        
        uint32_t TER      :1; //конец кольца (последний дескриптор).        
        uint32_t CIC      :2; // управление вставкой контрольной суммы (2 бита): 00 – не вставлять, 01 – только IP, 10 – IP и TCP/UDP, 11 – зарезервировано.        
        
        uint32_t reserve1 :1;
        uint32_t TTSE     :1; // включение временной метки.        
        uint32_t DP       :1; // вставка адреса назначения (для PTP).        
        uint32_t DC       :1; //      
        uint32_t FS       :1; //Указывает, что данный буфер является последним в пакете.
        uint32_t LS       :1; //Указывает, что данный буфер является первым в пакете.
        uint32_t IC       :1; //Запрет аппаратного добавления контрольной суммы.
        uint32_t OWN      :1; //Бит владения(1-DMA, 0-CPU)              

    }Status;

volatile uint32_t ControlBufferSize; //Размер буфера и управляющие биты

volatile uint32_t Buffer1; //адрес первого буфера данных.

volatile uint32_t Buffer2; //адрес второго буфера (или следующего дескриптора, если TCH=1).

}ETH_TX_DESC_Type;
#pragma pack(pop)
typedef struct
{
    struct
    {
        uint32_t ESA      :1;
        uint32_t CE       :1;
        uint32_t DE       :1;
        uint32_t RE       :1;

        uint32_t RWT      :1;
        uint32_t FT       :1;
        uint32_t LCO      :1;
        uint32_t IPHCE      :1;

        uint32_t LS       :1;
        uint32_t FS       :1;

        uint32_t VLAN     :1;
        uint32_t OE       :1;

        uint32_t LE       :1;
        uint32_t SAF      :1;
        uint32_t DE2      :1;
        uint32_t ES       :1;

        uint32_t FL       :14;

        uint32_t AFM      :1;
        uint32_t OWN      :1;

    }Status;

volatile uint32_t ControlBufferSize;

volatile uint32_t Buffer1;

volatile uint32_t Buffer2;

}ETH_RX_DESC_Type;

typedef struct
{
    ETH_TX_DESC_Type TxDesc[ETH_TX_DESC_COUNT];

    ETH_RX_DESC_Type RxDesc[ETH_RX_DESC_COUNT];

    uint8_t TxBuffer[ETH_TX_DESC_COUNT][ETH_TX_BUFFER_SIZE];

    uint8_t RxBuffer[ETH_RX_DESC_COUNT][ETH_RX_BUFFER_SIZE];

    uint8_t CurrentTx;

    uint8_t CurrentRx;

}ETH_DRIVER_Type;

typedef struct
{
    uint8_t  *Buffer;

    uint16_t Length;

}ETH_FRAME_Type;
#pragma pack(push,1)
typedef struct
{
    uint8_t Destination[6];

    uint8_t Source[6];

    uint16_t Type;

}ETH_HEADER_Type;

typedef struct
{
    uint16_t Hardware;

    uint16_t Protocol;

    uint8_t  HardwareLength;

    uint8_t  ProtocolLength;

    uint16_t Operation;

    uint8_t  SenderMAC[6];

    uint8_t  SenderIP[4];

    uint8_t  TargetMAC[6];

    uint8_t  TargetIP[4];

}ARP_PACKET_Type;

// Структуры IP и ICMP (определите в заголовке)
typedef struct {
    uint8_t  VerLen;        // Version (4) + IHL (4)
    uint8_t  TOS;           // Type of Service
    uint16_t TotalLen;      // Общая длина (в сетевом порядке)
    uint16_t ID;            // Идентификатор
    uint16_t FlagsOffset;   // Флаги + смещение фрагмента
    uint8_t  TTL;           // Time To Live
    uint8_t  Protocol;      // Протокол (1 – ICMP, 6 – TCP, 17 – UDP)
    uint16_t Checksum;      // Контрольная сумма заголовка
    uint32_t SrcIP;
    uint32_t DstIP;
} IP_HEADER_Type;

typedef struct {
    uint8_t Type;           // 8 – Echo Request, 0 – Echo Reply
    uint8_t Code;           // 0
    uint16_t Checksum;      // Контрольная сумма ICMP (всего пакета)
    uint16_t ID;
    uint16_t Sequence;
    // Далее данные (копируются из запроса)
} ICMP_HEADER_Type;
#pragma pack(pop)
void ETH_SetMACAddress(void);

void ETH_TXDescriptorInit(void);

void ETH_RXDescriptorInit(void);

void ETH_SetDMADescriptors(void);

void ETH_DMAStart(void);

uint8_t ETH_GetFrame(ETH_FRAME_Type *Frame);

void ETH_SendFrame(uint8_t *data, uint16_t len);

void ETH_Poll(void);

uint16_t ETH_ReceiveFrame(uint8_t *buffer, uint16_t max_len);


#endif