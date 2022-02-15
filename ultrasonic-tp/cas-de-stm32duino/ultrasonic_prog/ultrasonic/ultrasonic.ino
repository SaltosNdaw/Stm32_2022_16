#include <Wire.h>
#include "Ultrasonic.h"
#include "rgb_lcd.h"

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
int i;
Ultrasonic ultrasonic(7);
void setup()
{
    Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}
void loop()
{
    long RangeInCentimeters;
 
    Serial.println("The distance to obstacles in front is: "); 
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    Serial.print(RangeInCentimeters);//0~400cm
    Serial.println(" cm");
    delay(250);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("The distance is:");
    lcd.setCursor(1, 1);
    for(i=0; i< 16; i++) lcd.print("");
    lcd.print(RangeInCentimeters);
    lcd.setCursor(6, 1);
    lcd.print("cm");
    delay(100);


 
}
