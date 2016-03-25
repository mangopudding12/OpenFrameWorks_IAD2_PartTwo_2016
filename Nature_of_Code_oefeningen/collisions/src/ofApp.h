#pragma once


#include "ofMain.h"
#include "Cirkel.h"
#include "Collisions.h"



class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	int hoeveelheid; 
	bool move;

	// Zo maak je een vector aan doormiddel van new woord te gebruiken. 
	vector <Partical>* particles; 
	
	
};
