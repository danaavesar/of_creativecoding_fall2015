//
//  Particle.h
//  fireworks
//
//  Created by Dana Avesar on 10/10/15.
//
//

#ifndef __fireworks__Particle__
#define __fireworks__Particle__

#include "ofMain.h"

class Particle: public ofBaseApp{
public:
    void setup(); //quick setup
    void setup(float _xPos,
               float _yPos,
               float _xVel,
               float _yVel,
               float _xAcc,
               float _yAcc,
               float _diameter,
               float _brightness,
               ofColor _ballColor);
    void update(float _xAcc, float _yAcc, float _brightness);
    void draw();
    void resetForce();
    
private:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    float diameter;
    float bounciness;
    ofColor ballColor;
    float brightness;
};

#endif /* defined(__fireworks__Particle__) */
