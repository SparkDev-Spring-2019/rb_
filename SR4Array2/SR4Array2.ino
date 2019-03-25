//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN_0 53
#define ECHO_PIN_0 52
#define NEOPIXEL_DIM_0 51

#define TRIG_PIN_1 50
#define ECHO_PIN_1 49
#define NEOPIXEL_DIM_0 48

#define TRIG_PIN_2 47
#define ECHO_PIN_2 46
#define NEOPIXEL_DIM_0 45

#define TRIG_PIN_3 44
#define ECHO_PIN_3 43
#define NEOPIXEL_DIM_3 42

#define TRIG_PIN_4 41
#define ECHO_PIN_4 40
#define NEOPIXEL_DIM_4 39

SR04 ultra0 = SR04(ECHO_PIN_0,TRIG_PIN_0);
SR04 ultra1 = SR04(ECHO_PIN_1,TRIG_PIN_1);
SR04 ultra2 = SR04(ECHO_PIN_2,TRIG_PIN_2);
SR04 ultra3 = SR04(ECHO_PIN_3,TRIG_PIN_3);
SR04 ultra4 = SR04(ECHO_PIN_4,TRIG_PIN_4);

long loc[4];

const long DistanceMax = 500;
const long DistanceMin = 0;
const int PixMax = 8;
int array[5][7];

void setup() {
   Serial.begin(9600);
   delay(1000);

}

void loop() {
     long current = loc[0];
     int sensor = 0;
     int len = 0;

     Get_Distance();
     
     for (int i = 0; i < 5; i++){
      if (loc[i] <= current){
        current = loc[i];
        sensor = i;
      }
     }

     len = loc[sensor] / PixMax;
     
     Serial.print("pacman is @ dot #: ( ");
     Serial.print(sensor);
     Serial.print(" , ");
     Serial.print(len);
     Serial.println(" )");
   
   delay(200);
}

 void Get_Distance(){
   loc[0] = ultra0.Distance();
   loc[1] = ultra1.Distance();
   loc[2] = ultra2.Distance();
   loc[3] = ultra3.Distance();
   loc[4] = ultra4.Distance();

   loc[0] = constrain(loc[0], DistanceMin, DistanceMax);
   loc[1] = constrain(loc[1], DistanceMin, DistanceMax);
   loc[2] = constrain(loc[2], DistanceMin, DistanceMax);
   loc[3] = constrain(loc[3], DistanceMin, DistanceMax);
   loc[4] = constrain(loc[4], DistanceMin, DistanceMax);
 }


   
 
