//
//  limb.cpp
//  ofxThinkGearExample
//
//  Created by Conor Russomanno on 12/18/12.
//
//

#include "limb.h"

void limb::setup(){
    
    line3.setClosed(FALSE);
    line3.getSmoothed(50);
    ofSetLineWidth(5);
    
    float i = 0;
    for (int i = 0; i <10; i++){
        line3.addVertex(i*50+ofRandom(75), i*50+ofRandom(75));
    }
    //    line.close(); // close the shape
    
}

//--------------------------------------------------------------
void limb::update(){
    
}

//--------------------------------------------------------------
void limb::draw(){
    ofPushStyle();
    ofSetColor(255,0,0);
    line3.draw();
    ofPopStyle();
}

//--------------------------------------------------------------
