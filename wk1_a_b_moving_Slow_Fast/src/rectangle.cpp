#include "rectangle.h"


//------------------------------------------------------------------
rectangle::rectangle(){
  
}

void rectangle::update(){

	pos.x = pos.x + velocity;
    if (pos.x >= ofGetWidth()) {
        pos.x = 0;
    }
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(rectColor);  //198,246,55
    ofRect(pos.x, pos.y, 20,20);
}
