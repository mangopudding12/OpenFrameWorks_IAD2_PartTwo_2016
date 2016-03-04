#pragma once

#include "ofMain.h"

class Parameters {
public:
	Parameters();

	ofPoint startingPoint;
	float radius = 15;
	float maxSpeed = 300;
	float lifeTime = 2.0;
	float rotate = 90;
};
