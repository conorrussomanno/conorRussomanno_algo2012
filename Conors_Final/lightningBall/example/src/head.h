#pragma once


#ifndef HEAD_H
#define HEAD_H

#include "ofMain.h"

class head {
    
public:
    void setup();
    void update();
    void draw();
    
    ofPolyline line2;
    
};

#endif