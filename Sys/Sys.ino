// Pin Layout
// ****RTC Module****
// Pin SDA20, SCL21
// ****BLE Module****
// Pin Rx1 18, Tx1 19
// ****LCD Module****
// Pin D4,D5,D6,D7,D8,D9
// ****IR Sensor Module****
// Pin D2
// ****Servo Motor****
// Pin D3
// ****Buzzer****
// Pin D10

#include <Wire.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <EEPROM.h>
#include "RTClib.h"

RTC_DS1307 rtc;
Servo myservo;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Global constant
#define BUZZER 10
#define IR 2
#define SERVO 3
#define BLESTATUSPIN 13
#define OPENPOS 90
#define CLOSEPOS 0

const char Week[7][3] = {"SU", "MO", "TU", "WE", "TH", "FR", "SA"};

//Global variable
boolean setTime = true;
boolean foodLevel = true; //true = enough, false = low
boolean BTConnected = false;
char buff[8];
boolean timer1Flag = false;
boolean timer2Flag = false;
int current = 0;
int count = 0;
int rotatedTime = 0;
long rotationStartTime;
long lastRotateTime = 0;
struct feedTime {
  short int feedHour;
  short int feedMinute;
};

feedTime feedTime1;
feedTime feedTime2;

void setup() {
  // put your setup code here, to run once:

  //Initialize serial monitor for debugging
  Serial.begin(9600);

  //Initialize Real time clock
  /*Check if real time clock is connected*/
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC lost power, setting the time...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
  }

  //Initialize bluetooth serial
  Serial1.begin(9600);

  //Initialize bluetooth status pin
  pinMode(BLESTATUSPIN, INPUT);

  //Initialize LCD screen
  lcd.begin(16, 2);
  /*Code to test if LCD works, comment out to test
    lcd.setCursor(0,0);
    lcd.print("ARDUINO");
    lcd.setCursor(0,1);
    lcd.print("PETFEEDER");*/

  //Initialize Buzzer pin
  pinMode(BUZZER, OUTPUT);

  //Initialize Servo motor
  myservo.attach(SERVO);
  myservo.write(CLOSEPOS);

  //Initialize IR sensor
  pinMode(IR, INPUT);

  //Getting default feed time from EEPROM
  int addr = 0;
  char data[8];
  while (addr < 8) {
    EEPROM.get(addr, data[addr]);
    addr++;
  }
  addr = 0;

  feedTime1.feedHour = (data[0] - 48) * 10 + (data[1] - 48) * 1;
  feedTime1.feedMinute = (data[2] - 48) * 10 + (data[3] - 48) * 1;
  feedTime2.feedHour = (data[4] - 48) * 10 + (data[5] - 48) * 1;
  feedTime2.feedMinute = (data[6] - 48) * 10 + (data[7] - 48) * 1;
}

void loop() {

  DateTime noww = rtc.now();

  //Store food level status
  if (digitalRead(IR) == LOW) {
    foodLevel = false;
  } else {
    foodLevel = true;
  }

  if (!digitalRead(BLESTATUSPIN)) {
    BTConnected = false;
  } else {
    BTConnected = true;
  }

  if (BTConnected) {
    //Read time setting data from our phone and store into EEPROM
    if (Serial1.available()) {
      Serial1.readBytes(buff, sizeof(buff));
      delay(10);
      Serial.println(sizeof(buff));
      int i = 0;
      Serial.println("Verify data before writing");
      int hourr;
      int minn;
      while (i < 8) {
        //Depending on how you want to check the buffer
        //let's say if hour > 24 or hour < 0 or minute > 60 or minute < 0

      }
      Serial.println("Writing feed time into EEPROM: ");
      while (i < 8) {
        //Serial.print(buff[i]);
        EEPROM.write(i, buff[i]);
        i++;
      }

      //Feedback to master if food level low
      foodLevel ? : Serial1.write("Food Level Low");
    }
  }

  //Move the servo when feed time is up
  if ((feedTime1.feedHour == noww.hour() && feedTime1.feedMinute == noww.minute()) || (feedTime2.feedHour == noww.hour() && feedTime2.feedMinute == noww.minute())) {
    if (noww.second() == 0) {
      myservo.write(OPENPOS);
      rotationStartTime = millis();
      if (rotatedTime = 0) {
        lastRotateTime = millis();
        rotatedTime = 1;
      }
      if ((rotationStartTime - lastRotateTime) >= 3000 && rotatedTime == 1) {
        myservo.write(CLOSEPOS);
        rotatedTime = 0;
      }
    }
  }
  displayTimeAndBLEStatus();
}
