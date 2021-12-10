#include "mbed.h"

//Pinagem
PwmOut en_b(A4);
PwmOut en_a(D2);

DigitalOut B(A0);
DigitalOut B_(A1);
DigitalOut A_(D4);
DigitalOut A(D5);

//Variáveis do programa
float tempo;
float pwm = 1;


int main()
{
    //Estados iniciais
    en_b.write(0.9);
    en_a.write(0.9);

    B = 0;
    B_ = 0;
    A_ = 0;
    A = 0;

    tempo = 1;

    while(1)
    {
        // Passo 1
        A = 1;
        B = 0;
        A_ = 0;
        B_ = 0;
        wait_ms(tempo);
        // Passo 2
        A = 1;
        B = 1;
        A_ = 0;
        B_ = 0;
        wait_ms(tempo);
        // Passo 3
        A = 0;
        B = 1;
        A_ = 0;
        B_ = 0;
        wait_ms(tempo);
        // Passo 4
        A = 0;
        B = 1;
        A_ = 1;
        B_ = 0;
        wait_ms(tempo);
        // Passo 5
        A = 0;
        B = 0;
        A_ = 1;
        B_ = 0;
        wait_ms(tempo);
        // Passo 6
        A = 0;
        B = 0;
        A_ = 1;
        B_ = 1;
        wait_ms(tempo);
        // Passo 7
        A = 0;
        B = 0;
        A_ = 0;
        B_ = 1;
        wait_ms(tempo);
        // Passo 8
        A = 1;
        B = 0;
        A_ = 0;
        B_ = 1;
        wait_ms(tempo);
    }
}
