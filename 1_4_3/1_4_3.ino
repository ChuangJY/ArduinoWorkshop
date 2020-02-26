void setup() {

  //ceil round up a number, floor round down a number
  Serial.begin(9600);
  
  Serial.println( floor(10) );
  Serial.println( floor(10.1) );
  Serial.println( floor(0) );
  Serial.println( floor(.1) );
  Serial.println( floor(-1) );
  Serial.println( floor(-1.1) );
  Serial.println( ceil(1) );
  Serial.println( ceil(1.1) );
  Serial.println( ceil(0) );
  Serial.println( ceil(.1) );
  Serial.println( ceil(-1) );
  Serial.println( ceil(-1.1) );

  //round up is not the same as casting(converting)
  //for example, floating converted to int
  Serial.println( int(-1.9));
  Serial.println( ceil(-1.9));
}

void loop() {

}
