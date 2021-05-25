/*
/////////////////// DATOS DEL PROGRAMA ////////////////////
//  TTITULO: Led Blinkng
//  MICRO:PIC16F15244
//  ESTUDIANTES: Juan Felipe Reyes - 2420191049
 *               Juan Jose Hernadez - 2420291052
//  Profesor: Harold F MURCIA
//  FECHA: 19 de abril de 2021
///////////// CONFIGURACION del MCU ////////////////// */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>
#include "UART.h"

#pragma config FEXTOSC = OFF    // External Oscillator Mode Selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINTOSC_1MHZ    // Power-up Default Value for COSC bits->HFINTOSC (1 MHz)
#pragma config CLKOUTEN = OFF    // Clock Out Enable bit->CLKOUT function is disabled; I/O function on RA4
#pragma config VDDAR = HI    // VDD Range Analog Calibration Selection bit->Internal analog systems are calibrated for operation between VDD = 2.3V - 5.5V

// CONFIG2
#pragma config MCLRE = EXTMCLR    // Master Clear Enable bit->If LVP = 0, MCLR pin is MCLR; If LVP = 1, RA3 pin function is MCLR
#pragma config PWRTS = PWRT_OFF    // Power-up Timer Selection bits->PWRT is disabled
#pragma config WDTE = OFF    // WDT Operating Mode bits->WDT disabled; SEN is ignored
#pragma config BOREN = ON    // Brown-out Reset Enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO    // Brown-out Reset Voltage Selection bit->Brown-out Reset Voltage (VBOR) set to 1.9V
#pragma config PPS1WAY = ON    // PPSLOCKED One-Way Set Enable bit->The PPSLOCKED bit can be cleared and set only once in software
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset

// CONFIG4
#pragma config BBSIZE = BB512    // Boot Block Size Selection bits->512 words boot block size
#pragma config BBEN = OFF    // Boot Block Enable bit->Boot Block is disabled
#pragma config SAFEN = OFF    // SAF Enable bit->SAF is disabled
#pragma config WRTAPP = OFF    // Application Block Write Protection bit->Application Block is not write-protected
#pragma config WRTB = OFF    // Boot Block Write Protection bit->Boot Block is not write-protected
#pragma config WRTC = OFF    // Configuration Registers Write Protection bit->Configuration Registers are not write-protected
#pragma config WRTSAF = OFF    // Storage Area Flash (SAF) Write Protection bit->SAF is not write-protected
#pragma config LVP = ON    // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/Vpp pin function is MCLR. MCLRE Configuration bit is ignored.

// CONFIG5
#pragma config CP = OFF    // User Program Flash Memory Code Protection bit->User Program Flash Memory code protection is disabled


///////////// DEFINICIONES  //////////////////
#define _XTAL_FREQ 1000000

#define ACQ_US_DELAY 10
///////////////

///////////// VARIABLES GLOBALES  //////////////////
uint16_t dutyCycle50 = 50;
uint16_t dutyCycle75 = 75;
uint16_t dutyCycle100 = 100;

///////////// DECLARACI?N DE FUNCIONES Y PROCEDIMIENTOS ///////////////////

void PIN_MANAGER_Initialize(void) {
    // LATx registers
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    // TRISx registers
    TRISBbits.TRISB4 = 0; // Definiendo puerto B4 como salida digital
    TRISBbits.TRISB6 = 0; // Definiendo puerto B6 como salida digital
    TRISBbits.TRISB7 = 0; // Definiendo puerto B7 como salida digital
    TRISCbits.TRISC4 = 0; // Definiendo puerto C4 como salida digital
    TRISCbits.TRISC5 = 0; // Definiendo puerto C5 como salida digital
    TRISCbits.TRISC6 = 0; // Definiendo puerto C6 como salida digital
    TRISCbits.TRISC7 = 0; // Definiendo puerto C7 como salida digital

}

void OSCILLATOR_Initialize(void) {
    OSCEN = 0x00; // MFOEN disabled; LFOEN disabled; ADOEN disabled; HFOEN disabled;
    OSCFRQ = 0x00; // HFFRQ0 1_MHz
    OSCTUNE = 0x00;
}

