
int value = 0;
char ch = 'A';

void setup(){
  Serial.begin(9600);
  if(ch == 65){
    Serial.println("A is stored numerically 65");
  }
  ch++; //What happend if we increment character
  Serial.println(ch);
  value = 66;
  if(value == ch){
    Serial.println("We can compare int with char");
  }
  ch++;
  if(ch == 'C'){
    Serial.println("So C is not the same as c");
    Serial.print("C is ");
    Serial.print(ch, DEC);
    Serial.print(" c is ");
    Serial.println(tolower(ch), DEC); 
  }else if(ch == 'c'){
    Serial.println("So be careful!");
  }
}

void loop(){
}
