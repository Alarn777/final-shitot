
#include "TextBox.h"
#include "../utils/utils.h"


TextBox::TextBox(short left, short top, short width, Color textColor,
                 Color backgroundColor, string label, int maxLen) :
        Control(left, top, width, 7, new Border(1), textColor, backgroundColor) {
    this->value = "";
    this->label = label;
    this->maxLen = maxLen;
    this->original_background = backgroundColor;
    this->original_textColor = textColor;
    currentSelected = 0;
}

Control *TextBox::getControl() {
    return control;
}

bool TextBox::isFocusOnTextBox() {
    return getFocus() == this;
}


void TextBox::mousePressed(int x, int y, bool isLeft) {
    Control::mousePressed(x, y, isLeft);
}

void TextBox::setText(string text) {
    this->value = text.substr(0, width - 3);
}


void TextBox::keyDown(int keyCode, char character) {
    if (isFocusOnTextBox()) {
        if ((keyCode >= 0x30 && keyCode <= 0x5a) || keyCode == 0x20) {
            if (value.length() >= maxLen)
                return;
            value += character;
            if (currentSelected < maxLen)
                currentSelected++;
        }

        if (keyCode == VK_LEFT || keyCode == VK_RIGHT) {
            if (keyCode == VK_RIGHT) {
                if (value.size() >= maxLen)
                    return;
                this->currentSelected++;
            }
            if (keyCode == VK_LEFT) {
                if (currentSelected <= 1)
                    return;
                else
                    this->currentSelected--;
            }
        }

        if (keyCode == VK_BACK || keyCode == VK_DELETE) {

            if (value.size() == 0 || currentSelected == 0) {
                return;
            }
            string oldVal = this->value;
            string before = this->value.substr(0, currentSelected - 1);
            string to_delete = this->value.substr(currentSelected - 1, currentSelected);
            string after = "";
            try {
                after = this->value.substr(currentSelected, this->value.size() - 1);
            }
            catch (exception &e) {

            }

            this->setText(before + after);
            currentSelected--;
        }
    }
}

void TextBox::draw(Graphics &g, int x, int y, size_t z) {
    Control::drawShadow(g, x, y, getWidth(), getHeight(), z);
    Control::draw(g, x, y, z);

    Border *B1 = new Border(1);
    g.write(x + 2, y + 1, label);

    B1->drawBorder(g, x + 2, y + 2, maxLen, 3);
    g.setBackground(Color::White);
    if (value.empty()) {
        g.setBackground(Color::Cyan);
        g.write(x + 3, y + 3, " ");
        g.setBackground(Color::White);
        return;
    }

    for (int i = 0; i < this->value.size(); i++) {
        if (i == currentSelected - 1) {
            g.setBackground(Color::Cyan);
            g.write(x + 3 + i, y + 3, string(1, this->value[i]));
            g.setBackground(Color::White);
        } else
            g.write(x + 3 + i, y + 3, string(1, this->value[i]));
    }
}

void TextBox::focus() {
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void TextBox::unfocus() {
    this->backgroundColor = original_background;
    this->setTextColor(original_textColor);
}

