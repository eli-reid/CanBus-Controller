#ifndef  _STATUSBAR_H
#define  _STATUSBAR_H

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#include <string.h>
#include <Elegoo_GFX.h>
enum location_enum {TOP,BOTTOM};
class statusBar
{ 
    private:
        int16_t _w, _h, _fillColor, _borderColor, _textColor;
        int8_t _textSize, _location;
        bool _visible;
        char* _status;
        Elegoo_GFX  *_display;

    public:
    
        statusBar(Elegoo_GFX *display, int16_t h, int16_t w, 
            int8_t textSize, 
            bool visible,  
            int loc, 
            uint16_t borderColor = BLUE, 
            uint16_t fillColor = WHITE,
            uint16_t textColor = BLUE );

        ~statusBar();
        void printStatus();
        void setStatus(char* status);
        void draw();
        //TODO: add clicked events
};

#endif