//Projeto Final de Máquina Elétricas - Grupo 4
//CCM para controle de um motor CC

#include "mbed.h"

Serial pc(USBTX, USBRX);

InterruptIn b_ena(D8);
InterruptIn b_menu (D7);

Timer contador;

//Pinos de controle do motor CC
DigitalOut horario (D5);
DigitalOut anti (D4);
DigitalOut red (D9);
DigitalOut yel (D10);
DigitalOut green (D11);

PwmOut enable (D2);

AnalogIn rx (A3);
AnalogIn ry (A5);
AnalogIn pot (A0);

//Variáveis de controle
bool manual;
bool enabled;
bool menu;

float vel1;
float tempo_max;
float y;
float velocidade_motor;

char opcao;


//Enable do motor para controle manual
void toggle()
{
    enabled =! enabled;
    if (enabled == 1)
    {
        printf("\n\rENABLED");
    }
    else if (enabled == 0)
    {
        printf("\n\rUNABLED");
        
    }
    wait_ms(150);
}
//Variável de retorno para o menu principal
void back()
{
    menu =! menu;
    wait_ms(100);
}

//Comandos prontos
void foward()
{
    printf("\e[H\e[2J");
    printf("\n\r  Escolha o tempo de duracao da acao\n\r");
    scanf("%3f", &tempo_max);
    contador.reset();
    contador.start();
    horario = 0;
    anti = 0;
    printf("\r Girando por %3fs, controle minha velocidade\n", tempo_max);
    while(contador <= tempo_max)
    {
        vel1 = pot.read();//Leitura do potenciômetro
        velocidade_motor = 371.79*(12*vel1)-369.02;
        if (velocidade_motor >= 0)
        {
            printf("\r Velocidade horária do motor[RPM]= %2f", velocidade_motor);
        }
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
        velocidade_motor = 371.79*(12*vel1)-369.02;
        if (velocidade_motor >= 0)
        {
            printf("\r Velocidade anti-horária do motor[RPM]= %2f", velocidade_motor);
        }
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

    menu = 0;
    enabled = 0;

    b_ena.rise(&toggle);
    b_menu.rise(&back);

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
            red = 0;
            yel = 0;
            green = 0;
            enable.write(0);
            horario = 0;
            anti = 0;
            manual = 0;
            menu = 0;
            printf("\r Comandos prontos:\n");
            printf("\n");
            wait_ms(200);
            printf("\r   1. Press M para comandar manualmente\n\n");
            printf("\r   2. Press D para girar motor no sentido horario por determinado\n\n");
            printf("\r   3. Press A para girar motor no sentido anti-horario por tempo determinado\n\n");
            scanf("\r   %c", &opcao);
            switch (opcao)
            {
                case 'm': manual = 1;
                printf("\e[H\e[2J"); 
                printf("\r  Comando manual\n\n"); 
                break;
                case 'a': foward(); break;
                case 'd': backward(); break;
            }
        }

        // Comando manual do motor
        while (manual == 1)
        {
            //Enable desativado
            if (enabled == 0)
            {
                red = 1;
                yel = 0;
            }

            //Enable ativado
            else if (enabled == 1)
            {
                y = ry.read();
                yel = 1;
                red = 0;
                if (y >= 0.6) //Girar o motor
                {   
                    green = 1;
                    float girar = (y/0.4)-1.5;
                    enable.write(girar);
                    velocidade_motor = 371.79*(12*girar)-369.02;
                    if (velocidade_motor >= 0)
                    {
                        printf("\r  Velocidade anti-horária do motor[RPM]= %2f", velocidade_motor);
                    }
                    anti = 0;
                    horario = 1;
                }
                else if (y <= 0.4) //Girar o motor
                {
                    green = 1;
                    float girar = (-y/0.4)+1;
                    enable.write(girar);
                    velocidade_motor = 371.79*(12*girar)-369.02;
                    if (velocidade_motor >= 0)
                    {
                        printf("\r  Velocidade anti-horária do motor[RPM]= %2f", velocidade_motor);
                    }
                    horario = 0;
                    anti = 1;
                }
                else //Manter o motor parado
                {
                    printf("\r  Velocidade do motor[RPM]= 0");
                    green = 0;
                    anti.write(0);
                    horario.write(0);
                }
            }
            if (menu == 1)
            {
                manual = 0;
            }
        }
    }
}