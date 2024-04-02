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


#include <mega328.h>
#include <avr/io.h>

void init_timer(void) { 
    //mode operasi CTC, sumber clock prescaler 256 
    TCCR1A = 0; 
    TCCR1B = 0b00001100; 

    //overflow interrupt disable 
    TIMSK1 |=(0<<TOIE1); 
} 

void Delay(void) { 
    //Overflow interrupt enable 
    TIMSK1 |= (1<<TOIE1);

    //Counter start value 
    TCNT1H = 0; 
    TCNT1L = 0; 

    // as we choose 16MHz timer, clock freq will be 16M/256 = 62500 Hz
    // then the time for each tick is 1/F = 16us
    // number of count to get 1 second    -> 1000ms/16us = 62500
    // we need to substract with the maximum value to get the right timing 
    // as Timer1 is a 16-bit timer which is 2^16, the maximum value is 65535, 
    // hence period = 65535-62500 = 3035
    //Set OCR value for 1 Hz 
    OCR1AH = 0x7A; 
    OCR1AL = 0x12; 

    //Compare Match TCNT1 dan OCR1A 
    loop_until_bit_is_set(TIFR1,OCF1A); 
    //Reset Flag
    TIFR1 |= (1<<OCF1A);
    //overflow interrupt disable 
    TIMSK1 |= (0<<TOIE1); 
}

void main(void) {
    DDRD = 0xFF;                        // All PORTD is an output
    PORTD = 0b00001111;                 // Initial led condition
    
    while (1){
        init_timer();                   // Start the timer
        PORTD = 0b00001111;
        Delay();
        PORTD = 0b11110000;     
        Delay();                        
    }
}


/*=================================================
Code Alternatives


    int flag, rep;

    while (1){
        init_timer();                   // Start the timer
        Delay();                        // Create a delay for timer
        if (flag == 1){
            if (rep==1){
                PORTD = 0b00001111;
                rep=0;
            } else{
                PORTD = 0b11110000;
                rep++;
            }

            flag = 0;
        } 
    }

=================================================*/
    
