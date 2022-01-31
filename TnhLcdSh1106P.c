#include "TnhLcdSh1106P.h"
#include "FntEng32.h"
#include "FntEng16.h"
#include "FntEng06.h"
#include "FntUnit32.h"
//#include "FntJohabHan16.h"

//---------------------------------------------------------------------
//   lcd control perform
//---------------------------------------------------------------------
const char TitleList[17][17] PROGMEM ={
   {"   PREHEATING   "},
   {"   CONDITION    "},
   {"    HUMIDIFY    "},
   {"     CHARGE     "},
   {"   STERILIZER   "},

   {"    EXHAUST     "},
   {"   POST CYCLE   "},
   {"    AIR WISH    "},
   {"  AERATE PHASE  "},
   {"    COMPLETE    "},
   
   {" GAS STERILIZER "},
   {"  BASIC CONTROL "},
   {"   LEAK TEST    "},
   {"  SET & ADJUST  "},
   {"     WARNING    "},
   
   {"  SYSTEM CHECK  "},
   {"  QUIT CONFIRM  "}
 };

//---- for lcd hangul ----------------------------
/*
void hprintf(byte xposi, byte yposi, byte put_mode, char *fmt)
{
	byte data1, data2, first, mid, last, b1, b2, b3 = 1;//,*md;
	byte font_data;//bi,,k=0,h=0x80;
	byte count,countt;
	int il,i;//,j;
	//unsigned int m1;
    	byte table[3][32]={
		{ 0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
		{ 0,  0,  0,  1,  2,  3,  4,  5,  0,  0,  6,  7,  8,  9, 10, 11,
		0,  0, 12, 13, 14, 15, 16, 17,  0,  0, 18, 19, 20, 21,  0,  0 },
		{ 0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
		15, 16,  0, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  0,  0 }
	};
	char str[140]={0,};
	strcpy(str,fmt);
    

	for(il = 0 ; il<strlen(str) ; il++)
	{
		data1 = (byte) *(str+il);
		if (data1 > 127) {
		il++;
		data2 =(byte) *(str+il);  

			if(data1 == 212);
			else
			{
				first = (data1 & 124) >> 2;
				mid   = (data1 & 3) * 8 + (data2 >> 5);
				last  = data2 & 31;

				first = table[0][first];
				mid   = table[1][mid];
				last  = table[2][last];


				switch(first)
				{
					case  1:
					case 16:    
						if(last == 0) b2 = 0;
						else b2 = 2; 
						break;
					default: 
						if(last == 0) b2 = 1;
						else b2 = 3;
				}

				switch(mid)
				{
					case  1: case  2: case  3:
					case  4: case  5: case  6:
					case  7: case  8: case 21: 
						if(last == 0) b1 = 0; 
						else b1 = 5; 
						b3 = 0; 
						if(mid == 2) b3 = 1; 
						break;
					case  9: case 13: case 19: 
						if(last == 0) b1 = 1; 
						else b1 = 6; b3 = 3; 
						break;
					case 14: case 18:          
						if(last == 0) b1 = 2; 
						else b1 = 6; b3 = 3; 
						break;
					case 10: case 11: case 12: case 20:                   
						if(last == 0) b1 = 3; 
						else b1 = 7; b3 = 0; 
						break;
					case 15: case 16: case 17: 
						if(last == 0) b1 = 4; 
						else b1 = 7; 
						b3=3;
						break;
				}

				if((mid == 0) && (last == 0)) b1 = 0;
				//--------------LcdBuf Clear--------------------------------------------
				for( i = 0 ; i < 16 ; i++)  {
					ByaLcdBuf[yposi+1][xposi+i] = 0;
					ByaLcdBuf[yposi+0][xposi+i] = 0;
				}


				if(first != 0) {
					countt = 0;
					switch (b1) {
						case 0: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st0[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st0[first][ countt++]);
	   						}
							break;
						case 1: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st1[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st1[first][ countt++]);
							}
							break;
						case 2: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st2[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st2[first][ countt++]);
							}
							break;
						case 3: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st3[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st3[first][ countt++]);
							}
							break;
						case 4: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st4[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st4[first][ countt++]);
							}
							break;
						case 5: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st5[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st5[first][ countt++]);
							}
							break;
						case 6: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st6[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st6[first][ countt++]);
							}
							break;
						case 7: 
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_1st7[first][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_1st7[first][ countt++]);
							}
							break;
					}
				}

				if(mid != 0)  {
					countt = 0;
					switch (b2) {
						case 0:
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_2nd0[mid][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_2nd0[mid][ countt++]);
							}
							break;
						case 1:
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_2nd1[mid][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_2nd1[mid][ countt++]);
							}
							break;
						case 2:
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_2nd2[mid][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_2nd2[mid][ countt++]);
							}
							break;
						case 3:
							for( i = 0 ; i < 16 ; i++)  {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_2nd3[mid][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_2nd3[mid][ countt++]);
							}
							break;
					}    
	                        
				}

				if(last != 0){
					countt = 0;
					switch (b3) {
						case 0:
							for( i = 0 ; i < 16 ; i++) {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_3rd0[last][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_3rd0[last][ countt++]);
							}
							break;
						case 1:
							for( i = 0 ; i < 16 ; i++) {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_3rd1[last][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_3rd1[last][ countt++]);
							}
							break;
						case 2:
							for( i = 0 ; i < 16 ; i++) {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_3rd2[last][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_3rd2[last][ countt++]);
							}
							break;
						case 3:
							for( i = 0 ; i < 16 ; i++) {
								ByaLcdBuf[yposi+1][xposi+i] |= pgm_read_byte(&han_rm16_3rd3[last][ countt++]);
								ByaLcdBuf[yposi+0][xposi+i] |= pgm_read_byte(&han_rm16_3rd3[last][ countt++]);
							}
							break;
					}
				}
				if(put_mode!=PUT_NORMAL) 
				{
					for( i = 0; i < 16 ; i++) 
					{
						ByaLcdBuf[yposi+1][xposi+i] = ~ByaLcdBuf[yposi+1][xposi+i];
						ByaLcdBuf[yposi+0][xposi+i] = ~ByaLcdBuf[yposi+0][xposi+i];
					}
				}
			}
			xposi += 16;
		}
		else {
			if(data1 < 32) data1 = 32;
			count = 0;


			for( i = 0; i < 8 ; i++)   {
				font_data = pgm_read_byte(&eng_re16_fnt[data1][count++]);
				ByaLcdBuf[yposi+1][xposi+i] = font_data;
				font_data = pgm_read_byte(&eng_re16_fnt[data1][count++]);
				ByaLcdBuf[yposi+0][xposi+i] = font_data;
			}

			if (!put_mode)   {
				for( i = 0;i < 8; i ++)    {
					ByaLcdBuf[yposi+1][xposi+i] = ~ByaLcdBuf[yposi+1][xposi+i];
					ByaLcdBuf[yposi+0][xposi+i] = ~ByaLcdBuf[yposi+0][xposi+i];
				}
			}
			xposi+=8;
		}
    	}
}
*/

