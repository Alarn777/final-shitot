//
// Created by michael.rokitko on 7/24/2019.
//

#include "Combo.h"


Combo::Combo(short left, short top, Color textColor, Color backgroundColor, bool isSet,
             string text) : Control(left, top, text.size(), 1, nullptr, textColor, backgroundColor), text(text) {
    isPressed = isSet;
}

void Combo::draw(Graphics &g, int x, int y, size_t z) {
    if(z == 0){
        g.write(x,y,text);
    }
}

Control *Combo::getControl() {
    return control;
}

void Combo::focus(){
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void Combo::unfocus(){
    this->backgroundColor = Color::Cyan;
    this->setTextColor(Color::White);
}