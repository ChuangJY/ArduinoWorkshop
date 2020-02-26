#define SERIALUPDATETIME 1000

//Be careful now we're using analogue pin!
const int POT = A1;
int value = 0;
unsigned long current, previous = 0;

void setup(){
  //constrain(x, min, max) return a value that's within the bounds of min and max
  // if x < min, x = min ; x > max, x = max; min < x < max, x = x

  Serial.begin(9600);
  pinMode(POT, INPUT);
}

void loop(){
  value = constrain(analogRead(POT), 500, 1000);

  current = millis();

  if(current - previous > SERIALUPDATETIME){
    previous = current;
    Serial.println(value);
  }
}
