#include "rf_interface.h"

int getMarkerId(String S){
   String id_string;
   id_string = S.substring(0,S.indexOf(','));
   return id_string.toInt();
};

MarkerChannel::MarkerChannel(HardwareSerial* serial) {
  _Serial = serial;
  state = 1;
  marker_str = "";
  tmp_marker_str = "";
};

void MarkerChannel::update() {
  switch(this->state) {
    case 1:
      if(_Serial->available() > 0) {
        char c = _Serial->read();
        if (c == '\n')
          this->state = 2;
      }
      break;
    case 2:
      if(_Serial->available() > 0) {
        char c = _Serial->peek();
        if (c == '\n') {
          this->marker_str = this->tmp_marker_str;
          this->marker_id = getMarkerId(this->marker_str);
          this->state = 1;
          this->tmp_marker_str="";
        }
        else {
          this->tmp_marker_str.concat((char)_Serial->read());
        }
      }
      break;
  }
};

RfChannel::RfChannel(HardwareSerial* serial, MarkerChannel* mch_ptr) {
  _Serial = serial;
  this->mch_ptr = mch_ptr;
  this->state = 1;
  this->message = "";
};
char RfChannel::read() {
  if(_Serial->available())
    return (char)_Serial->read();
};
void RfChannel::update() {
  switch(this->state) {
    case 1:
      if(_Serial->available() > 0) {
        char c = _Serial->read();
        if( c == '@') {
          this->state = 2;
        }
        else if (c == '#') {
          this->state = 3; 
        }
      }
      break;
     case 2:
       if(_Serial->available() > 0) {
         char c = _Serial->read();
         if(c == '*') {
           this->mch_ptr->_Serial->println(this->message);
           this->message = "";
           this->state = 1;
         }
         else
           this->message.concat(c);
       }
       break;
     case 3:
       if(_Serial->available() > 0) {
         char c = _Serial->read();
         if(c == '*'){
           this->state = 4;
           requested_marker_id = requested_marker_id_str.toInt();
           requested_marker_id_str = "";
         }
         else
           this->requested_marker_id_str.concat(c);
       }
       break;
     case 4:
       if(this->mch_ptr->marker_id==this->requested_marker_id) {
         _Serial->println(this->mch_ptr->marker_str);
         this->state = 1;
       }
       break;
  }
};
