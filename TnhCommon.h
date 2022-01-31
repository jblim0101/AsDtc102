#ifndef _TNHCOMMON_H
#define _TNHCOMMON_H

#include <avr/io.h>
#include <avr/interrupt.h> 
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <avr/pgmspace.h>

#define FOSC 16000000
#define ON			1
#define OFF		0
#define HIGH		1
#define LOW		0
//#define TRUE	1
//#define FALSE	0

#define SetBit(x,y) (x|=(1<<y))
#define ClrBit(x,y) (x&=~(1<<y))

//--------------시스템 관련 주요 변수값 정의 --------
//---------------------------------------------------
#define DEBUG_DAC_LEVEL 0
#define SYSTEM_CLOCK_2R5MS 1
#define SYSTEM_CLOCK_3MS 0
#define SYSTEM_CLOCK_4MS 0
#define SYSTEM_CLOCK_40MS 0
#define SYSTEM_CLOCK_125MS 0
//---------------------------------------------------
//--------------For System Clock 2.5mSec---------------
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

#endif
//---------------------------------------------------

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

#endif
//---------------------------------------------------
enum { TIMER_STOP, TIMER_10uS, TIMER_100uS, TIMER_500uS, TIMER_1mS, TIMER_2r5mS,TIMER_3mS,TIMER_4mS, TIMER_10mS, TIMER_40mS, TIMER_50mS, TIMER_100mS, TIMER_125mS, TIMER_250mS,TIMER_500mS,TIMER_1SEC};


//---------------------------------------------------
//------------------COMMON STRUCTURE FOR VAR---------
//---------------------------------------------------
typedef unsigned char byte;
typedef unsigned char  u8;
typedef char  s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long  u32;
typedef long  s32;
typedef float f32;

typedef union
{
	unsigned short val; //lkjc
	unsigned char byte[2];
} u16_Byte;

typedef union
{
	signed short val; //lkjc
	unsigned char byte[2];
} s16_Byte;

typedef union
{
//lkjc	unsigned long int  val;
	unsigned int  val; //lkjc
	unsigned char byte[4];
} u32_Byte;

typedef union
{
	int  val; //lkjc
	unsigned char byte[4];
} s32_Byte;

typedef struct
{
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
} bBit;

typedef union
{
	bBit bits;
	unsigned char val;
} uniByte;

// tuner 6721 structure
typedef struct
{
	uniByte  uniByte0;
	uniByte  uniByte1;
	uniByte  uniByte2;
	uniByte  uniByte3;
	uniByte  uniByte4;
	uniByte  uniByte5;
}  SixuniByte;


#endif //_TNHCOMMON_H

