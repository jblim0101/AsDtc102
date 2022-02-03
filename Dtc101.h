
#ifndef Dtc101H
#define Dtc101H


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "TnhCommon.h"
#include "Dtc100_EepromList.h"
#include "TnhUsart_AtMega128.h"		//Ver1.7
#include "TnhLcdSh1106P.h"
#include "FntNumBox16x16.h"
#include "FntSymBox16x16.h"
#include "FntNumCir16x8.h"


#define SetBit(x,y) (x|=(1<<y))
#define ClrBit(x,y) (x&=~(1<<y))

#define MAX_SENSOR 5
#define MAX_CHANNEL 8
#define ADC_READ_NO 2			// 2.5mS 시스템 주기에 읽는 ADC갯수 

//---------------------------------------------------
//--------------시스템 관련 주요 변수값 정의 --------
//---------------------------------------------------
#define SW_VERSION ("V170")
#define DEBUG_DAC_LEVEL 0

/*
#define SYSTEM_CLOCK_2R5MS 1
#define SYSTEM_CLOCK_3MS 0
#define SYSTEM_CLOCK_4MS 0
#define SYSTEM_CLOCK_40MS 0
#define SYSTEM_CLOCK_125MS 0

//---------------------------------------------------
//--------------For System Clock 2R5mSec---------------
//---------------------------------------------------
#if SYSTEM_CLOCK_2R5MS
#define SYSTEM_125M  49
#define SYSTEM_250M  99
#define SYSTEM_500M  199
#define SYSTEM_750M  299
#define SYSTEM_1SEC  399
#define SYSTEM_2SEC  799
#define SYSTEM_3SEC  1199
#define SYSTEM_5SEC  1999
#define SYSTEM_7SEC  2799
#define SYSTEM_10SEC  3999
#define SYSTEM_15SEC  5999
#define SYSTEM_20SEC  7999
#define SYSTEM_30SEC  11999
#define SYSTEM_1MIN  23999
#define SYSTEM_2MIN  47999
#define SYSTEM_3MIN  71999
#define SYSTEM_5MIN  119999
#define SYSTEM_POWERDOWN	239999	//10분:239999
#define TIME_KEEP_ERROR  1199


#define Q_1 8	// 1/16박자 
#define Q_2 16	// 1/8박자 
#define Q_3 24	// 1/6박자 
#define Q_4 32	// 1/4박자 
#define Q_5 48	

#endif
//---------------------------------------------------
//--------------For System Clock 3mSec---------------
//---------------------------------------------------
#if SYSTEM_CLOCK_3MS
#define SYSTEM_125M  41
#define SYSTEM_250M  83
#define SYSTEM_DOOR_TIME 62	//250ms
//#define SYSTEM_DOOR_TIME 93	//375ms
//#define SYSTEM_DOOR_TIME 124	//500ms
#define SYSTEM_500M  166
#define SYSTEM_750M  249
#define SYSTEM_1SEC  333
#define SYSTEM_2SEC  666
#define SYSTEM_3SEC  999
#define SYSTEM_5SEC  1666
#define SYSTEM_7SEC  2333
#define SYSTEM_10SEC  3333
#define SYSTEM_15SEC  4999
#define SYSTEM_20SEC  6666
#define SYSTEM_30SEC  9999
#define SYSTEM_1MIN  19999
#define SYSTEM_2MIN  39999
#define SYSTEM_3MIN  59999
#define SYSTEM_5MIN  99999
#define SYSTEM_POWERDOWN	199999	//10분:199999

#define Q_1 8	// 1/16박자 
#define Q_2 16	// 1/8박자 
#define Q_3 24	// 1/6박자 
#define Q_4 32	// 1/4박자 
#define Q_5 48	

#endif
//---------------------------------------------------
//--------------For System Clock 4mSec---------------
//---------------------------------------------------
#if SYSTEM_CLOCK_4MS
#define SYSTEM_125M  31
#define SYSTEM_250M  62
#define SYSTEM_DOOR_TIME 62	//250ms
//#define SYSTEM_DOOR_TIME 93	//375ms
//#define SYSTEM_DOOR_TIME 124	//500ms
#define SYSTEM_500M  124
#define SYSTEM_750M  187
#define SYSTEM_1SEC  249
#define SYSTEM_2SEC  499
#define SYSTEM_3SEC  749
#define SYSTEM_5SEC  1249
#define SYSTEM_7SEC  1749
#define SYSTEM_10SEC  2499
#define SYSTEM_15SEC  3749
#define SYSTEM_20SEC  4999
#define SYSTEM_30SEC  7499
#define SYSTEM_1MIN  14999
#define SYSTEM_2MIN  29999
#define SYSTEM_3MIN  44999
#define SYSTEM_5MIN  74999
#define SYSTEM_POWERDOWN	149999	//10분:149999

#define Q_1 12	// 1/16박자 
#define Q_2 24	// 1/8박자 
#define Q_3 32	// 1/6박자 
#define Q_4 64	// 1/4박자 
#define Q_5 96	

#endif

//---------------------------------------------------
//--------------For System Clock 40mSec--------------
//---------------------------------------------------
#if SYSTEM_CLOCK_40MS
#define SYSTEM_250M  5
#define SYSTEM_500M  12
#define SYSTEM_750M  18
#define SYSTEM_1SEC  24
#define SYSTEM_2SEC  49
#define SYSTEM_3SEC  74
#define SYSTEM_10SEC  249
#define SYSTEM_15SEC  374
#define SYSTEM_20SEC  499
#define SYSTEM_30SEC  749
#define SYSTEM_1MIN  1499
#define SYSTEM_2MIN  2999
#define SYSTEM_3MIN  4499
#define SYSTEM_5MIN  7499
#define SYSTEM_POWERDOWN	14999	//10분: 14999 

#define Q_1 1
#define Q_2 3
#define Q_3 4
#define Q_4 7
#define Q_5 10
#endif
//---------------------------------------------------
//--------------For System Clock 125mSec-------------
//---------------------------------------------------
#if SYSTEM_CLOCK_125MS
#define SYSTEM_250M  1
#define SYSTEM_500M  3
#define SYSTEM_750M  5
#define SYSTEM_1SEC  7
#define SYSTEM_2SEC  15
#define SYSTEM_3SEC  23
#define SYSTEM_10SEC  79
#define SYSTEM_15SEC  119
#define SYSTEM_20SEC  159
#define SYSTEM_30SEC  239
#define SYSTEM_1MIN  479
#define SYSTEM_2MIN  959
#define SYSTEM_3MIN  1439
#define SYSTEM_5MIN  1919
#define SYSTEM_POWERDOWN	3839	//10분:3839

#define Q_1 1	// 1/16박자
#define Q_2 1	// 1/8박자 
#define Q_3 1	// 1/6박자
#define Q_4 2	// 1/4박자 
#define Q_5 3
#endif

enum { TIMER_STOP, TIMER_10uS, TIMER_100uS, TIMER_500uS, TIMER_1mS, TIMER_2r5mS,TIMER_3mS,TIMER_4mS, TIMER_10mS, TIMER_40mS, TIMER_50mS, TIMER_100mS, TIMER_125mS, TIMER_250mS,TIMER_500mS,TIMER_1SEC};
*/
enum { SNO,	DO5,	DO5H,	RE5,	RE5H,	MI5,	FA5,	FA5H,	SO5,	SO5H,	RA5,	RA5H,	SI5,
			DO6,	DO6H,	RE6,	RE6H,	MI6,	FA6,	FA6H,	SO6,	SO6H,	RA6,	RA6H,	SI6,
			DO7,	DO7H,	RE7,	RE7H,	MI7,	FA7,	FA7H,	SO7,	SO7H,	RA7,	RA7H,	SI7	};
