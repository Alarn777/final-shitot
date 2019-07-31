//
// Created by michael.rokitko on 7/24/2019.
//

#ifndef FINAL_PROJECT_SHITOT_COMBO_H
#define FINAL_PROJECT_SHITOT_COMBO_H
//
// Created by michael.rokitko on 7/23/2019.
//

#include "../Common/Control.h"
#include "Label.h"

class Combo : public Control{
public:

    ~Combo() {};
    Combo(short left, short top, Color textColor, Color backgroundColor, bool isSet,string text);
    Control* getControl();
    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft){};
    void keyDown(int keyCode, char character){};
    bool getValue() {return isPressed;}
    bool setValue(bool value) {isPressed = value;}
    string getText(){ return text; }
private:
    Control* control;
    bool isPressed;
    string text;
    void focus();
    void unfocus();
};


#endif
