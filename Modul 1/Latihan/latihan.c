#include <mega328p.h>
#include <delay.h>

int i;

void main(void)
{
    DDRD |= (1<<DDD4);                    // Using PD4      -> 0b00010000 

while (1)
      {         
        PORTD |= (1<<PORTD4);             // setting High   -> 00010000
        delay_ms(100);
        PORTD &= ~(1<<PORTD4);         
      //   PORTD = 0x00;                     // setting Low    -> 00000000
        delay_ms(100);
      }
}
