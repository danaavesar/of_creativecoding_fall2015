//
//  Branch.h
//  tree4
//
//  Created by Dana Avesar on 10/7/15.
//
//

#ifndef __tree4__Branch__
#define __tree4__Branch__

#include "ofMain.h"
#include "Rose.h"

class Branch : public ofBaseApp{
public:
    void setup(float _xPos, float _yPos,
               float _width, float _length,
               float _splitPercentage,
               float _maxSplitAngle,
               int _maxSubdivisions,
               int _maxSegments,
               int _segmentsSinceStart,
               float _angle,
               float _curvature,
               ofColor _color,
               int _season);
    void update();
    void draw();
    
    Rose myRose;
private:
    float xPos, yPos;
    float width, length;
    float splitPercentage;
    float maxSplitAngle;
    int maxSubdivisions;
    int maxSegments;
    int segmentsSinceStart;
    float angle;
    float curvature;
    bool hasLeaves;
    ofColor color;
    
    int numberOfRoses;
    vector <Rose> rosesOnTree;
    bool split;
    int season;
    
};

#endif /* defined(__tree4__Branch__) */
