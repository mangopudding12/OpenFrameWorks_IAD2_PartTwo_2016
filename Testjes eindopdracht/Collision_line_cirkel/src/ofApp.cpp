#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	hoeveelheid = 300;
	particles = new vector<Partical>;

	for (int k = 0; k < hoeveelheid; k++)
	{
		Partical tijdelijk = Partical(ofGetWidth() / 2, 300, 30, k, particles);
		particles->push_back(tijdelijk);
	}
	
	linee = Line(200.0,400.0,400.0,400.0);
}

//--------------------------------------------------------------
void ofApp::update()
{
	

	for (int k = 0; k < particles->size(); k++)
	{
		hit = linee.lineCircle(linee.locationpoint1.x, linee.locationpoint1.y,
			linee.locationpoint2.x, linee.locationpoint2.y, particles->at(k).location.x
			, particles->at(k).location.y, particles->at(k).radius);

		particles->at(k).move();
		particles->at(k).botsingdetection();
		particles->at(k).Schermbounds();

		if (hit == true)
		{
			if (particles->at(k).radius < 120)
			{
				particles->at(k).radius += 1;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	
	
	
	

	linee.display();
	ofPopMatrix();
	
	ofColor(200, 200, 150);
	for (int k = 0; k < particles->size(); k++)
	{
		particles->at(k).display();
	}

	
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	
}

void ofApp::mouseReleased(int x, int y, int button)
{

}