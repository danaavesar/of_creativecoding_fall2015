//
//  LittleSquares.cpp
//  project2
//
//  Created by Dana Avesar on 11/5/15.
//
//

#include "LittleSquares.h"
void LittleSquares::setup(){

//    int width, int height, ofPoint position, int rotation
    width = ofRandom(3,7);
    height = ofRandom(3,7);
    rotation = ofRandom(0,360);
    strokeWidth = ofRandom(.5, 1.5);
//    velocity.x = ofRandom(-.05,.05);
//    velocity.y = ofRandom(-.05,.05);
    
    position.x = ofRandom(331,473);
    position.y = ofRandom(360,787);
    fill.push_back(ofColor(212,167,75,40));
    fill.push_back(ofColor(237,199,122,40));
    fill.push_back(ofColor(198,191,164,40));
    fill.push_back(ofColor(125,137,92,60));
    randomFill = fill[ofRandom(0,4)];
    float uniqueVal = ofRandom(-1000,1000);
    drag  = ofRandom(0.95, 0.998);
    
    chime.loadSound("chime4.mp3");

}



void LittleSquares::update(float _mouseX, float _mouseY){
    ofPoint attractPt(_mouseX, _mouseY);
    
    frequency = attractPt - position;
    
    float dist = frequency.length();
    
    //velocity *= drag;
    if( dist < 10 ){
        velocity += -frequency * .007; //notice the frc is negative
        chime.play();
        
    }else{
        //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
//        frequency.x = ofSignedNoise(4, position.y * 0.01, ofGetElapsedTimef()*0.2);
//        frequency.y = ofSignedNoise(6, position.x * 0.01, ofGetElapsedTimef()*0.2);
//        velocity += frequency * 0.04;
    }
    

    position += velocity;
    
    // update the sound playing system:
    ofSoundUpdate();
  
}

void LittleSquares::draw(){
   
    ofPushStyle();
        ofPushMatrix();
            ofTranslate(position.x,position.y);
            ofRotate(rotation);//degrees
        //filled in rectangles
            ofFill();
            ofSetColor(randomFill);
            ofRect(0,0,width,height);
        //strokes
            ofNoFill();
            ofSetLineWidth(strokeWidth);
            ofSetColor(0, 0, 0);
            ofRect(0,0,width,height);
        ofPopMatrix();
    ofPopStyle();
}
