//
//  line.cpp
//  drawingWithParticles
//
//  Created by Dana Avesar on 12/17/15.
//
//

#include "Weirdo.h"
#include "ofMain.h"

void Weirdo::setup(float _mouseX, float _mouseY, float _prevMouseX, float _prevMouseY, float _size){
    posBeg.x= _prevMouseX;
    posBeg.y = _prevMouseY;
    posEnd.x = _mouseX;
    posEnd.y = _mouseY;
    scaleAmount= _size/100;
    rotation = ofRandom(-60,90);
}

void Weirdo::update(){
}

void Weirdo::draw(){
    cout << scaleAmount <<endl;
    ofPushMatrix();
    ofPushStyle();
//    ofScale(scaleAmount, scaleAmount);
//    ofRotate(rotation);
//    ofTranslate(posEnd.x, posEnd.y);
//    
//    ofFill();
//    ofBeginShape();
//    ofVertex(50,0);
//    ofBezierVertex(65,23,28,49,0,49);
//    ofBezierVertex(-26,49,-64,22,-49,0);
//    ofBezierVertex(20,-102,-26,-12,0,-12);
//    ofBezierVertex(28,-12,0,-85,50,0);
//    ofEndShape();
    ofEllipse(posBeg.x, posBeg.y, scaleAmount, scaleAmount);

    ofPopMatrix();
    ofPopStyle();
    
    

}
