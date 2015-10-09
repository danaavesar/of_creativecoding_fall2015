//
//  RosePetal.cpp
//  tree4
//
//  Created by Dana Avesar on 10/7/15.
//
//

#include "RosePetal.h"
void RosePetal::setup( int _cycles, float _rotation){
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    //    color = ofColor(ofRandom(180,240), ofRandom(91,125), ofRandom(100,125));
    width = 100;
    height = 150;
    rotation = _rotation;
    int cycles = _cycles;
    
    if(cycles == 0){
        //if outside make big
        color = ofColor(ofRandom(252,255), ofRandom(150,235), ofRandom(110,145));
        
        scaleFactor = ofRandom(1.5, 1.7);
    }else if(cycles == 1) { // if inside make small
        color = ofColor(ofRandom(210,239),ofRandom(50,150), ofRandom(64,100));
        //              color = ofColor(ofRandom(210,255),ofRandom(180,200), ofRandom(94,150));
        
        scaleFactor = ofRandom(1, 1.6);
        
    }else if(cycles >= 2 && cycles <=3){
        scaleFactor = ofRandom(.8,1.2);
        color = ofColor(ofRandom(140, 200), ofRandom(40, 50), ofRandom(50, 90));
    }else if(cycles >=4 && cycles <=6){
        scaleFactor = ofRandom(.3,.9);
        color = ofColor(ofRandom(80, 150), ofRandom(10,40), ofRandom(8, 60));
    }else if(cycles >=7){
        scaleFactor = ofRandom(.2,.4);
        color = ofColor(ofRandom(60, 120), ofRandom(5,40), ofRandom(6, 40));
        
    }
}

void RosePetal::draw(float _xPos, float _yPos){
    ofPushMatrix();
    
    ofSetColor(color);
    ofTranslate(_xPos, _yPos);
    ofPushStyle();
    ofScale(.2, .2);
    ofRotate(rotation);
    ofScale(scaleFactor, scaleFactor);
    ofBeginShape();
    
    float x0 = 0 - width/2;
    float x1 = 0 - width/3;
    float x2 = 0;
    float x3 = 0 + width/2;
    
    
    float y0 = 0 + 45;
    float y1 = y0 + height/3;
    float y2 = y0 + height/4;
    float y3 = y0;
    
    
    ofVertex(x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    ofPopStyle();
    ofPopMatrix();
    
}