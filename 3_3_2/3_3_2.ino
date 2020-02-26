const int inputPin = 7;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // declare LED as output
  pinMode(inputPin, INPUT); // declare pushbutton as input
}

void loop() {
  int val = digitalRead(inputPin); // read input value
  if (val == HIGH) // check if the input is HIGH
  {
    digitalWrite(LED_BUILTIN, HIGH); // turn LED on if motion detected
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
