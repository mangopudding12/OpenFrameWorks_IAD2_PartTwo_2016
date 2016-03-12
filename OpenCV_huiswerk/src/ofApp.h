#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void mousePressed(int x, int y, int button);

	ofVideoGrabber grabber;
	ofxCvColorImage rgbImage;
	ofxCvColorImage hsbImage;

	ofxCvGrayscaleImage hue;
	ofxCvGrayscaleImage saturation;
	ofxCvGrayscaleImage brightness;

	ofxCvGrayscaleImage filterednum1;
	ofxCvContourFinder contoursnum1;

	ofxCvGrayscaleImage filterednum2;
	ofxCvContourFinder contoursnum2;

	int findHuenum1;
	int findHuenum2;
	int fase; 
	//vector <int> findHue; 


};
