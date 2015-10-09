#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    bool hasDrawn = false;
    ofRectMode(RECT_MODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofBackground(125, 125, 125);
    myBranch.setup(ofGetWidth()/2, 3*(ofGetHeight()/4), //xpos ypos
                   20,130, //width, height
                   .5, //split percentage
                   PI/4,//splitAngle
                   2, //maxsubdivisions
                   5, //maxSegments
                   0, //segmentsSInceastart
                   -PI/2, //angle
                   0, //curvature
                   ofColor(73, 36, 13), //color
                   2 //season
                   );
//    void setup(float _xPos, float _yPos,
//               float _width, float _length,
//               float _splitPercentage,
//               float _maxSplitAngle,
//               float _maxSubdivisions,
//               float _maxSegments,
//               int _segmentsSinceStart,
//               float _angle,
//               float _curvature,
//               ofColor _color,
//               int _season);
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
