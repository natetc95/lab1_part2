// ******************************************************************************************* //
//
// File:         lab1p2.c
// Date:         12-30-2014
// Authors:      Garrett Vanhoy
//
// Description: 
// ******************************************************************************************* //

#include <xc.h>
#include <sys/attribs.h>
#include "lcd.h"
#include "timer.h"
#include "config.h"
#include "interrupt.h"


// ******************************************************************************************* //

int main(void)
{
    SYSTEMConfigPerformance(10000000);
    
    PR2 = 0;
    TMR2 = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.TCS = 0;
    IEC0bits.T2IE = 1;
    IFS0bits.T2IF = 0;
    IPC2bits.T2IP = 4;
    T2CONbits.ON = 0;
    
    initLCD();
    
    LCDShift();
    
    moveCursorLCD(1,2);
    
    
    while(1)
    {
        
    }
    
    return 0;
}
