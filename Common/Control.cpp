#include "Control.h"

Control* Control::focusedControl = nullptr;


Control::Control()
{
}


Control::~Control()
{
}

bool Control::isPressInRange(int x  ,int y){
    return x >= getLeft() && x <= getLeft() + getWidth() && y >= getTop() && y <= getTop() + getHeight();
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