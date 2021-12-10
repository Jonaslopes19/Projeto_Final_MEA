//Projeto Final de Máquina Elétricas - Grupo 4
//CCM para controle de um motor CC
#include "mbed.h"

Serial pc(USBTX, USBRX);

InterruptIn b_ena(D8);

Timer contador;

//Pinos de controle do motor CC
DigitalOut horario (D5);
DigitalOut anti (D4);
DigitalOut red (D9);
DigitalOut yel (D10);
DigitalOut green (D11);

DigitalIn b_menu (D7);

PwmOut enable (D2);

AnalogIn rx (A3);
AnalogIn ry (A5);
AnalogIn pot (A0);

//Variáveis de controle
bool manual;
bool enabled;

float vel1;
float tempo_max;

char opcao;



void toggle()
{
    enabled =! enabled;
    if (enabled == 1)
    {
        printf("\n\rENABLED")
    }
    else if (enabled == 0)
    {
        printf("\n\rUNABLED")
    }
    
}

//Comandos prontos
void foward()
{
    printf("\e[H\e[2J");
    printf("\n\rEscolha o tempo de duracao da acao\n\r");
    scanf("%3f", &tempo_max);
    contador.reset();
    contador.start();
    horario = 0;
    anti = 0;
    printf("\r Girando por %3fs, controle minha velocidade\n", tempo_max);
    while(contador <= tempo_max)
    {
        vel1 = pot.read();//Leitura do potenciômetro
        printf("\r leitura= %3f", vel1);
        enable.write(vel1);
        horario = 1;
        anti = 0;
    }
    wait(0.1);
    horario = 0;
    anti = 0;
    contador.reset();
}

void backward()
{   
    printf("\e[H\e[2J");
    printf("\n\rEscolha o tempo de duracao da acao\n\r");
    scanf("%3f", &tempo_max);
    contador.reset();
    contador.start();
    horario = 0;
    anti = 0;
    printf("\r Girando por %3fs, controle minha velocidade\n", tempo_max);
    while(contador <= tempo_max)
    {
        vel1 = pot.read();//Leitura do potenciômetro
        printf("\r leitura= %3f", vel1);
        enable.write(vel1);
        horario = 0;
        anti = 1;
    }
    wait(0.1);
    horario = 0;
    anti = 0;
    contador.reset();
}


//Rotina principal
int main()
{
    //Estados iniciais
    
    enable.write(0);
    horario = 0;
    anti = 0;
    manual = 0;

    enabled = 0;
    b_ena.rise(&toggle);

    //Introdução
    printf("\e[H\e[2J");
    printf("\r Bem vindo professor ");
    wait(1);
    printf("ao centro de comando ");
    wait(1);
    printf("do grupo 4\n");
    wait(1.5);
    printf("\r Jonas  Felps    Leonardo          (no Balkins)\n");
    wait(1.5);
    printf("\n");
    
    while(1)
    {
        while (manual == 0)
        {
            printf("\e[H\e[2J");
            enable.write(0);
            horario = 0;
            anti = 0;
            manual = 0;
            printf("\r Comandos prontos:\n");
            printf("\n");
            wait_ms(200);
            printf("\r   1. Press M para comandar manualmente\n\n");
            printf("\r   2. Press D para girar motor no sentido horario por 10s\n\n");
            printf("\r   3. Press A para girar motor no sentido anti-horario por 10s\n\n");
            switch (pc.getc())
            {
                case 'm': manual = 1; break;
                case 'a': foward(); break;
                case 'd': backward(); break;
            }
        }

        while (manual == 1)
        {
            printf("\e[H\e[2J");
            printf("\r Comando manual\n")
            y = ry.read();

            while (enabled == 0)
            {
                red = 1;
            }

            while (enabled == 1)
            {
                printf("\r valor y = %2f", y);

                if (y >= 0.6) //Girar o motor
                {
                    float girar = (y/0.4)-1.5;
                    enable.write(girar);
                    anti = 1;
                    horario = 0;
                }
                else if (y <= 0.4) //Girar o motor
                {
                    
                    float girar = (y/0.4)-1.5;
                    enable.write(girar);
                    horario = 0;
                    anti = 1;
                }
                
                else //Manter o motor parado
                {
                    
                    anti.write(0);
                    horario.write(0);
                }
            }

        }

    }
}