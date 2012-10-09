#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:

			
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		float damping;
    
        ofPoint pos;
        ofPoint vel;
        ofPoint frc;   // frc is also know as acceleration (newton says "f=ma")
    

    protected:
    private:
};

#endif // PARTICLE_H
