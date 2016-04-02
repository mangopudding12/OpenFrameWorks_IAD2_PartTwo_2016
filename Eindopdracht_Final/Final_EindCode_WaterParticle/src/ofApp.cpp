#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofBackground(255);
	ofSetFrameRate(60);

	// Arduino connection pc 
	ofAddListener(myArduino.EInitialized, this, &ofApp::setupArduino);
	arduino_opstarten = false;
	myArduino.connect("COM3", 57600); // aan deze poort zit de arduino 
	myArduino.sendFirmwareVersionRequest(); // Deze regel code niet weg halen anders werkt het niet meer

	// Ruimte in geheugen maken voor een vector 
	System = new vector<ParticleSystem>;

	// Maak 1 line aan 
	linee = Line(ofGetWidth() / 4, (ofGetWidth() / 4) * 3, 450.0, 450.0);

	// Kleurgetal
	kleurverandering = 300;

	// Zet startscherm aan
	fase_code = 0;

	// TekstBegin 
	begintekst.load("Zenfyrkalt.ttf", 30, true, true);
	begintekst.setLineHeight(18.0f);
	begintekst.setLetterSpacing(1.037);

	// Afbeeldingen in laden 
	monsterR.load("monster_R.png");
	monsterL.load("monster_L.png");

	// Achtergrond Particles aanmaken 
	achtergrondaanmaken(); 
}

// ------------- Setup Arduino -------------------
void ofApp::setupArduino(const int& version)
{
	ofRemoveListener(myArduino.EInitialized, this, &ofApp::setupArduino);

	arduino_opstarten = true;

	// Vertellen welke electronica op welke pin zit en wat het doet 
	myArduino.sendAnalogPinReporting(0, ARD_ANALOG); // hier zit watersensor aan

	ofAddListener(myArduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

// -------------- Setup Achtergrond Particle ----------------------
void ofApp::achtergrondaanmaken()
{
	// Achtergrond nummer 1 aanmaken 
	location_.set(ofGetWidth() / 8.5, ofGetHeight() / 6.7);

	AchtergrondParticleSystem newachtergrond1;
	newachtergrond1 = AchtergrondParticleSystem(location_);
	AchtergrondSystem.push_back(newachtergrond1);

	// Achtergrond nummer 2 aanmaken 
	location_.set((ofGetWidth() / 8.5)*7.5, ofGetHeight() / 6.7);

	AchtergrondParticleSystem newachtergrond2;
	newachtergrond2 = AchtergrondParticleSystem(location_);
	AchtergrondSystem.push_back(newachtergrond2);
}


//--------------------------------------------------------------
void ofApp::update()
{
	// Arduino update
	myArduino.update();
	waterreactie(); 

	// Zorgen dat de slaken als ze vallen van kleur veranderen 
	if (aanuit == false)
	{
		if (kleurverandering > 0)
		{
			kleurverandering -= 2;
		}
	}
	else {
		kleurverandering = 300;
	}

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

// --------------- wanneer water op water sensor ------------------
void ofApp::analogPinChanged(const int& pinNum)
{

	// Er ligt geen water op de sensor 
	if (myArduino.getAnalog(0) > 900)
	{
		water_op_sensor = false;
	}

	// Er ligt wel water op de sensor 
	if (myArduino.getAnalog(0) <= 400)
	{
		water_op_sensor = true;
	}
}


void ofApp::waterreactie()
{
	// Wanneer er wel iets in zit dan doe dit 
	if (LegeVectorVullen == true)
	{
		// Wanneer er wel water op de sensor zit dan .... 
		// Je kan er alleen meer particles bij maken als er onder de 500 particles zijn
		// anders wordt mijn pc te traag en ontstaan er sneller errors. 
		if (water_op_sensor == true && System->at(0).Moreparticles->size() <= 350)
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
				float r_ = ofRandom(15, 40);


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

		if (water_op_sensor == true)
		{
			ParticleSystem newSystem;
			newSystem = ParticleSystem((ofGetWidth() / 2) - 95, ofGetHeight() / 9, 25);
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
	
	


	// Wanneer er geen water op de sensor zit dan .... 
	if (water_op_sensor == false)
	{
		for (int i = 0; i < System->size(); i++)
		{
			System->at(i).shatter();
		}

		// Verwijder tekst 2 na druppel weghalen
		if (fase_code == 1)
		{
			fase_code = 2;
			ofBackground(255);
		}

		// Zo gaat niet achtergrond particles uit wanneer je op muis klikt
		// Eerst moet je de vierkante particle aanmaken
		if (LegeVectorVullen == true)
		{
			aanuit = false;
		}

		// De line mag weer bewegen als die geactiveerd is 
		line_bewegen_uit = false;
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
	else if (fase_code == 1) {
		ofSetColor(245, 58, 135);
		begintekst.drawString("Haal de druppel weg", ofGetWidth() / 5.5, 310);
	}
	else {}

	for (int i = 0; i < System->size(); i++)
	{
		ofSetColor(245 - kleurverandering, 205, 245);
		System->at(i).display();
	}

	ofSetColor(255, 255, 255);
	linee.display();

	if (aanuit == true)
	{
		monsterL.draw(-44, ofGetHeight() / 23);
		monsterR.draw((ofGetWidth() / 8.3) * 7, ofGetHeight() / 23);

		for (int i = 0; i < AchtergrondSystem.size(); i++)
		{
			AchtergrondSystem[i].run();
		}
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	// Kan even kijken wat er gebeurt door deze couts 
	if (key == 'd')
	{
		cout << "stopmoving" << endl;
		cout << linee.stopmoving << endl;

		// Alle als er al een system is gemaakt kan 
		// deze cout worden uitgevoert 
		if (System->size() > NULL)
		{
			cout << "Hoeveel balletjes" << endl;
			cout << System->at(0).Moreparticles->size() << endl;

			cout << "line_move" << endl;
			cout << System->at(0).line_move << endl;
		}
		cout << "watersensor" << endl;
		cout << water_op_sensor << endl;
	}
}


void ofApp::exit()
{
	myArduino.disconnect();
}