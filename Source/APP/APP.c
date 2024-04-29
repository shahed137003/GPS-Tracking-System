#include "../../Headers/MCAL/GPIO.h"
#include "../../Headers/MCAL/UART.h"
#include "../../Headers/HAL/GPS_module.h"
#include "../../Headers/HAL/LCD.h"


void  init(){
	gpio_digital_port_init(PORTF_INDEX,PIN0,INPUT);
	gpio_digital_port_init(PORTF_INDEX,PIN1,OUTPUT);
	gpio_digital_port_write(PORTF_INDEX,PIN1,LOW);
	UART2_Ini();	
}
char message[100];
		float coordinate[2];
	  float prevcoordinate[2];
		float displacement ;
		float distance=0;	
	

int main () {
		init();
	
	
		while(1){	
			uint8_t button_state = gpio_digital_read(PORTF_INDEX, PIN0);
			
			
				while(GPS_output_format(message,coordinate)==1){
						if(button_state==1){	
						// accumulating the distance
						displacement= obtainDistance(coordinate[0],coordinate[1],prevcoordinate[0],prevcoordinate[1]);
						distance+=displacement;
							
					
							prevcoordinate[0]=coordinate[0];
							prevcoordinate[1]=coordinate[1];
						
						}
						else{
							//turn on the LED
							gpio_digital_port_write(PORTF_INDEX,PIN1,HIGH);
							//send distance to lcd
							
							//set distance to 0
							distance=0;
						}
				}
		}
}
	
	
	
	
