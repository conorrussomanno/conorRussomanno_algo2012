#ifndef FIREWORK_H
#define FIREWORK_H

#include "ofMain.h"

class firework {

	public:
	
        firework(int numberOfFlickers, int x, int y);
	
		void draw();
		void interpolateByPct(float myPct);
		
		ofPoint		pos;
		ofPoint     posa; //want this to be an array of size numberOfFlickers
        ofPoint     posb; //same as above
		float		pct;	// what pct are we between "a" and "b"
		float		shaper;
	
	

};

#endif // RECTANGLE_H
