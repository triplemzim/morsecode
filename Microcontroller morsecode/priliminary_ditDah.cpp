/*
 * Timer2.cpp
 *
 * Created: 5/18/2016 12:21:35 AM
 * Author : Zim
 */

#include <avr/io.h>
#define ditTime 50
#define dahTime 100
#define darkTime 200


int main(void)
{
    DDRB = 0b00000111;
	DDRD = 0b00000000;
	PORTB = 0b00000000;

	TCCR1B |= 1<<CS10;
	int count = 0;
	int darkCount=0;

	PORTD = 1;

	//int ditFlag,dahFlag,darkFlag;


    while (1)
    {
		if(TCNT1 >=10000)
		{
			TCNT1 = 0;
			//count++;

			char n = PIND;

			if(bit_is_clear(PIND,0)==0)
			{
				count++;
				darkCount=0;
			}
			else
			{
				darkCount++;
				if(darkCount>=darkTime)
				{
					PORTB=0b00000100;
					//darkFlag=1;
				}

				else if (count>=ditTime && count<dahTime)
				{
					PORTB=0b00000001;
					//ditFlag=1;
				}

				else if(count>=dahTime)
				{
					PORTB=0b00000010;
					//dahFlag=1;
				}

				count=0;

			}

		}

    }
}


