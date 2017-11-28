/* 
 * File:   uart.h
 * Author: tbriggs
 *
 * Created on October 7, 2013, 12:21 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif


#define TXBUFFSZ 1024
#define RXBUFFSZ 512

#define BAUDRATE   38400
#define USEXONXOFF 1

void uart_echo(int enable);
void uart_init( );

// enable CR to LF mapping
extern int eolfix;

// buffering of STDIN/STDOUT or not
extern int buffering;


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

