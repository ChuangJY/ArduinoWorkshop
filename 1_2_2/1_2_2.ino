//First try serial plotter
//Then uncomment, try serial monitor
char ch = 65;
int value = 65;
float floatValue = 65.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("chrValue: ");
  //Serial.println(ch);
  //Serial.println(byte(ch));
  //Serial.println(ch, DEC);

  //Serial.println("int value: ");
  Serial.println(value);
  //Serial.println(byte(value));
  //Serial.println(value, DEC);
  //Serial.println(value, HEX);
  //Serial.println(value, OCT);
  //Serial.println(value, BIN);

  //Serial.println("floatValue: ");
  //Serial.println(floatValue);
  delay(1000);
  //ch++;
  value++;
}
