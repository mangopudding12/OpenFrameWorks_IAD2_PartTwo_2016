#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofxBox2d box2d; 
		vector <shared_ptr<ofxBox2dRect>> boxes;
		vector <shared_ptr<ofxBox2dRect>> circle;
		vector <ofPolyline> lines; 
		vector <shared_ptr<ofxBox2dEdge>> edges; // lijnen

		ofPolyline groundLine; // hiermee kan je lijn tekenen 
		ofxBox2dEdge ground; // uiteinde van lijnen denk ik

		bool remove = false; 
};
