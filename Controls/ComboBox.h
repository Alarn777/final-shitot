//
// Created by michael.rokitko on 7/24/2019.
//

#ifndef FINAL_PROJECT_SHITOT_COMBOBOX_H
#define FINAL_PROJECT_SHITOT_COMBOBOX_H

#include "Button.h"
#include "Combo.h"
#include <iostream>

class ComboBox : public Control {
public:
    ~ComboBox() {};
    ComboBox(short left, short top, short width, short height, Color textColor, Color backgroundColor,string title,vector<string>& values);
    bool focusInComboBox();
    void keyDown(int keyCode, char character);
    bool canGetFocus() { return true; };

    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    virtual void getAllControls(vector<Control*>* controls) {};

    string getReturnValue();

    virtual void focus();
    virtual void unfocus();



private:
    Button picker;
    string title;
    bool menuOpened;
    vector<Combo*> allChoices;
    Combo* currentChoise;
    Color original_background;
    Color original_textColor;
};


#endif //FINAL_PROJECT_SHITOT_COMBOBOX_H
