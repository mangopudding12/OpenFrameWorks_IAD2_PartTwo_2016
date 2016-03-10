#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update()
{
	ofBackground(255);

	location__.set(ofGetWidth() / 2, 100);
	Partical harry = Partical(location__); 
	MoreParticles.push_back(harry);

	ofLog(OF_LOG_NOTICE, "Particles " + ofToString(MoreParticles.size()));
}

//--------------------------------------------------------------
void ofApp::draw()
{

	// Manier 1 
	//for (vector<Partical>::iterator it = MoreParticles.begin(); it != MoreParticles.end();)
	//{
	//	// (*it) = je maakt van een pionter weer een object
	//	if ((*it).isDead() == true)
	//	{		
	//		it = MoreParticles.erase(it);
	//	}
	//	else {
	//		(*it).run();
	//		 it++; 
	//	}
	//}

	// Manier 2 
	int i = 0;
	while (i < MoreParticles.size()) {
		if (MoreParticles[i].isDead() == true) {
			MoreParticles.erase(MoreParticles.begin() + i);
		}
		else {
			MoreParticles[i].run();
			i++;
		}
	}

}