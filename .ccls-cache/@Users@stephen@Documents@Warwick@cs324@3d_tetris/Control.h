#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "GlobalDefinitions.h"
#include "Button.h"

enum KEYBOARDFUNC
{
    LEFT = 0,
    RIGHT = 1,
    AWAY = 2,
    CLOSE = 3,
    SPINPIECE = 4,
    SPINPIECEA = 5,
    SPEEDUP = 6,
    SPINCAMERA = 7,
    SPINCAMERAA = 8
};

class Control
{
public:
    Control();
    ~Control();
    
    void drawControlPage();
    bool returnButtonClicked(float posX, float posY);
private:
    void draw();

private:
    std::vector<std::string> texts = {"Move Left:", "Move Right:", "Move Away:", "Move Close:", 
        "Spin Piece Clockwise:", "Spin Piece Anti-clockwise:", "Speed Up:",
        "Spin Camera Clockwise:", "Spin Camera Anti-clockwise:"};

    std::vector<char> keyboards = {'a', 'd', 'w', 's', 'e', 'q', ' ', 'c', 'z'};

    Button* returnButton;
};

#endif
