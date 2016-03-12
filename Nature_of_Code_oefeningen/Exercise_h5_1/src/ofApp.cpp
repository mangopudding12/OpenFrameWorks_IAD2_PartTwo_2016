#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);

	box2d.init(); // aanmaken 
	box2d.createBounds(); // Dit betekent dat de vierkanten niet het scherm kunnen verlaten.
	// je hebt bounds gecreeërt. 
	box2d.setGravity(0, -20); // set gravity
	box2d.setFPS(60.0);
	box2d.registerGrabbing(); // register of je een boxes oppakt en loslaat. 

	// Ga lijnen tekenen 
	for (int i = 0; i<10; i++) {
		float x = ofMap(i, 0, 10, 0, 450);
		float y = ofGetHeight() / 2 + ofRandom(-200, 200);
		groundLine.addVertex(x, y);
	}
	
	ground.addVertexes(groundLine);
	ground.create(box2d.getWorld());
}

//--------------------------------------------------------------
void ofApp::update()
{
	box2d.update(); 

	float w = 16; 
	float h = 16; 

	if (boxes.size() < 250)
	{
		// Vector vullen met vierkanten
		boxes.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));

		// back returns a reference to the last element in the vector
		boxes.back().get()->setPhysics(10.0, 0.5, 1);
		// Setup voor de vierkanten 
		boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
	}
	

	// remove shapes offscreen 
	ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
	cout << "boxes amount: " << boxes.size() << endl; 

	// Hier voeg je de lijnen toe die jezelf hebt 
	// gemaakt in de setup.
	 // dit is belangrijk anders loopt die vast. oneindig tekenen.
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i < boxes.size(); i++)
	{
		ofSetHexColor(0xBF2545);
		boxes[i].get()->draw();
	}

	for (int i = 0; i<edges.size(); i++) {
		edges[i].get()->draw();
	}

	ofSetColor(255);
	ground.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'b')
	{
		boxes.clear(); // verwijder ze allemaal
	}
	
	if (key == 'l')
	{
		ground.clear();
		groundLine.clear(); 
		remove = true; 
	}

	if (key == 'm' && remove == true)
	{
		// Ga lijnen tekenen 
		for (int i = 0; i<15; i++) {
			float x = ofMap(i, 0, 10, 0, 450);
			
			float y; 
			if (i < 7)
			{
				y = ofGetHeight() / 2 + ofRandom(-200, 200);
			}
			else if (i < 13) {
				y =  ofGetHeight() - ofRandom(100, 250)  ;
			}
			else {
				y = ofGetHeight();
			}
			
			

			groundLine.addVertex(x, y);
		}

		ground.addVertexes(groundLine);
		ground.create(box2d.getWorld());
		remove = false; 
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
