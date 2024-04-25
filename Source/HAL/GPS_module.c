#include "../../Headers/HAL/GPS_module.h"
#include "../../Headers/MCAL/UART.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//char message[]="$GPRMC, 203522.00, A, 5109.0262308, S, 11401.8407342, E, 0.004, 133. 4, 130522, 0.0, E, D*2B";          //  Was used for testing  before connecting the GPS to Tiva 
 char logElements[12][20];
float currLong;
float currLatit;
char * pointer; 
char GPS_module[100]="";
char log_name[]="$GPRMC, ";
char recievedChar[100];  


	void GPS_read(){                                 //this function will only work when Uart reads data
int flag=1;                                              // the flag will be always 1 in case all chars are matched 
	int i;
	  for( i=0;i<100;i++){  
	// GPS_module[i]=message[i];    			//used for testing
	   GPS_module[i]=UART_READ(); 	                        //will read DATA from UART
	       }
    for(i=0;i<7;i++)		
	   if(log_name[i]!= GPS_module[i])
	     {
	       flag=0;
	      	break;
	     }
   	}
   	
//then we are sure that we are recieving the correct data 

// for formating the gps module output:
		
		
void GPS_output_format(){
  int  flag =1;
	char numOfGPSElements=0;
//	pointer=strtok( message,", ");                            
	pointer =strtok(GPS_module,", ");
do{
strcpy(logElements[numOfGPSElements], pointer);
	pointer=strtok(NULL,", ");
	numOfGPSElements++;
}while(pointer!=NULL);

/////////////////////////

(logElements[3]);
////then we will get the current long and lat :)

// //here we check the validity of the string formated gps_module
	
if(strcmp(logElements[2],"A")==0)
{
flag=1;
//// to get the current long:)
if(flag==1 && strcmp(logElements[4],"N")==0){
	currLatit=atof(logElements[3]);
printf("currLatit: %f \n",currLatit);	
}
else if(flag==1 && strcmp(logElements[4],"S")==0){
 currLatit=-atof(logElements[3]);
printf("currLatit: %f \n",currLatit);	
    
}

// //to get the current latitude:)
if(flag==1 && strcmp(logElements[6],"E")==0){
	currLong=atof(logElements[5]);
	printf("currLong: %f",currLong);	
}
else if(flag==1 && strcmp(logElements[6],"W")==0){
 currLong=-atof(logElements[5]);
printf("currLong: %f",currLong);	
}

}
else if(strcmp(logElements[2],"V")==0)
{ printf ("INVALID DATA");
flag =0;
}
}

//-------------------------------------------------------------------------------------------------ANOTHER_CODE---------------------------------------------------------------------------------------------//
//   char message[]="$GPRMC, 203522.00, A, 5109.0262308, N, 11401.8407342, W, 0.004, 133. 4, 130522, 0.0, E, D*2B";
// char* logElements[100];
// char log_name[]="$GPRMC, ";
// float currLong,directed_currLong ;
// float currLatit,directed_currLatit;
// char *pointer;
// char recievedChar[100]; 

// char* coordinates[2];

// 	void GPS_read(){                        
// int flag=1;
// 	int i;
// 	  for( i=0;i<100;i++){  
// 			  recievedChar[i]=message[i];    		
// 			  }
//     for(i=0;i<7;i++)		
// 	   if(log_name[i]!=recievedChar[i])
// 	     {
// 	       flag=0;
// 	      	break;
// 	     }
//   	}

 
// void GPS_output_format(){
//     int counter=0;
//     int valid=0;
//   pointer=strtok(message," ,");
     
//     while (pointer) {
//         if((strcmp(pointer,"$GPRMC")==0))
//             counter=0;
//       if(counter==2&&(strcmp(pointer," A")==0))   
//           valid =1;
//       if (counter==3&&valid ==1) 
//              currLatit=atof(pointer);
//              if (counter == 4&&valid==1) {
//                 if (strcmp(pointer, " N") == 0) 
//                   directed_currLatit= currLatit ;
//                     else if (strcmp(pointer, " S") == 0) 
//                       directed_currLatit=-currLatit ;
//                  }

//       if (counter==5&&valid==1)
//             currLong=atof(pointer);
//             //to get the current latitude:
//               if (counter == 6&&valid==1) {
//                  if (strcmp(pointer, " E") == 0) 
//                   directed_currLong=currLong;
//                      else if (strcmp(pointer, " W") == 0) 
//                       directed_currLong=-currLong;
//                  }
//         counter++;
//       pointer=strtok(NULL, ",");
      
//     }
//         printf("CurrLatit: %f\n",directed_currLatit);
//         printf("CurrLong:%f\n",directed_currLong);

// }

float toDegree(float angle) {
	float angleindegree=(int)angle/100;
	float mins = angle -(float)angleindegree*100;
	return (angleindegree + (mins/60));
}
float toRad(float angle)
{
	return ((angle * PI) / 180);
}

float harversine(float LongAinRad, float LatAinRad, float LongBinRad, float LatBinRad)
{
		//we will use Haversine law to calculate the distance on sphere
		float x=pow(sin((LatBinRad-LatAinRad)/2),2);
		float y=pow(sin((LongBinRad-LongAinRad)/2),2);
		float a=x+y*cos(LatAinRad)*cos(LatBinRad);
		float c = 2*atan2(sqrt(a),sqrt(1-a));
		return earthradius*c;
}

float obtainDistance(float LongA, float LatA, float LongB, float LatB) {
	//first we need to convert the distance given to radian
		float LatAinRad=toRad(toDegree(LatA));
		float LatBinRad=toRad(toDegree(LatB));
		float LongAinRad=toRad(toDegree(LongA));
		float LongBinRad=toRad(toDegree(LongB));
	//now we have them in radian
	//now we call Harversine method to get the distance
		return harversine(LongAinRad,LatAinRad,LongBinRad,LatBinRad);
}


 int main(){
   GPS_read();
   GPS_output_format();
 }










