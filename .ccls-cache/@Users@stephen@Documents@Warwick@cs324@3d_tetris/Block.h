#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "GlobalDefinitions.h"
#include "Utility.h"
#include "Scene.h"
#include <algorithm>
#include <cmath>

enum BLOCKTYPE
{
    TYPE0 = 0,      // 2 + 2
    TYPE1 = 1,      // 4
    TYPE2 = 2       // 1 + 3
};

struct BlockDesc {
    std::vector<std::vector<int>> points;
    int width = 0, height = 0;
    std::vector<float> color;

    BlockDesc(std::vector<std::vector<int>> points, int width, int height, std::vector<float> color):
        points(points), width(width), height(height), color(color) {}
};

class Block
{
public:
    Block();
    ~Block();

    void init();
    void generateBlock();
    void rotate(bool isClockwise);
    void moveX(bool isPositive);
    void moveZ(bool isPositive);
    void accelerate(bool activated);

    void move();
    void draw();

    bool generateNewBlock();
    bool isGameOver();
    int getScore();

    void updateLevel(int level);
private:
    void initBlocks();
    bool canMoveTo(int posX, float posY, int posZ);
    bool checkLand();

    int converter(float val, int extra = 0);
    int converterY(float val, int extra = 0);
    BlockDesc getCurBlockInfo();

    void drawBlock();
private:
    float rotateAngle;
    float posX, posY, posZ;
    float speedY;
    int speedLevel;
    size_t blockID;
    int blockType;

    bool gameState;                 // false - game over, true otherwise

    Scene* scene;

    std::vector<BlockDesc> blocks;
};

#endif
