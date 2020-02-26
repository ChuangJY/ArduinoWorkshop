// The setup() method runs once, when the sketch starts
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // initialize the digital pin as an output
}

// the loop() method runs over and over again,
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
  delay(1000); // wait a second
  digitalWrite(LED_BUILTIN, LOW); // turn the LED off
  delay(1000); // wait a second
}
