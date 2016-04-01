#pragma once
#include "ofMain.h"
#include "LineHeadClass.h"

class Line_Versiering : public LineHeadClass 
{
public: 
	Line_Versiering() {};
	// Constructor 
	Line_Versiering(float x1_, float x2_, float y1_, float y2_);

	// Fuctions 
	void display();
	
	// Vector 
	ofVec2f locationpoint1;
	ofVec2f locationpoint2;
	ofVec2f accelaration;


private: 
};