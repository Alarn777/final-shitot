#include "Control.h"

Control* Control::focusedControl = nullptr;

Control::Control() : left(0), top(0), width(1), height(1), textColor(Color::White), backgroundColor(Color::Black) {

    border = nullptr;
}

Control::Control(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor) :
    left(left), top(top), width(width), height(height), border(border), textColor(textColor), backgroundColor(backgroundColor) {}

Control::~Control() {
}

void Control::setFocus(Control& control) {  
    if((focusedControl != &control) && (control.canGetFocus())) {
        if(focusedControl) {
            focusedControl->unfocus();
        }
        focusedControl = &control;
        focusedControl->focus();
    }
}

void Control::draw(Graphics& g, int x, int y, size_t z) {
    short borderPadding = 0;
    g.setForeground(getTextColor());
    g.setBackground(getBackgroundColor());
    border->drawBorder(g,  x, y, width + borderPadding, height + borderPadding);
}

void Control::drawShadow(Graphics &g, int x, int y,int width,int height, size_t z) {
    g.setBackground(Color::Black);
    string space(1, ' ');

    for(int i = 1; i < height + 1; ++i) {
        g.moveTo(x + width + 2, y + i);
        g.write(space);
    }

    for(int i = 1; i < width + 3; ++i) {
        g.moveTo(x + i, height + y );
        g.write(space);
    }
}

bool Control::isPressInRange(int x  ,int y){
    return x >= getLeft() && x <= getLeft() + getWidth() && y >= getTop() && y <= getTop() + getHeight();
}


