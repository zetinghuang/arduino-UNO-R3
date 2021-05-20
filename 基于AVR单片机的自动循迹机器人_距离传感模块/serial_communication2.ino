#include <LiquidCrystal.h>//包含LCD的头文件
char comdata;
int i;
LiquidCrystal lcd(12,11,5,4,3,2);//定义LCD各个接口所连接的IO口
void setup()
{
    Serial.begin(9600);//设置接收串口波特率为9600
    pinMode(13,OUTPUT);
  	lcd.begin(16,2);//设置LCD的显示为16x2；
}
 
void loop()
{	
  
  lcd.setCursor(0,0);lcd.print("status");
    while (Serial.available() > 0)  //当串口接收到数据时执行下面语句
    {
        comdata =Serial.read();//将从串口中读取的一个字节数据保存到变量中
     	delay(100);	//延迟，使得数据能完整读取
      	Serial.println(comdata,DEC); //将将数据以10进制的形式解码，发送到串行监视口，方便检测是否正确读取

//接收到不同的数据时，LCD和指示灯呈现不同的状态
    if(comdata==2)
    {
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);lcd.print("move");
   	 delay(100);
     lcd.setCursor(0,1);lcd.print("    ");
      
      
    }
      else if(comdata==0)
    {
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);lcd.print("warning");
   	 delay(100);
     lcd.setCursor(0,1);lcd.print("       ");
        
    }
      else if (comdata==1)
      {
       digitalWrite(13,HIGH);
       lcd.setCursor(0,1);lcd.print("stop");
   	   delay(100);
       lcd.setCursor(0,1);lcd.print("    ");
       
      }
      
    }
  
}