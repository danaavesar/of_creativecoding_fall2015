//
//  Branch.h
//  tree
//
//  Created by Dana Avesar on 9/27/15.
//
//

#ifndef __tree__Branch__
#define __tree__Branch__

#include "ofMain.h"
class Branch : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
private:
    float xPos, yPos;
    float width, length;
    float splitPercentage;
    float maxSplitAngle;
    int maxSubdivisions;
    int maxSegments;
    int segmentSinceStart;
    float angle;
    float curvature;
    bool hasLeaves;
    ofColor color;
    
};

#endif /* defined(__tree__Branch__) */
