/*
/////////////////// DATOS DEL PROGRAMA ////////////////////
//  TTITULO: Sequence of operation
//  MICRO:PIC16F15244
//  ESTUDIANTES: Juan Felipe Reyes - 2420191049
 *               Juan Jose Hernadez - 2420291052
//  Profesor: Harold Fabian Murcia
//  FECHA: May 27, 2021
///////////// CONFIGURACION del MCU ////////////////// */


#include "mcc_generated_files/mcc.h"

void main(void)
{
    EUSART1_Initialize();
    SYSTEM_Initialize();
    printf("INICIO \n\r");

    while (1)
    {

       ////////Macro to turn right////////

        printf("El dispositivo est� girando a la derecha \n\r");
        IO_RB4_SetHigh();
        IO_RB6_SetLow();
        IO_RB7_SetLow();
        IO_RC4_SetLow();
        IO_RC5_SetHigh();
        IO_RC6_SetHigh();
        IO_RC7_SetLow();
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r");
        ////////Macro to turn left////////

        printf("El dispositivo est� girando a la izquierda \n\r");
        IO_RB4_SetLow();
        IO_RB6_SetHigh();
        IO_RB7_SetLow();
        IO_RC4_SetHigh();
        IO_RC5_SetLow();
        IO_RC6_SetLow();
        IO_RC7_SetHigh();
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r");
        ////////Macro to advance////////

        printf("El Dispositivo est� avanzando \n\r");
        IO_RB4_SetHigh();
        IO_RB6_SetLow();
        IO_RB7_SetLow();
        IO_RC4_SetHigh();
        IO_RC5_SetLow();
        IO_RC6_SetLow();
        IO_RC7_SetLow();
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r");
        ////////Macro to go back////////

        printf("El Dispositivo est� retrocediendo \n\r");
        
        IO_RB4_SetLow();
        IO_RB6_SetHigh();
        IO_RB7_SetHigh();
        IO_RC4_SetLow();
        IO_RC5_SetHigh();
        IO_RC6_SetHigh();
        IO_RC7_SetHigh();
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r");
                ////////Macro to stop////////

        printf("El Dispositivo est� detenido \n\r");
        IO_RB4_SetLow();
        IO_RB6_SetLow();
        IO_RB7_SetHigh();
        IO_RC4_SetLow();
        IO_RC5_SetLow();
        IO_RC6_SetLow();
        IO_RC7_SetLow();
        __delay_ms(1000);
        printf("---------------------------------------------- \n\r");
    }
}

