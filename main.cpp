#include "main.h"

Elegoo_TFTLCD screen(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
statusBar statbar(&screen,20,screen.width(),1,true, BOTTOM, BLUE, WHITE);
uint16_t identifier = screen.readID();  
void setup(){
        Serial.begin(9600);
        screen.reset();
        screen.begin(identifier);
        screen.setRotation(2);
        screen.fillScreen(BLACK);
        Serial.print("hello!");
        int hight = screen.height()-50;
        Serial.println(hight);
        statbar.draw();
        statbar.setStatus("Status: Edog");
        statbar.printStatus();
        }
void loop(){


        delay(2100);
    
}