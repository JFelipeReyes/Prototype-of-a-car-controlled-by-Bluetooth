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
    printf("INICIO SECUENCIA \n\r");

    while (1)
    {

       ////////Macro to turn right////////

        printf("El dispositivo esta girando a la derecha \n\r");
        IO_RB4_SetHigh();
        IO_RB6_SetLow();
        IO_RB7_SetLow();
        IO_RC4_SetLow();
        IO_RC5_SetHigh();
        IO_RC6_SetHigh();
        IO_RC7_SetLow();
        printf("---------------------------------------------- \n\r");
        __delay(10000);
        
        
        ////////Macro to turn left////////
        
        printf("El dispositivo esta girando a la izquierda \n\r");
        IO_RB4_SetLow();
        IO_RB6_SetHigh();
        IO_RB7_SetLow();
        IO_RC4_SetHigh();
        IO_RC5_SetLow();
        IO_RC6_SetLow();
        IO_RC7_SetHigh();
        printf("---------------------------------------------- \n\r");
        __delay_ms(10000);
        
        ////////Macro to advance////////

        printf("El Dispositivo esta avanzando \n\r");
        IO_RB4_SetHigh();
        IO_RB6_SetLow();
        IO_RB7_SetLow();
        IO_RC4_SetHigh();
        IO_RC5_SetLow();
        IO_RC6_SetLow();
        IO_RC7_SetLow();
        printf("---------------------------------------------- \n\r");
        __delay_ms(10000);
        
        ////////Macro to go back////////

        printf("El Dispositivo esta retrocediendo \n\r");
        IO_RB4_SetLow();
        IO_RB6_SetHigh();
        IO_RB7_SetHigh();
        IO_RC4_SetLow();
        IO_RC5_SetHigh();
        IO_RC6_SetHigh();
        IO_RC7_SetHigh();
        printf("---------------------------------------------- \n\r");
        __delay_ms(10000);
        
        ////////Macro to stop////////

        printf("El Dispositivo esta detenido \n\r");
        IO_RB4_SetLow();
        IO_RB6_SetLow();
        IO_RB7_SetHigh();
        IO_RC4_SetLow();
        IO_RC5_SetLow();
        IO_RC6_SetLow();
        IO_RC7_SetLow();
        printf("---------------------------------------------- \n\r");
        __delay_ms(10000);
    }
}

