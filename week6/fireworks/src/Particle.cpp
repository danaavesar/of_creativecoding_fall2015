//
//  Particle.cpp
//  fireworks
//
//  Created by Dana Avesar on 10/10/15.
//
//

#include "Particle.h"

//ofVec2f pos;
//ofVec2f vel;
//ofVec2f acc;
//float diameter;
//float bounciness;
//ofColor ballColor;


void Particle::setup(){
    
    pos.x = 60;
    pos.y = ofGetHeight();
    vel.x = 10; //initial speed in the horizontal direction
    vel.y = -20; //initial speed in the vertical direction
    acc.x = 0; //initial horizontal acceleration
    acc.y = .4; //initial vertical acceleration
    diameter = 50; //initial Ball diameter
    bounciness = .9;
    ballColor = ofColor(31, 69, 110);
    
}

void Particle::setup(float _xPos,
                    float _yPos,
                    float _xVel,
                    float _yVel,
                    float _xAcc,
                    float _yAcc,
                    float _diameter,
                    float _brightness,
                    ofColor _ballColor){
    
    pos.set(_xPos,_yPos);
    vel.set(_xVel,_yVel);
//    acc.set(_xAcc, _yAcc);
    diameter = _diameter;

       brightness = _brightness;
    
    ballColor = _ballColor;
    
}

void Particle::resetForce(){
    //reset acc every frame
    acc.set(0,0);
    
}

void Particle::update(float _xAcc, float _yAcc, float _brightness){
    acc.x += _xAcc;
    acc.y += _yAcc;
    
  
    //update position with velocity
    pos.x += vel.x;
    pos.y += vel.y;
    //update velocity with acceleration
    vel.x += acc.x;
    vel.y += acc.y;
        if(brightness > 0){
            brightness -= _brightness;
        }else{
            brightness = 0;
        }
}

void Particle::draw(){
    ofSetColor(ofColor(255,105,180, brightness));
     cout << brightness <<endl;
    ofCircle(pos.x, pos.y, diameter);
}
