#include "Level.h"
#include "GlobalDeclarations.h"

Level::Level() 
{
    Button* level1 = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT * 7 / 9.0,SCREEN_WIDTH / 3.0,SCREEN_HEIGHT / 9.0, "Level 1");
    levelButtons.push_back(level1);
    Button* level2 = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT * 5 / 9.0,SCREEN_WIDTH / 3.0,SCREEN_HEIGHT / 9.0, "Level 2");
    levelButtons.push_back(level2);
    Button* level3 = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT * 3 / 9.0,SCREEN_WIDTH / 3.0,SCREEN_HEIGHT / 9.0, "Level 3");
    levelButtons.push_back(level3);
    Button* level4 = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT * 1 / 9.0,SCREEN_WIDTH / 3.0,SCREEN_HEIGHT / 9.0, "Level 4");
    levelButtons.push_back(level4);
}

Level::~Level() {}

void Level::draw()
{
    drawLevelButtons();
}

int Level::getLevel(int posX, int posY)
{
    int selectedLevel = -1;
    for(int i = 0; i < levelButtons.size(); ++i)
    {
        if(levelButtons[i]->checkClicked(posX, posY)) selectedLevel = i;
    }
    return selectedLevel;
}

void Level::drawLevelButtons()
{
    for(auto button : levelButtons)
        button->draw();
}