//---- for lcd hangul ----------------------------
//---- for String Displayl ----------------------------
void e32printf(byte xposi, byte yposi, byte put_mode,char *fmt)
{
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
	byte xposii,yposii;
	byte byCnt,byData,byLen;
	byte il,i;
	char str[9];
	strcpy(str,fmt);
	byLen=strlen(str);
	if (byLen>8) {
	byLen=8;

	}
	xposii=xposi;
	yposii=yposi+1;
	for(il = 0 ; il<byLen; il++)    {
		byData = (byte) *(str+il);
		if(byData < 32) byData = 32;
		byData-=0x20;	//Eng32 font는 앞의 특수 기호 32개를 兩?상태에서 스페이스 부터 시작함 => 0=>0x30(일반 Eng Font)=>0x10(Eng32)
		byCnt = 0;
		
		if (put_mode==PUT_NORMAL) 
			for( i = 0; i < 16 ; i++)   {
				ByaLcdBuf[yposi+3][xposii] = pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi+2][xposii] = pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi+1][xposii] = pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi][xposii] = pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				xposii++;
			}
		else
			for( i = 0;i < 16; i ++)    {
				ByaLcdBuf[yposi+3][xposii] = ~pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi+2][xposii] = ~pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi+1][xposii] = ~pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi][xposii] = ~pgm_read_byte(&eng_re32_fnt[byData][byCnt++]);
				xposii++;
			}

	}
}


void e16printf(byte xposi, byte yposi, byte put_mode,char *fmt)
{
	// xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
 	byte xposii,yposii;
 	byte byCnt,byData,byLen;
	byte il,i;
	char str[20];
	strcpy(str,fmt);
	byLen=strlen(str);
	if (byLen>16) {
		byLen=16;
	}
	xposii=xposi;
	yposii=yposi+1;
	for(il = 0 ; il<byLen; il++)    {
		byData = (byte) *(str+il);
		if(byData < 32) byData = 32;
		byCnt = 0;
		if (put_mode==PUT_NORMAL) 
			for( i = 0; i < 8 ; i++)   {
				ByaLcdBuf[yposii][xposii] = pgm_read_byte(&eng_re16_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi][xposii] = pgm_read_byte(&eng_re16_fnt[byData][byCnt++]);
				xposii++;
			}
      		else
			for( i = 0;i < 8; i ++)    {
				ByaLcdBuf[yposii][xposii] = ~pgm_read_byte(&eng_re16_fnt[byData][byCnt++]);
				ByaLcdBuf[yposi][xposii] = ~pgm_read_byte(&eng_re16_fnt[byData][byCnt++]);
				xposii++;
			}
	}
}


