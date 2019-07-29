#ifndef BUTTON_H
#define BUTTON_H


#include "../Common/Control.h"
#include "../Common/Border/Border.h"
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "Panel.h"

class Button :public Control {
    public:

        Button();
        ~Button() {};
        Button(short left, short top, short height, Border* border, Color textColor, Color backgroundColor,string text);
        Control* getControl();
        bool focusOnButton();
        void draw(Graphics& g, int x, int y, size_t z);
        void mousePressed(int x, int y, bool isLeft) override;
        void SetText(string value);
        void addOnClick(string (*function)());
    private:
        Control* control;
        string text;
        std::vector<string (*)()> vectoroffunctions;
};


#endif