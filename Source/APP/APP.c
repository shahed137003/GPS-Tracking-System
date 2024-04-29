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

int __main () {
		init();
		char mess[100];
		float currLong;
		float currLat;
		float prevLong;
		float prevLat;

		float displacement ;
		float distance=0;
	
		while(1){	
			uint8_t button_state = gpio_digital_read(PORTF_INDEX, PIN0);
			
			
				while(GPS_output_format(mess,&currLong,&currLat )==1){
						if(button_state==1){	
						// accumulating the distance
						displacement= obtainDistance(currLong,currLat,prevLong,prevLat);
						distance+=displacement;
						prevLong=currLong;
						prevLat=currLat;
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
	
	
	
	
