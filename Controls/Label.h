#include "../Common/Control.h"
#include <string>
#ifndef LABEL_H
#define LABEL_H

using namespace std;

class Label: public Control
{   
    private:
        string value;
        int x,y;
    public:
        Label(string);
        Label(string value,int x,int y);
        Label(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor, string value);
        string getValue() ;
        void setValue(string);
        void draw(Graphics& g, int x, int y, size_t z);
        void getAllControls(vector<Control*>* controls) { controls->push_back(this);};
        ~Label();
};

#endif