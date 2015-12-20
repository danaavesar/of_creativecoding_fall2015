#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(160);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
   
   
    ofSetColor(0, 0, 0);
    ofFill();
    for(int i=0; i<circles.size(); i++){
        circles[i].draw();
    }
    
    for(int i=0; i<lines.size(); i++){
        lines[i].draw();
    }
    for(int i=0; i<weirdos.size(); i++){
        weirdos[i].draw();
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
    //find the previous mouseX and the current mouseX
    //get the distance between those points
    //the bigger the distance the smaller the circle
    //divide the distance by constant int

//    
//    dist.x = x - prevMouseX;
//    dist.y = y - prevMouseY;
//
    float dist  = ofDist(prevMouseX, prevMouseY, x, y);
     cout << dist << endl;
    float radius = dist/divider;
    float weight = dist/divider;
        Circle tempCircle;
        tempCircle.setup(mouseX,mouseY, radius);
        circles.push_back(tempCircle);
    if(dist < 60){
        Line myLine;
        myLine.setup(x,y, prevMouseX,prevMouseY, weight);
        lines.push_back(myLine);
    }
    
    if(dist >80){
        Weirdo myWeirdo;
        myWeirdo.setup(x,y, prevMouseX,prevMouseY, weight);
        weirdos.push_back(myWeirdo);
    }


  
    prevMouseX = x;
    prevMouseY = y;
    
    
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
