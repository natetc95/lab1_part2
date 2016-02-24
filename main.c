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

#define CLR 0x01


// ******************************************************************************************* //

typedef enum RS_enum {
    run, stop
}status;

volatile status state = run;

int main(void)
{
    int i = 0;
    char c;
    
    SYSTEMConfigPerformance(10000000);
    TRISDbits.TRISD0 = 0;
    LATDbits.LATD0 = 1;
    initTimer2();
    delayMs(1000);
    LATDbits.LATD0 = 0;
    delayMs(2000);
    
    initLCD();
    
    writeCMD(CLR);
    
    
    
    while(1)
    {
        testLCD();
    }
    return 0;
}

//void __ISR(_CHANGE_NOTICE_VECTOR, IPL2SRS) _CNInterrupt( void ){
//    IFS1bits.CNDIF = 0;     //Reset change notification flag
//    
//    clearLCD();
//}