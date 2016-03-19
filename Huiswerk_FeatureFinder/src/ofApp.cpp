#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);

	// afbeeldingen laden 
	ofImage imagess;
	imagess.load("eyes.png");
	images.push_back(imagess);
	
	ofImage imagesss;
	imagesss.load("kiss.png");
	images.push_back(imagesss);

	for (int i = 0; i < images.size(); i++)
	{
		ofVideoGrabber grabbertje;
		grabbertje.setup(480, 320, true);
		grabbers.push_back(grabbertje);
	}
	
	ofxCvHaarFinder finder;
	finder.setup("haarcascade_eyes.xml");
	haarFinders.push_back(finder); 

	ofxCvHaarFinder finderr;
	finderr.setup("haarcascade_mouth.xml");
	haarFinders.push_back(finderr);
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < images.size(); i++)
	{
		grabbers[i].update();

		if (grabbers[i].isFrameNew())
		{
			haarFinders[i].findHaarObjects(grabbers[i].getPixels(), 100, 100); // ondergrond vertellen
		} // zoek in elk plaatje of er hoofden zijn in het plaatje. 
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int k = 0; k < images.size(); k++)
	{
		grabbers[k].draw(0, 0);

		ofNoFill();
		for (int i = 0; i < haarFinders[i].blobs.size(); i++)
		{
			ofRectangle blobBoundingRect = haarFinders[i].blobs[i].boundingRect;

			if (drawBox == true)
			{
				ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
			}

			images[k].draw(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'b')
	{
		drawBox = !drawBox;
	}
}