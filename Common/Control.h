#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{

protected:
	short left;
	short top;
	short width;
	short height;
	Color textColor;
	Color backgroundColor;
	
public:
	Control();
	static Control* getFocus() { return NULL; };
	static void setFocus(Control& control) {};
	
	void setTextColor(Color textColor) { this->textColor = textColor; };
	virtual void setLeft(short left) { this->left = left; };
	virtual void setTop(short top) { this->top = top; };
	virtual void setWidth(short width) { this->width = width; };
	virtual void setHeight(short height) { this->height = height; };	
	void setBackgroundColor(Color backgroundColor) { this->backgroundColor = backgroundColor; };
	

	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual short getLeft() { return 0; };
	virtual short getTop() { return 0; };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
	~Control();
};

