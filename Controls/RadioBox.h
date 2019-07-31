
#ifndef FINAL_PROJECT_SHITOT_RADIOBOX_H
#define FINAL_PROJECT_SHITOT_RADIOBOX_H

#include "Radio.h"
#include "../Common/Control.h"

class RadioBox : public Control{
public:
    RadioBox();
    ~RadioBox() {};
    RadioBox(short left, short top, short width, short height, Color textColor, Color backgroundColor,string name);
    bool addRadio(Radio *rad);
    bool focusInRadioBox();
    virtual void keyDown(int keyCode, char character);
    bool canGetFocus() { return true; };
    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft) override;
    virtual void getAllControls(vector<Control*>* controls);
    string getSelected();
    virtual void focus();
    virtual void unfocus();
private:
    vector<Control*> allRadio;
    vector<Radio*> allRadioForValues;
    string radioBoxName;
    Color original_background;
    Color original_textColor;
};


#endif //FINAL_PROJECT_SHITOT_RADIOBOX_H
