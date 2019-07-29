

#ifndef FINAL_SHITOT_MESSAGEBOX_MY_H
#define FINAL_SHITOT_MESSAGEBOX_MY_H


#include "../Common/Control.h"
#include "Button.h"

class MessageBox_My : public Control {
public:
    MessageBox_My(Button &cancel, Button &ok) : Cancel(cancel), OK(ok) { message = ""; };
    ~MessageBox_My() {};
    MessageBox_My(short left, short top, short width, short height, Color textColor, Color backgroundColor,string name);


    // Control* getControl(int index);
    bool focusInMessageBox();
    virtual void keyDown(int keyCode, char character) {};
    bool canGetFocus() { return true; };

    void draw(Graphics& g, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft) override;
    virtual void getAllControls(vector<Control*>* controls) {};

    void showMessage(){ isActive = true;};

    void closeMessage(){ isActive = false;};

    bool isMessageActive(){ return isActive;}


    static string close();
//    string returnCancel();
//    string returnOK();
    virtual void focus();
    virtual void unfocus();

private:
    string message;
    Button OK;
    Button Cancel;
    bool isActive;


    Color original_background;
    Color original_textColor;
};


#endif //FINAL_PROJECT_SHITOT_MESSAGEBOX_MY_H
