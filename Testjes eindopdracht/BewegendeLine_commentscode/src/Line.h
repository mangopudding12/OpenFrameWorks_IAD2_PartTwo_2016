#pragma once
#include "ofmain.h"
#include "LineHeadClass.h"

class Line : public LineHeadClass
{

public:
	Line() {};
	Line(float x1_, float x2_, float y1_, float y2_);

	void move(bool bewegenaan);
	void display();

	// Vector 
	ofVec2f locationpoint1;
	ofVec2f locationpoint2;
	ofVec2f accelaration;

private:
};

