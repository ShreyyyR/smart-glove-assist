#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>
const int xpin = A0;                  
const int ypin = A1;                  
const int zpin = A2;                  
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
  Wire.begin();
  oled.init();
  oled.clearDisplay();
  oled.setTextXY(0, 1);
  // Display static text
  oled.putString("Hello, world!");
  delay(1000);
}
void loop() 
{
  adxl();
}
void adxl()
{
 int x = analogRead(xpin);  //read from xpin
 int y = analogRead(ypin);  //read from ypin
Serial.print(x); 
Serial.print("\t");
Serial.print(y);
Serial.print("\t"); 
Serial.print("\n");
delay(500);
if(x<300)
{
  Serial.println("NEED HELP!");
  oled.init();
  oled.clearDisplay();
  oled.setTextXY(0, 1);
  // Display static text
  oled.putString("NEED HELP!");
  delay(1000); 
}
else if(x>400)
{
   Serial.println("FOOD/WATER");
  oled.init();
  oled.clearDisplay();
  oled.setTextXY(0, 1);
  // Display static text
  oled.putString("FOOD/WATER");
  delay(1000); 
}
else if( x>360 && y>360)
{
   Serial.println("WASHROOM");
  oled.init();
  oled.clearDisplay();
  oled.setTextXY(0, 1);
  // Display static text
  oled.putString("WASHROOM");
  delay(1000); 
}
else if(x>300 && (y> 360))
{
   Serial.println("MEDICINE");
  oled.init();
  oled.clearDisplay();
  oled.setTextXY(0, 1);
  // Display static text
  oled.putString("MEDICINE");
  delay(1000); 
}
else 
{
   Serial.println("NOSIGN");
  oled.init();
  oled.clearDisplay();
  oled.setTextXY(0, 1
  );
  // Display static text
  oled.putString("NOSIGN");
  delay(1000); 
}
}
