#pragma once
#include "ofmain.h"
#include "Cirkel.h"

class Line
{
public:
	Line() {};
	Line(float x1_, float x2_, float y1_, float y2_);

	void display();
	void move(bool bewegenaan);
	bool lineCircle(float x1, float y1, float x2, float y2, float x_, float y_, float r_);
	bool pointCircle(float px, float py, float x_, float y_, float r_);
	bool linePoint(float x1, float y1, float x2, float y2, float px, float py);


	ofVec2f locationpoint1;
	ofVec2f locationpoint2;
	ofVec2f accelaration;
	float distX;
	float distY;
	float len;
	float dot;
	float closestX;
	float closestY;
	float distance;
	bool stopmoving = false; 

	vector<Line>* anderLines;
private:
};
