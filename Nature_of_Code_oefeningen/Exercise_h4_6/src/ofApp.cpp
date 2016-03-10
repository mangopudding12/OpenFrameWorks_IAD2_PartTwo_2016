#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	ParticleSystem newSystem;
	newSystem = ParticleSystem(ofGetWidth() / 2, 300, 10);
	SyStems.push_back(newSystem);
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < SyStems.size(); i++)
	{
		SyStems[i].move();
		SyStems[i].Dead();

		if (SyStems[i].maakNieuwe == true)
		{
			ParticleSystem newSystem;
			newSystem = ParticleSystem(ofRandom(-50,600), ofRandom(-50,400), ofRandom(2,10));
			SyStems.push_back(newSystem);

			SyStems[i].intact = true; 
			SyStems[i].maakNieuwe = false;
		}

	}

	

}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i < SyStems.size(); i++)
	{
		
		SyStems[i].display();
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	
	for (int i = 0; i < SyStems.size(); i++)
	{
			SyStems[i].shatter();
	}
}
