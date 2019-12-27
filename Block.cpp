#include "Block.h"
#include "GlobalDeclarations.h"
#include "Utility.h"
#include <vector>

Block::Block() 
{

    this->speedLevel = 0;
}

Block::~Block() {}

void Block::init()
{
    this->speedY = 0.03f;
    this->blockID = 0;
    this->blockType = -1;
    this->posX = 0.0f;
    this->posZ = 0.0f;
    this->posY = startHeight;
    this->gameState = true;
    scene = new Scene();

    initBlocks(); 
}

void Block::generateBlock()
{
    this->rotateAngle = 0.0f;
    this->posX = 0.0f;
    this->posZ = 0.0f;
    this->posY = startHeight;
    blockType = rand() % blocks.size();
    blockType = 1;
    blockID = glGenLists(1);
    glNewList(blockID, GL_COMPILE);
        for(auto p : blocks[blockType].points)
        {
            glPushMatrix();
                glTranslatef(p[0] * blockSize, p[1] * blockHeight, 0.0f);
                makeCube(blockSize, blockHeight, blocks[blockType].color);
            glPopMatrix();
        }
               
    glEndList();
}


void Block::rotate(bool isClockwise)
{
    if(isClockwise) {
        this->rotateAngle -= 90.0f;
        if(!canMoveTo(this->posX / blockSize + mapSize, this->posY, this->posZ / blockSize + mapSize)) this->rotateAngle += 90.0f;
    }
    else { 
        this->rotateAngle += 90.0f;
        if(!canMoveTo(this->posX / blockSize + mapSize, this->posY, this->posZ / blockSize + mapSize)) this->rotateAngle -= 90.0f;
    }
}

void Block::moveX(bool isPositive)
{
    if(isPositive) {
        if(canMoveTo((this->posX + blockSize) / blockSize + mapSize, this->posY, this->posZ / blockSize + mapSize)) this->posX += 1.0f * blockSize;
    } else {
        if(canMoveTo((this->posX - blockSize) / blockSize + mapSize, this->posY, this->posZ / blockSize + mapSize)) this->posX -= 1.0f * blockSize;
    }
}

void Block::moveZ(bool isPositive)
{
     if(isPositive) {
        //if(canMoveTo(this->posX + 1, this->posZ)) 
        if(canMoveTo(this->posX / blockSize + mapSize, this->posY, (this->posZ + blockSize) / blockSize + mapSize)) this->posZ += 1.0f;
    } else {
        if(canMoveTo(this->posX / blockSize + mapSize, this->posY, (this->posZ - blockSize) / blockSize + mapSize)) this->posZ -= 1.0f;
    }   
}

void Block::accelerate(bool activated)
{
    if(activated) this->speedY = 0.2f;
    else this->speedY = 0.03f * (this->speedLevel + 1);
}

void Block::move()
{
    if(this->rotateAngle >= 360.0f) this->rotateAngle -= 360.0f;
    else if(this->rotateAngle <= -360.0f) this->rotateAngle += 360.0f;

    this->posY -= this->speedY;
    if(this->posY <= blockHeight * (blocks[blockType].height - 1)) this->posY = blockHeight * (blocks[blockType].height - 1);
}

