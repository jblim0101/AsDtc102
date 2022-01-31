//--------------------------------------------------------------------------------------------
//Project DT-101 program by TNH 2018.08.21
//Base Model DT-100 (SPCD-8) - 7'Segment Type
//Feature : Display Oled 128x64 & New GUI
//--------------------------------------------------------------------------------------------
//Sensor�� �з� ������ HPA(0.1KPA)�� ���� 
//���� Ư���� ����(ADC 1V) �ְ�(ADC 4V) ���� HPA ������ ���,  0V�� �з� ���� �װ�Ƽ�� Ư�� ���´� ����Ǿ� �����.   
//---------------------------------------------------------------------------------------------
//Ver1.8 Short Key ������ ���Ͽ� ByKey�� ó�� �� �� Clear�ϴ� ������� ����   
//Ver1.7 2015.11.23 Spider One Request Multi Sending �߰� ID 0�̸� ��ä�� ���� (USATR ���� ���ͷ��� ��� �̿�)
//Ver1.6 2015.10.08 Spider One Request One Sending ������� ���� 
//Ver1.50 2015.08.20 [�߰�] Customer RS232 Protocol SPIDER_ACTIVE��� �߰� 
//Ver1.41 2015.08.24 [����] Ver1.50������ Sensoe P1 KPA���� ǥ�ý� ��ǥ�ð� ���� �״�� �����Ǿ� �ڸ����� Ʋ���� ���� �߰�  
//Ver1.40 2015.08.24 [����] Ver1.50������ Last Memory �ȵǴ� ���� �߰� , Norǥ�� �ֵ����� PMode21���� ����Ǵµ� PMode20�� üĿ�Ͽ� �߻�->üĿ ����   
//Ver1.30 2012.03.09 [����] Eagle EYE���� ���۰��� �з¿��� [ADC * AVG_COUNT]�� ���� 
//Ver1.20 2012.02.03 [�߰�] Eagle EYE��� �߰� 
//Ver1.06 2012.02.03 [����] PSI���� �ٸ� ������ ����� ���� �з��� Trigger��ó�� ������ ���� ������ ���Ͽ� ���������� Trigger�Ǵ� ���󰳼� 
//Ver1.05  2012.01.15 EEPROM�� Cal Block Size�� 5���� 6���� ����(��ȣ�ִ� ������ ����ȯ�� �ȵǾ� ��ġ��)
//Ver1.03  2012.01.15 [����]FAC_INIT���� CAL�� ���� �κ� ����
//Ver1.03  2012.01.15 [����] Delay Time - ��ȿæ���� ����� ���� AVG�� Max Count�� ����
//Ver1.03  2012.01.15 [����] ���������� AVG�� ������� ���� - KALMAN_2 ����
//Ver1.02  2012.01.14 [����]"----"ǥ���߿� �з��� �������·� ���������� ��Ÿ�� -> [����]FlagLowPrs/FlagHighPrs Clear�� ��Ʈ������ ~��� !�� ����Ͽ� ���� �߻�
//Ver1.02  2012.01.13 Low Leve�� ����ó������ �ʰ� ���� ������ ó�� 
//Ver1.01  2011.12.29 Display ������ ���� - ADC�������� ���� 2.5ms�ֱ� ���� ->Floating point����� ���� ������� �����Ͽ� �ҿ�ð� ����
//Ver1.00  2011.12.11 Build
//Ver0.99h 2011.12.09 Delay Time���� 
//Ver0.99h 2011.12.09 �Ѽ�ȯ��忡�� ���ǥ�� ���� ����
//Ver0.99h 2011.12.09 - ��ȯ ��忡�� ǥ�ظ�� ���� Key�� UP+DOWN���� ����
//Ver0.99h 2011.12.09 - ��ȯ��� Last Memory��� �߰� (ByChLast �� Bit3�� 1�̸� ��ȯǥ�ø���)
//Ver0.99e ADC���� ������ 10���� �ӽ� ó�� 
//Ver0.98g ADCó�� ��� �� ���Ͽ� 4096���� ����� ��� ä�ù� RS232��� ���� CAL RATE��� �߰� 
//Ver0.99f EagleEye Comport�߰�  
//Ver0.99e Last Channel ��� �߰� Channel������ 1���̻� �����ؾ� ������ / FAC CALB CLR_CAR��� ����
//Ver0.99d channel ADC offsetó�� ,���� Offset ó�� ��ȭ
//ver0.99 ���� Offset�� int���� ��Ź� ROM���� Ȯ��ó���� (����� 0����) 
//Ver0.99 ���� �߻��� ������ ���������� 10�ʰ� ���� ǥ����.(���� ǥ�ÿ��� ����) 
//Ver0.99 ���� ����� TrgOn/Off,Hist��� Default�� �ǵ��� �� ref:case 62
//Ver0.99 Unit�� ����ÿ��� TrgOn/Off,Hist ���� ���� ��������� ����Unit�� �µ��� ��ȯ��
//Ver0.99 Digit ǥ��� ���� (design_ref_xx.xls����)
//Ver0.98 a 2011.11.09 Histerisis ����ȵ� 
//Ver0.98 ��� æ���� Sensor�� None�� ���� : �ʱ�ȭ �����Ϸ�
//Ver0.98 2011.11.02 ALL Copy�ȵ� : case74 ����
//Ver0.98 2011.11.02 �з¼��� ������ ���� ���� �ȵ� :
//Ver0.97 2011.10.26 �з��� �ִ밪���� ǥ�õ��� �ʵ�. : Sensor Resulation 1024x4->1023x4
//Ver0.96 Sensor������ 1~5V���������� ���Ͽ� iPrsMin�� 1V�������� �����ϰ� 0V������ �����Ͽ� ������
//Ver0.95 Edit��尡 CAL���� ����, ��������� �ִ���� 8���� 
//Ver0.94 2011.10.18 Key Up/Down ���� + OverLoad Low Active�� ����
//Ver0.93 2011.10.08  CAL�� ��� �ð��� 1�η� ���� 
//Ver0.93 2011.10.06 Save, Load�� ������ ���ֱ� (���� ó���� ADC OFF)
//2011.10.4 Ver0.92 SEND & RCV SENSOR DATA���� ó�� ��
//2011.10.4 Ver0.91 Send Sensor & MAX_CHANNEL�̿� �Ϸ� 
//2011.10.2 CH2 Sensor�� None�� ������ ��� ���� 0���� ǥ�õ�
//Ver 0.2 2011.09.28  �̿� : FAC��� , ������� ��� ����or ���� -> Up/Dn Long Key �ߴ�/����,  
//Ver 0.1 2011.09.19

#define F_CPU 16000000UL
#include "Dtc101.h"

#define DEBUG 0		// 1 �̸� Lock üĿ �ߴ� 
#define DEBUG_TIME 0
#define DEBUG_TRX 0
#define KALMAN_2 1	//Ver1.03 Kalman2����
//--------------------------------------------------------------------------------------
//-------------------Select Protocol-------------------------------------------------------
//--------------------------------------------------------------------------------------
#define VTVM 1	//Volt Meter
#define Eagle_EYE_ACTIVE 0 // 1�̸� TX Data���� 
#define SPIDER_ACTIVE 0		//Ver1.50 // 1�̸� RS232 Customer Protocol 
#define SPIDER_SINGLE_ACTIVE 1		//Ver1.60 // 1�̸� RS232 Customer Protocol for Single channel 

//--------------------------------------------------------------------------------------
//-----------------------------���ͷ��� Vector����-------------------------------------- 
//--------------------------------------------------------------------------------------
ISR(INT0_vect)
{
	cli();
	//....User	
	sei();
}

//---------------------------------------------------------------------
ISR(USART0_RX_vect)
{
	cli();
//	while ((UCSR0A & 0x80) == 0) ;
//	StUsart0.byRxBuf[StUsart0.byRxBufPos++]=UDR0;
//	if (StUsart0.byRxBufPos>=MAX_RXBUF_SIZE) StUsart0.byRxBufPos=0; 
	sei();
}

//---------------------------------------------------------------------
ISR(USART1_RX_vect)
{
	cli();
	while ((UCSR1A & 0x80) == 0) ;
	StUsart1.byRxBuf[StUsart1.byRxBufPos++]=UDR1;
	if (StUsart1.byRxBufPos>=MAX_RXBUF_SIZE) StUsart1.byRxBufPos=0; 
	ByRxTimeCnt=1;
	sei();
}

//---------------------------------------------------------------------
ISR(USART1_TX_vect)
{
	//USART TX�� ��� ������ �۽� ���ۿ� Data�� �����ͼ� ����. 
	cli();
	unsigned char by;
	by=StUsart1.byTxBufCnt-StUsart1.byTxBufPos;
	if (by==0) {
		StUsart1.byTxBufPos=0;
		StUsart1.byTxBufCnt=0;
		UCSR1B &= 0xBF;	//Clear TXCIE0
	} else {	//Send Data	
		while (!(UCSR0A & (1<<UDRE0))) ;
		UDR1=StUsart1.byTxBuf[StUsart1.byTxBufPos];
		StUsart1.byTxBufPos++;
		if(by==1 || StUsart1.byTxBufPos>=TX_BUF_SIZE) {
			StUsart1.byTxBufPos=0;
			StUsart1.byTxBufCnt=0;
			UCSR1B &= 0xBF;	//Clear TXCIE0
		}
	}	
	sei();
}

//---------------------------------------------------------------------
ISR(TIMER0_COMP_vect)
{
	cli();
	//....User	
	sei();
}

//---------------------------------------------------------------------
ISR(TIMER1_COMPA_vect)
{	//�����ֱ��� Main System Clock Ŭ���� ������ 
	cli();
	IErrorTimeCnt++;
	ISystemCnt++;		//���÷� �� ���ۿ��� Clear�Ǿ� �� ��� ���� �ʿ信 ���� ����  
	Tm_mSec++;			//RUN Mode���� �ʱ�ȭ�Ǹ� �ð�ī���͸� ���Ͽ� ���Ǹ�,mS�� �ƴϰ� Main System Clock ī���ͷ� ��� 
	FlagSystem|=0x01; 	//Main System Clock�ֱ�� SysyUDR1 1 124em Flag Set
	sei();
}

//---------------------------------------------------------------------
ISR(TIMER2_COMP_vect)
{
	cli();
	IErrorTimeCnt++;
	ISystemCnt++;		//���÷� �� ���ۿ��� Clear�Ǿ� �� ��� ���� �ʿ信 ���� ����  
	Tm_mSec++;			//RUN Mode���� �ʱ�ȭ�Ǹ� �ð�ī���͸� ���Ͽ� ���Ǹ�,mS�� �ƴϰ� Main System Clock ī���ͷ� ��� 
	FlagSystem|=0x01; 	//Main System Clock�ֱ�� Sysyem Flag Set
	sei();
}

//---------------------------------------------------------------------
ISR(ADC_vect)
{
	cli();
	#if DEBUG_TIME
		ClrBit(PORTD,6);	//DEBUG Time check
	#endif
	AdcValue=ADC; //Note) ADCH�� �а� ADCL�� ������ ���ۿ���
	//Ver098g AdcValue*=4;	//Ver0.2 ADC�� 12bit�������� ��ƾ   
	if (AdcCnt==0) {
		AdcValueTotal=0;

	} else	{
		AdcValueTotal+=AdcValue;	//��4ȸ �հ� 4096
	}
	AdcCnt++;
	if (AdcCnt>AVG_COUNT) AdcClose(); 
	#if DEBUG_TIME
		SetBit(PORTD,6);	//DEBUG Time check
	#endif
	sei();

}

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


//----------------------------------------------------------------
//---------USART1 ApplicationFunction(MultiPort Protocol)---------
//----------------------------------------------------------------
void Usart1_SendSensorData(unsigned char channel)
{
	unsigned char bybuf[ROM_SENSOR_LENGTH+4];
	EncodeSensorData(channel,&bybuf[3]);
	bybuf[0]=STX;
	bybuf[1]= 0;	//CMD 0: Sensor data 1: Channel Data
	bybuf[2]=channel;
	bybuf[ROM_SENSOR_LENGTH+3]=ETX;
	Usart1_WriteData(bybuf,ROM_SENSOR_LENGTH+4);
}

void Usart1_SendChData(unsigned char channel)
{
	unsigned char bybuf[ROM_CHANNEL_LENGTH+4];
	EncodeChData(channel,&bybuf[3]);
	bybuf[0]=STX;
	bybuf[1]= 1;	//CMD 0: Sensor data 1: Channel Data
	bybuf[2]=channel;
	bybuf[ROM_CHANNEL_LENGTH+3]=ETX;
	Usart1_WriteData(bybuf,ROM_CHANNEL_LENGTH+4);
}

//----------------------------------------------------------------
char Usart1_RcvAck(void)
{
	if (StUsart1.byRxBufPos>0) {
		StUsart1.byRxBufPos=0;
		if (StUsart1.byRxBuf[0]==ACK) return 0;
		if (StUsart1.byRxBuf[0]==NACK) return -2;
	} 
	return -1; 
}
//----------------------------------------------------------------
void Usart1_RcvdDataToFrame(void)
{
	unsigned char i,j,k;
	unsigned char stx_pos;
	stx_pos=StUsart1.byRxBufPos;
	if (StUsart1.byRxBufPos<RX_FRAME_MIN) return;
	for (i=0;i<StUsart1.byRxBufPos;i++) { //STX_SAINT �� �ִ��� Ȯ��  	
		if (StUsart1.byRxBuf[i] == STX) {
			stx_pos=i;
			break;
		}
	}
	if (stx_pos==StUsart1.byRxBufPos) {	//STX�� ������ 
		StUsart1.byRxBufPos=0;
		return;

	}			
	if (stx_pos>0 && stx_pos<StUsart1.byRxBufPos) { //STX_SAINT�� �����ϴ� ��ġ�� ó��(0)���� ����� 
		for ( j=stx_pos,k=0;j<StUsart1.byRxBufPos;j++,k++)
			StUsart1.byRxBuf[k]=StUsart1.byRxBuf[j];
		StUsart1.byRxBufPos-=stx_pos;
	}
//	if (StUsart1.byRxBufPos<RX_FRAME_MIN) return;
	if (StUsart1.byRxBuf[1]==0) ByFrameSize=ROM_SENSOR_LENGTH+4; // =16
		else ByFrameSize=ROM_CHANNEL_LENGTH+4;	// =20
	if (StUsart1.byRxBufPos<ByFrameSize) { //FRAME Data���� 
		ByFrameSize=0;	//Ver0.93 Major(�޺κ��� �� ���� ������ Dataó��(FrameSize�� �����ϹǷ�)�� ���� �ʵ���    
		return;	
	}

	//RxFrame ETX�˻� 
	if (StUsart1.byRxBuf[ByFrameSize-1]!=ETX) {//FRAME ERROR
		StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
		ByFrameSize=0;
		return;	
	}

	//-----Frame�� ������ ó�� 
	for (i=0;i<ByFrameSize;i++)	//���� Data�� ByRxFrame���� Copy
		ByRxFrame[i]=StUsart1.byRxBuf[i];

	for (j=ByFrameSize,k=0;j<StUsart1.byRxBufPos;j++) {//���� STX_SAINT�� �����ϴ� ��ġ�� 0���� �����
		StUsart1.byRxBuf[k++]=StUsart1.byRxBuf[j];
	}
	StUsart1.byRxBufPos-=ByFrameSize;
}

char RxChFrameProcess(void)
{
	unsigned char channel;
	unsigned char i;
	unsigned char chksum=0;
	unsigned int addr;

	channel = ByRxFrame[2];

	for (i=3;i<ROM_CHANNEL_LENGTH+2;i++) {
		chksum+=ByRxFrame[i];
	}
	chksum++;
	ByFrameSize=0;
	if (ByRxFrame[ROM_CHANNEL_LENGTH+2]!=chksum) 
		return -1;

	addr=ROM_CH_START+(unsigned int)channel*ROM_CHANNEL_LENGTH;
	cli();
	for (i=0;i<ROM_CHANNEL_LENGTH;i++) {
		_EepromWriteByte(addr++,ByRxFrame[i+3]);	
	}
	sei();
	return 0;


}

char RxSensorFrameProcess(void)
{
	unsigned char channel;
	unsigned char i;
	unsigned char chksum=0;
	unsigned int addr;

	channel = ByRxFrame[2];

	for (i=3;i<ROM_SENSOR_LENGTH+2;i++) {
		chksum+=ByRxFrame[i];
	}
	chksum++;
	ByFrameSize=0;

	if (ByRxFrame[ROM_SENSOR_LENGTH+2]!=chksum) 
		return -1;

	addr=ROM_SENSOR_START+(unsigned int)channel*ROM_SENSOR_LENGTH;

	cli();
	for (i=0;i<ROM_SENSOR_LENGTH;i++) {
		_EepromWriteByte(addr++,ByRxFrame[i+3]);	
	}
	sei();
	return 0;
}

//----------------------------------------------------------------
//--------SPIDER(Usart1) RcvdDataToFrame----------------------------
//----------------------------------------------------------------
void RxBufClear(void)
{
	StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
	ByFrameSize=0;
	StUsart1.byRxBufPos=0;
}
void Spider_RcvdDataToFrame(void)
{
	unsigned char i,j,k;
	unsigned char stx_pos;
	stx_pos=StUsart1.byRxBufPos;
	if (StUsart1.byRxBufPos==0) return;
	//-----------------Check Response-------------------- 
	if (StUsart1.byRxBuf[0]==ACK) {	//After Send Single Data, Check ACK
		RxBufClear();
		ByReqdSpiderCh=99;	//Ver1.60 
		return;
	} else if (StUsart1.byRxBuf[0]==NACK){
		//NACK ��� ��۽� ó�� ------------------------------------------- 
		if (BySpiderSeq<SPIDER_1ST_TIME) BySpiderSeq=SPIDER_1ST_TIME;
		else if (BySpiderSeq<SPIDER_2ND_TIME) BySpiderSeq=SPIDER_2ND_TIME;
		//-----------------------------------------------------------------
		RxBufClear();
		return;
	}
	//-------------------------------------------------
	if (StUsart1.byRxBufPos<6) return;
	for (i=0;i<StUsart1.byRxBufPos;i++) { //STX_SAINT �� �ִ��� Ȯ��  	
		if (StUsart1.byRxBuf[i] == STX) {
			stx_pos=i;
			break;
		}
	}
	if (stx_pos==StUsart1.byRxBufPos) {	//STX�� ������ 
		StUsart1.byRxBufPos=0;
		return;
	}
	//STX�� ù��° ��ġ�� �̵� 
	if (stx_pos>0 && stx_pos<StUsart1.byRxBufPos) { //STX_SAINT�� �����ϴ� ��ġ�� ó��(0)���� ����� 
		for ( j=stx_pos,k=0;j<StUsart1.byRxBufPos;j++,k++)
			StUsart1.byRxBuf[k]=StUsart1.byRxBuf[j];
		StUsart1.byRxBufPos-=stx_pos;
	}
	if (StUsart1.byRxBufPos<6) return;
	i=StUsart1.byRxBuf[1];
	if (1>0 && i<8) { 
		ByFrameSize=i+4; 	//STX,LENGTH,CSUM,ETX
	}else {
		ByFrameSize=0;
		StUsart1.byRxBufPos=0;	//Frame Erroró��
		StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
	}		
	if (StUsart1.byRxBufPos<ByFrameSize) { //FRAME Data���� 
		return;	
	}
	
	//----------SPIDER Frame ETX�˻� -----------------------
	if (StUsart1.byRxBuf[ByFrameSize-1]!=ETX) {//FRAME ERROR
		Usart1_WriteByte(NACK);
		#if DEBUG_TRX		
		//----------Make Frame------------------------------------
		for (i=0;i<ByFrameSize;i++)	//���� Data�� ByRxFrame���� Copy
			ByRxFrame[i]=ByRxBuf[i];
		Usart1_WriteData(ByRxFrame, ByFrameSize);
		#endif
		StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
		ByFrameSize=0;
		return;	
	}
	//----------Make Frame------------------------------------
	for (i=0;i<ByFrameSize;i++)	//���� Data�� ByRxFrame���� Copy
		ByRxFrame[i]=StUsart1.byRxBuf[i];
	//-----------Remove First Frame Data in RxBuf-------------------------
	for (j=ByFrameSize,k=0;j<StUsart1.byRxBufPos;j++) {//���� STX_SAINT�� �����ϴ� ��ġ�� 0���� �����
		StUsart1.byRxBuf[k++]=StUsart1.byRxBuf[j];
	}
	StUsart1.byRxBufPos-=ByFrameSize;
	//-----------Check Sum �˻� --------------------------
	j=ByFrameSize-2;
	k=0;				//CheckSum
	for (i=0; i<j;i++) k+=ByRxFrame[i];
	if (k!=ByRxFrame[j]) {
		StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
		ByFrameSize=0;
		Usart1_WriteByte(NACK);
		#if DEBUG_TRX		
		Usart1_WriteData(ByRxFrame, ByFrameSize);
		#endif
		return;
	}
	//---------------------------------------------------
#if SPIDER_SINGLE_ACTIVE
	//Ver1.60 Usart1_WriteByte(ACK);
	//Check valid Channel in Frame------------------------------ 
	if (ByRxFrame[2]==0x61) {
		j=ByRxFrame[3];
		if (j<9) { //Ver1.7 ID 0�߰� 
			ByReqdSpiderCh=j;	//Ver1.60
			BySpiderSeq=0;
		} else {	//Channel ID Error
			RxBufClear();
			Usart1_WriteByte(NACK);
			return;
		}
	} else {		//invalid cmd
		StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
		ByFrameSize=0;
		Usart1_WriteByte(NACK);
		return;
	}
	RxBufClear();
#endif
	//---------------------------------------------------
#if SPIDER_ACTIVE
	Usart1_WriteByte(ACK);
	//Check valid Channel in Frame------------------------------ 
	j=ByRxFrame[3];
	if (j>8) { 	//Channel ID Error 
		StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
		ByFrameSize=0;
		Usart1_WriteByte(NACK);
		return;
	}
	i=j-1;
	if (StChannel[i].bySensor>=MAX_SENSOR) {	//��Ȱ�� Channel 
		StUsart1.byRxBuf[0]=0 ;	//���� STX�� ã�� ���� ��ġ 
		ByFrameSize=0;
		Usart1_WriteByte(NACK);
		return;
	}	
	//----------------------------------------------------

	if (ByRxFrame[2]==0x61) {
		if (j==0) BySpiderChMask=0xFF;
		else if (j<9) BySpiderChMask|=(0x01<<(j-1));
	}	
	else if (ByRxFrame[2]==0x62) {
		j=ByRxFrame[3];
		if (j==0) BySpiderChMask=0x00;
		else if (j<9) BySpiderChMask&=(~(0x01<<(j-1)));
	}	
#endif


		
}

void SpiderSetPrs(unsigned char channel) //Ver0.99 -199.9 ~ 9999 
{	//�Է� �з��� ������ HPA�� �Ǵ� 10mPsi�� ����.
	//�з� ������ ���� �ڸ����� �ٸ��� ǥ���� 
	//ǥ�� ���� : -145 ~ 0.00 ~ +145 -> 100�� �ϰ�� -14,500 ~ 0 ~ +14,500
	unsigned char by, byUnit,byDigitCnt;
	//int iPrs;
	char ch[8];
	int i;
	byUnit=StChannel[channel].byUnit;
	i=StChannel[channel].iPrsCur;
	i/=ByPrsStepAry[channel];
	//------PRECISION Digit ����
	for (by=4;by<8;by++) ch[by]=0xFF;
	byDigitCnt=0;
	switch (byUnit) {
		case UNIT_MPA:
			if (i<0) {	ch[byDigitCnt++]='-'; i=-i;}
			ch[byDigitCnt++]=(unsigned char)(i/1000)+0x30;
			ch[byDigitCnt++]='.';
			ch[byDigitCnt++]=(i%1000)/100+0x30;
			ch[byDigitCnt++]=(i%100)/10+0x30;
			ch[byDigitCnt]=i%10+0x30;
			
			break;
		case UNIT_KPA:
			if (ByPrsStepAry[channel]==1) {
				if (i<0) {	ch[byDigitCnt++]='-'; i=-i;}
				ch[byDigitCnt++]=(unsigned char)(i/1000)+0x30;
				ch[byDigitCnt++]=(i%1000)/100+0x30;
				ch[byDigitCnt++]=(i%100)/10+0x30;
				ch[byDigitCnt++]='.';
				ch[byDigitCnt]=i%10+0x30;
			} else {
				if (i<0) {	ch[byDigitCnt++]='-'; i=-i;}
				ch[byDigitCnt++]=(unsigned char)(i/1000)+0x30;
				ch[byDigitCnt++]=(i%1000)/100+0x30;
				ch[byDigitCnt++]=(i%100)/10+0x30;
				ch[byDigitCnt]=i%10+0x30;
			}
			break;
		case UNIT_BAR:
			if (ByPrsStepAry[channel]==1) {
				if (i<0) {	ch[byDigitCnt++]='-'; i=-i;}
				ch[byDigitCnt++]=(unsigned char)(i/1000)+0x30;
				ch[byDigitCnt++]='.';
				ch[byDigitCnt++]=(i%1000)/100+0x30;
				ch[byDigitCnt++]=(i%100)/10+0x30;
				ch[byDigitCnt]=i%10+0x30;
			} else {
				if (i<0) {	ch[byDigitCnt++]='-'; i=-i;}
				ch[byDigitCnt++]=(unsigned char)(i/1000)+0x30;
				ch[byDigitCnt++]=(i%1000)/100+0x30;
				ch[byDigitCnt++]='.';
				ch[byDigitCnt++]=(i%100)/10+0x30;
				ch[byDigitCnt]=i%10+0x30;
			}	
			break;
		case UNIT_PSI:
			if (ByPrsStepAry[channel]==1) {
				if (i<0) {	ch[byDigitCnt++]='-'; i=-i;}
				ch[byDigitCnt++]=(unsigned char)(i/1000)+0x30;
				ch[byDigitCnt++]=(i%1000)/100+0x30;
				ch[byDigitCnt++]='.';
				ch[byDigitCnt++]=(i%100)/10+0x30;
				ch[byDigitCnt]=i%10+0x30;
			} else {
				if (i<0) {	ch[byDigitCnt++]='-'; i=-i;}
				ch[byDigitCnt++]=(unsigned char)(i/1000)+0x30;
				ch[byDigitCnt++]=(i%1000)/100+0x30;
				ch[byDigitCnt++]=(i%100)/10+0x30;
				ch[byDigitCnt++]='.';
				ch[byDigitCnt]=i%10+0x30;
			}	
			break;
		default:
			break;
	}
	for (by=0;by<6;by++) SpiderPrs[channel][by]=ch[by];
}

void SpiderSetPrsF(unsigned char channel) //Ver0.99 -199.9 ~ 9999 
{	//�Է� �з��� ������ HPA�� �Ǵ� 10mPsi�� ����.
	//�з� ������ ���� �ڸ����� �ٸ��� ǥ���� 
	//ǥ�� ���� : -145 ~ 0.00 ~ +145 -> 100�� �ϰ�� -14,500 ~ 0 ~ +14,500
	unsigned char by, byUnit,byDigitCnt;
	//int iPrs;
	char ch[8];
	int i;
	double f;
	byUnit=StChannel[channel].byUnit;
	f=StChannel[channel].iPrsCur;
	f/=ByPrsStepAry[channel];
	//------PRECISION Digit ����
	for (by=4;by<8;by++) ch[by]=0xFF;
	byDigitCnt=0;
	switch (byUnit) {
		case UNIT_MPA:
			f/=1000.0;
			sprintf(ch,"%6.3f",f);
			break;
		case UNIT_KPA:
			if (ByPrsStepAry[channel]==1) {
				f/=10.0;
				sprintf(ch,"%6.1f",f);
			} else {
				i=(int) f;
				//sprintf(ch,"%6.0f",f);
				sprintf(ch,"%6d",i);
			}
			break;
		case UNIT_BAR:
			if (ByPrsStepAry[channel]==1) {
				f/=1000.0;
				sprintf(ch,"%6.3f",f);
			} else {
				f/=100.0;
				sprintf(ch,"%6.2f",f);
			}	
			break;
		case UNIT_PSI:
			if (ByPrsStepAry[channel]==1) {
				f/=100.0;
				sprintf(ch,"%6.2f",f);
			} else {
				f/=10.0;
				sprintf(ch,"%6.1f",f);
			}	
			break;
		default:
			break;
	}
	for (by=0;by<6;by++) SpiderPrs[channel][by]=ch[by];
}



//----------------------------------------------------------------
//-------------------Device �ʱ�ȭ-------------------------------- 	
//----------------------------------------------------------------

