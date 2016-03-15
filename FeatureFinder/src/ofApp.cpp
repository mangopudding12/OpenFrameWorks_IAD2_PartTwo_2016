#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);

	image.load("eyes.png"); 

	grabber.setup(480,320,true);
	//haarFinder.setup("haarcascade_frontalface_default.xml"); // xml inladen 
	haarFinder.setup("haarcascade_eyes.xml");
}

//--------------------------------------------------------------
void ofApp::update()
{
	grabber.update(); 

	if (grabber.isFrameNew())
	{
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100); // ondergrond vertellen
	} // zoek in elk plaatje of er hoofden zijn in het plaatje. 
}

//--------------------------------------------------------------
void ofApp::draw()
{
	grabber.draw(0,0); 

	ofNoFill(); 
	for (int i = 0; i < haarFinder.blobs.size(); i++)
	{
		ofRectangle blobBoundingRect = haarFinder.blobs[i].boundingRect;
		
		if (drawBox == true)
		{
			ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
		}
		
		image.draw(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
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