#include "rf_interface.h"

MarkerChannel::MarkerChannel() {
  this->state = 1;
};
void MarkerChannel::update() {
  switch(this->state) {
    case 1: 
      if(Serial.available()>0) {
        char c=Serial.read();
        if (c=='\n')
          this->state=2;
      }
      if (Serial.available()>0) {
        char c=Serial.peek();
        if (c=='\n') {
          this->marker_str=this->tmp_marker_str;
          this->marker_id=getMarkerId(this->marker_str);
          this->state=1;
          this->tmp_marker_str="";
        }
        else {
          this->tmp_marker_str.concat((char)Serial.read());
        }
      }
  }
};
RfChannel::RfChannel(int serial_channel, MarkerChannel* mch_ptr) {
  this->serial_channel = serial_channel;
  this->mch_ptr = mch_ptr;
  this->state = 1;
};

int RfChannel::available() {
  switch(this->serial_channel) {
    case 1: return Serial1.available(); break;
    case 2: return Serial2.available(); break;
    case 3: return Serial3.available(); break; 
  }
  return 0;
}
char RfChannel::read() {
  switch(this->serial_channel) {
    case 1: return (char)Serial1.read(); break;
    case 2: return (char)Serial2.read(); break;
    case 3: return (char)Serial3.read(); break;
  }
  return '!';
};

template<class T>
void RfChannel::print(T& data) {
  switch(this->serial_channel) {
    case 1: Serial1.print(data); break;
    case 2: Serial2.print(data); break;
    case 3: Serial3.print(data); break;
  }
}

template<class T>
void RfChannel::println(T& data) {
  this->print(data);
  this->print((char)'\n');
}

void RfChannel::update() {
  switch(this->state) {
    case 1:
      if (this->available()>0){
        char c = this->read();
        if (c=='@'){
          this->state = 2;
        }
        else if (c== '#'){
          this->state = 3;
        }
      }
    case 2:
      if (this->available()>0){
        char c = this->read();
        if (c=='*'){
          Serial.println(this->message);
          this->message="";
          this->state=1;
        }
        else
          this->message.concat(c);
      }
    case 3:
      if (this->available()>0){
      char c = this->read();
        if (c=='*'){
          this->state=4;
          requested_marker_id = requested_marker_id_str.toInt();
          requested_marker_id_str="";
        }
        else
          this->requested_marker_id_str.concat(c);
      }
    case 4:
      if(this->mch_ptr->marker_id==this->requested_marker_id) {
        this->println(this->mch_ptr->marker_str);
        this->state=1;
      }
  }
}
