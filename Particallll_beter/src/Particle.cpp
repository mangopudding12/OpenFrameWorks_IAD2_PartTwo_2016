#include "Particle.h"

Particle::Particle()
{
	isAlive = false; 

}

void Particle::setup(ofPoint StartingPoint, float radius, float velocityRadius, float maxAge, float rotateSpeed)
{
	position = StartingPoint + randomPointOnCircle(radius);
}

ofPoint Particle::randomPointOnCircle(float maxRadius)
{
	ofPoint pnt; 
	float radius = ofRandom(0, maxRadius);
	float angle = ofRandom(0, M_TWO_PI); 

	// Bereken je waar je start punt komt voor je partical
	pnt.x = cos(angle) * radius;
	pnt.y = sin(angle) * radius; 

	return pnt; 
}

void Particle::update(float elapsedTime)
{

}

void Particle::draw()
{
}
