//
//  Leaf.cpp
//  Leaf3
//
//  Created by Dana Avesar on 9/10/15.
//
//

#include "Leaf.h"

void Leaf::setup(){
//    float xPos, yPos;
//    float stemLength;
//    float stemWidth;
//    ofColor stemColor;
//    ofColor leafColor;
//    float leafWidth, leafLength;
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    stemWidth = 15;
    stemLength = 100;
    leafLength = 200;
    leafWidth = 160;
    stemColor = ofColor(ofRandom(250,255), ofRandom(100,180), ofRandom(0,40), 160);
    leafColor = ofColor(ofRandom(230,255), ofRandom(200,230), ofRandom(30,100));
    rotation = ofRandom(0,360);
    circleRadius = 100;
    x1 = 0;
    x2 = x1 - ofRandom(leafWidth/3, leafWidth/2);
    x3 = x1 - ofRandom(leafWidth/4, leafWidth/3);
    x4 = 0;
    
    y1 = circleRadius;
    y2 = y1 + ofRandom(leafLength/3, leafLength/4);
     y3 = y2 + ofRandom(leafLength/3, leafLength/4);
     y4 = y1 + leafLength;
    scaleFactor = ofRandom(.2, .6);
    
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw(){
    ofPushMatrix();
    
        ofTranslate(xPos,yPos);
        ofRotate(90);
        ofRotate(rotation);
    
    
        //leaf left side
    
  
        ofSetColor(leafColor);
    
        ofBeginShape();
            ofVertex(x1,y1);
            ofBezierVertex(x2, y2, x3, y3, x4, y4);
    
        ofEndShape();
    
        //right side
        ofBeginShape();
            ofVertex(x1,y1);
            ofBezierVertex(-x2, y2, -x3, y3, -x4, y4);
    
        ofEndShape();
    
    //leaf line
    ofSetColor(stemColor);
    ofTriangle(0-stemWidth/2, y1, 0+stemWidth/2, y1, 0, leafLength );

    
    ofPopMatrix();
    
}