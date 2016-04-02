#pragma once
#include "ofMain.h"
#include "AchtergrondParticle.h"


class AchtergrondParticleSystem
{
public:

	// Constuctors 
	AchtergrondParticleSystem() { };
	AchtergrondParticleSystem(ofVec2f location_);  // constuctor 

	// Functions 
	void addParticle();
	void run();

	// Vectors
	ofVec2f origin;
	vector<AchtergrondParticle> AchtergrondParticles;

private:
};
