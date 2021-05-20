int sensorReading=0;
char data=0;
void setup()
{
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop()
{
  sensorReading=analogRead(A0);
  int lightOutput=map(sensorReading,6,679,225,0);
  Serial.print("LDR Sensor Value:");
  Serial.print(sensorReading);
  int lightPercentage=map(sensorReading,20,950,0,100);
  Serial.print(" Light%:");
  Serial.println(lightPercentage);
  Serial.println(lightOutput);
  analogWrite(11,lightOutput);
  }