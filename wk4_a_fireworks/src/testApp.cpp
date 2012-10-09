#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    
    pct = 0;
	
	for (int i = 0; i < 400; i++){
		particle myParticle;
		float vx = ofRandom(-4,4);
        float vyT = powf(16-vx*vx, .5);
		float vy = ofRandom(-vyT,vyT);
		myParticle.setInitialCondition(300,300,vx, vy);
		// more interesting with diversity :)
		// uncomment this: 
		//myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
        cout << particles.size() << endl;
	}
    ofEnableAlphaBlending();
    
    shaper = .2;
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
    pct += .01;
    fader = powf(pct, shaper);
    
    if(fader>.999){
        float tempX = ofRandom(100,ofGetWidth()-100);
        float tempY = ofRandom(100,ofGetHeight()-100);
        for (int i = 0; i < particles.size(); i++){
            pct = 0;
            float maxR = ofRandom(10,20);
            float vx = ofRandom(-maxR,maxR);
            float vy = ofRandom(-powf(16-vx*vx, .5),powf(16-vx*vx, .5));
            particles[i].setInitialCondition(tempX, tempY,vx, vy);
        }
        cout << particles.size() << endl;
    }
    
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0, 50);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
	ofSetColor(255,255,255,300-300*fader);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	for (int i = 0; i < particles.size(); i++){
        pct = 0;
        float maxR = ofRandom(10,20);
		float vx = ofRandom(-maxR,maxR);
		float vy = ofRandom(-powf(16-vx*vx, .5),powf(16-vx*vx, .5));
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy);
	}
    cout << particles.size() << endl;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
