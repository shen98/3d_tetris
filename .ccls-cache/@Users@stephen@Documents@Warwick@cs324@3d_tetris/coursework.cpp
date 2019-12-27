#include "Game.h"
#include "GlobalDeclarations.h"
Game Game;

void AppReshape(int w, int h)
{
	Game.reshape(w,h);
}

void AppRender()
{
	Game.render();
}

void AppKeyboard(unsigned char key, int x, int y)
{
	Game.handleKeyboard(key,x,y,true);
}

void AppKeyboardUp(unsigned char key, int x, int y)
{
	Game.handleKeyboard(key,x,y,false);
}

void AppSpecialKeys(int key, int x, int y)
{
	Game.handleSpecialKeyboard(key,x,y,true);
}

void AppSpecialKeysUp(int key, int x, int y)
{
	Game.handleSpecialKeyboard(key,x,y,false);
}

void AppMouse(int button, int state, int x, int y)
{
	Game.handleMouse(button,state,x,y);
}

void AppMouseMotion(int x, int y)
{
	Game.handleMouseMotion(x,y);
}

void AppIdle()
{
	if(!Game.loop()) exit(0);
}

void update(int value)
{
glutPostRedisplay();
   Game.update();
   glutTimerFunc(25, update, 0);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); 

	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH); 

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); 
	glutInitWindowPosition(50, 50); 

	glutCreateWindow("3D Tetris");
  
    Game.init();
    glutKeyboardFunc(AppKeyboard); 
    glutKeyboardUpFunc(AppKeyboardUp);
    glutSpecialFunc(AppSpecialKeys);
    glutSpecialUpFunc(AppSpecialKeysUp);
    glutReshapeFunc(AppReshape); 
    glutDisplayFunc(AppRender); 
    glutMouseFunc(AppMouse);
    glutMotionFunc(AppMouseMotion);
    glutPassiveMotionFunc(AppMouseMotion);

    glutTimerFunc(25, update, 0);
	glutMainLoop(); 

	return 0; 
}
