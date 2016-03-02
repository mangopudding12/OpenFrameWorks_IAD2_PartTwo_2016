#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
	// Display framerate als display title 
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0));

	for (int i = 0; i < springs.size(); i++)
	{
		springs[i]->update(); 
	}


	for (int i = 0; i < particles.size(); i++)
	{
		particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0) + "FPS");

	if (drawParticles)
	{
		for (int i = 0; i < particles.size(); i++)
		{
			particles[i]->display();
		}
	}

	if (drawSprings)
	{
		for (int i = 0; i < springs.size(); i++)
		{
			springs[i]->draw();
		}
	}

	if (selectedFirstParticle)
	{
		ofSetColor(ofColor::white);
		ofDrawLine(firstParticle->position, ofPoint(mouseX, mouseY));
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	ofLog() << "Pressed" << key << endl; 

	if (key == 's')
	{
		drawSprings = !drawSprings; 
	}
	else if (key == 'p') {
		drawParticles = !drawParticles; 
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	Particle* clickedParticle = findParticle(x, y); 

	if (clickedParticle != NULL)
	{
		if(selectedFirstParticle)
		{
			Particle* secondParticle = clickedParticle; 
			Spring* spring = new Spring(firstParticle, secondParticle);
			springs.push_back(spring); 
			selectedFirstParticle = false; 
		} else {
			firstParticle = clickedParticle; 
			selectedFirstParticle = true; 
		}
	} else {
		addParticle(x, y); 
	}
}

void ofApp::addParticle(int x, int y)
{
	Particle* particle = new Particle(x, y); 
	particles.push_back(particle); 
}

Particle * ofApp::findParticle(int x, int y)
{
	for (int i = 0; i < particles.size(); i++)
	{
		Particle* particle = particles[i];

		if (particle->position.distance(ofPoint(x, y)) < particle->radius)
		{
			return particle;
		}

	}
	return NULL; 
}