void Block::draw()
{
    glPushMatrix();
    glTranslatef(this->posX, this->posY, this->posZ);
    glRotatef(rotateAngle, 0.0f, 1.0f, 0.0f);
    glCallList(blockID);
    glPopMatrix();

    glPushMatrix();
        scene->drawScene();
    glPopMatrix();

    glPushMatrix();
        drawText(200, 100, 0.25, 0.25, "Score:" + std::to_string(scene->getScore()));
        drawText(10, 500, 0.25, 0.25, "Level:" + std::to_string(this->speedLevel + 1));
    glPopMatrix();
    /*glDisable(GL_TEXTURE_2D); //added this*/
    //glMatrixMode(GL_PROJECTION);
    //glPushMatrix();
    //glLoadIdentity();
    //gluOrtho2D(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT);
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();
    //glLoadIdentity();
    //glRasterPos2i(10, 10);
    //std::string s = "Score: " + std::to_string(scene->getScore());
    //void * font = GLUT_BITMAP_9_BY_15;
    //glScalef(1.0,1.0,2.0);
    //for (std::string::iterator i = s.begin(); i != s.end(); ++i)
    //{
        //char c = *i;
        //glutStrokeCharacter(GLUT_STROKE_ROMAN,c); 
        ////glutBitmapCharacter(font, c);
    //}
    //glMatrixMode(GL_PROJECTION); //swapped this with...
    //glPopMatrix();
    //glMatrixMode(GL_MODELVIEW); //...this
    //glPopMatrix();
    ////added this
    /*glEnable(GL_TEXTURE_2D);*/

}

void Block::updateLevel(int level)
{
    this->speedLevel = level;
    this->speedY = 0.03f * (this->speedLevel + 1);

}
bool Block::canMoveTo(int posX, float posY, int posZ)
{
    auto blockInfo = getCurBlockInfo();
    auto sceneVec = scene->getSceneVec();
    for(auto p : blockInfo.points)
    {
        if(posX + p[0] < 0 || posX + p[0] >= sceneVec.size() || posZ - p[2] < 0 || posZ - p[2] >= sceneVec[0].size()) return false;             // check x and z
        if(sceneVec[p[0] + posX][posZ - p[2]][converterY(posY, p[1] - 1)] >= 0) return false;
    }
    return true;
}

bool Block::generateNewBlock()
{
/*    if(this->posY == blockHeight) {*/
        //auto block = getCurBlockInfo();
        //auto sceneVec = scene->getSceneVec();
        //bool reachedLand = false;

        //for(auto info : block.points) {

            ////std::cout << this->posX / blockSize + mapSize + info[0] << " " << this->posY / blockHeight + info[1] << " " << this->posZ / blockSize + mapSize + info[2] << std::endl;
            //scene->updateSceneVec(this->posX / blockSize + mapSize + info[0], this->posY / blockHeight + info[1], this->posZ / blockSize + mapSize - info[2], true);
        //}
    /*}*/
    if(this->blockType == -1) return true;

    bool temp = checkLand();
    return temp;
}

int Block::getScore()
{
    return scene->getScore();
}

bool Block::isGameOver()
{
    return !this->gameState;
}

bool Block::checkLand()
{ 
    auto block = getCurBlockInfo();
    auto sceneVec = scene->getSceneVec();
    bool reachedLand = false;


    for(auto info : block.points) {
        if(this->posY <= blockHeight * (blocks[blockType].height - 1)) { reachedLand = true; break; }
        //if(this->posY <= blockHeight * 3)std::cout << sceneVec[converter(this->posX, info[0])][converter(this->posZ, info[2])][converter(this->posY, -mapSize)] << std::endl;
        if(sceneVec[converter(this->posX, info[0])][converter(this->posZ, -info[2])][converterY(this->posY, info[1] - 1)] >= 0) { 
            //std::cout << converter(this->posX, info[0]) << " " <<  converter(this->posY, -mapSize + info[1] - 1) << " " << converter(this->posZ, info[2])<< std::endl;
            //std::cout << converter(this->posX) << " " <<  this->posY / blockHeight +info[1] - 1 << " " << converter(this->posZ)<< std::endl;
            reachedLand = true; break; 
        }
    }

    if(reachedLand) {
        if(this->posY >= blockHeight * blockSizeHeight) this->gameState = false;
        for(auto info : block.points) {
            //std::cout << this->posX / blockSize + mapSize + info[0] << " " << (int)(this->posY / blockHeight + info[1]) << " " << this->posZ / blockSize + mapSize + info[2] << std::endl;
            scene->updateSceneVec(this->posX / blockSize + mapSize + info[0], this->posY / blockHeight + info[1], this->posZ / blockSize + mapSize - info[2], blockType);
        }
        this->blockType = -1;
    }

    return reachedLand;
/*    std::vector<BlockInfo> blockInfo = getCurBlockInfo();*/
    //auto sceneVec = scene->getSceneVec();
    //bool reachedLand = false;

    //for(auto info : blockInfo)
        /*scene->updateSceneVec(this->posX / blockSize + mapSize + info.posX, this->posY / blockHeight, this->posZ / blockSize + mapSize + info.posZ, true);*/
}

