//
//  LittleSquares.h
//  project2
//
//  Created by Dana Avesar on 11/5/15.
//
//

#ifndef __project2__LittleSquares__
#define __project2__LittleSquares__

#include "ofMain.h"

class LittleSquares : public ofBaseApp{
public:
    void setup();
    void update(float _mouseX, float mouseY);
    void draw();

    
    
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
    ofPoint position;
    float strokeWidth;
    ofColor randomFill;
    vector<ofColor>fill;
    float uniqueVal;
    
    ofPoint velocity;
    ofPoint frequency;
    float drag;
    ofSoundPlayer chime;
};


#endif /* defined(__project2__LittleSquares__) */
