#include <SoftwareSerial.h>
#include "marker_utils.h"

int timeout = 100;

void setup() 
{
  Serial.begin(57600);
  sSerial.begin(9600);
}

void loop() 
{
  Marker marker;
  if(getNextMarker(marker,timeout))
  {
    Serial.println(marker.id);
  }
  else
    Serial.println("timed out");
}
