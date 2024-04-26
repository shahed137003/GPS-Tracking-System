/******************************************************************************
 *
 * Module: UART
 *
 * File Name: Uart.c
 *
 * Author: Mohamed Sameh & Toqa Gamal
 *
 *******************************************************************************/

#include "tm4c123gh6pm.h"
#include "../../headers/Services/TM4C123.h"

// some comments to help you in having some generic code 
// you can have a enum that conation the name of the port ang having it as an integer 
void UART1_Ini(void)
{ 
	
  SYSCTL_RCGCUART_R |= 0x02;
    SYSCTL_RCGCGPIO_R |= 0x04;
  while((SYSCTL_PRGPIO_R&0X04)==0){};
   UART1_CTL_R=0; // Disable UART1
  //GPIO_PORTC_LOCK_R=GPIO_LOCK_KEY;
  //GPIO_PORTC_CR_R=0XFF;
    // Configure UART1 pins (PB0 and PB1)
    GPIO_PORTC_AFSEL_R |= 0x03; // Enable alternate function for PB0 and PB1
    GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0xFF00FFFF) + 0x00220000; // Configure PB0 and PB1 as UART1
    GPIO_PORTC_DEN_R |= 0xFF; // Enable digital I/O 

    UART1_IBRD_R=104;
    UART1_FBRD_R=11;
    UART1_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN); // 8-bit data, enable FIFO
    UART1_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE); // Enable UART1, RX, and TX  
		
}



char CharIn1(void)
{
 while( (UART1_FR_R & 0X10) != 0);
 return (char)(UART1_DR_R & 0XFF);
}

void CharOut1(char data)
{
 while((UART1_FR_R&0X20)!= 0);
 UART1_DR_R=data;
}

/////////////////////////////////////////////////////////////////////////////////////////////

void UART0_Ini(void)
{
 SYSCTL_RCGCUART_R|=0X01; 
 SYSCTL_RCGCGPIO_R|=0x01; //PORTA activation
 while((SYSCTL_PRGPIO_R&0X01)==0){};
 GPIO_PORTA_LOCK_R=GPIO_LOCK_KEY;
 UART0_CTL_R&= ~(UART_CTL_UARTEN);
 GPIO_PORTA_CR_R=0XFF;
 GPIO_PORTA_AFSEL_R|=0X03;
 GPIO_PORTA_PCTL_R=(GPIO_PORTA_PCTL_R & 0xFFFFFF00)+0X11;
 GPIO_PORTA_DEN_R=0X02;
 
  //Disable UART0 in Initialization 
 UART0_IBRD_R=104;
 UART0_FBRD_R=11;
 UART0_LCRH_R=0X0070;
 UART0_CTL_R|=0X301;
}

char CharIn0(void)
{
 while( (UART0_FR_R & 0X10) != 0);
 return (char)(UART0_DR_R & 0XFF);
}


void CharOut0(char data)
{
 while((UART0_FR_R&0X20)!= 0);
 UART0_DR_R=data;
}




int main(void){
// for some test

 }