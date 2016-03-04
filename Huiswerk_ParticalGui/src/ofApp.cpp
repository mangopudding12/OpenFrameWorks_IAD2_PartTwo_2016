#include "ofApp.h"

void ofApp::setup()
{
	ofSetFrameRate(60);

	// Gui setup 
	gui.setup("Instellingen", "setting.xml");
	gui.add(radius_.set("radius", 1, 0, 350));
	gui.add(lifeTime_.set("lifeTime", 1, 0, 5));
	gui.add(rotate_.set("rotate", 1, 0, 360));
	gui.add(maxSpeed_.set("maxSpeed", 1, 0, 500));
	
	gui.loadFromFile("settings.xml");


	

	time = ofGetElapsedTimef();

	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	fbo.begin();
	ofBackground(ofColor::black);
	fbo.end();

	//particle = Particle(&parameters); // geef me adres terug van deze pionter 


}

void ofApp::update()
{
	parameters.radius = radius_; 
	parameters.lifeTime = lifeTime_;
	parameters.rotate = rotate_;
	parameters.maxSpeed = maxSpeed_;


	float currentTime = ofGetElapsedTimef();
	float elapsedTime = ofClamp(currentTime - time, 0, 0.1); // ofClamp een min en max zetten. 
	time = currentTime;


	//if (particle.isAlive)
	//{
	//particle.update(elapsedTime); 
	//}
	//else {
	//particle.setup(); 
	//}


	int i = 0;
	while (i < particles.size())
	{
		if (!particles[i].isAlive)
		{
			particles.erase(particles.begin() + i);
		}
		else {
			i++;
		}
	}

	if (particles.size() < 2000)
	{
		Particle newParticle(&parameters);
		newParticle.setup();
		particles.push_back(newParticle);
	}

	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].update(elapsedTime);
	}
}

void ofApp::draw()
{
	ofBackground(255, 255, 255);

	gui.draw();


	fbo.begin();
	ofEnableAlphaBlending();
	ofSetColor(ofColor::black, 2);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();

	//particle.draw(); 
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i].draw();
	}

	fbo.end();

	ofSetColor(ofColor::white);
	fbo.draw(0, 0);

}
