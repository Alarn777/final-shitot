#include "Panel.h"


Panel::Panel() {}

Panel::Panel(short x, short y, short width, short height, Border *border, Color textColor, Color backgroundColor) :
        Control(x, y, width, height, border, textColor, backgroundColor) {
    panelName = "";
    original_textColor = textColor;
    original_background =  backgroundColor;
}

bool Panel::isAnyInnerControlInFocus() {
    vector<Control *> controls;
    this->getAllControls(&controls);

    if (controls.empty())
        return false;

    for (auto *c : controls)
        if (c == getFocus())
            return true;

    return false;
}

bool Panel::isFocused() {
    if (getFocus() == nullptr)
        return false;

    return getFocus() == this || isAnyInnerControlInFocus();
}

bool Panel::addControl(Control *control) {
    if (control == nullptr) return false;

    this->controls.push_back(control);

    if (getFocus() == nullptr && control->canGetFocus())
        setFocus(*control);
    return true;
}

void Panel::setName(string name) { panelName = name; }

void Panel::draw(Graphics &g, int x, int y, size_t z) {
    int _x, _y;

    if (z == 0) {
        Control::draw(g, x, y, z);
        Control::drawShadow(g, x, y, getWidth(), getHeight(), z);

        int middle = (getWidth() - panelName.size() - 2) / 2;

        if (panelName != "") {
            g.setBackground(getBackgroundColor());
            g.write(getLeft() + middle,getTop() ,"[" + panelName + "]");
        }

        for (auto &allControl : controls) {
            _x = allControl->getLeft();
            _y = allControl->getTop();

            g.setForeground(allControl->getTextColor());
            g.setBackground(allControl->getBackgroundColor());

            allControl->draw(g, x + _x, y + _y, z);
        }
    }
}

void Panel::mousePressed(int x, int y, bool isLeft) {
    if (!isFocused())
        return;

    if (!this->isPressInRange(x, y))
        return;

    int len = controls.size();

    for (auto *control: controls){
        if(controls.size() <= len)
            control->mousePressed(x - getLeft(), y - getTop(), isLeft);
    }

}

void Panel::keyDown(int keyCode, char character) {
    if (!isFocused()) return;

    for (auto *control: controls)
        control->keyDown(keyCode, character);
}

void Panel::getAllControls(vector<Control *> *controls) {
    for (auto &allControl : this->controls) {
        controls->push_back(allControl);
        allControl->getAllControls(controls);
    }
}

void Panel::focus() {
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void Panel::unfocus() {
    this->backgroundColor = original_background;
    this->setTextColor(original_textColor);
}


