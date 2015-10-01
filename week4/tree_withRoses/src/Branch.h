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
#include "Rose.h"

class Branch : public ofBaseApp{
    
public:
    void setup(float _xPos, float _yPos,
               float _width, float _length,
               float _splitPercentage,
               float _maxSplitAngle,
               float _maxSubdivisions,
               float _maxSegments,
               int _segmentsSinceStart,
               float _angle,
               float _curvature,
               ofColor _color,
               int _season);
    void update();
    void draw();
    
     Rose myRosePetal;
    Rose myTreeRose;
    
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

    
    int numTreeRoses;
    vector <Rose> rosesOnTree;
    bool split;
    int season;
    
    int numberOfRosePetals;
    vector <Rose> rose;
    
    
};

#endif /* defined(__tree__Branch__) */
