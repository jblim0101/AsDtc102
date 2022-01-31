#include "TnhUsart_AtMega128.h"
//---------------------------------------------------------------------
//UART0 initialize
// desired baud rate: 9600
// actual: baud rate:9615 (0.2%)
// char size: 8 bit
// parity: Disabled
//----------------------------------------------------------------
//---------------------USART0 Function----------------------------
//----------------------------------------------------------------
//enum {M16_24,M16_48,M16_96,M16_144,M16_192,M16_288,M16_384,M16_576,M16_768,M16_1152,M16_2304,M16_2500,M16_5000,M16_10000};
/*
void Usart0_Init(char boardrate)
{	//기본 8data 1Stop NoPrt
	cli();
	UCSR0B = 0x00; //disable while setting baud rate
	UCSR0A = 0x00;
	UCSR0C = 0x06;	//NoPrty
	UBRR0H=0x00;
	switch (boardrate) {
		case M16_24:	UBRR0H=0x01;	UBRR0L=0xA0;	break;
		case M16_48:	UBRR0L=0xCF;	break;
		case M16_96:	UBRR0L=0x67;	break;
		case M16_144:	UBRR0L=0x44;	break;
		case M16_192:	UBRR0L=0x33;	break;
		case M16_288:	UBRR0L=0x22;	break;
		case M16_384:	UBRR0L=0x19;	break;
		case M16_576:	UBRR0L=0x10;	break;	//에러율 +2.12% 
		case M16_768:	UBRR0L=0x0C;	break;
		case M16_1152:	UBRR0L=0x08;	break;
		case M16_2304:	UBRR0L=0x03;	break;	//에러율 +8.5% 비추천
		case M16_2500:	UBRR0L=0x03;	break;
		case M16_5000:	UBRR0L=0x01;	break;
		case M16_10000:	UBRR0L=0x00;	break;
		default:
			break;
	}
	UCSR0B = 0x98;	//TX,RX INT Enable
	sei();
}

unsigned int Usart0_ReadByte(void)
{
	unsigned int data=0;
	FlagTimeOut=0;
	Timer1_Init(TIMER_1SEC);
	while ((UCSR0A & 0x80) == 0) {
		if (FlagTimeOut!=0) {
			data=0xFF00;
			break;
		}
	}
	data|=UDR0;	// data는 2byte로 Low byte에 수신 Data가 자리함 
	Timer1_Init(TIMER_STOP);
	return data; //Timeout이면 0xFFXX가 전송됨 
}


void Usart0_WriteByte(unsigned char data)
{
	while (!(UCSR0A & (1<<UDRE0))) ;
	UDR0=data;
}

void Usart0_WriteData(unsigned char *data, unsigned char len)
{
	int i;
	for (i=0;i<len;i++) Usart0_WriteByte(data[i]);
}

void Usart0_WriteStr(char *str)
{
	unsigned char i=0;
	while (1) {
		if (str[i]==0xFF || str[i]==0x00) break;
		Usart0_WriteByte(str[i++]);
	}
}

void Usart0_WriteDataByInt(unsigned char *data, unsigned char len)
{
	unsigned char by;
	by=StUsart0.byTxBufCnt+len;
	if (by>=TX_BUF_SIZE) return;
	for (by=0;by<len;by++) {
		StUsart0.byTxBuf[StUsart0.byTxBufCnt]=data[by];
		StUsart0.byTxBufCnt++;
	}
	UCSR0B|=0x40;	//set TXCIE0 

}
*/
//----------------------------------------------------------------
//---------------------USART1 Function----------------------------
//----------------------------------------------------------------
void Usart1_Init(char boardrate)
{	//기본 8data 1Stop NoPrt
	cli();
	UCSR1B = 0x00; //disable while setting baud rate
	UCSR1A = 0x00;
	UCSR1C = 0x06;	//NoPrty
	UBRR1H=0x00;
	switch (boardrate) {
		case M16_24:	UBRR1H=0x01;	UBRR0L=0xA0;	break;
		case M16_48:	UBRR1L=0xCF;	break;
		case M16_96:	UBRR1L=0x67;	break;
		case M16_144:	UBRR1L=0x44;	break;
		case M16_192:	UBRR1L=0x33;	break;
		case M16_288:	UBRR1L=0x22;	break;
		case M16_384:	UBRR1L=0x19;	break;
		case M16_576:	UBRR1L=0x10;	break;	//에러율 +2.12% 
		case M16_768:	UBRR1L=0x0C;	break;
		case M16_1152:	UBRR1L=0x08;	break;
		case M16_2304:	UBRR1L=0x03;	break;	//에러율 +8.5% 비추천
		case M16_2500:	UBRR1L=0x03;	break;
		case M16_5000:	UBRR1L=0x01;	break;
		case M16_10000:	UBRR1L=0x00;	break;
		default:
			break;
	}
	if (boardrate!=M16_NON) UCSR1B = 0x98;	//TX,RX INT Enable
	sei();
}

unsigned int Usart1_ReadByte(void)
{
	unsigned int data=0;
	FlagTimeOut=0;
	Timer1_Init(TIMER_1SEC);
	while ((UCSR1A & 0x80) == 0) {
		if (FlagTimeOut!=0) {
			data=0xFF00;
			break;
		}
	}
	data|=UDR1;	// data는 2byte로 Low byte에 수신 Data가 자리함 
	Timer1_Init(TIMER_STOP);
	return data; //Timeout이면 0xFFXX가 전송됨 
}


void Usart1_WriteByte(unsigned char data)
{	//TX Busy가 아닐때 까지 대기 후 전송 처리
	while ((UCSR1A & 0x20) ==0) ;
	UDR1=data;
}

void Usart1_WriteData(unsigned char *data, unsigned char len)
{
	int i;
	for (i=0;i<len;i++) Usart1_WriteByte(data[i]);
}

void Usart1_WriteStr(char *str)
{
	unsigned char i=0;
	while (str[i]!=0xFF) {
		Usart1_WriteByte(str[i]);
	}
}

void Usart1_WriteDataByInt(unsigned char *data, unsigned char len)
{
	unsigned char by;
	by=StUsart1.byTxBufCnt+len;
	if (by>=TX_BUF_SIZE) return;
	for (by=0;by<len;by++) {
		StUsart1.byTxBuf[StUsart1.byTxBufCnt]=data[by];
		StUsart1.byTxBufCnt++;
	}
	UCSR1B|=0x40;	//set TXCIE0 

}


