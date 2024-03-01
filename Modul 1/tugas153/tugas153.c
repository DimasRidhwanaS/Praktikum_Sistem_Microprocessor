#include <mega328.h>
#include <avr/io.h>

void init_timer(void) { 
    //mode operasi CTC, sumber clock prescaler 256 
    TCCR1A = 0; 
    TCCR1B = 0b0000XXXX; 

    //overflow interrupt disable 
    TIMSK1 |=(0<<TOIE1); 
} 

void Delay(void) { 
    //Overflow interrupt enable 
    TIMSK1 |= (1<<TOIE1);

    //Counter start value 
    TCNT1H = 0; 
    TCNT1L = 0; 

    //Set OCR value for 1 Hz 
    OCR1AH = 0xHH; 
    OCR1AL = 0xHH; 

    //Compare Match TCNT1 dan OCR1A 
    loop_until_bit_is_set(TIFR1,OCF1A); 
    //Reset Flag
    TIFR1 |= (1<<OCF1A);
    //overflow interrupt disable 
    TIMSK1 |= (0<<TOIE1); 
}



void main(void) {



    /*=================================================
    Fungsi delay
    - get initial_time = t0
    - get current_time = t1

    if (t1-t0 < 500){
    flag = 0;
    } else {
    flag = 1;
    }

    - fungsi lanjut kalau flag 1



    =================================================*/


    /*=================================================
    Tuliskan Kode Program yang membuat output flip flop 
    LED dengan pola 4 bit. Jeda antar flip flop sebesar
    500 ms. DILARANG MENGGUNAKAN FUNGSI delay_ms() unt-
    -uk menghasilkan jeda, gunakan fungsi Delay() untuk 
    menghasilkan jeda. Ilustrasi output sebagai berikut
    0 0 0 0 X X X X X = ON
    X X X X 0 0 0 0 0 = OFF
    0 0 0 0 X X X X
    X X X X 0 0 0 0
    dan seterusnya...
    =================================================*/

    DDRD = 0xFF;                        // All PORTD is an output
    PORTD = 0b00001111;                 // Initial led condition
    int flag, rep;

    while (1){
        init_timer();                   // Start the timer
        Delay();                        // Create a delay for timer
        if (flag == 1){
            if (rep==1){
                PORTD = (PORTD << 4);
                rep=0;
            } else{
                PORTD = (PORTD >> 4);
                rep++;
            }

            flag = 0;
        } 
    }



}
