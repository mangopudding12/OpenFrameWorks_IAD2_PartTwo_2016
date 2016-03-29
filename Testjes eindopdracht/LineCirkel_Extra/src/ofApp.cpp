#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	System = new vector<ParticleSystem>;

	ParticleSystem newSystem;
	newSystem = ParticleSystem(100, 100, 25);
	System->push_back(newSystem);

	linee = Line(200.0, 400.0, 400.0, 400.0);
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int k = 0; k < System->size(); k++)
	{
		System->at(k).move(linee); 
		System->at(k).Dead();

		if (System->at(k).maakNieuwe == true)
		{
			ParticleSystem newSystem;
			newSystem = ParticleSystem(ofRandom(-50, 600), ofRandom(-50, 400), ofRandom(2, 10));
			System->push_back(newSystem);

			System->at(k).intact = true;
			System->at(k).maakNieuwe = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	linee.display();
	
	ofColor(200, 200, 150);
	for (int i = 0; i < System->size(); i++)
	{
		System->at(i).display();
	}
}

// ------------------- Hierin staat informatie over collision line cirkel ----
void ofApp::collisionLineCirkel(int k_)
{	
	
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	for (int i = 0; i < System->size(); i++)
	{
		System->at(i).shatter();
	}

}

void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
