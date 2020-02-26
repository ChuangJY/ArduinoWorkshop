/*
  SwitchCase sketch
  example showing switch statement by switching on chars from the serial port

  sending the character 1 blinks the LED once, sending 2 blinks twice
  sending + turns the LED on, sending - turns it off
  any other character prints a message to the Serial Monitor
*/

void setup()
{
  Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  if (Serial.available()) // Check to see if at least one character is available
  {
    char ch = Serial.read();
    switch (ch)
    {
      case '1':
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        break;
      case '2':
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        break;
      case '+':
        digitalWrite(LED_BUILTIN, HIGH);
        break;
      case '-':
        digitalWrite(LED_BUILTIN, LOW);
        break;
      case '\n': //we don't want to enter you pressed being sent
        break;
      default :
        Serial.print(ch);
        Serial.println(" was received but not expected");
        break;
    }
  }
}