enum {KEY_NO, KEY_UP, KEY_EDIT, KEY_3RD, KEY_DN, KEY_UPDN};
enum {MEL_KEY, MEL_DINGDONG, MEL_DINGDONG2,MEL_DINGDING, MEL_POWER_ON, MEL_POWER_OFF, MEL_BELL, MEL_POWER_ON2,MEL_EMC,MEL_EMC2};  
#define KEY_LONG 0x04
#define KEY_CONTINUE 0x08

 
//-----Display관련 변수 정의 
#define COMMON_CATHODE 0
#define MAX_DIGIT 6

//-----7'Segment 정의 
/*
#define LED_STOP_RPM 11 
#define LED_STOP_RCF 12 
#define LED_STOP 13
#define LED_RUN_RPM 14
#define LED_RUN_RCF 15
#define LED_STR_STOP_RPM 16
#define LED_STR_STOP_RCF 17
#define LED_STR_STOP 18
#define LED_STR_RUN_RPM 19
#define LED_STR_RUN_RCF 20
#define LED_STR_RUN 21
*/

unsigned char FlagDot; 	//DOT가 표시될 Digit
unsigned int ByScroll; //스크롤 순서 
#if COMMON_CATHODE
const char Seg[]={	0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F,
					0x00,0x08,0x01,0x0E,0x40,0x42,0x6A,0x55,0x52,0x64,
					0x46,0x0,0x77,0x7C,0x39,0x5E,0x79,0x71,0x3D,0x76,
					0x10,0x1E,0x7A,0x38,0x33,0x54,0x5C,0x73,0x67,0x50,
					0x6D,0x78,0x1C,0x18,0x3C,0x14,0x6E,0x48,0x27 };
