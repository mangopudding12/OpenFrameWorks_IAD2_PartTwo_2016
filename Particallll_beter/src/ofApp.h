#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	ofFbo fbo;

	Parameters parameters;
	float time; 

	//Particle particle = NULL; // zodat er niet meteen een wordt aangemaakt
	vector <Particle> particles;

	float birthRate = 1500; 
};
