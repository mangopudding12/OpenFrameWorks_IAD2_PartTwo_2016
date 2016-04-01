#include "Line.h"

// ----------------- Constructor -----------------------
Line::Line(float x1_, float x2_, float y1_, float y2_)
{
	locationpoint1.set(x1_, y1_);
	locationpoint2.set(x2_, y2_);
	accelaration.set(0, 1);
	ofSetLineWidth(8);
}

// --------------------- Collision detection Line en Cirkels ----------------------
bool Line::lineCircle(float x1, float y1, float x2, float y2, float x_, float y_, float r_)
{
	// is either end INSIDE the circle?
	// if so, return true immediately
	bool inside1 = pointCircle(x1, y1, x_, y_, r_);
	bool inside2 = pointCircle(x2, y2, x_, y_, r_);
	if (inside1 || inside2) return true;


	// get length of the line
	float distX = x1 - x2;
	float distY = y1 - y2;
	float len = sqrt((distX*distX) + (distY*distY));

	// get dot product of the line and circle
	float dot = (((x_ - x1)*(x2 - x1)) + ((y_ - y1)*(y2 - y1))) / pow(len, 2);

	// find the closest point on the line
	float closestX = x1 + (dot * (x2 - x1));
	float closestY = y1 + (dot * (y2 - y1));

	// is this point actually on the line segment?
	// if so keep going, but if not, return false
	bool onSegment = linePoint(x1, y1, x2, y2, closestX, closestY);
	if (!onSegment) return false;

	// optionally, draw a circle at the closest
	// point on the line
	//ofColor(90, 90, 0);
	//ofEllipse(closestX, closestY, 20, 20);

	// get distance to closest point
	distX = closestX - x_;
	distY = closestY - y_;
	float distance = sqrt((distX*distX) + (distY*distY));

	if (distance <= r_)
	{
		return true;
	}
	else {
		return false;
	}
}

// ---------------------- Waar is de Cirkel in verhouding met de line ? -------------
bool Line::pointCircle(float px, float py, float x_, float y_, float r_)
{
	// get distance between the point and circle's center
	// using the Pythagorean Theorem
	float distX = px - x_;
	float distY = py - y_;
	float distance = sqrt((distX*distX) + (distY*distY));

	// if the distance is less than the circle's
	// radius the point is inside!
	if (distance <= r_) {
		return true;
	}
	return false;
}

// ------------------------- Kijk waar de cirkel de line raakt of niet raakt ---------
bool Line::linePoint(float x1, float y1, float x2, float y2, float px, float py)
{
	// get distance from the point to the two ends of the line
	float d1 = ofDist(px, py, x1, y1);
	float d2 = ofDist(px, py, x2, y2);

	// get the length of the line
	float lineLen = ofDist(x1, y1, x2, y2);

	// since floats are so minutely accurate, add
	// a little buffer zone that will give collision
	float buffer = 0.1;    // higher # = less accurate

						   // if the two distances are equal to the line's
						   // length, the point is on the line!
						   // note we use the buffer here to give a range,
						   // rather than one #
	if (d1 + d2 >= lineLen - buffer && d1 + d2 <= lineLen + buffer) {
		return true;
	}
	return false;
}

// ---------------- Afbeelden -----------------------------
void Line::display()
{
	//ofColor(255, 0, 0);
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
	}
	else {
		// Zet stopmoving weer op false zodat wanneer line weer
		// wordt aangeraakt door een cirkel dat er weer een collision ontstaat.
		stopmoving = false;
	}
}