#ifndef _GLOBAL_VARIABLES_H_
#define _GLOBAL_VARIABLES_H_

#include <vector>

float CAMERA_ZFAR = 200.0f;
float CAMERA_ZNEAR = 1.0f;

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

// map values
int mapSize = 3;

// block values
float blockSize = 1;
float blockSizeHeight = 8;
float blockHeight = blockSize * ((float)SCREEN_HEIGHT / (float)SCREEN_WIDTH);
float startHeight = blockSizeHeight * blockHeight;

    
float bgColor[] = {0.2f, 0.58f, 0.79f, 0.7f};

std::vector<std::vector<float>> blockColor = {{1.0f, 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}};

#endif
