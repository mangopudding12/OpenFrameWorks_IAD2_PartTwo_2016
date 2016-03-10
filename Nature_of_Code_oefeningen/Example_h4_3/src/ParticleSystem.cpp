#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(ofVec2f location_)
{
	origin = location_; 
}

void ParticleSystem::addParticle()
{
	Partical harry = Partical(origin);
	MoreParticles.push_back(harry);
}

void ParticleSystem::run()
{
	// Manier 2 
	int i = 0;
	while (i < MoreParticles.size()) {
		if (MoreParticles[i].isDead() == true) {
			MoreParticles.erase(MoreParticles.begin() + i);
		}
		else {
			MoreParticles[i].run();
			cout << "running" << endl; 
			i++;
		}
	}
}
