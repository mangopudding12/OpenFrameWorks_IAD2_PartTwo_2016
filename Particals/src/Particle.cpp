#include "Particle.h"

Particle::Particle(int x, int y)
{
	position.set(x, y); // point 
	radius = 40; 
}

void Particle::update()
{
	position += speed;
}

void Particle::display()
{
	ofSetColor(0, 20, 180, 130);
	ofDrawCircle(position, radius); 
}
