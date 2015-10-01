//
//  Branch.cpp
//  tree
//
//  Created by Dana Avesar on 9/27/15.
//
//

#include "Branch.h"

void Branch::setup(float _xPos, float _yPos,
                        float _width, float _length,
                        float _splitPercentage,
                        float _maxSplitAngle,
                        float _maxSubdivisions,
                        float _maxSegments,
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
    numTreeRoses = (int)ofRandom(0,4);
    if(segmentsSinceStart == maxSegments){
        numTreeRoses = (int)ofRandom(3,5);
    }
    if(segmentsSinceStart == 0){
        numTreeRoses = 0;
    }

    
    //===========================================
    // create the Roses!!!
    
    for(int i=0; i < numTreeRoses; i++){
     
        numberOfRosePetals = 105;
        int rotation = 0;
        int cycles = 0;
        for(int j=0; j<numberOfRosePetals; j++){
            Rose myRosePetal;
            rotation += 360/7;
    
            if(rotation <= 360){ //big leaves
                cycles = 0;
    
            }else if(rotation >= 360 ){ //small leaves
    //            rotation += 360/8;
                cycles = ((rotation - (rotation%360))/360); //find the cycle by finding the closest multiple of 360 inside of rotation
            }
    
            cout<<cycles<<endl;
    
            myRosePetal.setup(cycles,rotation);
            
            rose.push_back(myRosePetal);
        }
        
        //create a temp Rose? double vector that can store the entire rose in it?
       // rosesOnTree.push_back(rose);
    }
    
    //===========================================
    //draw current branch instance
    
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofLine(xPos, yPos, xPos + length*cos(angle), yPos + length*sin(angle));
    
    //===========================================
    //draw roses on current branch
    //??????
    
    
    //===========================================
    //update variables to pass to next (sub) branch
    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*(ofRandom(0.5,0.8));
    length = length*(ofRandom(0.7, 0.9));
    angle += curvature;
    curvature += ofRandom(0, (float)(2*PI)/360.0);
    
    segmentsSinceStart +=1;
    
    if (segmentsSinceStart <= maxSegments){
        if(!split){
            Branch subBranch;
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle, curvature, color, season);
        }else{
            Branch subBranch1;
            float angle1 = angle + ofRandom(0, maxSplitAngle);
            Branch subBranch2;
            float angle2 = angle - ofRandom(0, maxSplitAngle);
            
            subBranch1.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle1, curvature, color, season);
            
            subBranch2.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle2, curvature, color, season);


        }
    }
    
    
}
