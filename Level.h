#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "GlobalDefinitions.h"
#include "Button.h"

class Level
{
public:
    Level();
    ~Level();

    void draw();
    int getLevel(int posX, int posY);
private:
    void drawLevelButtons();

private:
    int level;
    std::vector<Button*> levelButtons;
};

#endif
