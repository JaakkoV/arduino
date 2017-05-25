/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

#include <SoftRcPulseOut.h>
SoftRcPulseOut servo1;

#define REFRESH_NB_FOR_DELAY(MsToWait)  ((MsToWait)/20UL)
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 0;
int button = 1;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(button, LOW);     
  servo1.attach(2);
  servo1.setMaximumPulse(2200);

}

// the loop routine runs over and over again forever:
void loop() {
uint16_t Needed20msRefreshNb;
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  while(digitalRead(button) == LOW) {
    delay(20);
  }
  servo1.write(0);
  /* Refresh pos during 2 sec */
  Needed20msRefreshNb=REFRESH_NB_FOR_DELAY(2000UL);
  do{
    while(!SoftRcPulseOut::refresh()); //without argument, refresh occurs every 20 ms (internal to the lib), returns 1 once refresh performed
    Needed20msRefreshNb--;
  }while(Needed20msRefreshNb);

  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  servo1.write(180);
  /* Refresh pos during 2 sec */
  Needed20msRefreshNb=REFRESH_NB_FOR_DELAY(2000UL);
  do{
    while(!SoftRcPulseOut::refresh()); //without argument, refresh occurs every 20 ms (internal to the lib), returns 1 once refresh performed
    Needed20msRefreshNb--;
  }while(Needed20msRefreshNb);
}
