#ifndef FINAL_PROJECT_SHITOT_NUMERICBOX_H
#define FINAL_PROJECT_SHITOT_NUMERICBOX_H


#include "Button.h"
#include <iostream>

class NumericBox : public Control {
public:
    ~NumericBox() {};
    NumericBox(short left, short top, Color textColor, Color backgroundColor,string title,int min,int max);
    bool focusInNumericBox();
    void keyDown(int keyCode, char character);
    bool canGetFocus() { return true; };
    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    virtual void getAllControls(vector<Control*>* controls) {};
    int getReturnValue();
    virtual void focus();
    virtual void unfocus();

private:
    Button plus;
    Button minus;
    int value,min{},max{};
    string title;
};


#endif //FINAL_PROJECT_SHITOT_NUMERICBOX_H
