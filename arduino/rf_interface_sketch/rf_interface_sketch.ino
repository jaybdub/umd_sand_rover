#include "rf_interface.h"

MarkerChannel mch(&Serial);
RfChannel rf1(&Serial1, &mch);
RfChannel rf2(&Serial2, &mch);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mch.update();
  rf1.update();
  rf2.update();
  /*if(rf1._Serial->available() ) {
    Serial.print(rf1._Serial->read()); 
  }*/
}
