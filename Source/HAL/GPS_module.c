# include "../../Headers/HAL/GPS.h"

# include "../../Headers/MCAL/UART.h"

# include <string.h>

# include <stdlib.h>

# include <math.h>



char GPS_module[80]; // this is the array that holds the output char from the GPS_module
char log_name[]="$GPRMC, ";
char logElements[12][20];
float currLong;
float currLatit;
char * pointer; // the pointer to store the addresof the first element in the array of each sepatrate element

char recievedChar;
void GPS_read(void){
// first i will check the validity of the data to be recieved 
	// i can check by the log name or any part in log 

char flag=1;
	char i=0;
	do{
		recievedChar=getChar();
flag=1;
	for(char i=0;i<7;i++){
		// the falg will be always 1 in case all chars are matched     
	
	if(log_name[i]!=getChar())
	{
	flag=0;
		break;
	
	}
	}
	}while(flag==0);

//then we are sure that we are recieving the correct data 

	strcpy(GPS_module,""); // for init the array
	
	
	

	do{
	char filler=0;
	recievedChar=getChar();
	GPS_module[filler++]=recievedChar;
	}while(recievedChar!='*');	
		
}
// for formating the gps module output:
 
void GPS_output_format(){
	char numOfGPSElements=0;
do{
pointer=strtok(GPS_module,",");

strcpy(logElements[numOfGPSElements],GPS_module);
	pointer=strtok(NULL,",");
	numOfGPSElements++;
}while(pointer!=NULL);

//then we will get the current long and lat :)

// here we check the validity of the string formated gps_module
if(strcmp(logElements[0],"A")==0)
{


// to get the current long:)
if(strcmp(logElements[3],"N")==0)
	currLong=atof(logElements[2]);
else if(strcmp(logElements[3],"S")==0)
 currLong=-atof(logElements[2]);

 //to get the current latitude:)
if(strcmp(logElements[5],"E")==0)
	currLatit=atof(logElements[4]);
else if(strcmp(logElements[5],"W")==0)
 currLatit=-atof(logElements[4]);


}


}










