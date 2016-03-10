#pragma once


#include "ofMain.h"
#include "Particle.h"
#include "ParticleSystem.h"


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);


	ofVec2f location_;
	vector<ParticleSystem> SyStems;
};
