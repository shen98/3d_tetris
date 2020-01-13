#include "Utility.h"
#include "GlobalDeclarations.h"
void makeGrid(float mapSize, float blockSize)
{
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

    glBegin(GL_LINES);
    for(int i = -mapSize; i <= mapSize; ++i)
    {
        glVertex3f(i * blockSize, 0, -mapSize * blockSize);
        glVertex3f(i * blockSize, 0, mapSize * blockSize);

        glVertex3f(mapSize * blockSize, 0, i * blockSize);
        glVertex3f(-mapSize * blockSize, 0, i * blockSize);
    }
    glEnd();
}

void makeCube(float cubeSize, float cubeHeight, std::vector<float> color)
{
    static float vertices[8][3] = 
    {
        {0.0f, 0.0f, 0.0f}, // front
        {1.0f * cubeSize, 0.0f, 0.0f},
        {1.0f * cubeSize, 1.0f * cubeHeight, 0.0f},
        {0.0f, 1.0f * cubeHeight, 0.0f},
        {0.0f, 0.0f, 1.0f * cubeSize}, // back 
        {1.0f * cubeSize, 0.0f, 1.0f * cubeSize},
        {1.0f * cubeSize, 1.0f * cubeHeight, 1.0f * cubeSize},
        {0.0f, 1.0f * cubeHeight, 1.0f * cubeSize}
    };

    // indices into verices
    static size_t faces[6][4] =
    {
        {0, 1, 2, 3},  // front
        {5, 4, 7, 6},  // back
        {4, 0, 3, 7},  // left
        {1, 5, 6, 2},  // right
        {4, 5, 1, 0},  // bottom
        {3, 2, 6, 7}   // top
    };

    static size_t edges[6][4] =
    {
        {0, 1, 2, 3},  // front
        {4, 5, 6, 7},  // back
        {0, 3, 4, 7},  // left
        {1, 2, 5, 6},  // right
        {0, 1, 4, 5},  // bottom
        {2, 3, 6, 7}   // top
    };
    glPushMatrix();
    glColor4f(color[0], color[1], color[2], 1.0f);    
    glBegin(GL_QUADS);
        for (size_t f=0;f<6;f++) // for each face
        for (size_t v=0;v<4;v++) 
            glVertex3fv(vertices[faces[f][v]]);
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        for(int i = 0; i < 6; ++i)
        {

            glBegin(GL_LINE_STRIP);
            for(int j = 0; j < 4; ++j) {
                glVertex3f(vertices[faces[i][j]][0], vertices[faces[i][j]][1], vertices[faces[i][j]][2]);  
            }
            glEnd();
        }
    glPopMatrix();
}

void drawText(float posX, float posY, float scaleX, float scaleY, std::string text)
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glDisable(GL_TEXTURE_2D); //added this
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            glLoadIdentity();
            glTranslatef(posX, posY, 0.0f);
            glScalef(scaleX,scaleY, 0.0f);
            //glRasterPos2i(posX, posY);
void * font = GLUT_BITMAP_9_BY_15;
for (std::string::iterator i = text.begin(); i != text.end(); ++i)
{
  char c = *i;
glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
  //glColor3d(1.0, 0.0, 0.0);
  //glutBitmapCharacter(font, c);
}
            glMatrixMode(GL_PROJECTION); //swapped this with...
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW); //...this
    glPopMatrix();
    //added this
    glEnable(GL_TEXTURE_2D);

}
