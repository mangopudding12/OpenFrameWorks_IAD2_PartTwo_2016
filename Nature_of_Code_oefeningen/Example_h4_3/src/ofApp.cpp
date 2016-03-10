#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);
	location_.set(ofGetWidth() / 2, 100);
	eenhoorn = ParticleSystem(location_);
}

//--------------------------------------------------------------
void ofApp::update()
{
	eenhoorn.origin.set(mouseX, mouseY);
	eenhoorn.addParticle();
}

//--------------------------------------------------------------
void ofApp::draw()
{	
	eenhoorn.run();
}