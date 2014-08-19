#ifndef RF_INTERFACE_H_
#define RF_INTERFACE_H_

#include <Arduino.h>

int getMarkerId(String S);

class MarkerChannel {
  public:
    int state;
    String marker_str;
    String tmp_marker_str;
    int marker_id;
    HardwareSerial* _Serial;
    MarkerChannel(HardwareSerial* serial);
    void update();
};

class RfChannel {
  public:
    int state;
    HardwareSerial* _Serial;
    String message;
    String requested_marker_id_str;
    int requested_marker_id;
    MarkerChannel* mch_ptr;
    RfChannel(HardwareSerial* serial, MarkerChannel* mch_ptr);
    void update();
    char read();
};
#endif
