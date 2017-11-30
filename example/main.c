/* 
 * File:   main.c
 * Author: tbriggs
 *
 * Created on October 7, 2013, 12:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include "uart.h"
#include "config.h"


#include <xc.h>


// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (15x Multiplier)
#pragma config UPLLIDIV = DIV_2         // USB PLL Input Divider (2x Divider)
#pragma config UPLLEN = ON              // USB PLL Enable (Enabled)
#pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 1)

// DEVCFG1
#pragma config FNOSC = PRIPLL           // Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = HS             // Primary Oscillator Configuration (HS osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_4           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS4096             // Watchdog Timer Postscaler (1:1)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))

// DEVCFG0
#pragma config DEBUG = ON               // Background Debugger Enable (Debugger is enabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC1/EMUD1 pins shared with PGC1/PGD1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

/*
 * 
 */
int main(int argc, char** argv) {
    SYSTEMConfig(GetSystemClock(), SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);

    uart_init();

    // Set system to manage the multi-vectored mode
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);

    // Enable the interrupt handling from the core
    INTEnableSystemMultiVectoredInt();

    setvbuf(stdin, NULL, _IONBF,0);
    setvbuf(stdout, NULL, _IONBF, 0);
    
    int i;
    char buff[128];
    while (1) {
        printf("hello enter your name\n");
        fflush(stdout);
        memset(buff, 0, 128);
        if (fgets(buff, 120, stdin) == NULL)
            break;

        // trim the newlines
        char *ptr = strchr(buff,'\n');
        if (ptr != NULL) *ptr = 0x00;
        
        printf("buff: (%s)\n", buff);
    }

    printf("Done\n");
    
    return (EXIT_SUCCESS);
}

