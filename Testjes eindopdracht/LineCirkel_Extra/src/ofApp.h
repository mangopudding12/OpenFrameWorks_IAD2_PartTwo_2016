#pragma once


#include "ofMain.h"
#include "Cirkel.h"
#include "Line.h"
#include "ParticleSystem.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void collisionLineCirkel(int k_); 
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void keyPressed(int key);
	void keyReleased(int key);

	int hoeveelheid;
	bool aanuit = true;

	// Zo maak je een vector aan doormiddel van new woord te gebruiken. 
	//vector <Partical>* particles;
	vector <ParticleSystem>* System; 

	Line linee;
};