//-----Device �ʱ�ȭ 	
void DeviceInit(void)
{
 //stop errant interrupts until set up
 cli(); //disable all interrupts
 XDIV  = 0x00; //xtal divider
 XMCRA = 0x00; //external memory
 Port_Init();

 MCUCR = 0x00;
 EICRA = 0x02; //extended ext ints
 EICRB = 0x00; //extended ext ints
 EIMSK = 0x01;
 TIMSK = 0x00; //timer interrupt sources
 ETIMSK = 0x00; //extended timer interrupt sources
 sei(); //re-enable interrupts
 //all peripherals are now initialized
}


//----------------------------------------------------------------
//---------------------INT1 ����---------------------------------- 
//----------------------------------------------------------------

//----------------------------------------------------------------
//---------------------INT2 ����---------------------------------- 
//----------------------------------------------------------------

//----------------------------------------------------------------
//---------------------INT3 ����---------------------------------- 
//----------------------------------------------------------------

//----------------------------------------------------------------
//---------------------Timer0 ����-------------------------------- 
//----------------------------------------------------------------


//----------------------------------------------------------------
//---------------------WatchDog Timer ����------------------------ 
//----------------------------------------------------------------

void WatchdogStart(void)
{
	WDTCR=0x1E;
	WDTCR=0x0E;

}
void WatchdogReset(void)
{
	asm volatile("WDR"::);
}
//----------------------------------------------------------------
//---------------------ADC  ������ ����--------------------------- 
//----------------------------------------------------------------
int CountValidCh(void)
{
	int i,icnt=0;
	for (i=0;i<MAX_CHANNEL;i++) 
		if (StChannel[i].bySensor<MAX_SENSOR) icnt++;
	return icnt;
}

void AdcRead(unsigned char AdcChannel,int iAvgCntNum)
{
	int iprs;
	long ii;
//	float f;
	AdcCnt=0;
	AdcValueTotal=0;	//ADC ���ͷ�Ʈ������ ����
	AdcStart();
	while (1) {	//ADC�� ��Ʈ��Ʈ�� ���Ͽ� AVG_COUNT��ŭ ���������� ��� 
		if (AdcCnt>AVG_COUNT) {
			AdcClose();
			//Ver0.98g iprs=AdcValueTotal/(AdcCnt-1);
			iprs=AdcValueTotal;
			break;
		}
	}

	IChKalmanCnt[AdcChannel]++;	//�ش� æ���� ���� Ƚ�� �߰�  
	IKalmanCnt=IChKalmanCnt[AdcChannel];	//�ش� æ���� ���� Ƚ�� - Kalman Filter�� ������ ���
#if KALMAN2
	if (IChKalmanCnt[AdcChannel]>=iAvgCntNum) IChKalmanCnt[AdcChannel]=iAvgCntNum;
#endif
	//IAdcValue[AdcChannel]=KalmanAvg(IAdcValue[AdcChannel],iprs);	//���� �ð� 350uS
	IAdcValue[AdcChannel]=KalmanAvgInt(IAdcValue[AdcChannel],iprs);	//���� �ð� 100uS

	//------------------------------------------------------
	//-----Delay(AVG) Time�� ���� ADC���ġ ����------------
	//------------------------------------------------------
	if (IKalmanCnt>=iAvgCntNum) {	//Ver0.99h  IKalmanCnt>iAvgCntNum ===> IKalmanCnt>=iAvgCntNum�� 
		StChannel[AdcChannel].iAdc=IAdcValue[AdcChannel];	//���� ADC��հ� 0~4092(1023*4)
		//--------------------------------------
		//------------ ADC ���� ----------------
		//--------------------------------------
#if 0
		//���� �ð� 380uS
		f = (double)IAdcValue[AdcChannel]*StChannel[AdcChannel].uniAdcCalRate.f-StChannel[AdcChannel].iAdcOffset;	
		iprs=(int)(f+0.5);
#else 
		//Ver1.01 ���� �ð� 180uS
		ii = (long)IAdcValue[AdcChannel]*(long)(StChannel[AdcChannel].uniAdcCalRate.f*10000.0)-(long)StChannel[AdcChannel].iAdcOffset*10000;	//���� �ð� 180uS
		ii+=5000;
		ii/=10000;
		iprs=ii;

#endif
//		IAdcValue[AdcChannel]=(int)((float)IAdcValue[AdcChannel]*StChannel[AdcChannel].uniAdcCalRate.f);
		if (iprs<0) iprs=0;	//Ver0.99d
		if (iprs>=RESOLUTION_RATE || IAdcValue[AdcChannel]>=RESOLUTION_RATE) iprs=(int)RESOLUTION_RATE;	//Ver0.99d
		StChannel[AdcChannel].iCalibratedAdc=iprs;	//ver1.3
		//--------------------------------------
		//----- ���� ADC�� �з´����� ��ȯ -----
		//--------------------------------------
		StChannel[AdcChannel].iPrsCur=AcdToPrsUserUnit(iprs,AdcChannel);	//���� �ð� 250 or 370uS(Psi�� ���) -> Ver1.01 AcdToPrsUserUnit�������� 370->270uS
#if SPIDER_ACTIVE
		SpiderSetPrsF(AdcChannel);	//Ver1.50
#endif
#if SPIDER_SINGLE_ACTIVE
		SpiderSetPrsF(AdcChannel);	//Ver1.50
#endif

#if !KALMAN2
		IChKalmanCnt[AdcChannel]=0;
		IAdcValue[AdcChannel]=0;
#endif
	}

}

//---------------------------------------------------------------------
//--------------------BASIC FUNCTION - DELAY --------------------------
//---------------------------------------------------------------------
void delay_ms(unsigned int idt)
{
	unsigned int i;
	unsigned long j;
	for (i=0;i<idt;i++) {
		for (j=0;j<500;j++)
			asm volatile("nop"::);
	}
}

void delay_100us(unsigned int idt)
{
	unsigned int i;
	unsigned long j;
	for (i=0;i<idt;i++) {
		for (j=0;j<200;j++)
			asm volatile("nop"::);
	}
}



//---------------------------------------------------------------------
void Delay_1us(void)
{	//16MHz�� ��� ���� ���� - ���� �մ��� �� �� 
	unsigned char j;
	for (j=0;j<6;j++)
			asm volatile("nop"::);
}

//---------------------------------------------------------------------
void Delay_5us(void)
{	//16MHz�� ��� ���� ���� - ���� �մ��� �� �� 
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
}

//---------------------------------------------------------------------
void Delay_10us(void)
{	//16MHz�� ��� ���� ���� - ���� �մ��� �� �� 
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
	Delay_1us();
}

//---------------------------------------------------------------------
void TimeCount(void)
{
	if (Tm_mSec==SYSTEM_500M) FlagSystem|=0x02; //Display Approval
	if (Tm_mSec<=SYSTEM_1SEC) return;
	Tm_mSec=0;	//Reset at 1000mS
	FlagSystem|=0x02; //Display Approval
	if (FlagTimeCount&0x01) {
		Tm_Sec++;
		if (Tm_Sec>59) {
			Tm_Sec=0;
			Tm_Min++;
		}
	}
}
void TimeClear(void)
{
	FlagSystem|=0x02;
	Tm_mSec=0;
	Tm_Sec=0;
	Tm_Min=0;

}

//---------------------------------------------------------------------
//------------------- BASIC FUNCTION - Kalman FIlter ------------------
//---------------------------------------------------------------------
double KalmanAvg(double preavg, double value)
{
   //����ð� 350uS
   double avg;
   avg=preavg+(value-preavg)/(double)IKalmanCnt;
   return avg;
}

//---------------------------------------------------------------------
int KalmanAvgInt(int preavg, int value)
{
 	//����ð� 100uS
   long avg,ip,iv;	//���� MAX -2,147,483,647 ~ 2,147,483,647 
   ip=(long)preavg;
   iv=(long)value;	
   avg=ip*100000 + ((iv-ip)*100000)/(long)IKalmanCnt;	//MAX : 4096*100000=40,960,000
   avg/=100000;
   return (int)avg;
}


//---------------------------------------------------------------------------------------------
unsigned char FindUserUnit(unsigned char byChannel) 
{	//Channel�� ������ ǥ�� ������ ���� ���� User Unit�� Return
	unsigned char byUnit=0;
	if (StChannel[byChannel].byUnit==UNIT_MPA) {
		byUnit=USER_UNIT_HPA;
	} else if (StChannel[byChannel].byUnit==UNIT_KPA) {
		byUnit=USER_UNIT_HPA;
	} else if (StChannel[byChannel].byUnit==UNIT_BAR) {
		byUnit=USER_UNIT_mBAR;
	} else {
		byUnit=USER_UNIT_10mPSI;
	}
	return byUnit;
}

//---------------------------------------------------------------------------------------------
int ChangeHpaTo10mPsi(int iHpa)
{
#if 0
	//����ð� 400uS
	float fa;
	fa=(float)iHpa*K_PSI;
	return (int)fa;
#else 
	//Ver1.01 ����ð� 200uS
	long fa;
	fa=iHpa*145038;
	fa/=100000;
	return (int)fa;
#endif
			
} 
//---------------------------------------------------------------------------------------------
int Change10mPsiToHpa(int psi)
{
	float fa;
	fa=(float)psi/K_PSI;
	return (int)fa;		
} 


//---------------------------------------------------------------------------------------------
//------------------------------ADC READ & CONVERT TO USER UNIT--------------------------------
//---------------------------------------------------------------------------------------------
int AcdToPrsUserUnit(unsigned int iadc,unsigned char byChannel)
{	//Sensor�� �з� ������ UNIT_HPA(UNIT_mBar) / ���� 
	//enum {SENSOR_P1,SENSOR_P2,SENSOR_P3,SENSOR_P4,SENSOR_P5,SENSOR_U1,SENSOR_U2,SENSOR_U3,MAX_SENSOR};
	//enum {UNIT_MPA, UNIT_KPA,UNIT_BAR, UNIT_PSI};
	//enum {USER_UNIT_HPA, USER_UNIT_mBAR, USER_UNIT_10mPSI, USER_UNIT_10PA, USER_UNIT_100uBAR, USER_UNIT_mPSI};
	int irtn;
	double fbuf;
	char cUnit;

#if 0	// Total 520 uS 
	fbuf=(float)(StSensor[StChannel[byChannel].bySensor].iPrsMax-StSensor[StChannel[byChannel].bySensor].iPrsMin) / RESOLUTION_RATE;
	fbuf*=(float)iadc;
	fbuf+=(float)StSensor[StChannel[byChannel].bySensor].iPrsMin;
#endif 

#if 0	// Total 520 uS 
	double fa,fb;
	int iprs;
	fa=StSensor[StChannel[byChannel].bySensor].iPrsMax;
	fb=StSensor[StChannel[byChannel].bySensor].iPrsMin;
	fbuf=(fa-fb) / RESOLUTION_RATE;		//�ҿ�ð� 250us
	fbuf*=(float)iadc;	//�ҿ�ð� 150us
	fbuf+=fb;			//�ҿ�ð� 100us
#endif


#if 1 	//Total 250uS
	long int ii;
	ii = (long int)(StSensor[StChannel[byChannel].bySensor].iPrsMax-StSensor[StChannel[byChannel].bySensor].iPrs_0V);	//Ver0.96
	ii = ii*(long int)iadc;
	ii = ii / RESOLUTION_RATE;		//�ҿ�ð� 250us
	ii=ii+StSensor[StChannel[byChannel].bySensor].iPrs_0V;		//Ver0.96	//�ҿ�ð� 100us
	fbuf=(double)ii;	//���� hPa
#endif

	cUnit=StChannel[byChannel].byUnit;

	switch (cUnit) {	//�ҿ�ð� 20us
		case UNIT_MPA:	 
		case UNIT_KPA:
		case UNIT_BAR:
			irtn=(int)fbuf;
		break;
		case UNIT_PSI:
#if 0
			irtn=(int)(fbuf*K_PSI);	//�߰� 120uS
#else 
			//Ver1.01 �߰� 20uS
			ii*=145038;
			ii/=100000;
			irtn=(int) ii;
#endif
			break;
		default:
			irtn=0x8000;
			break;
	}
	return irtn;

}

//---------------------------------------------------------------------
//----------------------- System �ʱ�ȭ �Լ� --------------------------
//---------------------------------------------------------------------
void Port_Init(void)
{
	PORTA = 0xFF;
	DDRA  = 0x3F;	//bit6:nouse, bit7:KEY_SET 
 
	PORTB = 0xFF;
	DDRB  = 0xF1;	//bit2,3 ������ Check
 
	PORTC = 0xFF;	//Led Data Out 
	DDRC  = 0xFF;	
 
	PORTD = 0xFC;	//Ver0.2 F0->FC	 
	DDRD  = 0xCB;	//PD0,1:ch_out6,7/ bit3,4:RX,TX / PD4:KEY_DN,PD5:KEY_UP
 
	PORTE = 0x03;	//PE0:RX0 PE1:TX0 ,PE2~7 : ch_out 0~6
	DDRE  = 0xFE;
 
	PORTF = 0x00;
	DDRF  = 0x00;
 
	PORTG = 0x0F;
	DDRG  = 0x0F;	//Unit LED 
}


//---------------------------------------------------------------------
void Var_Init(void)
{
	int i;

	ByKeyBuf=0;
	ByOldKeyBuf=0;
	ByKey=0;
	WKeyTime=0;
	WKeyInterval=0;
	FlagKey=0;
	ISystemCnt=0;
	Tm_mSec=0;
	Tm_Sec=0;
	Tm_Min=0;
	FlagDot=0;		//DOTǥ�� ��)1: 0.000   2:00.00   4:000.0    8:000.0
	FlagFlash=0;	//Digit�� Flashing���� b7: All Display OFF, b0:~b6 Flahing ����
	FlagError=0; 	//Input Status ���� ������ Set��
	FlagLowPrs=0;
	FlagHighPrs=0;

	IPrsCur=0; 
	ByChOutData=0;
	ByChLast=0;	//Ver0.99e bit0:2(0~7) :���� ä�� ,  //ver0.99h bit3: 0:ǥ�ظ�� 1:��ȯ��� 
	//-----USART���� �ʱ�ȭ 
	ByFrameSize=0;
	StUsart1.byRxBufPos=0;

	ByChCur=0;
	ByAdcChannel=0;
#if !VTVM
	//-----Sensor0 P1
	strcpy(StSensor[0].cName,"P1");
	StSensor[0].byUnit=UNIT_KPA;
	StSensor[0].iOffset=0;
	StSensor[0].byNagative=0;
	StSensor[0].iPrsMin=0;	//HPA :MIN_MPA*10
	StSensor[0].iPrsMax=10000;	//HPA :MAX_MPA*10
	//-----Sensor1 P2
	strcpy(StSensor[1].cName,"P2");
	StSensor[1].byUnit=UNIT_KPA;
	StSensor[1].iOffset=0;
	StSensor[1].byNagative=1;
	StSensor[1].iPrsMin=0;	//HPA :MIN_KPA*10
	StSensor[1].iPrsMax=-1000;	//HPA :MAX_KPA*10
	//-----Sensor2 P3
	strcpy(StSensor[2].cName,"P3");
	StSensor[2].byUnit=UNIT_KPA;
	StSensor[2].iOffset=0;
	StSensor[2].byNagative=0;
	StSensor[2].iPrsMin=0;	//HPA :MIN_KPA*10
	StSensor[2].iPrsMax=1000;	//HPA :MIN_KPA*10
	//-----Sensor3 P4
	strcpy(StSensor[3].cName,"P4");
	StSensor[3].byUnit=UNIT_KPA;
	StSensor[3].iOffset=0;
	StSensor[3].byNagative=0;
	StSensor[3].iPrsMin=-1000;	//HPA :MIN_KPA*10
	StSensor[3].iPrsMax=1000;	//HPA :MIN_KPA*10

	//-----Sensor4 P5
	strcpy(StSensor[4].cName,"P5");
	StSensor[4].byUnit=UNIT_KPA;
	StSensor[4].iOffset=0;
	StSensor[4].byNagative=0;
	StSensor[4].iPrsMin=-1000;	//HPA :MIN_KPA*10
	StSensor[4].iPrsMax=10000;	//HPA :MIN_KPA*10

	strcpy(StSensor[5].cName,"U1");
	StSensor[5].byUnit=UNIT_KPA;
	StSensor[5].iOffset=0;
	StSensor[5].byNagative=0;
	StSensor[5].iPrsMin=0;	//HPA :MIN_KPA*10
	StSensor[5].iPrsMax=1000;	//HPA :MIN_KPA*10

	strcpy(StSensor[6].cName,"U2");
	StSensor[6].byUnit=UNIT_KPA;
	StSensor[6].iOffset=0;
	StSensor[6].byNagative=0;
	StSensor[6].iPrsMin=0;	//HPA :MIN_KPA*10
	StSensor[6].iPrsMax=1000;	//HPA :MIN_KPA*10

	strcpy(StSensor[7].cName,"U3");
	StSensor[7].byUnit=UNIT_KPA;
	StSensor[7].iOffset=0;
	StSensor[7].byNagative=0;
	StSensor[7].iPrsMin=0;	//HPA :MIN_KPA*10
	StSensor[7].iPrsMax=1000;	//HPA :MIN_KPA*10
	for (i=0;i<8;i++)	{ //Ver0.96
		StSensor[i].iPrs_0V=StSensor[i].iPrsMin-(StSensor[i].iPrsMax-StSensor[i].iPrsMin)/4;	//HPA :MIN_KPA*10
	}

	for (i=0;i<MAX_CHANNEL;i++) {
		StChannel[i].byInCh=(unsigned char)i;
		StChannel[i].bySensor=SENSOR_P3;
		StChannel[i].byPrsType=PRS_REF;
		StChannel[i].byUnit=UNIT_BAR;
		StChannel[i].byTrgType=TRIG_SINGLE;
		//Ver1.03 StChannel[i].uniAdcCalRate.f=1.00;
		//Ver1.03 StChannel[i].iAdcOffset=10;		//Ver0.99e ADC���� ������ 10���� �ӽ� ó�� 
		StChannel[i].iAdc=0;
		StChannel[i].iOffset=DEFAULT_ADC_OFFSET;

		InitChannel(&StChannel[i]);
	}
#else
	//-----Sensor0 P1
	strcpy(StSensor[0].cName,"P1");
	StSensor[0].byUnit=UNIT_KPA;
	StSensor[0].iOffset=0;
	StSensor[0].byNagative=0;
	StSensor[0].iPrsMin=5000;	//HPA :MIN_MPA*10
	StSensor[0].iPrsMax=25000;	//HPA :MAX_MPA*10
	//-----Sensor1 P2
	strcpy(StSensor[1].cName,"P2");
	StSensor[1].byUnit=UNIT_KPA;
	StSensor[1].iOffset=0;
	StSensor[1].byNagative=1;
	StSensor[1].iPrsMin=1000;	//HPA :MIN_KPA*10
	StSensor[1].iPrsMax=5000;	//HPA :MAX_KPA*10
	//-----Sensor2 P3
	strcpy(StSensor[2].cName,"P3");
	StSensor[2].byUnit=UNIT_KPA;
	StSensor[2].iOffset=0;
	StSensor[2].byNagative=0;
	StSensor[2].iPrsMin=1000;	//HPA :MIN_KPA*10
	StSensor[2].iPrsMax=5000;	//HPA :MIN_KPA*10
	//-----Sensor3 P4
	strcpy(StSensor[3].cName,"P4");
	StSensor[3].byUnit=UNIT_KPA;
	StSensor[3].iOffset=0;
	StSensor[3].byNagative=0;
	StSensor[3].iPrsMin=1000;	//HPA :MIN_KPA*10
	StSensor[3].iPrsMax=5000;	//HPA :MIN_KPA*10

	//-----Sensor4 P5
	strcpy(StSensor[4].cName,"P5");
	StSensor[4].byUnit=UNIT_KPA;
	StSensor[4].iOffset=0;
	StSensor[4].byNagative=0;
	StSensor[4].iPrsMin=1000;	//HPA :MIN_KPA*10
	StSensor[4].iPrsMax=50000;	//HPA :MIN_KPA*10

	strcpy(StSensor[5].cName,"U1");
	StSensor[5].byUnit=UNIT_KPA;
	StSensor[5].iOffset=0;
	StSensor[5].byNagative=0;
	StSensor[5].iPrsMin=200;	//HPA :MIN_KPA*10
	StSensor[5].iPrsMax=1000;	//HPA :MIN_KPA*10

	strcpy(StSensor[6].cName,"U2");
	StSensor[6].byUnit=UNIT_KPA;
	StSensor[6].iOffset=0;
	StSensor[6].byNagative=0;
	StSensor[6].iPrsMin=200;	//HPA :MIN_KPA*10
	StSensor[6].iPrsMax=1000;	//HPA :MIN_KPA*10

	strcpy(StSensor[7].cName,"U3");
	StSensor[7].byUnit=UNIT_KPA;
	StSensor[7].iOffset=0;
	StSensor[7].byNagative=0;
	StSensor[7].iPrsMin=200;	//HPA :MIN_KPA*10
	StSensor[7].iPrsMax=1000;	//HPA :MIN_KPA*10
	for (i=0;i<8;i++)	{ //Ver0.96
		StSensor[i].iPrs_0V=StSensor[i].iPrsMin-(StSensor[i].iPrsMax-StSensor[i].iPrsMin)/4;	//HPA :MIN_KPA*10
	}

	for (i=0;i<MAX_CHANNEL;i++) {
		StChannel[i].byInCh=(unsigned char)i;
		StChannel[i].bySensor=SENSOR_P2;
		StChannel[i].byPrsType=PRS_REF;
		StChannel[i].byUnit=UNIT_MPA;
		StChannel[i].byTrgType=TRIG_SINGLE;
		//Ver1.03 StChannel[i].uniAdcCalRate.f=1.00;
		//Ver1.03 StChannel[i].iAdcOffset=10;		//Ver0.99e ADC���� ������ 10���� �ӽ� ó�� 
		StChannel[i].iAdc=0;
		StChannel[i].iOffset=DEFAULT_ADC_OFFSET;

		InitChannel(&StChannel[i]);
	}

#endif

	StChannel[0].bySensor=SENSOR_P1;
	InitChannel(&StChannel[0]);
	StChannel[1].bySensor=SENSOR_P2;
	InitChannel(&StChannel[1]);
	StChannel[2].bySensor=SENSOR_P2;
	StChannel[2].byUnit=UNIT_PSI;
	InitChannel(&StChannel[2]);
	StChannel[3].bySensor=SENSOR_P2;
	StChannel[3].byUnit=UNIT_MPA;
	InitChannel(&StChannel[3]);

	BySpiderChMask=0;		//Ver1.50	1:Spider On(Send PRS Data)
	BySpiderSeq=0;
	ByReqdSpiderCh=99;

}

void InitCalibration(void)
{	//Ver1.03 var_init()���� �и��Ͽ� ���� ó��
	int i;
	for (i=0;i<MAX_CHANNEL;i++) {
		StChannel[i].uniAdcCalRate.f=1.00;
		StChannel[i].iAdcOffset=0;		//Ver0.99e ADC���� ������ 10���� �ӽ� ó�� 
	}
}


//---------------------------------------------------------------------

void InitChannel(_CHDATA *stCh)
{
	unsigned char by,bystep;
	int ibuf;
	by=stCh->bySensor;
	if (by>=MAX_SENSOR) by=SENSOR_P3;
	stCh->iPrsCur=0;
	stCh->iOffset=0;
	ibuf=StSensor[by].iPrsMax-StSensor[by].iPrsMin;
	if (ibuf<0) ibuf=-ibuf;
	if (ibuf>5000) bystep=10;
		else bystep=1;
	if (stCh->byUnit==UNIT_PSI) {
		stCh->iTrgOn=1000*bystep;
		stCh->iTrgOff=ChangeHpaTo10mPsi(StSensor[by].iPrsMax);
	} else {
	 	stCh->iTrgOn=600*bystep;
		stCh->iTrgOff=StSensor[by].iPrsMax;
	}
	if (StSensor[by].byNagative!=0) stCh->iTrgOn=-stCh->iTrgOn;
	if (stCh->byUnit==UNIT_MPA) stCh->iHyst=10;  
		else stCh->iHyst=bystep;
	stCh->byDelayMode=PRS_AVG_100mS;
	stCh->byOutStatus=0;
	stCh->bySwType=SW_NOR_OFF;
}

//---------------------------------------------------------------------
void CopyChannel(_CHDATA *stDis,_CHDATA *stSou)
{
	stDis->byInCh		=	stSou->byInCh;
	stDis->bySensor		=	stSou->bySensor;
	stDis->byPrsType	=	stSou->byPrsType;
	stDis->byUnit		=	stSou->byUnit;
	stDis->byTrgType	=	stSou->byTrgType;
	stDis->iPrsCur		=	stSou->iPrsCur;
	stDis->iOffset		=	stSou->iOffset;
	stDis->iTrgOn		=	stSou->iTrgOn;
	stDis->iTrgOff		=	stSou->iTrgOff;
	stDis->iHyst		=	stSou->iHyst;
	stDis->byDelayMode	=	stSou->byDelayMode;
	stDis->byOutStatus	=	stSou->byOutStatus;
	stDis->bySwType		=	stSou->bySwType;

}

void CopySensor(_SENSOR *stDis,_SENSOR *stSou)
{
	stDis->cName[0]		=	stSou->cName[0];
	stDis->cName[1]		=	stSou->cName[1];
	stDis->cName[2]		=	stSou->cName[2];
	stDis->cName[3]		=	stSou->cName[3];
	stDis->cName[4]		=	stSou->cName[4];
	stDis->byUnit	=	stSou->byUnit;
	stDis->iOffset	=	stSou->iOffset;
	stDis->byNagative = stSou->byNagative;
	stDis->iPrsMin	=	stSou->iPrsMin;
	stDis->iPrsMax	=	stSou->iPrsMax;
}




//---------------------------------------------------------------------
void EncodeSensorData(unsigned char bySens, unsigned char *buf)
{	//Every Sensor Block is 10bytes
	unsigned int addr=0;
	unsigned int ibuf;
	unsigned char chksum=0;
	//-----Sensor Name byte0 Encode	//ADDR REF+0 
	buf[addr++]=StSensor[bySens].cName[0];
	//-----Sensor Name byte1 Encode	//ADDR REF+1
	buf[addr++]=StSensor[bySens].cName[1];
	//-----Sensor Name byte2 Encode //ADDR REF+2
	buf[addr++]=StSensor[bySens].cName[2];
	//-----Sensor Name byte3 Encode //ADDR REF+3
	buf[addr++]=StSensor[bySens].cName[3];

	//-----Pressure Unit byte Encode //ADDR REF+4
	buf[addr++]=StSensor[bySens].byUnit;

	//-----Offset MSB byte Encode //ADDR REF+5
	ibuf=StSensor[bySens].iOffset;
	ibuf>>=8;
	buf[addr++]=(unsigned char)ibuf;
	//-----Offset LSB byte Encode //ADDR REF+6
	ibuf=StSensor[bySens].iOffset;
	ibuf&=0x00FF;
	buf[addr++]=(unsigned char)ibuf;

	//-----Minimum Pressure MSB byte Encode //ADDR REF+7
	ibuf=StSensor[bySens].iPrsMin;
	ibuf>>=8;
	buf[addr++]=(unsigned char)ibuf;
	//-----Minimum Pressure LSB byte Encode //ADDR REF+8
	ibuf=StSensor[bySens].iPrsMin;
	ibuf&=0x00FF;
	buf[addr++]=(unsigned char)ibuf;

	//-----Maximum Pressure MSB byte Encode //ADDR REF+9
	ibuf=StSensor[bySens].iPrsMax;
	ibuf>>=8;
	buf[addr++]=(unsigned char)ibuf;
	//-----Maximum Pressure LSB byte Encode //ADDR REF+10
	ibuf=StSensor[bySens].iPrsMax;
	ibuf&=0x00FF;
	buf[addr++]=(unsigned char)ibuf;


	//-----CheckSum  Encode 		//ADDR REF+11
	for (ibuf=0;ibuf<addr;ibuf++) {
		chksum+=buf[ibuf];
	}
	buf[addr]=chksum+1;

}

