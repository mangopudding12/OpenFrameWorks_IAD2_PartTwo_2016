#pragma once
#include "ofMain.h"
#include "Line.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include "AchtergrondParticleSytem.h"

class ofApp : public ofBaseApp {

public:

	// Functions 
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void achtergrondaanmaken(); 
	void waterreactie(); // creeërt particle vierkant en activeert move function  
	void exit();

	// Class line 
	Line linee;

	// Zo maak je een vector aan doormiddel van new woord te gebruiken. 
	vector <ParticleSystem>* System;
	vector <AchtergrondParticleSystem> AchtergrondSystem;

	// Voor de achtergrondParticle locatie vector
	ofVec2f location_;

	// int, float
	int hoeveelheid;
	int fase_code;
	int kleurverandering;

	// Boolean's 
	bool aanuit = true;
	bool line_bewegen_uit = false;
	bool LegeVectorVullen = false;
	
	// Lettertype
	ofTrueTypeFont  begintekst;

	// Afbeeldingen 
	ofImage monsterR;
	ofImage monsterL;

	// Arduino stuff 
	bool arduino_opstarten;
	bool water_op_sensor = false;
	ofArduino myArduino;
	

private:

	// Arduino functions 
	void setupArduino(const int & version);
	void analogPinChanged(const int & pinNum);
};