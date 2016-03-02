#pragma once
#include "ofMain.h"

class Particle 
{
public: 
	Particle();

	void setup(ofPoint StartingPoint, float radius, float velocityRadius, float maxAge, float rotateSpeed);
	void update(float elapsedTime); 
	void draw(); 
	ofPoint randomPointOnCircle(float maxRadius);

	ofPoint position; 
	ofVec3f speed; 

	float age; 
	float maxAge; 
	bool isAlive; 

	float rotateSpeed; 

private:
};