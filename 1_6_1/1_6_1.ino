int number = 0;
void setup() {
  Serial.begin(9600);

  Serial.println("Here's something to show you...");
  Serial.println("Press some number to serial monitor");

}

void loop() {
  number = 0;

  while (Serial.available() > 0) {
    Serial.read();
    delay(100);
  }
  while (Serial.available() == 0) {
    //do nothing
  }
  while (Serial.available() > 0) {
    byte incoming = Serial.read();

    if (incoming >= '0' && incoming <= '9') {
      number *= 10;
      number += incoming - '0';

      delay(5);
      //Gotcha without this it won't work!
      //because the while loop is too fast
      //let's say you type 15, it reads 1 but too
      //fast so it cannot read the 5, Serial.available will
      //return 0. Try comment delay(5) out and see result.
      Serial.println("number = " + String(number));
      Serial.println("Number of bytes left in buffer: " + String(Serial.available()));
    } else {
      Serial.println("\nDon't input character\n");
    }
  }
  Serial.print("number= ");
  Serial.println(number);
}
