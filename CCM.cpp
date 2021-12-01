//Projeto Final de Máquina Elétricas - Grupo 4
//CCM para controle de um motor CC
#include "mbed.h"

Serial pc(USBTX, USBRX);

//Pinos de controle do motor CC
PwmOut horario (D5);
PwmOut anti (D4);

AnalogIn vrx(A3);
AnalogIn vry(A5);

DigitalIn en_a(D2);

//Pinos PWM não usados
/*
PwmOut mos3 (D9);
PwmOut mos4 (D8);
//Declaração PWM controle motor de passo
PwmOut mos5 (D7);
PwmOut mos6 (D6);
PwmOut mos7 (D5);
PwmOut mos8 (D4);

*/
//Variáveis de controle da IHM
int manual = 0;
/*
void toggle()//Função para incrementar dentes quando houver uma borda de subida
      {
            i =! i;
        }
*/
//Declaração de portas e variáveis motor CC


int main()
{
    printf("\r Bem vindo professor ");
    wait(1);
    printf("ao centro de comando ");
    wait(1);
    printf("do grupo 4\n");
    wait(2);
    printf("\r Jonas  Felps    Leonardo          (no Balkins)\n");
    wait(2);
    printf("\n");

    while(1) 
    {
        if (manual == 0)
        {
            printf("\r Comandos prontos:\n");
            printf("\n");
            wait_ms(200);
            printf("\r   1. Press M para comandar manualmente\n\n");
            printf("\r   2. Press D para girar motor no sentido horario por 5s\n\n");
            printf("\r   3. Press A para girar motor no sentido anti-horario por 5s\n\n");
        }

        else if (manual == 1)
        {
            printf("\rcerto");
            //float x = vrx.read()*1000;
            //printf("\r %2f", x);
        }
        
        switch (pc.getc())
        {
            case 'm': manual = 1; break;
            default: break;
        }
    }
}