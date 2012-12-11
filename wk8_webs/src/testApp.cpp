#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
//    ofSetBackgroundAuto(false);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    mode = 0;
    
//    myWeb.setInitialCondition();

//	for (int i = 0; i < 10; i++){
//		particle myParticle;
//		myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
//		particles.push_back(myParticle);
//	}
//	
//	for (int i = 0; i < (particles.size()-1); i++){
//		spring mySpring;
//		mySpring.distance		= 25;
//		mySpring.springiness	= 0.4f;
//		mySpring.particleA = & (particles[i]);
//		mySpring.particleB = & (particles[(i+1)%particles.size()]);
//		springs.push_back(mySpring);
//	}
	
	//particles[particles.size()-1].bFixed = true;
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].resetForce();
//	}
//	
//	
//	for (int i = 0; i < particles.size(); i++){
//		//particles[i].addForce(0,0.1);
//	}
//
//	
//	for (int i = 0; i < springs.size(); i++){
//		springs[i].update();
//	}
//	
//	
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].addDampingForce();
//		particles[i].update();
//	}
//
//	trail.push_back(particles[3].pos);
//	if (trail.size() > 150){
//		trail.erase(trail.begin());	
//	}
    for(int i = 0; i < webs.size(); i++){
        webs[i].update();
    }
    
    if(stretchWeb==true){
        webs[0].stretchWeb(mouseX, mouseY);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofSetColor(255);
    for(int i = 0; i < webs.size(); i++){
        webs[i].draw();
    }

//	ofSetColor(0xffffff);
	
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].draw();
//	}
//	
//	for (int i = 0; i < springs.size(); i++){
//		springs[i].draw();
//	}
//	
//	ofNoFill();
//	ofBeginShape();
//	for (int i = 0; i < trail.size(); i++){
//		ofVertex(trail[i].x, trail[i].y);
//	}
//	ofEndShape();
    ofSetColor(0,130,130, 200);
	ofRect(10,10,275,70);
	ofSetColor(255,255,255);
	ofDrawBitmapString("space to clear\ntoggle mode 'm'", 30, 30);
	
	
	ofSetColor(255,255,130);
	switch (mode){
		case 0: ofDrawBitmapString("drawing mode: place web", 30, 60);
			break;
		case 1: ofDrawBitmapString("drawing mode: mess with web!", 30, 60);
			break;
//		case 2: ofDrawBitmapString("drawing mode: clockwise", 30, 130);
//			break;
//		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 30, 130);
//			break;
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
//			// reposition everything: 
//			for (int i = 0; i < particles.size(); i++){
//				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
//			}
            for(int i = 0; i<webs.size(); i++){
                webs.erase(webs.begin());
            }

			break;
            
        case 'm':
            if(mode<1){
                mode++;
            }
            else{
                mode=0;
            }
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
//	particles[0].pos.set(mouseX, mouseY);
//    if(mode==1){
//        webs[0].stretchWeb(x, y);
//    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if(mode==0){
        web myWeb;
        myWeb.setInitialCondition(x, y);
        webs.push_back(myWeb);
    }
    if(mode==1){
//        webs[0].stretchWeb(x, y);
        stretchWeb=true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
//	particles[0].bFixed = false;
    stretchWeb=false;
}

