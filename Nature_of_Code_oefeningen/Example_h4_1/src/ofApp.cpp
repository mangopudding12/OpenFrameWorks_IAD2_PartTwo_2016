#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	location__.set(ofGetWidth()/2, 40);
	Particle_one = Partical(location__);
}

//--------------------------------------------------------------
void ofApp::update()
{
	ofBackground(255);
	Particle_one.move(); 

	if (Particle_one.isDead() == true)
	{
		cout << "Particle is dead" << endl;
		Particle_one = Partical(location__);
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	Particle_one.display(); 
}