#include "Spring.h"

Spring::Spring(Particle * firstParticle, Particle * secondParticle)
{
	first = firstParticle;
	second = secondParticle;
	length = DEFAULT_LENGTH;
}

void Spring::draw()
{
	ofSetColor(ofColor::white);
	ofDrawLine(first->position, second->position);
}

void Spring::update()
{
	// afstand en richting berekeningen tussen eerst en tweede punt.
	float distance = first->position.distance(second->position);

	ofVec3f acceleration = second->position - first->position;
	acceleration.normalize();

	// Wat gebeurt er hier precies ? Wat is het verschil
	// tussen length en DEFAULT_LENGTH ?? 
	acceleration *= (distance - length) / DEFAULT_LENGTH;

	first->speed += acceleration;
	second->speed -= acceleration;
}
