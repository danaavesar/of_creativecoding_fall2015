//
//  spiral.h
//  project2
//
//  Created by Dana Avesar on 11/11/15.
//
//

#ifndef __project2__spiral__
#define __project2__spiral__

#include "ofMain.h"

class spiral : public ofBaseApp{
public:
    void setup(ofPoint position, float radiusX, float radiusY, int numSpirals);
    void setupRandom();
    void update(float x, float y);
    void draw();
    void mouseDragged(int x, int y);

    
    
private:
    ofPoint position;
    int numSpirals;
    float radiusAdderX;
    float radiusAdderY;
    int randomLineWidth;
    float randomAlpha;
    float angleStep;
    Boolean initiated;
    float radiusX;
    float radiusY;
    float var;
    float rotation;
};


#endif /* defined(__project2__spiral__) */
