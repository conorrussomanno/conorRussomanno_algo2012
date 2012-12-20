
#include "head.h"
#include "ofMain.h"

//--------------------------------------------------------------
void head::setup(){
    
    line2.setClosed(FALSE);
    line2.getSmoothed(50);
    ofSetLineWidth(5);
    
    float i = 0;
    for (int i = 0; i <10; i++){
        line2.addVertex(i*50+ofRandom(75), i*50+ofRandom(75));
    }
    //    line.close(); // close the shape
    
}

//--------------------------------------------------------------
void head::update(){
    
}

//--------------------------------------------------------------
void head::draw(){
    ofPushStyle();
    ofSetColor(0,0,255);
    line2.draw();
    ofPopStyle();
}

//--------------------------------------------------------------
