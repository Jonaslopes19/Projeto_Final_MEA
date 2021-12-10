//Projeto Final de Máquina Elétricas - Grupo 4
//CCM para controle de Step Motor

#include "mbed.h"

Serial pc(USBTX, USBRX);

InterruptIn b_ena(D8);
InterruptIn b_menu (D7);

// Motor_passo
// Bobinas
DigitalOut B(A0);
DigitalOut B_(A1);
DigitalOut A_(D4);
DigitalOut A(D5);

// Sinais
DigitalOut red (D9);
DigitalOut yel (D10);
DigitalOut green (D11);

//Pinagem
// Enables dos motores
PwmOut en_b(A4);
PwmOut en_a(D2);

AnalogIn pot (A3);
AnalogIn ry (A5);

//Variáveis de controle
bool manual;
bool enabled;
bool menu;

float vel1;
float y;
float girar;
float velocidade_motor;

int passos;
int passos_max;

char opcao;


//Enable do motor para controle manual
void toggle()
{
    enabled =! enabled;
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
    passos = 0;
    printf("\e[H\e[2J");
    printf("\n\rEscolha o número de passos para andar\n\r");
    scanf("%5d", &passos_max);
    printf("\r Girando por %3f passos, controle minha velocidade\n\n", passos_max);
    while(passos <= passos_max)
    {
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        //Comando do motor
        // Passo 1
        A = 1;
        B = 0;
        A_ = 0;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        // Passo 2
        A = 1;
        B = 1;
        A_ = 0;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        // Passo 3
        A = 0;
        B = 1;
        A_ = 0;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        // Passo 4
        A = 0;
        B = 1;
        A_ = 1;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        // Passo 5
        A = 0;
        B = 0;
        A_ = 1;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        // Passo 6
        A = 0;
        B = 0;
        A_ = 1;
        B_ = 1;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        // Passo 7
        A = 0;
        B = 0;
        A_ = 0;
        B_ = 1;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        // Passo 8
        A = 1;
        B = 0;
        A_ = 0;
        B_ = 1;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
    }
    wait(0.1);
    B = 0;
    B_ = 0;
    A_ = 0;
    A = 0;
}

void backward()
{   
    passos = 0;
    printf("\e[H\e[2J");
    printf("\n\rEscolha o número de passos para andar\n\r");
    scanf("%5d", &passos_max);
    printf("\r Girando por %3fs, controle minha velocidade\n", passos_max);
    while(passos <= passos_max)
    {
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        //Comando do motor
        // Passo 8
        A = 1;
        B = 0;
        A_ = 0;
        B_ = 1;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        // Passo 7
        A = 0;
        B = 0;
        A_ = 0;
        B_ = 1;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        // Passo 6
        A = 0;
        B = 0;
        A_ = 1;
        B_ = 1;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        // Passo 5
        A = 0;
        B = 0;
        A_ = 1;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        // Passo 4
        A = 0;
        B = 1;
        A_ = 1;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        // Passo 3
        A = 0;
        B = 1;
        A_ = 0;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        // Passo 2
        A = 1;
        B = 1;
        A_ = 0;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
        vel1 = 1+499*pot.read();//Leitura do potenciômetro
        velocidade_motor = 1000/vel1;
        // Passo 1
        A = 1;
        B = 0;
        A_ = 0;
        B_ = 0;
        passos = passos + 1;
        if (passos > passos_max)
        {
            break;
        }
        wait_ms(vel1);
    }
    wait(0.1);
    B = 0;
    B_ = 0;
    A_ = 0;
    A = 0;
}

//Rotina principal
int main()
{
    //Estados iniciais
    en_b.write(0.9);
    en_a.write(0.9);

    B = 0;
    B_ = 0;
    A_ = 0;
    A = 0;

    manual = 0;

    menu = 0;
    enabled = 0;

    b_ena.rise(&toggle);
    b_menu.rise(&back);

    passos = 0;

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
            B = 0;
            B_ = 0;
            A_ = 0;
            A = 0;
            red = 0;
            yel = 0;
            green = 0;
            manual = 0;
            menu = 0;
            printf("\r Comandos prontos:\n");
            printf("\n");
            wait_ms(200);
            printf("\r   1. Press M para comandar manualmente\n\n");
            printf("\r   2. Press D para girar motor no sentido horario por x/400 passos\n\n");
            printf("\r   3. Press A para girar motor no sentido anti-horario por x/400 passos\n\n");
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

        while (manual == 1)
        {
            
            if (enabled == 0)
            {
                red = 1;
                yel = 0;
            }

            else if (enabled == 1)
            {
                y = ry.read();
                yel = 1;
                red = 0;
                while (y >= 0.6) //Girar o motor
                {
                    green = 1;
                    // Passo 1
                    A = 1;
                    B = 0;
                    A_ = 0;
                    B_ = 0;
                    if (y < 0.58)
                    {
                        break;
                    }
                    wait_ms(girar);
                    // Passo 2
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                    A = 1;
                    B = 1;
                    A_ = 0;
                    B_ = 0;
                    if (y < 0.58)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                    // Passo 3
                    A = 0;
                    B = 1;
                    A_ = 0;
                    B_ = 0;
                    if (y < 0.58)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                    // Passo 4
                    A = 0;
                    B = 1;
                    A_ = 1;
                    B_ = 0;
                    wait_ms(girar);
                    if (y < 0.58)
                    {
                        break;
                    }
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                    // Passo 5
                    A = 0;
                    B = 0;
                    A_ = 1;
                    B_ = 0;
                    wait_ms(girar);
                    if (y < 0.58)
                    {
                        break;
                    }
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                    // Passo 6
                    A = 0;
                    B = 0;
                    A_ = 1;
                    B_ = 1;
                    if (y < 0.58)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                    // Passo 7
                    A = 0;
                    B = 0;
                    A_ = 0;
                    B_ = 1;
                    if (y < 0.58)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                    // Passo 8
                    A = 1;
                    B = 0;
                    A_ = 0;
                    B_ = 1;
                    if (y < 0.58)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1248.5-1247.5*y;
                    velocidade_motor = 1000/girar;
                }
                while (y <= 0.4) //Girar o motor
                {
                    green = 1;
                    // Passo 8
                    A = 1;
                    B = 0;
                    A_ = 0;
                    B_ = 1;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                    // Passo 7
                    A = 0;
                    B = 0;
                    A_ = 0;
                    B_ = 1;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                    // Passo 6
                    A = 0;
                    B = 0;
                    A_ = 1;
                    B_ = 1;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                    // Passo 5
                    A = 0;
                    B = 0;
                    A_ = 1;
                    B_ = 0;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                    // Passo 4
                    A = 0;
                    B = 1;
                    A_ = 1;
                    B_ = 0;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                    // Passo 3
                    A = 0;
                    B = 1;
                    A_ = 0;
                    B_ = 0;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                    // Passo 2
                    A = 1;
                    B = 1;
                    A_ = 0;
                    B_ = 0;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                    // Passo 1
                    A = 1;
                    B = 0;
                    A_ = 0;
                    B_ = 0;
                    if (y > 0.42)
                    {
                        break;
                    }
                    wait_ms(girar);
                    y = ry.read();
                    girar = 1+1247.5*y;
                    velocidade_motor = 1000/vel1;
                }
                if (y < 0.6 || y > 0.4) //Manter o motor parado
                {
                    green = 0;
                    B = 0;
                    B_ = 0;
                    A_ = 0;
                    A = 0;

                }
            }
            if (menu == 1)
            {
                manual = 0;
            }
        }
    }
}