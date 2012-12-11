#include "spring.h"

//---------------------------------------------------------------------
spring::spring(){
	particleA = NULL;
	particleB = NULL;
}

//---------------------------------------------------------------------
void spring::update(){
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
	
	ofVec2f pta = particleA->pos;
	ofVec2f ptb = particleB->pos;
	
	float theirDistance = (pta - ptb).length();
	float springForce = (springiness * (distance - theirDistance));
	ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;
	
    if(theirDistance>distance){
        particleA->addForce(frcToAdd.x, frcToAdd.y);
        particleB->addForce(-frcToAdd.x, -frcToAdd.y);
    }
}


//---------------------------------------------------------------------
void spring::draw(){
	
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
    float tempGray = ofRandom(255);
    int randoRange = 3;
	ofSetColor(tempGray, tempGray, tempGray);
    ofLine((particleA->pos.x)+ofRandom(-randoRange,randoRange), particleA->pos.y+ofRandom(-randoRange,randoRange), particleB->pos.x+ofRandom(-randoRange,randoRange), particleB->pos.y+ofRandom(-randoRange,randoRange));
    
    
    tempGray = ofRandom(255);
    ofSetColor(tempGray, tempGray, tempGray);
    ofLine((particleA->pos.x)+ofRandom(-randoRange,randoRange), particleA->pos.y+ofRandom(-randoRange,randoRange), particleB->pos.x+ofRandom(-randoRange,randoRange), particleB->pos.y+ofRandom(-randoRange,randoRange));
    
    
    tempGray = ofRandom(255);
    ofSetColor(tempGray, tempGray, tempGray);
    ofLine((particleA->pos.x)+ofRandom(-randoRange,randoRange), particleA->pos.y+ofRandom(-randoRange,randoRange), particleB->pos.x+ofRandom(-randoRange,randoRange), particleB->pos.y+ofRandom(-randoRange,randoRange));
    
//    float tempGray = ofRandom(255);
//    ofSetColor(tempGray, tempGray, tempGray);
//    ofLine((particleA->pos.x)+4, particleA->pos.y-3, particleB->pos.x+1, particleB->pos.y-7);
//    
//    
//    tempGray = ofRandom(255);
//    ofSetColor(tempGray, tempGray, tempGray);
//    ofLine((particleA->pos.x)-1, particleA->pos.y-4, particleB->pos.x+ofRandom(-8,8)+5, particleB->pos.y-7);
//    
//    
//    tempGray = ofRandom(255);
//    ofSetColor(tempGray, tempGray, tempGray);
//    ofLine((particleA->pos.x)+4, particleA->pos.y-2, particleB->pos.x+6, particleB->pos.y);
}