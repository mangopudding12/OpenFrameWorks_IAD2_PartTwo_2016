#include "Cirkel.h"

Partical::Partical(float x_, float y_, float r_, int wiebenik_, vector<Partical> tijdelijk_)
{
	// Varible een waarde geven
	accelaration.set(0, 0.05);
	velocity.set(ofRandom(-1, 1), ofRandom(-2, 0));
	location.set(x_, y_);
	lifespan = 255.0;
	radius = r_;
	wiebenik = wiebenik_; 
	andereparticles = tijdelijk_;
}

void Partical::botsingdetection()
{
	for (int i = wiebenik + 1; i < andereparticles.size(); i++)
	{
		// Hey Edwin
		// Het is echt super raar deze for loop wordt gewoon niet door gelopen
		// Hij wordt niet gebruikt en ik snap niet waarom 
		// deze forloop moet juist mijn collision checken.
		// Moet ik met pionter gaan werken misschien ?? 
		// en hoe eigenijk :O 

		// afstand berekenen tussen de particles
		float dx = andereparticles[i].location.x - location.x; 
		float dy = andereparticles[i].location.y - location.y; 
		float afstand = sqrt(dx*dx + dy*dy);
		

		// Als dit waar is dan raken de cirkels elkaar aan. 
		if (afstand < (andereparticles[i].radius / 2) + (radius / 2))
		{
			cout << "collision" << endl;
		}
	}
}



void Partical::Schermbounds()
{
	// links
	if (location.x < (radius / 2))
	{
		location.x = (radius / 2);
	} 

	// rechts 
	if (location.x > ofGetWidth() - (radius/2))
	{
		location.x = ofGetWidth() - (radius / 2);
	}

	// bovenkant 
	if (location.y < (radius / 2))
	{
		location.y = (radius / 2);
	}

	// grond
	if (location.y > ofGetHeight() - (radius / 2))
	{
		location.y = ofGetHeight() - (radius / 2);
	}
}


void Partical::move()
{
	velocity += accelaration;
	location += velocity;
	//lifespan -= 2;
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
