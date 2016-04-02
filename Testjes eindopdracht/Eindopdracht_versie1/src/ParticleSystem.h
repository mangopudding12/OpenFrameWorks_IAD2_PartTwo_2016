#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "Line.h"

class ParticleSystem
{
public:

	// Constuctors 
	ParticleSystem() { };
	ParticleSystem(float x2_, float y2_, float r2_);

	// Functions 
	void addParticle(float x2_, float y2_, float r2_, float k_);
	float kleur(float kleur1);
	void display();
	void move(Line line_);
	void shatter();

	float kleurr1;

	// Pionter form a vector 
	vector <Particle>* Moreparticles;

	// bools 
	bool intact = true;
	bool line_move = false;
	bool hit;
	bool hitactiveren = false;

	// int, float enzo. 
	int rows = 8;
	int cols = 4;


private:
};