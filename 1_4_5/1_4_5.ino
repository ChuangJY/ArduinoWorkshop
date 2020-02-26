int randNumber;
int ledCombination[6][3] = { {4, 2, 3}, {4, 3, 2}, {2, 4, 3}, {2, 3, 4}, {3, 4, 2}, {3, 2, 4} };

void setup() {
  Serial.begin(9600);

  for (int i = 2; i <= 4; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(A0, INPUT);

  // Print random numbers with no seed value
  Serial.println("Print 20 random numbers between 0 and 9");
  for (int i = 0; i < 20; i++)
  {
    randNumber = random(10);
    Serial.print(randNumber);
    Serial.print(" ");
  }

  Serial.println();
  Serial.println("Print 20 random numbers between 2 and 9");
  for (int i = 0; i < 20; i++)
  {
    randNumber = random(2, 10);
    Serial.print(randNumber);
    Serial.print(" ");
  }

  // Print random numbers with the same seed value each time
  randomSeed(1234);
  Serial.println();
  Serial.println("Print 20 random numbers between 0 and 9 after constant seed ");
  for (int i = 0; i < 20; i++)
  {
    randNumber = random(10);
    Serial.print(randNumber);
    Serial.print(" ");
  }

  // Print random numbers with a different seed value each time
  randomSeed(analogRead(0)); // read from an analog port with nothing connected
  Serial.println();
  Serial.println("Print 20 random numbers between 0 and 9 after floating seed ");
  for (int i = 0; i < 20; i++)
  {
    randNumber = random(10);
    Serial.print(randNumber);
    Serial.print(" ");
  }

  //Print ramdom number to decide which LED to bright up
  //Can you do that?

  Serial.println();
  Serial.println();
}

void loop() {
  randomSeed(analogRead(A0));
  randNumber = random(0, 5);
  for (int j = 0; j < 3; j++) {
    Serial.print(randNumber);
    digitalWrite(ledCombination[randNumber][j], HIGH);
    delay(500);
    digitalWrite(ledCombination[randNumber][j], LOW);
    delay(70);
  }
}