#else
const char Seg[]={	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,
					0xFF,0xF7,0xFE,0xF1,0xBF,0xBD,0x95,0xAA,0xAD,0x9B,
					0xB9,0x3F,0x88,0x83,0xC6,0xA1,0x86,0x8E,0xC2,0x89,
					0xEF,0xE1,0x85,0xC7,0xCC,0xAB,0xA3,0x8C,0x98,0xAF,
					0x92,0x87,0xE3,0xE7,0xC3,0xEB,0x91,0xB7,0xD8 };
#endif 

unsigned char ByDispBuf[8]; //Display할 Digit의 문자(Seg)의 배열번호 

//------------------------------
//-----USART관련 변수 정의------
//------------------------------
#define MAX_RXBUF_SIZE 128
volatile unsigned char FlagUsartSta;	//b0 :Rx Evented
volatile unsigned char ByRxTimeCnt;		//Time Out Check : 10ms -> 4보다 크면 타임 out처라
//volatile unsigned char ByRxBufPos;		// Data가 RxBuf에 쓰여질 위치 이므로 수신된 Size와 동일함 
//volatile unsigned char ByRxBuf[MAX_RXBUF_SIZE];
volatile unsigned char ByFrameSize;
unsigned char ByRxFrame[24];
//unsigned char ByTxBuf[256];
//volatile unsigned char FlagTimeOut;		//b0: USART TIME OUT시 1로 세팅 
//enum {M16_NON,M16_24,M16_48,M16_96,M16_144,M16_192,M16_288,M16_384,M16_576,M16_768,M16_1152,M16_2304,M16_2500,M16_5000,M16_10000};
#define RX_FRAME_MIN 14
#define RX_FRAME_MAX 19
#define STX 0x02
#define ETX 0x03
#define ETX1 0x0D
#define ETX2 0x0A
#define ACK 0x06
#define NACK 0x31

void Usart1_SendChData(unsigned char channel);
void Usart1_RcvdDataToFrame(void);
char RxChFrameProcess(void);
char Usart1_RcvAck(void);
void RxBufClear(void);


