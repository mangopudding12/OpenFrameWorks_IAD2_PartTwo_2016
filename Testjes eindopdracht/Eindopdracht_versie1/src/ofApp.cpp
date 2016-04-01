#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	// Zet startscherm aan
	fase_code = 0;

	// TekstBegin 
	begintekst.load("Zenfyrkalt.ttf", 30, true, true);
	begintekst.setLineHeight(18.0f);
	begintekst.setLetterSpacing(1.037);


	// Achtergrond nummer 1 aanmaken 
	location_.set(ofGetWidth()/10,ofGetHeight()/9);

	AchtergrondParticleSystem newachtergrond1;
	newachtergrond1 = AchtergrondParticleSystem(location_);
	AchtergrondSystem.push_back(newachtergrond1);

	// Achtergrond nummer 2 aanmaken 
	location_.set((ofGetWidth() / 10)*9, ofGetHeight() / 9);

	AchtergrondParticleSystem newachtergrond2;
	newachtergrond2 = AchtergrondParticleSystem(location_);
	AchtergrondSystem.push_back(newachtergrond2);


	// Ruimte in geheugen maken voor een vector 
	System = new vector<ParticleSystem>;

	// Maak 1 line aan 
	linee = Line(ofGetWidth() / 4, (ofGetWidth() / 4) * 3, 450.0, 450.0);
}


//--------------------------------------------------------------
void ofApp::update()
{

	// Aanuit zetten van achtergrondParticles
	if (aanuit == true)
	{
		for (int i = 0; i < AchtergrondSystem.size(); i++)
		{
			AchtergrondSystem[i].addParticle();
		}
	}


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
	if (fase_code == 0)
	{
		ofSetColor(245, 58, 135);
		begintekst.drawString("Laat een druppel vallen", ofGetWidth() / 7, 300);
	}

	ofSetColor(200, 20, 200);
	linee.display();

	for (int i = 0; i < System->size(); i++)
	{
		System->at(i).display();
	}

	if (aanuit == true)
	{
		for (int i = 0; i < AchtergrondSystem.size(); i++)
		{
			AchtergrondSystem[i].run();
		}
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	for (int i = 0; i < System->size(); i++)
	{
		System->at(i).shatter();
	}

	// Zo gaat niet achtergrond particles uit wanneer je op muis klikt
	// Eerst moet je de vierkante particle aanmaken
	if (LegeVectorVullen == true)
	{
		aanuit = false;

		// Morgen moet hier nog dingen aanpassen 
		// zodat elke keer als je klikt er een nieuw achterparticle system 
		// ontstaat tot een bepaalt aantal
		// daarna wordt die gereset waardoor ??? de line ?? 
		// of door collision met line of gewoon random ?? 
		// Maak een int die steeds positie in location stond om zo te veranderen.
		location_.set((ofGetWidth() / 10) * 7, ofGetHeight() / 7);

		AchtergrondParticleSystem newachtergrond2;
		newachtergrond2 = AchtergrondParticleSystem(location_);
		AchtergrondSystem.push_back(newachtergrond2);
	}

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

	// Wanneer er wel iets in zit dan doe dit 
	if (LegeVectorVullen == true)
	{
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
				int rows = ofRandom(2, 9);
				int cols = ofRandom(2, 9);
				float y2_ = ofRandom(5, 200);
				float x2_ = ofRandom(ofGetWidth() / 7, (ofGetWidth() / 7) * 5);
				float r_ = ofRandom(15, 35);


				for (int i = 0; i < rows*cols; i++)
				{
					System->at(0).addParticle(x2_ + (i%cols)*r_, y2_ + (i / rows)*r_, r_, i);
				}

				System->at(0).intact = true;
				aanuit = true;
			}
		}
	}
	else if (LegeVectorVullen == false) {
		if (key == 'a')
		{
			ParticleSystem newSystem;
			newSystem = ParticleSystem((ofGetWidth() / 2) - 95, ofGetHeight() / 9, 15);
			System->push_back(newSystem);
			LegeVectorVullen = true;

			// De begin tekst moet hier op 1 worden gezet zodat die uit gaat.
			if (fase_code == 0)
			{
				fase_code = 1;
				ofBackground(255);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}