#pragma once

#include "ofMain.h"
#include "Partical.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		Partical Particle_one; 
		ofVec2f location__;
};
