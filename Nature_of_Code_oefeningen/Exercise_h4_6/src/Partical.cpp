#include "Particle.h"

Partical::Partical(float x_, float y_, float r_)
{
	// Varible een waarde geven
	accelaration.set(0, 0.05);
	velocity.set(ofRandom(-1, 1), ofRandom(-2, 0));
	location.set (x_,y_);
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
	velocity += accelaration;
	location += velocity;
	lifespan -= 2;
}

void Partical::display()
{
	ofSetColor(location.x - ofRandom(100, 500), lifespan - 50, location.y - 200, lifespan);
	ofFill();

	ofEllipse(location.x, location.y, radius, radius);
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