//---------------------------------------------------------------------
char DecodeSensorData(unsigned char bySens, unsigned char *buf)
{
	//Return 0: Success, -1: Fail
	unsigned int ibuf;
	unsigned char chksum=0;
	unsigned char ch;
	unsigned int addr=0;

	for (ch=0;ch<(ROM_SENSOR_LENGTH-1);ch++) { 
		chksum+=buf[ch];
	}
	chksum++;
	//-----Verify CheckSum 
	if (buf[ROM_SENSOR_LENGTH-1]!=chksum) return -1;

	//-----Sensor Name byte0 Decode	//ADDR REF+0 
	StSensor[bySens].cName[0]=buf[addr++];
	//-----Sensor Name byte1 Decode	//ADDR REF+1 
	StSensor[bySens].cName[1]=buf[addr++];
	//-----Sensor Name byte2 Decode	//ADDR REF+2 
	StSensor[bySens].cName[2]=buf[addr++];
	//-----Sensor Name byte3 Decode	//ADDR REF+3 
	StSensor[bySens].cName[3]=buf[addr++];

	//-----Pressure Unit byte Decode //ADDR REF+4
	StSensor[bySens].byUnit=buf[addr++];

	//-----Offset Decode //ADDR REF+5,6
	ibuf=(unsigned int)buf[addr++];
	ibuf<<=8;
	ibuf|=(unsigned int)buf[addr++];
	StSensor[bySens].iOffset=ibuf;
	//-----Minimum Pressure Decode //ADDR REF+7,8
	ibuf=(unsigned int)buf[addr++];
	ibuf<<=8;
	ibuf|=(unsigned int)buf[addr++];
	StSensor[bySens].iPrsMin=ibuf;

	//-----Maximum Pressure Decode //ADDR REF+9,10
	ibuf=(unsigned int)buf[addr++];
	ibuf<<=8;
	ibuf|=(unsigned int)buf[addr++];
	StSensor[bySens].iPrsMax=ibuf;

	if (StSensor[bySens].iPrsMax<StSensor[bySens].iPrsMin) StSensor[bySens].byNagative=1;
		else StSensor[bySens].byNagative=0;
	//-------Ver0.96
	StSensor[bySens].iPrs_0V=StSensor[bySens].iPrsMin-(StSensor[bySens].iPrsMax-StSensor[bySens].iPrsMin)/4;	//HPA :MIN_KPA*10

	return 0;
}


//---------------------------------------------------------------------
void EncodeChData(unsigned char channel, unsigned char *buf)
{
	unsigned int addr=0;
	unsigned int ibuf;
	unsigned char chksum=0;
	//-----Sensor Num byte Encode	//ADDR REF+0 
	buf[addr++]=StChannel[channel].byInCh;
	//-----Sensor Num byte Encode 	//ADDR REF+1
	buf[addr++]=StChannel[channel].bySensor;
	//-----Pressure Type byte Encode //ADDR REF+2
	buf[addr++]=StChannel[channel].byPrsType;

	//-----Pressure Unit byte Encode //ADDR REF+3
	buf[addr++]=StChannel[channel].byUnit;
	//-----Trigger Type byte Encode //ADDR REF+4
	buf[addr++]=StChannel[channel].byTrgType;
	//-----Pressure offset MSB byte Encode //ADDR REF+5
	ibuf=StChannel[channel].iOffset;
	ibuf>>=8;
	buf[addr++]=(unsigned char)ibuf;
	//-----Pressure offset LSB byte Encode //ADDR REF+6
	ibuf=StChannel[channel].iOffset;
	ibuf&=0x00FF;
	buf[addr++]=(unsigned char)ibuf;
	//-----Trg.On Pressure MSB byte Encode //ADDR REF+7
	ibuf=StChannel[channel].iTrgOn;
	ibuf>>=8;
	buf[addr++]=(unsigned char)ibuf;
	//-----Trg.On Pressure LSB byte Encode //ADDR REF+8
	ibuf=StChannel[channel].iTrgOn;
	ibuf&=0x00FF;
	buf[addr++]=(unsigned char)ibuf;
	//-----Trg.Off Pressure MSB byte Encode //ADDR REF+9
	ibuf=StChannel[channel].iTrgOff;
	ibuf>>=8;
	buf[addr++]=(unsigned char)ibuf;
	//-----Trg.Off Pressure LSB byte Encode //ADDR REF+10
	ibuf=StChannel[channel].iTrgOff;
	ibuf&=0x00FF;
	buf[addr++]=(unsigned char)ibuf;
	//-----Hysterisis MSB byte Encode //ADDR REF+11
	ibuf=StChannel[channel].iHyst;
	ibuf>>=8;
	buf[addr++]=(unsigned char)ibuf;
	//-----Hysterisis LSB byte Encode //ADDR REF+12
	ibuf=StChannel[channel].iHyst;
	ibuf&=0x00FF;
	buf[addr++]=(unsigned char)ibuf;

	//-----Delay Mode byte Encode //ADDR REF+13
	buf[addr++]=StChannel[channel].byDelayMode;

	//-----Switch Type byte Encode //ADDR REF+14
	buf[addr++]=StChannel[channel].bySwType;
	//-----CheckSum  Encode 		//ADDR REF+15
	for (ibuf=0;ibuf<addr;ibuf++) {
		chksum+=buf[ibuf];
	}
	chksum++;
	buf[addr]=chksum;

}

//---------------------------------------------------------------------
char DecodeChData(unsigned char channel, unsigned char *buf)
{	
	//Return 0: Success, -1: Fail
	unsigned int addr=0;
	unsigned int ibuf;
	unsigned char chksum=0;
	unsigned char ch;
	for (ch=0;ch<(ROM_CHANNEL_LENGTH-1);ch++) { 
		chksum+=buf[ch];
	}
	chksum++;
	//-----Verify CheckSum 
	if (buf[ROM_CHANNEL_LENGTH-1]!=chksum) return -1;;


	//-----Sensor Num byte Decode	//ADDR REF+0 
	StChannel[channel].byInCh=buf[addr++];

	//-----Sensor Num byte Decode 	//ADDR REF+1
	StChannel[channel].bySensor=buf[addr++];

	//-----Pressure Type byte Decode //ADDR REF+2
	StChannel[channel].byPrsType=buf[addr++];

	//-----Pressure Unit byte Decode //ADDR REF+3
	StChannel[channel].byUnit=buf[addr++];

	//-----Trigger Type byte Decode //ADDR REF+4
	StChannel[channel].byTrgType=buf[addr++];

	//-----Pressure offset MSB byte Decode //ADDR REF+5
	ibuf=(unsigned int)buf[addr++];
	ibuf<<=8;
	ibuf|=(unsigned int)buf[addr++];
	StChannel[channel].iOffset=ibuf;

	//-----Trg.On Pressure MSB byte Decode //ADDR REF+7
	ibuf=(unsigned int)buf[addr++];
	ibuf<<=8;
	ibuf|=(unsigned int)buf[addr++];
	StChannel[channel].iTrgOn=ibuf;

	//-----Trg.Off Pressure MSB byte Decode //ADDR REF+9
	ibuf=(unsigned int)buf[addr++];
	ibuf<<=8;
	ibuf|=(unsigned int)buf[addr++];
	StChannel[channel].iTrgOff=ibuf;

	//-----Hysterisis MSB byte Decode //ADDR REF+11
	ibuf=(unsigned int)buf[addr++];
	ibuf<<=8;
	ibuf|=(unsigned int)buf[addr++];
	StChannel[channel].iHyst=ibuf;

	//-----Delay Mode byte Decode //ADDR REF+13
	StChannel[channel].byDelayMode=buf[addr++];

	//-----Switch Type byte Decode //ADDR REF+14
	StChannel[channel].bySwType=buf[addr];

	return 0;
}


//---------------------------------------------------------------------
//-------------------EEPROM READ/WRITE BASIC FUNCTION------------------
//---------------------------------------------------------------------
void _EepromWriteByte(unsigned int addr, unsigned char dt)
{
	while(EECR & (1<<EEWE));
	EEAR = addr;
	EEDR = dt;
	EECR |= (1<<EEMWE);
	EECR |= (1<<EEWE);
}

//---------------------------------------------------------------------
unsigned char _EepromReadByte(unsigned int addr)
{
	while(EECR & (1<<EEWE));
	EEAR = addr;
	EECR |= (1<<EERE);
	return EEDR;
}

//---------------------------------------------------------------------
char _EepromRealWriteByte(unsigned int addr, unsigned char dt)
{	//Busy�̸� -1�� �����̸� 0�� ����
	if (EECR & (1<<EEWE)) return -1;
	EEAR = addr;
	EEDR = dt;
	EECR |= (1<<EEMWE);
	EECR |= (1<<EEWE);
	return 0;
}

//---------------------------------------------------------------------
char _EepromRealReadByte(unsigned int addr, unsigned char *data)
{	//Busy�̸� -1�� �����̸� 0�� ����
	if (EECR & (1<<EEWE)) return -1;
	EEAR = addr;
	EECR |= (1<<EERE);
	*data=EEDR;
	return 0;
}

//---------------------------------------------------------------------
//---------------------------- EEPROM Check ---------------------------
//---------------------------------------------------------------------
char EepromCheck(void)
{
	unsigned char ch;
	ch=_EepromReadByte(ROM_CONFIRM);
	if (ch==0x5A) return 0;
	else return -1;
}

//---------------------------------------------------------------------
//------------------EEPROM SENSOR DATA READ/WRITE ---------------------
//---------------------------------------------------------------------
char EepromRealSaveSensorBlock(unsigned char bySensor,unsigned char byByteCnt)
{
	// Write�� ������ ���� ����Ʈ ��ȣ�� ������
	unsigned int addr;
	unsigned char byte_no=byByteCnt;
	unsigned char bybuf[ROM_SENSOR_LENGTH];
	EncodeSensorData( bySensor, bybuf);

	addr=ROM_SENSOR_START+(unsigned int)bySensor*ROM_SENSOR_LENGTH+byte_no;

	cli();
	if (_EepromRealWriteByte(addr++,bybuf[byte_no])==0) {
		byte_no++;
	}
	sei();
	return byte_no;	
}

//---------------------------------------------------------------------
char EepromRealSaveChBlock(unsigned char channel,unsigned char byByteCnt)
{
	// Write�� ������ ���� ����Ʈ ��ȣ�� ������
	//StChannel Data�� byByteCnt��°�� byte�� Eeprom�� ����ϰ� ������ ó���ؾ���  Byte�� ������ ���� ��.
	//ROM_CHANNEL_LENGTH�� ��ŭ ȣ��Ǹ� �ϳ��� ä�� ����� �Ϸ��   
	unsigned int addr;
	unsigned char byte_no=byByteCnt;
	unsigned char bybuf[ROM_CHANNEL_LENGTH];
	EncodeChData( channel,bybuf);

	addr=ROM_CH_START+(unsigned int)channel*ROM_CHANNEL_LENGTH+byte_no;
	cli();
	if (_EepromRealWriteByte(addr++,bybuf[byte_no])==0) {
		byte_no++;
	}
	sei();
	return byte_no;	
}

//---------------------------------------------------------------------
char EepromRealSaveCalRateBlock(unsigned char byChannel,unsigned char byByteCnt)
{
	// Write�� ������ ���� ����Ʈ ��ȣ�� ������
	unsigned int addr;
	unsigned char byte_no=byByteCnt;
	unsigned char bybuf[4];

	bybuf[0]=StChannel[byChannel].uniAdcCalRate.byte[0];
	bybuf[1]=StChannel[byChannel].uniAdcCalRate.byte[1];
	bybuf[2]=StChannel[byChannel].uniAdcCalRate.byte[2];
	bybuf[3]=StChannel[byChannel].uniAdcCalRate.byte[3];


	addr=ROM_CAL_RATE_START+(unsigned int)byChannel*4+byte_no;

	cli();
	if (_EepromRealWriteByte(addr++,bybuf[byte_no])==0) {
		byte_no++;
	}
	sei();
	return byte_no;	
}

char EepromRealSaveCalRateAll(unsigned char byByteCnt)
{
	// �� Byte�� = Channel���� x 6 (=8*6=48), Write�� ������ ���� ����Ʈ ��ȣ�� ������
	int ibuf;
	unsigned int addr;
	unsigned char byte_no=byByteCnt;
	unsigned char by,bych;

	addr=ROM_CAL_RATE_START+byte_no;
	//Ver1.05 Cal Block Size�� 5���� 6���� ����(��ȣ�ִ� ������ ����ȯ�� �ȵǾ� ��ġ��)
	bych=byByteCnt/6;	//Channel Num 0~7; 	
	by=byByteCnt%6; 	//Byte Num in Channel Cal_Data 
	if (by<4) {
		by=StChannel[bych].uniAdcCalRate.byte[by];
	} else if (by==4) {
		//-----Offset MSB byte Encode //ADDR REF+4
		ibuf=StChannel[bych].iAdcOffset;
		ibuf>>=8;
		by=(unsigned char)ibuf;
	} else {
		//-----Offset LSB byte Encode //ADDR REF+5
		ibuf=StChannel[bych].iAdcOffset;
		ibuf&=0x00FF;
		by=(unsigned char)ibuf;
	}
	cli();
	if (_EepromRealWriteByte(addr,by)==0) {
		byte_no++;
	}
	sei();
	return byte_no;	
}

//---------------------------------------------------------------------
//------------------EEPROM Last Channel READ/WRITE --------------------
//---------------------------------------------------------------------
unsigned char EepromLoadLastCh(void)
{
	unsigned char ch;
	ch=_EepromReadByte(ROM_LAST_CH);
	if ((ch&0xF7)>=MAX_CHANNEL) ch=0;
	return ch;
}

//---------------------------------------------------------------------
void EepromSaveLastCh(unsigned char byCh)
{
	_EepromWriteByte(ROM_LAST_CH,byCh);
}

//---------------------------------------------------------------------
//------------------EEPROM Channel READ/WRITE -------------------------
//---------------------------------------------------------------------

//---------------------------------------------------------------------
void EepromSaveChOffset(unsigned char channel)
{

	unsigned int addr;
	unsigned char bybuf[ROM_CHANNEL_LENGTH];
	EncodeChData( channel,bybuf);

	addr=ROM_CH_START+(unsigned int)channel*ROM_CHANNEL_LENGTH;
	cli();
	_EepromWriteByte(addr+5,bybuf[5]);
	_EepromWriteByte(addr+6,bybuf[6]);
	_EepromWriteByte(addr+ROM_CHANNEL_LENGTH-1,bybuf[ROM_CHANNEL_LENGTH-1]);
	sei();	
}

//---------------------------------------------------------------------
//------------------EEPROM Sensor READ/WRITE -------------------------
//---------------------------------------------------------------------
/*Ver0.98f
//---------------------------------------------------------------------
void _EepromSaveSensorBlock(unsigned char bySensor)
{
	unsigned int addr;
	int i;
	unsigned char bybuf[ROM_SENSOR_LENGTH];
	EncodeSensorData( bySensor, bybuf);

	addr=ROM_SENSOR_START+(unsigned int)bySensor*ROM_SENSOR_LENGTH;

	for (i=0;i<ROM_SENSOR_LENGTH;i++) {
		_EepromWriteByte(addr++,bybuf[i]);	
	}
}
*/

/*Ver0.98f
//---------------------------------------------------------------------
void _EepromSaveChBlock(unsigned char channel)
{

	unsigned int addr;
	int i;
	unsigned char bybuf[ROM_CHANNEL_LENGTH];
	EncodeChData( channel,bybuf);

	addr=ROM_CH_START+(unsigned int)channel*ROM_CHANNEL_LENGTH;

	for (i=0;i<ROM_CHANNEL_LENGTH;i++) {
		_EepromWriteByte(addr++,bybuf[i]);	
	}
}
*/

/*Ver098f
//---------------------------------------------------------------------
void EepromSaveSensorBlock(unsigned char bySensor)
{
	cli();
	_EepromSaveSensorBlock(bySensor);
	sei();
}
*/
/*Ver0.98f 
//---------------------------------------------------------------------
void EepromSaveChBlock(unsigned char channel)
{
	cli();
	_EepromSaveChBlock(channel);
	sei();
}
*/

/*Ver0.98f
//---------------------------------------------------------------------
void EepromSaveAll(void)
{
	unsigned char i;
	cli();
	for (i=0;i<MAX_SENSOR;i++) {
		_EepromSaveSensorBlock(i);
	}
	for (i=0;i<MAX_CHANNEL;i++) {
		_EepromSaveChBlock(i);
	}
	_EepromWriteByte(0,0x5A);	

	sei();
}
*/

//---------------------------------------------------------------------
char _EepromLoadSensorBlock(unsigned char bySensor)
{
	//Return 0: Success, -1: Fail
	unsigned int addr;
	unsigned char ch;
	unsigned char dt[ROM_SENSOR_LENGTH];

	addr=ROM_SENSOR_START+(unsigned int)bySensor*ROM_SENSOR_LENGTH;

	//-----Read channel Block
	for (ch=0;ch<ROM_SENSOR_LENGTH;ch++) { 
		dt[ch]=_EepromReadByte(addr++);
	}
	//-----Verify CheckSum 
	return DecodeSensorData(bySensor,dt);
}

//---------------------------------------------------------------------
char EepromLoadSensorBlock(unsigned char bySensor)
{
	char rtn;
	cli();
	rtn=_EepromLoadSensorBlock(bySensor);
	sei();
	return rtn;
}
//---------------------------------------------------------------------

char _EepromLoadChBlock(unsigned char byCh)
{
	//Return 0: Success, -1: Fail

	unsigned int addr;
	unsigned char ch;
	unsigned char dt[ROM_CHANNEL_LENGTH];

	addr=ROM_CH_START+(unsigned int)byCh*ROM_CHANNEL_LENGTH;

	//-----Read channel Block
	for (ch=0;ch<ROM_CHANNEL_LENGTH;ch++) { 
		dt[ch]=_EepromReadByte(addr++);
	}
	//-----Verify CheckSum 
	return DecodeChData(byCh,dt);

}
//---------------------------------------------------------------------
char  EepromLoadChBlock(unsigned char byCh)
{
	char rtn;
	cli();
	rtn=_EepromLoadChBlock(byCh);
	sei();
	return rtn;
}
//---------------------------------------------------------------------
char  EepromLoadCalRateBlock(unsigned char byCh)
{	//��������(5%)�̳� �̸� �����ϰ� 0�� ����, �ƴϸ� 1�� �����ϰ� -1�� ���� 
	unsigned char by;
	int iOst;
	_FLOAT_UNION uniBuf;
	unsigned int addr;
	addr=ROM_CAL_RATE_START+(unsigned int)byCh*6;	//Ver1.05  CAL Block�� 6���� ���� 

	cli();
	uniBuf.byte[0]=_EepromReadByte(addr++);
	uniBuf.byte[1]=_EepromReadByte(addr++);
	uniBuf.byte[2]=_EepromReadByte(addr++);
	uniBuf.byte[3]=_EepromReadByte(addr++);
	by=_EepromReadByte(addr++);
	iOst=(unsigned int)by;
	iOst<<=8;
	by=_EepromReadByte(addr);
	iOst|=(unsigned int)by;
	sei();

	if (uniBuf.f>=0.95 && uniBuf.f<=1.05) {
		StChannel[byCh].uniAdcCalRate.f=uniBuf.f;
	} else {
		StChannel[byCh].uniAdcCalRate.f=1.00;
	}

	if (iOst>-20 && iOst<20 ) {
		StChannel[byCh].iAdcOffset=iOst;
	} else {
		StChannel[byCh].iAdcOffset=DEFAULT_ADC_OFFSET; //Ver0.99e ADC���� ������ 10���� �ӽ� ó�� 
	} 
	return 0;
}


