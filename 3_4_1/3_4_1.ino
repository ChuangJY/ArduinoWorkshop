const int pingPin = 6;
const int pulsePin = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(pulsePin, INPUT);
}

void loop()
{
  int cm = ping(pingPin, pulsePin) ;
  Serial.println(cm);
  delay(100);
}

int ping(int pingPin, int pulsePin)
{
  long duration, cm;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(pulsePin, HIGH);
  cm = microsecondsToCentimeters(duration);
  return cm ;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / (29 * 2);
}
