#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Spring.h"

class ofApp : public ofBaseApp{

public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
	
private: 
	void addParticle(int x, int y);

	// Ik vraag me af ?? Deze functie staat helemaal niet in de particle klas ??
	// Hoe kan findParticle dan werken ?? 
	Particle* findParticle(int x, int y); 

	// Framwebuffer object
	ofFbo fbo;
	int fadeAmount = 20;

	vector<Particle*> particles;
	vector<Spring*> springs; 

	Particle* firstParticle;
	bool selectedFirstParticle; 

	bool drawParticles = true; 
	bool drawSprings = true; 
};