//---------------------------------------------------------------------
void EepromSaveSensorOffset(unsigned char channel)
{

	unsigned int addr;
	unsigned char bybuf[ROM_SENSOR_LENGTH];
	EncodeSensorData( channel,bybuf);

	addr=ROM_SENSOR_START+(unsigned int)channel*ROM_SENSOR_LENGTH;
	cli();
	_EepromWriteByte(addr+5,bybuf[5]);
	_EepromWriteByte(addr+6,bybuf[6]);
	_EepromWriteByte(addr+ROM_SENSOR_LENGTH-1,bybuf[ROM_SENSOR_LENGTH-1]);
	sei();	
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------


//---------------------------------------------------------------------
//---------------------------------------------------------------------
char EepromLoadAll(void)
{
	unsigned char i;
	char rtn=0;
	cli();
	for (i=0;i<MAX_SENSOR;i++) {
		rtn=_EepromLoadSensorBlock(i);
		if (rtn!=0) {
			break;
		}
	}
	for (i=0;i<MAX_CHANNEL;i++) {
		rtn=_EepromLoadChBlock(i);
		if (rtn!=0) {
			break;
		}
	}
	for (i=0;i<MAX_CHANNEL;i++) {
		EepromLoadCalRateBlock(i);
	}
	sei();
	return rtn;
}
//---------------------------------------------------------------------
//---------------Oled Display-------------------------------------------
//---------------------------------------------------------------------
void DispUnitToStr(unsigned char byUnit ,char *cUnit) //���� -999~999
{
#if !VTVM
	if (byUnit==UNIT_MPA) {
		strcpy(cUnit,"MPA");
	} else if (byUnit==UNIT_KPA) {
		strcpy(cUnit,"KPA");
	} else if (byUnit==UNIT_BAR) {
		strcpy(cUnit,"BAR");
	} else if (byUnit==UNIT_PSI) {
		strcpy(cUnit,"PSI");
	}
#else 
	if (byUnit==UNIT_MPA) {
		strcpy(cUnit,"[V]");
	} else if (byUnit==UNIT_KPA) {
		strcpy(cUnit," mV");
	} else if (byUnit==UNIT_BAR) {
		strcpy(cUnit,"[A]");
	} else if (byUnit==UNIT_PSI) {
		strcpy(cUnit,"Jul");
	}
#endif
}

void DispMain(byte part, _CHDATA *stch)
{	//part bit0: Top bit 1:Display Value  bit2:Bottom Line 
	byte by;
	char cbuf[10];	//Max 6 digita - 0.000 
	by=part;	
	//-------------TOP LINE-------------------------
	if (by&0x01) {
		DBufClearRows(0,1,0,127);
#if 1		
		DispSetCh(0,0,ByChCur);
		//FlagActCh=CheckActiveCh();
		DispSetActChList(FlagActCh,ByChCur); 
		if (PMode<PMODE_RDISP)
			DispSetDispMode(104,0,0);
		else 
			DispSetDispMode(104,0,1);
#else
		DispSetMainMenu(0,1);
#endif
		LcdDispRow(0, 1);
	}
	
	if (by&0x02) {
		DBufClearRows(2,5,0,127);
		if (stch->bySensor<MAX_SENSOR) {
			DispFixedPrsToStr(stch->iPrsCur-stch->iOffset, stch->byUnit, cbuf);
		} else {	
			strcpy(cbuf,"NONE..");
		}	
		e32printf(4, 2, PUT_NORMAL , cbuf);
		DispSetUnit(104,2,PUT_NORMAL, stch->byUnit);
		DispSetSym(112,4,PUT_NORMAL, stch->byTrgType+5);
		LcdDispRow(2, 5);
	}	
	//-------------BOTTOM  LINE-------------------------
	if (by&0x04) {
		DBufClearRows(6,7,0,127);
		DispSetTrgCh(ByChOutData);
		LcdDispRow(6,7); // All Display
	}

}


void DispSetDispMode(byte xpos,byte yline, byte byMode)
{	//top line Menu - byMenu: On Menu�� bit�� ǥ�� 
	byte by;
	if (byMode==0) {
		e16printf(xpos,yline,PUT_NORMAL,(char *)"NOR");
	} else if (byMode==1) {
		e16printf(xpos,yline,PUT_NORMAL,(char *)"ROT");
	}	
	by=yline*8;
	DBufDrawBox(1,xpos,by,xpos+23,by+14);
	
}
void DispSetStrAndNum(byte xpos, byte yline, char *str, int iValue)
{	//TrgOn bit�� 1�̸� Trg ON���¸� ǥ�� 
	char cBuf[17];
	sprintf(cBuf,"%s%d",str,iValue);
	e16printf(xpos,yline,PUT_NORMAL,cBuf);
}

//void DispPrsToStr(int iPrs,unsigned char byUnit ,char *cPrs) //���� -999~999
void DispSetUnit(byte xpos,byte yline, byte put_mode, byte byUnit)
{	//TrgOn bit�� 1�̸� Trg ON���¸� ǥ�� 
	char cbuf[4];
	DispUnitToStr(byUnit,cbuf);
	e16printf(xpos,yline,put_mode,cbuf);
}
void DispSetUnit_8(byte xpos,byte yline, byte put_mode, byte byUnit)
{	//TrgOn bit�� 1�̸� Trg ON���¸� ǥ�� 
	char cbuf[4];
	DispUnitToStr(byUnit,cbuf);
	eprintf(xpos,yline,put_mode,cbuf);
}



void DispSetSym(byte xpos,byte yline, byte put_mode,byte bySym)
{	//�ڽ��ȿ� ä�� ǥ�� 
	DBufDrawFont16x16(xpos,yline, put_mode, &sym_box_fnt[bySym][0]);
}


void DispSetCh(byte xpos,byte yline, byte byCh)
{	//�ڽ��ȿ� ä�� ǥ��  byCh:0~7 => chǥ�ô�  1~8 
	byte by;
	char cbuf[4];
	by=byCh+1;
	sprintf(cbuf,"CH%d",(int)by);
	//e16printf(104,2,PUT_REVERSE,cbuf);
	e16printf(xpos,yline,PUT_NORMAL,cbuf);
	by=yline*8;
	DBufDrawBox(1,xpos,by,xpos+23,by+14);
}

void DispSetActChList(byte flagActCh, byte byCh)
{	//Ȱ��ȭ�� ä�� ǥ��,  byCh:0~7 => chǥ�ô�  1~8
	byte by,by2,byc;
	byte byX=32;
	for (by=0;by<MAX_CHANNEL;by++) {
		byc=0x01;
		byc<<=by;
		by2=by+1;
		if ((flagActCh & byc)!=0) { //if Active Channel
			if (byCh==by)  by2+=10;	//��� ���ڷ� ��Ʈ ���� 
			DBufDrawFont16x8(byX, 0, PUT_NORMAL, &num_cir_fnt[by2][0]);
			byX+=8;
		}
	}	
}

void DispSetTrgCh(unsigned char TrgOn)
{	//TrgOn bit�� 1�̸� Trg ON���¸� ǥ�� 
	unsigned char by;
	unsigned char byX=0;
	unsigned char byTrgOn=TrgOn;
	for (by=1;by<9;by++){
		if ((byTrgOn&0x01)==0)  
			DBufDrawFont16x16(byX, 6, PUT_NORMAL, &num_box_fnt[by][0]);
		else 
			DBufDrawFont16x16(byX, 6, PUT_REVERSE, &num_box_fnt[by][0]);
		byX+=16;
		byTrgOn>>=1;
	}

}

void DispSetMainMenu(byte byMenu, byte byStyle)
{	//top line Menu - byMenu: On Menu�� bit�� ǥ�� 
	// byStyle 0:None select, 1:Box style, 2:Revese style
	byte by;
/*	
#if 0
	byte by2;
	byte byRight;
	byte xPos=0;
	char cMenu[5][5];
	strcpy(cMenu[0],"Edit");
	strcpy(cMenu[1],"Calb");
	strcpy(cMenu[2],"ClrC");
	strcpy(cMenu[3],"Copy");
	strcpy(cMenu[4],"Retn");
	DBufClearRows(0,1, 0, 127);
	for (by=0;by<4;by++) {
		by2=by;		
		if (byMenu>3) by2++; 
		if (byStyle==0) {	//None select
			e16printf(xPos,0,PUT_NORMAL,cMenu[by2]);
		} else if (byStyle==1) {	//Box style
			e16printf(xPos,0,PUT_NORMAL,cMenu[by2]);
			if (by2==byMenu) {
				if (by==3) byRight=xPos+24;
				else byRight=xPos+31;
				DBufDrawBox(1, xPos, 0, byRight, 14);
			}
		} else if (byStyle==2) {	//Revese style
			if (by2==byMenu) {
				e16printf(xPos,0,PUT_REVERSE,cMenu[by2]);
			} else {
				e16printf(xPos,0,PUT_NORMAL,cMenu[by2]);
			}
		} else if (byStyle==3) {	//Nor Box And Selected Revese style
			if (by2==byMenu) {
				e16printf(xPos,0,PUT_REVERSE,cMenu[by2]);
			} else {
				e16printf(xPos,0,PUT_NORMAL,cMenu[by2]);
			}
			DBufDrawBox(1, 0, 0, 31, 14);
			DBufDrawBox(1, 31, 0, 63, 14);
			DBufDrawBox(1, 63, 0, 95, 14);
			DBufDrawBox(1, 95, 0, 127, 14);
		}	
		xPos+=32;
	}
#else 
	byte by2;
	byte bya[5];
	for (by=0;by<5;by++) {
		bya[by]=PUT_NORMAL;
	}	
	if (byStyle>1)  bya[byMenu]=PUT_REVERSE;
	if (byMenu==4) {
		e16printf(0,0,bya[1],(char *)"Calb");
		e16printf(32,0,bya[2],(char *)"ClrC");
		e16printf(64,0,bya[3],(char *)"Copy");
		e16printf(96,0,bya[4],(char *)"Exit");
	} else {	
		e16printf(0,0,bya[0],(char *)"Edit");
		e16printf(32,0,bya[1],(char *)"Calb");
		e16printf(64,0,bya[2],(char *)"ClrC");
		e16printf(96,0,bya[3],(char *)"Copy");
	}
	if (byStyle==1) {
		if (byMenu==4) {
			DBufDrawBox(1, 96, 0, 127, 14);
		} else {	
			by=byMenu*32;
			by2=by+31;
			DBufDrawBox(1, by, 0, by2, 14);
		}
	} else if (byStyle==3) {	//All Box 
		DBufDrawBox(1, 0, 0, 31, 14);
		DBufDrawBox(1, 31, 0, 63, 14);
		DBufDrawBox(1, 63, 0, 95, 14);
		DBufDrawBox(1, 95, 0, 127, 14);
	}
#endif
*/
	byte bya[5];
	for (by=0;by<5;by++) {
		bya[by]=PUT_NORMAL;
	}	
	if (byStyle>1)  bya[byMenu]=PUT_REVERSE;
	if (byMenu>2) {
		e16printf(0,0,PUT_NORMAL,(char *)"<");
		e16printf(10,0,bya[2],(char *)"ClrC");
		e16printf(48,0,bya[3],(char *)"Copy");
		e16printf(86,0,bya[4],(char *)"Exit");
	} else {	
		e16printf(10,0,bya[0],(char *)"Edit");
		e16printf(48,0,bya[1],(char *)"Calb");
		e16printf(86,0,bya[2],(char *)"ClrC");
		e16printf(120,0,PUT_NORMAL,(char *)">");
	}
	if (byStyle==1) {
		if (byMenu==0) {
			DBufDrawBox(1, 8, 0, 42, 15);
		} else if (byMenu==4) {
			DBufDrawBox(1, 84, 0, 118, 15);
		} else {
			DBufDrawBox(1, 46, 0, 80 , 15);
		}
			
	} else if (byStyle==3) {	//All Box 
			DBufDrawBox(1, 8, 0, 42, 15);
			DBufDrawBox(1, 46, 0, 80 , 15);
			DBufDrawBox(1, 84, 0, 118, 15);
	}

}

void DispSetCopyMain(byte byMenu, byte byEdit)
{	//top line Menu - byMenu: ���õ� �޴�, byEdit 0:Normal (Check Only) 1: Enter Edit Mode 
	byte by;
	//byte xPos=0;
	byte bya[3],byb[3];	//For Reverse Display - bya: �׸� , byb:��   
	char cBuf[9];
	DBufClearRows(2,7, 0, 127);
	for (by=0;by<3;by++) { 
		bya[by]=PUT_NORMAL;
		byb[by]=PUT_NORMAL;
	}	
	//----------�׸� �����̸� �׸��� �������� �ƴϸ� Menu�� �������� 
	if (byEdit==0) bya[byMenu]=PUT_REVERSE;
	else byb[byMenu]=PUT_REVERSE;
	

	e16printf(0,2,bya[0],(char *)"SRC CH : ");
	itoa(BySource+1,cBuf,10); 
	e16printf(72, 2, byb[0], cBuf);

	e16printf(0, 4, bya[1], (char *)"TRG CH : ");
	if (ByTarget==8) strcpy(cBuf,"ALL");
	else itoa(ByTarget+1,cBuf,10); e16printf(72, 4, byb[1], cBuf);
		
	if (bya[2]==1) ByRefBuf=0;	//�ʱ�ġ�� Yes
	e16printf(0,6,bya[2],(char *)"COPY?");
	DispSetSym(48, 6, byb[2], SYM_YES+ByRefBuf);

}

void DispSetEditMain(byte byMenu, byte byEdit)
{	//top line Menu - byMenu: ���õ� �޴�, byEdit 0:Normal (Check Only) 1: Enter Edit Mode 
	byte by;
	//byte xPos=0;
	byte byUnit;
	byte bya[9],byb[9];	//For Reverse Display - bya: �׸� , byb:��   
	char cBuf[9],cBuf1[9];
	DBufClearRows(2,7, 0, 127);
	for (by=0;by<9;by++) { 
		bya[by]=PUT_NORMAL;
		byb[by]=PUT_NORMAL;
	}	
	//----------�׸� �����̸� �׸��� �������� �ƴϸ� Menu�� �������� 
	if (byEdit==0) bya[byMenu]=PUT_REVERSE;
	else byb[byMenu]=PUT_REVERSE;
	
	if( byMenu<1) {
		//-----------1'st Page - Sensor Information ------------------
		e16printf(0,2,bya[0],(char *)"Sns:"); e16printf(32,2,byb[0],StSensor[StChannelBuf.bySensor].cName);
		e16printf(64,2, PUT_NORMAL,(char *)"SBU:"); DispSetUnit( 104, 2, PUT_NORMAL, StSensor[StChannelBuf.bySensor].byUnit);
		//----------Range of Senor as Sensor Unit 
		byUnit=StSensor[StChannelBuf.bySensor].byUnit;
		DispFixedPrsToStr(StSensor[StChannelBuf.bySensor].iPrsMin , byUnit, cBuf);
		DispFixedPrsToStr(StSensor[StChannelBuf.bySensor].iPrsMax ,byUnit, cBuf1);
		sprintf(StrBuf,"RNG:%s~%s",cBuf , cBuf1);
		e16printf(0,4,PUT_NORMAL, StrBuf); 
		//----------Range of Channel as Channel Unit 
		byUnit=StChannelBuf.byUnit;
		DispFixedPrsToStr(StSensor[StChannelBuf.bySensor].iPrsMin , byUnit, cBuf);
		DispFixedPrsToStr(StSensor[StChannelBuf.bySensor].iPrsMax ,byUnit, cBuf1);
		sprintf(StrBuf,"#%s~%s",cBuf , cBuf1);
		e16printf(0,6,PUT_NORMAL, StrBuf); 
		DispSetUnit_8 (104, 7, PUT_NORMAL, byUnit);	//Display Unit
		
		/*		
		DispPrsToStr(StSensor[StChannelBuf.bySensor].iPrs_0V , StSensor[StChannelBuf.bySensor].byUnit, cBuf);
		sprintf(StrBuf,"PRS_0V:%s",cBuf);
		e16printf(0,6,PUT_NORMAL, StrBuf);
		*/
		
	} else if( byMenu<3) {
		//-----------2'nd Page - Chanel Information A -----------------------
		e16printf(0,2,bya[0],(char *)"SNSR:"); e16printf(40,2,byb[0],StSensor[StChannelBuf.bySensor].cName);
		e16printf(0,4,bya[1],(char *)"Unit:"); DispSetUnit( 40, 4, byb[1], StChannelBuf.byUnit);
		e16printf(0,6,bya[2],(char *)"Trig:"); DispSetSym(40, 6, byb[2], StChannelBuf.byTrgType+SYM_TRG_SIGLE);
	} else if( byMenu<6) {

		e16printf(0,2,bya[3],(char *)"T.on:"); 
		DispFixedPrsToStr(StChannelBuf.iTrgOn, StChannelBuf.byUnit, cBuf);
		e16printf(40, 2, byb[3], cBuf);
		
		e16printf(0,4,bya[4],(char *)"Toff:");
		DispFixedPrsToStr(StChannelBuf.iTrgOff, StChannelBuf.byUnit, cBuf);
		e16printf(40, 4, byb[4], cBuf);
		
		e16printf(0,6,bya[5],(char *)"Hyst:");
		DispFixedPrsToStr(StChannelBuf.iHyst, StChannelBuf.byUnit, cBuf);
		e16printf(40,6, byb[5], cBuf);
	} else if( byMenu<9) { 
		//-----------3'rd Page-----------------------

		e16printf(0,2,bya[6],(char *)"Delay:");DispSetEditDelay(48,2,byb[6],StChannelBuf.byDelayMode);
		e16printf(0,4,bya[7],(char *)"Out Type:");
		if (StChannelBuf.bySwType==0) e16printf(80,4,byb[7],(char *)"N.OFF");
		else e16printf(80,4,byb[7],(char *)"N.ON ");
		if (byMenu==8) {
			if (bya[8]==1) ByRefBuf=0;	//�ʱ�ġ�� Yes
			e16printf(0,6,bya[8],(char *)"SAVE?");
			DispSetSym(48, 6, byb[8], SYM_YES+ByRefBuf);
		}	
	}	
}

void DispSetEditDelay(byte xpos,byte yline, byte put_mode, byte delay_mode)
{
	char cbuf[6];
	if (delay_mode==PRS_AVG_5mS) strcpy(cbuf,"5mS");
	else if  (delay_mode==PRS_AVG_50mS) strcpy(cbuf,"50mS");
	else if  (delay_mode==PRS_AVG_100mS) strcpy(cbuf,"100mS");
	else if  (delay_mode==PRS_AVG_250mS) strcpy(cbuf,"250mS");
	else if  (delay_mode==PRS_AVG_500mS) strcpy(cbuf,"500mS");
	else if  (delay_mode==PRS_AVG_750mS) strcpy(cbuf,"750mS");
	else if  (delay_mode==PRS_AVG_1S) strcpy(cbuf,"1Sec");
	else strcpy(cbuf,"100mS");
	e16printf(xpos,yline,put_mode,cbuf);
}
void DispSetEditOutType(byte xpos,byte yline, byte put_mode, byte output_type)
{
	char cbuf[6];
	if (output_type==0) strcpy(cbuf,"n.OFF");
	else  strcpy(cbuf,"n.ON");
	e16printf(xpos,yline,put_mode,cbuf);
	
}

void DispSetYesNo(byte xpos,byte yline, byte byYes)
{
	if (byYes==0) {	//NO
		e16printf(xpos,yline,PUT_NORMAL,(char *)"Yes");
		e16printf(xpos+32,yline,PUT_REVERSE,(char *)"No");
	} else if (byYes==1){
		e16printf(xpos,yline,PUT_REVERSE,(char *)"Yes");
		e16printf(xpos+32,yline,PUT_NORMAL,(char *)"No");
	} else {
		e16printf(xpos,yline,PUT_NORMAL,(char *)"Yes");
		e16printf(xpos+32,yline,PUT_NORMAL,(char *)"No");
	} 
}

void DispSetPrs(byte xpos,byte yline, int iPrs,unsigned char byUnit ) //Ver0.99 -199.9 ~ 9999 
{
	char cbuf[8];
	DispPrsToStr(iPrs,byUnit,cbuf);
	e16printf(xpos, yline, PUT_NORMAL, cbuf);
}

void DispPrsToStr(int iPrs,unsigned char byUnit ,char *cPrs) //���� -999~999
{	//Basic Function : DisplaySetPrs()
	//�Է� �з��� ������ MPA,KPA,BAR�� HPA. PSI�� 10mPSI ������ ����  
	//�з� ������ ���� �ڸ����� �ٸ��� ǥ���� 
	//ǥ�� ���� : -145 ~ 0.00 ~ +145 -> 100�� �ϰ�� -14,500 ~ 0 ~ +14,500
	int i =iPrs;
	double f;
	char cbuf[10];

	f=i;
	switch (byUnit) {
		case UNIT_MPA:	//�ӷ�(HPA) * 0.0001  9999=> 0.9999 => //�Ҽ��� 3�ڸ�
			f/=10000;
			if (f<0) sprintf(cbuf,"%6.3f",f);
			else sprintf(cbuf,"%5.3f",f);
			break;
		case UNIT_KPA:	//�ӷ�(HPA) * 0.1 
			if (i<10000) {	//�Ҽ��� 1�ڸ� ǥ�� 
				f/=10;
				if (f<0) sprintf(cbuf,"%6.1f",f);
				else sprintf(cbuf,"%5.1f",f);
			} else {		//���� ǥ�� 
				i/=10;
				if (i<0) sprintf(cbuf,"%5d",i);
				else sprintf(cbuf,"%4d",i);
			}
			break;

		case UNIT_BAR:	//�ӷ�(HPA) * 0.001 
			if (i<10000) {
				f/=1000;
				if (f<0) sprintf(cbuf,"%6.3f",f);
				else sprintf(cbuf,"%5.3f",f);
			}else {
				f/=1000;
				if (f<0) sprintf(cbuf,"%6.2f",f);
				else sprintf(cbuf,"%5.2f",f);
			}
			break;
		case UNIT_PSI:	//�⺻ �Ҽ��� 2�ڸ�  
		 	if (i<1000) {
				f/=100;
				if (f<0) sprintf(cbuf,"%6.2f",f);
				else sprintf(cbuf,"%5.2f",f);
			} else if (i<10000) { 
				f/=100;
				if (f<0) sprintf(cbuf,"%6.1f",f);
				else sprintf(cbuf,"%5.1f",f);
			} else {
				i/=100;
				if (i<0) sprintf(cbuf,"%5d",i);
				else sprintf(cbuf,"%4d",i);
			}
			break;
		default:
			break;
	}
	strcpy(cPrs,cbuf);
}

void DispSetFacManu(byte byMenu)
{	//top line Menu - byMenu: ���õ� �޴�, byEdit 0:Normal (Check Only) 1: Enter Edit Mode 
	// byStyle 0:None select, 1:Box style, 2:Revese style
	byte by;
	byte bya[9];
	DBufClearRows(2,7, 0, 127);
	for (by=0;by<8;by++) {
		if (by==byMenu) bya[by]=PUT_REVERSE;
		else bya[by]=PUT_NORMAL;
	}	
	e16printf(0,2,bya[0],(char *)"INIT");
	e16printf(40,2,bya[1],(char *)"ARUN");
	e16printf(80,2,bya[2],(char *)"SENSOR");
	e16printf(0,4,bya[3],(char *)"CALB");
	e16printf(40,4,bya[4],(char *)"CLRC");
	e16printf(80,4,bya[5],(char *)"SEND");
	e16printf(0,6,bya[6],(char *)"RCV");
	e16printf(40,6,bya[7],(char *)"EXIT");
	
}



void DispSetFixedPrs(byte xpos,byte yline, int iPrs, byte byUnit) //Ver0.99 -199.9 ~ 9999 
{
	char cbuf[8];
	DispFixedPrsToStr(iPrs, byUnit, cbuf);
	e32printf(xpos, yline, PUT_NORMAL, cbuf);
}

void DispFixedPrsToStr(int iPrs, byte byUnit, char *cPrs) //Ver0.99 -199.9 ~ 9999 
{	//�Է� �з��� ������ HPA�� �Ǵ� 10mPsi�� ����.
	//�з� ������ ���� �ڸ����� �ٸ��� ǥ���� 
	//ǥ�� ���� : -145 ~ 0.00 ~ +145 -> 100�� �ϰ�� -14,500 ~ 0 ~ +14,500
	int i;
	int mode=0; 
	double f;
	//------PRECISION Digit ����
	if (ByPrsStep==1) {
		switch (byUnit) {
			case UNIT_MPA:
				mode=PRECISION_3;
				break;
			case UNIT_KPA:
				mode=PRECISION_1;
				break;
			case UNIT_BAR:
				mode=PRECISION_3;
				break;
			case UNIT_PSI:
				mode=PRECISION_2;
				break;
			default:
				break;
		}
	} else if (ByPrsStep==10) {
		switch (byUnit) {
			case UNIT_MPA:
				mode=PRECISION_3;
				break;
			case UNIT_KPA:
				mode=PRECISION_0;
				break;
			case UNIT_BAR:
				mode=PRECISION_2;
				break;
			case UNIT_PSI:
				mode=PRECISION_1;
				break;
			default:
				break;
		}
	}
	//---------Display---------------------------
	i=iPrs;
	if (ByPrsStep==10) i+=5;		//Ver1.51 �ݿø� ���� 
	i/=ByPrsStep;
	if (i<-1999) i=-1999;	

	switch (mode) {
		case PRECISION_0:	//���� ǥ��
			if (i<0) 	sprintf(cPrs,"%5d", i);
			else sprintf(cPrs,"%4d", i);
			break;
		case PRECISION_1:	//�Ҽ��� 1�ڸ�
			f=i;
			f/=10;
			if (i<0) sprintf(cPrs,"%6.1f",f);
			else sprintf(cPrs,"%5.1f",f);
			break;
		case PRECISION_2:	//�Ҽ��� 2�ڸ�
			f=i;
			f/=100;
			if (i<0) sprintf(cPrs,"%6.2f",f);
			else sprintf(cPrs,"%5.2f",f);
			break;
		case PRECISION_3:	//�Ҽ��� 3�ڸ�
			f=i;
			f/=1000;
			if (i<0) sprintf(cPrs,"%6.3f",f);
			else sprintf(cPrs,"%5.3f",f);
			break;
	}
}

void DispSetErr(unsigned char ErrNo)
{
	char cbuf[8];
	DBufClearRows(2, 5, 0, 101);
	sprintf(cbuf,"ERR %d",(int) ErrNo);
	e32printf(0, 2, PUT_NORMAL, cbuf);
}

//---------------------------------------------------------------------
void DispSetErrFlag(void)
{
	unsigned char bych=0;
	if (FlagLowPrs!=0) {
		FlagError|=0x01;
		if (FlagLowPrs & 0x01) bych=1;
		else if (FlagLowPrs & 0x02) bych=2;
		else if (FlagLowPrs & 0x04) bych=3;
		else if (FlagLowPrs & 0x08) bych=4;
		else if (FlagLowPrs & 0x10) bych=5;
		else if (FlagLowPrs & 0x20) bych=6;
		else if (FlagLowPrs & 0x40) bych=7;
		else if (FlagLowPrs & 0x80) bych=8;
	} else if (FlagHighPrs!=0) {
		FlagError|=0x02;
		if (FlagHighPrs & 0x01) bych=1;
		else if (FlagHighPrs & 0x02) bych=2;
		else if (FlagHighPrs & 0x04) bych=3;
		else if (FlagHighPrs & 0x08) bych=4;
		else if (FlagHighPrs & 0x10) bych=5;
		else if (FlagHighPrs & 0x20) bych=6;
		else if (FlagHighPrs & 0x40) bych=7;
		else if (FlagHighPrs & 0x80) bych=8;
	} else {
		FlagError&=0xFC;	
	}
	if (FlagError & 0x01) {			//Sensor Low Prs Error 
		DispSetErr(bych);	
	} else if (FlagError & 0x02) {	//Sensor high Prs Error	 	
		DispSetErr(10+bych);
	} else if (FlagError & 0x04) {	//Low Channel Overload	
		DispSetErr(21);
	} else  if (FlagError & 0x08) {	//high Channel Overload	
		DispSetErr(22);
	} else if (FlagError & 0x80) { //Non used
		DispSetErr(03);
	} else if (FlagError & 0x10) { //Non used
		DispSetErr(04);
	} else if (FlagError & 0x20) { //Non used 
		DispSetErr(05);
	} else if (FlagError & 0x40) { //Non used 
		DispSetErr(15);
	} 
}

byte  DispSetRowFlag(byte start, byte end)
{	//Lcd�� Data�� �����ؾ��ϴ� Line�� �ش��ϴ� bit�� set - ref FlagReqLcdRow
	byte by,byf;
#if 0
	byf=0;
	for (by=start;by=<end;by++) {
		byf|=(0x01<<by);
	}
#else 
	byf=0xFF;
	by=end-start+1;
	byf<<=by;	
	byf=~byf;
	byf<<=start;
#endif
	return byf;	
}

//---------------------------------------------------------------------
//---------------7'Segment 1/6 duty Display & Key Scan-----------------
//---------------------------------------------------------------------
void Display(unsigned char seq)
{	
}

//---------------------------------------------------------------------
void DisplaySetChannel(unsigned char byData)
{
}


//---------------------------------------------------------------------
void DisplaySetNum(int iNum) //���� -999~999
{
}

//---------------------------------------------------------------------
void DisplaySetPrs(int iPrs,unsigned char byUnit) //���� -999~999
{	
}

void DisplaySetFixedPrs(int iPrs,_CHDATA *StCh) //Ver0.99 -199.9 ~ 9999 
{
}

//---------------------------------------------------------------------
void DisplaySetAvgTime(unsigned char delay_mode) //���� -999~999
{
}



//---------------------------------------------------------------------
void DisplaySetStr(const char *cstr)
{
}
void DisplaySetScrollStr(const char *cstr)
{
}

void DisplaySetEditMode(unsigned char byEditMode)
{
}


//---------------------------------------------------------------------
void DisplaySetChFrom(unsigned char byCh)
{	//Edit�� Copy Channel�� �ҽ� æ��ǥ�� - Display "Fr X"
}

//---------------------------------------------------------------------
void DisplaySetChTo(unsigned char byCh)
{
}

//---------------------------------------------------------------------
void DisplaySetLine(void)
{
}

//---------------------------------------------------------------------
void DisplaySetEnd(unsigned char byMode)
{	//0:Continue  1:END
}
//---------------------------------------------------------------------
void DisplaySetStop(void)
{
}
//---------------------------------------------------------------------
void DisplaySetInit(void)
{
}
//---------------------------------------------------------------------
void DisplaySetFac(unsigned char mode)
{
	// enum {FAC_INIT, FAC_AUTO_RUN, FAC_CLR_CAL, FAC_CAL, FAC_SENSOR, FAC_REMOTE};
	FlagDot=0x00;
	DisplaySetChannel('F');
	if (mode==FAC_INIT) {
		DisplaySetStr("INIT");
	} else if (mode==FAC_AUTO_RUN) {
		DisplaySetStr("ARUN");
		FlagDot=0x01;
	} else if (mode==FAC_CLR_CAL) {
		DisplaySetStr("CLRC");
		FlagDot=0x04;
	} else if (mode==FAC_CAL) {
		DisplaySetStr("CALB");
	} else if (mode==FAC_SENSOR) {
		DisplaySetStr("SENS");
	} else if (mode==FAC_SEND) { 
		DisplaySetStr(" SND");
	} else if (mode==FAC_RCV) { 
		DisplaySetStr(" RCV");
	} else if (mode==FAC_REMOTE) {
		DisplaySetStr(" RTN");
		FlagDot=0x00;
	} 
}

void DisplaySetHighPrs(unsigned char byCh)
{
}

void DisplaySetLowPrs(unsigned char byCh)
{
}


//---------------------------------------------------------------------
void DisplaySetErr(unsigned char ErrNo)
{
}

//---------------------------------------------------------------------
void DisplaySetUnit(unsigned char byUnit)
{
} 

//---------------------------------------------------------------------
void DisplaySetTrgType(unsigned char byTrgType)
{
}


//---------------------------------------------------------------------
void DisplaySetSwType(unsigned char bySwType)
{
} 


//---------------------------------------------------------------------
void DisplaySetSensor(unsigned char bySensor)
{
}

//---------------------------------------------------------------------

//---------------------------------------------------------------------
void DisplaySetYesNo(unsigned char byYes)
{
} 

//---------------------------------------------------------------------
//----------------------------------Key Scan---------------------------
//---------------------------------------------------------------------
//ByKey    : ó���ؾ� �� Key�� ���� ��� Key���� ����  
//ByKeyBuf : ���� Key�� ���� ���� ���� 
//ByOldKeyBuf : ���� ���� Key��
//FlagKey  : b0:  b1:Key Ready b2:Long Key b3:Continue Key  
char KeyScan(unsigned char seq)
{	//Non Matrics
	char ch;
	char ch1=0;
	//-----Key Scan In

	ByKeyBuf=KEY_NO;

	ch=~PIND;
	ch&=0x30;
	if ((ch&0x10)==0x10) 
		ByKeyBuf=KEY_DN;
	if ((ch&0x20)==0x20) 
		ByKeyBuf=KEY_UP;
	if ((ch&0x30)==0x30) 
		ByKeyBuf=KEY_UPDN;

	ch=~PINA;
	if ((ch&0x80)==0x80) 
		ByKeyBuf=KEY_EDIT;

	if ( ByKeyBuf==KEY_NO ) {//Key�� �������� ��� �Է� ���� 
		FlagKey=0;
		ByOldKeyBuf=KEY_NO;
//		ByKey=KEY_NO;	//Ver1.8 ó�� �� �� Clear  
		return KEY_NO;
	}

	if (ByKeyBuf!=KEY_NO && ByOldKeyBuf==ByKeyBuf) { //Key�� ä�͸� Ÿ���� ������
			 
		WKeyTime++; //Push Time ���� 
		if (WKeyTime==15) {	//100mS
			FlagKey|=0x02; 	//Ready Key
			ByKey=ByKeyBuf; //Key�� ���� 
		}
		if (WKeyTime>300) {	//Long Key(���� �ҿ�ð� 4ms x 375 =1.5��) 
			FlagKey|=0x04;
		} 
		if (WKeyTime>1000) {//Continue Key(���� �ҿ�ð� 4ms x 1250 = 5��)
			FlagKey|=0x08;
			WKeyTime=1250;      
		}
	} else {
		ByOldKeyBuf=ByKeyBuf;
		FlagKey=0;
		WKeyTime=0;
		WKeyInterval=0;
	}
	 		
	if (ByOldKeyBuf==0 && ByKeyBuf!=KEY_NO) { //ó�� ����Key �̸�
		ByOldKeyBuf=ByKeyBuf;
		FlagKey=0;	//Key�Է� �� 
		WKeyTime=0;
		WKeyInterval=0;
	} 		
	asm volatile("nop"::);
	return ch1;
}

//---------------------------------------------------------------------
unsigned char EditDigit(unsigned char value,unsigned char max)
{
	if (ByKey==KEY_UP) { // UP
		if ((FlagKey&0x03)==0x02) { 
			value++;
			if (value>max) value=0;
//			ByKey=0; //Key ó�� �Ϸ�� �Է� ���  
			FlagKey=1;
		}
		if (FlagKey&0x04) {
			value++;
			if (value>max) value=0;
			FlagKey&=0xF3;
			WKeyTime=250;
		}
	}
	if (ByKey==KEY_DN) { // DOWN
		if ((FlagKey&0x03)==0x02 ) { 
			if (value==0) value=max;
				else value--;
			FlagKey=1;
		}
		if (FlagKey&0x04) {
			if (value==0) value=max;
				else value--;
			FlagKey&=0xF3;
			WKeyTime=40;
		}

	}
	return value;
}


unsigned char DigitUp(unsigned char byValue)
{
	unsigned char by;
	by=byValue;
	if ((FlagKey&0x03)==0x02) { 
		if (by>='A' && by<'Z') by++;
		else if (by>='0' && by<'9') by++;
		else if (by=='9') by='A';
		else if (by=='Z') by='0';
		else by=' ';
		FlagKey=1;	// 1ȸ �ﰢ ó�� �Ϸ� 
	}

	if (FlagKey&0x04) {
		if (by>='A' && by<'Z') by++;
		else if (by>='0' && by<'9') by++;
		else if (by=='9') by='A';
		else if (by=='Z') by='0';
		else by=' ';
		FlagKey&=0xF3;	//Flag Clear
		WKeyTime=313;

/*
		WKeyInterval+=1;
		if (WKeyInterval>110) WKeyInterval=110;
		if (WKeyInterval<10) WKeyTime=313;
			else if (WKeyInterval<110) WKeyTime=353;
			else WKeyTime=373;
*/
	}
	return by;
}

unsigned char DigitDown(unsigned char byValue)
{
	unsigned char by;
	by=byValue;
	if ((FlagKey&0x03)==0x02) { 
		if (by>'A' && by<='Z') by--;
		else if (by>'0' && by<='9') by--;
		else if (by=='A') by='9';
		else if (by=='0') by='Z';
		else by=' ';
		FlagKey=1;	// 1ȸ �ﰢ ó�� �Ϸ� 
	}

	if (FlagKey&0x04) {
		if (by>'A' && by<='Z') by--;
		else if (by>'0' && by<='9') by--;
		else if (by=='A') by='9';
		else if (by=='0') by='Z';
		else by=' ';
		FlagKey&=0xF3;	//Flag Clear
		WKeyTime=313;
	}
	return by;
}



//---------------------------------------------------------------------

unsigned char PrsSetStep(unsigned char byCh)		//Ver1.5
{	//æ���� ���� ���� �� ������ ���� PrsStep�� ������. [����] ByPrsStep & ByPrsStepAry
	unsigned char byRtn; 
	int ibuf;
	ibuf=StSensor[StChannel[byCh].bySensor].iPrsMax-StSensor[StChannel[byCh].bySensor].iPrsMin;
	if (ibuf<0) ibuf=-ibuf;
	if (ibuf>5000 || StChannel[byCh].byUnit==UNIT_MPA ) byRtn=10;
		else byRtn=1;
	return byRtn;
}

void PrsSetStepAll(void)		//Ver1.5
{
	unsigned char by;
	for (by=0;by<8;by++)
		ByPrsStepAry[by]=PrsSetStep(by);
}

//---------------------------------------------------------------------
int PrsUp(int iPrs,int iMax)
{
	int i,istep;
	i=iPrs;
	istep=1;
	if ((FlagKey&0x03)==0x02) { 
		iPrs+=istep;
		if (iPrs>iMax) iPrs=iMax;
		FlagKey=1;	// 1ȸ �ﰢ ó�� �Ϸ� 
	}

	if (FlagKey&0x04) {
		iPrs+=istep;
		if (iPrs>iMax) iPrs=iMax;
		FlagKey&=0xF3;	//Flag Clear
		WKeyInterval+=1;
		if (WKeyInterval>110) WKeyInterval=110;
		if (WKeyInterval<10) WKeyTime=313;
			else if (WKeyInterval<110) WKeyTime=353;
			else WKeyTime=373;
	}
	return iPrs;
}

int PrsDown(int iPrs,int iMin)
{
	int i,istep;
	i=iPrs;
	istep=1;
	if ((FlagKey&0x03)==0x02) { 
		iPrs-=istep;
		if (iPrs<iMin) iPrs=iMin;
		FlagKey=1;
	}

	if (FlagKey&0x04) {
		iPrs-=istep;
		if (iPrs<iMin) iPrs=iMin;
		FlagKey&=0xF3;	//Flag Clear
		WKeyInterval+=1;
		if (WKeyInterval>110) WKeyInterval=110;
		if (WKeyInterval<10) WKeyTime=313;
			else if (WKeyInterval<110) WKeyTime=353;
			else WKeyTime=373;

	}
	return iPrs;
}


int PrsStepUp(int iPrs,int iMax,int istep)
{
	int i;
	i=iPrs;
	if ((FlagKey&0x03)==0x02) { 
		iPrs+=istep;
		if (iPrs>iMax) iPrs=iMax;
		FlagKey=1;	// 1ȸ �ﰢ ó�� �Ϸ� 
	}

	if (FlagKey&0x04) {
		iPrs+=istep;
		if (iPrs>iMax) iPrs=iMax;
		FlagKey&=0xF3;	//Flag Clear
		WKeyInterval+=1;
		if (WKeyInterval>110) WKeyInterval=110;
		if (WKeyInterval<10) WKeyTime=313;
			else if (WKeyInterval<110) WKeyTime=353;
			else WKeyTime=373;
	}
	return iPrs;
}
int PrsStepDown(int iPrs,int iMin,int istep)
{
	int i;
	i=iPrs;
	if ((FlagKey&0x03)==0x02) { 
		iPrs-=istep;
		if (iPrs<iMin) iPrs=iMin;
		FlagKey=1;
	}

	if (FlagKey&0x04) {
		iPrs-=istep;
		if (iPrs<iMin) iPrs=iMin;
		FlagKey&=0xF3;	//Flag Clear
		WKeyInterval+=1;
		if (WKeyInterval>110) WKeyInterval=110;
		if (WKeyInterval<10) WKeyTime=313;
			else if (WKeyInterval<110) WKeyTime=353;
			else WKeyTime=373;

	}
	return iPrs;
}





//---------------------------------------------------------------------
//----------------------------INPUT Status Check-----------------------
//---------------------------------------------------------------------
void CheckInputStatus(void)
{
	unsigned char ch;
	//-----���� ���˟� �߻� ó�� 
	ch=PINB;
	if ((ch & 0x04)==0) { //Ver0.94 CH_1~4 ������ 
		FlagError|=0x04;
		IErrorTimeCnt=0;	//Ver0.99 �ڵ������� ���� SystemTimeCnt
	} else {
		if (IErrorTimeCnt>TIME_KEEP_ERROR) FlagError&=0xFB;
	}
	if ((ch & 0x08)==0) { 	//Ver0.94CH_5~8 ������
		FlagError|=0x08;
		IErrorTimeCnt=0;	//Ver0.99 �ڵ������� ���� SystemTimeCnt
	} else {
		if (IErrorTimeCnt>TIME_KEEP_ERROR) FlagError&=0xF7;
	}
}

unsigned char CheckActiveCh(void)
{	//each bits set if channel is active ,exsample return value : b0001 1011 => 1,2,4,5 channel acive     
	unsigned char by,by2;
	unsigned char FlagRtn=0;
	by2=0x01;
	for (by=0;by<MAX_CHANNEL;by++) {
		if (StChannel[by].bySensor<MAX_SENSOR) 	FlagRtn|=by2;
		by2<<=1;
	}
	return FlagRtn;
}
unsigned char CheckEndMode(unsigned char *byEnd)
{	//���:0,  EDNȮ��:1, Mode����:2  
	unsigned char byrtn=0;
	DisplaySetEnd(*byEnd);
	if (ByKey==KEY_EDIT) {
		byrtn=1;
		ISystemCnt=0;
		ByKey=KEY_NO;
	}
	if (ByKey==KEY_UP || ByKey==KEY_DN) {
		byrtn=2;
		*byEnd^=0x01;
		ISystemCnt=0;
		ByKey=KEY_NO;
	}
	return byrtn;
}

unsigned char CheckYesMode(byte xpos, byte yline, byte *byYes)
{	//���:0,  EDNȮ��:1, Mode����:2  
	unsigned char byrtn=0;

	if (ByKey==KEY_EDIT) {
		byrtn=1;
		ISystemCnt=0;
		ByKey=KEY_NO;
	}
	if (ByKey==KEY_UP || ByKey==KEY_DN) {
		DispSetSym(xpos,yline,PUT_REVERSE,SYM_YES+*byYes);
		byrtn=2;
		*byYes^=0x01;
		ISystemCnt=0;
		ByKey=KEY_NO;
	}
	return byrtn;
}


void TimeOutCheck(unsigned int TimeCnt, unsigned char pmode)
{
	if (ISystemCnt>TimeCnt) {
		PMode=pmode;
		ISystemCnt=0;
		ByKey=KEY_NO;
	}
}
//---------------------------------------------------------------------
//----------------------------UART Control---------------------------
//---------------------------------------------------------------------
void UartOpen(void)
{
#if Eagle_EYE_ACTIVE
	Usart1_Init(M16_192); 
#else 
	Usart1_Init(M16_1152);
#endif
	FlagUartOn=1;
}
void UartClose(void)
{
	Usart1_Init(M16_NON);
	FlagUartOn=0;
}
//---------------------------------------------------------------------
//----------------------------OUTPUT Control---------------------------
//---------------------------------------------------------------------
unsigned char ChOutControl(unsigned char byCh)
{	//�з��� ���Ͽ� ����� �����ϴ� �Լ� 
	int ist1,ist2,ist3,ist4,ilevel;
	unsigned char out;
	ilevel=StChannel[byCh].iPrsCur-StChannel[byCh].iOffset;
	ist1=StChannel[byCh].iTrgOn; //+StChannel[byCh].iHyst;
	ist2=StChannel[byCh].iTrgOff;
	ist3=ist1-StChannel[byCh].iHyst; 
	ist4=ist2-StChannel[byCh].iHyst;
	//-----�ξз� ������ ��� 
	if (StSensor[StChannel[byCh].bySensor].byNagative==1) {
		ilevel=-ilevel;
		ist1=-ist1; //+StChannel[byCh].iHyst;
		ist2=-ist2;
		ist3=ist1-StChannel[byCh].iHyst; 
		ist4=ist2-StChannel[byCh].iHyst;
	}
	//-----���з� and �ξз� ��� ���з� ��忡�� ������ 
	if (StChannel[byCh].byTrgType==TRIG_SINGLE) { //Single Trigger Type
		if ((StChannel[byCh].byOutStatus&0x01)==0 && ilevel>=ist1) StChannel[byCh].byOutStatus=1;
		if ((StChannel[byCh].byOutStatus&0x01)==1 && ilevel<ist3) StChannel[byCh].byOutStatus=0;
	} else { //Window Trigger type
		if (StChannel[byCh].byOutStatus==0x00) {	//Range : MIN~TrigOn
			if(ilevel>=ist1 )  StChannel[byCh].byOutStatus=0x01;//Range : TrigOn~TrigOff
			if(ilevel>=ist2)  StChannel[byCh].byOutStatus=0x10;
		} else if (StChannel[byCh].byOutStatus==0x01) { 	//Range : TrigOn~TrigOff
			if (ilevel<ist3) StChannel[byCh].byOutStatus=0;
			if (ilevel>=ist2) StChannel[byCh].byOutStatus=0x10;
		} else if (StChannel[byCh].byOutStatus==0x10) { //Range : TrigOff~Max
			if(ilevel<=ist3 )  StChannel[byCh].byOutStatus=0x11;
			if(ilevel<ist4 )  StChannel[byCh].byOutStatus=0x00;
		} 
	}
	out=(StChannel[byCh].byOutStatus & 0x01)^StChannel[byCh].bySwType;	//Switch Type����

	return out;
} 

unsigned char FindActiveChannel(unsigned char byCurCh)
{	
	unsigned char by,bych,byrtn;
	byrtn=byCurCh;
	bych=byCurCh%10;
	for (by=0;by<MAX_CHANNEL;by++) {
		if (StChannel[bych].bySensor<MAX_SENSOR) {
			byrtn=bych;
			break;
		} else {
			bych++;
			if (bych>=MAX_CHANNEL) bych=0;
		}
	}
	return byrtn;
}

//---------------------------------------------------------------------
//-------------------------Eagle-EYE Processor----------//Ver1.20-------
//---------------------------------------------------------------------
void EagleInit(unsigned char bOn) //Ver1.20 
{
	int i;
	//-----Eagle eye �ʱ�ȭ 
	ByEagleCmd=0;
	ByEaglePos=0;
	for (i=0;i<64;i++)	StUsart1.byTxBuf[i]=0;
	StUsart1.byTxBuf[0]=STX;
	StUsart1.byTxBuf[1]=0x00;
	StUsart1.byTxBuf[2]=19;
	StUsart1.byTxBuf[24]=ETX;

	if (bOn==1) UartOpen();
		else UartClose();
}

unsigned char EagleTrans(void)	//ByEagleBuf�� ���� .  
{	//������ ���ڸ� Return
	unsigned char bybuf[2];
	unsigned char bylen;
	bylen=StUsart1.byTxBuf[2]+5;	//��byte�� = Data Num + 5(STX,ID,DataNum,Chksym,ETX) 
	if (ByEagleCmd<2) return 0;
	if (ByEaglePos>=bylen) {
		ByEaglePos=0;
		ByEagleCmd=0;
		return 0;
	}
	bybuf[0]=StUsart1.byTxBuf[ByEaglePos++];
//	bybuf[1]=StUsart1.byTxBuf[ByEaglePos++];

	Usart1_WriteByte(bybuf[0]);
//	Usart1_WriteByte(bybuf[1]);
	return 1; 
		
}

//---------------------------------------------------------------------
void EaglePrsReflash(void)	//Eagle eye Data ���� 
{
	int ibuf,iPrs;
	unsigned char by,byPos=0;
	unsigned char chksum=0;
	StUsart1.byTxBuf[byPos++]=STX;
	StUsart1.byTxBuf[byPos++]=12;
	StUsart1.byTxBuf[byPos++]=24;
	for (by=0;by<8;by++) {
		//Ver1.3 iPrs=StChannel[by].iPrsCur-StChannel[by].iOffset;
		iPrs=StChannel[by].iCalibratedAdc;	//Ver1.3 ������ ADC���� ���۹��ۿ� ���� 
		//-----Pressure MSB byte Encode //ADDR REF+5
		ibuf=iPrs>>8;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
		//-----Pressure LSB byte Encode //ADDR REF+6
		ibuf=iPrs&0x00FF;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
	}
	//-----Unit Reflash
	by=0;
	by|=StChannel[7].byUnit;
	by<<=2;
	by|=StChannel[6].byUnit;
	by<<=2;
	by|=StChannel[5].byUnit;
	by<<=2;
	by|=StChannel[4].byUnit;
	StUsart1.byTxBuf[byPos++]=by;	
	by=0;
	by|=StChannel[3].byUnit;
	by<<=2;
	by|=StChannel[2].byUnit;
	by<<=2;
	by|=StChannel[1].byUnit;
	by<<=2;
	by|=StChannel[0].byUnit;
	StUsart1.byTxBuf[byPos++]=by;	
	//-----Output Reflash
	StUsart1.byTxBuf[byPos++]=ByChOutEnable;
	StUsart1.byTxBuf[byPos++]=ByChOutData;
	//-----Sensor Reflash
	by=StChannel[7].bySensor;
	by<<=4;
	by|=StChannel[6].bySensor;
	StUsart1.byTxBuf[byPos++]=by;	

	by=StChannel[5].bySensor;
	by<<=4;
	by|=StChannel[4].bySensor;
	StUsart1.byTxBuf[byPos++]=by;	

	by=StChannel[3].bySensor;
	by<<=4;
	by|=StChannel[2].bySensor;
	StUsart1.byTxBuf[byPos++]=by;	

	by=StChannel[1].bySensor;
	by<<=4;
	by|=StChannel[0].bySensor;
	StUsart1.byTxBuf[byPos++]=by;	
	//-----CHECK SUM  Reflash
	for (by=0;by<byPos;by++)
		chksum+=StUsart1.byTxBuf[by];
	StUsart1.byTxBuf[byPos++]=chksum;
	StUsart1.byTxBuf[byPos]=ETX;
}

//---------------------------------------------------------------------
void EagleSensorReflash(void)	//Eagle eye Data ���� 
{
	int ibuf,iPrs;
	unsigned char by,byBuf,byPos=0;
	unsigned char chksum=0;
	StUsart1.byTxBuf[byPos++]=STX;
	StUsart1.byTxBuf[byPos++]=16;
	StUsart1.byTxBuf[byPos++]=23;
	//-----MIN Prs Reflash (at 1V)
	for (by=0;by<5;by++) {
		iPrs=StSensor[by].iPrsMin;
		//-----Pressure MSB byte Encode 
		ibuf=iPrs>>8;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
		//-----Pressure LSB byte Encode 
		ibuf=iPrs&0x00FF;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
	}
	//-----MAX Prs Reflash (at 5V)
	for (by=0;by<5;by++) {
		iPrs=StSensor[by].iPrsMax;
		//-----Pressure MSB byte Encode //ADDR REF+5
		ibuf=iPrs>>8;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
		//-----Pressure LSB byte Encode //ADDR REF+6
		ibuf=iPrs&0x00FF;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
	}
	//-----Unit Reflash
	by=0;
	by|=StSensor[7].byUnit;
	by<<=2;
	by|=StSensor[6].byUnit;
	by<<=2;
	by|=StSensor[5].byUnit;
	by<<=2;
	by|=StSensor[4].byUnit;
	StUsart1.byTxBuf[byPos++]=by;	

	by=0;
	by|=StSensor[3].byUnit;
	by<<=2;
	by|=StSensor[2].byUnit;
	by<<=2;
	by|=StSensor[1].byUnit;
	by<<=2;
	by|=StSensor[0].byUnit;
	StUsart1.byTxBuf[byPos++]=by;	
	//-----Invert Type Reflash
	byBuf=0;
	for (by=0;by<8;by++)
		byBuf|=(StSensor[by].byNagative<<by);
	StUsart1.byTxBuf[byPos++]=byBuf;	

	//-----CHECK SUM  Reflash
	for (by=0;by<byPos;by++)
		chksum+=StUsart1.byTxBuf[by];
	StUsart1.byTxBuf[byPos++]=chksum;
	StUsart1.byTxBuf[byPos]=ETX;
}

//---------------------------------------------------------------------
void EagleTriggerReflash(void)	//Eagle eye Data ���� 
{
	int ibuf,iPrs;
	unsigned char by,byBuf,byPos=0;
	unsigned char chksum=0;
	StUsart1.byTxBuf[byPos++]=STX;
	StUsart1.byTxBuf[byPos++]=13;
	StUsart1.byTxBuf[byPos++]=33;
	//-----Trigger ON Prs Reflash
	for (by=0;by<8;by++) {
		iPrs=StChannel[by].iTrgOn;
		//-----Pressure MSB byte Encode 
		ibuf=iPrs>>8;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
		//-----Pressure LSB byte Encode 
		ibuf=iPrs&0x00FF;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
	}
	//-----Trigger OFF Prs Reflash
	for (by=0;by<8;by++) {
		iPrs=StChannel[by].iTrgOff;
		//-----Pressure MSB byte Encode 
		ibuf=iPrs>>8;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
		//-----Pressure LSB byte Encode 
		ibuf=iPrs&0x00FF;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
	}
	//-----Trigger Type Reflash
	byBuf=0;
	for (by=0;by<8;by++)
		byBuf|=(StChannel[by].byTrgType<<by);
	StUsart1.byTxBuf[byPos++]=byBuf;	

	//-----CHECK SUM  Reflash
	for (by=0;by<byPos;by++)
		chksum+=StUsart1.byTxBuf[by];
	StUsart1.byTxBuf[byPos++]=chksum;
	StUsart1.byTxBuf[byPos]=ETX;
	
}

//---------------------------------------------------------------------
void EagleOffsetReflash(void)	//Eagle eye Data ���� 
{
	int ibuf,iPrs;
	unsigned char by,byBuf,byPos=0;
	unsigned char chksum=0;
	StUsart1.byTxBuf[byPos++]=STX;
	StUsart1.byTxBuf[byPos++]=14;
	StUsart1.byTxBuf[byPos++]=17;
	//-----Offset Prs Reflash
	for (by=0;by<8;by++) {
		iPrs=StChannel[by].iOffset;
		//-----Pressure MSB byte Encode //ADDR REF+5
		ibuf=iPrs>>8;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
		//-----Pressure LSB byte Encode //ADDR REF+6
		ibuf=iPrs&0x00FF;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
	}
	//-----Swith Type Reflash
	byBuf=0;
	for (by=0;by<8;by++)
		byBuf|=(StChannel[by].bySwType<<by);
	StUsart1.byTxBuf[byPos++]=byBuf;	

	//-----CHECK SUM  Reflash
	for (by=0;by<byPos;by++)
		chksum+=StUsart1.byTxBuf[by];
	StUsart1.byTxBuf[byPos++]=chksum;
	StUsart1.byTxBuf[byPos]=ETX;
	
}

//---------------------------------------------------------------------
void EagleDelayReflash(void)	//Eagle eye Data ���� 
{
	int ibuf,iPrs;
	unsigned char by,byPos=0;
	unsigned char chksum=0;
	StUsart1.byTxBuf[byPos++]=STX;
	StUsart1.byTxBuf[byPos++]=15;
	StUsart1.byTxBuf[byPos++]=24;
	//-----Hyterisys Reflash
	for (by=0;by<8;by++) {
		iPrs=StChannel[by].iHyst;
		//-----Pressure MSB byte Encode 
		ibuf=iPrs>>8;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
		//-----Pressure LSB byte Encode 
		ibuf=iPrs&0x00FF;
		StUsart1.byTxBuf[byPos++]=(unsigned char)ibuf;
	}
	//-----Delay Type Reflash
	for (by=0;by<8;by++) {
		StUsart1.byTxBuf[byPos++]=StChannel[by].byDelayMode;
	}
	//-----CHECK SUM  Reflash
	for (by=0;by<byPos;by++)
		chksum+=StUsart1.byTxBuf[by];
	StUsart1.byTxBuf[byPos++]=chksum;
	StUsart1.byTxBuf[byPos]=ETX;
	
}

//---------------------------------------------------------------------
//----------------------------Main Processor---------------------------
//---------------------------------------------------------------------
void MainProcessor(void)
{
	unsigned char by;
	int ibuf,ibuf2; 	
	float fbuf;
	switch (PMode) {
		case 0:
			PMode=PMODE_NDISP;
			break;
		//------------------------------------------------------------
		//----------------------------START---------------------------
		//------------------------------------------------------------
		
		case PMODE_START:
			PSubMode=0;
			WatchdogStart();
			PMode++;
			break;
		case PMODE_START+1:
			if (EepromCheck()!=0) {
				e16printf(8,2, PUT_NORMAL, (char *)"Check data.");
				BySource=0;
				ByTarget=0;
				PMode++;	
			} else {
				e16printf(8,2, PUT_NORMAL, (char *)"Load CH data.");
				PMode+=3; //to Load Sensor Data
			}
			LcdDispRow(2,3); // Display
			ISystemCnt=0;
			break;
		case PMODE_START+2: //Ver0.93 Save Sensor Data
			FlagFlash=0;
			BySource=0;
			ByTarget=0;
			ISystemCnt=0;
			_EepromWriteByte(E_AUTO_RUN,1);		//default Auto run 
			PSubMode=PMode+3;
			PMode=PMODE_SAVE_ALL;	//SAVE ALL ����
			break;
		case PMODE_START+3:	//Ver0.93 Load Sensor Data
			DBufClearRows(2,3,0,127);		
			e16printf(8,2, PUT_NORMAL, (char *)"Load SS data.");
			LcdDispRow(2,3); // Display
			if (EepromLoadSensorBlock(ByTarget)==0) {	//�����̸� 
				if (ByTarget>=MAX_SENSOR) {
					ByTarget=0;
					ISystemCnt=0;
					PMode++;
				}
			} else {	//�����̸� 
				PSubMode=1;
				ByTarget=0;
				ISystemCnt=0;
				PMode+=3;
			}
			break;
		case PMODE_START+4:	//Ver0.93 Load Channel Data
			DBufClearRows(2,3, 0,127);
			e16printf(8,2, PUT_NORMAL, (char *)"Load CH data.");
			LcdDispRow(2,3); // Display
			if (EepromLoadChBlock(ByTarget)==0) {	//�����̸� 
				ByTarget++;
				if (ByTarget>=MAX_CHANNEL) {
					PSubMode=0;
					ByTarget=0;
					ISystemCnt=0;
					PMode++;
				}
			} else {
				PSubMode=1;
				ByTarget=0;
				ISystemCnt=0;
				PMode+=2;
			}
			break;

		case PMODE_START+5:	//Ver0.93 Load Channel Data
			if (EepromLoadCalRateBlock(ByTarget)==0) {	//�����̸� 
				ByTarget++;
				if (ByTarget>=MAX_CHANNEL) {
					ByChLast=EepromLoadLastCh();	//Ver0.99e
					ByChCur=FindActiveChannel(ByChLast&0x07);	//Ver0.99f	LastChannel �� ��Ȱ��ȭ�̸� ���ο� Channel��			
					PSubMode=0;
					ByTarget=0;
					ISystemCnt=0;
					PMode++;
				}
			} else {
				PSubMode=1;
				ByTarget=0;
				ISystemCnt=0;
				PMode++;
			}
			break;

		case PMODE_START+6:
			DBufClearRows(2,3, 0,127);
			if (PSubMode==0) {
				e16printf(8,2, PUT_NORMAL, (char *)"Good...");
			}	else  {
				e16printf(8,2, PUT_NORMAL, (char *)"Fail!!!");
			}
			LcdDispRow(2,3); // Display
			if (ISystemCnt>SYSTEM_1SEC) {
				if (_EepromReadByte(E_AUTO_RUN)==1) PMode+=2;	//default 0
					else PMode++;
				ByAdcOn=1;	//Pressure Read On
				PSubMode=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		case PMODE_START+7:
			//DBufClearRows(4,5, 0,127);
			e16printf(8,4, PUT_NORMAL, (char *)"PUSH ANY KEY");
			LcdDispRow(4,6);
			if (ByKey!=KEY_NO) {
				PMode++;	//ǥ�� ǥ�� ��� 
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		case PMODE_START+8:	
			PrsSetStepAll();	//ä�κ� ���� ũ�� Ȯ�� 
			if ((ByChLast & 0x08)==0x08) PMode=PMODE_RDISP;	//��ȯǥ�ø�� 
				else PMode=PMODE_NDISP;	//ǥ�� ǥ�� ���  
			ISystemCnt=0;
			ByKey=KEY_NO;
			break;
		//------------------------------------------------------------
		//-------------------------ǥ�� ���� ���---------------------
		//------------------------------------------------------------
		case PMODE_NDISP: 	//ǥ�� ���� ���
			DispMain(0x07, &StChannel[ByChCur]);
			PMode++;
			break;
		case PMODE_NDISP+1:	//����������  ByPrsStep���� ����
			ibuf=StSensor[StChannel[ByChCur].bySensor].iPrsMax-StSensor[StChannel[ByChCur].bySensor].iPrsMin;
			if (ibuf<0) ibuf=-ibuf;
			if (ibuf>5000 || StChannel[ByChCur].byUnit==UNIT_MPA ) ByPrsStep=10;
				else ByPrsStep=1;
			PMode++;
			break;

		case PMODE_NDISP+2:	//ǥ�� ���� ��� 
			if (StChannel[ByChCur].bySensor<MAX_SENSOR) {
				ByChOutEnable|=0x01<<ByChCur;
			} else {
				ByChOutEnable&=~(0x01<<ByChCur);
			} 
			if (FlagSystem & 0x02) {	//�з� ǥ�� 
				DispMain(0x02,&StChannel[ByChCur]);
				FlagSystem&=0xFD; 
			}
			FlagFlash=0;
			//-----ERROR DISPLAY START--------------------------
			if (FlagLowPrs&(1<<ByChCur)) {	//Ver1.02  Low Level�� "----"�� ǥ���� + ���� ó���� ����  
				//DisplaySetLine();
			}
			//Ver1.02 if (FlagError!=0 && IErrorTimeCnt>TIME_KEEP_ERROR) {
			if (IErrorTimeCnt>TIME_KEEP_ERROR) {
				if (FlagError==0x01 && FlagLowPrs==0) {  
					FlagError&=0xFE; //Ver0.99 �ڵ� ������ ���� Count
					IErrorTimeCnt=0;
				}
				if (FlagError==0x02 && FlagHighPrs==0) {  
					FlagError&=0xFD; //Ver0.99 �ڵ� ������ ���� Count
					IErrorTimeCnt=0;
				}
			}
			//Ver1.02 if (FlagError!=0 && Tm_mSec>SYSTEM_750M) {
#if !VTVM			
			if (FlagError!=0 && Tm_mSec==SYSTEM_750M) {	
				DispSetErrFlag();
				LcdDispRow(2,5);
			}
#endif
			//-----ERROR DISPLAY END--------------------------

			if (ByKey==KEY_UPDN) {	//��ȯǥ�� ����	
				ByChLast=ByChCur| 0x08;
				EepromSaveLastCh(ByChLast);	//Ver0.99 Last Channel Save
				ISystemCnt=0;
				TimeClear();
				PMode=PMODE_RDISP;	 
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_DN) {
				if (ByChCur<(MAX_CHANNEL-1)) ByChCur++;
					else ByChCur=0;
				DispMain(0x03,&StChannel[ByChCur]);
				TimeClear();
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode--;
			} else  if (ByKey==KEY_UP) {
				if (ByChCur>0) ByChCur--;
					else ByChCur=MAX_CHANNEL-1;
				DispMain(0x03,&StChannel[ByChCur]);
				TimeClear();
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode--;
			} else if (ByKey==KEY_EDIT) {
			
				CopyChannel(&StChannelBuf,&StChannel[ByChCur]);  
				TimeClear();
				if (FlagKey==0) {
					FlagKey=1;
					ByKey=KEY_NO;
					ISystemCnt=0;
					PMode=PMODE_CHECK;	// ���� Ȯ�� ���� 
				} else if (FlagKey& 0x04) { //Long Key
					ByKey=KEY_NO;
					ISystemCnt=0;
					PMode=PMODE_MENU;	// ���� Ȯ�� ���� 
				}
			}
			break;
		case PMODE_RDISP : 
			DispMain(1,&StChannel[ByChCur]);
			if (ISystemCnt>SYSTEM_1SEC) {
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode++;
			}
			break;
		case PMODE_RDISP+1 : 	//��ȯ ǥ�� ��� 
			ibuf=StSensor[StChannel[ByChCur].bySensor].iPrsMax-StSensor[StChannel[ByChCur].bySensor].iPrsMin;
			if (ibuf<0) ibuf=-ibuf;
			if (ibuf>5000 || StChannel[ByChCur].byUnit==UNIT_MPA ) ByPrsStep=10;
				else ByPrsStep=1;
			DispMain(3,&StChannel[ByChCur]);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_RDISP+2 : 	//��ȯ ǥ�� ��� 
			if (StChannel[ByChCur].bySensor<MAX_SENSOR) {
				ByChOutEnable|=0x01<<ByChCur;
			} else {
				ByChOutEnable&=~(0x01<<ByChCur);
			} 
			if (FlagSystem & 0x02) {
				DispMain(0x06,&StChannel[ByChCur]);
				FlagSystem&=0xFD; 
			}
			//DispMain(4,&StChannel[ByChCur]);
			//-----ERROR DISPLAY START--------------------------
			if (FlagLowPrs&(1<<ByChCur ) ) {	//Ver1.02  Low Level�� "----"�� ǥ���� + ���� ó���� ����  
				//DisplaySetLine();
			}
			if (IErrorTimeCnt>TIME_KEEP_ERROR) {
				if (FlagError==0x01 && FlagLowPrs==0) {  
					FlagError&=0xFE; //Ver0.99 �ڵ� ������ ���� Count
					IErrorTimeCnt=0;
				}
				if (FlagError==0x02 && FlagHighPrs==0) {  
					FlagError&=0xFD; //Ver0.99 �ڵ� ������ ���� Count
					IErrorTimeCnt=0;
				}
			}
#if !VTVM			
			if (FlagError!=0 && Tm_mSec==SYSTEM_750M) {
				DispSetErrFlag();
				LcdDispRow(2,5);
			}
#endif			
			//-----ERROR DISPLAY END--------------------------
			if (ISystemCnt>SYSTEM_2SEC) {
				by=0; //Ver1.00 ��� ������ NONE���� ������ ���� �ݺ� RESET ���� 
				do {
					ByChCur++;
					by++; 
					if (ByChCur>=MAX_CHANNEL) ByChCur=0;
					if (StChannel[ByChCur].bySensor<MAX_SENSOR) break;
					if (by>=8) break; //Ver1.00 ��� ������ NONE���� ������ ���� �ݺ� RESET ���� 
				}while(1);
				TimeClear();
				ISystemCnt=0;
				PMode--;
			}

			if (ByKey==KEY_UPDN) {
				ByChLast&=0xF7;
				EepromSaveLastCh(ByChLast);	//Ver0.99h Last Channel Save
				ByChCur=ByChLast;
				PMode++;	//ǥ�� ǥ�� ���� �����ϱ�  
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		case PMODE_RDISP+3: //Normal ���� ����
			if (ISystemCnt>SYSTEM_1SEC) {
				ByKey=KEY_NO;
				PMode=PMODE_NDISP;
				ISystemCnt=0;
			}
			break;
		//------------------------------------------------------------
		//-------------------------���� Ȯ�� ���---------------------
		//------------------------------------------------------------
		case PMODE_CHECK : //���� Ȯ�� ��� -  CHECK ǥ��
			ByEditMenuId=0;
			DispSetEditMain(ByEditMenuId, 0);
			LcdDispRow(0,7);
			PMode++;
			break;
		case PMODE_CHECK+1:
			//--------------------Error Clear---------------------
			FlagError=0;
			FlagLowPrs=0;
			FlagHighPrs=0;
			//--------------------Error Clear---------------------
			if (ByKey==KEY_EDIT && ((FlagKey&0x03)==0x02)) { //���� ������ Ű�̸� 
				if (ByEditMenuId<1) {
					ByEditMenuId=1;
					DispSetEditMain(ByEditMenuId, 0);
					LcdDispRow(2,7);
					ByKey=KEY_NO;
				} else if (ByEditMenuId<5) {
					ByEditMenuId=6;
					DispSetEditMain(ByEditMenuId, 0);
					LcdDispRow(2,7);
					ByKey=KEY_NO;
				} else {//Last Page
					PMode=PMODE_NDISP;	
					ISystemCnt=0;
					ByKey=KEY_NO;
				}	
			}
			if (ByKey==KEY_UP ) {
				ByEditMenuId++;
				if (ByEditMenuId > 7 ) {
					ByKey=KEY_NO;
					ISystemCnt=0;
					PMode=PMODE_NDISP;
					break;
				}	
				DispSetEditMain(ByEditMenuId, 0);
				LcdDispRow(0,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_DN) {
				if (ByEditMenuId>0) ByEditMenuId--;
				else ByEditMenuId=7;
				DispSetEditMain(ByEditMenuId, 0);
				LcdDispRow(0,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_10SEC, PMODE_NDISP);
			break;
		case PMODE_CHECK+2 : //���� Ȯ�� ��� -  Sensor ����
			if (ByKey==KEY_EDIT) {
				PMode=PMODE_NDISP;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				PMode=PMODE_CHECK;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_10SEC, PMODE_NDISP);
			break;

		case PMODE_CHECK+9 : //���� Ȯ�� ��� -  END
			PSubMode=1;	//END
			if (CheckEndMode(&PSubMode)==1) {
				PMode=PMODE_NDISP;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_1SEC, PMODE_NDISP);
			break;
		//------------------------------------------------------------
		//-------------------------�������: MAIN---------------------
		//------------------------------------------------------------
		case PMODE_MENU:	//���� ��� - EDIT/CAL/COPY/SEND/RCV
			PSubMode=EDIT_SET;
			DBufClearRows(0,1, 0, 127);
			DispSetMainMenu(PSubMode-1, 3);
			LcdDispRow(0, 1);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_MENU+1:
			FlagFlash=0x0F;
			if (ByKey==KEY_DN) {	//----- KEY DOWNó�� 
				if (PSubMode<EDIT_RETURN) PSubMode++;
					else PSubMode=EDIT_RETURN;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DBufClearRows(0,1, 0, 127);
				DispSetMainMenu(PSubMode-1, 3);
				LcdDispRow(0, 1);
			}
			if (ByKey==KEY_UP) {	//----- KEY UP ó�� 
				if (PSubMode>EDIT_SET) PSubMode--;
					else PSubMode=EDIT_SET;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DBufClearRows(0,1, 0, 127);
				DispSetMainMenu(PSubMode-1, 3);
				LcdDispRow(0, 1);
			}
			if (ByKey==KEY_EDIT) {
				if (PSubMode==EDIT_SET) {
					CopyChannel(&StChannelBuf,&StChannel[ByChCur]);  
					ByEditMenuId=0;
					PMode=PMODE_EDIT;
				} else if (PSubMode==EDIT_CAL) {
					PMode=PMODE_CALB;
					PSubMode=0;
					ByTarget=ByChCur;
				} else if (PSubMode==EDIT_CLR_CAL) {
					PMode=PMODE_CLR_CALB;
					PSubMode=0;
					ByTarget=ByChCur;
				} else if (PSubMode==EDIT_COPY) { //COPY Channel Mode
					PMode=PMODE_COPY;
					BySource=ByChCur;
					ByTarget=MAX_CHANNEL;
				} else {
					PMode=PMODE_NDISP;
				}
				ByScroll=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_5SEC, PMODE_NDISP);
			break;
		//------------------------------------------------------------
		//-------------------------�������: ����---------------------
		//------------------------------------------------------------
		case PMODE_EDIT:	//���� ��� - EDIT:Sensor
			DispSetEditMain(ByEditMenuId, 0);
			LcdDispRow(0,7);
			if (StChannelBuf.byUnit==UNIT_PSI) {
				IPrsMin=ChangeHpaTo10mPsi(StSensor[StChannelBuf.bySensor].iPrsMin);
				IPrsMax=ChangeHpaTo10mPsi(StSensor[StChannelBuf.bySensor].iPrsMax);
			} else {
				IPrsMin=StSensor[StChannelBuf.bySensor].iPrsMin;	
				IPrsMax=StSensor[StChannelBuf.bySensor].iPrsMax;	
			}
			PMode++;
			break;
		case PMODE_EDIT+1:
			//--------------------Error Clear---------------------
			FlagError=0;
			FlagLowPrs=0;
			FlagHighPrs=0;
			//--------------------Error Clear---------------------
			if (ByKey==KEY_EDIT && ((FlagKey&0x03)==0x02)) { //���� ������ Ű�̸� 
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode=PMode+ByEditMenuId+1;
			}
			if (ByKey==KEY_UP ) {
				ByEditMenuId++;
				if (ByEditMenuId > 8 ) ByEditMenuId=8;
				DispSetEditMain(ByEditMenuId, 0);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_DN) {
				if (ByEditMenuId>0) ByEditMenuId--;
				else ByEditMenuId=0;
				DispSetEditMain(ByEditMenuId, 0);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT && (FlagKey&KEY_LONG)) {
				PMode=PMODE_MENU;
				PSubMode=EDIT_SET;	//Channel EDIT Mode
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_10SEC, PMODE_NDISP);

			break;

		case PMODE_EDIT+2:	//���� ��� - EDIT:Sensor
			if (ByKey==KEY_UP) {	//----- KEY UPó�� 
				if (StChannelBuf.bySensor<MAX_SENSOR) StChannelBuf.bySensor++;
					else StChannelBuf.bySensor=0;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_DN) {	//----- KEY DOWN ó�� 
				FlagFlash=0x00;
				if (StChannelBuf.bySensor>0) StChannelBuf.bySensor--;
					else StChannelBuf.bySensor=MAX_SENSOR;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				PMode=PMODE_EDIT;	//Save YES/NO Confirm 
				PSubMode=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		
		case PMODE_EDIT+3:	//���� ��� - EDIT:UNIT
			if (ByKey==KEY_UP) {	//----- KEY UPó�� 
				FlagFlash=0x00;
				if (StChannelBuf.byUnit<UNIT_PSI) StChannelBuf.byUnit++;
					else StChannelBuf.byUnit=UNIT_MPA;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(4,5);
			}
			if (ByKey==KEY_DN) {	//----- KEY DOWN ó�� 
				FlagFlash=0x00;
				if (StChannelBuf.byUnit>UNIT_MPA) StChannelBuf.byUnit--;
					else StChannelBuf.byUnit=UNIT_PSI;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(4,5);
			}
			if (ByKey==KEY_EDIT) {
				ibuf=StSensor[StChannelBuf.bySensor].iPrsMax-StSensor[StChannelBuf.bySensor].iPrsMin;
				if (ibuf<0) ibuf=-ibuf;
				if (ibuf>5000 || StChannelBuf.byUnit==UNIT_MPA) ByPrsStep=10;
					else ByPrsStep=1;
				if (StChannelBuf.bySensor!=StChannel[ByChCur].bySensor) { //Sensor�� ����Ǿ����� TrgOn,off���� ���� 
					//Ver0.98 StChannelBuf.byUnit=UNIT_BAR;
					InitChannel(&StChannelBuf);
				} else { //������ ������ ���� ������ ����� ���
					if (StChannelBuf.byUnit==UNIT_PSI && StChannel[ByChCur].byUnit!=UNIT_PSI) {	//PSI->Oher Unit���� �����
						StChannelBuf.iPrsCur=ChangeHpaTo10mPsi(StChannelBuf.iPrsCur);	//Ver1.06
						StChannelBuf.iTrgOn=ChangeHpaTo10mPsi(StChannelBuf.iTrgOn);
						StChannelBuf.iTrgOff=ChangeHpaTo10mPsi(StChannelBuf.iTrgOff);
					} else if (StChannelBuf.byUnit!=UNIT_PSI && StChannel[ByChCur].byUnit==UNIT_PSI) {//Oher Unit->PSI���� �����
						StChannelBuf.iPrsCur=Change10mPsiToHpa(StChannelBuf.iPrsCur);	//Ver1.06
						StChannelBuf.iTrgOn=Change10mPsiToHpa(StChannelBuf.iTrgOn);
						StChannelBuf.iTrgOff=Change10mPsiToHpa(StChannelBuf.iTrgOff);
					}
				} 
				if (StChannelBuf.byUnit==UNIT_PSI) {
					IPrsMin=ChangeHpaTo10mPsi(StSensor[StChannelBuf.bySensor].iPrsMin);
					IPrsMax=ChangeHpaTo10mPsi(StSensor[StChannelBuf.bySensor].iPrsMax);
				} else {
					IPrsMin=StSensor[StChannelBuf.bySensor].iPrsMin;	
					IPrsMax=StSensor[StChannelBuf.bySensor].iPrsMax;	
				}
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode=PMODE_EDIT;
			}
			break;
			

		case PMODE_EDIT+4:	//���� ��� - EDIT:Trigger Type
			if (ByKey==KEY_DN) {	//----- KEY UPó�� 
				FlagFlash=0x00;
				if (StChannelBuf.byTrgType<1) StChannelBuf.byTrgType++;
					else StChannelBuf.byTrgType=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(6,7);
			}
			if (ByKey==KEY_UP) {	//----- KEY DOWN ó�� 
				FlagFlash=0x00;
				if (StChannelBuf.byTrgType>0) StChannelBuf.byTrgType--;
					else StChannelBuf.byTrgType=1;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(6,7);
			}
			if (ByKey==KEY_EDIT) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_EDIT;
			}
			break;

		case PMODE_EDIT+5:	//���� ��� - EDIT:Trigger On Pressure
			if (ByKey==KEY_UP) {	//----- KEY UPó�� 
				if (StSensor[StChannelBuf.bySensor].byNagative==0) { //������ �з�
					StChannelBuf.iTrgOn=PrsStepUp(StChannelBuf.iTrgOn,IPrsMax,ByPrsStep);
				} else {	//�ι��� �з� 	
					StChannelBuf.iTrgOn=PrsStepUp(StChannelBuf.iTrgOn,IPrsMin,ByPrsStep);
				}
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(2,3);
			}
			if (ByKey==KEY_DN) {	//----- KEY DOWN ó�� 
				if (StSensor[StChannelBuf.bySensor].byNagative==0) {	//������ �з�
					StChannelBuf.iTrgOn=PrsStepDown(StChannelBuf.iTrgOn,IPrsMin,ByPrsStep);
				} else {	//�ι��� �з� 	
					StChannelBuf.iTrgOn=PrsStepDown(StChannelBuf.iTrgOn,IPrsMax,ByPrsStep);
				}
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(2,3);
			}
			if (ByKey==KEY_EDIT) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_EDIT;
			}
			break;
		case PMODE_EDIT+6:	//���� ��� - EDIT:Trigger Off Pressure
			if (StSensor[StChannelBuf.bySensor].byNagative==0) {	//������ �з�
				if (StChannelBuf.iTrgOff<StChannelBuf.iTrgOn+50) 
					StChannelBuf.iTrgOff=StChannelBuf.iTrgOn+50; 
			} else {
				if (StChannelBuf.iTrgOff>StChannelBuf.iTrgOn-50) 
					StChannelBuf.iTrgOff=StChannelBuf.iTrgOn-50; 
			} 
			if (ByKey==KEY_UP) {	//----- KEY UPó�� 
				if (StSensor[StChannelBuf.bySensor].byNagative==0) { //������ �з�
					StChannelBuf.iTrgOff=PrsStepUp(StChannelBuf.iTrgOff,IPrsMax,ByPrsStep);
				} else {	//�ι��� �з� 	
					StChannelBuf.iTrgOff=PrsStepUp(StChannelBuf.iTrgOff,StChannelBuf.iTrgOn-ByPrsStep,ByPrsStep);
				}
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(4,5);
			}
			if (ByKey==KEY_DN) {	//----- KEY DOWN ó�� 
				if (StSensor[StChannelBuf.bySensor].byNagative==0) {	//������ �з�
					StChannelBuf.iTrgOff=PrsStepDown(StChannelBuf.iTrgOff,StChannelBuf.iTrgOn+ByPrsStep,ByPrsStep);
				} else {	//�ι��� �з� 	
					StChannelBuf.iTrgOff=PrsStepDown(StChannelBuf.iTrgOff,IPrsMax,ByPrsStep);
				}
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(4,5);

			}
			if (ByKey==KEY_EDIT) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_EDIT;
			}
			break;
		case PMODE_EDIT+7:	//���� ��� - EDIT:Hysterisis Pressure
			if (ByKey==KEY_UP) {	//----- KEY UPó�� 
				FlagFlash=0x00;
				if (StSensor[StChannelBuf.bySensor].byNagative==0) { //������ �з�
					StChannelBuf.iHyst=PrsStepUp(StChannelBuf.iHyst,IPrsMax/10,ByPrsStep);
				} else { 
					StChannelBuf.iHyst=PrsStepUp(StChannelBuf.iHyst,-IPrsMax/10,ByPrsStep);
				}
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(6,7);

			}
			if (ByKey==KEY_DN) {	//----- KEY DOWN ó�� 
				FlagFlash=0x00;
				StChannelBuf.iHyst=PrsStepDown(StChannelBuf.iHyst,0,ByPrsStep);
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(6,7);
			}
			if (ByKey==KEY_EDIT) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_EDIT;
			}
			break;
		case PMODE_EDIT+8:	//���� ��� - EDIT: AVG Time(Delay Time)
			if (ByKey==KEY_UP) {	//----- KEY UPó�� 
				FlagFlash=0x00;
				if (StChannelBuf.byDelayMode<PRS_AVG_1S) StChannelBuf.byDelayMode++;
					else StChannelBuf.byDelayMode=PRS_AVG_5mS;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(2,3);
			}
			if (ByKey==KEY_DN) {	//----- KEY DOWN ó�� 
				FlagFlash=0x00;
				if (StChannelBuf.byDelayMode>PRS_AVG_5mS) StChannelBuf.byDelayMode--;
					else StChannelBuf.byDelayMode=PRS_AVG_1S;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(2,3);
			}
			if (ByKey==KEY_EDIT) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_EDIT;
			}
			break;

		case PMODE_EDIT+9:	//���� ��� - EDIT:Switch Type
			if (ByKey==KEY_DN) {	//----- KEY UPó�� 
				FlagFlash=0x00;
				if (StChannelBuf.bySwType<SW_NOR_ON) StChannelBuf.bySwType++;
					else StChannelBuf.bySwType=SW_NOR_OFF;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(4,5);
			}
			if (ByKey==KEY_UP) {	//----- KEY DOWN ó�� 
				if (StChannelBuf.bySwType>SW_NOR_OFF) StChannelBuf.bySwType--;
					else StChannelBuf.bySwType=SW_NOR_ON;
				ISystemCnt=0;
				ByKey=KEY_NO;
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(4,5);
			}
			if (ByKey==KEY_EDIT) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_EDIT;
			}
			break;

		case PMODE_EDIT+10:	//���� ��� -  EDIT:Save Confirm
			if (ByKey==KEY_DN ||ByKey==KEY_UP ) {	//----- KEY UPó��
				ByRefBuf^=0x01;		//Toggle yes & no
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(6,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				if (ByRefBuf==0) {	//YES�̸�
					DBufClearRows(6,7,0,127);
					e16printf(0,6,PUT_REVERSE,(char *) " SAVING...");
					LcdDispRow(6,7);
					if (StChannelBuf.bySensor>=MAX_SENSOR) {
						IChKalmanCnt[ByChCur]=0;
						StChannelBuf.iPrsCur=0;
						StChannelBuf.byOutStatus=0;
					}
					CopyChannel(&StChannel[ByChCur], &StChannelBuf);
					ISystemCnt=0;
					ByKey=KEY_NO;
					BySource=ByChCur;
					PSubMode=PMode+1;
					PMode=PMODE_SAVE_CHANNEL_ONE; //SAVE Channel data to Eeprom
				} else {
					PSubMode=0;	//END MODE
					ISystemCnt=0;
					PMode=PMODE_NDISP;
					ByKey=KEY_NO;
				}
			}
			break;

		case PMODE_EDIT+11: //���� ��� - EDIT End
			if (ISystemCnt>SYSTEM_1SEC) {
				ByAdcOn=1;	//Pressure Read On
				ByPrsStepAry[ByChCur]=PrsSetStep(ByChCur);
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_NDISP;
				PSubMode=0;
			}	
			break;
			

		//------------------------------------------------------------
		//-------------------------�������: ����---------------------
		//------------------------------------------------------------
		case PMODE_COPY:	//���� ��� - COPY CHANNEL
			ByEditMenuId=0;
			DispSetCopyMain	(ByEditMenuId, 0);
			LcdDispRow(2,7);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_COPY+1:
			//--------------------Select Copy Item ---------------------
			if (ByKey==KEY_EDIT && ((FlagKey&0x03)==0x02)) { //���� ������ Ű�̸� 
				DispSetCopyMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode=PMode+ByEditMenuId+1;
			}
			if (ByKey==KEY_UP ) {
				ByEditMenuId++;
				if (ByEditMenuId > 2 ) ByEditMenuId=2;
				DispSetCopyMain(ByEditMenuId, 0);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_DN) {
				if (ByEditMenuId>0) ByEditMenuId--;
				else ByEditMenuId=0;
				DispSetCopyMain(ByEditMenuId, 0);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_10SEC, PMODE_NDISP);

			break;

		case PMODE_COPY+2:	//Select SOURCE CH 
			if (ByKey==KEY_UP) {	//MAX_CHANNEL�� ALL Cahnnel�� �ǹ��� 
				if (BySource<(MAX_CHANNEL-1)) BySource++;
				else BySource=0;
				DispSetCopyMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_DN) {
				if (BySource>0) BySource--;
					else BySource=MAX_CHANNEL-1;
				DispSetCopyMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				ByEditMenuId++;
				DispSetCopyMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode++;
			}
			break;
		case PMODE_COPY+3:	//Select TARGET CH 
			if (ByKey==KEY_UP) {	//MAX_CHANNEL�� ALL Cahnnel�� �ǹ��� 
				if (ByTarget<MAX_CHANNEL) ByTarget++;
					else ByTarget=0;
				DispSetCopyMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_DN) {
				if (ByTarget>0) ByTarget--;
				else ByTarget=MAX_CHANNEL;
				DispSetCopyMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				ByEditMenuId++;
				DispSetCopyMain(ByEditMenuId, 1);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode++;
			}
			break;
		case PMODE_COPY+4:	//���� ��� - COPY One CHANNEL
			if (ByKey==KEY_DN ||ByKey==KEY_UP ) {	//----- KEY UPó��
				ByRefBuf^=0x01;		//Toggle yes & no
				DispSetEditMain(ByEditMenuId, 1);
				LcdDispRow(6,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				if (ByRefBuf==0) {	//YES�̸�
					DBufClearRows(6,7,0,127);
					e16printf(0,6,PUT_REVERSE,(char *) " COPY...");
					LcdDispRow(6,7);
					if (ByTarget>=MAX_CHANNEL) {		//copy to All channel 
						PMode+=2;	
					} else {		//Copy to One Channel
						PMode++;
					}
					ISystemCnt=0;
					ByKey=KEY_NO;
				} else {
					PSubMode=0;	//END MODE
					ISystemCnt=0;
					PMode=PMODE_NDISP;
					ByKey=KEY_NO;
				}
			}
			break;
		case PMODE_COPY+5:	//Copy And Save One Channel Data 
			CopyChannel(&StChannel[ByTarget],&StChannel[BySource]);
			BySource=ByTarget;		//BySource(Svae��� CH��ȣ )��  Target CH ��ȣ�� ����  
			ByTarget=0;				//Save�� CH Data Byte��ȣ�� ��� 
			ISystemCnt=0;
			PSubMode=PMode+2;		//���� PMode
			PMode=PMODE_SAVE_CHANNEL_ONE;
			break;
		case PMODE_COPY+6:	//���� ��� - COPY ALL CHANNEL
			for (by=0;by<MAX_CHANNEL;by++) {
				if (by!=BySource) {	//Ver0.98 ByTarget�� by�� 
					CopyChannel(&StChannel[by],&StChannel[BySource]);
				}
			}
			BySource=0;
			ByTarget=0;
			PSubMode=PMode+1;
			ISystemCnt=0;
			PMode=PMODE_SAVE_CHANNEL_ALL;
			break;
		case PMODE_COPY+7:	//Ver0.93 Save Channel Data
			ByAdcOn=1;	//Pressure Read On
			PSubMode=1;
			PMode++;
			break;
		case PMODE_COPY+8:	//���� ��� - COPY ALL CHANNEL 
			//PSubMode=1;	//END
			if (CheckEndMode(&PSubMode)==1) {
				if (PSubMode==1) {
					PMode=PMODE_NDISP;
					PSubMode=0;
				} else { 
					PMode=PMODE_COPY;
				}
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_5SEC, PMODE_NDISP);
			break;


		//------------------------------------------------------------
		//-------------------------�������: ����---------------------
		//------------------------------------------------------------
		case PMODE_CALB:	//���� ��� - CAL: CHANNEL - YES/NO
			DBufClearRows(6,7,0,127);
			e16printf(0,6,PUT_NORMAL,(char *)"Calibrate ? ");
			ByRefBuf=0;
			DispSetSym(96, 6, PUT_REVERSE, SYM_YES+ByRefBuf);
			LcdDispRow(6,7);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_CALB+1:	//���� ��� - CAL: CHANNEL - YES/NO
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				ByRefBuf^=0x01;
				DispSetSym(96,6,PUT_REVERSE,SYM_YES+ByRefBuf);
				LcdDispRow(6,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				if (StChannelBuf.bySensor<MAX_SENSOR) {
					if (ByRefBuf==0) {	//YES
						PMode++;
						StChannelBuf.byDelayMode=StChannel[ByAdcChannel].byDelayMode; //Ver0.93
						StChannel[ByAdcChannel].byDelayMode=PRS_AVG_1S; //Ver0.93
					} else  {				//NO
						
						PMode=PMODE_MENU;
						PSubMode=EDIT_CAL;
					}
				} else {					//NO SENSOR
					PMode=PMODE_CALB+5;
					PSubMode=EDIT_CAL;
				}
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		case PMODE_CALB+2:	//���� ��� - CAL: CHANNEL
			StChannel[ByAdcChannel].byDelayMode=StChannelBuf.byDelayMode;
			DBufClearRows(6, 7, 0, 127);
			e16printf(0, 6, PUT_NORMAL, (char *)"Calibrate...");
			LcdDispRow(6, 7);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_CALB+3:	//���� ��� - //WAIT ADC READ FOR CAL
			if (ISystemCnt>SYSTEM_2SEC) {	//WAIT ADC READ 
				PMode++;
				ISystemCnt=0;
			}
			break;
		case PMODE_CALB+4:	//���� ��� - CAL:One CHANNEL
			if (StChannel[ByTarget].byUnit==UNIT_PSI) { //���� ������ ���� �ִ� ������ 5% ���� 
				ibuf=ChangeHpaTo10mPsi((StSensor[StChannel[ByTarget].bySensor].iPrsMax-StSensor[StChannel[ByTarget].bySensor].iPrsMin)/20);
			} else {
				ibuf=(StSensor[StChannel[ByTarget].bySensor].iPrsMax-StSensor[StChannel[ByTarget].bySensor].iPrsMin)/20;
			}
			if (ibuf<0) ibuf=-ibuf; //���� 
			ibuf2=StChannel[ByTarget].iPrsCur;
			if (ibuf2<0) ibuf2=-ibuf2;
			if (ibuf2<ibuf) { 
				StChannel[ByTarget].iOffset=StChannel[ByTarget].iPrsCur; //Ver0.93
				EepromSaveChOffset(ByTarget);
				PSubMode=1;
				ISystemCnt=0;
				PMode++;
			} else {
				PMode=PMODE_ERROR;
				PSubMode=1;
				ByScroll=0;
				ISystemCnt=0;
			}
			break;
		case PMODE_CALB+5:	//���� ��� - CAL: OK END or CONTINUE
			DBufClearRows(6, 7, 0, 127);
			e16printf(0, 6, PUT_NORMAL, (char *)"Calibrate OK");
			LcdDispRow(6, 7);
			ISystemCnt=0;
			PMode++;
			break;
			
		case PMODE_CALB+6:	//���� ��� - CAL: OK END or CONTINUE
			if (ByKey!=KEY_NO) {
				PMode=PMODE_NDISP;
				PSubMode=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_3SEC, PMODE_NDISP);
			break;
		//------------------------------------------------------------
		//-------------------------�������: �������-----------------
		//------------------------------------------------------------
		case PMODE_CLR_CALB:	//������� - EDIT_CLR_CAL YES/NO
			DBufClearRows(6,7,0,127);
			e16printf(0,6,PUT_NORMAL,(char *)"Clear Calib.?");
			ByRefBuf=0;
			DispSetSym(104, 6, PUT_REVERSE, SYM_YES+ByRefBuf);
			LcdDispRow(6,7);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_CLR_CALB+1:	//������� - EDIT_CLR_CAL YES/NO
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				ByRefBuf^=0x01;
				DispSetSym(104,6,PUT_REVERSE,SYM_YES+ByRefBuf);
				LcdDispRow(6,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				DBufClearRows(6,7,0,127);
				if (ByRefBuf==0) {	//YES
					e16printf(0,6,PUT_REVERSE,(char *)"OK - Push Anykey");
					StChannel[ByTarget].iOffset=0;
					EepromSaveChOffset(ByTarget);
					ISystemCnt=0;
					ByKey=KEY_NO;
				} else {	//NO
					e16printf(0,6,PUT_REVERSE,(char *)"Canceled Clear..");
					ISystemCnt=0;
					ByKey=KEY_NO;
				}
				LcdDispRow(6,7);
				ISystemCnt=0;
				PMode++;
				
			}
			break;

		case PMODE_CLR_CALB+2:	//FAC_CLR_CAL - END
			if (ByKey!=KEY_NO) {
				PMode=PMODE_NDISP;
				PSubMode=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			TimeOutCheck(SYSTEM_3SEC, PMODE_NDISP);
			break;


		//------------------------------------------------------------
		//-------------------------������:���� ---------------------
		//------------------------------------------------------------
		// enum {FAC_INIT, FAC_AUTO_RUN, FAC_CLR_CAL, FAC_CAL, FAC_SENSOR, FAC_REMOTE};
		case PMODE_FAC: //FACTORY MODE
			DBufClearRows(0,7,0,127l);
			e16printf(0,0,PUT_NORMAL,(char *)"FAC.MODE");
			e16printf(96,0,PUT_NORMAL,(char *)SW_VERSION);
			e16printf(16,2,PUT_NORMAL,(char *)"Loading DATA");
			LcdDispRow(0,4);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC+1:
			PSubMode=1;
			by=0x00;
			if (EepromCheck()==0) {
				if(EepromLoadAll()==0) 
					PSubMode=0;
			} 
			ISystemCnt=0;
			WatchdogStart();
			if (PSubMode==0) PMode++;
				else PMode+=2;
			ByScroll=0;
			break;
		case PMODE_FAC+2:
			if (ISystemCnt>SYSTEM_1SEC) {
				PMode++;
				ISystemCnt=0;
			}
			break;
		case PMODE_FAC+3:
			e16printf(16,6,PUT_REVERSE,(char *)"Push Anykey.");
			if (PSubMode==0) {
				e16printf(32,4,PUT_NORMAL,(char *)"GOOD...");
			} else 	{
				e16printf(32,4,PUT_NORMAL,(char *)"Need INIT");
			}
			LcdDispRow(4,7);
			ISystemCnt=0;
			ByKey=KEY_NO;
			PMode++;
			break;
		case PMODE_FAC+4:
			if (ByKey!=KEY_NO) {
				ByKey=KEY_NO;
				ByEditMenuId=0;
				PSubMode=0;
				ISystemCnt=0;
				PMode=PMODE_FAC_MENU;
			}
			break;



		//------------------------------------------------------------
		//-------------------------������: MAIN---------------------
		//------------------------------------------------------------
		case PMODE_FAC_MENU: //FACTORY MODE 104
			DispSetFacManu(ByEditMenuId);
			LcdDispRow(2,7); 
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_MENU+1: //FACTORY MODE 104
			if (ByKey==KEY_DN) {
				if (ByEditMenuId<FAC_REMOTE) ByEditMenuId++;
					else ByEditMenuId=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode--;
			} else if (ByKey==KEY_UP) {
				if (ByEditMenuId>0) ByEditMenuId--;
					else ByEditMenuId=FAC_REMOTE;
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode--;
			} else if (ByKey==KEY_EDIT) {
				if (ByEditMenuId==FAC_INIT) {	//FAC_INIT
					ByRefBuf=0;
					PMode=PMODE_FAC_INIT;
				} else if (ByEditMenuId==FAC_AUTO_RUN) {	//FAC_AUTO_RUN
					ByRefBuf=0;
					PMode=PMODE_FAC_ARUN;
				} else if (ByEditMenuId==FAC_CLR_CAL) {	//FAC_CLR_CAL
					ByRefBuf=0;
					PMode=PMODE_FAC_CLR_CAL;
				} else if (ByEditMenuId==FAC_CAL) {	//FAC_CAL
					ByRefBuf=0;
					PMode=PMODE_FAC_CAL;
				} else if (ByEditMenuId==FAC_SENSOR) {	//FAC_SENSOR
					ByTarget=0;
					ByRefBuf=0;
					PMode=PMODE_FAC_SENSOR;
				} else if (ByEditMenuId==FAC_SEND) {	//FAC_SEND
					ByRefBuf=0;
					PMode=PMODE_FAC_SEND;
				} else if (ByEditMenuId==FAC_RCV) {	//FAC_RCV
					ByRefBuf=0;
					PMode=PMODE_FAC_RCV;
				} else if (ByEditMenuId==FAC_REMOTE) {	//FAC_REMOTE
					PMode=PMODE_FAC_EXIT;
				}
				ByScroll=0;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		//------------------------------------------------------------
		//-------------------------������: �ʱ�ȭ ------------------
		//------------------------------------------------------------
		case PMODE_FAC_INIT:		//FAC_INIT
			DBufClearRows(2,7,0,127);
			e16printf(0,6,PUT_NORMAL,(char *)"Initailize? ");
			DispSetSym(96, 6, PUT_REVERSE, SYM_YES+ByRefBuf);
			LcdDispRow(6,7);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_INIT+1:		//FAC_INIT
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				ByRefBuf^=0x01;
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode--;
			} else if (ByKey==KEY_EDIT) {
				if (ByRefBuf==0) {	//YES
					Var_Init();	//PMode�� 0�̵� //Ver1.03 Calibration�ʱ�ȭ�� �Լ������� �и��Ͽ���. 
					PMode++;
					BySource=0;
					ByTarget=0;
				} else {
					PMode=PMODE_FAC_MENU;
				}
				FlagFlash=0x00;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;

		case PMODE_FAC_INIT+2:	//Ver0.93 Save Sensor Data 
			//DBufClearRows(6,7,0,127);
			e16printf(0, 6, PUT_NORMAL, (char *)"Initilizing.....");
			LcdDispRow(6,7);
			FlagFlash=0;
			BySource=0;
			ByTarget=0;
			_EepromWriteByte(E_AUTO_RUN,1);		//default Auto run 
			ISystemCnt=0;
			PSubMode=PMODE_FAC_INIT+3;
			PMode=PMODE_SAVE_ALL;	//SAVE ALL ����
			break;

		case PMODE_FAC_INIT+3: //FAC_INIT -  End
			e16printf(0, 6, PUT_NORMAL, (char *)"Initilizing...OK");
			LcdDispRow(6,7);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_INIT+4: //FAC_INIT -  End
			if (ByKey!=KEY_NO) {
				ByRefBuf=0;
				ByKey=KEY_NO;
				ByEditMenuId=0;
				PSubMode=0;
				ISystemCnt=0;
				PMode=PMODE_FAC_MENU;
			}
			break;

		//------------------------------------------------------------
		//-------------------------������:AUTO RUN------------------
		//------------------------------------------------------------
		case PMODE_FAC_ARUN:	//FAC_AUTO_RUN
			DBufClearRows(2,7,0,127);
			e16printf(0,6,PUT_NORMAL,(char *)"Auto-Run? ");
			DispSetSym(80, 6, PUT_REVERSE, SYM_YES+ByRefBuf);
			LcdDispRow(6,7);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_ARUN+1:	//FAC_AUTO_RUN
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				ByRefBuf^=0x01;
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode--;
			} else if (ByKey==KEY_EDIT) {
				DBufClearRows(6,7,0,127);
				if (ByRefBuf==0) {	//YES 
					e16printf(0,6,PUT_NORMAL,(char *)"Set AutoRun OK");
				} else {
					e16printf(0,6,PUT_NORMAL,(char *)"Canceled AutoRun");
				}
				LcdDispRow(6,7);
				//------------------------------------------
				ByRefBuf^=0x01;		// 1:AutoRun
				cli();
				_EepromWriteByte(E_AUTO_RUN,ByRefBuf);
				sei();
				//------------------------------------------
				FlagFlash=0x00;
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode++;
			}
			break;
		case PMODE_FAC_ARUN+2:	//FAC_AUTO_RUN - END
			if (ByKey!=KEY_NO || ISystemCnt>SYSTEM_3SEC) {
				ByEditMenuId=FAC_AUTO_RUN;
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_FAC_MENU;
			}
			break;


		//------------------------------------------------------------
		//-------------------------������:�������------------------
		//------------------------------------------------------------
		case PMODE_FAC_CLR_CAL:	//FAC_CLR_CAL
			DBufClearRows(2,7,0,127);
			e16printf(0,6,PUT_NORMAL,(char *)"Reset Calib.?");
			DispSetSym(104, 6, PUT_REVERSE, SYM_YES+ByRefBuf);
			LcdDispRow(6,7);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_CLR_CAL+1:		//FAC_CLR_CAL
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				ByRefBuf^=0x01;
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode--;
			} else if (ByKey==KEY_EDIT) {
				if (ByRefBuf==0) {	//YES
					DBufClearRows(6,7,0,127);
					e16printf(0,6,PUT_NORMAL,(char *)"Clear Calib...");
					LcdDispRow(6,7);
					//---------------------------------
					InitCalibration();	//Ver1.03 ��ƾ ���� 
					//---------------------------------
					ByTarget=0;
					PSubMode=PMode+1;
					PMode=PMODE_SAVE_CAL_RATE;
				} else {
					ByEditMenuId=FAC_CLR_CAL;
					PMode=PMODE_FAC_MENU;
				}
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;

		case PMODE_FAC_CLR_CAL+2:	//FAC_CLR_CAL - EEPROM Write
			DBufClearRows(6,7,0,127);
			e16printf(0,6,PUT_NORMAL,(char *)"Clear Calib. OK");
			LcdDispRow(6,7);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_CLR_CAL+3:	//FAC_CLR_CAL - END
			if (ByKey!=KEY_NO || ISystemCnt>SYSTEM_3SEC) {
				ByEditMenuId=FAC_CLR_CAL;
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_FAC_MENU;
			}
			break;


		//------------------------------------------------------------
		//-------------------------������:���� ---------------------
		//------------------------------------------------------------
		case PMODE_FAC_SENSOR:	//���� ��� - TX SEND 
			DBufClearRows(2,7,0,127);
			sprintf(ChBuf,"S%d",(int)(ByTarget+1));
			e16printf(0,2,PUT_REVERSE,ChBuf);
			e16printf(32,2,PUT_NORMAL,StSensor[ByTarget].cName);
			DispSetUnit(104,2, PUT_NORMAL,StSensor[ByTarget].byUnit);
			LcdDispRow(2,7);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_SENSOR+1:	//FAC_SENSOR - SENSOR
			if (ByKey==KEY_UP) {
				if (ByTarget<(MAX_SENSOR-1)) ByTarget++;
					else ByTarget=0;
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode--;
			}
			if (ByKey==KEY_DN) {
				if (ByTarget>0) ByTarget--;
					else ByTarget=(MAX_SENSOR-1);
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode--;
			}

			if (ByKey==KEY_EDIT) {
				CopySensor(&StSensorBuf,&StSensor[ByTarget]);
				//------Char Reverse---------
				ByLcdPosX=32;
				ByLcdPosY=2;
				DBufReverse_16(8);
				LcdDispRow(2,3);
				//--------------------------
				ByRefBuf=0;		//Digit No
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode++;
			}
			break;			
		case PMODE_FAC_SENSOR+2:	//FAC_SENSOR - Digit 1	
			by=StSensorBuf.cName[ByRefBuf];
			if (ByKey==KEY_UP) {
				FlagFlash=0x00;
				StSensorBuf.cName[ByRefBuf]=DigitUp(by);
				e16printf(32,2,PUT_NORMAL,StSensorBuf.cName);
				DBufReverse_16(8);
				LcdDispRow(2,3);
			}
			if (ByKey==KEY_DN) {
				FlagFlash=0x00;
				StSensorBuf.cName[ByRefBuf]=DigitDown(by);
				e16printf(32,2,PUT_NORMAL,StSensorBuf.cName);
				DBufReverse_16(8);
				LcdDispRow(2,3);
			}
			if (ByKey==KEY_EDIT) {
				if (FlagKey==0) {
					ByRefBuf++;
					if (ByRefBuf>3) ByRefBuf=0;
					//------Char Reverse---------
					DBufReverse_16(8);
					ByLcdPosX=(ByRefBuf*8)+32;
					DBufReverse_16(8);
					LcdDispRow(2,3);
					//--------------------------
					ISystemCnt=0;
					ByKey=KEY_NO;
				} else if (FlagKey& 0x04) { //Long Key
					ByKey=KEY_NO;
					ISystemCnt=0;
					PMode++;	// ���� Ȯ�� ���� 
				}
			}
			break;			
		case PMODE_FAC_SENSOR+3:	//FAC_SENSOR - Digit 2	
			for (by=0; by<4;by++) {
				if (StSensorBuf.cName[by]==' ') StSensorBuf.cName[by]=0;
			}	
			sprintf(ChBuf,"S%d",(int)(ByTarget+1));
			e16printf(0,2,PUT_REVERSE,ChBuf);
			e16printf(32,2,PUT_NORMAL,StSensor[ByTarget].cName);
			DispSetUnit(104,2, PUT_NORMAL,StSensor[ByTarget].byUnit);
			LcdDispRow(2,3);

			ISystemCnt=0;
			ByKey=KEY_NO;
			PMode++;
			break;			
		case PMODE_FAC_SENSOR+4:	//FAC_SENSOR - Digit 5	
			e16printf(0,4,PUT_NORMAL,(char *)"PRS MIN:" );
			DispPrsToStr(StSensorBuf.iPrsMin,StSensorBuf.byUnit,ChBuf);
			e16printf(64,4,PUT_NORMAL,ChBuf);
			LcdDispRow(4,5);
			ISystemCnt=0;
			ByKey=KEY_NO;
			PMode++;
			break;			
		case PMODE_FAC_SENSOR+5:	//FAC_SENSOR -SENSOR MIN
			if (ByKey==KEY_UP) {
				FlagFlash=0x00;
				if (StSensorBuf.iPrsMin>999) by=10;
					else by=1;
				StSensorBuf.iPrsMin=PrsStepUp(StSensorBuf.iPrsMin,19999,by);
				DBufClearRows(4,5,0,127);
				e16printf(0,4,PUT_NORMAL,(char *)"PRS MIN:" );
				DispPrsToStr(StSensorBuf.iPrsMin,StSensorBuf.byUnit,ChBuf);
				e16printf(64,4,PUT_NORMAL,ChBuf);
				LcdDispRow(4,5);
				
			}
			if (ByKey==KEY_DN) {
				FlagFlash=0x00;
				if (StSensorBuf.iPrsMin<=1000) by=1;
					else by=10;
				StSensorBuf.iPrsMin=PrsStepDown(StSensorBuf.iPrsMin,-1999,by);
				DBufClearRows(4,5,0,127);
				e16printf(0,4,PUT_NORMAL,(char *)"PRS MIN:" );
				DispPrsToStr(StSensorBuf.iPrsMin,StSensorBuf.byUnit,ChBuf);
				e16printf(64,4,PUT_NORMAL,ChBuf);
				LcdDispRow(4,5);
			}
/*
			if (ByKey==KEY_UP) {
				FlagFlash=0x00;
				StSensorBuf.iPrsMin=PrsUp(StSensorBuf.iPrsMin,9999);
			}
			if (ByKey==KEY_DN) {
				StSensorBuf.iPrsMin=PrsDown(StSensorBuf.iPrsMin,-9999);
			}
*/
			if (ByKey==KEY_EDIT) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_FAC_MENU;
			}
			break;

		case PMODE_FAC_SENSOR+8:	//FAC_SENSOR -SENSOR MAX
			DisplaySetPrs(StSensorBuf.iPrsMax,UNIT_BAR);
			DisplaySetChannel(17);	//Trigger ǥ�� 
			LedSetUnit(UNIT_BAR);
			FlagFlash=0x0F;
			if (ByKey==KEY_UP) {
				FlagFlash=0x00;
				if (StSensorBuf.iPrsMax>999) by=10;
					else by=1;
				StSensorBuf.iPrsMax=PrsStepUp(StSensorBuf.iPrsMax,19999,by);
			}
			if (ByKey==KEY_DN) {
				FlagFlash=0x00;
				if (StSensorBuf.iPrsMax<=1000) by=1;
					else by=10;
				StSensorBuf.iPrsMax=PrsStepDown(StSensorBuf.iPrsMax,-19999,by);
			}
			if (StSensorBuf.iPrsMax<StSensorBuf.iPrsMin) StSensorBuf.byNagative=1;
				else StSensorBuf.byNagative=0;
			if (ByKey==KEY_EDIT) {
				PMode++;
				PSubMode=1;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;

		case PMODE_FAC_SENSOR+9:	//FAC_SENSOR -SENSOR SAVE
			DisplaySetChannel('C');	// 
			LedSetUnit(UNIT_BAR);
			FlagFlash=0x0F;
			if (CheckYesMode(0,0,&PSubMode)==1) {  
				if (PSubMode==1) {	//YES�̸�
					DisplaySetStr(" RUN");
					CopySensor(&StSensor[BySource], &StSensorBuf);
					ByTarget=0;
					PSubMode=PMode+1;
					PMode=PMODE_SAVE_SENSOR_ONE;
					ISystemCnt=0;
					ByKey=KEY_NO;
				} else {
					PMode++;
					PSubMode=1;	//END MODE
					ISystemCnt=0;
					ByKey=KEY_NO;
				}
			}

			break;			


		case PMODE_FAC_SENSOR+10:	//FAC_SENSOR -SENSOR END
			PSubMode=1;	//END
			DisplaySetChannel('F');	//Channelǥ�� 
			FlagFlash=0x00;
			if (CheckEndMode(&PSubMode)==1) {
				if (PSubMode==1) {
					PMode=PMODE_FAC_MENU;
					PSubMode=FAC_SENSOR;
				} else PMode=PMODE_FAC_MENU;
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
			
		//------------------------------------------------------------
		//-------------------------������:��������------------------
		//------------------------------------------------------------
		//Sensor�� Channel Data�� ������.
		case PMODE_FAC_SEND:	//���� ��� - TX SEND 
			ByRefBuf=0;
			DBufClearRows(2,7,0,127);
			e16printf(0,2,PUT_NORMAL,(char *)"Send all data?");
			DispSetSym(112, 2, PUT_REVERSE, SYM_YES+ByRefBuf);
			LcdDispRow(2,7);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_SEND+1:	//���� ��� - TX SEND 
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				ByRefBuf^=0x01;
				ByKey=KEY_NO;
				DispSetSym(112, 2, PUT_REVERSE, SYM_YES+ByRefBuf);
				LcdDispRow(2,7);
			} else if (ByKey==KEY_EDIT) {
				if (ByRefBuf==0) {	//send yes
					Usart1_Init(M16_1152); 
					BySource=0;
					PMode++;
				} else {
					ByEditMenuId=FAC_SEND;
					PMode=PMODE_FAC_MENU;
				}
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		case PMODE_FAC_SEND+2:	//���� ��� - TX SEND SENSOR DATA
			sprintf(ChBuf,"SEND SS DATA:%d",(int)(BySource+1));
			e16printf(0,4,PUT_NORMAL,ChBuf);
			LcdDispRow(4,5);
			Usart1_SendSensorData(BySource);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_SEND+3: 	//���� ��� - TX SEND : WAIT ACK SIGNAL
			by=Usart1_RcvAck();
			if (by==0) {
				BySource++; 
				if (BySource<MAX_SENSOR) {
					PMode--;
				} else {
					PMode++;
					PSubMode=1;
					BySource=0;
				}
				ISystemCnt=0;
				break;
			} else if (by==-2) {
				PMode--;
			}
			if (ISystemCnt>SYSTEM_3SEC) {
				e16printf(0,6,PUT_NORMAL,(char *)"NG...Push AnyKey");
				LcdDispRow(6,7);
				FlagError=0x01;
				PMode=PMODE_FAC_SEND+6;	//TX ERROR
			}
			break;
		case PMODE_FAC_SEND+4:	//���� ��� - TX SEND 
			sprintf(ChBuf,"SEND CH DATA:%d",(int)(BySource+1));
			e16printf(0,4,PUT_NORMAL,ChBuf);
			LcdDispRow(4,5);
			Usart1_SendChData(BySource);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_SEND+5: 	//���� ��� - TX SEND : WAIT ACK SIGNAL
			by=Usart1_RcvAck();
			if (by==0) {
				BySource++; 
				if (BySource<MAX_CHANNEL) {
					PMode--;
				} else {
					e16printf(0,6,PUT_NORMAL,(char *)"OK...Push AnyKey");
					LcdDispRow(6,7);
					ByKey=KEY_NO;
					ISystemCnt=0;
					PMode++;
				}
				ISystemCnt=0;
				break;
			} else if (by==-2) {
				PMode--;
			}
			if (ISystemCnt>SYSTEM_5SEC) {
				e16printf(0,6,PUT_NORMAL,(char *)"NG...Push AnyKey");
				LcdDispRow(6,7);
				FlagError=0x01;
				PMode=PMODE_FAC_SEND+7;	//TX ERROR
			}
			break;
		case PMODE_FAC_SEND+6:	//���� ��� - TX SEND 
			if (ByKey!=KEY_NO) {
				Usart1_Init(M16_NON); 
				ByKey=KEY_NO;
				ISystemCnt=0;
				PSubMode=FAC_SEND;
				PMode=PMODE_FAC_MENU;
			}
			break;
		//------------------------------------------------------------
		//-------------------------������:��������------------------
		//------------------------------------------------------------
		case PMODE_FAC_RCV:	//���� ��� - RCV START 
			BySource=0;
			DBufClearRows(2,7,0,127);
			sprintf(ChBuf,"Get SS DATA:%d",(int)(BySource+1));
			e16printf(0,2,PUT_NORMAL,ChBuf);
			LcdDispRow(2,7);
			Usart1_Init(M16_1152); 
			ISystemCnt=0;
			PMode++;
			break;

		case PMODE_FAC_RCV+1:	//���� ��� - RCV SENSOR DATA 
			Usart1_RcvdDataToFrame();
			if (ByFrameSize==ROM_SENSOR_LENGTH+4) {
				PMode++;
			} else {
				if ((ByKey!=KEY_NO) || (ISystemCnt>SYSTEM_1MIN)){
					e16printf(0,6,PUT_NORMAL,(char *)"NG...Push AnyKey");
					LcdDispRow(6,7);
					FlagError=0x01;
					ByKey=KEY_NO;
					PMode=PMODE_FAC_RCV+7;
				}	
			}	
			break;
		case PMODE_FAC_RCV+2:	//���� ��� - RCV SENSOR DATA & WRITE TO EEPROM 
			by=DecodeSensorData(BySource,&ByRxFrame[3]);	//Ver0.93
			ByFrameSize=0;
			Delay_10us();			
			if (by==0) {	//���� ó���̸� 
				Usart1_WriteByte(ACK);
				BySource++;
				if (BySource>=MAX_SENSOR) {
					sprintf(ChBuf,"Get CH DATA:%d",(int)(BySource+1));
					e16printf(0,4,PUT_NORMAL,ChBuf);
					LcdDispRow(4,5);
					BySource=0;
					ByTarget=0;
					StUsart1.byRxBufPos=0;
					ISystemCnt=0;
					PMode++;
				} else {
					sprintf(ChBuf,"Get SS DATA:%d",(int)(BySource+1));
					e16printf(0,2,PUT_NORMAL,ChBuf);
					LcdDispRow(2,3);
					PMode--;
				}
				 
			} else {
				Usart1_WriteByte(NACK);
				PMode--;
			}
			break;
			
		case PMODE_FAC_RCV+3:	//���� ��� - RCV CHANNEL DATA  
			Usart1_RcvdDataToFrame();
			if (ByFrameSize==ROM_CHANNEL_LENGTH+4) {
				PMode++;
			} else {
				if ((ByKey==KEY_EDIT) || (ISystemCnt>SYSTEM_10SEC)) {
					e16printf(0,6,PUT_NORMAL,(char *)"NG...Push AnyKey");
					LcdDispRow(6,7);
					FlagError=0x01;
					PMode=PMODE_FAC_RCV+7;
				}	
			}	
			break;
		case PMODE_FAC_RCV+4:	//���� ��� - RX CHANNEL ACK SEND 
			by=DecodeChData(BySource,&ByRxFrame[3]); //Ver0.93
			ByFrameSize=0;
			Delay_10us();			
//Ver0.93	by=RxChFrameProcess();
			if (by==0) {	//���� ó���̸� 
				Usart1_WriteByte(ACK);
				BySource++;
				if (BySource>=MAX_CHANNEL) {
					PMode++;
					BySource=0;
					ISystemCnt=0;
				} else {
					sprintf(ChBuf,"Get SS DATA:%d",(int)(BySource+1));
					e16printf(0,4,PUT_NORMAL,ChBuf);
					LcdDispRow(4,5);
					PMode--;
				}
				 
			} else {
				Usart1_WriteByte(NACK);
				PMode--;
			}
			break;

		case PMODE_FAC_RCV+5:	//Ver0.93 Save Sensor Data 
			e16printf(0,4,PUT_NORMAL,(char *)"Save rcvd data" );
			FlagFlash=0;
			BySource=0;
			ByTarget=0;
			ISystemCnt=0;
			PSubMode=PMode+1;
			PMode=PMODE_SAVE_ALL;	//SAVE ALL ����
			break;
		case PMODE_FAC_RCV+6:	//���� ��� - RX OK Display
			e16printf(0,6,PUT_NORMAL,(char *)"OK...Push AnyKey");
			LcdDispRow(6,7);
			ISystemCnt=0;
			PSubMode=0;
			PMode++;	
			break;
		case PMODE_FAC_RCV+7:	//���� ��� - RX END
			if (ByKey==KEY_EDIT) {
				PSubMode=FAC_RCV;
				Usart1_Init(M16_NON); 
				ByKey=KEY_NO;
				ISystemCnt=0;
				PMode=PMODE_FAC_MENU;
			}
			break;

		//------------------------------------------------------------
		//-------------------------������:���� ---------------------
		//------------------------------------------------------------
		case PMODE_FAC_CAL:	//FAC_CLR_CAL
			DBufClearRows(2,7,0,127);
			e16printf(0,2,PUT_NORMAL,(char *)"Calb. at4.1V?");
			DispSetSym(112, 2, PUT_REVERSE, SYM_YES+ByRefBuf);
			LcdDispRow(2,7);
			ByErrorCnt=0;
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_CAL+1:	//FAC_CAL-���� ������ REF 4.1V INPUT
			//--------Calibration Ȯ��-----------------------
			if (ByKey==KEY_UP || ByKey==KEY_DN) {
				ByRefBuf^=0x01;
				DispSetSym(112, 2, PUT_REVERSE, SYM_YES+ByRefBuf);
				LcdDispRow(2,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				if (ByRefBuf==0) {//Yes
					//-----��� æ�� ���簪 ���� �ʱ�ȭ - �Ϸ��� �����̸� ����ϰ� �ٽ� EEPROM���� ������ ������
					for (by=0;by<MAX_CHANNEL;by++) {	//��ä�� Calb�� �ʱ�ȭ �� ��� 
						//----Backup	
						StCalBackup[by].bySensor=StChannel[by].bySensor;
						StCalBackup[by].uniAdcCalRate.f=StChannel[by].uniAdcCalRate.f;
						StCalBackup[by].iAdcOffset=StChannel[by].iAdcOffset;
						//-----������ ���� �ʱ�ȭ 
						StChannel[by].bySensor=SENSOR_P3;
						StChannel[by].uniAdcCalRate.f=1.00;
						StChannel[by].iAdcOffset=0;
						StChannel[by].iOffset=0;
					} 
					ByTarget=0;
					ByAdcOn=1; //--------------ADC ON
					PMode++;
					DBufClearRows(4,5,0,127);
					DispSetStrAndNum(0, 4, (char *)"CH:",ByTarget+1);
					LcdDispRow(4,5);
				}else {
					ByEditMenuId=FAC_CAL;
					PMode=PMODE_FAC_MENU;

				}
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			break;
		case PMODE_FAC_CAL+2:
			//-------ByTarget Channel Calibrate at 4.1 V ---------------------
			if (ISystemCnt>SYSTEM_750M) {	
				fbuf=(float)StChannel[ByTarget].iAdc;	
				fbuf=ADC4_REF_4R1V/fbuf;
				if (fbuf>0.98 && fbuf <1.02) { // 2%�̳��̸�
					e16printf(40,4,PUT_NORMAL,(char *)"PASS:");
					StChannel[ByTarget].uniAdcCalRate.f=fbuf;
				} else {
					ByErrorCnt++;
					e16printf(40,4,PUT_NORMAL,(char *)"FAIL:");
					StChannel[ByTarget].uniAdcCalRate.f=StCalBackup[ByTarget].uniAdcCalRate.f; //Ver1.04
				}
				fbuf=fbuf-1;
				fbuf*=1000;
				ibuf=(int)fbuf;
				itoa(ibuf,ChBuf,10);
				e16printf(80,4,PUT_NORMAL,ChBuf);
				LcdDispRow(4,5);
				ISystemCnt=0;
				PMode++;
			}
			break;
		case PMODE_FAC_CAL+3:
			//-------Next  Channel Calibrate at 4.1 V ---------------------
			
//			if (ByKey==KEY_EDIT) {
				ByTarget++;
				if (ByTarget>=MAX_CHANNEL) {
					ByTarget=0;
					DBufClearRows(2,7,0,127);
					e16printf(0,2,PUT_NORMAL,(char *)"Calb. at1.0V");
					DispSetStrAndNum(0, 4, (char *)"CH:",ByTarget+1);
					LcdDispRow(2,5);
					PMode++;	 
				} else {
					DBufClearRows(4,5,0,127);
					DispSetStrAndNum(0, 4, (char *)"CH:",ByTarget+1);
					LcdDispRow(4,5);
					PMode--;
				}
				ISystemCnt=0;
				ByKey=KEY_NO;
//			}
			break;
		case PMODE_FAC_CAL+4:
			if (ISystemCnt>SYSTEM_750M) {	
				fbuf=(float)StChannel[ByTarget].iAdc*StChannel[ByTarget].uniAdcCalRate.f;
				fbuf=fbuf-ADC4_REF_1R0V+0.5;
				ibuf=(int)fbuf;
				StChannel[ByTarget].bySensor=StCalBackup[ByTarget].bySensor; //Ver1.04 Sensor����
				if (ibuf>-20 && ibuf <20 ) { // 20/1024=2%�̳��̸�
					e16printf(40,4,PUT_NORMAL,(char *)"PASS:");
					StChannel[ByTarget].iAdcOffset=ibuf;
				} else {
					ByErrorCnt++;
					e16printf(40,4,PUT_NORMAL,(char *)"FAIL:");
					StChannel[ByTarget].iAdcOffset=StCalBackup[ByTarget].iAdcOffset; //Ver1.04
				}
				/*
				fbuf=fbuf-1;
				fbuf*=1000;
				ibuf=(int)fbuf;
				*/
				itoa(ibuf,ChBuf,10);
				e16printf(80,4,PUT_NORMAL,ChBuf);
				LcdDispRow(4,5);
				ISystemCnt=0;
				PMode++;
			}
			break;
		case PMODE_FAC_CAL+5:	//FAC_CAL - ADC OffSet ������ REF 1.0V INPUT
			//-------ByTarget Channel Calibrate at 4.1 V ---------------------
			if (ByTarget>=MAX_CHANNEL-1) {
				DBufClearRows(2,7,0,127);
				e16printf(0,2,PUT_NORMAL,(char *)"Finished Calib..");
				LcdDispRow(2,3);
				if (ByErrorCnt==0) {
					PMode+=2;
				}	else {
					ByRefBuf=1;
					itoa((int)ByErrorCnt,ChBuf,10);
					e16printf(0,4,PUT_NORMAL,(char *)"Calib. FAIL:");
					e16printf(96,4,PUT_NORMAL,ChBuf);
					e16printf(0,6,PUT_NORMAL,(char *)"Save Result?");
					DispSetSym(112, 6, PUT_REVERSE, SYM_YES+ByRefBuf);
					LcdDispRow(4,7);
					ByRefBuf=1;
					PMode++;
				}
				ByKey=KEY_NO;
				ISystemCnt=0;
			} else {
//				if (ByKey==KEY_EDIT) {
					ByTarget++;
					DBufClearRows(4,5,0,127);
					DispSetStrAndNum(0, 4, (char *)"CH:",ByTarget+1);
					LcdDispRow(4,5);
					PMode--;
					ISystemCnt=0;
					ByKey=KEY_NO;
//				}
			}	
			break;
		case PMODE_FAC_CAL+6:	//FAIL�� ������ ���� ���� Ȯ�� 
			if (ByKey==KEY_DN ||ByKey==KEY_UP ) {	//----- KEY UPó��
				ByRefBuf^=0x01;		//Toggle yes & no
				DispSetSym(112, 6, PUT_REVERSE, SYM_YES+ByRefBuf);
				LcdDispRow(6,7);
				ISystemCnt=0;
				ByKey=KEY_NO;
			}
			if (ByKey==KEY_EDIT) {
				if (ByRefBuf==0) {	//Save Yes 
					ByKey=KEY_NO;
					ISystemCnt=0;
					PMode++;
				} else {				//Cancel Save and return to Factory menu. 
					ByKey=KEY_NO;
					ISystemCnt=0;
					PSubMode=FAC_CAL;
					PMode=PMODE_FAC_MENU;
				}
			}	
			break;
		case PMODE_FAC_CAL+7:	//FAC_CAL_SAVE - EEPROM Write Start
			DBufClearRows(6,7,0,127);
			e16printf(0,6,PUT_NORMAL,(char *)"Please, Wait...");
			LcdDispRow(6,7);
			ByTarget=0;
			PSubMode=PMode+1;
			PMode=PMODE_SAVE_CAL_RATE;
			break;
		case PMODE_FAC_CAL+8:	//FAC_CAL_SAVE - EEPROM Write End 
			e16printf(0,4,PUT_NORMAL,(char *)"Complete save.  ");
			e16printf(0,6,PUT_REVERSE,(char *)"  Push AnyKey   ");
			LcdDispRow(4,7);
			ByKey=KEY_NO;
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_FAC_CAL+9:	//FAC_CAL_SAVE - EEPROM Write
			if (ByKey!=KEY_NO) {
				ByKey=KEY_NO;
				ISystemCnt=0;
				PSubMode=FAC_CAL;
				PMode=PMODE_FAC_MENU;
			}
			break;
		//------------------------------------------------------------
		//-------------------------������:���� ---------------------
		//------------------------------------------------------------
		case PMODE_FAC_EXIT:
			FlagFlash=0;
			ISystemCnt=0;
			ByKey=KEY_NO;
			PMode=PMODE_START;
			break;			

		//------------------------------------------------------------
		//-------------------------�����Լ�:SAVE ALL------------------
		//------------------------------------------------------------
		case PMODE_SAVE_SENSOR_ONE:	//Ver0.93 Save Sensor Data
			ByAdcOn=0;	//Pressure Read Disable 
			ByTarget=EepromRealSaveSensorBlock(BySource,ByTarget);
			if (ByTarget>=ROM_SENSOR_LENGTH) {
				PMode=PSubMode;
				PSubMode=0;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
			}
			break;

		case PMODE_SAVE_CHANNEL_ONE:	//Ver0.93 Channel Data Save
			ByAdcOn=0;	//Pressure Read Disable 
			ByTarget=EepromRealSaveChBlock(BySource,ByTarget);
			if (ByTarget>=ROM_CHANNEL_LENGTH) {
				PMode=PSubMode;
				PSubMode=0;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
//				ByAdcOn=1;	//Pressure Read On
			}
			break;

		case PMODE_SAVE_SENSOR_ALL:	//Ver0.93 Save Sensor Data
			ByAdcOn=0;	//Pressure Read Disable 
			ByTarget=EepromRealSaveSensorBlock(BySource,ByTarget);
			if (ByTarget>=ROM_SENSOR_LENGTH) {
				BySource++;
				ByTarget=0;
			}
			if (BySource>=MAX_SENSOR) {
				PMode=PSubMode;
				PSubMode=0;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
//				ByAdcOn=1;	//Pressure Read On
			}
			break;

		case PMODE_SAVE_CHANNEL_ALL:	//Ver0.93 Channel Data Save
			ByAdcOn=0;	//Pressure Read Disable 
			ByTarget=EepromRealSaveChBlock(BySource,ByTarget);
			if (ByTarget>=ROM_CHANNEL_LENGTH) {
				BySource++;
				ByTarget=0;
			}
			if (BySource>=MAX_CHANNEL) {
				PMode=PSubMode;
				PSubMode=0;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
//				ByAdcOn=1;	//Pressure Read On
			}
			break;

		case PMODE_SAVE_ALL:	//Ver0.93 Save Sensor Data
			ByAdcOn=0;	//Pressure Read Disable 
			ByTarget=EepromRealSaveSensorBlock(BySource,ByTarget);
			if (ByTarget>=ROM_SENSOR_LENGTH) {
				BySource++;
				ByTarget=0;
			}
			if (BySource>=MAX_SENSOR) {
				PMode++;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
			}
			break;
		case PMODE_SAVE_ALL+1:	//Ver0.93 Channel Data Save
			ByTarget=EepromRealSaveChBlock(BySource,ByTarget);
			if (ByTarget>=ROM_CHANNEL_LENGTH) {
				BySource++;
				ByTarget=0;
			}
			if (BySource>=MAX_CHANNEL) {
				PMode++;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
			}
			break;
		case PMODE_SAVE_ALL+2:
			cli();
			if (_EepromRealWriteByte(0,0x5A)==0) {
				PMode=PSubMode;	//Return Previous Step
				PSubMode=0;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
			} 
			if (ISystemCnt>SYSTEM_1SEC) {
				PMode=PMODE_ERROR;	//Return Previous Step
				PSubMode=1;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
			}
//			ByAdcOn=1;	//Pressure Read On
			sei();
			break;

		case PMODE_SAVE_CAL_RATE:	//Ver0.99f Save Cal. Rate
			ByAdcOn=0;	//Pressure Read Disable 
			ByTarget=EepromRealSaveCalRateAll(ByTarget);
			//if (ByTarget>=(MAX_CHANNEL*6)) {
			if (ByTarget>=48) {	//Ver1.05 CAL Block Size�� 6���� ����
				PMode=PSubMode;
				PSubMode=0;
				BySource=0;
				ByTarget=0;
				ISystemCnt=0;
//				ByAdcOn=1;	//Pressure Read Enable
			}
			break;


		case PMODE_ERROR:
			DBufClearRows(6, 7, 0, 127);
			e16printf(0, 6, PUT_REVERSE, (char *)"FAIL-Push anykey");
			LcdDispRow(6, 7);
			ISystemCnt=0;
			PMode++;
			break;
		case PMODE_ERROR+1:
			if (ByKey!=KEY_NO) {
				ISystemCnt=0;
				ByKey=KEY_NO;
				PMode=PMODE_NDISP;	//ǥ�� ǥ�� ���  
			}
			TimeOutCheck(SYSTEM_10SEC, PMODE_NDISP);
			break;
		default:
			break;
	}
	
}

int CalDelayCnt(unsigned char byMode,unsigned char byValidChCnt)
{
	int irtn=1;
	int ichcnt=(int)byValidChCnt;
#if 0
	if (byMode==PRS_AVG_5mS) irtn=1;
	else if (byMode==PRS_AVG_50mS) irtn=8;
	else if (byMode==PRS_AVG_100mS) irtn=17;
	else if (byMode==PRS_AVG_250mS) irtn=34;
	else if (byMode==PRS_AVG_500mS) irtn=83;
	else if (byMode==PRS_AVG_750mS) irtn=117;
	else if (byMode==PRS_AVG_1S) irtn=167;
	else irtn=17;
#else
	//Ver1.03
	if (byMode==PRS_AVG_5mS) irtn=4;
	else if (byMode==PRS_AVG_50mS) irtn=40;
	else if (byMode==PRS_AVG_100mS) irtn=80;
	else if (byMode==PRS_AVG_250mS) irtn=200;
	else if (byMode==PRS_AVG_500mS) irtn=400;
	else if (byMode==PRS_AVG_750mS) irtn=600;
	else if (byMode==PRS_AVG_1S) irtn=800;
	else irtn=4;
	irtn/=ichcnt;
	if (irtn<1) irtn=1;
#endif
	return irtn;
}

unsigned int ReadADC(unsigned char byPort)
{
	return 0;
}

void SpiderSendData(void)
{
	unsigned char by,bySum;
	BySpiderSeq++;
	if (BySpiderSeq>39) BySpiderSeq=0;
	by=BySpiderSeq/4;
	//Channel�� �� Ȱ��ȭ �Ǿ� �ְų� Spiderä�θ���ũ�� ��Ȱ��ȭ�̸� return  
	if (by>7) return;
	if (StChannel[by].bySensor>=MAX_SENSOR || ((0x01<<by)&BySpiderChMask)==0) {
		return;
	}	
	if ((BySpiderSeq%4)==0) {
		StUsart1.byTxBuf[0]=STX;
		StUsart1.byTxBuf[1]=0x09;	//Length
		StUsart1.byTxBuf[2]=0x01;	//CMD
		StUsart1.byTxBuf[3]=by+1;	//b7:ByChOutData : b3~0:Channel ID
		StUsart1.byTxBuf[4]=StChannel[by].byUnit;
		if (((0x01<<by)&ByChOutData)!=0) StUsart1.byTxBuf[4]|=0x80;
		StUsart1.byTxBuf[5]=SpiderPrs[by][0];
		StUsart1.byTxBuf[6]=SpiderPrs[by][1];
		StUsart1.byTxBuf[7]=SpiderPrs[by][2];
		StUsart1.byTxBuf[8]=SpiderPrs[by][3];
		StUsart1.byTxBuf[9]=SpiderPrs[by][4];
		StUsart1.byTxBuf[10]=SpiderPrs[by][5];
		bySum=0;	//CheckSum
		for (by=0;by<11;by++)
			bySum+=StUsart1.byTxBuf[by];
		StUsart1.byTxBuf[11]=bySum;
		StUsart1.byTxBuf[12]=ETX;
		Usart1_WriteData(StUsart1.byTxBuf,13);
	}
}

char SpiderSendSingleData(unsigned char byRealCh)
{	//Ver1.6 Spider One Request One Sending ������� ���� 
	unsigned char by,bych=byRealCh;
	unsigned char bySum;
	unsigned char byCnt=3;
	//Channel�� �� Ȱ��ȭ �Ǿ� �ְų� Spiderä�θ���ũ�� ��Ȱ��ȭ�̸� return  
	if (bych>8) return -1;	//Ver1.7 ID 0 �߰� 
	if (bych==0){
		StUsart1.byTxBuf[0]=STX;
		StUsart1.byTxBuf[1]=1;	//Length
		StUsart1.byTxBuf[2]=0x01;	//CMD
		for (bych=0;bych<8;bych++) {
			if (StChannel[bych].bySensor<MAX_SENSOR) {	//��Ȱ�� Channel 
				StUsart1.byTxBuf[1]+=8;	//Length
				StUsart1.byTxBuf[byCnt++]=bych+1;	//b7:ByChOutData : b3~0:Channel ID
				StUsart1.byTxBuf[byCnt]=StChannel[bych].byUnit;
				if (((0x01<<bych)&ByChOutData)!=0) StUsart1.byTxBuf[byCnt]|=0x80;
				byCnt++;
				StUsart1.byTxBuf[byCnt++]=SpiderPrs[bych][0];
				StUsart1.byTxBuf[byCnt++]=SpiderPrs[bych][1];
				StUsart1.byTxBuf[byCnt++]=SpiderPrs[bych][2];
				StUsart1.byTxBuf[byCnt++]=SpiderPrs[bych][3];
				StUsart1.byTxBuf[byCnt++]=SpiderPrs[bych][4];
				StUsart1.byTxBuf[byCnt++]=SpiderPrs[bych][5];
			}
		}	
		bySum=0;	//CheckSum
		for (by=0;by<byCnt;by++)
			bySum+=StUsart1.byTxBuf[by];
		StUsart1.byTxBuf[byCnt++]=bySum;
		StUsart1.byTxBuf[byCnt++]=ETX;
		RxBufClear();
		Usart1_WriteDataByInt(StUsart1.byTxBuf,byCnt);
	}
	else {	//single channel 
	 	bych--;
		if (StChannel[bych].bySensor<MAX_SENSOR) {	//��Ȱ�� Channel 
			StUsart1.byTxBuf[0]=STX;
			StUsart1.byTxBuf[1]=0x09;	//Length
			StUsart1.byTxBuf[2]=0x01;	//CMD
			StUsart1.byTxBuf[3]=bych+1;	//b7:ByChOutData : b3~0:Channel ID
			StUsart1.byTxBuf[4]=StChannel[bych].byUnit;
			if (((0x01<<bych)&ByChOutData)!=0) StUsart1.byTxBuf[4]|=0x80;
			StUsart1.byTxBuf[5]=SpiderPrs[bych][0];
			StUsart1.byTxBuf[6]=SpiderPrs[bych][1];
			StUsart1.byTxBuf[7]=SpiderPrs[bych][2];
			StUsart1.byTxBuf[8]=SpiderPrs[bych][3];
			StUsart1.byTxBuf[9]=SpiderPrs[bych][4];
			StUsart1.byTxBuf[10]=SpiderPrs[bych][5];
			bySum=0;	//CheckSum
			for (by=0;by<11;by++)
				bySum+=StUsart1.byTxBuf[by];
			StUsart1.byTxBuf[11]=bySum;
			StUsart1.byTxBuf[12]=ETX;
			RxBufClear();
			Usart1_WriteDataByInt(StUsart1.byTxBuf,13);
		} 
		else {
			RxBufClear();
			Usart1_WriteByte(NACK);
		}	
	}
	return 0;
}


int main(void)
{
	char cSeq=0;
	int iMaxKalmanCnt;
	int idelta;
	unsigned char by,byOut;

	for (by=0;by<MAX_CHANNEL;by++) {
		IAdcValue[by]=0;
		IChKalmanCnt[by]=0;
	}
	Port_Init();
	Var_Init();		//PMode=0
	InitCalibration(); //������ �ʱ�ȭ 

	//-----��ǰ ���� End 
#if !DEBUG
	StUsart1.byTxBuf[0]=_EepromReadByte(1);
	StUsart1.byTxBuf[1]=_EepromReadByte(2);
	StUsart1.byTxBuf[2]=_EepromReadByte(3);
	if (StUsart1.byTxBuf[0]!='T' || StUsart1.byTxBuf[1]!='N' || StUsart1.byTxBuf[2]!='H') {
		while(1){
			;
		}
	}
#endif
	//-----��ǰ ���� End

	//if (EepromCheck()==0) EepromLoadAll();
	ACSR=0x80;
	cSeq=0;
	Timer1_Init(TIMER_2r5mS);	//Time
	FlagSystem|=0x01;
	sei();
	//DisplaySetStop();
	ByAdcChannel=0;
	AdcSetChannel(ByAdcChannel);
	FlagFlash=0x00;
	ByAdcOn=0;		//ADC ���� �㰡	
	ByChOutEnable=0x00; // All output port Disable

	LcdInit();
	DBufClearAll();
	e16printf(8,2, PUT_NORMAL, (char *)"Initialize");
	LcdDispRow(0,7); // All Display


	if ((PINA&0x80)==0) {
		PMode=PMODE_FAC;
	} else {
		PMode=PMODE_START;
		#if Eagle_EYE_ACTIVE 	//Ver1.20
		UartOpen();
		#endif
	}

	//PMode=PMODE_START;
	FlagActCh=CheckActiveCh();

	while (1) {

#if SPIDER_ACTIVE	//Ver1.50
		if ( PMode>20 && PMode<40)  Spider_RcvdDataToFrame();	//Ver1.50
#endif
#if SPIDER_SINGLE_ACTIVE	//Ver1.50
		if ( PMode>20 && PMode<40)  Spider_RcvdDataToFrame();	//Ver1.50
#endif
		if (ISystemCnt>0xFFFFFF00) ISystemCnt=0xFFFFFF00; //Ver0.5
		if (IErrorTimeCnt>0xFFFFFF00) IErrorTimeCnt=0xFFFFFF00; //Ver0.99 
		if (ByChCur!=(ByChLast&0x07) && PMode==22 && ISystemCnt>SYSTEM_1MIN) {	//Ver1.40 20->21 //Ver0.99e
			ByChLast=ByChCur;
			EepromSaveLastCh(ByChCur);	//Ver0.99 Last Channel Save
		}
		if (!(FlagSystem & 0x01)) continue;
#if DEBUG_TIME
			SetBit(PORTD,7);	//DEBUG Time check
#endif
		TimeCount();
		//Display(cSeq);	//Ver2.0 
		KeyScan(cSeq);
		CheckInputStatus();	//������ üĿ
		MainProcessor();
		//-----1'st Channel ADC Check 
		FlagSystem&=0xFE; //System Timer1 Interupt Flag Clear
		if (ByAdcOn==1) {
			for (byOut=0;byOut<ADC_READ_NO;byOut++) {
#if DEBUG_TIME
				SetBit(PORTD,6);	//DEBUG Time check
#endif


				//-----ADC READ START
				if (StChannel[ByAdcChannel].bySensor<MAX_SENSOR) {

					
					iMaxKalmanCnt=CalDelayCnt(StChannel[ByAdcChannel].byDelayMode,CountValidCh());
					AdcRead(ByAdcChannel,iMaxKalmanCnt);
				}
#if DEBUG_TIME
				ClrBit(PORTD,6);	//DEBUG Time check
#endif
				//------------------------------------------
				//----------���� ä�� �����ϱ�--------------
				//------------------------------------------
				by=ByAdcChannel;
				do {	//��ȿ�� ���� ä�� ã�� 			
					ByAdcChannel++;
					if (ByAdcChannel>=MAX_CHANNEL) ByAdcChannel=0;
					if (by==ByAdcChannel) break;//Ȱ��ȭ æ���� ������ 
					if (StChannel[ByAdcChannel].bySensor<MAX_SENSOR) break;
				} while(1);
				if (StChannel[ByAdcChannel].bySensor<MAX_SENSOR) {	//���� ä�� ADC ����
					AdcSetChannel(ByAdcChannel);
				}

				//------------------------------------------
				//----------���� ä�� ADC���� ����---------- 
				//------------------------------------------
				if (StChannel[by].bySensor>=MAX_SENSOR) continue;	//continue for....

				if (StSensor[StChannel[by].bySensor].byNagative==0) { // ���м����� ��� 
					//-----PRESSURE HIGH ����
					idelta=(StSensor[StChannel[by].bySensor].iPrsMax-StSensor[StChannel[by].bySensor].iPrsMin)/20;	//������ 5%
					IPrsCur=StSensor[StChannel[by].bySensor].iPrsMax-idelta;
					if (StChannel[by].byUnit==UNIT_PSI) IPrsCur=ChangeHpaTo10mPsi(IPrsCur); //PSI�ϰ�� ���� ���Ѱ� ���� 
						else delay_100us(1);
					FlagHighPrs=FlagHighPrs&(~(1<<by));	
					if (StChannel[by].iPrsCur > IPrsCur) { 
						FlagHighPrs|=(1<<by);
						FlagError|=0x02;
						IErrorTimeCnt=0;	//Ver0.99 �ڵ������� ���� SystemTimeCnt
					}
					//-----PRESSURE LOW ���� 
					FlagLowPrs=FlagLowPrs&(~(1<<by));

					IPrsCur=StSensor[StChannel[by].bySensor].iPrsMin-idelta;
					if (StChannel[by].byUnit==UNIT_PSI) IPrsCur=ChangeHpaTo10mPsi(IPrsCur); //PSI�ϰ�� ���� ���Ѱ� ����

					if (StChannel[by].iPrsCur < IPrsCur ) {	
						FlagLowPrs|=(1<<by);
						FlagError|=0x01;
						IErrorTimeCnt=0;	//Ver0.99 �ڵ������� ���� SystemTimeCnt

					} 
				} else {	//�ξм����� ��� 
					//-----PRESSURE HIGH ����
					idelta=(StSensor[StChannel[by].bySensor].iPrsMax-StSensor[StChannel[by].bySensor].iPrsMin)/20;	//������ 5%
					IPrsCur=StSensor[StChannel[by].bySensor].iPrsMax-idelta;
					if (StChannel[by].byUnit==UNIT_PSI) IPrsCur=ChangeHpaTo10mPsi(IPrsCur); //PSI�ϰ�� ���� ���Ѱ� ���� 
					FlagHighPrs=FlagHighPrs&(~(1<<by));	
					if (StChannel[by].iPrsCur < IPrsCur) {
						FlagHighPrs|=(1<<by);
						FlagError|=0x02;
						IErrorTimeCnt=0;	//Ver0.99 �ڵ������� ���� SystemTimeCnt
					} 
					//-----PRESSURE LOW ���� 
					IPrsCur=StSensor[StChannel[by].bySensor].iPrsMin-idelta;
					if (StChannel[by].byUnit==UNIT_PSI) IPrsCur=ChangeHpaTo10mPsi(IPrsCur); //PSI�ϰ�� ���� ���Ѱ� ���� 
					FlagLowPrs=FlagLowPrs&(~(1<<by));
					if (StChannel[by].iPrsCur > IPrsCur) {	
						FlagLowPrs|=(1<<by);
						FlagError|=0x01;
						IErrorTimeCnt=0;	//Ver0.99 �ڵ������� ���� SystemTimeCnt
					}
				}

			}	//End for(byout...) 
		}
		cSeq++;
		if (cSeq>=(MAX_DIGIT)) {
			cSeq=0;
		}
		//--------------------------------------------------------------- 
		//-----------------��� ����------------------------------------- 
		//--------------------------------------------------------------- 
		byOut=0;
		for (by=0;by<MAX_CHANNEL;by++)	{ //Channel���� ����� ByChOutData�� ���� 
			if (StChannel[by].bySensor<MAX_SENSOR) {
				ByChOutEnable|=0x01<<by;
				byOut|=(ChOutControl(by)<<by);	//�з��� ���Ͽ� ����� �����ϴ� �Լ�
			} else {
				ByChOutEnable&=~(0x01<<by);
			} 
		}
		byOut=byOut&ByChOutEnable;
		ByChOutData=byOut;
		if (PMode>=PMODE_NDISP && PMode<PMODE_FAC) {
			//-----CH 1~6 ����� �� PORT E�� 
			PORTE=(byOut<<2);	
			//-----CH 7,8 ����� �� PORT D Bit0,1�� 
			if (byOut&0x40) SetBit(PORTD,0); 
				else ClrBit(PORTD,0); 
			if (byOut&0x80) SetBit(PORTD,1); 
				else ClrBit(PORTD,1); 
		}			
		//--------------------------------------------------------------- 
		//-----------------SPIDER------------------------------------- 
		//--------------------------------------------------------------- 
#if SPIDER_ACTIVE	//Ver1.50
		if ( PMode>PMODE_NDISP &&  PMode<40) 	{
			if (FlagUartOn==0) UartOpen();
			SpiderSendData();
		}	
#endif
#if SPIDER_SINGLE_ACTIVE		//Ver1.60
		if (ByRxTimeCnt>0) {		//Check Rx OverTime 
			ByRxTimeCnt++;
			if (ByRxTimeCnt>5) {
				ByRxTimeCnt=0;
				RxBufClear();
			}
		}		
		if ( PMode>20 &&  PMode<40) 	{
			if (FlagUartOn==0) UartOpen();
			if (ByReqdSpiderCh<9) {
				if (BySpiderSeq==0 || BySpiderSeq==SPIDER_1ST_TIME || BySpiderSeq==SPIDER_2ND_TIME) {
					RxBufClear();
					SpiderSendSingleData(ByReqdSpiderCh);
				}
				BySpiderSeq++;
				if (BySpiderSeq>SPIDER_2ND_TIME) {		//if ReSend Time is more then 3, Stop Send Data  
					BySpiderSeq=0;
					ByReqdSpiderCh=99;	//Cancel Sned Data
				}	
			}	
		}	
#endif
		
		//--------------------------------------------------------------- 
		//-----------------Eagle-EYE------------------------------------- 
		//--------------------------------------------------------------- 
#if Eagle_EYE_ACTIVE 	//Ver1.20
		if (PMode>20 && PMode<40) {	//FACTORY���� EEPROM ���� ������ ���� , ��� ��ȯ���� ������ ó����    
			if (FlagUartOn==0) UartOpen();
			if ( ByEagleCmd==0 ) {
				if (StUsart1.byRxBufPos>0) {
					ByEagleCmd=ByRxBuf[0];	//Data�� TXBuf�� �����ϱ����� Reflashó�� �ϱ����� ���� 
					ByEaglePos=0;
				}
			} else if (ByEagleCmd==0x02) {
				EaglePrsReflash();
				ByEagleCmd=9;
			} else if (ByEagleCmd==0x03) {
				EagleTriggerReflash();
				ByEagleCmd=9;
			} else if (ByEagleCmd==0x04) {
				EagleOffsetReflash();
				ByEagleCmd=9;
			} else if (ByEagleCmd==0x05) {
				EagleDelayReflash();
				ByEagleCmd=9;
			} else if (ByEagleCmd==0x06) {
				EagleSensorReflash();
				ByEagleCmd=9;
			} else if (ByEagleCmd==9) {
				if (EagleTrans()==0) ByEagleCmd=0;
			} else {
				ByEagleCmd=0;
			}
			StUsart1.byRxBufPos=0;	//RX Buf Clear
		} 
#endif
		//--------------------------------------------------------------- 
		//-----------------WATCH DOG------------------------------------- 
		//--------------------------------------------------------------- 
		WatchdogReset();
		
		#if DEBUG_TIME
			ClrBit(PORTD,7);	//DEBUG Time check
		#endif
	}
}	

