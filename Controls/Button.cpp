#include "Button.h"



Button::Button(){

}

void Button::SetText(string value){
    this->text = value;
}

Button::Button(short left, short top, short width, Border* border, Color textColor, Color backgroundColor,string text) :
    Control(left, top, width,3, new Border(1), textColor, backgroundColor) {
        this->text = text;
    }

Control* Button::getControl() {
    return control;
}

bool Button::focusOnButton() {
    return getFocus() == control;
}

void Button::draw(Graphics& g, int x, int y, size_t z) {

    if(z == 0) {
        Control::draw(g,x,y,z);
        Control::drawShadow(g,x,y,getWidth(),getHeight(),z);
        g.setBackground(getBackgroundColor());
        g.write(x+1,y+1,this->text);
       
    }
}

void Button::mousePressed(int x, int y, bool isLeft) {
    if(this->isPressInRange(x,y))
    {
       this->backgroundColor = Color::Green;   
        for (auto & _function : vectoroffunctions){
            _function();
        }
    }
}


void Button::addOnClick(string (*function)())
{
    //Don't take the address of the address:
    vectoroffunctions.push_back(function);
}