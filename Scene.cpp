#include "Scene.h"
#include "GlobalDeclarations.h"
#include "Utility.h"
#include <cmath>

Scene::Scene()
{
    this->score = 0;
    sceneVec = std::vector<std::vector<std::vector<int>>>(mapSize * 2, std::vector<std::vector<int>>(mapSize * 2, std::vector<int>(blockSizeHeight, -1)));
}

Scene::~Scene() {}

void Scene::drawScene()
{
    checkFullLine();

    glPushMatrix();
    for(int i = 0; i < sceneVec.size(); ++i)
    {
        for(int j = 0; j < sceneVec[0].size(); ++j)
        {
            for(int k = 0; k < sceneVec[0][0].size(); ++k)
                if(sceneVec[i][j][k] >= 0) drawCubes(blockSize * (i - mapSize), blockHeight * k, blockSize * (j - mapSize), sceneVec[i][j][k]); 
        }
    }
    
    glPopMatrix();
}

void Scene::drawCubes(float posX, float posY, float posZ, int blockType)
{
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    //std::cout << blockType << std::endl;
    makeCube(blockSize, blockHeight, blockColor[blockType]);
    glPopMatrix();
}

std::vector<std::vector<std::vector<int>>> Scene::getSceneVec() const
{
    return this->sceneVec;
}

void Scene::updateSceneVec(int posX, int posY, int posZ, int blockType)
{
    this->sceneVec[posX][posZ][posY] = blockType;
}

void Scene::checkFullLine()
{
    for(int y = 0; y < sceneVec[0][0].size(); ++y)
    {
        int completeTime = 0;
        for(int x = 0; x < sceneVec.size(); ++x)
        {
            for(int z = 0; z < sceneVec[0].size(); ++z)
            {
                if(sceneVec[x][z][y] == -1) break;
                if(z == sceneVec[0].size() - 1) {
                    completeTime++; 
                    cleanRow(x, y); 
                }
            }
        }
        for(int z = 0; z < sceneVec[0].size(); ++z)
        {
            for(int x = 0; x < sceneVec.size(); ++x)
            {
                if(sceneVec[x][z][y] == -1) break;
                if(x == sceneVec.size() - 1) {
                    completeTime++;
                    cleanColumn(z, y); 
                }
            }
        }
        completeTime > 0 ? this->score += pow(2, completeTime) : 0;
    }
}

void Scene::cleanRow(int x, int prevY)
{
    for(int z = 0; z < sceneVec[0].size(); ++z)
    {
        for(int y = prevY + 1; y < sceneVec[0][0].size(); ++y)
        {
            sceneVec[x][z][y - 1] = sceneVec[x][z][y];
        }
        sceneVec[x][z].back() = -1;
    }
}

void Scene::cleanColumn(int z, int prevY)
{
    for(int x = 0; x < sceneVec.size(); ++x)
    {
        for(int y = prevY + 1; y < sceneVec[0][0].size(); ++y)
        {
            sceneVec[x][z][y - 1] = sceneVec[x][z][y];
        }
        sceneVec[x][z].back() = -1;
    } 
}

int Scene::getScore() const
{
    return this->score;
}
