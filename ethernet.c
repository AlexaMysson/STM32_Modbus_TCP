#include "ethernet.h"
#include "Definition.h"

#pragma data_alignment=32
ETH_DRIVER_Type ETH_Driver;
static const uint8_t MAC_Address[6]=
{
    0x02,
    0x12,
    0x34,
    0x56,
    0x78,
    0x9A
};

uint8_t IP_Address[4] =
{
    192,
    168,
    1,
    101
};

uint8_t Mask[4] =
{
    255,
    255,
    255,
    0
};

uint8_t Gateway[4] =
{
    192,
    168,
    1,
    1
};

uint16_t compute_checksum(uint8_t *Data, uint16_t Length)
{
    uint32_t Sum;
    uint16_t Word;
    Sum = 0;
    while(Length > 1)
    {
        Word = ((uint16_t)Data[0] << 8) | Data[1];
        Sum += Word;
        Data += 2;
        Length -= 2;
    }
    if(Length)
    {
        Sum += ((uint16_t)Data[0] << 8);
    }
    while(Sum >> 16)
    {
        Sum = (Sum & 0xFFFF) + (Sum >> 16);
    }
    return (uint16_t)(~Sum);
}

void ETH_SetMACAddress(void)
{
    ETH->MACA0LR.MACA0L =
            ((uint32_t)MAC_Address[3] << 24) |
            ((uint32_t)MAC_Address[2] << 16) |
            ((uint32_t)MAC_Address[1] << 8 ) |
             (uint32_t)MAC_Address[0];

    ETH->MACA0HR.MACA0H =
            ((uint32_t)MAC_Address[5] << 8) |
             (uint32_t)MAC_Address[4];
}

void ETH_TXDescriptorInit(void)
{
    uint32_t i;

    for(i=0;i<ETH_TX_DESC_COUNT;i++)
    {
        ETH_Driver.TxDesc[i].Status.OWN = 0;
        ETH_Driver.TxDesc[i].Status.FS = 1;
        ETH_Driver.TxDesc[i].Status.LS = 1;
        ETH_Driver.TxDesc[i].Status.TCH = 1;
        ETH_Driver.TxDesc[i].ControlBufferSize = ETH_TX_BUFFER_SIZE;
        ETH_Driver.TxDesc[i].Buffer1 =(uint32_t)ETH_Driver.TxBuffer[i];
        if(i==(ETH_TX_DESC_COUNT-1))
        {
            ETH_Driver.TxDesc[i].Buffer2 =(uint32_t)&ETH_Driver.TxDesc[0];
        }
        else
        {
            ETH_Driver.TxDesc[i].Buffer2 =(uint32_t)&ETH_Driver.TxDesc[i+1];
        }
    }
    ETH_Driver.CurrentTx = 0;
}

void ETH_RXDescriptorInit(void)
{
    uint32_t i;
    for(i=0;i<ETH_RX_DESC_COUNT;i++)
    {
        ETH_Driver.RxDesc[i].Status.OWN = 1;
        ETH_Driver.RxDesc[i].ControlBufferSize =ETH_RX_BUFFER_SIZE;
        ETH_Driver.RxDesc[i].ControlBufferSize |= (1<<14);
        ETH_Driver.RxDesc[i].Buffer1 =(uint32_t)ETH_Driver.RxBuffer[i];
        if(i==(ETH_RX_DESC_COUNT-1))
        {
            ETH_Driver.RxDesc[i].Buffer2 =(uint32_t)&ETH_Driver.RxDesc[0];
        }
        else
        {
            ETH_Driver.RxDesc[i].Buffer2 =(uint32_t)&ETH_Driver.RxDesc[i+1];
        }
    }
    ETH_Driver.CurrentRx = 0;
}

void ETH_SetDMADescriptors(void)
{
ETH->DMARDLAR.SRL =(uint32_t)&ETH_Driver.RxDesc[0];
ETH->DMATDLAR.STL =(uint32_t)&ETH_Driver.TxDesc[0];
}

