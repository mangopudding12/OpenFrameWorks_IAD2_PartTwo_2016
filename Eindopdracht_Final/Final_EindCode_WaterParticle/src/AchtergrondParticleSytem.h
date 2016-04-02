#pragma once
#include "ofMain.h"
#include "AchtergrondParticle.h"


class AchtergrondParticleSystem
{
public:

	// Constuctors 
	AchtergrondParticleSystem() { };
	AchtergrondParticleSystem(ofVec2f location_);  

	// Functions 
	void addParticle();
	void run();

	// Vector
	ofVec2f origin;

	// Vector lijstje
	vector<AchtergrondParticle> AchtergrondParticles;

private:
};

