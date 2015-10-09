//
//  Rose.h
//  tree
//
//  Created by Dana Avesar on 9/27/15.
//
//

#ifndef __tree__Rose__
#define __tree__Rose__

#include "ofMain.h"
#include "Rose_petal.h"
#include "Branch.h"

class Rose : public ofBaseApp{
    
public:
    void setup(float _angle);
    void update();
    void draw(float _xPos, float _yPos);
    Rose_petal myRose;
    
private:
    
    float xPos, yPos; //position
    int numberOfRosePetals;
    vector <Rose_petal> rose;
};

#endif /* defined(__tree__Rose__) */