void ETH_MAC_Init(void)
{
    ETH->DMABMR.SR = 1;
    while(ETH->DMABMR.SR);

    ETH->MACFFR.PM   = 0;
    ETH->MACFFR.HU   = 0;
    ETH->MACFFR.HM   = 0;
    ETH->MACFFR.DAIF = 0;
    ETH->MACFFR.PAM  = 0;
    ETH->MACFFR.BFD  = 0;
    ETH->MACFFR.PCF  = 0;
    ETH->MACFFR.SAIF = 0;
    ETH->MACFFR.SAF  = 0;
    ETH->MACFFR.HPF  = 0;
    ETH->MACFFR.RA   = 0;

    ETH->MACFCR.TFCE = 0;
    ETH->MACFCR.RFCE = 0;

    ETH->MACCR.RE = 0;
    ETH->MACCR.TE = 0;

    ETH->MACCR.WD   = 0;
    ETH->MACCR.JD   = 0;
    ETH->MACCR.IFG  = 0;
    ETH->MACCR.CSD  = 0;
    ETH->MACCR.FES  = 1;
    ETH->MACCR.DM   = 1;
    ETH->MACCR.LM   = 0;
    ETH->MACCR.IPCO = 0;
    ETH->MACCR.RD   = 0;
    ETH->MACCR.BL   = 0;

    ETH->DMABMR.DA  = 1;
    ETH->DMABMR.USP = 1;
    ETH->DMABMR.RDP = 32;
    ETH->DMABMR.PBL = 32;
    ETH->DMABMR.AAB = 1;
    ETH->DMABMR.FB  = 1;

    ETH->DMAOMR.TSF = 1;
    ETH->DMAOMR.RSF = 1;
    ETH->DMAOMR.OSF = 1;

    ETH->DMAOMR.FTF = 1;

    while(ETH->DMAOMR.FTF);

    ETH->DMAOMR.ST = 0;
    ETH->DMAOMR.SR = 0;
}

void ETH_DMAStart(void)
{
  
    ETH->DMAOMR.SR = 1;
    ETH->DMAOMR.ST = 1;

    ETH->MACCR.RE = 1;
    ETH->MACCR.TE = 1;

    ETH->DMARPDR.RPD = 0;
    ETH->DMATPDR.TPD = 0;
}

void ETH_SendFrame(uint8_t *Data, uint16_t Length)
{
    uint32_t i;
    uint16_t CopyLength;
    CopyLength = Length;
    
    while(ETH_Driver.TxDesc[ETH_Driver.CurrentTx].Status.OWN);

    for(i = 0; i < CopyLength; i++)
    {
        ETH_Driver.TxBuffer[ETH_Driver.CurrentTx][i] = Data[i];
    }
    if(CopyLength < 60)
    {
        for(i = CopyLength; i < 60; i++)
        {
            ETH_Driver.TxBuffer[ETH_Driver.CurrentTx][i] = 0;
        }
        Length = 60;
    }
    
    ETH_Driver.TxDesc[ETH_Driver.CurrentTx].ControlBufferSize =(ETH_Driver.TxDesc[ETH_Driver.CurrentTx].ControlBufferSize & ~0x1FFF) |Length;
    ETH_Driver.TxDesc[ETH_Driver.CurrentTx].Status.OWN = 1;
    ETH->DMATPDR.TPD = 0;
    ETH_Driver.CurrentTx++;
    if(ETH_Driver.CurrentTx >= ETH_TX_DESC_COUNT)
    {
        ETH_Driver.CurrentTx = 0;
    }
}

