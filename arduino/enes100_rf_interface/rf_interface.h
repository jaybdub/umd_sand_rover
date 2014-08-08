#ifndef DATA_STRUCTURES_H_
#define DATA_STRUCTURES_H_

#include <Arduino.h>

int getMarkerId(String S){
   String id_string;
   id_string = S.substring(0,S.indexOf(','));
   return id_string.toInt();
};

class MarkerChannel {
  public:
    MarkerChannel();
    int state;
    String marker_str;
    String tmp_marker_str;
    int marker_id;
    void update();
};

class RfChannel {
  public:
    //Variables
    int state;
    int serial_channel;
    String message;
    String requested_marker_id_str;
    int requested_marker_id;
    MarkerChannel* mch_ptr;
    //Methods
    RfChannel(int serial_channel, MarkerChannel* mch_ptr);
    int available();
    char read();
    template<class T>
    void print(T& data);
    template<class T>
    void println(T& data);
    void update();
};

#endif
