#include <SoftwareSerial.h>
SoftwareSerial My_Serial(8, 9);

#define Button  A1 // This Button for call command
String Massage_Body = "Hello Arduino...!";

void setup() 
{ 
  My_Serial.begin(9600);
  pinMode(Button, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead (Button) == LOW)
    {
      Send_Text();
    }
  delay(5);
}


void Send_Text()
{
  My_Serial.println("AT+CMGF=1");
  delay(1000);
  My_Serial.println("AT+CMGS=\"+8801730288553\"\r");
  delay(1000);
  My_Serial.println(Massage_Body);
  delay(200);
  My_Serial.println((char)26);
  delay(1000);

}
