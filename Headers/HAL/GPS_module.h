#ifndef GPS
#define GPS
#define PI 3.141592653589793238
#define earthradius  6371000
#include <Math.h>
#include <String.h>
#include <stdlib.h>


//void setGPSModule(char * gps);
void GPS_read(char * GPS_module);
float toDegree(float angle);
int GPS_output_format(char * GPS_module,float *currLong,float * currLatit);
float harversine(float LongAinRad, float LatAinRad, float LongBinRad, float LatBinRad);
float obtainDistance(float LongA, float LatA, float LongB, float LatB);


#endif