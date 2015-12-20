//
//  SquigglyLine.cpp
//  project2
//
//  Created by Dana Avesar on 11/5/15.
//
//

#include "SquigglyLine.h"
void SquigglyLine::setup(int _bottomOfCurveX){
    numberOfPoints = 30;
    bottomOfCurveX = _bottomOfCurveX;
    bottomOfCurve = 815;
    topOfCurve = 274;
    curveAmount; //curve on the x
    verticalSpace = bottomOfCurve - topOfCurve;
    curveInterval = ofRandom(verticalSpace/numberOfPoints, (verticalSpace + 30)/numberOfPoints); //interval on the y of the line


    //points array, push the first point in (the lowest one)
    squigglyPoints.push_back(ofPoint(bottomOfCurveX, bottomOfCurve));

    for(int i=1; i<numberOfPoints; i++){
        float xi;
        //if i is even then go to the left, else go to the right
        if(i%2 == 0 ){
            curveAmount = ofRandom(1,4);
            xi = bottomOfCurveX - curveAmount;
        }else{
            curveAmount = ofRandom(1,3);
            xi = bottomOfCurveX + curveAmount;
        }
        
        float yi = bottomOfCurve - curveInterval*i;
        
        squigglyPoints.push_back(ofPoint(xi, yi));
    }




}

void SquigglyLine::update(float x, float y){
    for(int i=1; i<numberOfPoints; i++){
           // squigglyPoints[i].y -curveInterval;
          //  numberOfPoints ++;
           // bottomOfCurve ++;
        
       // squiggle();

        
        ofPoint attractPt(x, y);
        
        ofPoint frequency = attractPt - squigglyPoints[i];
        
        float dist = frequency.length();
        
        //velocity *= drag;
        if( dist < 10 ){
             squigglyPoints[i].x = squigglyPoints[i].x + .5*cos(ofGetElapsedTimef()*1.0f);
        }
    }
  
}

void SquigglyLine::squiggle(){
    int i = 0;
    
    if(i%2 == 0){
        squigglyPoints[i].x = squigglyPoints[i].x + .5*cos(ofGetElapsedTimef()*1.0f); //the frames make it faster
        //squigglyPoints[i].y = squigglyPoints[i].y + .5*sin(ofGetElapsedTimef()*1.0f);
        
    }else{
        squigglyPoints[i].x = squigglyPoints[i].x + cos(ofGetElapsedTimef()*2.0f);
        // squigglyPoints[i].y = squigglyPoints[i].y + .8*sin(ofGetElapsedTimef()*1.0f);
    }
    i++;
//    if(i < 30){
//        update();
//    }
}

void SquigglyLine::draw(){
    
    ofNoFill();
    ofSetColor(168,114,44);
    ofBeginShape();
    //beginning point
    ofCurveVertex(squigglyPoints[0].x, squigglyPoints[0].y);
    for(int i=1; i<numberOfPoints; i++){
        //loop through all points
        ofCurveVertex(squigglyPoints[i].x,squigglyPoints[i].y );
    }
    ofCurveVertex(squigglyPoints[numberOfPoints -1].x,squigglyPoints[numberOfPoints -1].y );

    //end point (you are supposed to have them twice)
    
    ofEndShape();
   
    ofEnableAlphaBlending();
    
    ofDisableAlphaBlending();
}