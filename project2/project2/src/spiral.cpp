//
//  spiral.cpp
//  project2
//
//  Created by Dana Avesar on 11/11/15.
//
//

#include "spiral.h"

void spiral::setup(ofPoint _position, float _radiusAdderX, float _radiusAdderY, int _numSpirals){
    position = _position;
    radiusAdderX = _radiusAdderX/600;
    radiusAdderY = _radiusAdderY/600;
    numSpirals = _numSpirals*100;
    randomLineWidth = ofRandom(2,3);
    randomAlpha = ofRandom(80,240);
    initiated = false;
    var = 0;
    rotation = ofRandom(0,5);
}

void spiral::setupRandom(){
    position.x = ofRandom(480, 600);
    position.y = ofRandom(270, 687);
    radiusAdderX = ofRandom(29,60)/600;
    radiusAdderY = ofRandom(29,55)/600;
    numSpirals = ofRandom(3,5)*100;
    randomLineWidth = ofRandom(2,3);
    randomAlpha = ofRandom(80,240);
    initiated = false;
    var = 0;
    rotation = ofRandom(0,5);
}



void spiral::update(float x, float y){
    if(initiated){
        var = sin(ofGetElapsedTimef()/5.0f) * 60;
        //var = sin(x/10.0f) *y;
    }
}

void spiral::draw(){
    ofPushMatrix();
        ofTranslate(position.x,position.y,0);
        ofRotate(rotation);
        ofSetColor(233,149,0, randomAlpha);
        ofNoFill();
        ofEnableAlphaBlending();
        ofSetLineWidth(randomLineWidth);
        ofSetPolyMode(OF_POLY_WINDING_ODD);
        ofBeginShape();
        angleStep 	= TWO_PI/(100.0f + var);
        radiusX 		= 0;
        radiusY = 0;
        for (int i = 0; i < numSpirals; i++){
            float anglef = (i) * angleStep;
            float x = radiusX * cos(anglef);
            float y = radiusY * sin(anglef);
            ofVertex(x,y);
            radiusX 	+= radiusAdderX;
            radiusY += radiusAdderY;
        }
    ofEndShape();
    ofPopMatrix();
    ofFill();
    ofSetColor(235,95,57);
    ofEllipse(position.x, position.y, 10, 7);
    
    //so cool
    /*
    ofPushMatrix();
    ofTranslate(100,300,0);
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(1);
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
    float angleStep 	= TWO_PI + (sin(mouseX/10.0f) *mouseY);
    float radiusAdder = 0.4f;
    float radius 		= 0;
    
    for (int i = 0; i < 400; i++){
        float anglef = (i) * angleStep;
        float x = radius * cos(anglef);
        float y = radius * sin(anglef);
        ofVertex(x,y);
        radius 	+= radiusAdder;
    }
    ofEndShape();
    ofPopMatrix();
     */
}

void spiral::mouseDragged(int x, int y){
    if(x > position.x - radiusX/2 && x< position.x + radiusX/2 && y < position.y + radiusY/2 && y> position.y -radiusY/2){
        initiated = true;
    }
}