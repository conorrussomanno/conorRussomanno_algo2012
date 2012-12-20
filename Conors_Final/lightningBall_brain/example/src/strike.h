#pragma once

#ifndef ofxThinkGearExample_strike_h
#define ofxThinkGearExample_strike_h

#include "ofMain.h"
#include "head.h"
#include "limb.h"

class strike {
    
public:
    
//    void setup(float _ballRadius, float _maxDTheta, float _minDTheta, float _maxTheta, float _minBoltWidth, float _maxBoltWidth, float _minJumpLength, float _maxJumpLength, float _splitOdds);
    void strike::setup(float x0I, float y0I, float width0, float theta0, float jumpMin, float jumpMax, float _splitOdds, float _minDTheta, float _maxDTheta, float _maxTheta, int _counter);
    void update();
    void draw();

    
    ofPolyline line;
    head h;
    limb l;
    
    float fiftyFifty;
    
    float lineWidth0, theta, x0, y0, x1, y1, x2, y2, straightJump, straightJumpMax, straightJumpMin, lineWidth, splitOdds, minDTheta, maxDTheta, maxTheta;
    
    ofColor boltColor;
    
    int counter;
};
    

#endif
