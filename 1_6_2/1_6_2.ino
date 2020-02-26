int num = 0;

void setup(){
  Serial.begin(9600);
  //Try to comment this out and see the effect
  //Serial.setTimeout(10);
}

void loop(){
  while(Serial.available() == 0){
    
  }
  
  while(Serial.available()>0){
    num = Serial.parseInt();    
  }
  Serial.println(num);
}
