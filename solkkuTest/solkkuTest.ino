//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Simple code to output a PWM sine wave signal on pin 9
//////////////////////////////////////////////////////////////////

#define solenoidPin 3
#define detectorPin 6
#define ledPin 9

void setup(){
  pinMode(solenoidPin, OUTPUT);  
  pinMode(detectorPin, INPUT);
  }

void loop(){
  boolean hit = digitalRead(detectorPin);
  boolean yes = false;
  if (digitalRead(buttonPin)) {
    digitalWrite(solenoidPin, LOW);
  }
  
  if (hit) {
    for (int i = 0; i <= 5; i++) {
      delay(1000);
    }
    yes = true;  
  }

  if (yes) {
    digitalWrite(solenoidPin, HIGH);
  }
  delay(15)


}
