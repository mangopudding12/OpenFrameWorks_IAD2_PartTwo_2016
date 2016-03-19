#include "Cirkel.h"

Cirkel::Cirkel()
{
	setup(); 
}

void Cirkel::setup()
{
	color.r = ofRandom(20, 100); 
	color.g = ofRandom(60, 150); 
	color.b = ofRandom(200, 255);
}

void Cirkel::draw()
{
	float radius = getRadius(); // opvragen uit de hoofdklas -> zit in ofxbox2d class
	ofPoint position = getPosition(); 

	ofFill(); 
	ofSetColor(color); 
	ofDrawCircle(position.x, position.y, radius);

	ofSetColor(color, 100); 
	ofDrawCircle(position.x, position.y, radius*1.2);
}
