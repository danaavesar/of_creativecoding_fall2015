//
//  bigCirclesDress.h
//  project2
//
//  Created by Dana Avesar on 11/7/15.
//
//

#ifndef __project2__bigCirclesDress__
#define __project2__bigCirclesDress__


#include "ofMain.h"

class bigCirclesDress : public ofBaseApp{
public:
    void setup();
    void setupFixed(ofPoint position, int width, int height);
    void update();
    void draw();
    Boolean overlapped();
    
    
private:
    //    width
    //    height
    //    color
    //    position
    //    velocity
    //    acceleration
    int width;
    int height;
    int rotation;
    int widthInner;
    int heightInner;
    float randomScale;
    ofPoint position;
    float strokeWidth;
    ofColor randomFill;
    ofColor innerFill;
    ofColor outerFill;
//    vector<ofColor>outerFill;
    vector<ofPoint>positions;
    Boolean overlap;
};

#endif /* defined(__project2__bigCirclesDress__) */
