#pragma once
#include "ofMain.h"
#include "Partical.h"

class ParticleSystem
{
public:
	ParticleSystem() { };
	ParticleSystem(ofVec2f location_);  // constuctor 


	void addParticle(); 
	void run();
	ofVec2f origin;
	vector<Partical> MoreParticles;

private:
};