//#pragma assumebank(2)
void eprintf(byte xposi, byte yposi, byte put_mode,char *fmt)
{
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
 	byte xposii,yposii;
 	byte byCnt,byData,byLen;
	byte il,i;
	char str[30];
	strcpy(str,fmt);
	byLen=strlen(str);
	if (byLen>21) byLen=21;
	xposii=xposi;
	yposii=yposi;
	for(il = 0 ; il<byLen; il++)    {
		byData = (byte) *(str+il);
//		if(data1 < 32) data1 = 32;
		byCnt=0;
       	if (put_mode==PUT_NORMAL)
			for( i = 0; i < 6 ; i++)   {
				ByaLcdBuf[yposi+0][xposii] = pgm_read_byte(&eng_r6_fnt[byData][byCnt++]);
				xposii++;
			}
		else
			for( i = 0;i < 6; i ++)    {
				ByaLcdBuf[yposi+0][xposii] = ~pgm_read_byte(&eng_r6_fnt[byData][byCnt++]);
				xposii++;
			}
	}
}
//#pragma assumebank(2)


void DBufDrawFont16x16(byte xposi, byte yposi, byte put_mode, byte *font)
{
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
    byte i,yposii,xposii;
    byte count = 0;
    yposii=yposi+1;
    xposii=xposi;
    if ( put_mode==PUT_NORMAL) 
        for( i = 0; i < 16 ; i++)   {
         ByaLcdBuf[yposii][xposii] =pgm_read_byte(&font[count++]);
         ByaLcdBuf[yposi][xposii] =pgm_read_byte(&font[count++]);
         xposii++; 
        }
      else
       for( i = 0;i < 16; i ++)    {
         ByaLcdBuf[yposii][xposii] = ~pgm_read_byte(&font[count++]);
         ByaLcdBuf[yposi][xposii] = ~pgm_read_byte(&font[count++]);
         xposii++; 
       }
    
}

void DBufDrawFont32x16(byte xposi, byte yposi, byte put_mode, byte *font)
{	// 16x32 Font Display
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
	byte i,xposii;
 	byte yposii,yposiii,yposiiii;
    	byte count = 0;
    	yposiiii=yposi+3;
    	yposiii=yposi+2;
    	yposii=yposi+1;
    	xposii=xposi;
    	if ( put_mode==PUT_NORMAL) 
        	for( i = 0; i < 16 ; i++)   {
         		ByaLcdBuf[yposiiii][xposii] =pgm_read_byte(&font[count++]);
         		ByaLcdBuf[yposiii][xposii] =pgm_read_byte(&font[count++]);
         		ByaLcdBuf[yposii][xposii] =pgm_read_byte(&font[count++]);
         		ByaLcdBuf[yposi][xposii] =pgm_read_byte(&font[count++]);
         		xposii++; 
        	}
      else
       	for( i = 0;i < 16; i ++)    {
          		ByaLcdBuf[yposiiii][xposii] =~pgm_read_byte(&font[count++]);
         		ByaLcdBuf[yposiii][xposii] =~pgm_read_byte(&font[count++]);
         		ByaLcdBuf[yposii][xposii] =~pgm_read_byte(&font[count++]);
         		ByaLcdBuf[yposi][xposii] =~pgm_read_byte(&font[count++]);
         		xposii++; 
       	}
    
}


void DBufDrawFont16x8(byte xposi, byte yposi, byte put_mode, byte *font)
{
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
	byte xposii,yposii;
	byte byCnt;
	byte i;
	xposii=xposi;
	yposii=yposi+1;
	byCnt = 0;
	if (put_mode==PUT_NORMAL) {
		for( i = 0; i < 8 ; i++)   {
			ByaLcdBuf[yposii][xposii] = pgm_read_byte(&font[byCnt++]);
			ByaLcdBuf[yposi][xposii] = pgm_read_byte(&font[byCnt++]);
			xposii++;
		}
	} 
	else {
		for( i = 0;i < 8; i ++)    {
			ByaLcdBuf[yposii][xposii] = ~pgm_read_byte(&font[byCnt++]);
			ByaLcdBuf[yposi][xposii] = ~pgm_read_byte(&font[byCnt++]);
			xposii++;
		}
	}
}



