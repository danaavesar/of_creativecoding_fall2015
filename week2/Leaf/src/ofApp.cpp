#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numLeaves = 40;
    for(int i=0; i<numLeaves; i++){
        Leaf tempLeaf;
        tempLeaf.setup();
        leaves.push_back(tempLeaf);
   }
    numCircles = 100;
    for(int i=0; i<numCircles; i++){
        Circle tempCircle;
        tempCircle.setup();
        circles.push_back(tempCircle);
    }
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<numLeaves; i++){
        leaves[i].draw();
    }
    for(int i=0; i<numCircles; i++){
        circles[i].draw();
    }
//    tempLeaf.draw();
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
