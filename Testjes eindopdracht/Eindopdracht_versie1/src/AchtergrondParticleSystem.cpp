#include "AchtergrondParticleSystem.h"

AchtergrondParticleSystem::AchtergrondParticleSystem(ofVec2f location_)
{
	origin = location_;
}

void AchtergrondParticleSystem::addParticle()
{
	AchtergrondParticle harry = AchtergrondParticle(origin);
	AchtergrondParticles.push_back(harry);
}

void AchtergrondParticleSystem::run()
{
	// Manier 2 
	int i = 0;
	while (i < AchtergrondParticles.size()) {
		if (AchtergrondParticles[i].isDead() == true) {
			AchtergrondParticles.erase(AchtergrondParticles.begin() + i);
			
		}
		else {
			AchtergrondParticles[i].run();
			i++;
		}
	}
}
