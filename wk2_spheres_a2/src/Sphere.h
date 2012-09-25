#pragma once

#include "ofMain.h"
#include "Sphere.h"

class Sphere {
    
public:
    void setup();
    void update();
    void draw();
    
    float xRot, yRot, zRot, xPos, yPos, zPos, currentR, maxR;
    int numParticles, radius;
    float dxRot, dyRot, dzRot;
    
};

