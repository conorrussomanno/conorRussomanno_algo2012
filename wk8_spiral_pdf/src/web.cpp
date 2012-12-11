//
//  web.cpp
//  springs
//
//  Created by Conor Russomanno on 11/26/12.
//
//

#include "web.h"
#include "ofMain.h"

//---------------------------------------------------------------------
void web::setInitialCondition(int x, int y){

    center.x = x; //center of web, values retrieved from mouse pressed
    center.y = y;
    cout << "center " << center.x << " " << center.y << endl;
    numSpines = (int)ofRandom(10,30); //spines coming out from center of web
    cout << numSpines << endl;
    numSpirals = (int)ofRandom(5,30); //number of times the circular webs spiral the center
    cout << numSpirals << endl;
    splitAvg = ofRandom(20,50); //average split between each spiral
    cout << splitAvg << endl;
    
    float spineAngle[numSpines]; //array for number of spines
    for (int i = 0; i < numSpines; i++) {
        spineAngle[i] = (float)((360)/numSpines)*(i) + ofRandom(15); //sets angle of the various spines with slight randomization to obtain "natural" look
        cout << i << " " << spineAngle[i] << endl;
    }
    
    //nodes for spring connections:
    
    for (int i=0; i < numSpirals; i++){ 
        for (int j=0; j < numSpines; j++){
            particle tempParticle;
            float angle = spineAngle[j]; //just use angle of j...
            float radius = j*(splitAvg/numSpines) + i*splitAvg;
            cout << "radius " << i << " " << j << " " << radius << endl;
            cout << "angle " << i << " " << j << " " << angle << endl;
            float adjustedX, adjustedY;
            adjustedX = center.x + radius * cos(spineAngle[j]*(PI/180)); //
            adjustedY = center.y + radius * sin(spineAngle[j]*(PI/180));
            cout << adjustedX << " " << adjustedY << endl;
            tempParticle.setInitialCondition(adjustedX, adjustedY, 0, 0);
            nodes.push_back(tempParticle);
        }
    }
    
    //spring connections:
}

//---------------------------------------------------------------------
void web::update(){
    if (nodes.size()>0) {
        for(int i = 0; i < nodes.size(); i++){
            nodes[i].update();
        }
    }
}


//---------------------------------------------------------------------
void web::draw(){
    if (nodes.size()>0) {
        for(int i = 0; i < nodes.size(); i++){
            ofEllipse(nodes[i].pos.x, nodes[i].pos.y, 2, 2);
        }
    }
}