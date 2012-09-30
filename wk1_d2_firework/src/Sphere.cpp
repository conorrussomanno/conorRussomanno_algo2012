
#include "testApp.h"

//--------------------------------------------------------------
void Sphere::setup(){
    xRot = .1;
    yRot = .3;
    zRot = .2;
    dxRot = .05;
    dyRot = .1;
    dzRot = .2;
    
    xPos = ofRandom(100, ofGetWidth()-100);;
    yPos = ofRandom(100, ofGetHeight()-100);;
    zPos = 0;
    
    color.r = ofRandom(255);
    color.g = ofRandom(255);
    color.b = ofRandom(255);
    
    numParticles = 20;
    theta = 360.0/numParticles;
    cout << theta << endl;
    innerR = 0;
    outerR = ofRandom(300, 600);
    radius = 5;
    
    yVel = 0;
    yAcc = .004;
    
    shaper = .2;
    
}

//--------------------------------------------------------------
void Sphere::update(float myPct){
    
    // powf (2, 3) = 8
	
	pct = powf(myPct, shaper);
    
    currentR = ((1-pct) * innerR + (pct) * outerR)/2;
    
    yVel += yAcc;
    yPos += yVel;
    
//    xRot += dxRot;
//    yRot += dyRot;
//    zRot += dzRot;    

}

//--------------------------------------------------------------
void Sphere::draw(){
    
    ofPushStyle();
    ofSetColor(color, 255 - (255*pct));
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofRotateX(xRot);
    ofRotateY(yRot);
    ofRotateZ(zRot);
    for (int j = 0; j<numParticles; j++){
        ofPushMatrix();
        ofRotateY(theta*j);
        for(int i=0; i<numParticles; i++){
            //ofTranslate(currentR*cos((360/numParticles)*i), currentR*sin((360/numParticles)*i));
            ofEllipse(currentR*cos((theta*i)*(PI/180)), currentR*sin((theta*i)*(PI/180)), radius, radius); //how could I get these disks to face the camera despite being in their rotated position?
            //ofRect(currentR*cos((theta*i)*(PI/180)), currentR*sin((theta*i)*(PI/180)), radius, radius);
//          cout << << endl;
        }
        ofPopMatrix();
    }   
    
    ofPopMatrix();
    ofPopStyle();

}
	
