void setup(){
  Serial.begin(9600);
  int someValue;
  someValue = 1+2;
  Serial.println(someValue);
  someValue = 3-2;
  Serial.println(someValue);
  someValue = 3*2;
  Serial.println(someValue);
  someValue = 3/2;
  Serial.println(String(someValue) + " But why?");
}

void loop(){
  
}