//-----MainSystem관련 변수 정의
#define PMODE_START 10
#define PMODE_NDISP 20
#define PMODE_RDISP 25
#define PMODE_CHECK 30
#define PMODE_MENU 50
#define PMODE_EDIT 55
#define PMODE_COPY 72
#define PMODE_CALB 81
#define PMODE_CLR_CALB 90

#define PMODE_FAC 			100
#define PMODE_FAC_MENU 		110
#define PMODE_FAC_INIT 		120
#define PMODE_FAC_ARUN 		130

#define PMODE_FAC_CLR_CAL   140
#define PMODE_FAC_SENSOR 	145
#define PMODE_FAC_SEND 		160
#define PMODE_FAC_RCV 		170
#define PMODE_FAC_CAL 		180
#define PMODE_FAC_EXIT 		190

#define PMODE_SAVE_SENSOR_ONE 200
#define PMODE_SAVE_CHANNEL_ONE 201
#define PMODE_SAVE_SENSOR_ALL 202
#define PMODE_SAVE_CHANNEL_ALL 203
#define PMODE_SAVE_ALL 204
#define PMODE_SAVE_CAL_RATE 210 
#define PMODE_ERROR 		250

enum {FAC_INIT, FAC_AUTO_RUN, FAC_SENSOR, FAC_CAL, FAC_CLR_CAL, FAC_SEND, FAC_RCV,  FAC_REMOTE};
enum {SENSOR_P1,SENSOR_P2,SENSOR_P3,SENSOR_P4,SENSOR_P5,SENSOR_U1,SENSOR_U2,SENSOR_U3};
enum {PRS_REF,PRS_ABS};
enum {SW_NOR_OFF,SW_NOR_ON};
enum {TRIG_SINGLE, TRIG_WIND};
enum {UNIT_MPA,UNIT_KPA,UNIT_BAR,UNIT_PSI,UNIT_HPA};
enum {UNIT_VOLT, UNIT_mV,UNIT_A, UNIT_mA, UNIT_TMPC};
enum {USER_UNIT_HPA, USER_UNIT_mBAR, USER_UNIT_10mPSI, USER_UNIT_10PA, USER_UNIT_100uBAR, USER_UNIT_mPSI};
enum {PRS_AVG_5mS,PRS_AVG_50mS, PRS_AVG_100mS, PRS_AVG_250mS,PRS_AVG_500mS,PRS_AVG_750mS, PRS_AVG_1S};
enum {EDIT_NO, EDIT_SET, EDIT_CAL, EDIT_CLR_CAL, EDIT_COPY,EDIT_RETURN};
enum {PRECISION_0, PRECISION_1, PRECISION_2, PRECISION_3};

volatile unsigned char FlagSystem; 	//SystemClock 한번씩 b0가 1로 세팅됨,Display승인 :b1
volatile unsigned char FlagError; 	//측정값 오류 bit 	
unsigned char ByErrorCnt;		//진행 에러 카운터 
unsigned char FlagLowPrs;		//각 채널의 Low값 초과여부 를 bit 단위로 표시  0:정상 1:최소치 초과 
unsigned char FlagHighPrs;
unsigned char FlagReqLcdRow;		//Lcd  표시가 요구되는 Raw

typedef union
{
//lkjc	float;
	float f; //lkjc
	unsigned char byte[4];
} _FLOAT_UNION;



typedef struct {
	char cName[5];
	unsigned char byUnit;
	unsigned char byNagative;
	int  iOffset;
	int	 iPrs_0V;
	int	 iPrsMin;
	int  iPrsMax;
}_SENSOR;
_SENSOR StSensor[8];
_SENSOR StSensorBuf;

