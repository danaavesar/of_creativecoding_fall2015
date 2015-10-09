#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //    numberOfRoses = 105;
    //      ofEnableSmoothing();
    //    int rotation = 0;
    //    int cycles = 0;
    //    for(int i=0; i<numberOfRoses; i++){
    //        Rose myRose;
    //        rotation += 360/7;
    //
    //        if(rotation <= 360){ //big leaves
    //            cycles = 0;
    //
    //        }else if(rotation >= 360 ){ //small leaves
    ////            rotation += 360/8;
    //            cycles = ((rotation - (rotation%360))/360); //find the cycle by finding the closest multiple of 360 inside of rotation
    //        }
    //
    //        cout<<cycles<<endl;
    //
    //        myRose.setup(cycles,rotation);
    //
    //        roses.push_back(myRose);
    //    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //    for(int i=0; i<numberOfRoses; i++){
    //        roses[i].draw();
    //    }
    
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
    ofBackground(125, 125, 125);
    
    //This is where your Tree begins!
    myBranch.setup(ofGetWidth()/2,      //float _xPos
                   3*(ofGetHeight()/4),     //float _yPos
                   //                   ofGetHeight()/2,     //float _yPos
                   20,                  //float _width
                   70,                  //float _length
                   0.35,                //float _splitPercentage
                   PI/4,                //float _maxSplitAngle
                   2,                   //int _maxSubdivisions
                   5,                   //int _maxSegments
                   0,                   //int _segmentsSinceStart
                   -PI/2,                //float _angle
                   0,                   //float _curvature
                   ofColor(73, 36, 13),//ofColor _color
                   false
                   );
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
