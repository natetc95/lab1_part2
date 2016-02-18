/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>
#include "timer.h"

void delayUs(unsigned int delay){
    IFS0bits.T2IF = 0;
    TMR2 = 0;
    PR2 = delay;
    T2CONbits.ON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.ON = 0;
}