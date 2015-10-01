//
//  Branch.h
//  recursion
//
//  Created by Dana Avesar on 9/22/15.
//
//

#ifndef __recursion__Branch__
#define __recursion__Branch__

#include "ofMain.h"

class Branch : public ofBaseApp{
public:
    void setup(float _xPos, float _yPos,
               float _radius, ofColor _color,
               int _segmentsSinceStart, int _maxSegments,
               float addAmount
               );
    void update();
    void draw();
    
private:
    float xPos, yPos; //position
    float radius;
    ofColor color;
    int segmentsSinceStart;
    int maxSegments;
    float addAmount;
    
    
    
};

#endif /* defined(__recursion__Branch__) */