typedef struct{
	unsigned char bySensor;		//센서 종류 표시: SENSOR_P1,SENSOR_P2,SENSOR_P3,SENSOR_P4,....,MAX_SENSOR(NoUse Channel)
	unsigned char byInCh;		//Input Channel No.
	unsigned char byPrsType;	//0이면 절대압력 1이면 상대압력(현재기압을 0), 모든압력은 절대압으로 설정 및 보관
	unsigned char byUnit; 		//0: Bar, 1: Kpa, 2: PSI, 3: KGF
	unsigned char byTrgType;	//0: Only Trigger On at Set pressure, 1: Trigger On in pressure range

	_FLOAT_UNION uniAdcCalRate;
	int iAdcOffset;				//각 채널의 ADC Offset보정값 (0~4092)
	int iAdc;
	int iCalibratedAdc;				//Ver1.03 보정된 ADC값
	int iPrsCur;				//각 챈널의 현재 압력(Bar*100, kpa, psi*10, kgf*100)
	int iOffset;				//압력 Offset
	int iTrgOn;				//Trig On Setting 압력(Bar*100, kpa, psi*10, kgf*100)
	int iTrgOff;				//Trig Off Setting 압력(Bar*100, kpa, psi*10, kgf*100)
	int iHyst;			//Histery 
	unsigned char byDelayMode;		//Delay Time
	unsigned char byOutStatus;		//출력 상태
	unsigned char bySwType;
}_CHDATA;
_CHDATA StChannel[8];
_CHDATA StChannelBuf;

typedef struct{		//Cal시 이전값 백업용 
	unsigned char bySensor;		//센서 종류 표시: SENSOR_P1,SENSOR_P2,SENSOR_P3,SENSOR_P4,....,MAX_SENSOR(NoUse Channel)
	_FLOAT_UNION uniAdcCalRate;
	int iAdcOffset;				//각 채널의 ADC Offset보정값 (0~4092)
}_CHDATA_CAL;
_CHDATA_CAL StCalBackup[8];

//----------------------------------------------------------------------------------------
int IPrsCur;
int IPrsMax;
int IPrsMin;

unsigned char FlagActCh;
unsigned char ByChCur;
unsigned char ByChLast;
unsigned char ByOutput;
unsigned char ByAutoStart;
unsigned char PMode;
unsigned char PModeOld;
unsigned char PSubMode;
unsigned char FlagFlash;		//Flashing할 Digit를 세팅 0x01: 첫번째 Digit Flashing
unsigned char ByEditMenuId;		//Edit or check Menu ID
unsigned char BySource;		//Channel 0~7  User표시는 1!8
unsigned char ByTarget;		//Channel 0~8  8은  ALL CH
//-------------------------------------------------------------------------------------


//-----Key관련 변수 정의
volatile unsigned char ByKey;
volatile unsigned char ByOldKeyBuf;
volatile unsigned char ByKeyBuf;
volatile unsigned char FlagKey; //  b0: 1회 처리완료 - Next Key Approval, b1: 현재 Key Active, 
unsigned int WKeyTime; //Key가 눌러져 있는 시간 
unsigned int WKeyInterval ;// Long Key에서 반복 동작 주기 계수 클수록 빠름 0~100;

//-----Timer관련 변수 정의
volatile unsigned long ISystemCnt, IErrorTimeCnt; //Timer2에 의한 Count 기본 4mS주기 
volatile unsigned int Tm_mSec;
unsigned char Tm_Sec;
unsigned char Tm_Min;
unsigned char FlagTimeCount;	//b0:Count Start 초단위이후  계산

#define TimeCountRun() (FlagTimeCount|=0x01)
#define TimeCountStop() (FlagTimeCount&=0xFE)

