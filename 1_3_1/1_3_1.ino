void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("The size of every variable, unit in byte");
  Serial.print("The size of integer is: ");
  Serial.println(sizeof(int));

  Serial.print("The size of floating number is: ");
  Serial.println(sizeof(float));

  Serial.print("The size of floating number with double precision is: ");
  Serial.println(sizeof(double));

  Serial.print("The size of boolean variable (true or false) is: ");
  Serial.println(sizeof(boolean));

  Serial.print("The size of character is: ");
  Serial.println(sizeof(char));

  Serial.print("The size of one byte is: ");
  Serial.println(sizeof(byte));

  Serial.print("The size of void (aka nothing) is: ");
  Serial.println(sizeof(void));

  //we put while(1) here to stop the program from running over and over again, the whole program is said "trapped" in a while loop
  while(1);
}
