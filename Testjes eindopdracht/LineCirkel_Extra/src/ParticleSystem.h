#pragma once
#include "ofMain.h"
#include "Cirkel.h"
#include "Line.h"

class ParticleSystem
{
public:
	ParticleSystem() { };
	ParticleSystem(float x2_, float y2_, float r2_);  // constuctor 


	void addParticle(float x2_, float y2_, float r2_,float k_);
	void display();
	void move(Line linee);
	void shatter();
	void Dead();
	
	vector <Partical>* Moreparticles;

	int rows = 20;
	int cols = 20;
	bool intact = true;
	bool maakNieuwe = false;
	bool hit;

private:
}; 
