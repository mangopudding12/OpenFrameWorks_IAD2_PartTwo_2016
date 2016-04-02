#pragma once
#include "ofMain.h"


class Particle
{
public:

	// Constuctors 
	Particle() { };
	Particle(float x_, float y_, float r_, int wiebenik_, vector<Particle>*tijdelijk_);  // constuctor 

																						 // Functions 
	void move();
	void display();
	void Schermbounds();
	void botsingdetection();
	

	// Pionter from a vector 
	vector<Particle>* andereparticles;

	// Vectors 
	ofVec2f location;
	ofVec2f accelaration;
	ofVec2f velocity;
	ofVec2f gravity;

	// float, int enzo. 
	float radius;
	int wiebenik;
	float spring;
	float lifespan;

	// Afbeeldingen 
	ofImage slak;

private:
};
