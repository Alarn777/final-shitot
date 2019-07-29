#include "../Common/Control.h"
#include "../Common/Border/Border.h"
#include <string>
#include <vector>


#ifndef PANEL_H
#define PANEL_H


class Panel : public Control {
private:
    vector<Control *> controls;
    string panelName;

    bool isAnyInnerControlInFocus();

    Color original_background;
    Color original_textColor;
public:

        Panel();
        ~Panel() {};
        Panel(int height, int width);
        Panel(short x, short y, short width, short height, Border* border, Color textColor, Color backgroundColor);

        bool addControl(Control* control);
        bool isFocused();
        virtual void keyDown(int keyCode, char character);
        bool canGetFocus() { return true; };

        void draw(Graphics& g, int x, int y, size_t z);
        void mousePressed(int x, int y, bool isLeft) override;
		virtual void getAllControls(vector<Control*>* controls);
        string getPanelName(){return panelName;}
        virtual void focus();
        virtual void unfocus();
        void setName(string name);
};


#endif //FINAL_PROJECT_SHITOT_PANEL_H
