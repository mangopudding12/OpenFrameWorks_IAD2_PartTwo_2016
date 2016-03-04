#include "Partical.h"

Partical::Partical(ofVec2f location_)
{
	// Varible een waarde geven
	accelaration.set(0, 0.001);
	velocity.set(ofRandom(-0.3, 0.3), ofRandom(-0.3, 0));
	location = location_;
	lifespan = 255.0;
	radius = 80;
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
	lifespan -= 0.4;
	
}

void Partical::display()
{
	ofSetColor(lifespan, 200, lifespan, lifespan);
	//ofSetLineWidth(3); // weet niet of dit goed is !!! 
	ofEllipse(location.x, location.y, radius, radius);
}

bool Partical::isDead()
{
	//if (lifespan < 0.0)
	//{
		//return true;
	//}
	//else {
		//return false;
	//}

	return (lifespan < 0.0);
}
