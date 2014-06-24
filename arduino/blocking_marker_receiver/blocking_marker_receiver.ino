#include <SoftwareSerial.h>
#include "marker_utils.h"

int timeout = 150;
Marker marker;

void setup() 
{
  Serial.begin(57600);
  sSerial.begin(9600);
}

void loop() 
{
  if(getNextMarker(marker,timeout))
  {
    if(marker.id == 4) {
      Serial.print(marker.x);
      Serial.print(",");
      Serial.println(marker.y);
    }
  }
  else
    Serial.println("timeout");
}