//-----ADC관련 변수
#define RESOLUTION_RATE 4092.0
#define AVG_COUNT 4						//MAX 10이상이면 변수 범위를 벗어남
#define AdcSetChannel(ch) (ADMUX=ch) 		//Set USE_AREF & Channel
#define AdcStart()	(ADCSRA=0xFC)	//Set ADEN/ADSC/ADFR/ADIF/ADIE & 1/16 Clock
#define AdcClose() (ADCSRA=0x00)
volatile unsigned int AdcCnt;
volatile unsigned int AdcValue;
volatile unsigned int AdcValueTotal;
unsigned char ByAdcOn;		//ADC 동작 허가 
unsigned char ByAdcChannel; 
int IAdcValue[MAX_CHANNEL];
int IChKalmanCnt[MAX_CHANNEL];
//int IMaxChKalmanCnt[MAX_CHANNEL];




//-----Basic함수 
void Port_Init(void);
void Var_Init(void);
void InitCalibration(void);
void InitChannel(_CHDATA *stCh);
void CopyChannel(_CHDATA *stDis,_CHDATA *stSou);
void CopySensor(_SENSOR *stDis,_SENSOR *stSou);
void Timer0_Init(char mode);
void Timer1_Init(char mode);
void Timer2_Init(char mode);
void DeviceInit(void);
void delay_ms(unsigned int idt);
void delay_100us(unsigned int idt);
void Delay_1us(void);
void Delay_5us(void);
void Delay_10us(void);
void TimeCount(void);
void TimeClear(void);

volatile unsigned int IKalmanCnt;
volatile double FKalmanAvg;
	
double KalmanAvg(double preavg, double value);
int KalmanAvgInt(int preavg, int value);

char DecodeSensorData(unsigned char bySens, unsigned char *buf);
void EncodeSensorData(unsigned char bySens, unsigned char *buf);
char DecodeChData(unsigned char channel, unsigned char *buf);
void EncodeChData(unsigned char channel, unsigned char *buf);


//---------------------------------------------------------------------
//-------------------EEPROM READ/WRITE BASIC FUNCTION------------------
//---------------------------------------------------------------------
void _EepromWriteByte(unsigned int addr, unsigned char dt);
unsigned char _EepromReadByte(unsigned int addr);

//---------------------------------------------------------------------
char _EepromRealWriteByte(unsigned int addr, unsigned char dt) ;//Busy이면 -1을 성공이면 0을 리턴
char _EepromRealReadByte(unsigned int addr, unsigned char *data);//Busy이면 -1을 성공이면 0을 리턴
char EepromRealSaveSensorBlock(unsigned char bySensor,unsigned char byByteCnt);
char EepromRealSaveChBlock(unsigned char channel,unsigned char byByteCnt);
char EepromRealSaveCalRateBlock(unsigned char byChannel,unsigned char byByteCnt);
char EepromRealSaveCalRateAll(unsigned char byByteCnt);

//---------------------------------------------------------------------
char EepromCheck(void);
//Ver0.98f void _EepromSaveChBlock(unsigned char channel);
//Ver0.98f void _EepromSaveSensorBlock(unsigned char bySensor);
//Ver0.98f void EepromSaveSensorBlock(unsigned char bySensor);
//Ver0.98f void EepromSaveChBlock(unsigned char channel);
//Ver0.98f void EepromSaveAll(void);

char _EepromLoadSensorBlock(unsigned char bySensor);
char _EepromLoadChBlock(unsigned char channel);

char EepromLoadSensorBlock(unsigned char bySensor);
char EepromLoadChBlock(unsigned char channel);
char  EepromLoadCalRateBlock(unsigned char byCh);

void EepromSaveChOffset(unsigned char channel);
char EepromLoadAll(void);

//---------------------------------------------------------------------
//---------------Oled Display-------------------------------------------
//---------------------------------------------------------------------
void DispUnitToStr(unsigned char byUnit ,char *cUnit); 
void DispMain(byte part, _CHDATA *stch);
void DispSetCopyMain(byte byMenu, byte byEdit);
void DispSetDispMode(byte xpos,byte yline, byte byMode);	//Display Mode 0:NOR, 1:ROT 

