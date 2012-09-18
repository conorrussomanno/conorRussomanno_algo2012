#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:
	
		rectangle();
	
		void update();
		void draw();
	
		ofPoint pos;
        float velocity;
        ofColor rectColor;
	

};

#endif // RECTANGLE_H
