#include "Cirkel.h"

Partical::Partical(float x_, float y_, float r_, int wiebenik_, vector<Partical>* tijdelijk_)
{
	// Begin kleur 
	ofSetColor(location.x - ofRandom(100, 500), ofRandom(0, 255), ofRandom(0, 255));

	// Varible een waarde geven
	accelaration.set(0, 0.05);
	velocity.set(-1, -1);
	location.set(x_, y_);
	radius = r_;
	wiebenik = wiebenik_;
	spring = 0.5;
	lifespan = 255; 

	andereparticless = tijdelijk_;
	gravity.set(0.995, 0.995);
}

void Partical::botsingdetection()
{
	for (int i = wiebenik + 1; i < andereparticless->size(); i++)
	{
		float dx = andereparticless->at(i).location.x - location.x;
		float dy = andereparticless->at(i).location.y - location.y;
		float afstand = sqrt(dx*dx + dy*dy);
		float minDist = (andereparticless->at(i).radius / 2 + radius / 2);


		// Als er een collision is dan ... 
		if (afstand < minDist)
		{
			float angle = atan2(dy, dx);
			float targetX = location.x + cos(angle) * minDist;
			float targetY = location.y + sin(angle) * minDist;
			float ax = (targetX - andereparticless->at(i).location.x) * spring;
			float ay = (targetY - andereparticless->at(i).location.y) * spring;

			velocity.y -= ay;
			velocity.x -= ax;

			andereparticless->at(i).velocity.y += ay;
			andereparticless->at(i).velocity.x += ax;

			// Damping
			andereparticless->at(i).velocity *= gravity;

			// Maximum velocity instellen 
			andereparticless->at(i).velocity.limit(4);
			velocity.limit(4);
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
	if (location.x > ofGetWidth() - (radius / 2))
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
}

void Partical::display()
{
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
