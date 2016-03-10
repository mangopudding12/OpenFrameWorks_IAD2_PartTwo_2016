#include "ofApp.h"

void ofApp::setup()
{
	ofSetFrameRate(60); 
	
	time = ofGetElapsedTimef(); 

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	fbo.begin(); 
	ofBackground(ofColor::black);
	fbo.end(); 

	//particle = Particle(&parameters); // geef me adres terug van deze pionter 


}

void ofApp::update() 
{
	float currentTime = ofGetElapsedTimef(); 
	float elapsedTime = ofClamp(currentTime - time, 0, 0.1); // ofClamp een min en max zetten. 
	time = currentTime; 

	int i = 0; 
	while (i < particles.size())
	{
		if (!particles[i].isAlive)
		{
			particles.erase(particles.begin() + i); 
		}
		else {
			i++; 
		}
	}

	int newParticles = birthRate * elapsedTime; 
    
	for (int i = 0; i < newParticles; i++)
	{
		Particle newParticle(&parameters); 
		newParticle.setup(); 
		particles.push_back(newParticle);
	}

	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].update(elapsedTime);
	}
}

void ofApp::draw()
{
	ofBackground(255,255,255); 

	fbo.begin(); 
	ofEnableAlphaBlending(); 
	ofSetColor(ofColor::black, 2);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending(); 

	//particle.draw(); 
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].draw(); 
	}

	fbo.end(); 

	ofSetColor(ofColor::white);
	fbo.draw(0,0); 
	
}
