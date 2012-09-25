
#include "testApp.h"

//--------------------------------------------------------------
void Sphere::setup(){
    xRot = 0;
    yRot = 0;
    zRot = 0;
    dxRot = ofRandom(-.2,.2);
    dyRot = ofRandom(-.2,.2);
    dzRot = ofRandom(-.2,.2);
    
    xPos = ofRandom(100,ofGetWidth()-100);
    yPos = ofRandom(100,ofGetHeight()-100);
    zPos = 0;
    
    numParticles =(int)ofRandom(15);
    radius = (int)ofRandom(2,20);
    currentR = 0;
    maxR = ofRandom(100,300);
    
}

//--------------------------------------------------------------
void Sphere::update(){
    
    
	float sinOfTime = sin( ofGetElapsedTimef()/2 ) ;
    cout << (ofGetElapsedTimef()) << endl;
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