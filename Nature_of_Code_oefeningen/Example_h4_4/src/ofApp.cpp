#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < SyStems.size(); i++)
	{
		SyStems[i].addParticle();
	}
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i < SyStems.size(); i++)
	{
		SyStems[i].run();
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	location_.set(x,y);

	ParticleSystem newSystem; 
	newSystem = ParticleSystem(location_);
	SyStems.push_back(newSystem); 
}
