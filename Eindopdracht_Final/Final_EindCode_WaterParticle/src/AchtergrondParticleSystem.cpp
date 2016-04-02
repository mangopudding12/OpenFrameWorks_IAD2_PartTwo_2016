#include "AchtergrondParticleSytem.h"

// ----------------- Constructor ----------------------------------
AchtergrondParticleSystem::AchtergrondParticleSystem(ofVec2f location_)
{
	origin = location_;
}

// -------------------- Toevoegen AchtergrondParticles -----------------
void AchtergrondParticleSystem::addParticle()
{
	AchtergrondParticle harry = AchtergrondParticle(origin);
	AchtergrondParticles.push_back(harry);
}

// ----------------------- Check of er dingen dood gaan ------------------
void AchtergrondParticleSystem::run()
{
	int i = 0;
	while (i < AchtergrondParticles.size()) 
	{
		if (AchtergrondParticles[i].isDead() == true) 
		{
			AchtergrondParticles.erase(AchtergrondParticles.begin() + i);
		}
		else {
			AchtergrondParticles[i].run();
			i++;
		}
	}
}
