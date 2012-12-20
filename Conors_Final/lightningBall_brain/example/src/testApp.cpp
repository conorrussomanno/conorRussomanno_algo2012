

#include "testApp.h"

void testApp::setup()////////////////////////////////////////////////////////////////////
{
//    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetFullscreen(TRUE);
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofSetBackgroundAuto(FALSE);
    

    
//--------------------THINKGEAR/SETUP----------------//
    
    thinkGear.setup("/dev/tty.MindSet-DevB");
    ofAddListener(thinkGear.attentionChangeEvent, this, &testApp::attentionListener);
    ofAddListener(thinkGear.meditationChangeEvent, this, &testApp::meditationListener);
    ofAddListener(thinkGear.deltaChangeEvent, this, &testApp::deltaListener);
    
    font.loadFont("font/DroidSansMono.ttf", 20);
    
    distAw = 0.0;
    prevAw = 0.0;
    currAw = 0.0;
    distMw = 0.0;
    prevMw = 0.0;
    currMw = 0.0;
    distDw = 0.0; //
    prevDw = 0.0; //
    currDw = 0.0; //
    
    atChangeTime = 0.0;
    attention = 0.0;
    meChangeTime = 0.0;
    meditation = 0.0;
    deChangeTime = 0.0;
    delta = 0.0;
    
    //-----------
    
    mode = 0;
    graph = false;
    brainSYNC = false;
    
    
///-------------------LIGHTNING/SETUP----------------///
    
    ballRadius = 90;
    
    maxDTheta = PI/10;
    minDTheta = PI/20;
    maxTheta = PI/2;
    
    minBoltWidth = 50;
    maxBoltWidth = 150;
    minJumpLength = 3;
    maxJumpLength =12;
    
    
    lastStrike = 0;
    nextStrike = 0;
    
    maxTimeBetweenBolts = 30;
    
    splitOdds = .009;
    
    timeForBolt = false;
    
    fade = true;
    
}

void testApp::update()///////////////////////////////////////////////////////////////////
{
    //--------------------THINKGEAR/UPDATE----------------//
    thinkGear.update();
    
    float cur = ofGetElapsedTimef();
    float progress = cur - atChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevAw = currAw;
    currAw = ofxTweenLite::tween(prevAw, distAw, progress, OF_EASE_SINE_INOUT);
    
    progress = cur - meChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevMw = currMw;
    currMw = ofxTweenLite::tween(prevMw, distMw, progress, OF_EASE_SINE_INOUT);
    
    // ------- ADDED ----------
    progress = cur - deChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevMw = currMw;
    currDw = ofxTweenLite::tween(prevDw, distDw, progress, OF_EASE_SINE_INOUT);
    
    //----------END OF ADDED
    
    ///-------------------LIGHTNING/UPDATE----------------///
    
    currentAttAvg = calcAvgAtt(1);
    if(brainSYNC==true){
        maxTimeBetweenBolts = 3000-(2990)*(currentAttAvg/100);
    }
    else{
        maxTimeBetweenBolts = 30;
    }
    
    cout << "maxTimeBetweenBolts: " << maxTimeBetweenBolts << endl;
    
    if(ofGetElapsedTimeMillis()-lastStrike>nextStrike){
        lastStrike = ofGetElapsedTimeMillis();
        nextStrike = ofRandom(maxTimeBetweenBolts);
        timeForBolt=true;  
    }
}

