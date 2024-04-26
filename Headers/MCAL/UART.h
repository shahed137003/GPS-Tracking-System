/**************************************************************************************************************************************************
*
*Module: UART
*
*File Name: UART.h
*
*Author: Mohamed Sameh & Toqa Gamal
*
****************************************************************************************************************************************************/

#ifndef UART_H
#define UART_H
#include <stdint.h>
#include "../tm4c123gh6pm.h"

/******** UART0 **********/
void UART0_Init(void); //initialization for UART0

unsigned char UART0_InChar(void); //to Receive the data

unsigned char UART0_InCharNonBlocking(void);

void UART0_OutChar(unsigned char data); //to transmit the data

/******** UART1 **********/
void UART1_Init(void);  //initialization for UART1

unsigned char UART1_InChar(void); //to Receive the data

unsigned char UART1_InCharNonBlocking(void); 

void UART1_OutChar(unsigned char data); //to transmit the data

/******** UART2 **********/
void UART2_Init(void); //initialization for UART2

unsigned char UART2_InChar(void); //to Receive the data

unsigned char UART2_InCharNonBlocking(void);

void UART2_OutChar(unsigned char data); //to transmit the data
#endif
