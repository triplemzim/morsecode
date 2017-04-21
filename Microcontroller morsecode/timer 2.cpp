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
	int input1,input2;
	input1 = 0;
	input2 = 0;
	PORTD = 0;
    while (1)
    {

		//if(bit_is_clear(PIND,0)){
			//PORTB = 0b00000001;
		//}
		//else{
			//PORTB = 0b00000000;
		//}
		if(TCNT1 >=10000){
			TCNT1 = 0;
			cnt++;

			if(cnt == 50){

				char n = PIND;
				if(1&n){
					PORTB = 0b00000001;
				}

			}
			if(cnt>=100){
				cnt = 0;
				PORTB = 0b00000000;
			}
			//if(1&n){
				//input1++;
				//input2=0;
			//}
			//else{
				//input1 = 0;
				//input2++;
			//}
			//if(cnt >=100){
				//cnt = 0;
				//
				//
				//
				//if(input1>=100){
					//PORTB = 0b00000001;
					//input1 = 0;
				//}
				//else if(input2>=100){
					//PORTB = 0b00000010;
					//input2 = 0;
				//}
			//}
		}

    }
}

