#include "Particle.h"

Particle::Particle(Parameters* parameters)
{
	isAlive = false;
	param = parameters;
}

void Particle::setup()
{
	position = param->startingPoint + randomPointOnCircle(param->radius);
	//position = param->startingPoint; // Op de manier ontstaan alle particle on zelfde startpositie

	speed = randomPointOnCircle(param->maxSpeed);
	age = 0;
	maxAge = param->lifeTime;
	isAlive = true;
}

void Particle::update(float elapsedTime)
{
	if (!isAlive == true) return;

	speed.rotate(0, 0, param->rotate* elapsedTime);
	
	ofVec3f acceleration;
	ofVec3f distance = position - param->startingPoint;
	if (ofInRange(distance.length(), 0, param->radius))
	{
		distance.normalize();
		acceleration += distance * param->force;
		acceleration.x = -distance.y * param->spinning;
		acceleration.y = distance.x * param->spinning;
	}

	speed += acceleration * elapsedTime;
	speed *= (1 - param->friction);
	position += speed * elapsedTime;

	age += elapsedTime;

	if (age >= maxAge)
	{
		isAlive = false;
	}
}

void Particle::draw()
{
	//ofSetColor(150, age*2, age+80);

	// Andere manier om mooie kleuren te krijgen. 
	ofColor color = ofColor::red;
	float hue = ofMap(age, 0, maxAge, 0, 255);
	color.setHue(hue);
	ofSetColor(color);



	ofDrawCircle(position, param->size); // 3 is grote van cirkel 
}

ofPoint Particle::randomPointOnCircle(float maxRadius)
{
	ofPoint point;
	float radius = ofRandom(0, maxRadius);
	float angle = ofRandom(0, M_TWO_PI);

	point.x = cos(angle) * radius;
	point.y = sin(angle) * radius;

	return point;
}
