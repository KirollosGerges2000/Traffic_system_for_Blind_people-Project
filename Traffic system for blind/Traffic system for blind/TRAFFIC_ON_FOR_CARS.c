/*
 * 7 segment.c
 *
 * Created: 6/9/2023 7:38:06 PM
 * Author : Kirollos Gerges
 */ 
#include <avr/io.h>
#include <util/delay.h>
typedef unsigned char u8;
int TRAFFIC_ON_FOR_CARS(void)
{
u8 counter_1 =9;
u8 counter_2 =10;
// declaration 7 segments as an output module
 DDRC |=(1<<0);  
 DDRC |=(1<<1);
 DDRC |=(1<<2);
    DDRC |=(1<<3);
   DDRD |=(1<<0);
   DDRD |=(1<<1);
   DDRD |=(1<<2);
   DDRD |=(1<<3); 
 PORTC = 0x09;
 PORTD = 0x09;
while(counter_1!=0 && counter_2!=0)
	{ 
		counter_2--;
		PORTD=counter_2;
			
		_delay_ms(810); //delay time for counting
	if( PORTD == 0x00)
	{counter_2=10;
		counter_1--;
		PORTC=counter_1;
		}
		
	}
	counter_2=10;
	while(counter_2!=0)
	{
		PORTC = 0x00;
counter_2--;
PORTD=counter_2;
if(counter_2<=4)
{
	disablegreenLED();
	operatingyellowLED();
BUZZER();
	
}


_delay_ms(810); //delay time for counting
	}
disableyellowLED();
operatingredLED();

}
