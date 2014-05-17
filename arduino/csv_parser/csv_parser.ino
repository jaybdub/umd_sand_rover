void setup(){
  Serial.begin(9600);
}

void loop(){
  char finish_char = '\n';
  
  String msg = "";
  int count = 0;
  int comma_ind = 0;
  
  float id;
  float x;
  float y;
  float theta;
  String time = "";
  
  String dat;
  char dat_char[10];
  
  /* Retrieve data string from USB */
  char nextChar[50];
//  int count = 0;
  
  do{
    if(Serial.available()){
      nextChar[count] = Serial.read();
      count++;
    }
  }while(nextChar[count-1] != finish_char);
  
  nextChar[count] = 0;
  count = 0;
  
  /* Message transmitted as:
     "id,x,y,theta,time\n"
  */
  
  /* Sample message */
//  msg = "1234,20,30,140,10:24:45\n";
  
  msg = nextChar;

  while(msg.length() > 1){
    comma_ind = msg.indexOf(",");
    
    if(comma_ind != -1){
      dat = msg.substring(0,comma_ind);
      dat.toCharArray(dat_char,10);
    }else{
      dat = msg.substring(0,msg.length()-1);
//      dat.toCharArray(dat_char,10);
    }
    
    switch(count){
      case 0: id = atof(dat_char); break;
      case 1: x = atof(dat_char); break;
      case 2: y = atof(dat_char); break;
      case 3: theta = atof(dat_char); break;
      case 4: time = dat; break;
    }
    
    if(comma_ind != -1)
      msg = msg.substring(comma_ind + 1);
    else
      msg = msg.substring(msg.indexOf(finish_char));
    
    count++;
    
  }
  
  Serial.print(id);
  Serial.print(",");
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.print(theta);
  Serial.print(",");
  Serial.println(time);
  //Serial.println(" ");
//  delay(1000);
}
