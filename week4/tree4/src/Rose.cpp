//
//  Rose.cpp
//  tree4
//
//  Created by Dana Avesar on 10/7/15.
//
//

#include "Rose.h"

void Rose::setup(){
    numberOfPetals = 105;
    ofEnableSmoothing();
    int rotation = 0;
    int cycles = 0;
    for(int i=0; i<numberOfPetals; i++){
        RosePetal myRosePetal;
        rotation += 360/7;
        
        if(rotation <= 360){//big leaves
            cycles = 0;
        }else if (rotation >= 360){//small leaves
            rotation += 360/8;
            cycles = ((rotation - (rotation%360))/360); //find the cycle by finding the closest multiple of 360 inside of rotation
        }
        
        cout<<cycles<<endl;
        
        myRosePetal.setup(cycles, rotation);
        rosePetalVector.push_back(myRosePetal);
    }
}

void Rose::draw(float _xPos, float _yPos){
    for(int i=0; i<numberOfPetals; i++){
        rosePetalVector[i].draw(_xPos, _yPos);
    }
}

void Rose::mousePressed(int x, int y, int button){
    rosePetalVector.clear();
    setup();
}