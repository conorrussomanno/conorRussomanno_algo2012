#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
	
	for (int i = 0; i < 200; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	//VF.randomizeField(2.0);
	
	drawingStyle = 0;
	bFade = false;
    
    bRepel		= true;
	radius		= 40;
	strength	= 0.5f;
    pulseFrequency  = 5;
    pulseDiameterRange = 10;
    pulse = .5;
    
    colorMode = 0; //0 = red/orange, 1 = turqoise, 2 = something else
    boolAttract = true;
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    pulse = sin(ofGetElapsedTimef()*pulseFrequency)/pulseDiameterRange + 1;
    cout << pulse << endl;
    ;
    
    
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i].addRepulsionForce(mouseX, mouseY, 200, 1.4);
		
        if (boolAttract == true) {
        
            for (int j = 0; j < i; j++){
                particles[i].addRepulsionForce(particles[j], 50*pulse, 0.4);
                particles[i].addAttractionForce(particles[j], 500, 0.005);
            }
        }
        
	}
	
	for (int i = 0; i < particles.size(); i++){
        // get the force from the vector field:
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
        particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].update();
        particles[i].bounceOffWalls();
	}
	
	if (bFade == true) VF.fadeField(0.99f);

}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofSetColor(0,0,0, 20);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
//    
//	ofEnableAlphaBlending();
//	ofSetColor(0,130,130, 200);
//	VF.draw();
	
	for (int i = 0; i < particles.size(); i++){
        float proximityCount = 0;
        for (int j = 0; j < particles.size(); j++){
            if(ofDist(particles[i].pos.x, particles[i].pos.y, particles[j].pos.x, particles[j].pos.y) < 100){
                proximityCount++;
            }
        }
		particles[i].draw(proximityCount, colorMode);
	}
    
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].draw();
//	}
	
	ofSetColor(0,130,130, 200);
	ofRect(10,10,275,150);
	ofSetColor(255,255,255);
	ofDrawBitmapString("space to clear\ntoggle fade 'f'\ntoggle creature color 'c'\ntoggle particle attraction 'b'\nchange drawing mode 'a'", 30, 30);
	
	
	ofSetColor(255,255,130);
	switch (drawingStyle){
		case 0: ofDrawBitmapString("drawing mode: inward", 30, 130);
			break;
		case 1: ofDrawBitmapString("drawing mode: outward", 30, 130);
			break;
		case 2: ofDrawBitmapString("drawing mode: clockwise", 30, 130);
			break;
		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 30, 130);
			break;
	}	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 4;
	} else if (key == 'f'){
		bFade = !bFade;
	} else if (key == 'c'){
        if (colorMode<5) {
            colorMode++;
        }
        else {
            colorMode = 0;
        }
	} else if (key == 'b'){
		boolAttract = !boolAttract;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if (button == 0) {
		switch (drawingStyle){
			case 0: VF.addInwardCircle((float)x, (float)y, 200, 0.3f);
				break;
			case 1: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 2: VF.addClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
		}		
	} else {
		
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
		
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
