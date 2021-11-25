//Projeto Final de Máquina Elétricas - Grupo 4
//CCM para controle de um motor brushless e um motor CC
#include "mbed.h"

Serial pc (USBTX, USBRX);

//Declaração PWM Ponte-H motor CC
PwmOut mos1 (D12);
PwmOut mos2 (D11);
PwmOut mos3 (D9);
PwmOut mos4 (D8);
//Declaração PWM controle motor de passo
PwmOut mos5 (D7);
PwmOut mos6 (D6);
PwmOut mos7 (D5);
PwmOut mos8 (D4);

//Variáveis de controle da IHM
bool m_cc = 0;
bool m_passo = 0;

bool enable = 0;

int ação = 0;




void toggle()//Função para incrementar dentes quando houver uma borda de subida
        {
            i =! i;
        }

//Declaração de portas e variáveis motor CC


int main()
{
    printf(\r"Bem vindo professor");
    wait(1.2);
    printf(\r"ao centro de comando");
    wait(1.2);
    printf(\r"do grupo 4");
    wait(1.2);
    printf(\r"Jonas Luis Leonardo (no Balkins)");
    wait(1.5);

    while(1) 
    {
        switch (pc.getc())
        {
            case 'a': m_cc = 1; break;
            case 'b': m_passo = 1; break; 
            default: break;
        }

        // Controle do motor CC
        if (m_cc == 1):
        {
            if (enable == 1)
            {
                if (ação == 0)
                {

                }

                else if (ação == 1 )
                {

                }

                else if (ação == 1 )
                {
                    
                }
            }
        }

        else if (m_passo == 1)
        {

        }
    }
}