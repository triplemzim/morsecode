
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd2.h"
int main(void)
{
InitializeMrLCD();

char positionString[4];

while(1)
{
for(int y = 1; y<=4; y++)
{
for(int x = 1;x<=20;x++)
{
itoa(x, positionString, 10);
GotoMrLCDsLocation(12, 3);
Send_A_String("X = ");
Send_A_String(positionString);

itoa(y, positionString, 10);
GotoMrLCDsLocation(12, 4);
Send_A_String("Y = ");
Send_A_String(positionString);

GotoMrLCDsLocation(x, y);
Send_A_String("x");
_delay_ms(50);

GotoMrLCDsLocation(x, y);
Send_A_String(" ");

itoa(x, positionString, 10);
GotoMrLCDsLocation(12, 3);
Send_A_String(" ");

itoa(y, positionString, 10);
GotoMrLCDsLocation(12, 4);
Send_A_String(" ");
}
}
}
}
