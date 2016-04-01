#pragma once
#include "ofmain.h"
#include "Particle.h"

class Line
{
public:
	// Constuctors 
	Line() {};
	Line(float x1_, float x2_, float y1_, float y2_);

	// Functions 
	void display();
	void move(bool bewegenaan);
	bool lineCircle(float x1, float y1, float x2, float y2, float x_, float y_, float r_);
	bool pointCircle(float px, float py, float x_, float y_, float r_);
	bool linePoint(float x1, float y1, float x2, float y2, float px, float py);

	// Vector
	vector<Line>* anderLines;

	// Vector 
	ofVec2f locationpoint1;
	ofVec2f locationpoint2;
	ofVec2f accelaration;

	// Boolean, int, float enzo.
	bool stopmoving = false;


private:
};
