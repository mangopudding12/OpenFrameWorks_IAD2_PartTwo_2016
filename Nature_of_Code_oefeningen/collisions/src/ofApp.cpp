#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	hoeveelheid = 5; 

	for (int k = 0; k < hoeveelheid; k++)
	{
		Partical tijdelijk = Partical(300,300,30,k,konijns);
		konijns.push_back(tijdelijk); 
	}
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	//for (Partical ball : konijns) {
		for (int k = 0; k < konijns.size(); k++)
		{
			konijns[k].move();
			konijns[k].isDead();
			konijns[k].botsingdetection();
			konijns[k].Schermbounds();
		}
	//}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	//for (Partical ball : konijns) 
	//{
	for (int k = 0; k < konijns.size(); k++)
	{
		konijns[k].display();
	}
	//}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	
}
