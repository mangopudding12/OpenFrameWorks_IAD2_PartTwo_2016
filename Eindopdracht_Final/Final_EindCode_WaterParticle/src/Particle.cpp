#include "Particle.h"

// ------------------- Constructor --------------------------- 
Particle::Particle(float x_, float y_, float r_, int wiebenik_, vector<Particle>* tijdelijk_)
{
	ofSetColor(location.x - ofRandom(100, 500), ofRandom(0, 255), ofRandom(0, 255));

	// alle Vectors waarden geven 
	accelaration.set(0, 0.05);
	velocity.set(-1, -1);
	location.set(x_, y_);
	gravity.set(0.995, 0.995);

	// Alle float en int waarden geven 
	radius = r_;
	wiebenik = wiebenik_;
	spring = 0.5;

	// Tijdelijk_ is een pionter vector uit de ofApp.cpp die wordt gelijkt 
	// gesteld met andereparticles zodat we de collision tussen als cirkels 
	// kunnen berekenen en detecteren. 
	andereparticles = tijdelijk_;

	// Afbeelding inladen
	slak.load("slak.png");

}

// --------------------------- Collisions tussen Cirkels -----------------------
void Particle::botsingdetection()
{
	for (int i = wiebenik + 1; i < andereparticles->size(); i++)
	{
		float dx = andereparticles->at(i).location.x - location.x;
		float dy = andereparticles->at(i).location.y - location.y;
		float afstand = sqrt(dx*dx + dy*dy);
		float minDist = (andereparticles->at(i).radius / 2 + radius / 2);


		// Als er een collision is dan ... 
		if (afstand < minDist)
		{
			// Hier berekenen we de kracht die de cirkels uit elkaar duwen
			// wanneer er een collisions plaats vind. 
			float angle = atan2(dy, dx);
			float targetX = location.x + cos(angle) * minDist;
			float targetY = location.y + sin(angle) * minDist;
			float ax = (targetX - andereparticles->at(i).location.x) * spring;
			float ay = (targetY - andereparticles->at(i).location.y) * spring;

			velocity.y -= ay;
			velocity.x -= ax;

			andereparticles->at(i).velocity.y += ay;
			andereparticles->at(i).velocity.x += ax;

			// Damping
			andereparticles->at(i).velocity *= gravity;

			// Maximum velocity instellen 
			andereparticles->at(i).velocity.limit(4);
			velocity.limit(4);
		}
	}
}


// ----------------- Bouncing of the screens -------------------------------- 
void Particle::Schermbounds()
{
	// links
	if (location.x < (radius / 1.3))
	{
		location.x = (radius / 1.3);
	}

	// rechts 
	if (location.x > ofGetWidth() - (radius / 1.3))
	{
		location.x = ofGetWidth() - (radius / 1.3);
	}

	// bovenkant 
	if (location.y < (radius / 2))
	{
		location.y = (radius / 2);
	}

	// grond
	if (location.y > ofGetHeight() - (radius + 10))
	{
		location.y = ofGetHeight() - (radius + 10);
	}
}

// -------------------------- De beweging van de Cirkels -------------------------
void Particle::move()
{
	velocity += accelaration;
	location += velocity;
}

// -------------------------- Afbeelden Cirkels --------------------------------
void Particle::display()
{
	ofEllipse(location.x, location.y, radius, radius);
	slak.draw(location.x - 24, location.y - 14);
}