/*
void PutIcon(byte xposi, byte yposi, byte put_mode, byte icon_no)
{
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
	byte i,yposii,xposii;
	byte count = 0;
	yposii=yposi+1;
	xposii=xposi;
	if (put_mode==PUT_NORMAL)
		for( i = 0; i < 16 ; i++)   {
			ByaLcdBuf[yposii][xposii] = pgm_read_byte(&icon_3017[icon_no][count++]);
			ByaLcdBuf[yposi][xposii] = pgm_read_byte(&icon_3017[icon_no][count++]);
			xposii++; 
		}
	else
	       for( i = 0;i < 16; i ++)    {
			ByaLcdBuf[yposii][xposii] = ~pgm_read_byte(&icon_3017[icon_no][count++]);
			ByaLcdBuf[yposi][xposii] = ~pgm_read_byte(&icon_3017[icon_no][count++]);
			xposii++; 
		}
}

void put_graph(byte mode)
{
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
    byte i,j,xposii;
//    yposii=3;
    xposii=16;
    for (j=1;j<13;j++) { 
      count = 0;
      if ( (j-mode)==0 ) 
        for( i = 0; i < 8 ; i++)   {
         ByaLcdBuf[3][xposii] = ~eng_re16_fnt[j][count++];
         ByaLcdBuf[2][xposii]  = ~eng_re16_fnt[j][count++];
         xposii++; 
        }   else
        for( i = 0;i < 8; i ++)    {
         ByaLcdBuf[3][xposii] = eng_re16_fnt[j][count++];
         ByaLcdBuf[2][xposii]  = eng_re16_fnt[j][count++];
         xposii++; 
        }
    }   
    
    switch (mode){
      case 2:
            tbuf[1]=(int)nv_time[NV_PH_HOUR]; 
            tbuf[2]=(int)nv_time[NV_PH_MIN];  
            tbuf[3]=(int)nv_time[NV_PH_SEC];  
            tbuf[4]=nv_pnt[NV_LTEMP];  
            tbuf[5]=nv_pnt[NV_HTEMP];  
            draw_preheat_set(0);  
        break;
      case 3:
            tbuf[1]=(int)nv_time[NV_CDV_SEC]; 
            tbuf[2]=(int)nv_time[NV_CDN_SEC];  
            tbuf[3]=(int)nv_time[NV_CDS_SEC];  
            tbuf[4]=(int)nv_time[NV_CD_PULSE];  
            draw_cd_set(0);
        break;
      case 4:
            tbuf[1]=(int)nv_time[NV_HM2LP_MIN]; 
            tbuf[2]=(int)nv_time[NV_HM2LP_SEC]; 
            tbuf[3]=(int)nv_time[NV_HM2HP_MIN]; 
            tbuf[4]=(int)nv_time[NV_HM2HP_SEC]; 
            tbuf[5]=(int)nv_time[NV_HMHD_MIN]; 
            tbuf[6]=(int)nv_time[NV_HMHD_SEC]; 
            tbuf[7]=(int)nv_time[NV_HM_PULSE]; 
            tbuf[8]=nv_pnt[NV_HM_LP]; 
            tbuf[9]=nv_pnt[NV_HM_HP]; 
            draw_hm_set(0);
        break;
      case 5:
            tbuf[1]=(int)nv_time[NV_CH_HOUR]; 
            tbuf[2]=(int)nv_time[NV_CH_MIN];  
            tbuf[3]=(int)nv_time[NV_CH_SEC];  
            tbuf[4]=nv_pnt[NV_CH_P];  
            draw_chaw_set(0);
        break;
      case 6:
            tbuf[1]=(int)nv_time[NV_ST_HOUR]; 
            tbuf[2]=(int)nv_time[NV_ST_MIN];  
            tbuf[3]=(int)nv_time[NV_ST_SEC];  
            tbuf[4]=nv_pnt[NV_ST_LP];  
            tbuf[5]=nv_pnt[NV_ST_HP];  
            draw_st_set(0);
         break;
      case 7:
            tbuf[1]=(int)nv_time[NV_EX_MIN]; 
            tbuf[2]=(int)nv_time[NV_EX_SEC];  
            tbuf[3]=nv_pnt[NV_EX_P];  
            draw_ex_set(0);
        break;
      case 8:
            tbuf[1]=(int)nv_time[NV_PS_MIN]; 
            tbuf[2]=(int)nv_time[NV_PS_SEC];  
            tbuf[3]=(int)nv_time[NV_PS_PULSE];  
            tbuf[4]=nv_pnt[NV_PS_LP];  
            tbuf[5]=nv_pnt[NV_PS_HP];  
            draw_ps_set(0);
        break;
      case 9:
            tbuf[1]=(int)nv_time[NV_AW_HOUR]; 
            tbuf[2]=(int)nv_time[NV_AW_MIN];  
            tbuf[3]=(int)nv_time[NV_AW_SEC];  
            tbuf[4]=nv_pnt[NV_AW_P];  
            draw_chaw_set(0);
        break;
      case 10:
            tbuf[1]=(int)nv_time[NV_AR_HOUR]; 
            tbuf[2]=(int)nv_time[NV_AR_MIN];  
            tbuf[3]=(int)nv_time[NV_AR_SEC];  
            tbuf[4]=(int)nv_time[NV_AR_PULSE];  
            tbuf[5]=nv_pnt[NV_AR_HOLDP];  
            draw_ar_set(0);
        break;
      case 11:
            draw_help(HLP_DEFAULT);   
        break;
      default :
        break;

    }
}
*/
void DBufReverseBox(byte left, byte top, byte right, byte bot)
{
	byte i, by, byi;
	byte byFstLine, byLastLine;
	byte byFstLineStBit, byLastLineEndBit;
	//------Calculate  Start and End Line----------- 
	byFstLine=top/8;	//Start Line 구하기 
	byFstLineStBit=top%8;	//Line에서 세로 위치 
	byLastLine=bot/8;	//Line 구하기 
	byLastLineEndBit=bot%8;	//Line에서 세로 위치 
	//-----Start Line 처리 ------------------------
	by=0xFF;
	by<<=byFstLineStBit;	//해당 bit이후 MSB까지 모두 1로 
	if (byFstLine!=byLastLine) {
		for (i=left;i<=right;i++) 
			ByaLcdBuf[byFstLine][i] ^= by;	//해당 라인의 해당 비트를 역전 
	} else {
		byi=0xFF;
		byi<<=(byLastLineEndBit+1);	//해당 bit이후 모두 0로 
		byi=~byi;	//LSB부터 마지막 bit 까지 1로   
		by&=byi;
		for (i=left;i<=right;i++) 
			ByaLcdBuf[byFstLine][i] ^= by;	//해당 라인의 해당 비트를 역전 
		return;
	}
	//------중간 Line 처리-------------------------- 
	for (byi=byFstLine+1;byi<byLastLine;byi++) {
		for (i=left;i<=right;i++) {
			ByaLcdBuf[byi][i] =~ByaLcdBuf[byFstLine][i];	//해당 라인의 해당 비트를 역전 
		}
	}
	//-----End(Last) Line 처리 ------------------------
	by=0xFF;
	by<<=(byLastLineEndBit+1);	//해당 bit이후 모두 0로 
	by=~by;	//LSB부터 마지막 bit 까지 1로   
	for (i=left;i<=right;i++) {
		ByaLcdBuf[byLastLine][i] ^= by;	//해당 라인의 해당 비트를 역전 
	}
}


