#pragma once
#include "ofMain.h"
#include "Line.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include "AchtergrondParticleSystem.h"

class ofApp : public ofBaseApp {

public:

	// Functions 
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void keyPressed(int key);
	void keyReleased(int key);

	// Class line 
	Line linee;

	// Zo maak je een vector aan doormiddel van new woord te gebruiken. 
	vector <ParticleSystem>* System;
	vector <AchtergrondParticleSystem> AchtergrondSystem;

	// Voor de achtergrondParticle locatie vector
	ofVec2f location_;

	// int, float, boolean enzo. 
	int hoeveelheid;
	bool aanuit = true;
	bool line_bewegen_uit = false;
	int fase_code;

	bool LegeVectorVullen = false;
	ofTrueTypeFont  begintekst;

	int getal;
	
};