#include "lcd.h"


int main(void)

{
	InitializeMrLCD();

	while(1)
	{
       for(int y = 1; y<=2; y++)
        {
            for(int x = 1; x<=16; x++)
            {

                GotoMrLCDsLocation(x, y);
				Send_A_Character('A');
				//Send_A_String("x");
                _delay_ms(50);

            }
        }

	}

}

