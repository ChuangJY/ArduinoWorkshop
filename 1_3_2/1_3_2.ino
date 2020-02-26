#define SERVO 4
#define LEDBLINKINGINTERVAL 1000

const int IR = 3;

unsigned long current = 0;
unsigned long previous = 0;
bool ledState = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR, INPUT);
  pinMode(SERVO, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  current = millis();
  
  Serial.print("current - previous: ");
  Serial.println(current - previous);
  
  if(current - previous >= LEDBLINKINGINTERVAL){
    previous = current;
    ledState ? ledState = LOW : ledState = HIGH;
  }else if(current - previous < 0){
    //when integer overflow, reset timer
    previous = current;
  }
  digitalWrite(LED_BUILTIN,ledState);
}
