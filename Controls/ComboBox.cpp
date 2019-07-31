//
// Created by michael.rokitko on 7/24/2019.
//

#include "ComboBox.h"



ComboBox::ComboBox(short left, short top, short width, short height, Color textColor, Color backgroundColor,
                             string title,vector<string>& values): Control(left, top, width, height,new Border(1), textColor, backgroundColor) {

    for(int i = 0; i < values.size();i++){

        Combo* temp = new Combo(13,i+4,Color::White,Color::Cyan, false,values[i]);
        allChoices.push_back(temp);
        currentChoise = temp;
    }
    this->title = title;
    menuOpened = false;
    picker = Button(3, 3, 6, nullptr, Color::White, Color::Red,"Choose");
    original_textColor = textColor;
    original_background =  backgroundColor;


}

bool ComboBox::focusInComboBox() {
    return getFocus() == this;
}

void ComboBox::keyDown(int keyCode, char character){
    if(focusInComboBox()){
        if (keyCode == VK_UP || keyCode ==  VK_DOWN){
            for(int i = 0; i < allChoices.size();i++) {
                if (currentChoise == allChoices[i]) {
                    if (i + 1 >= allChoices.size()) {
                        currentChoise = allChoices[0];
                        return;
                    } else {
                        currentChoise = allChoices[i + 1];
                        return;
                    }
                }
            }
        }
    }
}

void ComboBox::draw(Graphics &g, int x, int y, size_t z) {
    if(z == 0) {
        Control::drawShadow(g, x, y, getWidth(), getHeight(), z);
        Control::draw(g, x, y, z);
        if (!title.empty()) {
            g.moveTo(x+1, y+1);
            g.setBackground(getBackgroundColor());
            g.write(title);

        }

        Border B1(1);
        g.setBackground(Color::Red);
        B1.drawBorder(g,picker.getLeft()+9 + x,picker.getTop() + y,currentChoise->getText().size(),3);
        picker.draw(g, x + picker.getLeft(), y + picker.getTop(), z);
        g.setBackground(Color::Green);
        currentChoise->draw(g,x+ picker.getLeft()+10,picker.getTop() + y + 1,z);




        if (menuOpened){
            for (Combo* combo: allChoices){
                combo->draw(g,x + combo->getLeft(),y + combo->getTop(),z);
            }
        }

    }
}

void ComboBox::mousePressed(int x, int y, bool isLeft) {
    if(focusInComboBox()){
        if(isPressInRange(x,y)){
            picker.mousePressed(x - getLeft(),y - getTop(),isLeft);
            if(picker.isPressInRange(x - getLeft(),y - getTop()))
               this->menuOpened = true;
            if(menuOpened){
                for(auto combo: allChoices ) {
                    if (combo != currentChoise) {
                        combo->mousePressed(x - getLeft(), y - getTop(), isLeft);
                        if (combo->isPressInRange(x - getLeft(), y - getTop())) {
                            currentChoise = combo;
                            menuOpened = false;
                        }
                    }
                }
            }
        }
    }
}

string ComboBox::getReturnValue(){
    return currentChoise->getText();
}


void ComboBox::focus() {
    this->backgroundColor = Color::White;
    this->setTextColor(Color::Black);
}

void ComboBox::unfocus() {
    this->backgroundColor = original_background;
    this->setTextColor(original_textColor);
}

