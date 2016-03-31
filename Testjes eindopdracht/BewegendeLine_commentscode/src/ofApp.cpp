#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);
	
	// Ruimte in geheugen maken voor een vector 
	System = new vector<ParticleSystem>;

	// Stop in vector System als het eerst vierkante particleSystem 
	ParticleSystem newSystem;
	newSystem = ParticleSystem(100, 100, 25);
	System->push_back(newSystem);

	// Maak 1 line aan 
	linee = Line(200.0, 400.0, 370.0, 370.0);
}


//--------------------------------------------------------------
void ofApp::update()
{
	// Loop door fucntions heen 
	for (int k = 0; k < System->size(); k++)
	{
		// We stoppen de line class in move van Sytem zodat de collision
		// Tussen de line en cirkel kunnen berekent worden.
		System->at(k).move(linee);

		// In de line move functie stoppen we line_move boolean 
		// om zo te bepalen wanneer de lijn in beweging komt en wanneer die stopt.
		if (line_bewegen_uit == false)
		{
			linee.move(System->at(k).line_move);
		} 
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

	// De line mag weer bewegen als die geactiveerd is 
	line_bewegen_uit = false;
}

void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	// Kan even kijken wat er gebeurt door deze couts 
	if (key == 'd')
	{
		cout << "line_move" << endl; 
		cout << System->at(0).line_move << endl; 
		cout << "stopmoving" << endl;
		cout << linee.stopmoving << endl; 
		cout << "Hoeveel balletjes" << endl; 
		cout << System->at(0).Moreparticles->size() << endl;
	}

	// Je kan er alleen meer particles bij maken als er onder de 500 particles zijn
	// anders wordt mijn pc te traag en ontstaan er sneller errors. 
	if (key == 'a' && System->at(0).Moreparticles->size() <= 500)
	{
		// Lijn staat stil tot dat je de muis hebt gedrukt.
		line_bewegen_uit = true; 

		// Wanneer er voor het eerst een nieuw particleSystem wordt toegevoegt
		// Accepteren we elke collision met de line
		System->at(0).hitactiveren = true;

		if (aanuit == false)
		{
			int rows = ofRandom(3, 8);
			int cols = ofRandom(4, 10);
			float y2_ = ofRandom(10, 250);
			float x2_ = ofRandom(400, 850);
			float r_ = ofRandom(20, 45);


			for (int i = 0; i < rows*cols; i++)
			{
				ofColor(90, 90, 9);
				System->at(0).addParticle(x2_ + (i%cols)*r_, y2_ + (i / rows)*r_, r_, i);
			}

			System->at(0).intact = true;
			aanuit = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) 
{
	
}
