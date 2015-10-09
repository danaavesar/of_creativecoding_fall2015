//
//  Rose.h
//  tree4
//
//  Created by Dana Avesar on 10/7/15.
//
//

#ifndef __tree4__Rose__
#define __tree4__Rose__

#include "ofMain.h"
#include "RosePetal.h"

class Rose : public ofBaseApp{
public:
    void setup();
    void draw(float _xPos, float _yPos);
    void mousePressed(int x, int y, int button);
    RosePetal myRosePetal;
private:
    int numberOfPetals;
    vector <RosePetal> rosePetalVector;
};

#endif /* defined(__tree4__Rose__) */
