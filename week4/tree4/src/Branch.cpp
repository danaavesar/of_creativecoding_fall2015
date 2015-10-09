//
//  Branch.cpp
//  tree4
//
//  Created by Dana Avesar on 10/7/15.
//
//

#include "Branch.h"

void Branch::setup(float _xPos, float _yPos,
                   float _width, float _length,
                   float _splitPercentage,
                   float _maxSplitAngle,
                   int _maxSubdivisions,
                   int _maxSegments,
                   int _segmentsSinceStart,
                   float _angle,
                   float _curvature,
                   ofColor _color,
                   int _season){
    //===========================================
    // set incoming values based on what was passed in from previous instance of branch
    
    
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    length = _length;
    splitPercentage = _splitPercentage;
    maxSplitAngle = _maxSplitAngle;
    maxSubdivisions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
    season = _season;
    
    //===========================================
    //determine if the branch splits
    
    if(ofRandom(0, 1) > splitPercentage && segmentsSinceStart != maxSegments){ //dont split on last branch
        split = true;
    }else {
        split = false;
    }
    
    //===========================================
    // determine number of Roses!!!
    numberOfRoses = (int)ofRandom(0,4);
    if(segmentsSinceStart == maxSegments){
        numberOfRoses = (int)ofRandom(3,5);
    }
    if(segmentsSinceStart == 0){
        numberOfRoses = 0;
    }
    
    //===========================================
    // create the Roses!!!
    
    for(int i=0; i < numberOfRoses; i++){
        Rose tempRose;
        tempRose.setup();
        rosesOnTree.push_back(tempRose);
    }
    
    //===========================================
    //draw current branch instance
    
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofLine(xPos, yPos, xPos + length*cos(angle), yPos + length*sin(angle));
    
    
    //===========================================
    //draw roses on current branch
    
    
    for(int i=0; i < numberOfRoses; i++){
        rosesOnTree[i].draw(xPos + length*cos(angle), yPos + length*sin(angle));
        
        
    }
    
    //===========================================
    //update variables to pass to next (sub) branch

    
    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*(ofRandom(0.5,0.8));
    length = length*(ofRandom(0.7, 0.9));
    angle += curvature;
    curvature += ofRandom(0, (float)(2*PI)/360.0);
    
    //========================================
    segmentsSinceStart += 1; // DO THIS OR THE RECURSION WILL NEVER STOP!!!

    //===========================================
    //RECURSION!
    
    if(segmentsSinceStart <= maxSegments){
        if(!split){
            Branch subBranch;
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle, curvature, color, season);
            
        }else{
            cout << "split" << endl; //some feedback
            Branch subBranch1;
            float angle1 = angle + ofRandom(0, maxSplitAngle);
            Branch subBranch2;
            float angle2 = angle - ofRandom(0, maxSplitAngle);
            
            subBranch1.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle1, curvature, color, season);
            
            subBranch2.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle2, curvature, color, season);
        }
    }

    
    
    
    
    
    
}