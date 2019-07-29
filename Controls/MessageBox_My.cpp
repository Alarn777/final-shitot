//
// Created by michael.rokitko on 7/24/2019.
//
#include <cassert>

#include "MessageBox_My.h"
#include "Panel.h"

string returnOK(){
    return "OK";
}
string returnCancel(){
    return "Cancel";
}

MessageBox_My::MessageBox_My(short left, short top, short width, short height, Color textColor, Color backgroundColor,
                         string message):Control(left, top, width, height,new Border(1), textColor, backgroundColor) {

    this->message = message;
    isActive = true;
    OK = Button(5, 5, 4, nullptr, Color::White, Color::Red,"OK");
    OK.addOnClick(returnOK);

    int cancelCoord = width - 15 > 15 ? width - 10 : 15;

    Cancel = Button(cancelCoord, 5, 8, nullptr, Color::White, Color::Red,"Cancel");
    Cancel.addOnClick(returnCancel);

    original_textColor = textColor;
    original_background =  backgroundColor;

}

bool MessageBox_My::focusInMessageBox() {
    return getFocus() == this;
}

void MessageBox_My::draw(Graphics &g, int x, int y, size_t z) {
    if(!isActive)
        return;
    if(z == 0) {
        Control::draw(g, x, y, z);
        OK.draw(g,x + OK.getLeft(),y+ OK.getTop(),z);
        Cancel.draw(g,x + Cancel.getLeft(),y + Cancel.getTop(),z);
        g.moveTo(x+2,y+2);
        cout << message << endl;
    }
}

void MessageBox_My::mousePressed(int x, int y, bool isLeft) {
    if(focusInMessageBox()){
       if(isPressInRange(x,y)){
           OK.mousePressed(x - getLeft(),y - getTop(),isLeft);
           if(OK.isPressInRange(x - getLeft(),y - getTop()))
               this->closeMessage();
           Cancel.mousePressed(x - getLeft(),y - getTop(),isLeft);
           if(Cancel.isPressInRange(x - getLeft(),y - getTop()))
               this->closeMessage();
       }
   }
}

void MessageBox_My::focus() {
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void MessageBox_My::unfocus() {
    this->backgroundColor = original_background;
    this->setTextColor(original_textColor);
}