//#pragma assumebank(2)
void DBufReverse_16(byte xcount)
{
 // 2개 line을 xcount로 정해진 bit수만큼 반전시킴
 // xposi :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
	byte i;
	byte byBufPosX;		
	byte byBufPosY;

	byBufPosY=ByLcdPosY+1;
	byBufPosX=ByLcdPosX;
	for( i = 0; i < xcount ; i++)   {
		ByaLcdBuf[ByLcdPosY][byBufPosX] = ~ByaLcdBuf[ByLcdPosY][byBufPosX];
		ByaLcdBuf[byBufPosY][byBufPosX] = ~ByaLcdBuf[byBufPosY][byBufPosX];
		byBufPosX++; 
	}
}

//#pragma assumebank(2)
void DBufReverse_8(byte xcount)
{
 // 2개 line을 xcount로 정해진 bit수만큼 반전시킴
 // xpois :0~127 점의 위치를 표시 ,yposi:0~7 문자행을 표시 
	byte i;
	byte byBufPosX;		
	byBufPosX=ByLcdPosX;
	for( i = 0; i < xcount ; i++)   {
		ByaLcdBuf[ByLcdPosY][byBufPosX] = ~ByaLcdBuf[ByLcdPosY][byBufPosX];
		byBufPosX++; 
	}
}



//#pragma assumebank(2)
void DBufClearAll(void)
{
	byte i,j;
	for( i = 0 ; i < 8 ; i++)
		for( j = 0 ; j < 132 ; j++)
			ByaLcdBuf[i][j] = 0x00;
}

//#pragma assumebank(2)
void DBufClearRows(byte srow, byte erow,byte scol, byte ecol)
{
	byte i,j;
	for( i = srow ; i <= erow ; i++)
		for(j = scol ; j <= ecol ; j++)  ByaLcdBuf[i][j] &= 0x00;
}


void DBufClearRow(byte row, byte scol, byte ecol)
{
  byte i;
  for(i = scol ; i <= ecol ; i++)  ByaLcdBuf[row][i] &= 0x00;
}

//#pragma assumebank(2)
void DBufDrawUnderLine(byte row,byte scol, byte ecol)
// 7번 line에 밑줄 긋기
{
  byte i;
  for(i = 1 ; i <= ecol ; i++)  ByaLcdBuf[row][i] |= 0x80;
}

void DBufClearUnderLine(byte row,byte scol, byte ecol)
{
  byte i;
  for(i = 1 ;  i <= ecol  ; i++)  ByaLcdBuf[row][i] &= 0x7F;
}



