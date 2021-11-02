#include "statusBar.h"

statusBar::statusBar(Elegoo_GFX  *display, int16_t h, int16_t w, 
        int8_t textSize, bool visible, int loc, uint16_t borderColor=BLUE, 
        uint16_t fillColor = WHITE, uint16_t textColor = BLUE ){    
    _w = w;
    _h = h;
    _textSize =  textSize;
    _visible = visible;
    _location =  loc; 
    _display = display;
    _fillColor = fillColor;
    _borderColor = borderColor;
    _textColor = textColor;
    _status = "  ";
}

statusBar::~statusBar()
{
}

void statusBar::printStatus()
{  
    Serial.println(_status);
    _display->setTextSize(_textSize);
    _display->setTextColor(_textColor);

    if(_location == BOTTOM)
        _display->setCursor(2,_display->height()-14); 
   

    for (int i = 0; i < strlen(_status); i++)
    {
        _display->write(_status[i]);
    }
    return;
}

void statusBar::setStatus(char* status)
{   
    Serial.println("status updated"); 
    strcpy(_status, status);
    return;
}

void statusBar::draw() {
    if(_location == BOTTOM)
    {
        _display->drawRect(0,_display->height()-_h,_w,_h, _borderColor);
        _display->fillRect(1,_display->height()-_h-1,_w-2,_h-2, _fillColor);
    }
    else
    {
        _display->drawRect(0,0,_w,_h,_borderColor);
        _display->fillRect(1,1,_w-2,_h-2, _fillColor);
    }
    return;

}