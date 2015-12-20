//
//  Bird.h
//  flocking
//
//  Created by Dana Avesar on 11/19/15.
//
//

#ifndef __flocking__Bird__
#define __flocking__Bird__

#include "ofMain.h"

class Bird : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    

    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
};

#endif /* defined(__flocking__Bird__) */
