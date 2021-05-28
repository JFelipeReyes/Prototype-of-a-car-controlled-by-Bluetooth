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
    
    uint8_t Contador = 0;
    
    printf("INICIO \n\r");

    while (1)
    {

       ////////Macro to turn right////////

        printf("El dispositivo est? girando a la derecha \n\r", Contador++);
        
        PORTBbits.RB4 = 1;
        PORTCbits.RC4 = 0;
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 0;
        PORTCbits.RC5 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC7 = 0;
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r", Contador++);
        
        ////////Macro to turn left////////

        printf("El dispositivo est? girando a la izquierda \n\r", Contador++);
        PORTBbits.RB4 = 0;
        PORTCbits.RC4 = 1;
        PORTBbits.RB6 = 1;
        PORTBbits.RB7 = 0;
        PORTCbits.RC5 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC7 = 1;
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r", Contador++);
        
        ////////Macro to advance////////

        printf("El Dispositivo est? avanzando \n\r");
        
        PORTBbits.RB4 = 1;
        PORTCbits.RC4 = 1;
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 0;
        PORTCbits.RC5 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC7 = 0;
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r", Contador++);
        
        ////////Macro to go back////////

        printf("El Dispositivo est? retrocediendo \n\r");
        PORTBbits.RB4 = 0;
        PORTCbits.RC4 = 0;
        PORTBbits.RB6 = 1;
        PORTBbits.RB7 = 1;
        PORTCbits.RC5 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC7 = 1;
        __delay_ms(15000);
        printf("---------------------------------------------- \n\r", Contador++);
        
                ////////Macro to stop////////

        printf("El Dispositivo est? detenido \n\r");
        
        PORTBbits.RB4 = 0;
        PORTCbits.RC4 = 0;
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 1;
        PORTCbits.RC5 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC7 = 0;
        
        __delay_ms(1000);
        printf("---------------------------------------------- \n\r", Contador++);
    }
}

