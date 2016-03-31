#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(float x2_, float y2_, float r2_)
{
	// Vector aanmaken 
	Moreparticles = new vector<Partical>;

	for (int i = 0; i < rows*cols; i++)
	{
		addParticle(x2_ + (i%cols)*r2_, y2_ + (i / rows)*r2_, r2_,i);
	}
}


void ParticleSystem::addParticle(float x2_, float y2_, float r2_,float k_)
{
		Partical tijdelijk = Partical(x2_, y2_, r2_, k_, Moreparticles);
		Moreparticles->push_back(tijdelijk);
}

void ParticleSystem::display()
{
	for (int i = 0; i < Moreparticles->size(); i++)
	{
		Moreparticles->at(i).display();
	}
}

void ParticleSystem::move(Line linee)
{
	if (intact == false)
	{
		for (int i = 0; i < Moreparticles->size(); i++)
		{

			hit = linee.lineCircle(linee.locationpoint1.x, linee.locationpoint1.y,
				linee.locationpoint2.x, linee.locationpoint2.y, Moreparticles->at(i).location.x
				, Moreparticles->at(i).location.y, Moreparticles->at(i).radius);

			Moreparticles->at(i).botsingdetection();
			Moreparticles->at(i).Schermbounds();

			// Collision line cirkel 
			if (hit == true)
			{
				if (Moreparticles->at(i).velocity.y < 0)
				{
					if (Moreparticles->at(i).radius < 70)
					{
						Moreparticles->at(i).radius++;
					}
					LineMove = true;

					
					if (Moreparticles->size() > 10)
					{
							Moreparticles->erase(Moreparticles->begin()+i);
					}
				}
			}else {
					if (linee.stopmoving == true)
					{
						LineMove = false;
						linee.stopmoving = false;
					}
			}

			Moreparticles->at(i).move(); // Laat particle bewegen
		}
	}
}

void ParticleSystem::shatter()
{
	for (int i = 0; i < Moreparticles->size(); i++)
	{
		intact = false;
	}
}

void ParticleSystem::Dead()
{
	for (int i = 0; i < Moreparticles->size(); i++)
	{
		if (hit == true && LineMove == true)
		{
			if (Moreparticles->size() > 10)
			{
				Moreparticles->erase(Moreparticles->begin());
			}
		}
	}
}