void DispSetUnit(byte xpos,byte yline, byte put_mode, byte byUnit);
void DispSetUnit_8(byte xpos,byte yline, byte put_mode, byte byUnit);
void DispSetSym(byte xpos,byte yline,  byte put_mode, byte bySym);
void DispSetCh(byte xpos,byte yline, byte byCh);
void DispSetActChList(byte flagActCh, byte byCh);

void DispSetTrgCh(unsigned char TrgOn);
void DispSetMainMenu(byte byMenu, byte byStyle);
void DispSetFacMenu(byte byMenu, byte byEdit);
void DispSetEditMain(byte byMenu, byte byEdit);
void DispSetEditDelay(byte xpos,byte yline, byte put_mode, byte delay_mode);
void DispSetEditOutType(byte xpos,byte yline, byte put_mode, byte output_type);
void DispSetYesNo(byte xpos,byte yline, byte byYes);
void DispSetPrs(byte xpos,byte yline, int iPrs,unsigned char byUnit ); //Ver0.99 -199.9 ~ 9999 
void DispPrsToStr(int iPrs,unsigned char byUnit ,char *cPrs);  //범위 -999~999
void DispSetFixedPrs(byte xpos,byte yline, int iPrs, byte byUnit ); //Ver0.99 -199.9 ~ 9999 
void DispFixedPrsToStr(int iPrs, byte byUnit , char *cPrs); //Ver0.99 -199.9 ~ 9999 
void DispSetErr(unsigned char ErrNo);		//Display Error Code 
void DispSetErrFlag(void);
byte  DispSetRowFlag(byte start, byte end);
void DispSetStrAndNum(byte xpos, byte yline, char *str, int iValue);

//---------------------------------------------------------------------
//---------------7'Segment 1/5 duty Display & Key Scan-----------------
//---------------------------------------------------------------------
void Display(unsigned char seq);
void DisplaySetChannel(unsigned char byData);

//#define LedClrUnit() (PORTG=0x0F)
#define LedSetUnit(x) (PORTG=~(0x01<<x))
//#define DisplaySetOutChannel(x) (ByDispBuf[5]=~(1<<x))
//#define DisplaySetOutStatus(x) (ByDispBuf[5]=~x)

void DisplaySetNum(int iNum); //범위 -999~999
void DisplaySetPrs(int iPrs,unsigned char byUnit); //범위 -99999~99999
void DisplaySetFixedPrs(int iPrs,_CHDATA *StCh); //범위 -999~999

void DisplaySetLine(void);
void DisplaySetEnd(unsigned char byMode);
void DisplaySetStop(void);


void DisplaySetStr(const char *cstr);
void DisplaySetScrollStr(const char *cstr);
void DisplaySetEditMode(unsigned char byEditMode);
void DisplaySetChFrom(unsigned char byCh);
void DisplaySetChTo(unsigned char byCh);
void DisplaySetHighPrs(unsigned char byCh);
void DisplaySetLowPrs(unsigned char byCh);

void DisplaySetInit(void);
void DisplaySetFac(unsigned char mode);
void DisplaySetUnit(unsigned char byUnit);
void DisplaySetTrgType(unsigned char byTrgType);
void DisplaySetSwType(unsigned char bySwType);
void DisplaySetSensor(unsigned char bySensor);
//void DisplaySetPrsType(unsigned char byPrsType);
void DisplaySetSave(char cSave);


//---------------------------------------------------------------------
//----------------------------INPUT Status Check-----------------------
//---------------------------------------------------------------------
char KeyScan(unsigned char seq);
unsigned char EditDigit(unsigned char value,unsigned char max);
unsigned char DigitUp(unsigned char byValue);
unsigned char DigitDown(unsigned char byValue);

