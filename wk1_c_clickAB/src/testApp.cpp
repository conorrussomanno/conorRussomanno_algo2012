#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
    flipper = 0;
    myRectangle.setup(198,246,55);
    myOtherRectangle.setup(246,55,198);
    moved = false;
						// a variable we can alter...
} 

//--------------------------------------------------------------
void testApp::update(){
    moved = false;
}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
    myOtherRectangle.draw();
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
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    if(flipper==0 && moved==false){
        myRectangle.pos.x = mouseX;
        myRectangle.pos.y = mouseY;
        moved = true;
        flipper=1;
    }
    if(flipper==1 && moved == false){
        myOtherRectangle.pos.x = mouseX;
        myOtherRectangle.pos.y = mouseY;
        moved = true;
        flipper=0;
    }
}
