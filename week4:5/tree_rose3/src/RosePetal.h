//
//  Rose_petal.h
//  tree
//
//  Created by Dana Avesar on 9/27/15.
//
//

#ifndef __tree__Rose__
#define __tree__Rose__

#include "ofMain.h"
//#include "Rose.h"
//#inclue "Branch.h"

class RosePetal : public ofBaseApp{
    
public:
    void setup(int _cycles, float _rotation);
//    void update();
    void draw();
    
    
private:
    float xPos, yPos;
    ofColor color;
    float width;
    float height;
    float scaleFactor;
    float rotation;
    
    
    
};
#endif /* defined(__tree__Rose__) */