#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(float x2_, float y2_, float r2_)
{
	for (int i = 0; i < rows*cols; i++)
	{
		addParticle(x2_ + (i%cols)*r2_, y2_ + (i / rows)*r2_, r2_);
	}
}


void ParticleSystem::addParticle(float x2_, float y2_, float r2_)
{
	Partical harry = Partical(x2_, y2_, r2_);
	MoreParticles.push_back(harry);
}

void ParticleSystem::display()
{
	for (int i = 0; i < MoreParticles.size(); i++)
	{
		MoreParticles[i].display();
	}
}

void ParticleSystem::move()
{
	if (intact == false)
	{
		for (int i = 0; i < MoreParticles.size(); i++)
		{
			MoreParticles[i].move(); // Laat particle bewegen 
		}
	}
}

void ParticleSystem::shatter()
{
	for (int i = 0; i < MoreParticles.size(); i++)
	{
		if (ofGetMouseX() >= MoreParticles[i].location.x && ofGetMouseY() >= MoreParticles[i].location.y
			&& ofGetMouseX() <= MoreParticles[i].location.x + MoreParticles[i].radius && ofGetMouseY()
			<= MoreParticles[i].location.y + MoreParticles[i].radius)
		{
			intact = false;
		}
	}
}

void ParticleSystem::Dead()
{
	for (int i = 0; i < MoreParticles.size(); i++)
	{
		if (MoreParticles[i].isDead() == true)
		{
			MoreParticles.erase(MoreParticles.begin() + i);
			cout << "remove all" << endl;
			cout << MoreParticles.size() << endl;

			if (MoreParticles.size() == 0)
			{
				maakNieuwe = true;
			}
		}
	}

}
