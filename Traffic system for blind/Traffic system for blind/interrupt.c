#include <avr/io.h>
#include "MACROS.h"
void ISR(void)
{
	DDRB &=~((1<<0));
	if(INPUT_BIT(PINB,0))
	{
		TRAFFIC_OFF_FOR_PEOPLE();
		
	}
}