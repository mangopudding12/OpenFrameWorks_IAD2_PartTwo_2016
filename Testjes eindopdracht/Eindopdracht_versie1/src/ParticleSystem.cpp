#include "ParticleSystem.h"

// ------------------------ Constructor ------------------------------ 
ParticleSystem::ParticleSystem(float x2_, float y2_, float r2_)
{
	// Vector aanmaken in het geheugen
	// Dit moet op deze manier omdat we een pionter naar een vector hebben. 
	Moreparticles = new vector<Particle>;

	// Dit stukje code zorgt ervoor dat alle particles samen een vierkant vormen.
	for (int i = 0; i < rows*cols; i++)
	{
		addParticle(x2_ + (i%cols)*r2_, y2_ + (i / rows)*r2_, r2_, i);
	}
}

// ---------------- Creert de particles op de goeie plek -----------------------
void ParticleSystem::addParticle(float x2_, float y2_, float r2_, float k_)
{
	Particle tijdelijke_particle = Particle(x2_, y2_, r2_, k_, Moreparticles);
	Moreparticles->push_back(tijdelijke_particle);
}

// --------------------- Afbeelden van alle particles ------------------------ 
void ParticleSystem::display()
{
	for (int i = 0; i < Moreparticles->size(); i++)
	{
		Moreparticles->at(i).display();
	}
}

// -------------------- Alle particles laten bewegen --------------------------- 
void ParticleSystem::move(Line line_)
{
	if (intact == false)
	{
		// Hier wordt er gereageert op collisions cirkel en line
		for (int i = 0; i < Moreparticles->size(); i++)
		{

			hit = line_.lineCircle(line_.locationpoint1.x, line_.locationpoint1.y,
				line_.locationpoint2.x, line_.locationpoint2.y, Moreparticles->at(i).location.x
				, Moreparticles->at(i).location.y, Moreparticles->at(i).radius);

			Moreparticles->at(i).botsingdetection();
			Moreparticles->at(i).Schermbounds();

			// Collision line cirkel en we activeren de collision function
			if (hit == true && hitactiveren == true)
			{
				// Wanneer je de onderkant van de lijn raakt 
				// Doordat de cirkel een negatieve snelheid heeft 
				if (Moreparticles->at(i).velocity.y < 0)
				{
					if (Moreparticles->at(i).radius < 70)
					{
						Moreparticles->at(i).radius++;
					}

					line_move = true;

					if (Moreparticles->size() > 1)
					{
						Moreparticles->erase(Moreparticles->begin() + i);
					}
				}
			}
			else {
				if (line_.stopmoving == true)
				{
					line_move = false;
				}
			}

			Moreparticles->at(i).move(); // Laat particle bewegen
		}
	}
}

// ------------ Laat het vierkant in allemaal particles uit elkaar vallen ------------------- 
void ParticleSystem::shatter()
{
	for (int i = 0; i < Moreparticles->size(); i++)
	{
		intact = false;
	}
}

// ------------------- verwijder het hele particle system --------------------- 
// wordt niet gebruikt !!! 
//void ParticleSystem::Dead()
//{
//for (int i = 0; i < Moreparticles->size(); i++)
//{
//if (hit == true && line_move == true)
//{
//if (Moreparticles->size() > 10)
//{
//Moreparticles->erase(Moreparticles->begin());
//}
//}
//}
//}