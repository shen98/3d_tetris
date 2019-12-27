#ifndef _SCENE_H_
#define _SCENE_H_


#include "GlobalDefinitions.h"
#include "Utility.h"

class Scene
{
public:
    Scene();
    ~Scene();

    void drawScene();
    void updateSceneVec(int posX, int posY, int posZ, int blockType);
    std::vector<std::vector<std::vector<int>>> getSceneVec() const;
    int getScore() const;
private:
    void drawCubes(float posX, float posY, float posZ, int blockType);
    void checkFullLine();
    void cleanRow(int x, int y);
    void cleanColumn(int z, int y);
private:
    int score;
    std::vector<std::vector<std::vector<int>>> sceneVec;
};

#endif
