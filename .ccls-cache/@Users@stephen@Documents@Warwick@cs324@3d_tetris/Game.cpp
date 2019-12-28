#include "Game.h"
#include "GlobalVariables.h"
Game::Game() 
{
    this->cameraAngle = 0.0f;
    this->distanceFromCameraToOrigin = 12;
    this->distanceFromLookatToOrigin = 8;
    this->cameraPosX = 10.0f;
    this->cameraPosY = 6.0f;
    this->cameraPosZ = 0.0f;
    this->lookatPosX = 0.0f;
    this->lookatPosY = 0.0f;
    this->lookatPosZ = 0.0f;
    this->gameState = 0;
    block = new Block();
    block->init();
    level = new Level();
    control = new Control();
}

Game::~Game() {}

bool Game::init()
{	
    glClearColor(bgColor[0], bgColor[1], bgColor[2], bgColor[3]);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, CAMERA_ZNEAR, CAMERA_ZFAR);
    //glOrtho(-2.0, 2.0, -2.0, 2.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);

/*    glEnable(GL_LIGHTING);*/
    //glEnable(GL_LIGHT0);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHT1);
    //glEnable(GL_COLOR_MATERIAL);
    /*glEnable(GL_NORMALIZE);*/
/*    glShadeModel(GL_SMOOTH);*/
    //glDisable(GL_BLEND);
    /*glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    Button* button = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT * 5 / 7.0,SCREEN_WIDTH / 3.0,SCREEN_HEIGHT / 7.0, "Start");
    buttons.push_back(button);
    Button* levelButton = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT * 3 / 7.0,SCREEN_WIDTH / 3.0,SCREEN_HEIGHT / 7.0, "Level");
    buttons.push_back(levelButton);
    Button* controlButton = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT / 7.0,SCREEN_WIDTH / 3.0,SCREEN_HEIGHT / 7.0, "Control");
    buttons.push_back(controlButton);

    restartButton = new Button(SCREEN_WIDTH / 3.0, SCREEN_HEIGHT / 6.0, SCREEN_WIDTH / 3.0f, SCREEN_HEIGHT / 6.0f, "Restart");
}

bool Game::loop()
{
    return true; 
}

void Game::handleKeyboard(unsigned char key, int x, int y, bool press)
{
    if(gameState != 2) return;

    switch (key) { 
        case 'w': {
            if(press) {
                if(cameraAngle <= 135 && cameraAngle > 45) block->moveX(false);
                else if(cameraAngle <= 225 && cameraAngle > 135) block->moveZ(true);
                else if(cameraAngle <= 315 && cameraAngle > 225) block->moveX(true);
                else block->moveZ(false);
            }
            break;
        } 
        case 'd': { 
            if(press) {
                if(cameraAngle <= 135 && cameraAngle > 45) block->moveZ(false);
                else if(cameraAngle <= 225 && cameraAngle > 135) block->moveX(false);
                else if(cameraAngle <= 315 && cameraAngle > 225) block->moveZ(true);
                else block->moveX(true);
            }
            break; 
        } 

        case 'a': { 
            if(press) {
                if(cameraAngle <= 135 && cameraAngle > 45) block->moveZ(true);
                else if(cameraAngle <= 225 && cameraAngle > 135) block->moveX(true);
                else if(cameraAngle <= 315 && cameraAngle > 225) block->moveZ(false);
                else block->moveX(false);
            }
            break; 
        } 

        case 's': { 
            if(press) {
                if(cameraAngle <= 135 && cameraAngle > 45) block->moveX(true);
                else if(cameraAngle <= 225 && cameraAngle > 135) block->moveZ(false);
                else if(cameraAngle <= 315 && cameraAngle > 225) block->moveX(false);
                else block->moveZ(true);
            }
            break;
        } 

        case 'q': { 
            if(press) block->rotate(false);
            break; 
        } 

        case 'e': { 
            if(press) block->rotate(true);
            break; 
        }
        case ' ': {
            if(press) block->accelerate(true);
            else block->accelerate(false);
            break;
        }
        case 'z': { 
            if(press) cameraAngle += 5.0f;
            if(cameraAngle > 360) cameraAngle -= 360;
            break; 
        }
        case 'c': { 
            if(press) cameraAngle -= 5.0f;
            if(cameraAngle < 0) cameraAngle += 360;
            break; 
        }
        default: { 
        } 
        break; 
    }  
}

void Game::handleSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
    
}

void Game::handleMouse(int button, int state, int x, int y)
{

    if(state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            if(this->gameState == MAINMENU) {
                for(int i = 0; i < buttons.size(); ++i) {
                    if(buttons[i]->checkClicked(x, SCREEN_HEIGHT - y)) {
                        if(i == 0) { this->gameState = GAME; block->init(); }
                        else if(i == 1) { this->gameState = LEVELMENU; }
                        else if(i == 2) { this->gameState = CONTROL; }
                    }
                }
            } else if(this->gameState == LEVELMENU) {
                int selectedLevel = level->getLevel(x, SCREEN_HEIGHT - y);
                if(selectedLevel != -1) { 
                    this->gameState = MAINMENU;
                    std::cout << selectedLevel << std::endl;
                    block->updateLevel(selectedLevel);
                }
            } else if(this->gameState == GAMEOVER) {
                if(restartButton->checkClicked(x, SCREEN_HEIGHT - y)) this->gameState = MAINMENU;
            } else if(this->gameState == CONTROL) {
                if(control->returnButtonClicked(x, SCREEN_HEIGHT - y)) this->gameState = MAINMENU;
            }
        }
    }
}

void Game::handleMouseMotion(int x, int y)
{
    
}

bool Game::process()
{
   
}

void Game::reshape(int w, int h)
{
    
}

void Game::render()
{
        //glFogfv(GL_FOG_COLOR, bgColor);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    calcCamera();
    gluLookAt(cameraPosX, cameraPosY, cameraPosZ,
            lookatPosX, lookatPosY, lookatPosZ, 
            0.0, 1.0, 0.0);

    glPushMatrix();
        
    if(gameState == GAME)
    {
   /*     GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)*/
		//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
		
		////Add positioned light
		//GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
		//GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
		//glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
		//glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
		
		////Add directed light
		//GLfloat lightColor1[] = {0.2f, 0.2f, 1.0f, 1.0f}; //Color (0.5, 0.2, 0.2)
		////Coming from the direction (-1, 0.5, 0.5)
		//GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
		//glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
		//glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

        makeGrid(mapSize, blockSize);

    glPopMatrix();
   
    if(block->generateNewBlock()) block->generateBlock();
    if(block->isGameOver()) { this->gameState = 3; return;}
    glPushMatrix();
        block->draw();
    glPopMatrix();

/*    glPushMatrix();*/
        //scene->drawScene();
    /*glPopMatrix();*/
    } 
    else if(gameState == MAINMENU)
    {
        for(auto button : buttons)
            button->draw();

    }
    else if(gameState == LEVELMENU)
    {
        level->draw();
    }
    else if(this->gameState == GAMEOVER)
    {
        drawText(SCREEN_WIDTH / 6.0, SCREEN_HEIGHT * 3 / 4.0, 0.5f, 0.5f, "Game Over"); 
        drawText(SCREEN_WIDTH / 6.0, SCREEN_HEIGHT * 2 / 4.0, 0.5f, 0.5f, "Your score is: " + std::to_string(block->getScore()));
        restartButton->draw();
    }
    else if(this->gameState == CONTROL)
    {
        control->drawControlPage(); 
    }
    glutSwapBuffers();
}

void Game::update()
{
    block->move();
}

void Game::calcCamera()
{
    this->cameraPosX = sin(this->cameraAngle * PI / 180) * this->distanceFromCameraToOrigin;
    this->cameraPosZ = cos(this->cameraAngle * PI / 180) * this->distanceFromCameraToOrigin;
}