void DBufDraw_init(void)
{
	byte i;
	DBufClearAll();
	for (i=0;i<17;i++) StrBuf[i]=TitleList[5][i];
	StrBuf[17]=0x00;
	ByLcdPosX=0;	ByLcdPosY=0;	ByLcdPutMode=PUT_REVERSE;
	e16printf(0,0,PUT_NORMAL,StrBuf);
	ByLcdPosX=16;	ByLcdPosY=2;	ByLcdPutMode=PUT_NORMAL;
	e16printf(16,2,PUT_NORMAL,(char*)"You are");
	ByLcdPosX=48;	ByLcdPosY=4;	ByLcdPutMode=PUT_NORMAL;
	e16printf(48,4,PUT_NORMAL,(char*)"Welcome!");
	ByLcdPosX=8;	ByLcdPosY=6;	ByLcdPutMode=PUT_NORMAL;
	e16printf(8,6,PUT_NORMAL,(char*)"KL Medical Co.");
	//DBufDrawBox();
}

//#pragma assumebank(2)
/*
void DBufDrawBox(void)
{
	byte i;
	//------위 아래 가로선 그리기----------- 
	for (i=0;i<128;i++) {
		ByaLcdBuf[0][i] |= 0x01;
		ByaLcdBuf[7][i] |= 0x80;
	}
	//------좌 우측 세로선 그리기----------- 
	for (i=0;i<8;i++) {
		ByaLcdBuf[i][0] = 0xff;
		ByaLcdBuf[i][127] = 0xff;
	}
}
*/
void DBufDrawBox(byte byOn, byte left, byte top, byte right, byte bot)
{

	DBufDrawYLine(byOn,left,top,bot);
	DBufDrawYLine(byOn,right,top,bot);

	DBufDrawXLine(byOn,top,left,right);
	DBufDrawXLine(byOn,bot,left,right);
}


void DBufDrawGraphBox(unsigned char xs,unsigned char ys,unsigned char xe,unsigned char ye)
{
	DBufDrawXLine(1,ys,xs,xe);
	DBufDrawYLine(1,xs,ys,ye);
	DBufDrawXLine(1,ye,xs,xe);
	DBufDrawYLine(1,xe,ys,ye);
/*
*/	
}


void DBufDrawPoint(byte bOn, byte x, byte y)	//LCD의 xy점을 지우거나 그리기 
{	
	byte byLine,byBit;	//RAM Buf 위치
	byLine=y/8;
	byBit=0x01<<(y%8);	//해당 위치의 bit를 1로 
	//byDt=ByaLcdBuf[byLine][x];
	if (bOn==0) {
		byBit=~byBit;
		ByaLcdBuf[byLine][x]&=byBit;
	} else {
		ByaLcdBuf[byLine][x]|=byBit;
	}
}	

void DBufDrawXLine(byte bOn,byte y, byte byStart, byte byEnd)	//LCD의 yLine에 정의된 구간선그리기  
{	
	byte byLine;	//RAM Buf 위치
	byte byDt;
	byte by;
	byLine=y/8;
	byDt=0x01<<(y%8);	//해당 위치의 bit를 1로 
	if (bOn) {
		for (by=byStart;by<=byEnd;by++)
		ByaLcdBuf[byLine][by]|=byDt;
	} else {
		for (by=byStart;by<=byEnd;by++)
			ByaLcdBuf[byLine][by]&=~byDt;
	}
}	


void DBufDrawYLine(byte bOn,byte x, byte byStart, byte byEnd)	//LCD의 yLine에 정의된 구간선그리기  
{	
	byte byLineSt,byLineEnd;	//RAM Buf 위치
	byte byDt,byl;
	byte by;
	byLineSt=byStart/8;
	byLineEnd=byEnd/8;
	for (by=byLineSt;by<=byLineEnd;by++) { //Line마다 에 수직선 그리기 
		byDt=0xFF;
		//--------첫 Line----------------
		if (by==byLineSt) {
			byl=byStart%8;		// if byStart=3 이면 첫라인의 byl은 5,
			byDt=byDt<<byl;	
		}
		//--------마지막 Line----------------
		if (by==byLineEnd) {
			byl=byEnd%8;		// if byStart=3 이면 첫라인의 byl은 5,
			byDt=byDt>>(8-byl);	
		}
		if (bOn) {
			ByaLcdBuf[by][x]|=byDt;
		} else {
			ByaLcdBuf[by][x]&=~byDt;
		}	
		
	}
	//---첫번째 Line------------------
	
}	




