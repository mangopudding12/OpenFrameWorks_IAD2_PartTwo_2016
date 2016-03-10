#include "Partical.h"

Partical::Partical(ofVec2f location_)
{
	// Varible een waarde geven
	accelaration.set(0, 0.05);
	velocity.set(ofRandom(-1, 1), ofRandom(-2, 0));
	location = location_;
	lifespan = 255.0;
	radius = 12;
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
	ofSetColor(lifespan, 200, lifespan, lifespan);
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
