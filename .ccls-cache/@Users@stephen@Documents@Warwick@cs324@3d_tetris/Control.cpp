#include "Control.h"
#include "GlobalDeclarations.h"
#include "Utility.h"

Control::Control() 
{
}

Control::~Control() {}

void Control::drawControlPage()
{
    draw();
}

bool Control::returnButtonClicked(float posX, float posY)
{
    return returnButton->checkClicked(posX, posY);    
}

void Control::draw()
{
    float buttonWidth = 100.0f;
    float heightIdent = SCREEN_HEIGHT / 30.0;
    float widthIdent = SCREEN_WIDTH / 30.0f;
    float textHeight = (SCREEN_HEIGHT - (texts.size() + 1) * heightIdent) / texts.size();

    float scaleY = textHeight / 70.0f * 0.5f ;
    for(int i = 0; i < texts.size(); ++i)
    {
        float textLength = glutStrokeLength(GLUT_STROKE_ROMAN, (unsigned char*)texts[i].c_str());
        float scaleX = (SCREEN_WIDTH * 2.0 / 3.0 - 2 * widthIdent - buttonWidth) / textLength * 0.6f;
        drawText(widthIdent + buttonWidth, SCREEN_HEIGHT - (i + 1) * heightIdent - (i + 1) * textHeight, scaleX, scaleY, texts[i] );
        std::string keyboardText = "";
        keyboardText += keyboards[i];
        if(keyboardText == " ") keyboardText = "space";
        drawText(SCREEN_WIDTH * 2.0 / 3.0 + widthIdent, SCREEN_HEIGHT - (i + 1) * heightIdent - (i + 1) * textHeight, scaleY, scaleY, keyboardText);
    }

    
    returnButton = new Button(10, SCREEN_HEIGHT - 10 - textHeight, buttonWidth, textHeight, "Return");
    returnButton->draw();
}
