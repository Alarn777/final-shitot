

#include "../Common/Control.h"


class TextBox : public Control {
private:
    Control *control;
    string value,label;
    Color original_background;
    Color original_textColor;
    int maxLen;
    int currentSelected;
public:
    TextBox(short left, short top,short width, Color textColor, Color backgroundColor,string label,int maxLen);
    Control *getControl();
    bool canGetFocus() { return true; };
    bool isFocusOnTextBox();
    void keyDown(int keyCode, char character);
    void draw(Graphics &g, int x, int y, size_t z);
    void setText(string text);

    void mousePressed(int x, int y, bool isLeft) override;

    virtual void focus();
    virtual void unfocus();
};

