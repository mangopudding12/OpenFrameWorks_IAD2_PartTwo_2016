#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"
#include "ofxGui.h"

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

	ofxPanel gui; 
	ofParameter<float> radius_;
	ofParameter<float> lifeTime_; 
	ofParameter<float> maxSpeed_; 
	ofParameter<float> rotate_; 
	ofParameter<float> size_;
	ofParameter<float> force_;
	ofParameter<float> spinning_;
	ofParameter<float> friction_;


	float birthRate = 1500;
};
