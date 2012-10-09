
#include "testApp.h"

//--------------------------------------------------------------
void Sphere::setup(int x, int y , int z){
    xRot = 0;
    yRot = 0;
    zRot = 0;
    dxRot = ofRandom(-.1,.1);
    dyRot = ofRandom(-.1,.1);
    dzRot = ofRandom(-.1,.1);
    
    xPos = x;
    yPos = y;
    zPos = z;
    
    numParticles = (int)ofRandom(10,20);
    currentR = 0;
    maxR = 300;
    radius = 10;
    
}

//--------------------------------------------------------------
void Sphere::update(){
    
    
	float sinOfTime = sin( ofGetElapsedTimef()/2 ) ;
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, maxR);
    
    currentR = sinOfTimeMapped;
    radius = 10;
    xRot += dxRot;
    yRot += dyRot;
    zRot += dzRot;    

}

//--------------------------------------------------------------
void Sphere::draw(){
    
    ofPushMatrix();
    ofTranslate(xPos, yPos, zPos);
    ofRotateX(xRot);
    ofRotateY(yRot);
    ofRotateZ(zRot);
    ofSetColor(255, 255, 255);
    for(int i=0; i<numParticles+1; i++){
        ofPushMatrix();
        ofTranslate(currentR*cos((360/numParticles)*i), currentR*sin((360/numParticles)*(PI/180)*i));
        ofRotateX(-xRot);
        ofRotateY(-yRot);
        ofRotateZ(-zRot);
        ofEllipse(0, 0, radius, radius); //how could I get these disks to face the camera despite being in their rotated position?
        ofPopMatrix();
    }
    
    
    ofPopMatrix();

}