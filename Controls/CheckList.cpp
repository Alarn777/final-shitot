
#include "CheckList.h"


CheckList::CheckList(short left, short top, short width, short height, Color textColor,
                     Color backgroundColor, string name):Control(left, top, width, height,new Border(1), textColor, backgroundColor){
    checkListName = name;

    original_textColor = textColor;
    original_background =  backgroundColor;
}

bool CheckList::focusInCheckList() {
    if (getFocus() != nullptr && getFocus() == this)
        return true;
    if (getFocus() != nullptr) {
        for (auto &allControl : allCheckBoxes) {
            if (allControl == getFocus()) {
                return true;
            }
        }
    } else
        return false;
    return false;
}

bool CheckList::addCheckBox(Control *control) {
    this->allCheckBoxes.push_back(control);
    if (getFocus() == nullptr && control->canGetFocus()) {
        setFocus(*control);
    }
    return true;
}

void CheckList::keyDown(int keyCode, char character) {
    Control::keyDown(keyCode, character);
}

void CheckList::draw(Graphics &g, int x, int y, size_t z) {
    int newX, newY;
    if (z == 0) {
        Control::draw(g, x, y, z);
        Control::drawShadow(g, x, y, getWidth(), getHeight(), z);

        if (checkListName != "") {
            g.moveTo(x+1, y+1);
            g.setBackground(getBackgroundColor());
            g.write(checkListName);
        }

        for (auto &allControl : allCheckBoxes) {
            newX = allControl->getLeft();
            newY = allControl->getTop();
            g.setForeground(allControl->getTextColor());
            g.setBackground(allControl->getBackgroundColor());
            allControl->draw(g, x + newX, y + newY, z);
        }

    }
}

void CheckList::mousePressed(int x, int y, bool isLeft) {
    cout << "mouse in checklist" << endl;
    if (focusInCheckList()) {
        if (this->isPressInRange(x, y)) {

            for (Control *control: allCheckBoxes) {
                control->mousePressed(x - getLeft(), y - getTop(), isLeft);
            }
        }
    }
}

void CheckList::getAllControls(vector<Control *> *controls) {
        for (auto &allControl : this->allCheckBoxes) {
            controls->push_back(allControl);
            allControl->getAllControls(controls);
        }
    }

void CheckList::focus() {
    this->setBackgroundColor(Color::White);
    this->setTextColor(Color::Black);
}

void CheckList::unfocus() {
    this->backgroundColor = original_background;
    this->setTextColor(original_textColor);
}
