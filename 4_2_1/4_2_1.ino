#include <Servo.h>

#define SERVO90 3000

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int poss = 90;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  //utestProgram();
}

void loop() {
//  if(millis() > SERVO90){
//    poss = 0;
//  }else{
//    poss = 90;
//  }
//  Serial.println(poss);
//  myservo.write(poss);
  while(millis() < SERVO90){
    myservo.write(90);
  }
  myservo.write(2);
}

void testProgram(){
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);
    delay(15);              
  }
}
