
#pragma once
#include "ofMain.h"


class Partical
{
public:
	Partical() { };
	Partical(float x_, float y_, float r_, int wiebenik_, vector<Partical>*tijdelijk_);  // constuctor 

	void move();
	void display();
	void Schermbounds();
	void botsingdetection();


	ofVec2f location;
	ofVec2f accelaration;
	ofVec2f velocity;
	ofVec2f gravity;
	float radius;
	int wiebenik;
	float spring;

	vector<Partical>* andereparticless;

private:
};