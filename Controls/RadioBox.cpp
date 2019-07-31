
#include "RadioBox.h"
#include "Radio.h"

RadioBox::RadioBox(short left, short top, short width, short height, Color textColor,
                     Color backgroundColor, string name):Control(left, top, width, height,new Border(1), textColor, backgroundColor){
    radioBoxName = name;
    original_textColor = textColor;
    original_background =  backgroundColor;
}

bool RadioBox::focusInRadioBox() {
    if (getFocus() != nullptr && getFocus() == this)
        return true;
    if (getFocus() != nullptr) {
        for (auto &allControl : allRadio) {
            if (allControl == getFocus()) {
                return true;
            }
        }
    } else
        return false;
    return false;
}

bool RadioBox::addRadio(Radio *rad) {

    Control *control = rad;
    this->allRadioForValues.push_back(rad);
    this->allRadio.push_back(control);
    if (getFocus() == nullptr && control->canGetFocus()) {
        setFocus(*control);
    }
    return true;
}

void RadioBox::keyDown(int keyCode, char character) {
    Control::keyDown(keyCode, character);
}

void RadioBox::draw(Graphics &g, int x, int y, size_t z) {
    int newX, newY;
    if (z == 0) {
        Control::draw(g, x, y, z);
        Control::drawShadow(g, x, y, getWidth(), getHeight(), z);

        if (!radioBoxName.empty()) {
            g.moveTo(x+1, y+1);
            g.setBackground(getBackgroundColor());
            g.write(radioBoxName);
        }

        for (auto &allControl : allRadio) {
            newX = allControl->getLeft();
            newY = allControl->getTop();
            g.setForeground(allControl->getTextColor());
            g.setBackground(allControl->getBackgroundColor());
            allControl->draw(g, x + newX, y + newY, z);
        }

    }
}

void RadioBox::mousePressed(int x, int y, bool isLeft) {
    if (focusInRadioBox()) {
        if (this->isPressInRange(x, y)) {

            for (Control *control: allRadio) {
                control->mousePressed(x - getLeft(), y - getTop(), isLeft);
            }
        }
    }
}

void RadioBox::getAllControls(vector<Control *> *controls) {
    for (auto &allControl : this->allRadio) {
        controls->push_back(allControl);
        allControl->getAllControls(controls);
    }
}

void RadioBox::focus() {
    this->setBackgroundColor(Color::White);
    this->setTextColor(Color::Black);
}

void RadioBox::unfocus() {
    this->backgroundColor = original_background;
    this->setTextColor(original_textColor);
}

string RadioBox::getSelected() {
    for (auto &Control : this->allRadioForValues) {
        if(Control->getValue())
            return Control->getText();
    }
    return "";
}
