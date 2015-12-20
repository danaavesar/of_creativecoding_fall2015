//
//  line.cpp
//  drawingWithParticles
//
//  Created by Dana Avesar on 12/17/15.
//
//

#include "line.h"
#include "ofMain.h"

void Line::setup(float _mouseX, float _mouseY, float _prevMouseX, float _prevMouseY, float _weight ){
    posBeg.x= _prevMouseX;
    posBeg.y = _prevMouseY;
    posEnd.x = _mouseX;
    posEnd.y = _mouseY;
    width = _weight;
}
void Line::update(){
}

void Line::draw(){
    cout << "draw" <<endl;
    ofNoFill();
    ofSetColor(0,0,0);
    ofBeginShape();
    ofSetLineWidth(width);
    ofVertex(posBeg.x, posBeg.y);
    ofVertex(posEnd.x, posEnd.y);
    
    ofEndShape();
}
