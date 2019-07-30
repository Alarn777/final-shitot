#include "NumericBox.h"

NumericBox::NumericBox(short left, short top, Color textColor, Color backgroundColor,string title,int min,int max): Control(left, top,13 + to_string(max).size(),9,new Border(1), textColor, backgroundColor) {


    this->min = min;
    this->max = max;
    this->value = 0;
    this->title = title;
    this->title = title;

    plus = Button(3,3,1, nullptr, Color::White, Color::Red,"+");
    minus = Button(8 + to_string(this->max).size(),3,1, nullptr, Color::White, Color::Red,"-");

}

bool NumericBox::focusInNumericBox() {
    return getFocus() == this;
}

void NumericBox::keyDown(int keyCode, char character){
    if(focusInNumericBox()){
        if (keyCode == VK_UP ||  keyCode == VK_SUBTRACT || keyCode == VK_LEFT) {
            if (value < max)
                value++;
        }
        if(keyCode ==  VK_DOWN || keyCode == VK_ADD || keyCode == VK_RIGHT )
            if (value > min)
                value--;
    }
}

void NumericBox::draw(Graphics &g, int x, int y, size_t z) {
    if(z == 0) {
        Control::drawShadow(g, x, y, getWidth(), getHeight(), z);
        Control::draw(g, x, y, z);
        if (!title.empty()) {
            g.moveTo(x+1, y+1);
            g.setBackground(getBackgroundColor());
            g.write(title);

        }

        plus.draw(g, x + plus.getLeft(), y + plus.getTop(), z);
        Border B1(1);
        g.setBackground(Color::Red);
        B1.drawBorder(g,plus.getLeft()+3 + x,plus.getTop() + y,to_string(this->max).size(),3);

        g.setBackground(Color::Green);
        g.write(x+ plus.getLeft()+4,plus.getTop() + y + 1,to_string(this->value));

        minus.draw(g, x + minus.getLeft(), y + minus.getTop(), z);

    }
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {
    if(focusInNumericBox()){
        if(isPressInRange(x,y)){
            minus.mousePressed(x - getLeft(),y - getTop(),isLeft);
            if(minus.isPressInRange(x - getLeft(),y - getTop()))
                if (value > min)
                    value--;

            plus.mousePressed(x - getLeft(),y - getTop(),isLeft);
            if(plus.isPressInRange(x - getLeft(),y - getTop()))
                if (value < max)
                    value++;
        }
    }
}

int NumericBox::getReturnValue(){
    return value;
}

void NumericBox::focus() {
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void NumericBox::unfocus() {
    this->backgroundColor = Color::Cyan;
    this->setTextColor(Color::White);
}

