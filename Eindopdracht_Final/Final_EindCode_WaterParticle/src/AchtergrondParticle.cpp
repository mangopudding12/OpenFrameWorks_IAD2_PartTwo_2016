#include "AchtergrondParticle.h"

// --------------------- Constructor ---------------------------
AchtergrondParticle::AchtergrondParticle(ofVec2f location_)
{
	// Varible een waarde geven
	accelaration.set(0, 0.05);
	velocity.set(ofRandom(-1, 1), ofRandom(-2, 0));
	location = location_;
	lifespan = 255.0;
	radius = 12;
	anderekleur = 0;
}

// ------------------------- Voer move, display uit --------------
void AchtergrondParticle::run()
{
	move();
	display();
}

// ------------------ Beweeg achtergrond Particles -----------------
void AchtergrondParticle::move()
{
	velocity += accelaration;
	location += velocity;
	lifespan -= 2;

}

// ---------------- AchtergrondParticle Afbeelden ---------------------
void AchtergrondParticle::display()
{
	ofSetColor(360 - location.y, (lifespan + location.y) - 150, (location.x - 100) + anderekleur, lifespan);
	ofFill();

	ofEllipse(location.x, location.y, radius, radius);
}

// ----------------------- Wanneer AchtergrondParticle dood is ------------
bool AchtergrondParticle::isDead()
{
	if (lifespan < 0.0)
	{
		return true;
	}
	else {
		return false;
	}
}
