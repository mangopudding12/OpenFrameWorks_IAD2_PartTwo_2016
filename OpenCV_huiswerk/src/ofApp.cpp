#include "ofApp.h"
#define GRABBER_WIDTH 320
#define GRABBER_HEIGHT	240 


//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(0, 0, 0); // scherm zwart maken 
	grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT, true);

	rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hsbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	saturation.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	brightness.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

	filterednum1.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	filterednum2.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

	fase = 1; 
}

//--------------------------------------------------------------
void ofApp::update()
{
	grabber.update();

	if (grabber.isFrameNew())
	{
		rgbImage.setFromPixels(grabber.getPixels().getData(), GRABBER_WIDTH, GRABBER_HEIGHT);

		rgbImage.mirror(false, true);

		hsbImage = rgbImage;
		hsbImage.convertRgbToHsv();

		hsbImage.convertToGrayscalePlanarImages(hue, saturation, brightness);


			for (int j = 0; j < GRABBER_WIDTH * GRABBER_HEIGHT; j++)
			{
			
				if (ofInRange(hue.getPixels()[j], findHuenum1 - 5, findHuenum1 + 5))
				{
					filterednum1.getPixels()[j] = 255;
				}
				else {
					filterednum1.getPixels()[j] = 0;
				}

				if (ofInRange(hue.getPixels()[j], findHuenum2 - 5, findHuenum2 + 5))
				{
					filterednum2.getPixels()[j] = 255;
				}
				else {
					filterednum2.getPixels()[j] = 0;
				}

			}

			
		filterednum1.flagImageChanged();
		filterednum2.flagImageChanged();

		contoursnum1.findContours(filterednum1, 50, GRABBER_WIDTH*GRABBER_HEIGHT / 2, 1, false);
		contoursnum2.findContours(filterednum2, 50, GRABBER_WIDTH*GRABBER_HEIGHT / 2, 1, false);

	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor::white);
	rgbImage.draw(640, 0);
	hsbImage.draw(0, 0);

	hue.draw(0, 240);
	saturation.draw(320, 240);
	brightness.draw(640, 240);

	filterednum1.draw(0, 480);
	contoursnum1.draw(640, 0);

	filterednum2.draw(0, 480);
	contoursnum2.draw(640, 0);

	ofSetColor(ofColor::blue, 100);
	ofFill();

	for (int i = 0; i < contoursnum1.nBlobs; i++)
	{
		ofDrawCircle(contoursnum1.blobs[i].centroid.x + 640, contoursnum1.blobs[i].centroid.y, 20);
	}

	ofSetColor(ofColor::red, 100);
	ofFill();

	for (int i = 0; i < contoursnum2.nBlobs; i++)
	{
		ofDrawCircle(contoursnum2.blobs[i].centroid.x + 640, contoursnum2.blobs[i].centroid.y, 20);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	// Door de pixel heen zoeken
	if (fase == 1)
	{
		findHuenum1 = hue.getPixels()[y * GRABBER_WIDTH + x];
		fase = 2; 
	}
	else if (fase == 2) {
		findHuenum2 = hue.getPixels()[y * GRABBER_WIDTH + x];
		fase = 1; 
	}
		
	
}


