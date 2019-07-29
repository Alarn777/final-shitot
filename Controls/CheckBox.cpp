#include "CheckBox.h"



void CheckBox::draw(Graphics &g, int x, int y, size_t z) {
    if (z == 0) {
        g.write(x, y, "[");
        if (this->getValue())
            g.write(x + 1, y, "X");
        else
            g.write(x + 1, y, " ");
        g.write(x + 2, y, "] ");

        text.draw(g, x + 3, y - 1, z);
    }
}

Control *CheckBox::getControl() { return control; }

bool CheckBox::focusOnCheckBox() {
    return getFocus() != nullptr && getFocus() == this;
}


void CheckBox::mousePressed(int x, int y, bool isLeft) {
    if (isPressInRange(x, y)) {
        this->setValue(!this->getValue());
    }
}

void CheckBox::keyDown(int keyCode, char character) {
    if (focusOnCheckBox())
        if (keyCode == VK_SPACE)
            this->setValue(!this->getValue());
}

CheckBox::CheckBox(short left, short top, Color textColor, Color backgroundColor, bool isSet,
                   Label text) : Control(left, top, 3, 1, nullptr, textColor, backgroundColor), text(text) {
    isPressed = isSet;
}

void CheckBox::focus() {
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void CheckBox::unfocus() {
    this->backgroundColor = Color::Blue;
    this->setTextColor(Color::White);
}
