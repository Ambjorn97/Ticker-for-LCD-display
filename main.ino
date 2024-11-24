#include <Adafruit_LiquidCrystal.h>


Adafruit_LiquidCrystal lcd(0);
String message = "Enter any message you want to run.";
String space = "               ";
String result = message + space;
int messageLength;
int position=0;

void setup() {
  
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  messageLength = result.length();
  
}

void loop() {
  if(position == messageLength){
    lcd.clear();
    position = 0;
  }
  
  for(int i =15 ; i>=0; i--){
 
    lcd.setCursor(i, 0);
    
    if((position-(15-i)<0) || (position-(15-i))>=messageLength){
    	continue;
    }
    lcd.print(result.charAt(position-(15-i)));
    
  }
  position++;
}