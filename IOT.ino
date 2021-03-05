//Blynk Alert system
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "TP2qqrgT6LHyLp1yVSRl8T7ZVivIex6a"; //Auth code sent via Email
//char ssid[] = "DESKTOP-6TOVM9R 6821"; //Wifi name
//char pass[] = "4/m322J1";  //Wifi Password
char ssid[] = "aakash"; //Wifi name
char pass[] = "147147147";  //Wifi Password
int irPin = D1;
int buzzer = D0;
int ledPin = D2;
int flag=0;
void notifyOnThings()
{
  int isButtonPressed = digitalRead(irPin);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Someone  is in the House");
    Blynk.notify("Alert : Someone is in the House");
    flag=1;   
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
          digitalWrite(ledPin, HIGH);
    delay(10000);
    digitalWrite(ledPin, LOW);
  }
  else if (isButtonPressed==0)
  { 
    flag=0;
  }
}
void setup()
{
Blynk.begin(auth, ssid, pass); 
pinMode(irPin,INPUT_PULLUP);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
timer.setInterval(500L,notifyOnThings); 
Serial.begin(115200);

}
void loop()
{
  Blynk.run();
  timer.run();
}
