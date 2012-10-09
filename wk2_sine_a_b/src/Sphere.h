#pragma once

#include "ofMain.h"
#include "Sphere.h"

class Sphere {
    
public:
    void setup(int x, int y, int z);
    void update();
    void draw();
    
    float xRot, yRot, zRot, xPos, yPos, zPos, currentR, maxR, numParticles, radius;
    float dxRot, dyRot, dzRot;
    
};

