#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // ALL THE TESTING HAPPENED HERE!

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
//	ofSetVerticalSync(true);
    ofSetFrameRate(1024);  //framerate does not affect speed above 1024 (from what I noticed)
	
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	
	fastRectangle.pos.x = 120;
	fastRectangle.pos.y = 40;
    fastRectangle.velocity = 5;  //w/ frameRate set to 1024 I can still percieve motion when velocity (pixel/frame) is set to 5, but not 10
    //when ofSetFrameRate is not turned on and ofSetVerticalSync is true (they are mutually exclusive), I can just barely perceive velocity at a value of 100
    
    slowRectangle.pos.x = 120;
    slowRectangle.pos.y = 80;
    slowRectangle.velocity = .0001; //w/ ofSetVerticalSync, .001 is about as boring as I can tolerate
    //with frameRate to 1024, .0001 is tolerable
	
}

//--------------------------------------------------------------
void testApp::update(){

	fastRectangle.update();
    slowRectangle.update();
	
}



//--------------------------------------------------------------
void testApp::draw(){
	fastRectangle.draw();
    slowRectangle.draw();
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
	// in class we looked at this -- click = new position
	//myRectangle.pos.x = ofRandom(0,ofGetWidth());
	//myRectangle.pos.y =  ofRandom(0,ofGetHeight());
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
