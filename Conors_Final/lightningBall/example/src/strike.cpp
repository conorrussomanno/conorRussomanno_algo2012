//
//  lightning.cpp
//  ofxThinkGearExample
//
//  Created by Conor Russomanno on 12/18/12.
//
//

#include "strike.h"

//--------------------------------------------------------------
//void strike::setup(float _ballRadius, float _maxDTheta, float _minDTheta, float _maxTheta, float _minBoltWidth, float _maxBoltWidth, float _minJumpLength, float _maxJumpLength, float _splitOdds){
 void strike::setup(float x0I, float y0I, float width0, float theta0, float jumpMin, float jumpMax, float _splitOdds, float _minDTheta, float _maxDTheta, float _maxTheta, int _counter){
     
     
     theta = theta0;
         cout << "theta: " << theta*(180/PI) << endl;
    
     x0 = x0I;
     x1 = x0I;
     x2 = x0I;
     y0 = y0I;
     y1 = y0I;
     y2 = y0I;
    
     lineWidth = width0;
     lineWidth0 = width0;
    
     straightJumpMin = jumpMin;
     straightJumpMax = jumpMax;
     straightJump = ofRandom(straightJumpMin, straightJumpMax);
     
     splitOdds = _splitOdds;
     minDTheta = _minDTheta;
     maxDTheta = _maxDTheta;
     maxTheta = _maxTheta;
     
     counter = _counter + 1;

    
//    line.setClosed(FALSE);
//    line.getSmoothed(50);
//    ofSetLineWidth(5);
//    
//    float i = 0;
//    for (int i = 0; i <10; i++){
//        line.addVertex(i*50+ofRandom(75), i*50+ofRandom(75));
//    }
//    //    line.close(); // close the shape
//    
//    h.setup();
//    l.setup();
    
}

//-------------------------------------------------------------
void strike::update(){
    
}

//--------------------------------------------------------------
void strike::draw(){

    ofPushStyle();
    ofSetColor(255, 255, 255);
    
    while(y2 < ofGetHeight() && y2 > 0 && x2 > 0 && x2 && ofGetWidth() && counter < 3){
        ofSetLineWidth(1);
        
        
        fiftyFifty = ofRandom(1);
        if (fiftyFifty>.5) {
            theta += (-1)*ofRandom(minDTheta, maxDTheta);
        }
        else{
            theta += ofRandom(minDTheta, maxDTheta);
        }
        
        straightJump = ofRandom(straightJumpMin, straightJumpMax);
        x2 = x1 - straightJump*cos(theta);
        y2 = y1 - straightJump*sin(theta);
        
//        lineWidth = ofMap(ofDist(ofGetWidth()/2, ofGetHeight()/2, x2, y2), ofGetWidth()/2, 0, 1, lineWidth0);
        lineWidth = ofMap(counter, 0, 25, lineWidth, 1);
        
        if (lineWidth<0) {
            lineWidth = 0;
        }
        
        ofSetLineWidth(lineWidth);
        ofLine(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        
        if(ofRandom(1)<splitOdds){
            float newTheta = theta;
            fiftyFifty = ofRandom(1);
            if (fiftyFifty>.5) {
                newTheta += (-1)*ofRandom(minDTheta, maxDTheta);
            }
            else{
                newTheta += ofRandom(minDTheta, maxDTheta);
            }
            strike subBolt;
            subBolt.setup(x2, y2, lineWidth, newTheta, straightJumpMin, straightJumpMax, splitOdds, minDTheta, maxDTheta, maxTheta, counter);
            subBolt.draw();
            
        }
        
    }
    
    ofPopStyle();
    
    
    
    
    
    
    
    
    
    //    ofPushStyle();
//    ofSetColor(255);
//    line.draw();
//    ofPopStyle();
//    h.draw();
//    l.draw();
}

//--------------------------------------------------------------
