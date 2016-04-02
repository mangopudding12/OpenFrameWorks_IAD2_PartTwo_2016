#pragma once
#include "ofMain.h"

class AchtergrondParticle
{
public:
	// Constructors 
	AchtergrondParticle() { };
	AchtergrondParticle(ofVec2f location_);  

	// Functions 
	void run();
	void move();
	void display();
	bool isDead();

	// Vectors 
	ofVec2f location;
	ofVec2f accelaration;
	ofVec2f velocity;

	// Float, int's
	int anderekleur;
	float lifespan;
	float radius;


private:
};
