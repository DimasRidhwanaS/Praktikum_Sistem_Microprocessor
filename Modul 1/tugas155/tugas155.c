/*=================================================
Tuliskan Kode Program yang output looping nyala LED
dengan interupsi setiap push button ditekan. Output
looping LED memiliki pola flip-flop yang sama deng-
an tugas 1.5.3. Setiap push button ditekan, akan terj-
adi interrupt dimana semua LED mati selama 250 ms.
Berikut merupakan contoh perilaku.
0 0 0 0 X X X X X = ON
X X X X 0 0 0 0 0 = OFF
0 0 0 0 X X X X
*interrupt push button*
0 0 0 0 0 0 0 0
*setelah 250 ms interrupt selesai*
X X X X 0 0 0 0
0 0 0 0 X X X X
X X X X 0 0 0 0
dan seterusnya...
=================================================*/


#include <mega328p.h>
#include <delay.h>
#include <avr/interrupt.h>

int state;

interrupt [EXT_INT0] void ext_int0_isr(void) {
    state++;
}

void main(void) {
    //SET MODE PIN D, PIN D2 = INPUT, SISANYA OUTPUT
    DDRB = 0xFF;        // setting all LED as an output
    // sei();              // Global Interrupt Enable bit
    #asm("sei")

    //ENABLE INT0
    EIMSK = (1<<INT0);    // Enabling interrupt

    //SET FALLING EDGE PADA INT0
    EICRA= (0<<ISC11)|(0<<ISC10)|(1<<ISC01)|(0<<ISC00);     
        // ISC11 and ISC10 is for INT1  -> PD3
        // ISCi1 and ISC00 is for INT0  -> PD2

    //SET INT0 FLAG
    EIFR=(0<<INTF1) | (1<<INTF0);

    while (1) {
        if (state%2==0){
            delay_ms(250);
            PORTB = 0b11110000;
        } else {
            delay_ms(250);
            PORTB = 0b00001111;
        }
    }
}