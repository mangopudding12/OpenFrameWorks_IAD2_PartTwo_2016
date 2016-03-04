#pragma once

#include "ofMain.h"
#include "Partical.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	ofVec2f location__;
	vector<Partical> MoreParticles;
};
