#ifndef _GLOBAL_DECLARATIONS_H_
#define _GLOBAL_DECLARATIONS_H_

#include "GlobalDefinitions.h"

extern float CAMERA_ZFAR;
extern float CAMERA_ZNEAR;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern int mapSize;

extern float blockSize;
extern float blockSizeHeight;
extern float blockHeight;
extern float startHeight;

extern float screenShakeMagnitude;

extern float bgColor[];

extern std::vector<std::vector<float>> blockColor;

//extern std::vector<std::vector<int>> sceneVec; 
#endif
