
#include "Radio.h"

void Radio::draw(Graphics &g, int x, int y, size_t z) {
    if(z == 0){
        g.write(x,y,"(");
        if(this->getValue())
            g.write(x+1,y,"o");
        else
            g.write(x+1,y," ");
        g.write(x+2,y,") ");

        text.draw(g,x+3,y-1,z);
    }
}

Control *Radio::getControl() {
    return control;
}

bool Radio::focusOnCheckBox() {
    return getFocus() != nullptr && getFocus() == this;
}

void Radio::mousePressed(int x, int y, bool isLeft) {

    this->setValue(isPressInRange(x, y));
}

Radio::Radio(short left, short top, Color textColor, Color backgroundColor, bool isSet,
                   Label text) : Control(left, top, 3, 1, nullptr, textColor, backgroundColor), text(text) {
    isPressed = isSet;
}

void Radio::focus(){
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void Radio::unfocus(){
    this->backgroundColor = Color::Red;
    this->setTextColor(Color::White);
}