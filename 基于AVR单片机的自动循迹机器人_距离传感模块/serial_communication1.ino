int cm=0; //LCD1602上的距离以厘米显示
char com;//定义一个字符变量，在串口通信时进行数据传递

long readUltrasonicDistance(int triggerPin, int echoPin)//超声波触发以及信号收集函数,triggerPin和echoPin分别对应HC-SR04的trigger和echo引脚
{
 pinMode(triggerPin,OUTPUT);//设置和trigger所连接的IO口是输出模式，进行信号输出
 digitalWrite(triggerPin,LOW);//先向trigger引脚输出低电平,延时2秒
 delayMicroseconds(2);
 digitalWrite(triggerPin, HIGH);//向trigger输出高电平，延时10秒后拉低，制造脉冲信号
 delayMicroseconds(10);
 digitalWrite(triggerPin,LOW);
 pinMode(echoPin,INPUT);
  return pulseIn(echoPin,HIGH); //接收高电平的持续时间并返回
}
void setup()
{
  Serial.begin(9600);//设置串口波特率为9600，无需校验位
  
}
void loop() 
{ 
  cm=0.01723*readUltrasonicDistance(7,6);//将高电平时间转化为厘米

//在不同的距离范围对com附以不同的值

if(cm<30&&cm>10)
  {
  com=0;   
}
  else if(cm<10)
  {
    com=1;
   
  }
  else if(cm>=30)
{
    com=2;     
  }
  Serial.print(com);//向串口发送一个字节的数据,在Arduino上，UART串口通信会将发送的一个字节数据根据ASCII码转化为对应的字符,进行加密。

}
