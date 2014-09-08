#include <SoftwareSerial.h>
#include "marker_utils.h"

int timeout = 1000;
Marker marker;

void setup() 
{
   pinMode(7,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
 digitalWrite(7, HIGH);
 digitalWrite(10, HIGH);
 digitalWrite(11, HIGH);
 digitalWrite(12, LOW);
  Serial.begin(9600);
  sSerial.begin(9600);
  delay(100);
  sSerial.print("@OSV connected*");
}

void loop() 
{
  sSerial.flush();
  sSerial.print("#4*");
  if(getNextMarker(marker,timeout))
  {
    if(marker.id == 4) {
      Serial.print(marker.id);
      Serial.print(",");
      Serial.print(marker.x);
      Serial.print(",");
      Serial.print(marker.y);
      Serial.print(",");
      Serial.print(marker.theta);
      Serial.print(",");
      Serial.println(marker.time);
      
      
    }
  }
  else
    Serial.println("timeout");
    
    delay(500);
}
