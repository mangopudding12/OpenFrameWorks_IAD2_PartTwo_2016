#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	ofVideoGrabber grabber;
	ofxCvHaarFinder haarFinder;
	ofImage image;

	vector <ofVideoGrabber> grabbers; 
	vector <ofxCvHaarFinder> haarFinders; 
	vector <ofImage> images;
	vector <ofRectangle> blobBoundingRects;

	bool drawBox = true;
};


