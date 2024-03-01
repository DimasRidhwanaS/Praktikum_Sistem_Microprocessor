 /*=================================================
    Tuliskan Kode Program yang output looping nyala LED
    dengan interupsi setiap 1 detik. Output looping LED
    memiliki pola berulang dengan jeda 100 ms dengan i-
    -lustrasi sebagai berikut.
    X 0 X 0 X 0 X 0 X = ON
    0 X 0 X 0 X 0 X 0 = OFF
    X 0 X 0 X 0 X 0
    0 X 0 X 0 X 0 X
    dan seterusnya...
    Kemudian akan terjadi interrupt yang terjadi setiap
    1 detik. Interrupt akan menghasilkan output berupa
    semua LED menyala selama 1 detik.
    *interrupt terjadi*
    X X X X X X X X 
    *1 detik berlalu*
    interrupt selesai
    =================================================*/
    
    /*
    Design Implementation
    - Using Timer1 
    
    */

#include <mega328.h>
#include <io.h>
#include <interrupt.h>
#include <delay.h>

//SET COUNT VALUE FOR 1 HZ
#define TCNT_HIGH 0x00      // This contains the upper 8 bit
#define TCNT_LOW 0x00       // This contains the lower 8 bit

int state;


void init_int(void) {
    TIMSK1 |= (1<<TOIE1);

    // Set timer mode to "Normal"
    TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));
    TCCR1B &= (~(1<<WGM12)) & (~(1<<WGM13));

    // Choosing the prescaller into 1024
    TCCR1B |= (1<<CS12) | (1<<CS10);
    TCCR1B &= ~(1<<CS11);
    TCCR1A |= (1<<COM1A0);
    TCCR1A &= ~(1<<COM1A1);

    // Load period to get 1 second clock
        // as we choose 16MHz timer, clock freq will be 16M/1024 = 15625 Hz
        // then the time for each tick is 1/F = 64us
        // number of count to get 1000ms    -> 1000ms/64us = 15625
        // we need to substract with the maximum value to get the right timing 
        // as Timer1 is a 16-bit timer which is 2^16, the maximum value is 65535, 
        // hence period = 65535-15625 = 49910
    // Initial timer start value
    TCNT1H = TCNT_HIGH;      // This one probably needs to be defined as TNCTH and TNCTL
    TCNT1L = TCNT_LOW;
    
    // Timer Period
    OCR1AH = 0x3D;
    OCR1AL = 0x09;


    #asm("sei")         // if this doesnt work, we can manually set up the global interrupt enable

    //-------------------------------------------------------------------------------------------------
    //set prescaler 1024
    // TIMSK1=0b000000; 
    // TCCR1B=0b0000XXXX; 

    // TCNT1H=TCNT_HIGH; 
    // TCNT1L=TCNT_LOW; 

    //Enable Interrupt
    // #asm("sei")         // if this doesnt work, we can manually set up the global interrupt enable
}

interrupt [TIM1_OVF] void timer1_ovf_isr(void) { 
    TCNT1H = TCNT_HIGH;
    TCNT1L = TCNT_LOW;
    OCR1AH = 0x3D;
    OCR1AL = 0x09;
    state++;
}

void main(void) {
    init_int(); 
    while (1) {
        PORTB = 0b10101010;
        delay_ms(100);
        PORTB = 0b01010101;
        delay_ms(100);
        
    }
}