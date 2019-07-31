
#ifndef RADIO_H
#define RADIO_H

#include "../Common/Control.h"
#include "Label.h"

class Radio : public Control{
public:

    ~Radio() {};
    Radio(short left, short top, Color textColor, Color backgroundColor, bool isSet,Label text);
    Control* getControl();
    bool focusOnCheckBox();
    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    void keyDown(int keyCode, char character){};
    bool canGetFocus() { return false; };
    bool getValue() {return isPressed;}
    bool setValue(bool value) {isPressed = value;}
    string getText(){ return text.getValue(); }
private:
    Control* control;
    bool isPressed;
    Label text;
    void focus();
    void unfocus();
};

#endif