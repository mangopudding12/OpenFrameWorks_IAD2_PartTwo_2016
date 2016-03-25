#include "Particle.h"

Partical::Partical(float x_, float y_, float r_)
{
	// Varible een waarde geven
	accelaration.set(0, 5);
	velocity.set(ofRandom(-100, 100), ofRandom(-200, 0));
	location.set(x_, y_);
	lifespan = 255.0;
	radius = r_;
	
}


void Partical::run()
{
	move();
	display();
}

void Partical::move()
{
	position = getPosition();
	velocity -= accelaration;
	position += velocity; 
}

void Partical::display()
{
	ofSetColor(position.x - ofRandom(100, 500), lifespan - 50, position.y - 200, lifespan);
	ofFill();
	ofDrawCircle(position.x, position.y, radius);
}

bool Partical::isDead()
{
	if (lifespan < 0.0)
	{
		return true;
	}
	else {
		return false;
	}
}