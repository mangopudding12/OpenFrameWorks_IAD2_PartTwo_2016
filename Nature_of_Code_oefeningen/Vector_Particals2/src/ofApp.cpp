#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

}

//--------------------------------------------------------------
void ofApp::update()
{
	ofBackground(255);

	location__.set(ofGetWidth() / 2, 30);
	Partical harry = Partical(location__); 
	MoreParticles.push_back(harry);

	ofLog(OF_LOG_NOTICE, "Particles " + ofToString(MoreParticles.size()));
}

//--------------------------------------------------------------
void ofApp::draw()
{
	//vector<Partical>::iterator goedteller;
	for (vector<Partical>::iterator goedteller = MoreParticles.begin(); goedteller != MoreParticles.end(); ++goedteller)
	{
		// Waarom in godsnaam hier een pionter ?? 
		// Waarom een pionter van goedteller ?? 
		(*goedteller).run();

		if ((*goedteller).isDead() == true)
		{
			
			// Hij geeft een fout melding en zegt iets moeilijks
			cout << "hoi" << endl; 
			MoreParticles.erase(goedteller);
			cout << "hoi2" << endl;
		}
	}
}