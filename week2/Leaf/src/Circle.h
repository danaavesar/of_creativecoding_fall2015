//
//  Circle.h
//  Leaf3
//
//  Created by Dana Avesar on 9/13/15.
//
//

#ifndef __Leaf3__Circle__
#define __Leaf3__Circle__

#include <ofMain.h>

class Circle : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
private:
    
    float xPos, yPos;
    float rotation;
    float scaleFactor;
    float radius;
    float circleRadius;
    ofColor circleColor;
    
};

#endif /* defined(__Leaf3__Circle__) */