uint16_t ETH_ReceiveFrame(uint8_t *buffer, uint16_t max_len)
{
    if (ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.OWN == 1) {
        return 0;
    }

    if (ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.ES == 1) {
        ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.OWN = 1;
        ETH_Driver.CurrentRx++;
        if (ETH_Driver.CurrentRx >= ETH_RX_DESC_COUNT) {
            ETH_Driver.CurrentRx = 0;
        }
        return 0;
    }

    if (!(ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.FS &&
        ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.LS)) {
        ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.OWN = 1;
        ETH_Driver.CurrentRx++;
        if (ETH_Driver.CurrentRx >= ETH_RX_DESC_COUNT) {
            ETH_Driver.CurrentRx = 0;
        }
        return 0;
    }
uint16_t frame_len = ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.FL;
if(frame_len >= 4)
{
    frame_len -= 4;
}
else
{
    frame_len = 0;
}

    if (frame_len > max_len) {
        frame_len = max_len;
    }

    uint8_t *rx_buf = (uint8_t *)ETH_Driver.RxBuffer[ETH_Driver.CurrentRx];
    for (uint32_t i = 0; i < frame_len; i++) {
        buffer[i] = rx_buf[i];
    }
    
    ETH_Driver.RxDesc[ETH_Driver.CurrentRx].Status.OWN = 1;
    ETH->DMARPDR.RPD = 0;

    ETH_Driver.CurrentRx++;
    if (ETH_Driver.CurrentRx >= ETH_RX_DESC_COUNT) {
        ETH_Driver.CurrentRx = 0;
    }

    return frame_len;
}

void ETH_SendARPReply(ARP_PACKET_Type *Request)
{
    uint8_t Buffer[ETH_MAX_PACKET_SIZE];
    ETH_HEADER_Type *ETH;
    ARP_PACKET_Type *ARP;
    uint32_t i;

    ETH = (ETH_HEADER_Type *)Buffer;
    ARP = (ARP_PACKET_Type *)(Buffer + sizeof(ETH_HEADER_Type));

    for(i = 0; i < 6; i++)
    {
        ETH->Destination[i] = Request->SenderMAC[i];
        ETH->Source[i] = MAC_Address[i];
    }

    ETH->Type = 0x0608;
    
    ARP->Hardware = 0x0100;

    ARP->Protocol = 0x0008;

    ARP->HardwareLength = 6;

    ARP->ProtocolLength = 4;

    ARP->Operation = 0x0200;

    for(i = 0; i < 6; i++)
    {
        ARP->SenderMAC[i] = MAC_Address[i];
    }
    for(i = 0; i < 4; i++)
    {
        ARP->SenderIP[i] = IP_Address[i];
    }
    for(i = 0; i < 6; i++)
    {
        ARP->TargetMAC[i] = Request->SenderMAC[i];
    }
    for(i = 0; i < 4; i++)
    {
        ARP->TargetIP[i] = Request->SenderIP[i];
    }
    ETH_SendFrame(Buffer,sizeof(ETH_HEADER_Type) + sizeof(ARP_PACKET_Type));
}

