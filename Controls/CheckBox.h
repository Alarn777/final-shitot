#include "../Common/Control.h"
#include "../Common/Border/Border.h"
#include "Label.h"
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <iostream>

class CheckBox : public Control {
public:


    ~CheckBox() {};
    CheckBox(short left, short top, Color textColor, Color backgroundColor, bool isSet,Label text);
    Control* getControl();
    bool focusOnCheckBox();
    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    void keyDown(int keyCode, char character);
    bool canGetFocus() { return true; };
    bool getValue() {return isPressed;}
    bool setValue(bool value) {isPressed = value;}
private:
    Control* control;
    bool isPressed;
    Label text;
    void focus();
    void unfocus();
};

