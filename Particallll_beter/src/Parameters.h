#pragma once

#include "ofMain.h"

class Parameters {
public:
	Parameters();

	ofPoint startingPoint;
	float radius = 80; 
	float maxSpeed = 300; 
	float lifeTime = 1.0; 
	float rotate = 90;
};
