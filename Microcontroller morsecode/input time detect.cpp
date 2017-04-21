/*
 * Timer2.cpp
 *
 * Created: 5/18/2016 12:21:35 AM
 * Author : Zim
 */

#include <avr/io.h>


int main(void)
{
    DDRB = 0b00000011;
	DDRD = 0b00000000;
	PORTB = 0b00000000;
	TCCR1B |= 1<<CS10;
	int cnt = 0;
	int lightInput,darkInput;
	lightInput = 0;
	darkInput = 0;
	PORTD = 1;

	int scndCount=0;
	int blinkFlag=0;
	int darkFlag=0;

    while (1)
    {
		if(TCNT1 >=10000)
		{
			TCNT1 = 0;
			cnt++;

			char n = PIND;
			if(bit_is_clear(PIND,0)==0)
			{
				lightInput++;
				darkInput=0;
			}
			else
			{
				darkInput++;
				lightInput=0;
			}

			if (blinkFlag)
			{
				if(cnt>=100)
				{
					PORTB=~PORTB;
				}
			}

			if (darkFlag)
			{
				PORTB=0;
			}

			if(cnt>=100)
			{
				cnt=0;
			}


			if (lightInput>=290)
			{
				blinkFlag=1;
				darkFlag=0;
				lightInput=0;
			}

			if(darkInput>=290)
			{
				blinkFlag=0;
				darkFlag=1;
				darkInput=0;
			}

			//scndCount=0;


		}

    }
}

