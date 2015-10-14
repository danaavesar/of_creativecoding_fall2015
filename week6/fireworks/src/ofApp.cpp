#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0); //black background
    ofEnableAlphaBlending();
     ofEnableSmoothing();
    ofSetFrameRate(60);
    numParticles = 100;
    
    for(int i=0; i <numParticles; i++){
        Particle myParticle;
        myParticle.setup();
        particles.push_back(myParticle);
    }
   
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i =0; i<numParticles; i++){
        particles[i].resetForce();
        particles[i].update(0.0, //xAcc
                            .05, //yAcc
                            ofRandom(2,15) // brightness
                            );
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0, 100); //black background
    myBall.draw();
    
    for(int i=0; i<numParticles; i++){
        particles[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
//    etup(float _xPos,
//         float _yPos,
//         float _xVel,
//         float _yVel,
//         float _xAcc,
//         float _yAcc,
//         float _diameter,
//         float _bounciness,
//         ofColor _ballColor)
    for(int i=0; i<numParticles; i++){
        particles[i].setup(mouseX, //xPos
                           mouseY, //yPos
                           ofRandom(-2,2), //xVel
                          ofRandom (-2,2), // ofRandom(sin(0)*10, sin(PI)*10 ), //yVel
                           0, //xAcc
                           .6, // yAcc
                           2, //diameter
                           255, //brightness
                           ofColor(255,105,180)
                           );
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
