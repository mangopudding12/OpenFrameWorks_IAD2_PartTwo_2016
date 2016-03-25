#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//loader.loadModel("raven.dae"); 
	//loader.loadModel("dragon.dae");

	// Animatie model 
	//loader.loadModel("dwarf.x");
	//loader.playAllAnimations(); 
	//loader.setLoopStateForAllAnimations(OF_LOOP_NORMAL);

	loader.loadModel("lee.dae");
	mesh = loader.getMesh(0); 
	origVertices = mesh.getVertices(); //  we maken copie 
}

//--------------------------------------------------------------
void ofApp::update()
{
	// update na elke animatie frame 
	//loader.update();

	vector<ofPoint> vertices = mesh.getVertices(); 

	for (int i = 0; i < origVertices.size(); i += 4)
	{
		ofPoint newVertex = origVertices[i] * ofMap(sin(ofGetElapsedTimef()),-1,1,0.9,1.4); 
		mesh.setVertex(i, newVertex); 
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackgroundGradient(ofColor(64), ofColor::black); 

	camera.setScale(1, -1, 1);
	camera.begin(); 
		ofEnableDepthTest(); 
			//loader.drawWireframe();
			//loader.drawFaces();
			
		ofPushMatrix(); 
			ofMultMatrix(loader.getModelMatrix());

			mesh.drawWireframe(); 

		ofPopMatrix();

			
		ofDisableDepthTest(); 
	camera.end(); 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
