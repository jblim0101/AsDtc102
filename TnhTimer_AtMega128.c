#include "TnhTimer_Atmega128.h"

//----------------------------------------------------------------
//---------------------Timer0 설정-------------------------------- 
//----------------------------------------------------------------
void Timer0_Init(char mode)
{
	cli();
	switch (mode) {
		case TIMER_STOP:
			TCCR0 = 0x00;	//b00011001 CTC, 1분주, Disable OC0 toggle
			TIMSK &= 0xFC; 		//Timer0 OCIE0 Mask
			break;
		case TIMER_10uS:
			TCCR0 = 0x09;	//b00011001 CTC, 1분주, Disable OC0 toggle
			//OCR0 = 160;			//16MHz, 분주비 1일때 10us주기로 인터럽트 발생 
			OCR0 = 159;			//16MHz, 분주비 1일때 10us주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0xFC;			//OCF0, TOV0 Flag Clear
			TIMSK |= 0x02; 		//Timer0 OCIE0 Mask
			break;
		case TIMER_100uS:
			TCCR0 = 0x0A;	//b00011001 CTC, 8분주, Disable OC0 toggle
			//OCR0 = 200;			//16MHz, 분주비 8일때 100us주기로 인터럽트 발생 
			OCR0 = 199;			//16MHz, 분주비 8일때 100us주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0xFC;			//OCF0, TOV0 Flag Clear
			TIMSK |= 0x02; 		//Timer0 OCIE0 Mask
			break;
		case TIMER_500uS:
			TCCR0 = 0x0B;	//b00011001 CTC, 32분주, Disable OC0 toggle
			//OCR0 = 250;			//16MHz, 분주비 1일때 500us주기로 인터럽트 발생 
			OCR0 = 249;			//16MHz, 분주비 1일때 500us주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0xFC;			//OCF0, TOV0 Flag Clear
			TIMSK |= 0x02; 		//Timer0 OCIE0 Mask
			break;
		case TIMER_1mS:
			TCCR0 = 0x0C;	//b00011001 CTC, 64분주, Disable OC0 toggle
			//OCR0 = 250;			//16MHz, 분주비 1일때 1ms주기로 인터럽트 발생 
			OCR0 = 249;			//16MHz, 분주비 1일때 1ms주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0xFC;			//OCF0, TOV0 Flag Clear
			TIMSK |= 0x02; 		//Timer0 OCIE0 Mask
			break;
		default:
			break;
	}
	sei();
}



void Timer0_Sound(unsigned char level)
{
	cli();
	if (level==0) {
		TCCR0 = 0x00;	//b00011001 CTC, 1분주, Disable OC0 toggle
		TIMSK &= 0xFC; 		//Timer0 OCIE0 Mask
		sei();
		return;
	}
	TCCR0 = 0x9D;	//b10011110 CTC, 128분주, Enable OC0 toggle
//	OCR0 = sound[level];			
	asm volatile("nop"::);
	TIFR &= 0xFC;			//OCF0, TOV0 Flag Clear
	TIMSK |= 0x02; 		//Timer0 OCIE0 Mask
	sei();
}

