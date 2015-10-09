//
//  RosePetal.h
//  tree4
//
//  Created by Dana Avesar on 10/7/15.
//
//

#ifndef __tree4__RosePetal__
#define __tree4__RosePetal__

#include "ofMain.h"
class RosePetal : public ofBaseApp{
public:
    void setup(int _cycles, float _rotation);
    void draw(float _xPos, float _yPos);
private:
    float xPos, yPos;
    ofColor color;
    float width;
    float height;
    float scaleFactor;
    float rotation;
};

#endif /* defined(__tree4__RosePetal__) */
