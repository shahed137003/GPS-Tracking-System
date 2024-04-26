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
void UART0_Ini(void); //initialization for UART0

char CharIn0(void); //to receive data

void CharOut0(char data); //to transmit the data

/******** UART1 **********/
void UART1_Ini(void);  //initialization for UART1

char CharIn1(void); //to Receive the data

void CharOut1(char data); //to transmit the data

#endif
