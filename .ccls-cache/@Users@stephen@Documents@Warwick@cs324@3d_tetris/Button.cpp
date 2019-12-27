#include "Button.h"
#include "Utility.h"
#include "GlobalDeclarations.h"

Button::Button(float topLeftX, float topLeftY, float width, float height, std::string buttonLabel, bool clicked, bool highlighted)
    : topLeftX(topLeftX), topLeftY(topLeftY), width(width), height(height), buttonLabel(buttonLabel), clicked(clicked), highlighted(highlighted)
{}

Button::~Button() {}

void Button::draw()
{
    drawButton();
}

void Button::drawButton()
{


    if(this->highlighted)
        glColor3f(0.7f, 0.7f, 0.8f);
    else 
        glColor3f(0.6f, 0.6f, 0.6f);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
    glBegin(GL_QUADS);
        glVertex2f(this->topLeftX, this->topLeftY);
        glVertex2f(this->topLeftX, this->topLeftY + this->height);
        glVertex2f(this->topLeftX + this->width, this->topLeftY + this->height);
        glVertex2f(this->topLeftX + this->width, this->topLeftY);
    glEnd();

    glLineWidth(3);

    if(this->clicked)
        glColor3f(0.4f, 0.4f, 0.4f);
    else 
        glColor3f(0.8f, 0.8f, 0.8f);


	glBegin(GL_LINE_STRIP);
			glVertex2i( this->topLeftX+this->width, this->topLeftY      );
			glVertex2i( this->topLeftX     , this->topLeftY      );
			glVertex2i( this->topLeftX     , this->topLeftY+this->height );
		glEnd();

		if (this->clicked) 
			glColor3f(0.8f,0.8f,0.8f);
		else 
			glColor3f(0.4f,0.4f,0.4f);

		glBegin(GL_LINE_STRIP);
			glVertex2i( this->topLeftX     , this->topLeftY+this->height );
			glVertex2i( this->topLeftX+this->width, this->topLeftY+this->height );
			glVertex2i( this->topLeftX+this->width, this->topLeftY      );
	glEnd();

    glLineWidth(1);
		glPopMatrix();

	glMatrixMode(GL_PROJECTION);;
	glPopMatrix();


    float textLength = glutStrokeLength(GLUT_STROKE_ROMAN, (unsigned char*)this->buttonLabel.c_str());
    float scaleX = (this->width - 20) / textLength;
    float scaleY = 0.7f * (this->height / 100);
    float labelX = this->topLeftX + 10;
    float labelY = this->topLeftY + 10;

    drawText(labelX, labelY, scaleX, scaleY, this->buttonLabel);
}

bool Button::checkClicked(float posX, float posY)
{
    bool click = test(posX, posY);
    this->clicked = click;
    return click;
}

bool Button::test(float posX, float posY)
{
    if(posX >= this->topLeftX && posX <= this->topLeftX + this->width &&
            posY >= this->topLeftY && posY <= this->topLeftY + this->height) return true;
    
    return false;
}