void ETH_SendICMPReply(uint8_t *RxBuffer, uint16_t RxLength)
{
    ETH_HEADER_Type *ETH_RX;

    ETH_HEADER_Type *ETH_TX;

    IP_HEADER_Type *IP_TX;

    ICMP_HEADER_Type *ICMP_RX;

    ICMP_HEADER_Type *ICMP_TX;

    uint8_t Buffer[ETH_MAX_PACKET_SIZE];

    uint16_t IPLength;

    uint16_t DataLength;

    uint32_t i;

    if(RxLength < (14 + 20 + 8))
    {
        return;
    }

    ETH_RX = (ETH_HEADER_Type *)RxBuffer;

    ICMP_RX = (ICMP_HEADER_Type *)(RxBuffer + 14 + 20);

    if(ICMP_RX->Type != 8)
    {
        return;
    }

    ETH_TX = (ETH_HEADER_Type *)Buffer;

    IP_TX = (IP_HEADER_Type *)(Buffer + 14);

    ICMP_TX = (ICMP_HEADER_Type *)(Buffer + 14 + 20);
    
    for(i = 0; i < 6; i++)
    {
        ETH_TX->Destination[i] = ETH_RX->Source[i];

        ETH_TX->Source[i] = MAC_Address[i];
    }

    ETH_TX->Type = 0x0008;
    
    IP_TX->VerLen = 0x45;

    IP_TX->TOS = 0;

    DataLength = RxLength - 14 - 20 - 8;

    IPLength = 20 + 8 + DataLength;

    IP_TX->TotalLen = ((IPLength >> 8) & 0xFF) | ((IPLength & 0xFF) << 8);

    IP_TX->ID = 0;

    IP_TX->FlagsOffset = 0;

    IP_TX->TTL = 64;

    IP_TX->Protocol = 1;

    IP_TX->Checksum = 0;

    for(i = 0; i < 4; i++)
    {
        ((uint8_t *)&IP_TX->SrcIP)[i] = IP_Address[i];

        ((uint8_t *)&IP_TX->DstIP)[i] = ((uint8_t *)&ETH_RX[1])[12 + i];
    }
    
    ICMP_TX->Type = 0;

    ICMP_TX->Code = 0;

    ICMP_TX->Checksum = 0;

    ICMP_TX->ID = ICMP_RX->ID;

    ICMP_TX->Sequence = ICMP_RX->Sequence;

    for(i = 0; i < DataLength; i++)
    {
        ((uint8_t *)ICMP_TX)[8 + i] = ((uint8_t *)ICMP_RX)[8 + i];
    }

IP_TX->Checksum = compute_checksum((uint8_t *)IP_TX,20);

IP_TX->Checksum =
    (IP_TX->Checksum >> 8) |
    (IP_TX->Checksum << 8);

ICMP_TX->Checksum = compute_checksum((uint8_t *)ICMP_TX,
                                     8 + DataLength);

ICMP_TX->Checksum =
    (ICMP_TX->Checksum >> 8) |
    (ICMP_TX->Checksum << 8);

    ETH_SendFrame(Buffer,14 + IPLength);
}

void ETH_ProcessFrame(uint8_t *Data, uint16_t Length)
{
    ETH_HEADER_Type *ETH;

    ARP_PACKET_Type *ARP;

    IP_HEADER_Type *IP;

    uint32_t i;

    uint8_t Match;

    if(Length < sizeof(ETH_HEADER_Type))
    {
        return;
    }

    ETH = (ETH_HEADER_Type *)Data;

   
    if(ETH->Type == 0x0608)
    {
        if(Length < (sizeof(ETH_HEADER_Type) + sizeof(ARP_PACKET_Type)))
        {
            return;
        }

        ARP = (ARP_PACKET_Type *)(Data + sizeof(ETH_HEADER_Type));

        if(ARP->Operation != 0x0100)
        {
            return;
        }

        Match = 1;

        for(i = 0; i < 4; i++)
        {
            if(ARP->TargetIP[i] != IP_Address[i])
            {
                Match = 0;

                break;
            }
        }

        if(Match == 1)
        {
            ETH_SendARPReply(ARP);
        }

        return;
    }

    if(ETH->Type == 0x0008)
    {
        if(Length < (sizeof(ETH_HEADER_Type) + sizeof(IP_HEADER_Type)))
        {
            return;
        }

        IP = (IP_HEADER_Type *)(Data + sizeof(ETH_HEADER_Type));

        Match = 1;

        for(i = 0; i < 4; i++)
        {
            if(((uint8_t *)&IP->DstIP)[i] != IP_Address[i])
            {
                Match = 0;

                break;
            }
        }

        if(Match == 0)
        {
            return;
        }

        if(IP->Protocol != 1)
        {
            return;
        }

        ETH_SendICMPReply(Data, Length);
    }
}

void ETH_Poll(void)
{
    static uint8_t Buffer[ETH_MAX_PACKET_SIZE];
    uint16_t Length;

    Length = ETH_ReceiveFrame(Buffer,ETH_MAX_PACKET_SIZE);

    if(Length == 0)
    {
        return;
    }
    
    ETH_ProcessFrame(Buffer,Length);
}




