
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
        PORTBbits.RB4 = 1;
        PORTCbits.RC4 = 0;
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 0;
        PORTCbits.RC5 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC7 = 0;
        __delay_ms(15000);

        ////////Macro to turn left////////Initially it must be ensured that the entire device is p
owered by a source of at least 5 volts to ensure proper operation of the device, as a step to follow would be to open the application developed by the working group and connect your mobile device to the Bluetooth module used in the assembly, thanks to the configuration perform turns on the same axis facilitating maneuvering in tight places.The MCU must be powered after being connected to the bluetooth module and the L298n controller (H-bridge), then leave it on a flat and wide surface to run the sequence and stop.



        printf("El dispositivo est� girando a la izquierda \n\r");
        PORTBbits.RB4 = 0;
        PORTCbits.RC4 = 1;
        PORTBbits.RB6 = 1;
        PORTBbits.RB7 = 0;
        PORTCbits.RC5 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC7 = 1;
        __delay_ms(15000);

        ////////Macro to advance////////

        printf("El Dispositivo est� avanzando \n\r");
        PORTBbits.RB4 = 1;
        PORTCbits.RC4 = 1;
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 0;
        PORTCbits.RC5 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC7 = 0;
        __delay_ms(15000);

        ////////Macro to go back////////

        printf("El Dispositivo est� retrocediendo \n\r");
        PORTBbits.RB4 = 0;
        PORTCbits.RC4 = 0;
        PORTBbits.RB6 = 1;
        PORTBbits.RB7 = 1;
        PORTCbits.RC5 = 1;
        PORTCbits.RC6 = 1;
        PORTCbits.RC7 = 1;
        __delay_ms(15000);

        ////////Macro to stop////////

        printf("El Dispositivo est� detenido \n\r");
        PORTBbits.RB4 = 0;
        PORTCbits.RC4 = 0;
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 1;
        PORTCbits.RC5 = 0;
        PORTCbits.RC6 = 0;
        PORTCbits.RC7 = 0;
        __delay_ms(1000);
    }
}
