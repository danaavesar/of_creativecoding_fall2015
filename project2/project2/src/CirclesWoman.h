//
//  CirclesWoman.h
//  project2
//
//  Created by Dana Avesar on 10/28/15.
//
//

#ifndef __project2__CirclesWoman__
#define __project2__CirclesWoman__

#include "ofMain.h"

class CirclesWoman : public ofBaseApp{
public:
    void setup(int width, int height, ofColor color1, ofColor color2, ofColor color3 , ofPoint position);
    void update();
    void draw();
    void randomSetup(string type);
 
    

//    width
//    height
//    color
//    position
//    velocity
//    acceleration
   int width;
    int height;
    ofPoint position;
    vector<ofColor>color;
    ofColor outerColor;
    ofColor innerColor;
    ofColor mostInnerColor;
    
    
};

#endif /* defined(__project2__CirclesWoman__) */