BlockDesc Block::getCurBlockInfo()
{
    BlockDesc block = blocks[blockType];
    for(auto& p : block.points)
    {
        if(rotateAngle == -180.0f || rotateAngle == 180.0f)
        {
            p[0] = 0 - p[0];
            p[2] = 0 - p[2];
            p[0]--;
            p[2]++;
        } else {
    
        int distance = abs(p[0]) + abs(p[2]);
        float angle = atan2(p[2], p[0]) + rotateAngle * PI / 180;
        if(p[0] != 0 || p[2] != 0) {
            p[2] = distance * sin(angle);
            p[0] = distance * cos(angle);
        }
        
        if(rotateAngle == -90.0f || rotateAngle == 270.0f) {p[0]--;}
        else if(rotateAngle == 90.0f || rotateAngle == -270.0f) {p[2] += 1;}
        }
    }
/*    switch(blockType)*/
        //{
        //case TYPE0:
        //{
            //if(rotateAngle == 0.0f || rotateAngle == 360.0f || rotateAngle == -360.0f) { 
                //for()
                //[>blockInfo.push_back(BlockInfo(0, 0, 2));<]
                //[>blockInfo.push_back(BlockInfo(1, 0, 2));<]
            //}
            //else if(rotateAngle == 90.0f || rotateAngle == -270.0f) {
                //[>blockInfo.push_back(BlockInfo(0, -1, 2));<]
                //[>blockInfo.push_back(BlockInfo(0, -2, 2));<]
            //}
            //else if(rotateAngle == 180.0f || rotateAngle == -180.0f) {
               //[> blockInfo.push_back(BlockInfo(-1, -1, 2));<]
                //[>blockInfo.push_back(BlockInfo(-2, -1, 2));<]
            //}
            //else if(rotateAngle == 270.0f || rotateAngle == -90.0f) {
                //[>blockInfo.push_back(BlockInfo(-1, 0, 2));<]
                //[>blockInfo.push_back(BlockInfo(-1, 1, 2));<]
            //}
            //break;
        //}
        /*}*/

    return block;
}

int Block::converter(float val, int extra)
{
    return val / blockSize + mapSize + extra;
}

int Block::converterY(float val, int extra)
{
    return val / blockHeight + extra;
}

void Block::initBlocks()
{
    std::vector<std::vector<int>> vec = {{0, 0, 0}, {1, 0, 0}, {1, -1, 0}, {0, -1, 0}};
    blocks.push_back(BlockDesc(vec, 2, 2, {1.0f, 0.0f, 0.0f, 1.0f}));

    vec = {{1, 0, 0}, {0, -1, 0}, {1, -1, 0}, {2, -1, 0}};
    blocks.push_back(BlockDesc(vec, 3, 2, {1.0f, 1.0f, 0.0f, 1.0f}));


    vec = {{0, 0, 0}, {1, 0, 0}, {1, -1, 0}, {2, -1, 0}};
    blocks.push_back(BlockDesc(vec, 3, 2, {0.0f, 1.0f, 0.0f, 1.0f}));

    //vec = {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}};
    //blocks.push_back(BlockDesc(vec, 4, 1));

    vec = {{1, 0, 0}, {2, 0, 0}, {0, -1, 0}, {1, -1, 0}};
    blocks.push_back(BlockDesc(vec, 3, 2, {0.0f, 0.0f, 1.0f, 1.0f}));
}

