#pragma once
#include "iostream"
#include "string"
#include "../Graphics.h"

using namespace std;

class Border {
    public:
        Border();
        Border(int i);
        ~Border();
        void drawBorder(Graphics& g, short left, short top, short width, short height);

    protected:
        char topLeft;
        char topRight;
        char bottomLeft;
        char bottomRight;
        char horizontal;
        char vertical;
};
