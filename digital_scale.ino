#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int cm , inch , x ;
long ms;
LiquidCrystal_I2C lcd(0x27,16, 2);
void setup() {
  pinMode(2,OUTPUT); // tring
  pinMode(4,INPUT); // echo
  pinMode(7,INPUT_PULLUP); //switch
  Serial.begin(9600); 
  lcd.begin();
  lcd.backlight();
 
  lcd.setCursor(0,0);
  lcd.print("Digital Scale by") ;
  lcd.setCursor(0,1);
  lcd.print("ATALL Robotics");
  delay(3000);
}

void loop() {
  x = digitalRead(7);
  digitalWrite(2,LOW);
  delay(5);
  digitalWrite(2,HIGH); // send ultrasound
  delay(15);
  digitalWrite(2,LOW); // stop sending Ultrasound
  ms = pulseIn(4,HIGH);  // count time ;
  cm = ms/58;
  inch = ms/148; 
if (cm < 200 ){
  if (x == 0){  // display cm value on screen
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance= ");
    lcd.print(cm);
    lcd.print(" cm");
    
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance= ");
    lcd.print(inch);
    lcd.print(" in");
    
  }
}
  delay(200);

}
