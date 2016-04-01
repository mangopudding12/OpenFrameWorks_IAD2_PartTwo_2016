#include "Line_Versiering.h"

// ----------------- Constructor -----------------------
Line_Versiering::Line_Versiering(float x1_, float x2_, float y1_, float y2_)
{
	locationpoint1.set(x1_, y1_);
	locationpoint2.set(x2_, y2_);
	accelaration.set(0, 1);
	ofSetLineWidth(8);
}


// ---------------- Afbeelden -----------------------------
void Line_Versiering::display()
{
	ofColor(200, 100, 60);
	ofLine(locationpoint1.x, locationpoint1.y, locationpoint2.x, locationpoint2.y);
}