//------------------------------------------------------------------------
//#pragma assumebank(2)
char  Cs1_Busy_Check(void)
{
	unsigned char iTmOut=0;
	char cRtn=0;
	LCD_SET_RD;
	PORT_LCD_DO=0xFF;
	LCD_SET_CMD;
#if BUSY_CHECK_EN
	LCD_EN_L;
	LCD_SET_RD;
	asm volatile("nop");
	LCD_CLR_CS1;
	LCD_EN_H;
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	cRtn=PORT_LCD_DI;
   	while((PORT_LCD_DI & 0x80)!=0) {
		if (iTmOut++>CS_TIME_OUT) {		//PrintRow에서 시험 결과 1이면 에러 발생 2부터 정상 동작 
			cRtn=-1;
			break;
		}	
	};
	LCD_SET_CS1;
	LCD_EN_L;
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
#else 
	asm volatile("nop");
#endif	
	return cRtn;

}


//#pragma assumebank(2)
void Cs2_Busy_Check(void)
{
	LCD_SET_CMD;
	asm volatile("nop");
	asm volatile("nop");
	LCD_EN_H;
	asm volatile("nop");
	asm volatile("nop");
	LCD_EN_L;
	PORT_LCD_DO=0xFF;
	PORT_LCD_DIR=0x00;
	LCD_SET_RD;
	LCD_CLR_CS1;
	LCD_SET_CS2;
	asm volatile("nop");
	asm volatile("nop");
	LCD_EN_H;
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
    while((PORT_LCD_DI & 0x80)!=0) {};
	LCD_EN_L;
	asm volatile("nop");
	asm volatile("nop");
	LCD_CLR_CS2;
	asm volatile("nop");
	asm volatile("nop");
	LCD_EN_H;
}

void Cs1_Write_byte(unsigned char data)
{
	LCD_EN_L;
	LCD_SET_WR;
	asm volatile("nop");
	LCD_SET_WR;
	PORT_LCD_DO=data;
	LCD_CLR_CS1;
	LCD_EN_H;
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
 	LCD_EN_L;
	LCD_SET_CS1;
	LCD_SET_RD;		//Ver1.2 
	PORT_LCD_DO=0xFF;
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
/*  //Ver1.1 Think NoNeed
	LCD_EN_H;
*/	
}

//#pragma assumebank(2)

void LcdInit(void)
{
	LcdOn();
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
void LcdWriteCmd( unsigned char dt )
{
	Cs1_Busy_Check();
	Cs1_Write_byte(dt);   
}

//-------------------------------------------------------------------
void LcdDisplayOffset( unsigned char offset )
{	//Double Bytes Command
	//This is a double byte command. The next command specifies the mapping of display start line to one of COM0-63
	Cs1_Busy_Check();
	Cs1_Write_byte(0xD3);   
	Cs1_Write_byte(offset);   
}

void LcdContrast( unsigned char byLevel )
{	//Double Bytes Command
	//This is a double byte command. The next command specifies the mapping of display start line to one of COM0-63
	Cs1_Busy_Check();
	Cs1_Write_byte(0x81);   
	Cs1_Write_byte(byLevel);   
}

//-------------------------------------------------------------------
void LcdWrDataToRAM( unsigned char *pdt ,unsigned char len )
{	//Write RAM DATA
	unsigned char by;
		Cs1_Busy_Check();
		LCD_SET_DATA;
		asm volatile("nop");
		asm volatile("nop");
		for( by = 0; by< len; by++)  {
			asm volatile("nop");
			asm volatile("nop");
			Cs1_Write_byte(*pdt++);      // Data Write
		}
}


//-------------------------------------------------------------------
unsigned char LcdReadStatus(void)	
{	//b7 busy 
	unsigned char cRtn=0;
	//cRtn=(unsigned char) I2cReadCurrentAddr(SH1106_ID_STAT);
	return cRtn;
}


//-------------------------------------------------------------------
#if LOW_LEVEL
//-------------------------------------------------------------------
void LcdSetRowPage(unsigned char RowPage)
{	//Set Row Page 0~7
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_SET_PAGE + RowPage);   
}

//-------------------------------------------------------------------
void LcdSetTopLine(unsigned char top)
{	//line(RowPage) 0~7
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_SET_PAGE + top);   
}
//-------------------------------------------------------------------
void LcdSetStartLine(unsigned char line)
{	//line 0~63
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_START_LINE + line);   
}

//-------------------------------------------------------------------
void LcdGotoYX(unsigned char RowPage, unsigned char xPos)
{
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_SET_PAGE + RowPage);   

 	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_SET_COL_LOW + (xPos & 0x0F) );   
	
 	Cs1_Busy_Check();
	Cs1_Write_byte( SH1106_CMD_SET_COL_HIGH + ((xPos>>4)&0x0F) );   
}
//-------------------------------------------------------------------
void LcdEntireDisplay(unsigned char byOn)
{	//Set Entire Display OFF/ON	
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_ENDISP_OFF+byOn);   
}

//-------------------------------------------------------------------
void LcdOff(void)
{
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_DISP_OFF);   
}

//-------------------------------------------------------------------
void LcdOn(void)
{
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_DISP_ON);   
}

