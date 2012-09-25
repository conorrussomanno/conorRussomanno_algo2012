#pragma once

#include "ofMain.h"
#include "Sphere.h"
#include <vector>

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
    
        vector<Sphere> spheres; //for some reason when I try to include multiple "spheres" with this vector, it doesn't work. Any ideas?
        float counter; 

};