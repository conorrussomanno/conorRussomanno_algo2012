#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class rectangle {

	public:
	
        void setup(int r, int g, int b);
		void draw();
    
		ofPoint		pos;
        ofColor     rectColor;
    

};

#endif // RECTANGLE_H
