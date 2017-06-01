#include <Arduino.h>

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 8;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 12;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 11;

int counter = 0;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  //Serial.begin(9600);
  //Serial.println("reset");
}

void loop()
{

       digitalWrite(latchPin, LOW);          //Pull latch LOW to start sending data
       shiftOut(dataPin, clockPin, MSBFIRST, B00000010);
       shiftOut(dataPin, clockPin, MSBFIRST, B00000010);         //Send the data
       digitalWrite(latchPin, HIGH);         //Pull latch HIGH to stop sending data
/*
       delay(500);

       digitalWrite(latchPin, LOW);          //Pull latch LOW to start sending data
       shiftOut(dataPin, clockPin, MSBFIRST, 0);         //Send the data
       digitalWrite(latchPin, HIGH);

       delay(500);
*/
}
