/*
 * TRAFFIC_OFF_FOR_PEOPLE.c
 *
 * Created: 6/9/2023 7:38:06 PM
 * Author : Kirollos Gerges
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "BUZZER.c"
typedef unsigned char u8;
int TRAFFIC_OFF_FOR_PEOPLE()
{
	 u8 counter_1=2;
  u8 counter_2=5;
// declaration 7 segments as an output module
 DDRC |=(1<<0);  
 DDRC |=(1<<1);
 DDRC |=(1<<2);
    DDRC |=(1<<3);
   DDRD |=(1<<0);
   DDRD |=(1<<1);
   DDRD |=(1<<2);
   DDRD |=(1<<3); 
   //initialize value 
 PORTC = 0x02;
 PORTD = 0x05;

{

	while(counter_2!=0)
	{
	PORTC=0X02;
	counter_2--;
	PORTD=counter_2;
	_delay_ms(810);
	 }
}
counter_2=10;
counter_1--;
PORTC=counter_1;
while(counter_2!=0)
{
PORTC=0X01;
counter_2--;
PORTD=counter_2;
_delay_ms(810);	
}
counter_2=10;
counter_1=0;
while(counter_2!=0)
{
	PORTC=0X00;
	counter_2--;
	PORTD=counter_2;
	_delay_ms(810);
	if(counter_2<=4)
	{
		operatingyellowLED();
		disableredLED();
BUZZER();
	}
}
PORTC=0X00;
PORTD=0x00;
disableyellowLED();



}