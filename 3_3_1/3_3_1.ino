#define PIR 7

int value;

void setup(){
  Serial.begin(9600);
  pinMode(PIR, INPUT);  
}

void loop(){
  value = digitalRead(PIR);

  Serial.println(value);

  delay(100);
}
