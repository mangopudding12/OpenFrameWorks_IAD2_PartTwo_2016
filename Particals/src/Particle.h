#pragma once
#include "ofMain.h"

class Particle
{
public: 

	// x & y locatie 
	Particle(int x, int y); 
	void update(); 
	void display();

	ofPoint position; // Waarom een point ?? 
	ofVec2f speed; 
	int radius; 

private: 

};