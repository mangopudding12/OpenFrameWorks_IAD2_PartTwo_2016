#pragma once
#include "ofMain.h"


class Partical 
{
public:
	Partical() { };
	Partical(float x_, float y_, float r_,int wiebenik_,vector<Partical>*tijdelijk_);  // constuctor 

	void move();
	void displayy(float mouseX_,float mouseY_);
	void display();
	void Schermbounds(); 
	void botsingdetection(); 
	bool isDead();


	ofVec2f location;
	ofVec2f accelaration;
	ofVec2f velocity;
	ofVec2f gravity; 
	float lifespan;
	float radius;
	int wiebenik;
	float spring;
	
	vector<Partical>* andereparticless;

private:
};