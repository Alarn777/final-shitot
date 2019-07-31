#include "../Common/Control.h"

class CheckList : public Control{
public:
    CheckList();
    ~CheckList() {};
    CheckList(short left, short top, short width, short height, Color textColor, Color backgroundColor,string name);

    bool addCheckBox(Control* control);
    bool focusInCheckList();
    virtual void keyDown(int keyCode, char character);
    bool canGetFocus() { return true; };

    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft) override;
    virtual void getAllControls(vector<Control*>* controls);
    virtual void focus();
    virtual void unfocus();
private:
    vector<Control*> allCheckBoxes;
    string checkListName;
    Color original_background;
    Color original_textColor;
};

