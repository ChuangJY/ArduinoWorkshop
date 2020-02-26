int number = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("The number is: "); // Serial.print prints sth without hitting enter
  Serial.println(number++); //Serial.println prints the thing inside and hit enter

  // Let's say you want to debug if a pin is reading high input
  if(digitalRead(3) == HIGH){
    Serial.println("I'm high up here");
  }
  
  delay(1000);
}
