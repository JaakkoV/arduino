int pinRF = 2;
int pinOut = 3;
int previousButtonState = 0;
int ledstate = 0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(pinRF, INPUT);
  pinMode(pinOut, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(pinRF) == LOW && previousButtonState == 0) {
    Serial.println("ei muutosta ");
    Serial.println(ledstate);
    delay(1);
  }
  previousButtonState = 1;
  ledstate++;
  
  if (ledstate == 1) {
    Serial.println(ledstate);
    digitalWrite(pinOut, HIGH);
  } else if (ledstate == 2) {
    Serial.println(ledstate);
    digitalWrite(pinOut, LOW);
    delay(1000);
    digitalWrite(pinOut, HIGH);
    delay(1000);
    digitalWrite(pinOut, LOW);
    delay(1000);
    digitalWrite(pinOut, HIGH);
    } else {
      Serial.println(ledstate);
      digitalWrite(pinOut, LOW);
      Serial.println("takaisin nollaan");
      ledstate = 0;
    }
    
  delay(2000);
  previousButtonState = 0;
}
