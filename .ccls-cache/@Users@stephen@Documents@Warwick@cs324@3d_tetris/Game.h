#ifndef _Game_H_
#define _Game_H_

#include "GlobalDefinitions.h"
#include "Utility.h"
#include "Block.h"
#include "Control.h"
#include "Level.h"
#include <cmath>

enum STATE
{
    MAINMENU = 0,
    LEVELMENU = 1,
    GAME = 2,
    GAMEOVER = 3,
    CONTROL = 4
};

class Game
{
public:
    Game();
    virtual ~Game();

    bool init();
    bool loop();

    void handleKeyboard(unsigned char key, int x, int y, bool press);
    void handleSpecialKeyboard(unsigned char key, int x, int y, bool press);
    void handleMouse(int button, int state, int x, int y);
    void handleMouseMotion(int x, int y);

    bool process();
    
    void reshape(int w, int h);
    void render();
    void update();

private:
    void calcCamera();

private:
    Block* block;
    Level* level;
    Control* control;
    std::vector<Button*> buttons;
    Button* restartButton;

    float cameraAngle, distanceFromLookatToOrigin, distanceFromCameraToOrigin;

    float cameraPosX, cameraPosY, cameraPosZ;
    float lookatPosX, lookatPosY, lookatPosZ;

    int gameState;              // 0 - menu, 1 - level menu, 2 - game, 3 - game over 

    
};

#endif
