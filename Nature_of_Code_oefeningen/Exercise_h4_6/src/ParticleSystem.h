#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem
{
public:
	ParticleSystem() { };
	ParticleSystem(float x2_, float y2_, float r2_);  // constuctor 


	void addParticle(float x2_, float y2_, float r2_);
	void display(); 
	void move(); 
	void shatter(); 
	void Dead();
	//void run();

	vector<Partical> MoreParticles;

	int rows = 40;
	int cols = 40;
	bool intact = true; 
	bool maakNieuwe = false; 

private:
};