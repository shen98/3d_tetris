#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "GlobalDefinitions.h"

class Button
{
public:
    Button(float topLeftX, float topLeftY, float width, float height, std::string buttonLabel, bool clicked = false, bool highlighted = false);
    ~Button();
    
    void draw();
    bool checkClicked(float posX, float posY);
private:
    void drawButton();
    bool test(float posX, float posY);

private:
    float topLeftX;
    float topLeftY;
    float width;
    float height;
    std::string buttonLabel;
    bool clicked;               /* state of the button, true if pressed, false otherwise */
    bool highlighted;          /* is the mouse cursor over the button */

};

#endif