void TMR2_Initialize(void) {
    T2CLKCON = 0x01; // T2CS FOSC/4;
    T2HLT = 0x00; // T2PSYNC Not Synchronized; T2MODE Software control; T2CKPOL Rising Edge; T2CKSYNC Not Synchronized;
    T2RST = 0x00;
    T2PR = 249;
    T2TMR = 0x00;
    PIR1bits.TMR2IF = 0; // Clearing IF flag.
    T2CON = 0b10000000; // T2CKPS 1:1; T2OUTPS 1:1; TMR2ON on;
}

void PWM4_Initialize(void) {
    PWM4CON = 0x90; // PWM4POL active_low; PWM3EN enabled;
    PWM4DCH = 0x3E;
    PWM4DCL = 0x40;
}

void PWM4_LoadDutyValue(uint16_t dutyValue) {
    PWM4DCH = (dutyValue & 0x03FC) >> 2; // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
    PWM4DCL = (dutyValue & 0x0003) << 6; // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
}
/////////////  INICIO DEL PROGRAMA PRINCIPAL //////////////////////////

void main(void)
{
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    TMR2_Initialize();
    PWM4_Initialize();
    UART_init();
    
    char dato_rx;
    
    while(1){
        
        dato_rx = UART_read();
        
        if (dato_rx == 'A') // move forward 50%
        {
                PWM4_LoadDutyValue(dutyCycle50);
                PORTBbits.RB4 = 1;                       
                PORTBbits.RB6 = 0;
                PORTBbits.RB7 = 0; 
                PORTCbits.RC4 = 0;          
                PORTCbits.RC5 = 1;          
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 0; 
            
        }
        
        else if (dato_rx == 'H') // move forward 75%
        {
                PWM4_LoadDutyValue(dutyCycle75);
                PORTBbits.RB4 = 1;                  
                PORTBbits.RB6 = 0;
                PORTBbits.RB7 = 0;
                PORTCbits.RC4 = 0;          
                PORTCbits.RC5 = 1;          
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 0; 
            
        }
        
        else if (dato_rx == 'I') // move forward 100%
        {
                PWM4_LoadDutyValue(dutyCycle100);
                PORTBbits.RB4 = 1;                        
                PORTBbits.RB6 = 0;
                PORTBbits.RB7 = 0;
                PORTCbits.RC4 = 0;          
                PORTCbits.RC5 = 1;          
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 0; 
            
        }
        
        else if (dato_rx == 'E') //go back
        {
                PWM4_LoadDutyValue(dutyCycle50);
                PORTBbits.RB4 = 0;                        
                PORTBbits.RB6 = 1;
                PORTBbits.RB7 = 1;
                PORTCbits.RC4 = 1;          
                PORTCbits.RC5 = 0;          
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 0; 
            
        }
      
        else if (dato_rx == 'D') //right turn
        {
                PWM4_LoadDutyValue(dutyCycle50);
                PORTBbits.RB4 = 1;                        
                PORTBbits.RB6 = 0;
                PORTBbits.RB7 = 0;
                PORTCbits.RC4 = 1;          
                PORTCbits.RC5 = 0;          
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 1; 
        }
        
        else if (dato_rx == 'B') //left turn
        {
                PWM4_LoadDutyValue(dutyCycle50);
                PORTBbits.RB4 = 0;                        
                PORTBbits.RB6 = 1;
                PORTBbits.RB7 = 0;
                PORTCbits.RC4 = 0;          
                PORTCbits.RC5 = 1;          
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 1; 
        }
        
        else if (dato_rx == '0') //stop
        {
                PWM4_LoadDutyValue(dutyCycle50);
                PORTBbits.RB4 = 0;                        
                PORTBbits.RB6 = 0;
                PORTBbits.RB7 = 1;
                PORTCbits.RC4 = 0;          
                PORTCbits.RC5 = 0;          
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 0; 
        }
        
        else if (dato_rx == 'C') // warnings
        {       
                PWM4_LoadDutyValue(dutyCycle50);
                PORTCbits.RC6 = 1;          
                PORTCbits.RC7 = 1;
                __delay_ms(500);
                PORTCbits.RC6 = 0;          
                PORTCbits.RC7 = 0;
                __delay_ms(300);
                        
        }
    }
}