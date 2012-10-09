#pragma once

#include "ofMain.h"
#include "Sphere.h"

class Sphere {
    
public:
    void setup();
    void update(float myPct);
    void draw();
    
    float xRot, yRot, zRot, xPos, yPos, zPos, currentR, innerR, outerR, numParticles, radius;
    float dxRot, dyRot, dzRot, theta;
    float		pct;	// what pct are we between "inner" and "outer"
    float		shaper;
    ofColor color;
    float yVel, yAcc;
    
    
};