//----------------------------------------------------------------
//---------------------Timer1 설정-------------------------------- 
//----------------------------------------------------------------
void Timer1_Init(char mode)
{
	cli();
	switch (mode) {
		case TIMER_STOP:
			TCCR1A = 0x00;	//CTC(OCrnA)	
			TCCR1B = 0x00;	//bxxx01xxx: CTC, bxxxxx011:64분주
			TCCR1C = 0x00;	//NON FOC	
			TIMSK &= 0xC3; 		//Timer1 ALL INT Mask
			ETIMSK &= 0xFE; 	//Timer1 OCIE1C INT Mask
			break;
		case TIMER_2r5mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx010:64분주 
			OCR1AH = 0x02;	 
			OCR1AL = 0x70;	//70 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_3mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx010:64분주 
			OCR1AH = 0x02;	 
			OCR1AL = 0xED;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_4mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx010:64분주 
			OCR1AH = 0x03;	 
			OCR1AL = 0xE7;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_10mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx010:64분주 
			OCR1AH = 0x09;	 
			OCR1AL = 0xC3;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_40mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx011:64분주 
			OCR1AH = 0x27;	 
			OCR1AL = 0x0F;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_50mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx011:64분주 
			OCR1AH = 0x30;	 
			OCR1AL = 0xD3;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_100mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx011:64분주 
			OCR1AH = 0x61;	 
			OCR1AL = 0xA7;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_125mS:
			TCCR1B = 0x0B;	//bxxx01xxx: CTC, bxxxxx011:64분주 
			OCR1AH = 0x7A;	 
			OCR1AL = 0x11;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_250mS:
			TCCR1B = 0x0C;	//bxxx01xxx: CTC, bxxxxx011:256분주 
			OCR1AH = 0x3D;	 
			OCR1AL = 0x08;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_500mS:
			TCCR1B = 0x0C;	//bxxx01xxx: CTC, bxxxxx011:256분주 
			OCR1AH = 0x7A;	 
			OCR1AL = 0x11;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;
		case TIMER_1SEC:
			TCCR1B = 0x0D;	//bxxx01xxx: CTC, bxxxxx011:1024분주 
			OCR1AH = 0x3D;	 
			OCR1AL = 0x08;	 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIMSK |= 0x10; 		//Timer1 OCIE1A Mask
			break;

		default:
			break;
	}
	sei();
}

//----------------------------------------------------------------
//---------------------Timer2 설정-------------------------------- 
//----------------------------------------------------------------

void Timer2_Init(char mode)
{
	cli();
	switch (mode) {
		case TIMER_STOP:
			TCCR2 = 0x00;	//b00011001 CTC, 1분주, Disable OC0 toggle
			TIMSK &= 0x3F; 		//Timer2 OCIE2 Mask
			break;
		case TIMER_10uS:
			TCCR2 = 0x09;	//b00011001 CTC, 1분주, Disable OC0 toggle
			//OCR0 = 160;			//16MHz, 분주비 1일때 10us주기로 인터럽트 발생 
			OCR2 = 159;			//16MHz, 분주비 1일때 10us주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0x3F;			//OCF2, TOV2 Flag Clear
			TIMSK |=0x80; 		//Timer2 OCIE0 Mask
			break;
		case TIMER_100uS:
			TCCR2 = 0x0A;	//b00011001 CTC, 8분주, Disable OC0 toggle
			//OCR0 = 200;			//16MHz, 분주비 8일때 100us주기로 인터럽트 발생 
			OCR2 = 199;			//16MHz, 분주비 8일때 100us주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0x3F;			//OCF2, TOV2 Flag Clear
			TIMSK |= 0x80; 		//Timer2 OCIE2 Mask
			break;
		case TIMER_500uS:
			TCCR2 = 0x0B;	//b00011001 CTC, 64분주, Disable OC0 toggle
			//OCR0 = 250;			//16MHz, 분주비 1일때 500us주기로 인터럽트 발생 
			OCR2 = 124;			//16MHz, 분주비 1일때 500us주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0x3F;			//OCF2, TOV2 Flag Clear
			TIMSK |= 0x80; 		//Timer2 OCIE2 Mask
			break;
		case TIMER_1mS:
			TCCR2 = 0x0B;	//b00011001 CTC, 64분주, Disable OC0 toggle
			//OCR0 = 250;			//16MHz, 분주비 1일때 1ms주기로 인터럽트 발생 
			OCR2 = 249;			//16MHz, 분주비 1일때 1ms주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0x3F;			//OCF2, TOV2 Flag Clear
			TIMSK |= 0x80; 		//Timer2 OCIE2 Mask
			break;
		case TIMER_4mS:
			TCCR2 = 0x0C;	//b00011001 CTC, 256분주, Disable OC0 toggle
			//OCR0 = 250;			//16MHz, 분주비 1일때 1ms주기로 인터럽트 발생 
			OCR2 = 249;			//16MHz, 분주비 1일때 4ms주기로 인터럽트 발생 
			asm volatile("nop"::);
			asm volatile("nop"::);
			asm volatile("nop"::);
			TIFR &= 0x3F;			//OCF2, TOV2 Flag Clear
			TIMSK |= 0x80; 		//Timer2 OCIE2 Mask
			break;
		default:
			break;
	}
	sei();
}

