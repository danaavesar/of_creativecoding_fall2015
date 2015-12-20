//
//  CirclesWoman.cpp
//  project2
//
//  Created by Dana Avesar on 10/28/15.
//
//

#include "CirclesWoman.h"



void CirclesWoman::setup(int _width, int _height, ofColor color1, ofColor color2, ofColor color3 , ofPoint _position){
    
    //set new variable values
 
    width =    _width;
    height = _height;

    outerColor = color1;
    innerColor = color2;
    mostInnerColor = color3;
   
    position = _position;
    
}


void CirclesWoman::randomSetup(string type){

    if(type == "blue"){
        position.x = ofRandom(349.894,386);
        position.y = ofRandom(452, 487);
    
        outerColor = ofColor(ofRandom(11,32),ofRandom(78,112),ofRandom(120,170));
        innerColor = ofColor(ofRandom(202,214),ofRandom(144, 185),ofRandom(61,98));
       mostInnerColor = ofColor(202,144,61);
    
        width =    ofRandom(20,30);;
        height = ofRandom(10,20);
    }
    
    if(type == "butt"){
        position.x = ofRandom(436,470);
        position.y = ofRandom(572, 611);
        
        outerColor = ofColor(ofRandom(11,32),ofRandom(78,112),ofRandom(120,170));
        innerColor = ofColor(ofRandom(175,197),ofRandom(87, 108),ofRandom(90,119));
        mostInnerColor = ofColor(ofRandom(175,197),ofRandom(87, 108),ofRandom(90,119));
        
        width =    ofRandom(20,30);;
        height = ofRandom(10,20);
        
    }
    
}

void CirclesWoman::update(){
    
}

void CirclesWoman::draw(){
    ofFill();
    //most outer circle
    ofSetColor(outerColor);
    ofEllipse(position.x, position.y, width, height);
    
    //inner circle
    ofSetColor(innerColor);
    ofEllipse(position.x, position.y, width/2, height/2);
    
    //most inner circle
    ofSetColor(mostInnerColor);
    ofEllipse(position.x, position.y, width/4, height/4);
    
}
