
#include "testApp.h"

//--------------------------------------------------------------
void Sphere::setup(){
    xRot = 0;
    yRot = 0;
    zRot = 0;
    dxRot = .05;
    dyRot = .1;
    dzRot = .2;
    
    xPos = 0;
    yPos = 0;
    zPos = 0;
    
    numParticles = 10;
    currentR = 0;
    maxR = 300;
    
}

//--------------------------------------------------------------
void Sphere::update(){
    
    
	float sinOfTime = sin( ofGetElapsedTimef()/2 ) ;
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, maxR);
    
    currentR = sinOfTimeMapped;
    xRot += dxRot;
    yRot += dyRot;
    zRot += dzRot;    

}

//--------------------------------------------------------------
void Sphere::draw(){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateX(xRot);
    ofRotateY(yRot);
    ofRotateZ(zRot);
    ofSetColor(255, 255, 255);
    for(int i=0; i<numParticles+1; i++){
        ofPushMatrix();
        ofEllipse(currentR*cos((360/numParticles)*i), currentR*sin((360/numParticles)*i), 10, 10); //how could I get these disks to face the camera despite being in their rotated position?
        ofPopMatrix();
    }
    
    
    ofPopMatrix();

}