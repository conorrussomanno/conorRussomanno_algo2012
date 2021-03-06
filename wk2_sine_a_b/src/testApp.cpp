#pragma once

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    
//	ofSetVerticalSync(true);
    ofSetFrameRate(240);
    ofSetBackgroundAuto(false);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    
    mySphere.setup(300,100,0);
    myOtherSphere.setup(700,700,0);

}

//--------------------------------------------------------------
void testApp::update(){
    mySphere.update();
    myOtherSphere.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0,5);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    mySphere.draw();
    myOtherSphere.draw();
    
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

