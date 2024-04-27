#ifndef GPS
#define GPS
#define PI 3.141592653589793238
#define earthradius  6371000
#include <Math.h>
#include <String.h>
#include <stdlib.h>


void GPS_read(void);
float toDegree(float angle);
void GPS_output_format();
float harversine(float LongAinRad, float LatAinRad, float LongBinRad, float LatBinRad);
float obtainDistance(float LongA, float LatA, float LongB, float LatB);


#endif