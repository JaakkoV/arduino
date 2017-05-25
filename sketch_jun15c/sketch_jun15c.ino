void setup()
{
  Serial.begin(9600);  //Baud rate of the GSM/GPRS Module 
  Serial.print("\r");
  delay(1000);
  Serial.print("AT+CPIN=\"0000\"\r");    
  delay(2000);
  Serial.print("AT+CSCS=\"GSM\"\r");    
  delay(1000);
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+358505770513\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial.print("Test M590 SMS kit module using AT commands from Arduino mega boards - niq_ro\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);  // command for send sms, code for CTRL-Z
  delay(1000); 
}
void loop()
{
}
