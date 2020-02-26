void displayTimeAndBLEStatus() {
  DateTime now = rtc.now();
  lcd.setCursor(0, 0);
  lcd.print(now.year() , DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print(' ');
  lcd.print(Week[now.dayOfTheWeek()]);
  lcd.setCursor(0, 1);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  lcd.print(' ');
  BTConnected ? lcd.write('Y') : lcd.write('N');
  lcd.print('/');
  foodLevel ? lcd.write('F') : lcd.write('E');
}
