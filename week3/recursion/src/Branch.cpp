//
//  Branch.cpp
//  recursion
//
//  Created by Dana Avesar on 9/22/15.
//
//

#include "Branch.h"
void Branch::setup(
                   float _xPos,
                   float _yPos,
                   float _radius,
                   ofColor _color,
                   int _segmentsSinceStart,
                   int _maxSegments,
                   float addAmount
                   ){
    

    xPos = _xPos;
    yPos = _yPos;
    radius = _radius;
//    splitPercentage = _splitPertentage;
//    maxSubdivisions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
//    angle = _angle;
//    curvature = _curvature;
    color = _color;
    
    
    //===========================================
    //draw current instance
    //===========================================
    ofNoFill();
    ofSetColor(color);
    ofEnableSmoothing();
    ofCircle(xPos, yPos, radius);
   
    //===========================================
    //update variables to pass to the sub
    //===========================================
    
     addAmount += 100*cos(PI);
    yPos+= 60*sin(PI/2);
    radius -= radius/10;
    segmentsSinceStart +=1;
    
    //===========================================
    //RECURSION!
    //===========================================
    
    if(segmentsSinceStart <= maxSegments){
        Branch subBranch;
        float positionX1 = xPos + addAmount;
        subBranch.setup(positionX1, yPos, radius, color, segmentsSinceStart, maxSegments, addAmount);
        
        float positionX2 = xPos - addAmount;
        Branch subBranch2;
        subBranch2.setup(positionX2, yPos, radius, color, segmentsSinceStart, maxSegments, addAmount);
    }
    
    
    
}

//--------------------------------------------------------------
void Branch::update(){
    
}

//--------------------------------------------------------------
void Branch::draw(){
    
}