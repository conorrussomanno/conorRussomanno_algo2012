#pragma once

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    
	ofSetVerticalSync(true);
//    ofSetFrameRate(120);
    ofSetBackgroundAuto(false);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    
    counter = 0;
    
    for (int i = 0; i < 2; i++) {
        Sphere s;
        s.setup();
        spheres.push_back(s);
    }

}

//--------------------------------------------------------------
void testApp::update(){

//    if (counter-ofGetElapsedTimef()>=200) {
//        counter = 0;
//    }
    for (int i = 0; i < 10; i++) {
        spheres[i].update();
    }
//    counter++;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0,5);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    for (int i = 0; i < 10; i++) {
        spheres[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