//-------------------------------------------------------------------
void LcdReverse(unsigned char byOn)
{
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_NOR_DISP+byOn);   
}
//-------------------------------------------------------------------
void LcdMirror(unsigned char byMir)
{
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_COM_DIR+(byMir<<3));   
}

//-------------------------------------------------------------------
void LcdAllDotOn(unsigned char byOn)
{
	Cs1_Busy_Check();
	Cs1_Write_byte(SH1106_CMD_ENDISP_OFF+byOn);   
}

void LcdClearLine(unsigned char byLine)
{
		
}

#else
//-------------------------------------------------------------------
void LcdSetRowPage(unsigned char RowPage)
{	//Set Row Page 0~7
	LcdWriteCmd( SH1106_CMD_SET_PAGE + RowPage);
}

//-------------------------------------------------------------------
void LcdSetTopLine(unsigned char top)
{	//line(RowPage) 0~7
	LcdWriteCmd( SH1106_CMD_SET_PAGE + top);
}
//-------------------------------------------------------------------
void LcdSetStartLine(unsigned char line)
{	//line 0~63
	LcdWriteCmd( SH1106_CMD_START_LINE + line);
}

//-------------------------------------------------------------------
void LcdGotoYX(unsigned char RowPage, unsigned char xPos)
{
    LcdWriteCmd( SH1106_CMD_SET_PAGE + RowPage);
    LcdWriteCmd( SH1106_CMD_SET_COL_LOW + (xPos & 0x0F) );
    LcdWriteCmd( SH1106_CMD_SET_COL_HIGH + ((xPos>>4)&0x0F) );
}
//-------------------------------------------------------------------
void LcdEntireDisplay(unsigned char byOn)
{	//Set Entire Display OFF/ON	
	LcdWriteCmd( SH1106_CMD_ENDISP_OFF+byOn);
}

//-------------------------------------------------------------------
void LcdSleep(void)
{

	LcdWriteCmd( SH1106_CMD_DISP_OFF);
}

//-------------------------------------------------------------------
void LcdOff(void)
{
	LcdWriteCmd( SH1106_CMD_DISP_OFF);
}

//-------------------------------------------------------------------
void LcdOn(void)
{
	LcdWriteCmd( SH1106_CMD_DISP_ON);
}

//-------------------------------------------------------------------
void LcdReverse(unsigned char byOn)
{
	LcdWriteCmd( SH1106_CMD_NOR_DISP+byOn);
}
//-------------------------------------------------------------------
void LcdMirror(unsigned char byMir)
{
	LcdWriteCmd( SH1106_CMD_COM_DIR+(byMir<<3));
}

//-------------------------------------------------------------------
void LcdAllDotOn(unsigned char byOn)
{
	LcdWriteCmd(SH1106_CMD_ENDISP_OFF+byOn);      // 
}

void LcdClearLine(unsigned char byLine)
{
		
}


#endif

void LcdDispRow(byte start, byte end)
{	//Range Start/end  0~7 Line 
	byte j;//,k;
	EX1=0;
	//k=end;
	for (j=start;j<=end;j++) {
		
		LcdGotoYX( j,2); // Set Page Address
		LcdWrDataToRAM( &ByaLcdBuf[j][0],128);      // Data Write
	}	
	EX1=1;

}

//------------------------------------------------------------------
//-------------------------------------------------------------------
void	LcdDispRowMir(byte start, byte end)
{	//Range Start/end  0~7 Line 
	byte i,j,k;
	byte buf[128];
	byte *pbuf =buf;
	EX1=0;
	k=end;
	for (i=start;i<=end;i++) {
		LcdGotoYX(i,2); // Set Page Address
		
		pbuf=&buf[127];
		for (j=0;j<128;j++) *pbuf--=ByaLcdBuf[i][j];
		LcdWrDataToRAM( &buf[0],128);      // Data Write
	}	
	EX1=1;

}

//-------------------------------------------------------------------
void DisplayRowRead(byte start, byte end)
{	//Range Start/end  0~7 Line 
/*
	byte i,j,k;
	EX1=0;
	k=end;
	for (j=start;j<=end;j++) {
		OLedGotoYX( j,0); // Set Page Address
		//------------Dummy Read----------------------
		asm("nop");
		for( i = 0; i < 128; i++)  {
			asm("nop");
			//ByaLcdBuf[j][i]= LcdReadData();      // Data Write
		}
	}	
	EX1=1;
*/
}

void LcdDrawBmp(byte *bmp)
{
	byte j;
	byte *pBmp;
	pBmp=bmp;
	EX1=0;

	for (j=0;j<=7;j++) {
		
		LcdGotoYX( j,2); // Set Page Address
		LcdWrDataToRAM( pBmp ,128);      // Data Write
		pBmp+=128;
	}	
	EX1=1;


}



