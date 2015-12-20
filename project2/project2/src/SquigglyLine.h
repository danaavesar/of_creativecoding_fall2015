//
//  SquigglyLine.h
//  project2
//
//  Created by Dana Avesar on 11/5/15.
//
//

#ifndef __project2__SquigglyLine__
#define __project2__SquigglyLine__

#include "ofMain.h"

class SquigglyLine : public ofBaseApp{
public:
    void setup(int bottomOfCurveX);
    void update(float x, float y);
    void draw();
    void squiggle();
    
private:
    vector<ofPoint> squigglyPoints;
    int numberOfPoints;
    int bottomOfCurve;
    int topOfCurve;
    int curveAmount;
    int verticalSpace;
    int curveInterval;
    int bottomOfCurveX;
    
};
#endif /* defined(__project2__SquigglyLine__) */
