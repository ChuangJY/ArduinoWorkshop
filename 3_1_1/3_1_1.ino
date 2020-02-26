#define LEDPIN LED_BUILTIN
#define BUTTON 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalRead(BUTTON) ? digitalWrite(LEDPIN, HIGH):digitalWrite(LEDPIN, LOW);
}
