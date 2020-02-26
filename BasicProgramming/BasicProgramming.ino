void setup(){
  //Why 9600? Let's open device manage!
  Serial.begin(9600);
}

void loop(){
  helloWorld();
  Serial.println("Welcome to my life");
}
