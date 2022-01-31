//Graphic B/W LCD 128x64 5V GM126401S용 
#ifndef _TNHLCD_GD12864_H
#define _TNHLCD_GD12864_H

#include "TnhCommon.h"
/*
*/
#define LOW_LEVEL 1
#define SH1106_ID 0x78			//Common Chip Address
#define SH1106_ID_CW 0x78		//Chip Address for Command Write
#define SH1106_ID_CR 0x79		//Chip Address for Command Read  -  to check Status
#define SH1106_ID_STAT 0x79
#define SH1106_ID_DW 0x7A		//Chip Address for Data Write	
#define SH1106_ID_DR 0x7B		//Chip Address for Data Read
//----------Oled Control Byte-----------
#define SH1106_CTRL_CMDDT 0x00
#define SH1106_CTRL_CMDDT_CTRL 0x80
#define SH1106_CTRL_RAMDT 0x40
#define SH1106_CTRL_RAMDT_CTRL 0xC0
//-------------------------------------------
#define SH1106_CMD_SET_COL_LOW 0x00	//0x00+4 Lower bits col addr
#define SH1106_CMD_SET_COL_HIGH 0x10	//0x00+4 Higher bits col addr
#define SH1106_CMD_RD_STAT 0x00
#define SH1106_CMD_START_LINE 0x40		//0x40+line(0~63)
#define SH1106_CMD_ENDISP_OFF 0xA4
#define SH1106_CMD_ENDISP_ON 0xA5
#define SH1106_CMD_NOR_DISP 0xA6
#define SH1106_CMD_REV_DISP 0xA7
#define SH1106_CMD_DISP_OFF 0xAE
#define SH1106_CMD_DISP_ON 0xAF
#define SH1106_CMD_SET_PAGE 0xB0		//0xB0+page(0~7)
#define SH1106_CMD_COM_DIR 0xC0
#define SH1106_CMD_SET_DISP_OFFSET 0xD3	// 0xD3 Data(0~63)
#define SH1106_CMD_NOP 0xE3

//----------lcd display---------- 
#define PUT_NORMAL           0x00
#define PUT_REVERSE          0x01
#define PORT_LCD_CON	PORTA
#define PORT_LCD_DO		PORTC
#define PORT_LCD_DI		PINC
#define PORT_LCD_DIR	DDRC

//----------lcd display---------- 
#define LCD_SET_CMD		PORT_LCD_CON&=0xFD
#define LCD_SET_DATA	PORT_LCD_CON|=0x02

#define LCD_SET_RD		PORT_LCD_CON|=0x01
#define LCD_SET_WR		PORT_LCD_CON&=0xFE

#define LCD_EN_H		PORT_LCD_CON|=0x04
#define LCD_EN_L		PORT_LCD_CON&=0xFB

#define LCD_CLR_CS1	 	PORT_LCD_CON&=0xF7
#define LCD_SET_CS1 	PORT_LCD_CON|=0x08

#define LCD_CLR_CS2 	PORT_LCD_CON&=0xEF
#define LCD_SET_CS2 	PORT_LCD_CON|=0x10

#define LCD_RST_L 		PORT_LCD_CON&=0xDF
#define LCD_RST_H 		PORT_LCD_CON|=0x20

byte ByaLcdBuf[8][132];
byte EX1;



char StrBuf[25];
byte ByLcdPosX;
byte ByLcdPosY;
byte ByLcdPutMode;

void hprintf(byte xposi, byte yposi, byte put_mode, char *fmt);
void e32printf(byte xposi, byte yposi, byte put_mode,char *fmt);
void e16printf(byte xposi, byte yposi, byte put_mode,char *fmt);
//void eprintf(char *fmt);
void eprintf(byte xposi, byte yposi, byte put_mode,char *fmt);
void DBufDrawFont16x16(byte xposi, byte yposi, byte put_mode, byte *font);
void DBufDrawFont32x16(byte xposi, byte yposi, byte put_mode, byte *font);
void DBufDrawFont16x8(byte xposi, byte yposi, byte put_mode, byte *font);
//void PutIcon(byte xposi, byte yposi, byte put_mode, byte icon_no);
void DBufReverseBox(byte left, byte top, byte right, byte bot);
void DBufReverse_16(byte xcount);
void DBufReverse_8(byte xcount);
void DBufClearAll(void);
void DBufClearRows(byte srow, byte erow,byte scol, byte ecol);
void DBufClearRow(byte row, byte scol, byte ecol);
void DBufDrawUnderLine(byte row,byte scol, byte ecol);
void DBufClearUnderLine(byte row,byte scol, byte ecol);
//void DBufDrawBox(void);
void DBufDrawBox(byte byOn, byte left, byte top, byte right, byte bot);
void DBufDraw_init(void);

void DBufDrawGraphBox(unsigned char xs,unsigned char ys,unsigned char xe,unsigned char ye);
void DBufDrawPoint(byte bOn, byte x, byte y);	//LCD의 xy점을 지우거나 그리기 
void DBufDrawXLine(byte bOn,byte y, byte byStart, byte byEnd);	//LCD의 yLine에 정의된 구간선그리기  
void DBufDrawYLine(byte bOn,byte x, byte byStart, byte byEnd);	//LCD의 yLine에 정의된 구간선그리기  

#define BUSY_CHECK_EN 1
#define CS_TIME_OUT 50			//Cs1,2 무음답시 무한루프 방지 - PrintRow에서 시험 결과 1이면 에러 발생 2부터 정상 동작 
char  Cs1_Busy_Check(void);

void Cs1_Write_byte(unsigned char data);

void LcdInit(void);
void LcdWriteCmd( unsigned char dt );
void LcdDisplayOffset( unsigned char offset );

void LcdOff(void);
void LcdOn(void);
void LcdReverse(unsigned char byOn);
void LcdMirror(unsigned char byMir);
void LcdAllDotOn(unsigned char byOn);


void LcdDispRow(byte start, byte end);
void LcdDispRowMir(byte start, byte end);
void LcdDrawBmp(byte *bmp);


#endif
