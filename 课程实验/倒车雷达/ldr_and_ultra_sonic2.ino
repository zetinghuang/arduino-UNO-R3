//该实验为倒车雷达设计
#define LEDpin 5
#define Buzzerpin 9
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,4,3,2);
int inches=0;
int cm=0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
 pinMode(triggerPin,OUTPUT);
 digitalWrite(triggerPin,LOW);
 delayMicroseconds(2);
 digitalWrite(triggerPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(triggerPin,LOW);
 pinMode(echoPin,INPUT);
  return pulseIn(echoPin,HIGH);
}
void setup()
{
  lcd.begin(16,2);
  
  pinMode(Buzzerpin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  cm=0.01723*readUltrasonicDistance(7,6);
  inches=(cm/2.54);
  long frequency1=300;
  long frequency2=100;
  lcd.clear();
  lcd.setCursor(0,0);lcd.print(cm);lcd.print("cm");
  lcd.setCursor(0,1);lcd.print(inches);lcd.print("inches");
  delay(10);
  Serial.println(inches);
  Serial.println("in");
  Serial.println(cm);
  Serial.println("cm");
  if(cm<30&&cm>10)
  {
   tone(Buzzerpin,frequency2);
   analogWrite(LEDpin,63);
  }
  else if(cm<10)
  {
    tone(Buzzerpin,frequency1);
    analogWrite(LEDpin,255);
  }
  else if(cm>=30)
  {
   analogWrite(LEDpin,0); 
   noTone(Buzzerpin);
  }
}