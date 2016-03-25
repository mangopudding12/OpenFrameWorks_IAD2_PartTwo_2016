#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	hoeveelheid = 400; 

	particles = new vector<Partical>;
	move = false;

	for (int k = 0; k < hoeveelheid; k++)
	{
		Partical tijdelijk = Partical(ofGetWidth()/2,300,30,k,particles);
		particles->push_back(tijdelijk);
	}
	
}

//--------------------------------------------------------------
void ofApp::update()
{
		for (int k = 0; k < particles->size(); k++)
		{
	
			
			particles->at(k).move();
			particles->at(k).botsingdetection();
			particles->at(k).Schermbounds();
			//particles->at(k).isDead();

			
				//if (move == false)
				//{
				//	particles->at(1).displayy(mouseX, mouseY);
				//}
				//else {
				///	particles->at(1).move();
				//}
			//}
			
			//particles->at(1).botsingdetection();
			//particles->at(1).Schermbounds();
			
		}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int k = 0; k < particles->size(); k++)
	{
		particles->at(k).display();
		//particles->at(1).display();
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
		move = true;
}

void ofApp::mouseReleased(int x, int y, int button)
{
	
}