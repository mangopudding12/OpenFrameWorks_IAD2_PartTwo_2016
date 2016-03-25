#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	ofBackground(0);

	box2d.init(); // box2d aanzetten 
	box2d.setFPS(30); // zet framerate voor box2d 
					  //box2d.setGravity(0,-10); // gravity setup (x,y); 
					  //box2d.createGround(); // dan kunnen ze niet door de grond
	box2d.createBounds(); // alle zijkanten niet door heen kunnen

	box2d.registerGrabbing();
}

//--------------------------------------------------------------
void ofApp::update()
{
	
	for (int i = 0; i < circles.size(); i++)
	{
		// circles is een pionter , box2d hoef je zelf niet te tekenen alleen bij boundaries.
		circles[i]->move();
	}
	box2d.update(); // reken alles door 
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i < circles.size(); i++)
	{
		// circles is een pionter , box2d hoef je zelf niet te tekenen alleen bij boundaries.
		
		circles[i]->display();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'h')
	{
		Partical* circle = new Partical(ofGetWidth()/2,ofGetHeight()/2,50);
		circle->setPhysics(0.3, 0.5, 0.1);
		circle->setup(box2d.getWorld(), mouseX, mouseY, circle->radius);
		circles.push_back(circle);
	}
	else if (key == OF_KEY_RETURN)
	{
		box2d.setGravity(0, 0);
	}
	else if (key == OF_KEY_UP) {
		box2d.setGravity(0, -5);
	}
	else if (key == OF_KEY_DOWN)
	{
		box2d.setGravity(0, 5);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}
