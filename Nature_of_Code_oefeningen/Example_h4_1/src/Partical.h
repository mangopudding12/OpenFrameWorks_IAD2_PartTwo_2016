#pragma once
#include "ofMain.h"

class Partical
{
public: 
	Partical () { };
	Partical(ofVec2f location_);  // constuctor 

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