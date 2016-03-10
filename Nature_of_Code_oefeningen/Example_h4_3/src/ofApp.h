#pragma once

#include "ofMain.h"
#include "Partical.h"
#include "ParticleSystem.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	ParticleSystem eenhoorn; 
	ofVec2f location_; 
};
