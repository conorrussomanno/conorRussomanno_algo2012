
#ifndef TEST_APP
#define TEST_APP

#include "ofMain.h"
#include "ofxThinkGear.h"
#include "ofxTweenLite.h"
#include "strike.h"
#include "head.h"
#include "limb.h"

class testApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void lightningBolt();
    void drawAttentionGraph();
    float calcAvgAtt(int numPackets);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    ofxThinkGear thinkGear;
    void attentionListener(float &param);
    void meditationListener(float &param);
    void deltaListener(float &param);
    
    ofTrueTypeFont font;
    
    
    float atChangeTime;
    float meChangeTime;
    float deChangeTime; //
    float attention;
    float meditation;
    float delta; //
    float distAw;    
    float prevAw;
    float currAw;
    float distMw;
    float prevMw;
    float currMw;
    float distDw; //
    float prevDw; //
    float currDw; //
    
    bool graph;
    vector <int> attValues;
    int mode; //for slide
    
    
    ofPolyline path;
    strike bolt;
    
    float vx, vy, temp, fiftyFifty, maxDTheta, minDTheta, maxTheta, tempTheta;
    
    float ballRadius;
    
    float currentAttAvg, currentAvg;
    
    float minBoltWidth, maxBoltWidth, minJumpLength, maxJumpLength, lastStrike, nextStrike, maxTimeBetweenBolts, splitOdds;
    
    bool timeForBolt, fade, brainSYNC;
//    ofPolyline polyLine;
    
    vector <float> avgAttValues;
    
    
    
    
};

#endif
