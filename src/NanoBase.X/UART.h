void UART_init()
{
    TRISCbits.TRISC1 = 1;   //RX input
    TRISCbits.TRISC0 = 0;   //TX output 
    
    TX1STAbits.SYNC = 0;     //UART
    TX1STAbits.TX9 = 0;      //8 BITS
    TX1STAbits.BRGH = 1;     //ALTA VELOCIDAD
    SP1BRG = 129;            //9600 baudios
    RC1STAbits.SPEN = 1;     //UART on    
    TX1STAbits.TXEN = 1;    //TX on
    RC1STAbits.CREN = 1;     //RX on
}

char UART_read(void)
{
    if (PIR1bits.RC1IF == 1)
        return RC1REG;
    else
        return 0;
}

void UART_write(char dato)
{
    TX1REG = dato;
     while(TX1STAbits.TRMT == 0);
}

void UART_printf(unsigned char *cadena)
{
    while(*cadena !=0x00){
        UART_write(*cadena);
        cadena++;
    }
}