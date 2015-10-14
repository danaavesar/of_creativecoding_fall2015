//
//  Rose.cpp
//  tree
//
//  Created by Dana Avesar on 9/27/15.
//
//

#include "Rose.h"

void Rose::setup(float _angle){
    numberOfRosePetals = 105;
    ofEnableSmoothing();
    int rotation = 0;
    int cycles = 0;
   /* for(int i=0; i<numberOfRosePetals; i++){
        Rose myRose;
        rotation += 360/7;
        
        if(rotation <= 360){ //big leaves
            cycles = 0;
            
        }else if(rotation >= 360 ){ //small leaves
            //            rotation += 360/8;
            cycles = ((rotation - (rotation%360))/360); //find the cycle by finding the closest multiple of 360 inside of rotation
        }
        
        cout<<cycles<<endl;
        
        myRose.setup(cycles,rotation);
//        
//        roses.push_back(myRose);
    }*/
    
}

void Rose::update(){
    
}

void Rose::draw(float _xPos, float _yPos){
    
}