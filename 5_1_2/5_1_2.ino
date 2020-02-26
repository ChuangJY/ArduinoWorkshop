#include<SoftwareSerial.h>

SoftwareSerial softSerial(2,3);

void setup(){
  //The sender code
  Serial.begin(9600);
  softSerial.begin(9600);
}
void loop(){

   if(Serial.available()>0){
    softSerial.write(Serial.read());
   }

   if(softSerial.available()>0){
    Serial.write(softSerial.read());
   }
}
