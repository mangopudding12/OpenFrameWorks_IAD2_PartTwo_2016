#pragma once
#include "ofMain.h"

class Partical
{
public:
	Partical() { };
	Partical(float x_, float y_ ,float r_);  // constuctor 

	void run();
	void move();
	void display();
	bool isDead();


	ofVec2f location;
	ofVec2f accelaration;
	ofVec2f velocity;
	float lifespan;
	float radius;
private:
};