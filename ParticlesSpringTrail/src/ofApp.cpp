#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofBackground(0);

	ofSetBackgroundAuto (false); //  niet schoon maken
	ofEnableAlphaBlending(); 

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); // Framebuffer aan maken 
	
	fbo.begin(); // teken operatie nu op framebuffer plaats.
	ofClear(0, 0, 0, 0); // 100% leeg maken 
	fbo.end(); 
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

	fbo.begin(); 

	ofFill();
	ofSetColor(0, 0, 0, fadeAmount);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

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

	fbo.end(); 

	fbo.draw(0,0); // teken de framebuffer op het scherm met de particals die in framebuffer zitten. 

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

