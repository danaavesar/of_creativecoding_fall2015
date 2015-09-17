//
//  Circle.cpp
//  Leaf3
//
//  Created by Dana Avesar on 9/13/15.
//
//

#include "Circle.h"
void Circle::setup(){

    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    rotation = ofRandom(0,360);
    circleRadius = ofRandom(80,100);
    scaleFactor = ofRandom(.2, .6);
    circleColor = ofColor(ofRandom(160,205), ofRandom(80,150), ofRandom(30,80));
    radius = 20;
    
}

//--------------------------------------------------------------
void Circle::update(){
    
}

//--------------------------------------------------------------
void Circle::draw(){
    ofPushMatrix();
    
        ofTranslate(xPos,yPos);
    
        ofRotate(rotation);
    
        //middle circles
        ofSetColor(circleColor);
        ofCircle(0, circleRadius, radius);
    
    ofPopMatrix();
    
}