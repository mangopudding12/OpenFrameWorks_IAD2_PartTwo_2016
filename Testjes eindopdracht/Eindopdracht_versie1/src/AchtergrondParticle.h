#pragma once
#include "ofMain.h"

class AchtergrondParticle
{
public:
	AchtergrondParticle() { };
	AchtergrondParticle(ofVec2f location_);  // constuctor 

	void run();
	void move();
	void display();
	bool isDead();
	int anderekleur;

	ofVec2f location;
	ofVec2f accelaration;
	ofVec2f velocity;
	float lifespan;
	float radius;
private:
};
