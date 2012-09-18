#include "firework.h"


//------------------------------------------------------------------
firework::firework(int numberOfFlickers, int x, int y){
    
	shaper = .3;
}

//------------------------------------------------------------------
void firework::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, 20,20);
}


//------------------------------------------------------------------
void firework::interpolateByPct(float myPct){
	
	
	// powf (2, 3) = 8
	
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
}