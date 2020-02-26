#define LEDPIN LED_BUILTIN
#define BUTTON 7

int buttonReading = HIGH;
int LEDSTATE = LOW;
int previous = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  buttonReading = digitalRead(BUTTON);
  
  if(buttonReading == HIGH & previous == LOW){
    if(LEDSTATE == HIGH){
      LEDSTATE = LOW;
    }else{
      LEDSTATE = HIGH;
    }
  }

  digitalWrite(LEDPIN, LEDSTATE);
  previous = buttonReading;
}
