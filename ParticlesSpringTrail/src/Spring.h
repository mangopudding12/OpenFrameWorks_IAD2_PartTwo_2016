#pragma once
#include "Particle.h"
#define DEFAULT_LENGTH 100 

class Spring
{
public:
	Spring(Particle* first, Particle* second);

	void draw();
	void update();

private:
	// Pointer naar class particle die first heet !!
	Particle* first;
	Particle* second;
	int length;
};