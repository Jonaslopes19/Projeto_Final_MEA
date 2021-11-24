//Projeto Final de Máquina Elétricas - Grupo 4
//CCM para controle de um motor brushless e um motor CC

#include "mbed.h"

InterruptIn User (USER_BUTTON);

PwmOut IN_1 (PA_8); // pinos para PWM
PwmOut IN_2 (PA_9);
PwmOut IN_3 (PA_10);
DigitalOut EN_1 (PC_10); // pinos ENABLE
DigitalOut EN_2 (PC_11);
DigitalOut EN_3 (PC_12);

AnalogIn pot(PB_1);

double tempo;
int controle;
float pwm = 0.8;
bool i = 0;

void toggle(void);// Protótipo de função


int main()
{
    // configurações iniciais
    IN_1.period_ms(1); 
    IN_2.period_ms(1); 
    IN_3.period_ms(1); 
    EN_1 = 2; // Braço A
    EN_2 = 2; // Braço B
    EN_3 = 2; // Braço C
    
    User.rise(&toggle);
    
    while(1) 
    {
        tempo = 10-(8*(1-pot.read()));
        
        if (i == 1)
        {
            //Estado 1
            EN_1 = 2;
            EN_2 = 0;
            EN_3 = 1;
            IN_1.write(0);
            IN_2.write(pwm);
            IN_3.write(pwm);
            wait_ms(tempo);   
            
            //Estado 2
            EN_1 = 1;
            EN_2 = 0;
            EN_3 = 2;
            IN_1.write(0);
            IN_2.write(0);
            IN_3.write(pwm);
            wait_ms(tempo);
            
            //Estado 3
            EN_1 = 1;
            EN_2 = 2;
            EN_3 = 0;
            IN_1.write(pwm);
            IN_2.write(0);
            IN_3.write(pwm);
            wait_ms(tempo);
            
            //Estado 4
            EN_1 = 2; 
            EN_2 = 1; 
            EN_3 = 0; 
            IN_1.write(pwm); 
            IN_2.write(0); 
            IN_3.write(0); 
            wait_ms(tempo);
            
            //Estado 5
            EN_1 = 0; 
            EN_2 = 1; 
            EN_3 = 2; 
            IN_1.write(pwm); 
            IN_2.write(pwm);
            IN_3.write(0);
            wait_ms(tempo);
            
            //Estado 6
            EN_1 = 0; 
            EN_2 = 2; 
            EN_3 = 1; 
            IN_1.write(0); 
            IN_2.write(pwm); 
            IN_3.write(0);
            wait_ms(tempo);
        }
    }
}

void toggle()//Função para incrementar dentes quando houver uma borda de subida
        {
            i =! i;
        }