//
//  Leaf.h
//  Leaf3
//
//  Created by Dana Avesar on 9/10/15.
//
//

#ifndef __Leaf3__Leaf__
#define __Leaf3__Leaf__

#include "ofMain.h"

class Leaf : public ofBaseApp{
    
public:
void setup();
void update();
void draw();
    
private:
    
    float xPos, yPos;
    float stemLength, stemWidth;
    float leafWidth, leafLength;
    ofColor stemColor;
    ofColor leafColor;
    float x1;
    float x2;
    float x3;
    float x4;
    
    float y1;
    float y2;
    float y3;
    float y4;
    
    float rotation;
    float scaleFactor;
    float circleRadius;
    
};
#endif /* defined(__Leaf3__Leaf__) */
