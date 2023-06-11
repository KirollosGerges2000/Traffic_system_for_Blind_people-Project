/*
 * Traffic system for blind.c
 *
 * Created: 6/10/2023 4:08:49 PM
 * Author : Kirollos Gerges
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "MACROS.h"
#include "TRAFFIC_ON_FOR_CARS.c"
#include "TRAFFIC_OFF_FOR_PEOPLE.c"
#include "operating LEDs.c"
#include "interrupt.c"
#include <avr/interrupt.h>
typedef unsigned char u8;

int main(void)
{
	while (1) 
    {
	operatingredLED();
		TRAFFIC_OFF_FOR_PEOPLE();    //In part 2 will be interrupt
	   disableredLED();
	   operatinggreenLED();
	TRAFFIC_ON_FOR_CARS();
		disablegreenLED();
		
		
    }
	
}

