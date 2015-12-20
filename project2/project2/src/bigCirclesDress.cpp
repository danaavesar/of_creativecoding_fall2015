//
//  bigCirclesDress.cpp
//  project2
//
//  Created by Dana Avesar on 11/7/15.
//
//

#include "bigCirclesDress.h"
void bigCirclesDress::setup(){
    
//    overlap = false;
//    //    int width, int height, ofPoint position, int rotation
//    width = ofRandom(18,35);
//    height = ofRandom(12,26);
//    rotation = ofRandom(0,23);
//    strokeWidth = ofRandom(.5, 1.5);
//    
//    position.x = ofRandom(331,473);
//    position.y = ofRandom(280,787);
  
    
//    overlapped();
//
//    if (overlap == true){
//    
//    }
    
    
    //light cream color
//    outerFill.push_back(ofColor(ofRandom(236, 239),ofRandom(218,222),ofRandom(147,172)));
//    outerFill.push_back(ofColor(ofRandom(250,255),ofRandom(218,222),ofRandom(2,79)));
   // randomFill = outerFill[ofRandom(0,1)];
    
}

//Boolean bigCirclesDress::overlapped(){
//    //check to see if they have overlapped
//    for(int i=0; i<positions.size(); i++){
//        int areaXright = positions[i].x + width/2;
//        int areaXleft = positions[i].x - width/2;
//        int areaYtop = positions[i].y + height/2;
//        int areaYbottom = positions[i].y - height/2;
//
//
//        if(position.x < areaXright && position.x > areaXleft && position.y < areaYbottom && position.y > areaYtop){
//            overlap = true;
//           
//        }
//        
//    }
//    
//    return overlap;
//}

void bigCirclesDress::setupFixed(ofPoint _position, int _width, int _height){
 
    width = _width;
    height = _height;
    randomScale = ofRandom(2, 3);
    widthInner = width/randomScale;
    heightInner = height/randomScale;
    position.x = _position.x + width/2;
    position.y = _position.y + height/2;
    rotation = ofRandom(-8,0);
    strokeWidth = ofRandom(.5, 1.5);
    outerFill = ofColor(250,216,44, 250);
    innerFill = ofColor(242,183,0, 250);
}



void bigCirclesDress::update(){
    
}

void bigCirclesDress::draw(){
    ofPushStyle();
    ofPushMatrix();
    ofEnableAlphaBlending();
        ofTranslate(position.x,position.y);
        ofRotate(rotation);//degrees
        //filled in outer ellipse
        ofFill();
        ofSetColor(outerFill);
        ofEllipse(0,0,width,height);
        //filled inside ellipse
        ofFill();
        ofSetColor(innerFill);
        ofEllipse(0,0,widthInner,heightInner);
        //strokes
        ofNoFill();
        ofSetLineWidth(strokeWidth);
        ofSetColor(0, 0, 0, 180);
        ofEllipse(0,0,width,height);
    ofPopMatrix();
    ofPopStyle();
}


