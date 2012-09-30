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
    
    mySphere.setup();
    mainPct = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    mainPct += 0.01f;
    if (mainPct > 1.5){
        mySphere.xPos = ofRandom(100, ofGetWidth()-100);
        mySphere.yPos = ofRandom(100, ofGetHeight()-100);
        mySphere.color.r = ofRandom(255);
        mySphere.color.g = ofRandom(255);
        mySphere.color.b = ofRandom(255);
        mySphere.yVel = 0;
        mySphere.outerR = ofRandom(300, 600);
        mainPct = 0;
    }
    mySphere.update(mainPct);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0,25);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    mySphere.draw();
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