void testApp::draw()//////////////////////////////////////////////////////////////////////
{

//--------------------THINKGEAR/UPDATE----------------//
    
//    ofBackgroundGradient(ofColor::white, ofColor::gray);
        
    ofPushStyle();
    ofSetColor(ofColor::black);
//    string qStr = "";
    if (thinkGear.getSignalQuality() == 0.0)
    {
//        qStr = "good";
        ofPushStyle();
        ofSetColor(0, 255, 0);
        ofEllipse(25, ofGetScreenHeight()-25, 10, 10);
        ofPopStyle();
    }
    else 
    {
//        qStr = "poor (" + ofToString(thinkGear.getSignalQuality()) + ")";
        ofPushStyle();
        ofSetColor(255, 0, 0);
        ofEllipse(25, ofGetScreenHeight()-25, 10, 10);
        ofPopStyle();
    }
//    font.drawString("signal quality = " + qStr, 10, 40);
    ofPopStyle();
    
    ofSetWindowTitle("fps = " + ofToString(ofGetFrameRate()));
    
//    ofPushMatrix();
////    ofTranslate(0, 30);
//    ofPushStyle();
//    ofSetColor(ofColor::white);
//    font.drawString("Attention", 10, ofGetHeight()/4 - 10);
//    ofNoFill();
//    ofRect(1, ofGetHeight()-100, ofGetWidth() - 2, 60);
//    ofSetColor(ofColor::magenta, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-100, currAw, 59);
//    if (attention > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(attention), 10, ofGetHeight()/4 + 40);
//    }
//    ofPopStyle();
//    ofPopMatrix();

//    ofPushMatrix();
//    ofTranslate(0, 0);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Meditation", 10, ofGetHeight()-(ofGetHeight()/2) - 10);
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/2), ofGetWidth() - 2, 60);
//    ofSetColor(ofColor::cyan, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/2), currMw, 59);
//    if (meditation > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(meditation), 10, ofGetHeight()-(ofGetHeight()/2) + 40);
//    }
//    ofPopStyle();
//    ofPopMatrix();
    
//-----------DELTA ADDED----------//
//    ofPushMatrix();
//    ofTranslate(0, -30);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Delta", 10, ofGetHeight()-(ofGetHeight()/4) - 10);
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/4), ofGetWidth() - 2, 60);
//    ofSetColor(ofColor::cyan, ofMap(currDw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/4), currDw, 59);
//    if (delta > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currDw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(delta), 10, ofGetHeight()-(ofGetHeight()/4) + 40);
//    }
//    ofPopStyle();
//    ofPopMatrix();
    
    //--------------END OF DELTA-------------//
    
//--------------------LIGHTNING/DRAW----------------//
    
    if(fade==true){
        ofPushStyle();
        ofSetColor(0, 0, 0, 50);
        ofRect(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
        ofPopStyle();
    }
    
    
    if(timeForBolt==true){
        lightningBolt();
    }
    
    ofPushStyle();
    ofSetColor(255, 255, 255, 20);
    ofEllipse(ofGetWidth()/2, ofGetHeight()/2, ballRadius*2, ballRadius*2);
    ofPopStyle();
    
    ofPushStyle();
    for(int i = 0; i < 10; i++){
        ofSetColor(255, 255, 255, 40-4*i);
        ofSetLineWidth(2);
        ofPolyline polyLine;
        polyLine.arc(ofGetWidth()/2, ofGetHeight()/2,2+ballRadius+(i*2),2+ballRadius+i*2,0+i,360+i,40);
        polyLine.draw();
        
    }
    ofPopStyle();
    
    if(graph==true){
        drawAttentionGraph();
    }
}

void testApp::lightningBolt(){
    
//    cout << "BOLT" << endl;

    vx = ofRandom(-ballRadius,ballRadius);
    temp = powf((ballRadius*ballRadius)-vx*vx, 0.5);
    temp = ofRandom(-temp,temp);
    fiftyFifty = ofRandom(1);
    if (fiftyFifty>.5) {
        vy = temp;
        
    }
    else{
        vy = -temp;
    }
    
    if(vx<0){
        tempTheta = tan(vy/vx);
    }
    else{
        tempTheta = tan(vy/vx);
    }
//    cout << "tempTheta: " << tempTheta << endl;
//    
//    cout << "vx: " << vx << endl;
//    cout << "vy: " << vy << endl;
    
    ofPushStyle();
    for(int i = 0; i < 10; i++){
        ofSetColor(255, 255, 255, 100-10*i);
        ofEllipse(ofGetWidth()/2+vx, ofGetHeight()/2+vy, 10+i*6, 10+i*6);
    }
    ofPopStyle();
    
    bolt.setup(ofGetWidth()/2+vx, ofGetHeight()/2+vy, ofRandom(minBoltWidth,maxBoltWidth), tempTheta, minJumpLength, maxJumpLength, splitOdds, minDTheta, maxDTheta, maxTheta, 0);
    bolt.draw();

    timeForBolt = false;
}

void testApp::attentionListener(float &param)
{
    attention = param;
    attValues.push_back(attention);
    distAw = ofMap(attention, 0.0, 100.0, 0, ofGetWidth());
    atChangeTime = ofGetElapsedTimef();
}

void testApp::meditationListener(float &param)
{
    meditation = param;
    distMw = ofMap(meditation, 0.0, 100.0, 0, ofGetWidth());
    meChangeTime = ofGetElapsedTimef();    
}

