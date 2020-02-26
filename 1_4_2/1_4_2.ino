void setup(){

  //Below's are the example of using compund operator to increment or decrement a value
  //be careful of the ++ and --, putting them as prefix or postfix is different.
  Serial.begin(9600);

  int i = 0;

  i = i + 1;
  i++;
  Serial.println(++i); //guess what's the output? (3)

  i = i - 1;
  Serial.println(i--); //guess what's this again? (2)

  i += 1;
  Serial.println(i); //(2)

  i -= 1;
  Serial.println(i); //(1)

  i *= 2;
  Serial.println(i); //(2)

  i /= 2;
  Serial.println(i); //(1)
  
}

void loop(){
  
}
