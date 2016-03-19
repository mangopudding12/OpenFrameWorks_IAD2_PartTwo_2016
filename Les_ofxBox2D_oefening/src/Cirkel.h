#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

// extands 
class Cirkel : public ofxBox2dCircle
{
public: 
	Cirkel();

	void setup(); 
	void draw(); 
	void move(); 
	ofVec3f hoi; 
	ofColor color; 

private: 

};