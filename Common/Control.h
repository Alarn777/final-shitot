#pragma once
#include "Graphics.h"
#include "Border/Border.h"
#include <vector>

using namespace std;

class Control
{

protected:
		static Control* focusedControl;
		short left;
		short top;
		short width;
		short height;
		Border* border;
		Color textColor;
		Color backgroundColor;
	
public:
	Control();
	Control(short left, short top, short width, short height, Border* border, Color textColor, Color backgroundColor);
	virtual ~Control() = 0;

	static Control* getFocus() { return focusedControl; };

	static void setFocus(Control& control);
	void setTextColor(Color textColor) { this->textColor = textColor; };
	virtual void setLeft(short left) { this->left = left; };
	virtual void setTop(short top) { this->top = top; };
	virtual void setWidth(short width) { this->width = width; };
	virtual void setHeight(short height) { this->height = height; };	
	void setBackgroundColor(Color backgroundColor) { this->backgroundColor = backgroundColor; };

    void drawShadow(Graphics& g, int x, int y,int width,int height, size_t z);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char character) {};
	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual short getWidth() { return width; };
	virtual short getHeight() { return height; };
	virtual void getAllControls(vector<Control*>* controls) {};
	Color getTextColor() { return textColor; };
	Color getBackgroundColor() { return backgroundColor; };


	virtual bool canGetFocus() { return FALSE; };
	bool isPressInRange(int x,int y);
	virtual void focus() {};
	virtual void unfocus() {};

};

