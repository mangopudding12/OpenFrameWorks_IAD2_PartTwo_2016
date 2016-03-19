#include "ofMain.h"
#include "ofxBox2d.h"

class Partical: public ofxBox2dCircle
{
public:
	Partical() { };
	Partical(float x_, float y_, float r_);  // constuctor 

	void run();
	void move();
	void display();
	bool isDead();


	ofVec2f location;
	ofVec2f accelaration;
	ofVec2f velocity;
	float lifespan;
	float radius;
private:
};