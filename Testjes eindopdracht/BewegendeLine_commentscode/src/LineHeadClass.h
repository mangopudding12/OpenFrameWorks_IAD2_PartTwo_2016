#pragma once
#include "ofMain.h"
#include "Line.h"
#include "Particle.h"

class LineHeadClass
{
public: 

	// Constuctors 
	LineHeadClass();

	// Functions 
	bool lineCircle(float x1, float y1, float x2, float y2, float x_, float y_, float r_);
	bool pointCircle(float px, float py, float x_, float y_, float r_);
	bool linePoint(float x1, float y1, float x2, float y2, float px, float py);

	// Vector
	//vector<Line>* anderLines;

	// Boolean, int, float enzo.
	bool stopmoving = false;


private: 
};
