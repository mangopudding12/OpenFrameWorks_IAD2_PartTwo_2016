#include "ofApp.h"
#include "Ball.h"

Ball ball;
Ball ball2;

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(30, 30, 30);

	drawGrid = false; 
	drawBox = false;

	ball.setup();
	ball2.setup(); 

	light.setPointLight(); 
	light.setPosition(200, 200, 200);
}

//--------------------------------------------------------------
void ofApp::update() {
	ball.update();
	ball2.update(); 

	// Distance is een standaard functie in ofvec3
	if (ball.position.distance(ball2.position) < ball.radius * 2)
	{
		ball.speed *= -1;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofEnableDepthTest(); 

	cam.begin();
	light.enable(); 

	if (drawGrid)
	{
		ofDrawGrid(200);
	}

	if (drawBox)
	{
		//ofNoFill(); 
		ofSetColor(255,255,255,100);
		ofDrawBox(800, 800, 800);
		ofFill(); 
	}

	ball.draw();
	ball2.draw(); 

	light.disable();
	cam.end(); 
	ofDisableDepthTest(); 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'g')
	{
		drawGrid = !drawGrid; 
	}
	else if (key == 'b') {
		drawBox = !drawBox;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