void CheckInputStatus(void);
unsigned char CheckActiveCh(void);	//each bits set if channel is active ,exsample return value : b0001 1011 => 1,2,4,5 channel acive 
unsigned char CheckEndMode(unsigned char *byEnd);
unsigned char CheckYesMode(byte xpos, byte yline, byte *byYes);
unsigned int ReadADC(unsigned char byPort);
int PrsUp(int iPrs,int iMax);
int PrsDown(int iPrs,int iMin);
int PrsStepUp(int iPrs,int iMax,int istep);
int PrsStepDown(int iPrs,int iMin,int istep);

unsigned char ByPrsStepAry[8];
unsigned char PrsSetStep(unsigned char byCh);		//Ver1.5
void PrsSetStepAll(void);		//Ver1.5

//---------------------------------------------------------------------
//----------------------------Pressure Processor-----------------------
//---------------------------------------------------------------------
#define K_PSI 1.450379
#define ADC4_REF_4R1V 	3356	//=839*4
#define ADC4_REF_1R0V	820		//=205*4    
#define DEFAULT_ADC_OFFSET 0
unsigned char ByChOutData;
unsigned char ByChOutEnable;
int ByPrsStep;

int CountValidCh(void);
void AdcRead(unsigned char AdcChannel,int iAvgCntNum);
unsigned char FindUserUnit(unsigned char byChannel); 
int AcdToPrs(unsigned int iadc, unsigned char byChannel);			//1~5V용도 
int AcdToPrsUserUnit(unsigned int iadc, unsigned char byChannel);	//0~5V용도 
int ChangeHpaTo10mPsi(int iHpa);
int Change10mPsiToHpa(int psi);
unsigned char ChOutControl(unsigned char byCh);
int CalDelayCnt(unsigned char byMode,unsigned char byValidChCnt);


//---------------------------------------------------------------------
//----------------------------Eagle-EYE--------------------------------
//---------------------------------------------------------------------
unsigned char ByEagleCmd;	//0: 동작없음 , 1: Pressure 전송, 전송중에는 Data갱신 없으며 전송후에는 0으로 Clear됨 
unsigned char ByEaglePos;	//전송시 ByEagleBuf의 위치
unsigned char EagleTrans(void);
void EagleInit(unsigned char  bOn);
void EaglePrsReflash(void); 
void EagleSensorReflash(void);	//Eagle eye Data 갱신 
void EagleTriggerReflash(void); 
void EagleOffsetReflash(void); 
void EagleDelayReflash(void); 

//---------------------------------------------------------------------
//Ver1.50---------------Spider Function--------------------------------
//---------------------------------------------------------------------
#define SPIDER_1ST_TIME 20		//Second Retry Response Time 40x2.5=100ms
#define SPIDER_2ND_TIME 40		//Second Retry Response Time 40x2.5=100ms

unsigned char BySpiderChMask;		//Spider On Chanel Flag Bitx:1 xCh On
unsigned char BySpiderSeq;
unsigned char SpiderPrs[8][16];
void Spider_RcvdDataToFrame(void);		 //Ver1.50
void SpiderSetPrs(unsigned char AdcChannel);	 //Ver1.50 //Ver0.99 -199.9 ~ 9999 
void SpiderSetPrsF(unsigned char channel);	 //Ver1.50  //Ver0.99 -199.9 ~ 9999 
void SpiderSendData(void);	//Send Data by Usart1		
unsigned char ByReqdSpiderCh;				//Ver1.6 요청받은 CH ID:1~8
char SpiderSendSingleData(unsigned char byRealCh);	//byRealCh:1~8, 정상 송출이면 0, 아니면(비활성CH) -1 return


//---------------------------------------------------------------------
//----------------------------Main Processor---------------------------
//---------------------------------------------------------------------
char ChBuf[17];
unsigned char ByRefBuf;	//보충용 전역 변수 
unsigned char FlagUartOn;
void UartOpen(void);
void UartClose(void);

unsigned char FindActiveChannel(unsigned char byCurCh);
void TimeOutCheck(unsigned int TimeCnt, unsigned char pmode);		//pmode:reserve a Return pmode 
void MainProcessor(void);

#endif
