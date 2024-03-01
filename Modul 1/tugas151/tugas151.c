#include <mega328p.h>
#include <delay.h>

int i;

void main(void)
{
    DDRD |= (1<<DDD4);                    // Using PD4      -> 0b00010000 

while (1)
      {         
        PORTD = 0b00000001;
        delay_ms(100);
        PORTD = 0b00000010;          
        delay_ms(100);
        PORTD = 0b00000100;     
        delay_ms(100);
        PORTD = 0b00001000;     
        delay_ms(100);
        PORTD = 0b00010000;  
        delay_ms(100);
        PORTD = 0b00100000;  
        delay_ms(100);
        PORTD = 0b01000000;  
        delay_ms(100);
        PORTD = 0b10000000;
        delay_ms(100);
      }
}
