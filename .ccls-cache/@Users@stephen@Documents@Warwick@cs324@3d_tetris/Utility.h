#ifndef _UTILITY_H_
#define _UTILITY_H_

#include "GlobalDefinitions.h"

void makeGrid(float mapSize, float blockSize);
void makeCube(float cubeSize, float cubeHeight, std::vector<float> color);
void drawText(float posX, float posY, float scaleX, float scaleY, std::string text);
#endif
