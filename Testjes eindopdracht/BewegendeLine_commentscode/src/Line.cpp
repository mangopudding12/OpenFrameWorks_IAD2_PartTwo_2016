#include "Line.h"

// ----------------- Constructor -----------------------
Line::Line(float x1_, float x2_, float y1_, float y2_)
{
	locationpoint1.set(x1_, y1_);
	locationpoint2.set(x2_, y2_);
	accelaration.set(0, 1);
	ofSetLineWidth(8);
}


// ---------------- Afbeelden -----------------------------
void Line::display()
{
	ofColor(200, 100, 60);
	ofLine(locationpoint1.x, locationpoint1.y, locationpoint2.x, locationpoint2.y);
}

// -------------------------- Move Function ----------------------------------- 
void Line::move(bool bewegenaan)
{
	if (bewegenaan == true)
	{
		locationpoint1 += accelaration;
		locationpoint2 += accelaration;

		if (locationpoint1.y >= ofGetHeight())
		{
			// Stopmoving op true zorgt ervoor dat de line ophoud met bewegen. 
			stopmoving = true;
			locationpoint1.y = 400;
			locationpoint2.y = 400;
		}
	} else {
		// Zet stopmoving weer op false zodat wanneer line weer
		// wordt aangeraakt door een cirkel dat er weer een collision ontstaat.
		stopmoving = false;
	}
}