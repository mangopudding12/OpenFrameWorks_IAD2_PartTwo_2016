#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	System = new vector<ParticleSystem>;

	ParticleSystem newSystem;
	newSystem = ParticleSystem(100, 100, 25);
	System->push_back(newSystem);

	linee = Line(200.0, 400.0, 200.0, 200.0);
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int k = 0; k < System->size(); k++)
	{
		
		if (System->at(k).LineMove == true)
		{
			cout << "hoi" << endl; 
			System->at(k).doodmachine = true; 
			System->at(k).Dead();
		}
		else {
			System->at(k).doodmachine = false; 
		}

		System->at(k).move(linee);
		linee.move(System->at(k).LineMove);

	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	linee.display();
	
	ofColor(200, 200, 150);
	for (int i = 0; i < System->size(); i++)
	{
		System->at(i).display();
	}
}

// ------------------- Hierin staat informatie over collision line cirkel ----
void ofApp::collisionLineCirkel(int k_)
{	
	
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	for (int i = 0; i < System->size(); i++)
	{
		System->at(i).shatter();
	}

	aanuit = false; 

}

void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (aanuit == false)
	{
		int rows = ofRandom(3, 8);
		int cols = ofRandom(4, 10);
		float y2_ = ofRandom(10, 250);
		float x2_ = ofRandom(20, 850);
		float r_ = ofRandom(5, 45);


		for (int i = 0; i < rows*cols; i++)
		{
			ofColor(90, 90, 9);
			System->at(0).addParticle(x2_ + (i%cols)*r_, y2_ + (i / rows)*r_, r_, i);
		}

		System->at(0).intact = true;
		aanuit = true; 
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
