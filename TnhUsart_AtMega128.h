#ifndef _TNHUSART_ATMEGA128_H
#define _TNHUSART_ATMEGA128_H

#include "TnhCommon.h"
#include "TnhTimer_AtMega128.h"

//---------------------------------------------------------------------
//UART0 initialize
// desired baud rate: 9600
// actual: baud rate:9615 (0.2%)
// char size: 8 bit
// parity: Disabled
//----------------------------------------------------------------
#define RX_BUF_SIZE 128
#define TX_BUF_SIZE 128

typedef struct
{
	unsigned char bRxNewData:1;
	unsigned char bRxOvf:1;
	unsigned char bTxOvf:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
} _bUsartStatus;

typedef struct {
	_bUsartStatus bitsStat;
	unsigned char byRxBufPos;		// Data가 RxBuf에 쓰여질 위치 이므로 수신된 Size와 동일함 
	unsigned char byRxBuf[RX_BUF_SIZE];
	unsigned char byRxFrameSize;
	unsigned char byTxBufCnt;
	unsigned char byTxBufPos;
	unsigned char byTxBuf[TX_BUF_SIZE];
}_UsartBuf;


_UsartBuf StUsart1;


//---------------------USART0 Function----------------------------
//----------------------------------------------------------------
enum {M16_NON, M16_24,M16_48,M16_96,M16_144,M16_192,M16_288,M16_384,M16_576,M16_768,M16_1152,M16_2304,M16_2500,M16_5000,M16_10000};

unsigned char FlagTimeOut;

/*
_UsartBuf StUsart0;
void Usart0_Init(char boardrate);
unsigned int Usart0_ReadByte(void);
void Usart0_WriteByte(unsigned char data);
void Usart0_WriteData(unsigned char *data, unsigned char len);
void Usart0_WriteStr(char *str);
//----------인터럽트 송신 
void Usart0_WriteDataByInt(unsigned char *data, unsigned char len);
*/

//----------------------------------------------------------------
//---------------------USART1 Function----------------------------
//----------------------------------------------------------------
void Usart1_Init(char boardrate);
unsigned int Usart1_ReadByte(void);
void Usart1_WriteByte(unsigned char data);
void Usart1_WriteData(unsigned char *data, unsigned char len);
void Usart1_WriteStr(char *str);
void Usart1_WriteDataByInt(unsigned char *data, unsigned char len);

#endif