void testApp::deltaListener(float &param)
{
    delta = param;
    distDw = ofMap(delta, 0.0, 100.0, 0, ofGetWidth());
    deChangeTime = ofGetElapsedTimef();
}

float testApp::calcAvgAtt(int numPackets){
    
    
    currentAvg = 0;
    
    for (int i = attValues.size()-numPackets; i<attValues.size(); i++) {
        currentAvg += attValues[i];
    }
    currentAvg = currentAvg/numPackets;
    
    cout << "currentAvg: " << currentAvg << endl;
    return currentAvg;
}

void testApp::drawAttentionGraph()
{
    ofPushStyle();
    ofSetColor(123, 123, 123);
    ofLine(50, (3/4)*ofGetScreenHeight(), ofGetScreenWidth()-50, (3/4)*ofGetScreenHeight());
    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(0, 30);
    ofPushStyle();
    ofSetColor(ofColor::white);
    font.drawString("Attention", 10, ofGetHeight()-100 - 10);
    ofNoFill();
    ofRect(1, ofGetHeight()-100, ofGetWidth() - 2, 60);
    ofSetColor(ofColor::magenta, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
    ofFill();
    ofRect(0, ofGetHeight()-100, currAw, 59);
    if (attention > 0.0)
    {
        ofSetColor(ofColor::black, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
        font.drawString(ofToString(attention), 10, ofGetHeight()-100 + 40);
    }
    ofPopStyle();
    ofPopMatrix();
    
    ofPushStyle();
    ofSetColor(ofColor::white);
    string qStr = "";
    
    if (thinkGear.getSignalQuality() == 0.0)
    {
        qStr = "good";
        ofPushStyle();
        ofSetColor(0, 255, 0);
//        ofEllipse(25, ofGetScreenHeight()-25, 10, 10);
        ofPopStyle();
    }
    else
    {
        qStr = "poor (" + ofToString(thinkGear.getSignalQuality()) + ")";
        ofPushStyle();
        ofSetColor(255, 0, 0);
//        ofEllipse(25, ofGetScreenHeight()-25, 10, 10);
        ofPopStyle();
    }
    
//    float firstHalf = 0;
//    float secondHalf = 0;
//    
//    //------------- CALCULATE first/second AVG
//    
//    for(int i = 0; i < (int)attValues.size()/2; i++){
//        firstHalf+=attValues[i];
//    }
//    firstHalf=firstHalf/(attValues.size()/2);
////    cout << "firstHalf: " << firstHalf << endl;
//    
//    
//    for(int i = (int)attValues.size()/2; i < attValues.size(); i++){
//        secondHalf+=attValues[i];
//    }
//    secondHalf=secondHalf/(attValues.size()/2);
////    cout << "secondHalf: " << secondHalf << endl;
    
    
    //------------
    
    font.drawString("Signal Quality = " + qStr, 10, 40);
    font.drawString("Avg Attention (Previous 5 Seconds) = " + ofToString(calcAvgAtt(5)), 10, 80);
//    font.drawString("Attention AVG 2nd Half: " + ofToString(secondHalf), 10, 120);
    ofPopStyle();
    
    if(attValues.size()>0){
        for (int i = 0; i < attValues.size()-1; i++) {
            ofPushStyle();
            ofSetColor(0, 255, 0);
            ofEllipse(ofMap(i, 0, attValues.size(), 50, ofGetScreenWidth()-50), (3/4)*ofGetScreenHeight()-attValues[i]*2, 5, 5);
            ofSetLineWidth(5);
            ofLine(ofMap(i, 0, attValues.size(), 50, ofGetScreenWidth()-50), (3/4)*ofGetScreenHeight()-attValues[i]*2, ofMap(i+1, 0, attValues.size(), 50, ofGetScreenWidth()-50), (3/4)*ofGetScreenHeight()-attValues[i+1]*2);
            ofEllipse(ofMap(i+1, 0, attValues.size(), 50, ofGetScreenWidth()-50), (3/4)*ofGetScreenHeight()-attValues[i+1]*2, 5, 5);
            ofPopStyle();
        }
    }
}


void testApp::keyPressed(int key)
{
    if(key=='b'){
        mode--;
        cout<< "mode: " << mode << endl;
    }
    if(key=='g'){
        graph = !graph;
    }
    if(key=='b'){
        brainSYNC = !brainSYNC;
    }
}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button)
{
    lightningBolt();

}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}