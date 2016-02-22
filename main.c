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
#include "switch.h"


// ******************************************************************************************* //

int main(void)
{
    SYSTEMConfigPerformance(10000000);
    
    
    
    
    initTimer2();
    
    TRISGbits.TRISG15 = 0;
    LATGbits.LATG15 = 0;
    int i = 0;
    for (i = 0; i < 1000; i++) {
        delayUs(1000);
    }
    LATGbits.LATG15 = 1;
    
    
    initLCD();
    
    delayUs(1000000);
    
//    testChar();
//    testChar();
    testString();
    writeCHAR('Q',1);
    writeCHAR('Q',1);
    
    
    
    //LCDShift();
    
    //moveCursorLCD(1,2);
    
   // enableInterrupts();
    
   // initSW1();          //Initialize the button
    
    while(1)
    {
        
    }
    
    return 0;
}

//void __ISR(_CHANGE_NOTICE_VECTOR, IPL2SRS) _CNInterrupt( void ){
//    IFS1bits.CNDIF = 0;     //Reset change notification flag
//    
//    clearLCD();
//}